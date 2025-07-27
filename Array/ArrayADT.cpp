//WAP IN C++ TO IMPLEMENT ARRAY ABSTRACTION AND IT'S OPERATIONS

#include <iostream>
using namespace std;

class Array
{
    private:
        int *A;
        int size;
        int length;
    public:
        Array()
        {
            size=10;
            A = new int[10];
            length=0;
        }
        Array(int sz)
        {
            size=sz;
            length=0;
            A = new int[size];
        }
        ~Array()
        {
            delete []A;
        }
        void Display();
        void Append(int x);
        void Insert(int index,int x);
        int Delete(int index);
};

void Array::Display()
{
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Array::Append(int x)
{
    if(length < size)
    {
        A[length++]=x;
    }
    else
    {
        cout<<"Array is full. Cannot append."<<endl;
    }
}

void Array :: Insert(int index,int x)
{
    if(index>=0 && index<=length && length < size)
    {
        for(int i=length;i>index;i--)
        {
            A[i]=A[i-1];
        }
        A[index]=x;
        length++;
    }
    else
    {
        cout<<"Invalid index or array full."<<endl;
    }
}

int Array::Delete(int index)
{
    int x;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(int i=index;i<length-1;i++)
        {
            A[i]=A[i+1];
        }
        length--;
        return x;
    }
    cout<<"Invalid index."<<endl;
    return -1;
}

int main()
{
    int size, choice, index, x;
    cout<<"Enter size of the array: ";
    cin>>size;
    Array arr(size);

    do
    {
        cout<<"\nMenu:\n";
        cout<<"1. Display\n";
        cout<<"2. Append\n";
        cout<<"3. Insert\n";
        cout<<"4. Delete\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                arr.Display();
                break;
            case 2:
                cout<<"Enter element to append: ";
                cin>>x;
                arr.Append(x);
                break;
            case 3:
                cout<<"Enter index and element to insert: ";
                cin>>index>>x;
                arr.Insert(index, x);
                break;
            case 4:
                cout<<"Enter index to delete: ";
                cin>>index;
                x = arr.Delete(index);
                if(x != -1)
                    cout<<"Deleted element: "<<x<<endl;
                break;
            case 5:
                cout<<"Exiting program."<<endl;
                break;
            default:
                cout<<"Invalid choice. Try again.\n";
        }

    } while(choice != 5);

    return 0;
}
