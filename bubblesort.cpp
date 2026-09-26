#include<iostream>
using namespace std;
int main()
{
    int size = 5;
    int arr[] = {5, 2, 1, 4, 7};
    for(int i = 0; i < size ;i++)
    {
        for(int j = 0;j<size-1-i;j++)
        {
           if(arr[j]>arr[j+1])
            {
              swap(arr[i],arr[j+1]);
            }
        }
    };
        for(int i=0;i<size;i++)
        {
         cout<<arr[i]<<" ";
        }
    return 0;
}