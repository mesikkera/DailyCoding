# -*- coding:utf-8 -*-
# 가나다라

'''
Summation of primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
'''
import time
import math

# def is_prime(number):
#     oldnum = number
#     factor = 1
#     while number > 1:
#         factor += 1
#         if number % factor == 0:
#             if 1 < factor < oldnum:
#                 return False # is not prime
#             number //= factor
#     return True # is prime!

# def is_prime(n):
#     for i in range(3, n):
#         if n % i == 0:
#             return False
#     return True

# def is_prime(n):
#     for x in xrange(3, int(n**0.5)+1):
#         if n % x == 0:
#             return False
#     return True    

# def eratosthenes(n):
#      multiples = set()
#      for i in range(2, n+1):
#         if i not in multiples:
#             yield i
#             multiples.update(range(i*i, n+1, i))
#   	print(list(eratosthenes(2000000)))

def is_prime(number):
	for factor in xrange(3, int(number**0.5) + 1, 2):
		if number % factor == 0:
			return False 
	return True

def find_summation_of_primes(end_number):
	summation_of_primes = 2

	# 홀수만 검사
	for number in range(3, end_number+1, 2):
		if is_prime(number):
			summation_of_primes += number
	return summation_of_primes

start = time.time()
summation_of_primes = find_summation_of_primes(2000000)
elapsed = time.time() - start

print "found %s returned in %s seconds." % (summation_of_primes,elapsed)