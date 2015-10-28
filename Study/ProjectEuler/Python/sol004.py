# -*- coding: utf-8 -*-
# 가나다라
'''
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.



앞에서부터 읽을 때나 뒤에서부터 읽을 때나 모양이 같은 수를 대칭수(palindrome)라고 부릅니다.

두 자리 수를 곱해 만들 수 있는 대칭수 중 가장 큰 수는 9009 (= 91 × 99) 입니다.

세 자리 수를 곱해 만들 수 있는 가장 큰 대칭수는 얼마입니까?
'''
# 3-digit number * 3-digit number = 6-digit number
# len(6-digit number) > 5

# if palindrome is str
# palindrome[0] == palindrome[5]
# palindrome[1] == palindrome[4]
# palindrome[2] == palindrome[3]

# simple sol 001
# number1: range(1000, 100, -1)
# number2: range(1000, 100, -1)
largest_palindrome = 0
for number1 in range(1000, 100, -1):
	for number2 in range(1000, 100, -1):
		temp = number1 * number2
		temp_palindrome = str(temp)
		if len(temp_palindrome) > 5:
			if temp_palindrome[0] == temp_palindrome[5]:
				if temp_palindrome[1] == temp_palindrome[4]:
					if temp_palindrome[2] == temp_palindrome[3]:	
						if temp_palindrome > largest_palindrome:	
							largest_palindrome = temp_palindrome
							print "largest_palindrome: ", largest_palindrome
					else:
						pass
				else:
					pass
			else:
				pass
		else:
			pass
			
'''
run:
largest_palindrome:  580085
largest_palindrome:  906609
[Finished in 0.4s]
'''






