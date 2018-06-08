
// median of medians approach

#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

void swapp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMedian(int arr[], int n) {
    sort(arr, arr+n);
    return arr[n/2];
}

// partitions the array[l, r] around x
int partition(int arr[], int l, int r, int x) {
    // Search for the element x and swap it to end
    int i;
    for(i = l; i < r; i++)
        if(arr[i] == x)
            break;
    swapp(&arr[i], &arr[r]);

    // Standard partition program
    i = l;
    for(int j = l; j < r; j++) {
        if(arr[j] <= x) {
            swapp(&arr[i], &arr[j]);
            i++;
        }
    }
    swapp(&arr[i], &arr[r]);
    return i;
}

// returns kth smallest element from arr[l, r]
int kthSmallest(int arr[], int l, int r, int k) {
    // if k is smaller than the size of range given
    if(k > 0 && k <= r - l + 1) {
        int n = r - l + 1;
        int i, median[(n+4)/5];         // there will be floor((n+4)/5) groups of 5 in given range
        for(i = 0; i < n/5; i++)
            median[i] = findMedian(arr + l + i*5, 5);
        // for last group with less than 5 elements
        if(i*5 < n) {
            median[i] = findMedian(arr + l + i*5, n%5);
            i++;
        }
        // find median of medians using recursive call
        // If median[] has only one element, then no need of recursive call
        int medOfMed = (i == 1) ? median[i-1] : kthSmallest(median, 0, i-1, i/2);

        int pos = partition(arr, l, r, medOfMed);

        if(pos-l == k-1)
            return arr[pos];
        if(pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    // if k is not in apt range
    return numeric_limits<int>::max();
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, n-1, k);
    return 0;
}
