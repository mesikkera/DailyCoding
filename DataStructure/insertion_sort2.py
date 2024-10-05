from typing import List

def insertion_sort(arr: List[int]) -> List[int]:
    """
    Sorts a list of integers using the insertion sort algorithm and prints each step.
    
    Args:
    arr (List[int]): The list of integers to be sorted
    
    Returns:
    List[int]: The sorted list of integers
    """
    print(f"Initial array: {arr}")
    
    for i in range(1, len(arr)):
        key: int = arr[i]
        j: int = i - 1
        
        print(f"\nStep {i}: Inserting {key}")
        print(f"  Current array: {arr}")
        
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        arr[j + 1] = key
        
        print(f"  After insertion: {arr}")
    
    return arr

def main() -> None:
    arr: List[int] = [64, 34, 25, 12, 22, 11, 90]
    print("Array before sorting:")
    print(arr)
    print("\nSorting process:")
    
    sorted_arr: List[int] = insertion_sort(arr)
    
    print("\nArray after sorting:")
    print(sorted_arr)

if __name__ == "__main__":
    main()

