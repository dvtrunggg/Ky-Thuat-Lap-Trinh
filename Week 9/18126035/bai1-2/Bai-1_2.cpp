#include"Bai-1_2.h"

void InputArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ", cin >> *(a+i);
    }
}
void GenerateArray(int *a, const int& n, const int min, const int max)
{
    srand(1000);
    for (int i = 0; i < n; i++)
    {
        *(a+i) = min + (rand() % (max - min + 1));
    }
}

void PrintArray(int *a, int n)
{
    cout << "======================================" << endl;
    cout << "a[] = ";
    for (int i = 0; i < n; i++)
        cout << "   " << *(a+i);
}


//câu 1:
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void InterchangeSort_Pointer(int* a,int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(a + i) > *(a + j))
            {
                Swap(*(a + i), *(a + j));
            }
        }
    }
}



void Init(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* createNode(int data)
{
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;		// khong du bo nho de cap phat
    p->data = data;
    p->pNext = NULL;
    return p;
}
void Output(LIST l)
{
    for (NODE* i = l.pHead; i != NULL; i = i->pNext)
    {
        cout << i->data << "  ";
    }
}


int listLen(LIST l)
{
    int count = 0;
    for (NODE* i = l.pHead; i != NULL; i = i->pNext)
    {
        count++;
    }
    return count;
}

void InterchangeSort_LinkedList(LIST l, int* a, int n)
{
    LIST l2;
    Init(l2);
    InterchangeSort_Pointer(a, n);
    for (int i = 0; i < n; i++)
    {
        addTail(l2, *(a + i));
    }
    Output(l2);
    
}

void addTail(LIST& l, int data)
{
    NODE* p = createNode(data);
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}