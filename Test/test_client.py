# -*- coding: UTF-8 -*-
import sys
import time
import errno
import string
import select
import socket
import datetime
from threading import Lock

from mobicle.log import Log
from protocol.HolePunching_pb2 import HP_Message

lock=Lock()
log=Log(lock)
log.fileHeader="HolePunchingClient"

# IP Address
MyIP=socket.gethostbyname(socket.gethostname())

# Get Port Number
for MyPort in range(30000, 31500):
    sock = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
    result = sock.connect_ex(('0.0.0.0', MyPort))
    if result == 0:
        pass
    else:
        break
sock.close()

# Server Address
serverAddr = ('192.168.1.250', 19515)

# Sockets from which we expect to read
inputs = [ ]

# Sockets to which we expect to write
outputs = [ ] 

# Outgoing message queues ( socket : Queue )
message_queue = { } 

counter = 0
# 패킷 초기화
# 간편함을 위하여 유저ID, 게임ID는 임의로 처리.
def InitPacket(command):
    packet = HP_Message()
    packet.Id.userID = 'WorldBestMobicle'
    packet.Id.gameID = 'UDPHolePunching'
    packet.privateIP = MyIP
    packet.privatePort = MyPort
    packet.command = command
    return packet

# 핑테스트 
# 최소, 최대, 평균 레이턴시, 패킷 손실율을 구한다. 
def PingTest(sock, address):
    latency = [ ] 
    lossCounter = 0
    
    sendPacket = HP_Message()
    sendPacket = InitPacket(HP_Message.PING)
    sendPacket.serial = 8888
    serializedData = sendPacket.SerializeToString()
    pingCounter = 0
    while True:
        startTime = time.time()
        sock.sendto(serializedData, address)
        try:
            serializedData, address = sock.recvfrom(1024)
            endTime = time.time()
            latency.append(endTime-startTime)
        except socket.timeout:
            print 'Packet Loss: %s' % str(lossCounter+1)
            lossCounter += 1
            # continue 
        pingCounter += 1
        if pingCounter >= 100 or lossCounter >= 100:
            break
        latencySum = 0
    
    for x in latency:
        latencySum += x        
    print '==PING Test Complete=='

    latency.sort()
    if lossCounter == 100:
        print 'All Packet Loss::' + str(address) + '::' + str(datetime.datetime.now())
        sys.exit()
    elif lossCounter < pingCounter:
        print "Minimum PING Latency::" + str(round(latency[0], 5) * 1000) + 'ms'
        print "Maximum PING Latency::" + str(round(latency[pingCounter-lossCounter - 1], 5) * 1000) + "ms"
        avgLatency = latencySum / (pingCounter - lossCounter)
        # 손실률은 lossCounter/총패킷수 * 100으로 계산할 수 있다. 
        # 총 전송 패킷수가 100이므로 lossCounter / 100 * 100이므로 손실율(lossRate)은 lossCounter와 같다고 할 수 있다. 
        print "Average PING Latency::" + str(round(avgLatency, 5) * 1000) + "ms"
        log.write("PING Test Complete::Average Latency::" + str(round(avgLatency, 5) * 1000) + "ms::Loss Rate::" + str(lossCounter) + "%::" + str(datetime.datetime.now()))
    else:
        print 'mis process!.'
        log.write("ALL Packet Loss::" + str(address)+ "::" + str(datetime.datetime.now()))
    print '-'*100
    
def main():
    listenAddr = None
    peerAddr = None
    
    # UDP 소켓 생성(타임아웃 : 1초) : 사용 보류 
    listenSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
    listenSock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    # hpSock.bind((MyIP, MyPort))
    listenSock.settimeout(1)
    
    # UDP 소켓 생성(타임아웃 : 1초) : 사용 보류
    toSock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, 0)
    toSock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    toSock.bind((MyIP, MyPort))
    toSock.settimeout(1)
       
    print '<<Prepare UDP Hole Punching>>'
    # 핑테스트 : 랑데뷰 서버 
    PingTest(listenSock, serverAddr)
        
    # 레지스터 메세지 전송
    sendPacket = HP_Message()
    recvPacket = HP_Message()
    sendPacket = InitPacket(HP_Message.REGISTER)
    sendPacket.serial = 1111
    serializedData = sendPacket.SerializeToString()
    listenSock.sendto(serializedData, serverAddr)
    try:
        (serializedData, addr) = listenSock.recvfrom(1024)
    except socket.timeout:
        print 'Packet Loss'
        while True:
            listenSock.sendto(serializedData, serverAddr)
            try: 
                (serializedData, addr) = listenSock.recvfrom(1024)
                if serializedData != '':
                    break
                else:
                    continue
            except socket.timeout:
                print 'no response from Rendezvous Server'
                continue
    recvPacket.ParseFromString(serializedData)
    if recvPacket.result == HP_Message.SUCCESS:
        print 'REGISTRATION SUCCESS'
    # 랑데뷰 서버의 등록 실패 메세지를 받으면 일단은 프로그램 종료.
    else:
        print 'REGISTRATION FAIL'
        sys.exit()
    print '-'*100
        
    # 리퀘스트 메세지 전송
    sendPacket = HP_Message()
    sendPacket = InitPacket(HP_Message.REQUEST)
    # 필요로 하는 클라이언트의 ID정보
    sendPacket.requestID.userID = 'NumberOneMobicle'
    sendPacket.requestID.gameID = 'UDPHolePunching'
    sendPacket.serial = 2222
    serializedData = sendPacket.SerializeToString()
    toSock.sendto(serializedData, serverAddr)
