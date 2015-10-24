# -*- coding: UTF-8 -*-
# Server Class

import daemon
from SocketServer import ThreadingMixIn, UDPServer

__version__ = "0.1"
__auther__ = "mesikkera"


class ServerUDP(ThreadingMixIn, UDPServer):
    allow_reuse_address = True
    request_queue_size = 100


    # Server start
    def start(self, daemon_process=False):
        if daemon_process is True:

            self.context = daemon.DaemonContext(

            )



