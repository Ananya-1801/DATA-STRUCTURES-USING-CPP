#include <iostream>
using namespace std;

void reverse(int *a, int s, int e)
{
    while (s < e)
    {
        int temp = *(a + s);
        *(a + s) = *(a + e);
        *(a + e) = temp;

        s++;
        e--;
    }
}

void display(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n,k; 
    cout << "Enter the size of the array:";
    cin>>n;

    int *arr = new int[n];

    cout<<"Enter the elements in the array:";

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    cout<<"Enter the number of elements by which array has to be rotated:";
    cin>>k;

    reverse(arr,0,n-k-1);
    reverse(arr,n-k,n-1);
    reverse(arr,0,n-1);

    display(arr,n);
    
    delete []arr;

    return 0;
}