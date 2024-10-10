def djb2_hash(s):
    hash_value = 5381
    for char in s:
        hash_value = ((hash_value << 5) + hash_value) + ord(char)
    return hash_value & 0xFFFFFFFF 

# Example
print(djb2_hash("hello"))  
print(djb2_hash("world"))  