# 리퀘스트 메세지를 전송하였을 때 1) 응답이 없는 경우, 2) FAIL메세지를 받은 경우에 대한 처리
    try:   
        serializedData, addr = toSock.recvfrom(1024)
    except socket.timeout:
        print 'no response from Rendezvous Server.'
        sys.exit()
    recvPacket = HP_Message()
    recvPacket.ParseFromString(serializedData)
    print recvPacket, addr
 
    peerAddr = (recvPacket.publicIP, recvPacket.publicPort)
    print '-'*100
    print recvPacket.publicIP
    print recvPacket.publicPort 
    print peerAddr 
    print '<<Start UDP Hole Punching!!>>'
    
    inputs = [toSock]
    outputs = [ ] 
    message_queue = { }
    # 전송받은 상대 클라이언트 정보를 바탕으로 핑테스트 
    # PingTest(listenSock, peerAddr)
    listenSock.setblocking(False)
    toSock.setblocking(False)
    while True:
        # Get the list sockets which are readable
        timeout = 1
        readable, writable, exceptional = select.select([listenSock, toSock], [], [], timeout)
        # readSock, writeSock, errorSock = select.select([hpSock, toSock], [], [], 1)
        if len(exceptional) != 0:
            # error
            print 'Transfer Error.'
            return 
        if listenSock in readable:
            # print 'listenSock has got some data:', 
            # listenSock is ready for read
            while True:
                try:
                    (serializedData, addr) = listenSock.recvfrom(1024)
                    if serializedData == '':
                        # preserve connection 
                        continue
                    # print serializedData
                except socket.error, e:
                    # errno.EAGAIN : try again
                    # socket error 10035 : Resource temporarily unavailable.
                    if e[0] != errno.EAGAIN and e[0] != 10035:
                        raise e
                    # EAGAIN
                    break
                toSock.sendto(serializedData, serverAddr)
                
        if toSock in writable:
            # print 'toSock has got some data:', 
            # toSock is ready for read
            while True:
                try:
                    next_msg = message_queue[s].get_nowait()
                except:
                    if fromAddr and addr == serverAddr:
                        listenSock.sendto(serializedData, fromAddr)       
        """ 
        for read in readSock:
            #incoming message from remote server
            if read is hpSock:
                serializedData, addr = hpSock.recvfrom(2048)
                recvPacket = HP_Message()
                recvPacket.ParseFromString(serializedData)
                print recvPacket
                
                if recvPacket.command == 'PING':
                    hpSock.sendto(serializedData, (hostIP, hostPort))
                    pass
            #user entered a message
            else :
                # msg = sys.stdin.readline()
                # s.send(msg)
                pass
        """
        
if __name__=='__main__':
    main()
    
    
"""
import socket
import sys
import select
from communication import send, receive

BUFSIZ = 1024

class ChatClient(object):
    A simple command line chat client using select 

    def __init__(self, name, host='127.0.0.1', port=3490):
        self.name = name
        # Quit flag
        self.flag = False
        self.port = int(port)
        self.host = host
        # Initial prompt
        self.prompt='[' + '@'.join((name, socket.gethostname().split('.')[0])) + ']> '
        # Connect to server at port
        try:
            self.sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            self.sock.connect((host, self.port))
            print 'Connected to chat server@%d' % self.port
            # Send my name...
            send(self.sock,'NAME: ' + self.name) 
            data = receive(self.sock)
            # Contains client address, set it
            addr = data.split('CLIENT: ')[1]
            self.prompt = '[' + '@'.join((self.name, addr)) + ']> '
        except socket.error, e:
            print 'Could not connect to chat server @%d' % self.port
            sys.exit(1)

    def cmdloop(self):

        while not self.flag:
            try:
                sys.stdout.write(self.prompt)
                sys.stdout.flush()

                # Wait for input from stdin & socket
                inputready, outputready,exceptrdy = select.select([0, self.sock], [],[])
                
                for i in inputready:
                    if i == 0:
                        data = sys.stdin.readline().strip()
                        if data: send(self.sock, data)
                    elif i == self.sock:
                        data = receive(self.sock)
                        if not data:
                            print 'Shutting down.'
                            self.flag = True
                            break
                        else:
                            sys.stdout.write(data + '\n')
                            sys.stdout.flush()
                            
            except KeyboardInterrupt:
                print 'Interrupted.'
                self.sock.close()
                break
            
            
if __name__ == "__main__":
    import sys

    if len(sys.argv)<3:
        sys.exit('Usage: %s chatid host portno' % sys.argv[0])
        
    client = ChatClient(sys.argv[1],sys.argv[2], int(sys.argv[3]))
    client.cmdloop()
"""