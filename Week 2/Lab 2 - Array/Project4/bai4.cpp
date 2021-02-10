#include"bai4.h"
void Input(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		 cout << "a[" << i << "] = ";
		 cin >> *(a + i);
	}
}
void Output(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << "\t";

}

//Xuất ra những phần tử có trong A mà không có trong B
void OutputA(int* a, int* b, int n1, int n2)
{
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (*(a + i) == *(b + j))
				break;
			else if (j == n2 - 1)
				cout << *(a + i) << "\t";
		}

	}

}


//ghép mảng a và mảng b thành mảng c
//n1, n2, n3 lần lượt là size of mảng a, b, c
void Ghep(int *a, int n1, int *b, int n2, int *c, int& n3)
{
	n3 = n1+n2;
	for (int i = 0; i < n3; i++)
		if (i < n1)
			*(c + i) = *(a + i);
		else
			*(c + i) = *(b + i - n1);
}

//hàm xóa 1 phần tử trong mảng tại vị trí pos
void deleteElement(int *a, int& n, int pos)
{
	for (int i = pos; i < n; i++)
	{
		*(a + i) = *(a + i + 1);
	}
	n--;
}

//mảng c không có các phần tử trùng nhauuu nghãi là ta sẽ xóa các phần tử trùng nhau trong mảng c và chỉ giữ lại 1 cái
//vd: c[] = {1,1,2,3,2,4} => sau khi xóa trùng --> c[] = {1,2,3,4}
void arrayC(int* a, int n1, int* b, int n2, int* c, int& n3)
{
	//ghép mảng a và b thành mảng c
	Ghep(a, n1, b, n2, c, n3);

	//xóa các phần tử trùng nhauuu
	for (int i = 0; i < n3; i++)
	{
		for (int j = i + 1; j < n3; j++) {
			if (*(c + i) == *(c + j))
			{
				deleteElement(c, n3, j);
				j--;
			}
		}
	}
}


