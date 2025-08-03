#include <iostream>
using namespace std;

class Array 
{
private:
    int* A;
    int size;
    int length;

public:
    Array(int sz) 
    {
        size = sz;
        length = 0;
        A = new int[size];
    }

    ~Array() 
    {
        delete[] A;
    }

    void input() 
    {
        cout << "Enter number of elements (max " << size << "): ";
        cin >> length;
        if (length > size) length = size;

        cout << "Enter " << length << " sorted elements:\n";
        for (int i = 0; i < length; i++) {
            cin >> A[i];
        }
    }

    void display() 
    {
        cout << "Array elements: ";
        for (int i = 0; i < length; i++) 
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int BinSearch(int key) 
    {
        int low = 0;
        int high = length - 1;

        while (low <= high) 
        {
            int mid = (low + high) / 2;
            if (A[mid] == key)
                return mid;
            else if (key < A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1; 
    }
};

int main() 
{
    int size;
    cout << "Enter array size: ";
    cin >> size;

    Array arr(size);
    arr.input();

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int index = arr.BinSearch(key);

    arr.display();
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}
