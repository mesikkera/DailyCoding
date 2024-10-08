def polynomial_hash(s, base=31, modulus=2**64):
    hash_value = 0
    for char in s:
        hash_value = (hash_value * base + ord(char)) % modulus
    return hash_value


print(polynomial_hash("hello"))
print(polynomial_hash("world"))

