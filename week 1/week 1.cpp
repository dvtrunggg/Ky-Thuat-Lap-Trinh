
//hello, i use c++ for coding because i am not use to be using C :)

#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	// bai 1
	/*int a = 5, b = -1;
	printf("Gia tri: a = %d, j = %d\n", a, b);
	printf("Dia chi: a = %p, b = %p\n", &a, &b);*/

	 //bai 2
	int a = 1; 
	int* pointer; 	
	float b = 0.00; 	
	printf(" a= %d \n", a);           // in giá trị biến a
	printf("i = %p \n", &a);			// in địa chỉ a		
	pointer = &a; 	
	printf("p = %p\n", pointer);           // in giá trị pointer 
	cout<<"dia chi pointer:"<<&pointer;      // in dia chi pointer
	/*pointer = 1000; */         // không thể gán trực tiếp giá trị cho con trỏ
	/*pointer = &b;*/		// sai vì poiter là kiểu *int, b là float


//	////bai 3
//	//char a = 'A', * pa;
//	//float x = 2.5F, * px;
//	//int i = 1, * m;
//	//pa = &a;
//	//px = &x;
//	//m = &i;
//	//printf("pa = %p\npx = %p\n m = %p\n", pa, px, m);
//	//
//	// bai 4
//	char a = 'A', b = 'B', * pa, * pb; // line 1
//	pa = &a; // line 2
//	pb = pa; // line 3
//	printf(" dia chi bien a: %p\n", &a);
//	printf(" dia chi bien b: %p\n", &b);
//	printf("pa = %p, pb = %p\n", pa, pb); // line 4
//	cout << "dia chi cua pa" << &pa << endl;
//	cout << "dia chi cua pb" << &pb << endl;
//	pa = &b; // Line 5
//	printf("pa = %p, pb = %p\n", pa, pb); //line 6
//	/*printf("dia chi cua pa: %c\n", &pa);
//	printf("dia chi cua pb: %c\n", &pb);*/
//	cout << "dia chi cua pa" << &pa << endl;
//	cout << "dia chi cua pb" << &pb << endl;

	return 0;
}
