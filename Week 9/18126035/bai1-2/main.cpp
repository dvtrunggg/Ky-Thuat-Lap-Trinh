#include"Bai-1_2.h"

int main()
{
    int* a;
    int n = 4;
    int min = 0;
    int max = 100;
    cout << "Nhap so luong ptu mang: ", cin >> n;
    a = new int[n];
    GenerateArray(a, n, min, max);
    cout << "Mang cua ban: " << endl;
    PrintArray(a, n);

    //cau 1:
    cout << "\nSort: " << endl;
    InterchangeSort_Pointer(a, n);
    PrintArray(a, n);

    //con tro ham
    void(*InterchangeSort_Function_Pointer)(int*, int) = InterchangeSort_Pointer;
    cout << endl;
    (*InterchangeSort_Function_Pointer)(a, n);
    cout << "\ncon tro ham" << endl;
    PrintArray(a, n);
    delete[] a;

   // cau 2
    LIST l;
    Init(l);
    int* b;
    b = new int[n];
    GenerateArray(b, n, min, max);
    cout << "\n==============================================" << endl;
    cout <<"\nday la phan linked list"<< endl;
    cout << "Mang cua ban: " << endl;
    for (int i = 0; i < n; i++)
    {
        addTail(l, *(b + i));
    }
    Output(l);
    cout << "\nSort use linked list: " << endl;
    InterchangeSort_LinkedList(l, b, n);
    // dung con tro ham

    void(*InterchangeSort_Function_LinkedList)(LIST, int*, int) = InterchangeSort_LinkedList;
    cout << endl;
    cout << "Mang sau khi sort( dung linked list)_Con Tro Ham: " << endl;
    (*InterchangeSort_Function_LinkedList)(l, b, n);


    
    delete[] b;
    return 0;
}

