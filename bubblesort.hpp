/**
Bubble Sort

Bubble sort compares each element in the list with the element immediately 
following it. If the first is less than the second, their values are swapped. 
On the first pass, every element in the list is looked at. On each successive 
pass, one less element needs to be examined. The sort is done in place and
requires constant storage with respect to N.

Runtime: 
 O(n) = (n+1)*(n/2) 

*/

void swap (float& a, float& b){
  float tmp = a; a = b; b = tmp;
}

void bubblesort (float* arr, int size)
{
  for (int i=0; i < size; ++i){
    for (int j=0; j < size-i-1; ++j){
      if (arr[j] < arr[j+1]){
        swap (arr[j], arr[j+1]);
      }
    }
  }
}