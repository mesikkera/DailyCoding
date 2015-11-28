# -*- coding: utf-8 -*-
# 가나다라

import time

start = time.time()
while True:
	val1, val2 = raw_input()

elapsed = time.time() - start 

print "주어진 두 수 사이의 모든 수의 자릿수의 합은 %s 이고, 걸린 시간은 %s이다." % (result, elapsed)