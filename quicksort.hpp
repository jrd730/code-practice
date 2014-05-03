/**
Quick Sort

Quick sort works by recursively dividing the original list into to partitions
around a chosen median value where the elements in one partition are less than 
the median value and the elements in the other partition are greater than the 
median. In this implementation, the median value is chosen to be the median of 
the first, middle, and last elements in the list. This sort is done in place,
and uses constant storage with respect to N.

Runtime:
  O(n) = n log (n) average

*/

void swp (float& a, float& b){
  float tmp = a; a = b; b = tmp;
}

int medianOfThree (float* arr, int a, int b, int c)
{
  if (arr[a] < arr[b]){
    if (arr[b] < arr[c]){
      return b;
    }
    else { // arr[b] >= arr[c] 
      if (arr[a] < arr[c]) { 
        return c;
      }
      else { // arr[a] >= arr[c]
        return a;
      }
    }
  }
  else {// arr[a] >= arr[b] 
    if (arr[a] < arr[c]){
      return a;
    }
    else { // arr[a] >= arr[c] 
      if (arr[b] < arr[c]){
        return c;
      }
      else { // arr[b] >= arr[c] 
        return b;
      }
    }
  }
}

float selectPivot (float* arr, int size)
{
  return medianOfThree (arr, 0, size/2, size-1);
}

void quicksort (float* arr, int size)
{
  if (size <= 1) return;
  else{
    int pivot = selectPivot (arr, size);
    swp (arr[size-1], arr[pivot]);
    pivot = size-1;
    
    // put all values less than the pivot value after the pivot
    for (int i=0; i < pivot;){
      if ( (arr[i] < arr[pivot]) ){
        swp (arr[i], arr[pivot-1]);
        swp (arr[pivot-1], arr[pivot]);
        pivot--;
      }
      else{
        i++;
      }
    }
    quicksort (arr, pivot);
    quicksort (arr+pivot, size-pivot);
  }
}