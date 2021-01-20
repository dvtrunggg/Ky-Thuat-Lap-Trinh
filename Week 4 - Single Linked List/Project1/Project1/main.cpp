#include "Node.h"

int main()
{
	LIST l;
	Init(l);
	NODE* p1;
	NODE* p2;
	NODE* q1;
	NODE* q2;
	q1 = addFirst(l, 20);
	q2 = addTail(l, 199);
	addFirst(l, -999);
	addTail(l, 3);
	addTail(l, 31);
	p1 = createNode(10);
	p2 = createNode(2);
	addFirst(l, 15);
	insertAfterQ(l, p1, q1);
	deleteAfterQ(l, q1);
	//deleteList(l);
	cout << "List 1: ";
	Output(l);
	//bai 2======================================

	/*deleteHead(l);
	deleteTail(l);*/
	cout << endl;
	//Output(l);

	//NODE* p5 = Search(l, 15);

	cout << "\nlength of list 1:" << listLen(l) << endl;
	//-------------------------------------------------------------------
		//nối 2 list
	
	LIST l2;
	Init(l2);
	NODE *t1;
	NODE *t2;

	addFirst(l2, 5);
	addTail(l2, 10);
	cout << "List 2: ";
	Output(l2);

	LIST Result = Noi(l, l2);
	cout << "\nList 3: ";
	Output(Result);

	return 0;
}