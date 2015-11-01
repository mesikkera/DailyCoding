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
 
def is_prime(n):
    if n % 2 == 0: 
    	return False
    p = 3
    while p < n**0.5+1:
        if n % p == 0: 
        	return False
        p += 2
    return True
 
def find_nth_prime(n):
    prime_number = 2
    count = 1
    iter = 3
    while count < n:
        if is_prime(iter):
            prime_number = iter
            count += 1
        iter += 2
    return prime_number
 
start = time.time()
prime = find_nth_prime(10001)
elapsed = (time.time() - start)
 
print "found %s in %s seconds" % (prime,elapsed)