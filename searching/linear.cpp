#include<iostream>
using namespace std;

int linear_search(int arr[], int len, int n)
{
    for(int i = 0; i < len; i++)
        if(arr[i] == n)
            return i;
    return -1;
}

int main()
{
    int arr[10] = {5, 2, 7, 8, 1, 29, 47, 37, 68, 4};
    cout<<" Provided array is -> ";
    for(int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n Choose a number whoes index you wanna know : ";
    int num;
    cin>>num;
    int index = linear_search(arr, 10, num);
    cout<<" Index of given number is - "<<index;
}
