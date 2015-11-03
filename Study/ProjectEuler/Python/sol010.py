# -*- coding:utf-8 -*-
# 가나다라

'''
Summation of primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

10 이하의 소수를 모두 더하면 2 + 3 + 5 + 7 = 17 이 됩니다.

이백만(2,000,000) 이하 소수의 합은 얼마입니까?
'''
import time

def is_prime(number): 
	if number % 2 == 0:  
		return False 
	odd_number = 3
	while odd_number < number**0.5+1:
		if number % odd_number == 0: 
			return False
    	odd_number += 2 
    	return True

def find_summation_of_primes(end_number):
	summation_of_primes = 0
	for number in range(1, end_number+1, 1):
		if is_prime(number):
			summation_of_primes += number
	return summation_of_primes

start = time.time()
summation_of_primes = find_summation_of_primes(2000000)
elapsed = time.time() - start

print "found %s returned in %s seconds." % (summation_of_primes,elapsed)