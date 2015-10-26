#**********************************************************
# Project Euler Problem 001                                *
#***********************************************************
# Multiples of 3 and 5                                     *
# If we list all the natural numbers below 10 that are     *
# multiples of 3 or 5, we get 3, 5, 6, and 9. The sun of   *
# these multiples is 23. Find the sun of all the multiples *
# of 3 or 5 below 1000.                                    *
#**********************************************************/

result = 0
for number in range(1, 1001, 1):
	if (number % 3 == 0) and (number & 5 == 0):
		result += number
print result
