from typing import List

def insertion_sort(arr: List[int]) -> List[int]:
    """
    Sorts a list of integers using the insertion sort algorithm.
    
    Args:
    arr (List[int]): The list of integers to be sorted
    
    Returns:
    List[int]: The sorted list of integers
    """
    for i in range(1, len(arr)):
        key: int = arr[i]  # Current element to be inserted
        j: int = i - 1     # Index of the last element in the sorted portion
        
        # Move elements greater than key to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        # Insert the key at the correct position
        arr[j + 1] = key
    
    return arr

# Test the function
def main() -> None:
    arr: List[int] = [64, 34, 25, 12, 22, 11, 90]
    print("Array before sorting:", arr)
    
    sorted_arr: List[int] = insertion_sort(arr)
    print("Array after sorting:", sorted_arr)

if __name__ == "__main__":
    main()

