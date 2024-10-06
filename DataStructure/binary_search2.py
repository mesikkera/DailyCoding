from typing import List
import time

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
    step = 0
    start_time = time.time()
    
    while left <= right:
        step += 1
        mid = (left + right) // 2
        current_time = time.time() - start_time
        print(f"Step {step} (Time: {current_time:.6f}s): Searching between indices {left} and {right}. Mid: {mid}, Value: {arr[mid]}")
        
        if arr[mid] == target:
            print(f"Target found at index {mid}")
            return mid
        elif arr[mid] < target:
            left = mid + 1
            print(f"Target is greater. Moving left boundary to {left}")
        else:
            right = mid - 1
            print(f"Target is smaller. Moving right boundary to {right}")
    
    print("Target not found")
    return -1

def binary_search_recursive(arr: List[int], target: int, left: int, right: int, step: int = 0, start_time: float = None) -> int:
    """
    Recursive implementation of binary search
    
    Args:
    arr (List[int]): Sorted list of integers
    target (int): The value to search for
    left (int): The left boundary of the search
    right (int): The right boundary of the search
    step (int): The current step number (for display purposes)
    start_time (float): The start time of the search
    
    Returns:
    int: The index of the target if found, -1 otherwise
    """
    if start_time is None:
        start_time = time.time()
    
    step += 1
    current_time = time.time() - start_time
    print(f"Step {step} (Time: {current_time:.6f}s): Searching between indices {left} and {right}.")
    
    if left <= right:
        mid = (left + right) // 2
        print(f"Mid: {mid}, Value: {arr[mid]}")
        
        if arr[mid] == target:
            print(f"Target found at index {mid}")
            return mid
        elif arr[mid] < target:
            print(f"Target is greater. Moving left boundary to {mid + 1}")
            return binary_search_recursive(arr, target, mid + 1, right, step, start_time)
        else:
            print(f"Target is smaller. Moving right boundary to {mid - 1}")
            return binary_search_recursive(arr, target, left, mid - 1, step, start_time)
    
    print("Target not found")
    return -1

def main():
    arr = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    target = 13
    
    print(f"Array: {arr}")
    print(f"Target: {target}")
    
    print("\nIterative Binary Search:")
    iterative_start = time.time()
    iterative_result = binary_search_iterative(arr, target)
    iterative_end = time.time()
    print(f"Iterative Binary Search Result: {iterative_result}")
    print(f"Total time for iterative search: {iterative_end - iterative_start:.6f}s")
    
    print("\nRecursive Binary Search:")
    recursive_start = time.time()
    recursive_result = binary_search_recursive(arr, target, 0, len(arr) - 1)
    recursive_end = time.time()
    print(f"Recursive Binary Search Result: {recursive_result}")
    print(f"Total time for recursive search: {recursive_end - recursive_start:.6f}s")

if __name__ == "__main__":
    main()

