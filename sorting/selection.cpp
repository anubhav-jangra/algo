// selection sort

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Gimme the size of array: ";
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++)
        cin>>A[i];
    for(int j = 0; j < n-1; j++)
    {
        int min_index = j;
        for(int i = j + 1; i < n; i++)
            if(A[min_index] > A[i])
                min_index = i;
        // swapping the min_index and j
        if(min_index != j) {
            A[min_index]    = A[min_index] + A[j];
            A[j]            = A[min_index] - A[j];
            A[min_index]    = A[min_index] - A[j];
        }
    }
    cout<<"Sorted array is : ";
    for(int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    return 0;
}

