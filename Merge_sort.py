import random
import time
import sys

# --- MERGE SORT IMPLEMENTATION ---
def merge_sort(arr):
    """
    Recursively splits and merges the array.
    """
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0
        # Merge the two halves
        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        # Copy the remaining elements of left_half, if any
        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        # Copy the remaining elements of right_half, if any
        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1

def main():
    """
    Usage: python merge_sort.py <n>
      - n is the size of the array to sort. Default = 1e6 (1 million).
    """
    if len(sys.argv) > 1:
        n = int(sys.argv[1])
    else:
        n = 10**6  # Default size if no argument is given

    print(f"Generating array of size {n} ...")
    arr = [random.randint(0, 10**9) for _ in range(n)]

    print("Starting merge sort...")
    start_time = time.time()
    merge_sort(arr)
    end_time = time.time()

    print(f"Time taken to sort {n} elements: {end_time - start_time:.4f} seconds")

    # Optional: check if array is sorted
    # (This can be expensive to do for large n, so you may remove this check.)
    assert all(arr[i] <= arr[i+1] for i in range(n-1)), "Array is not sorted!"

if __name__ == "__main__":
    main()
