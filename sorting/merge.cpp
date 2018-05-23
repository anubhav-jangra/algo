// merge sort

#include<iostream>
#include<cstdlib>
#include<limits>
#include<cmath>
using namespace std;


void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1, n2 = r - q;
    int L[n1 + 1], R[n2 + 1], i = 0, j = 0;
    for(int j = 0; j < n1; j++)
        L[j] = A[j + p];
    for(int j = 0; j < n2; j++)
        R[j] = A[j + q + 1];
    L[n1] = numeric_limits<int>::max();
    R[n2] = numeric_limits<int>::max();
    for(int k = p; k <= r; k++)
    {
        if(L[i] < R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void merge_sort(int A[], int p, int r)
{
    if(r > p)
    {
        int q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
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
    
    merge_sort(A, 0, n-1);

    cout<<"Sorted array is : ";
    for(int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    return 0;
}
