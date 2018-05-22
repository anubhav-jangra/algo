// insertion sort

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
    for(int j = 1; j < n; j++)
    {
        int key = A[j];
        int i = j-1;
        while(i >= 0 && A[i] > key)
            A[i + 1] = A[i--];
        A[i+1] = key;
    }
    cout<<"Sorted array is : ";
    for(int i = 0; i < n; i++)
        cout<<A[i]<<" ";
    return 0;
}
