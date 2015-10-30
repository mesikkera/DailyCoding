# -*- coding: utf-8 -*-
# 가나다라
'''
2520 is the smallest number that can be divided by 
each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly 
divisible by all of the numbers from 1 to 20?

1 ~ 10 사이의 어떤 수로도 나누어 떨어지는 가장 작은 수는 2520입니다.

그러면 1 ~ 20 사이의 어떤 수로도 나누어 떨어지는 가장 작은 수는 얼마입니까?
'''

'''
2520 % 1 == 0
2520 % 2 == 0
2520 % 3 == 0
2520 % 4 == 0
2520 % 5 == 0
2520 % 6 == 0
2520 % 7 == 0
2520 % 8 == 0
2520 % 9 == 0
2520 % 10 == 0
'''

'''
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20

2, 3, 5, 7, 11, 13, 17, 19
'''
import time
 
# function to factor a given positive integer n
def factors(n):
    factors = []
    # remove any factors of 2 first
    while n % 2 == 0:
        factors.append(2)
        n = n/2
    # now look for odd factors
    p = 3
    while n != 1:
        while n % p == 0:
            factors.append(p)
            n = n/p
        p += 2
    return factors
 
# merge two lists of factors based on maximum multiplicities
def factor_append(factors,new):
    if len(factors) == 0: return new
    for i in range(len(new)):
        if i > 0 and new[i] == new[i-1]: continue
        new_count = new.count(new[i])
        old_count = factors.count(new[i])
        if new_count > old_count:
            for j in range(new_count - old_count): factors.append(new[i])
    factors.sort()
    return factors
 
# find the smallest positive evenly divisible number for a positive integer n
def smallest_evenly_divisible(num):
    F = []
    for i in range(1,num + 1):
        F = factor_append(F,factors(i))
    product = 1
    for i in F: product *= i
    return product
 
start = time.time()
product = smallest_evenly_divisible(20)
elapsed = (time.time() - start)
 
print "result %s returned in %s seconds." % (product,elapsed)