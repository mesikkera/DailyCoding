from functools import reduce

factorial = reduce(lambda x, y: x * y, range(1, 10))
print(factorial)
