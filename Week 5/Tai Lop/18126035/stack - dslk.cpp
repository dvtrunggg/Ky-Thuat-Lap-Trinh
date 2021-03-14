//MSSV:18126035
//Bai Tap Tren Lop tuan 5
//	Stack dung dslk 


#include<iostream>
using namespace std;

struct NODE {		
	int data;
	NODE* pNext;
};

struct Stack {
	NODE* pTop;		// con trỏ đầu quản lý stack
};

// khoi tao stack rong
void Init(Stack& s)
{
	s.pTop = NULL;
}
bool isEmty(Stack s)
{
	if (s.pTop == NULL)
	{
		return true;
	}
	return false;
}
NODE* createNODE(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		cout << "Khong du bo nho de cap phat" << endl;
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;

}
// them 1 ptu vao dau stack
void Push(Stack& s, int x)
{
	NODE* p = createNODE(x);
	if (isEmty(s) == true)	// ds rong
	{
		s.pTop = p;
	}
	else				// ds co ptu
	{
		p->pNext = s.pTop;
		s.pTop = p;
	}
}

// lay ptu o dau nhung ko xoa
int Top(Stack& s)
{
	
		return s.pTop->data;
}

// lay ptu dau stack va huy no di
void Pop(Stack& s)
{
	//if (isEmty(s) == true)		// ds rong
	//{
	//	cout << "ds rong";
	//}
	/*else*/
	{
		int x;
		x = s.pTop->data;
		s.pTop = s.pTop->pNext;
	}
}
void Output(Stack s)
{
	if (isEmty(s) == true)
	{
		cout << "Danh sach rong" << endl;
	}
	while (isEmty(s) == false)
	{
		cout << Top(s) << "\t";
		Pop(s);
	}
}
// xoa tat ca 
void Delete(Stack& s)
{
	while (isEmty(s) == false)
	{
		 Pop(s);
	}
}
int main()
{
	Stack s;
	Init(s);
	Push(s, 1);
	Push(s, 2);
	Push(s, 3);
	Push(s, 4);
	//cout << Top(s);
	//Output(s);
	Pop(s);
	Output(s);
	/*Delete(s);
	if (isEmty(s) == true)
		cout << "stack rong";*/
	
	return 0;
}