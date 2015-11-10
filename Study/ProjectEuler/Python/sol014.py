# -*- coding: utf-8 -*-
# 가나다라
'''
The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

양의 정수 n에 대하여, 다음과 같은 계산 과정을 반복하기로 합니다.

n → n / 2 (n이 짝수일 때)
n → 3 n + 1 (n이 홀수일 때)

13에 대하여 위의 규칙을 적용해보면 아래처럼 10번의 과정을 통해 1이 됩니다.

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
아직 증명은 되지 않았지만, 이런 과정을 거치면 어떤 수로 시작해도 마지막에는 1로 끝나리라 생각됩니다. 
(역주: 이것은 콜라츠 추측 Collatz Conjecture이라고 하며, 이런 수들을 우박수 hailstone sequence라 부르기도 합니다)

그러면, 백만(1,000,000) 이하의 수로 시작했을 때 1까지 도달하는데 가장 긴 과정을 거치는 숫자는 얼마입니까?

참고: 계산 과정 도중에는 숫자가 백만을 넘어가도 괜찮습니다.
'''
import time
 
# TODO: 문제가 원하는 답은 구했으나, 실행시간이 매우 길어(약 16초) 개선이 필요하다. 
# def find_chain_count(hailstone_sequence):
# 	count = 1
# 	while hailstone_sequence > 1:
# 		if hailstone_sequence % 2 == 0:
# 			hailstone_sequence = hailstone_sequence / 2
# 		else:
# 			hailstone_sequence = 3 * hailstone_sequence + 1
# 		count += 1
# 	return count

# def find_longest_chain():
# 	longest_chain = 1
# 	has_longest_chain_number = 1
# 	for number in range(1000000):
# 		count = find_chain_count(number)
# 		if count > longest_chain:
# 			longest_chain = count
# 			has_longest_chain_number = number
# 	return has_longest_chain_number

start = time.time()
longest_chain_number = find_longest_chain()
elapsed = time.time() - start

print "Longest chain number is %s and it returned in %s seconds." % (longest_chain_number, elapsed)
