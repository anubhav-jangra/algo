// quick sort

#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
using namespace std;


int partition(int A[], int p, int q) {
    int i = p-1, j = p;
    for(j; j < q; j++) {
        if(A[j] <= A[q])
            swap(A[++i], A[j]);
    }
    swap(A[i+1], A[q]);
    return i + 1;
}

void quick_sort(int A[], int p, int r)
{
    if(p < r)
    {
        int q = partition(A, p, r);
        quick_sort(A, p, q - 1);
        quick_sort(A, q + 1, r);
    }
}
int main()
{
    int n;
    cout<<"Gimme the size of array: ";
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++)
        cin>>A[i];
    
    quick_sort(A, 0, n-1);

    cout<<"Sorted array is : ";
    for(int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    return 0;
}
