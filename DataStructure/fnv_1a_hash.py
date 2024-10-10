def fnv1a_hash(s):
    hash_value = 0x811C9DC5
    for char in s:
        hash_value ^= ord(char)
        hash_value *= 0x01000193
    return hash_value & 0xFFFFFFFF

# Example
print(fnv1a_hash("hello"))  
print(fnv1a_hash("world"))  

