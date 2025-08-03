#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
public:
    LinkedList()
    {
        first = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int x);
    int Delete(int index);
    int Length();
    Node* Search(int key);
    int Sum();
    int Max();
    void Reverse();
};

LinkedList::LinkedList(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList::Display()
{
    Node *p = first;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int LinkedList::Length()
{
    Node *p = first;
    int len = 0;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}

void LinkedList::Insert(int index, int x)
{
    Node *t, *p = first;
    if (index < 0 || index > Length())
        return;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int LinkedList::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;

    if (index < 1 || index > Length())
    {
        return -1;
    }
    if (index == 1)
    {
        p = first;
        first = first->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = first;
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

Node* LinkedList::Search(int key)
{
    Node *p = first;
    while (p)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

int LinkedList::Sum()
{
    Node *p = first;
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int LinkedList::Max()
{
    Node *p = first;
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

void LinkedList::Reverse()
{
    Node *p = first;
    Node *q = NULL, *r = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

int main()
{
    LinkedList *ll = NULL;
    int choice;

    do
    {
        cout << "\n****** OPERATIONS ON LINKED LIST **********\n";
        cout << "1.CREATE\n";
        cout << "2.DISPLAY\n";
        cout << "3.INSERT\n";
        cout << "4.DELETE\n";
        cout << "5.SEARCH\n";
        cout << "6.SUM\n";
        cout << "7.MAX\n";
        cout << "8.COUNT NODES\n";
        cout << "9.REVERSE\n";
        cout << "10.EXIT\n";
        cout << "Enter your choice(1-10): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            {
                int n;
                cout << "Enter number of elements: ";
                cin >> n;
                int *A = new int[n];
                cout << "Enter elements: ";
                for (int i = 0; i < n; i++)
                    cin >> A[i];
                ll = new LinkedList(A, n);
                delete[] A;
                break;
            }
        case 2:
            if (ll)
                ll->Display();
            else
                cout << "List not created yet.\n";
            break;

        case 3:
            {
                int index, val;
                cout << "Enter index and value to insert: ";
                cin >> index >> val;
                if (ll)
                    ll->Insert(index, val);
                else
                    cout << "List not created yet.\n";
                break;
            }

        case 4:
            {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                if (ll)
                {
                    int x = ll->Delete(index);
                    if (x != -1)
                        cout << "Deleted element: " << x << endl;
                    else
                        cout << "Invalid index.\n";
                }
                else
                    cout << "List not created yet.\n";
                break;
            }

        case 5:
            {
                int key;
                cout << "Enter element to search: ";
                cin >> key;
                if (ll)
                {
                    Node *res = ll->Search(key);
                    if (res)
                        cout << "Element found at address: " << res << endl;
                    else
                        cout << "Element not found.\n";
                }
                else
                    cout << "List not created yet.\n";
                break;
            }

        case 6:
            if (ll)
                cout << "Sum of elements: " << ll->Sum() << endl;
            else
                cout << "List not created yet.\n";
            break;

        case 7:
            if (ll)
                cout << "Maximum element: " << ll->Max() << endl;
            else
                cout << "List not created yet.\n";
            break;

        case 8:
            if (ll)
                cout << "Number of nodes: " << ll->Length() << endl;
            else
                cout << "List not created yet.\n";
            break;

        case 9:
            if (ll)
            {
                ll->Reverse();
                cout << "List reversed.\n";
            }
            else
                cout << "List not created yet.\n";
            break;

        case 10:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 10);

    delete ll;
    return 0;
}
