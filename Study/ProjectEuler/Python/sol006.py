# -*- coding: utf-8 -*-
# 가나다라

'''
The sum of the squares of the first ten natural numbers is,

12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
'''
import time

def the_sum_of_the_squares(the_number):
	sum = 0
	for number in range(1, the_number, 1):
		sum += (number * number)
	return sum


def the_square_of_the_sum(the_number):
	sum = 0
	for number in range(1, the_number, 1):
		sum += number 
	return sum * sum


def difference_between(number):
	result_of_sum = the_sum_of_the_squares(number)
	result_of_square = the_square_of_the_sum(number)
	difference_between = result_of_square - result_of_sum
	return difference_between

start = time.time()
product = difference_between(100)
elapsed = (time.time() - start)
 
print "result %s returned in %s seconds." % (product,elapsed)