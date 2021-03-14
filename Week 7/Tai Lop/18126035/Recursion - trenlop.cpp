// lam bai 4 va 11 

#include<iostream>
#include<math.h>
using namespace std;

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
		cout << *(a + i) << "   ";

}

//Tinh S = x + x^3 + x^5 + … + x^(2n + 1)
int Sum1(int* a, int n)
{
	if (n == 0)
		return *a;
	return Sum1(a, n - 1) + pow(*a, 2 * n + 1);
}

// tinh tong cac phan tu chan trong mang
int Sum2(int* a, int n)
{
	int sum = 0;
	if (n < 0)
		return sum;
	if (*(a + n) % 2 == 0)
	{
		sum += *(a + n);
	}
	return Sum2(a, n - 1) + sum;
}

// giup ham main ko nhieu code
void Support(int* a, int n)
{
	Input(a, n);
	Output(a, n);
	cout << "\n==========================" << endl;
	cout << "Tong cac ptu chan:" << Sum2(a, n);
	cout << "\n==========================" << endl;
	cout << "Tinh S = x + x^3 + x^5 + … + x^(2n + 1)" << endl;
	cout << "\tVoi: x la cac ptu cua mang, n la so luong phan tu cua mang: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "(x = " << *(a + i) << ", n = " << n << ")" << endl;
		cout << "\tS = " << Sum1(&*(a + i), n) << endl;
	}
}
int main()
{
	int* a;
	int n;
	cout << "Nhap so luong ptu mang:", cin >> n;
	a = new int[n];
	Support(a, n);
	delete[] a;
	return 0;
}
