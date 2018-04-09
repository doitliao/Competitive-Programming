#include <bits/stdc++.h>

using namespace std;

unsigned long long  _mergeSort(unsigned arr[], unsigned temp[], int left, int right);
unsigned long long merge(unsigned arr[], unsigned temp[], int left, int mid, int right);
 
/* This function sorts the input array and returns the
 *    number of inversions in the array */
unsigned long long mergeSort(unsigned arr[], int array_size)
{
      unsigned *temp = (unsigned *)malloc(sizeof(unsigned)*array_size);
          return _mergeSort(arr, temp, 0, array_size - 1);
}
 
/* An auxiliary recursive function that sorts the input array and
 *   returns the number of inversions in the array. */
unsigned long long  _mergeSort(unsigned arr[], unsigned temp[], int left, int right)
{
    int mid;
    unsigned long long inv_count = 0;
      if (right > left)
          {
                /* Divide the array into two parts and call _mergeSortAndCountInv()
                 *        for each of the parts */
                mid = (right + left)/2;
                 
                    /* Inversion count will be sum of inversions in left-part, right-part
                     *       and number of inversions in merging */
                    inv_count  = _mergeSort(arr, temp, left, mid);
                        inv_count += _mergeSort(arr, temp, mid+1, right);
                         
                            /*Merge the two parts*/
                            inv_count += merge(arr, temp, left, mid+1, right);
                              }
        return inv_count;
}
 
/* This funt merges two sorted arrays and returns inversion count in
 *    the arrays.*/
unsigned long long merge(unsigned arr[], unsigned temp[], int left, int mid, int right)
{
    int i, j, k;
      unsigned long long  inv_count = 0;
       
        i = left; /* i is index for left subarray*/
          j = mid;  /* j is index for right subarray*/
            k = left; /* k is index for resultant merged subarray*/
              while ((i <= mid - 1) && (j <= right))
                  {
                        if (arr[i] <= arr[j])
                              {
                                      temp[k++] = arr[i++];
                                          }
                            else
                                  {
                                          temp[k++] = arr[j++];
                                           
                                               /*this is tricky -- see above explanation/diagram for merge()*/
                                                inv_count = inv_count + (mid - i);
                                                    }
                              }
               
                /* Copy the remaining elements of left subarray
                 *    (if there are any) to temp*/
                while (i <= mid - 1)
                      temp[k++] = arr[i++];
                 
                  /* Copy the remaining elements of right subarray
                   *    (if there are any) to temp*/
                  while (j <= right)
                        temp[k++] = arr[j++];
                   
                    /*Copy back the merged elements to original array*/
                    for (i=left; i <= right; i++)
                          arr[i] = temp[i];
                     
                      return inv_count;
}

unsigned a[500009];

int main() {
  int n;
  while(true){
    scanf("%d", &n);
    if(n == 0) break;

    for(int i = 0;  i < n; i++){
      scanf("%u", &a[i]);
    }

    printf("%llu\n", mergeSort(a, n));
  }

}
