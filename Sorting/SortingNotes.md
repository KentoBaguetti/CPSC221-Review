# Sorting

## Selection Sort
- Repeatedly finds the smallest item <br>
- *Selects* the smallest item and puts it into place at the front (Sorting in ascending order) <br>
- The array is divided into a sorted part and an unsorted part <br>
- Repeatedly swap the first *unsorted* item with the smallest *sorted* item <br><br>
- For *n* unsorted elements, the algorithm makes *n-1* comparisons throughout the array <br><br>

- Example:
- First item is considered *unsorted* and we alr know its value, check every other element in the array after the first item and find the smallest value. *n-1* operations.
- Swap the smalelst value we found with the first item. It's possible that the first item is the smallest item and we just swap it with itself which doesn't change shit. Still *n-1* comparisons were done.
- We now have *n-1* unsorted elements. So we do *n-2* comparisons.
- Repeat for every element in the array until our array is sorted.
- Time complexity is O(n^2).<br><br>

- Selection sort will always make (n(n-1))/2 comparisons, regardless of the original order of the array <br><br>

- All in all, selection sort is ass and is only viable in limited systems where reads are cheap but writing is expensive.
- Its only decent to use with small problems we need to sort, or when we can only use a couple lines of code.
- The only decent advantage selection sort may have compared to something like merge sort is that everything happens in place. But at that point use quick sort or insertion sort. <br><br>

## Insertion Sort
