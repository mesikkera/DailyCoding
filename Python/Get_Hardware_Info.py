# author: mesikkera
# -*- coding: utf-8 -*-
# 가나다라

# pip install uuid
from uuid import getnode as get_mac
import psutil

# get mac address as integer.
mac = get_mac()

# get pid and process names
for proc in psutil.process_iter():
    try:
        pinfo = proc.as_dict(attrs=['pid', 'name'])
    except psutil.NoSuchProcess:
        pass
    else:
        print(pinfo)

if __name__ == "__main__":
	print "mac: ", mac
