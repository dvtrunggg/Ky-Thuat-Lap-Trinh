#include"bai3.h"

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

//hàm kiểm tra số nguyên tố
int CheckPrime(int x)
{
	if (x <= 1)
		return 0;

	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return 0;
	}
	return true; 	
}

//đếm số lượng số KHÔNG PHẢI là số nguyên tố trong mảng
int Count(int* a, int n)
{
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		if (CheckPrime(*(a+i)) == 0)
			c++;
	}
	return c;
}

//hàm insert 1 phần tử có giá trị key vào vị trí pos trong mảng.
//n là size của mảng
void Insert(int* a, int& n, int pos, int key)
{
	for (int i = n; i > pos; i--)
	{
		*(a + i) = *(a + i - 1);
	}
	a[pos] = key;
	n++;
}

//Trích những phần tử trong A không phải số nguyên tố ra mảng B
void ArrayPrimes(int* a, int* b, int na)
{
	int j = 0;
	for (int i = 0; i < na; i++)
	{

		//nếu *(a+i) ko phải là số ngto
		if (CheckPrime(*(a + i)) == 0) {
			{
				*(b + j) = *(a + i); // gán *(a+i) vào mảng b
				j++;
			}

		}
	}
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void descendingSort(int* a, int n)  // sap xep giam dan
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (*(a + j) > *(a + i))
				Swap(*(a + j), *(a + i));
	}
}

//hàm xóa 1 phần tử trong mảng tại vị trí pos
void deleteElement(int* a, int& n, int pos)
{
	for (int i = pos; i < n; i++)
	{
		*(a + i) = *(a + i + 1);
	}
	n--;
}

//xóa các phần tử là số nguyên tố trong mang a
void deletePrime(int* a, int& n)
{
	int i = 0;
	while(i < n)
	{
		//nếu a[i] là số ngto thì delete nó đi tại vị trí i:):)
		if (CheckPrime(*(a + i)) == 1)
		{
			deleteElement(a, n, i);

		}
		else {
			i++;
		}

	}
}