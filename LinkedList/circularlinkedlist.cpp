#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CLinkedList
{
private:
    Node *Head;
public:
    CLinkedList()
    {
        Head = NULL;
    }

    CLinkedList(int A[], int n);
    ~CLinkedList();

    void Display();
    int Length();
    void Insert(int index, int x);
    int Delete(int index);
};

CLinkedList::CLinkedList(int A[], int n)
{
    Node *t, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = Head;
        last->next = t;
        last = t;
    }
}

CLinkedList::~CLinkedList()
{
    if (Head == NULL) return;

    Node *p = Head;
    while (p->next != Head)
        p = p->next;

    while (p != Head)
    {
        p->next = Head->next;
        delete Head;
        Head = p->next;
    }

    delete Head;
    Head = NULL;
}

void CLinkedList::Display()
{
    if (Head == NULL) return;

    Node *h = Head;
    do {
        cout << h->data << " ";
        h = h->next;
    } while (h != Head);
    cout << endl;
}

int CLinkedList::Length()
{
    if (Head == NULL) return 0;

    Node *h = Head;
    int len = 0;
    do {
        len++;
        h = h->next;
    } while (h != Head);
    return len;
}

void CLinkedList::Insert(int index, int x)
{
    if (index < 0 || index > Length()) return;

    Node *t = new Node;
    t->data = x;

    if (index == 0)
    {
        if (Head == NULL) {
            Head = t;
            Head->next = Head;
        } 
        else
        {
            Node *p = Head;
            while (p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    } 
    else
    {
        Node *p = Head;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int CLinkedList::Delete(int index)
{
    if (index < 0 || index >= Length())
        return -1;

    int x;
    if (index == 0)
    {
        Node *p = Head;
        while (p->next != Head)
            p = p->next;

        x = Head->data;

        if (Head == p) {
            delete Head;
            Head = NULL;
        } else {
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    } 
    else
    {
        Node *p = Head;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        Node *q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

int main()
{
    int n;
    cout << "Enter number of elements to initialize the circular linked list: ";
    cin >> n;

    int *A = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> A[i];
    }

    CLinkedList cll(A, n);
    delete[] A;

    char ans = 'y';

    do {
        int ch;
        cout << "\n***** OPERATIONS ON CIRCULAR LINKED LIST *****\n";
        cout << "1. DISPLAY\n";
        cout << "2. LENGTH\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. EXIT\n";
        cout << "Enter your choice (1-5): ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cll.Display();
            break;
        case 2:
            cout << "Length: " << cll.Length() << endl;
            break;
        case 3:
            {
                int index, val;
                cout << "Enter index and value to insert: ";
                cin >> index >> val;
                cll.Insert(index, val);
                cout << "Inserted.\n";
                cll.Display();
            }
            break;
        case 4:
            {
                int index;
                cout << "Enter index to delete: ";
                cin >> index;
                int res = cll.Delete(index);
                if (res != -1) {
                    cout << "Deleted value: " << res << endl;
                    cll.Display();
                } else {
                    cout << "Invalid index.\n";
                }
            }
            break;
        case 5:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    return 0;
}
