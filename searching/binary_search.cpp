#include<iostream>
using namespace std;

int binarySearch(int arr[], int x, int min, int max)
{
    if(min > max)
        return -1;
    int mid = (min + max) / 2;
    if(arr[mid] == x)
        return mid;
    else if(arr[mid] > x)
        return binarySearch(arr, x, min, mid - 1);
    else
        return binarySearch(arr, x, mid + 1, max);
    return -1;
}

int main()
{
    int array[15] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 }; 
    int testValues[9]     = { 0, 3, 12, 13, 22, 26, 43, 44, 49};
    int expectedValues[9] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };
    cout<<"Array is -> ";
    for(int i = 0; i < 15; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < 9; i++)
    {
        int min = 0;
        int max = 14;
        int index = binarySearch(array, testValues[i], min, max);
        cout<<"The value of "<<testValues[i];
        if(index == -1)
            cout<<" doesn't exist"<<endl;
        else
            cout<<" exists on :"<<index<<endl;

        cout<<"The expected answer is :"<<expectedValues[i]<<endl;
        
    }
    return 0;
}
