#include"DSLK_Doi.h"

int main()
{
	List l;
	Node* p1;
	Node* p2;
	Node* p3;
	Node* p4;
	Node* p5;
	Node* p6;
	
	Init(l);
	p1 = addHead(l, 10);
	p2 = addHead(l, 20);
	p4 = addHead(l, 40);
	p5 = addHead(l, 50);
	p6 = addHead(l, 60);
	p3 = addTail(l, 5);
	addSomeWhere(l, 0, 2);
	deleteSomeWhere(l, 2);
	//deleteList(l);
	cout << "Danh sach l: ";
	Xuat(l);
	cout <<"\n=============================================== "<< endl;
	cout <<"ptu o cuoi: " <<getTail(l)<<endl;
	cout <<"ptu o dau: "<< getHead(l)<<endl;
	int n;
	cout <<"ptu vi tri bat ky: "<<Get(l, 3)<<endl;
	Node* p;
	p = Search(l, 5);
	cout <<"search: "<< p->data;
	cout << "\nchieu dai cua list: " << Size(l)<<endl;

	List l2;
	Node* a1; 
	Node* a2; 
	Init(l2);
	a1 = addHead(l2, 1);
	a2 = addHead(l2, 2);
	cout << "danh sach l2: ";
	Xuat(l2);
	List l3;
	Init(l3);

	l3 = Noi(l, l2);
	cout << "\n\nnoi l va l2: " << endl;
	cout << "danh sach l3: " << endl;
	Xuat(l3);
	
	return 0;
}