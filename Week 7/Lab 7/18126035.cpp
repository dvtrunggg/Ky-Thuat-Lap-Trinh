#include <iostream>
#include <math.h>
using namespace std;


void Input(int*& a, int& n)
{
	cout << "Nhap so phan tu: ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> *(a + i);
	}
}
void Print(int* a, int n)
{
	cout << "a[] = ";
	for (int i = 0; i < n; i++)
		cout << *(a + i) << "  ";
}

//	Bai 1:  tong S = 1/1 + 1/2 + 1/3 + ... + 1/n
float TongPhanSo(float n)
{
	if (n == 1)
		return 1;
	return 1 / n + TongPhanSo(n - 1);
}

//	Bai 2:  tich T = 1x2x3x...xn
int Tich(int n)
{
	if (n == 1)
		return 1;
	return n * Tich(n - 1);
}

//	Bai 3:  S = x + x^2 + x^3 + ... + x^n
int TongLuyThua(int x, int n)
{
	if (n == 0)
		return 1;
	return pow(x, n) + TongLuyThua(x, n - 1);
}

//  tong S = x + x^3 + x^5 + ... + x^(2n+1)
int TongMuLe(int x, int n)
{
	if (n == 0)
		return x;
	else
		return pow(x, 2 * n + 1) + TongMuLe(x, n - 1);
}

//	  tong  S(x,n) = x + x^2/2! + x^3/3! + …+x^n/n!
int GiaiThua(int n)
{
	if (n == 1)
		return 1;
	return n * GiaiThua(n - 1);
}
float TongLuyThuaChiaGiaiThua(int x, int n)
{
	if (n == 1)
		return x;
	return float(pow(x, n)) / float(GiaiThua(n)) + TongLuyThuaChiaGiaiThua(x, n - 1);
}


//	 Dem so luong chu so cua so nguyen duong n
int DemSoLuongChuSo(int n)
{
	if (n < 10)
		return 1;
	return 1 + DemSoLuongChuSo(n / 10);
}

//	  tong cac chu so cua so nguyen duong n
int TongCacChuSo(int n)
{
	if (n < 10)
		return n;
	return n % 10 + TongCacChuSo(n / 10);
}

//	 Dem so luong so le cua so nguyen duong n
int DemSoLuongSoLe(int n)
{
	if (n < 10)
	{
		if (n % 2 == 1)
			return 1;
		else
			return 0;
	}
	else
	{
		if (n % 2 == 1)
			return 1 + DemSoLuongSoLe(n / 10);
		else
			return DemSoLuongSoLe(n / 10);
	}
}

//	 Kiem tra so nguyen duong n co toan chu so chan
int KiemTraToanChuSoChan(int n)
{
	if (n < 10)
	{
		if (n % 2 == 0)
			return 1;
		else
			return 0;
	}
	else
	{
		if (n % 2 == 0)
			return KiemTraToanChuSoChan(n / 10);
		else
			return 0;
	}
}


//  tong cac phan tu chan trong mang

int TongChanMang(int* a, int n)
{
	int sum = 0;
	if (n < 0)
		return sum;
	if (*(a + n) % 2 == 0)
	{
		sum += *(a + n);
	}
	return TongChanMang(a, n - 1) + sum;
}

//	 tich cac so nguyen to trong mang
bool isPrime(int n, int i = 2)
{
	// Base cases 
	if (n <= 2)
		return (n == 2) ? true : false;
	if (n % i == 0)
		return false;
	if (i * i > n)
		return true;

	// Check for next divisor 
	return isPrime(n, i + 1);
}

int TichNguyenTo(int* a, int n)
{
	if (n < 0)
		return 1;
	if (isPrime(a[n], a[n] / 2) == true)
		return TichNguyenTo(a, n - 1) * a[n];
	else
		return TichNguyenTo(a, n - 1);
}

//tich cac so am
int Mul(int* a, int n)
{
	if (n <= 0)
		return 0;
	if (a[n] < 0)
		return Mul(a, n - 1) * a[n];
	else
		return Mul(a, n - 1);
}

// check mang la so am hay ko
bool CheckMangSoAm(int* a, int n)
{
	while (n >= 0)
	{
		if (*(a+n-1) >= 0)
			return false;
		else
		{
			CheckMangSoAm(a, n - 1);
			return true;
		}
		n--;
	}
}

//dem x trong mang
int DemX(int* a, int n, int x)
{
	int dem;
	if (n < 0)
		return 0;
	else if (a[n] == x)
		dem = 1;
	else
		dem = 0;
	return DemX(a, n - 1, x) + dem;
}

//gia tri lon nhat trong mang
int TimMax(int* a, int n)
{
	int max = a[0];
	while (n >= 0)
	{
		if (a[n] >= max)
		{
			max = a[n];
			return max;
		}
		else return TimMax(a, n - 1);
	}
}

// dem so duong trong mang 
int DemSoDuong(int* a, int n)
{
	while ((*a - n - 1) % 2 == 0)
	{
		if (n == 0)
			return 0;
		if (a[n - 1] > 0)
			return 1 + DemSoDuong(a, n - 1);
		n--;
	}
	return DemSoDuong(a, n - 1);
}

// dem gia tri phan biet
int Dem(int* a, int left, int right)
{
	if (left > right)
		return 0;
	for (int i = left + 1; i <= right; i++)
	{
		if (a[left] == a[i])
			return Dem(a, left + 1, right);
	}
	return 1 + Dem(a, left + 1, right);
}

int main()
{
	// Bai 4
	int x = KiemTraToanChuSoChan(246782);
	cout << x << endl;

	//Bai 11
	int* a;
	int n;
	Input(a, n);
	Print(a, n);
	cout << endl;
	int t;


	/*if (CheckMangSoAm(a, n) == true)
		cout << "mang toan so am" << endl;
	else
		cout << "mang co so duong" << endl;*/
	// = TimMax(a, n);
	//cout << "Max cua mang: " << t;

	//t = DemSoDuong(a, n);
	//cout << "so luong so duong:" << t;
	//t = DemX(a, n, 3);
	//cout << "so lan 3 xuat hien: " << t;
	//t = Dem(a, 0, n - 1);
	//cout <<"so phan tu phan biet:"<< t;
	
	return 0;
}
