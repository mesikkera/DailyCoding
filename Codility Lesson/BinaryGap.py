"""
    BinaryGap
    Find longest sequence of zeros in binary representation of an integer.


    A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded
    by ones at both ends in the binary representation of N.
    For example, number 9 has binary representation 1001 and contains a binary gap of length 2.
    The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.
    The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps.

    Write a function:

    def solution(N)
    that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

    For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5.

    Assume that:

    N is an integer within the range [1..2,147,483,647].

    Complexity:
    expected worst-case time complexity is O(log(N));
    expected worst-case space complexity is O(1).

    Copyright 2009–2016 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.
"""

# -*- coding: utf-8 -*-
# 가나다라

import time

# 정수 N --> 2진수
# 가장 긴 0의 연속 개수

def solution(N):
    binary_number = bin(N)
    max_gap = 0
    current_gap = 0
    max_sequence = 0
    for digit in binary_number[2:]:
        if digit == '0':
            current_gap += 1
        elif digit == '1':
            max_gap = max(max_gap, current_gap)
            current_gap = 0
    return max_gap

def solution2(N):
    pass

def main():
    start_time = time.time()
    result = solution(1041)
    elapsed_time = time.time() - start_time
    print("Result(1041): ", result)
    print("Elapsed Time using solution1(1041): ", elapsed_time)

    start_time = time.time()
    result = solution(1376796946)
    elapsed_time = time.time() - start_time
    print("Result(1376796946): ", result)
    print("Elapsed Time using solution1(1376796946): ", elapsed_time)

if __name__ == '__main__':
    main()
