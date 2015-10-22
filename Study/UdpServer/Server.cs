using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

public class UdpSrvrSample
{
    public static void Main()
    {
        byte[] data = new byte[1024];
        //IPEndPoint ipep = new IPEndPoint(IPAddress.Any, 9050);
        //UdpClient newsock = new UdpClient(ipep);
        UdpClient newsock = new UdpClient();

        IPEndPoint sender = new IPEndPoint(IPAddress.Any, 0);

        byte[] temp = new byte[1];
        temp[0] = 0x60;
        newsock.Send(temp, temp.Length, "192.168.1.123", 8854);
        data = newsock.Receive(ref sender);
        if (data[0] == 0x70)
        {
            ushort[] rPort = new ushort[1];
            byte[] portByte = new byte[2];
            portByte[1] = data[1];
            portByte[0] = data[2];
            Buffer.BlockCopy(portByte, 0, rPort, 0, 2);
            Console.WriteLine("External IP Of This Server is...");
            Console.WriteLine(data[3].ToString() + "." + data[4].ToString() + "." + data[5].ToString() + "." + data[6].ToString() + " : " + rPort[0].ToString());
        }

        Console.WriteLine("Waiting for a client...");

        

        data = newsock.Receive(ref sender);

        Console.WriteLine("Message received from {0}:", sender.ToString());
        Console.WriteLine(Encoding.ASCII.GetString(data, 0, data.Length));

        string welcome = "Welcome to my test server";
        data = Encoding.ASCII.GetBytes(welcome);
        newsock.Send(data, data.Length, sender);

        while (true)
        {
            data = newsock.Receive(ref sender);

            Console.WriteLine(Encoding.ASCII.GetString(data, 0, data.Length));
            newsock.Send(data, data.Length, sender);
        }
    }
}