# -*- coding:utf-8 -*-
# 가나다라

'''
10001st prime

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

10001번째 소수

처음 여섯개의 소수는 2, 3, 5, 7, 11, 13이다. 이중에 6번째 소수는 13이다. 

10001번째 소수는 무엇인가?
'''
import time

# def is_prime(natural_number):
# 	# prime number: 1과 자기자신외에는 나누어어지지 않는 수
# 	is_prime_number = False
# 	for number in range(1, natural_number, 1):
# 		if natural_number % number != 0 and natural_number % natural_number == 0:
# 			is_prime_number == True
# 	return is_prime_number


def prime_number(natural_number):
	prime_number_list = []
	number = 1
	while True:
		if 4natural_number % number != 0:
			prime_number_list.append(number)

		if natural_number == number:
			break
		number += 1
	print prime_number_list

start = time.time()
product = prime_number(100)
elapsed = time.time() - start

print "result %s returned in %s seconds." % (product,elapsed)