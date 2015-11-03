# -*- coding: utf-8 -*-
# 가나다라 
'''
Special Pythagorean triplet

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a**2 + b**2 = c**2
For example, 3**2 + 4**2 = 9 + 16 = 25 = 5**2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

세 자연수 a, b, c 가 피타고라스 정리 a2 + b2 = c2 를 만족하면 피타고라스 수라고 부릅니다 (여기서 a < b < c ).

예를 들면 3의 제곱 + 4의 제곱 = 9 + 16 = 25 = 5의 제곱 이므로 3, 4, 5는 피타고라스 수입니다.

a + b + c = 1000 인 피타고라스 수 a, b, c는 한 가지 뿐입니다. 이 때, a × b × c 는 얼마입니까?
'''
import time

# solution 1. 단순 & 무식
def find_pythagorean_triplet(number):
	# a < b < c
	# a + b + c = 1000
	for a in range(1, number+1, 1):
		for b in range(a+1, number+1, 1):
			c = ((a ** 2) + (b ** 2))**(0.5)
			if a + b + c == number:
				return a * b * c
	
start = time.time()
product = find_pythagorean_triplet(1000)
elapsed = (time.time() - start)

print "found %s in %s seconds" % (product,elapsed)