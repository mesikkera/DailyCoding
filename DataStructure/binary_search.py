from typing import List

def binary_search_iterative(arr: List[int], target: int) -> int:
    """
    Iterative implementation of binary search
    
    Args:
    arr (List[int]): Sorted list of integers
    target (int): The value to search for
    
    Returns:
    int: The index of the target if found, -1 otherwise
    """
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1  # Target not found

def binary_search_recursive(arr: List[int], target: int, left: int, right: int) -> int:
    """
    Recursive implementation of binary search
    
    Args:
    arr (List[int]): Sorted list of integers
    target (int): The value to search for
    left (int): The left boundary of the search
    right (int): The right boundary of the search
    
    Returns:
    int: The index of the target if found, -1 otherwise
    """
    if left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            return binary_search_recursive(arr, target, mid + 1, right)
        else:
            return binary_search_recursive(arr, target, left, mid - 1)
    
    return -1  # Target not found

# Test the functions
def main():
    arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 13
    
    print(f"Array: {arr}")
    print(f"Target: {target}")
    
    iterative_result = binary_search_iterative(arr, target)
    print(f"Iterative Binary Search Result: {iterative_result}")
    
    recursive_result = binary_search_recursive(arr, target, 0, len(arr) - 1)
    print(f"Recursive Binary Search Result: {recursive_result}")

if __name__ == "__main__":
    main()

