# -*- coding: utf-8 -*-
# 가나다라

'''
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.


How many such routes are there through a 20×20 grid?

왼쪽 최상단 끝에서 오른쪽 최하단 끝까지 갈 수 있는 길의 수 찾기.
'''

import time

def find_route_count(length, height):
	count = 0
	return count

start = time.time()
route_count = find_route_count(20,20)
elapsed = time.time() - start

"모든 길의 수는 %s개이며, 길의 수를 세는데 걸린 시간은 %S이다.", (route_count, elapsed)
