def simple_hash(s, table_size):
    total = 0
    for char in s:
        total += ord(char)
    return total % table_size

table_size = 10
print(simple_hash("hello", table_size)) 
print(simple_hash("world", table_size)) 
