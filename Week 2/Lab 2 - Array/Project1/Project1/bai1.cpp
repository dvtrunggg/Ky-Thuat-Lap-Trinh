#include"bai1.h"

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
		cout <<*(a + i) <<"\t";
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
//sắp xếp tăng dần
void Sort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (*(a + j) < *(a + i))
				Swap(*(a + j), *(a + i));
	}
}

//hàm tìm và xuất các ước trong mảng
void Uoc(int *a, int n, int number)   
{
	for (int i = 0; i < n; i++)
	{

		if (number % *(a + i) == 0)
		{
			cout << "a[" << i << "] = " << *(a + i) << "\t";
		}
	}
}
int Count(int* a, int n, int number)   // dem uoc cua number
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (number % *(a + i) == 0)
		{
			count++;
		}
	}
	return count;
}

//hàm xuất mảng theo yêu cầu:
//Dồn những phần tử là ước số của X về cuối mảng. Sắp xếp các phần tử không
//phải là ước số của X theo thứ tự tăng dần(giữ nguyên vị trí các phần tử là ước số của X).

void specialArray(int* a, int n, int number)
{
	int k = Count(a, n, number); // k là số lượng ước số của number trong mảng

	//duyệt các phần tử không phải là ước của number
	for(int i = 0; i<n-k; i++)
	{
		for (int j = n - 1; j >= (n-1-k); j--)
		{
			//nếu phần tử thứ a[j] không phải là ước của number và a[i] là ước của number thì Swap vị trí 2 phần tử này
			if (number % *(a + j) != 0 && number % *(a + i) == 0)
			{
				Swap(*(a + j), *(a + i));
			}
		}
		
	}
	 
	//mảng a sau khi xử lý thì: a[0] --> a[n-k] là các số ko phải ước của number
	//							a[n-1-k] --> a[n-1] là ước của number
	//=> sort các phần tử từ a[0] -> a[n-k] là //Sắp xếp các phần tử không phải là ước của number
	//giữ nguyên vị trí các phần tử là ước số của number
	Sort(a, n - k);
}
