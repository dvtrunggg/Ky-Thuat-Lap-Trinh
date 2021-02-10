#include "Fraction.h"
void Input(PHANSO& ps)
{
	float temp;
	cout << "\nNhap phan so: ";
	cin >> temp;
	ps.num = temp;
	do
	{
		cout << "\nNhap mau so: ";
		cin >> temp;
		ps.deno = temp;
		if (ps.deno == 0)
		{
			cout << "\nMau so phai khac 0, nhap lai! " << endl;
		}
	} while (ps.deno == 0);
}

void Output(PHANSO ps)
{
	cout << ps.num << "/" << ps.deno;
}

float UCLN(float a, float b)
{
	if (a < 0)
	{
		a = a * -1;
	}
	if (b < 0)
	{
		b = b * -1;
	}

	if (a == 0 && b != 0)
	{
		return b;
	}
	else if (b == 0 && a != 0)
	{
		return a;
	}

	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else
			b = b - a;
	}
	return a;
}
// Rút gọn phân số
PHANSO RutGonPhanSo(PHANSO a)
{
	float temp = UCLN(a.num, a.deno);
	a.num = a.num / temp;
	a.deno = a.deno / temp;
	return a;
}
// Tổng 2 phân số
PHANSO Summation(PHANSO a, PHANSO b)
{
	PHANSO result;
	result.num = a.num * b.deno + a.deno * b.num;
	result.deno = a.deno * b.deno;
	return result;
}
// Hiệu 2 phân số
PHANSO Subtraction(PHANSO a, PHANSO b)
{
	PHANSO result;
	result.num = a.num * b.deno - a.deno * b.num;
	result.deno = a.deno * b.deno;
	return result;
}
// Tích 2 phân số
PHANSO Multiplication(PHANSO a, PHANSO b)
{
	PHANSO result;
	result.num = a.num * b.num;
	result.deno = a.deno * b.deno;
	return result;
}

// Thương 2 phân số
PHANSO Division(PHANSO a, PHANSO b)
{
	PHANSO result;
	result.num = a.num * b.deno;
	result.deno = a.deno * b.num;
	return result;
}

// check phân số tối giản
bool isToiGian(PHANSO a)
{
	PHANSO c = RutGonPhanSo(a);
	if (c.num == a.num && c.deno == a.deno)
		return true;
	return false;
}

// quy đồng 2 phân số
void QuiDong2PhanSo(PHANSO& a, PHANSO& b)
{
	PHANSO temp;
	temp.num = a.num;
	temp.deno = a.deno;

	a.num *= b.deno;
	a.deno *= b.deno;

	b.num *= temp.deno;
	b.deno *= temp.deno;

}

// Kiểm tra phân số dương
bool isPositive(PHANSO a)
{
	if (a.num >= 0 && a.deno > 0)
		return true;
	return false;
}
// Kiểm tra phân số âm
bool isNegative(PHANSO a)
{
	if (a.num < 0 || a.deno < 0)
		return true;
	return false;
}

//So sánh 2 phân số: hàm trả về 1 trong 3 giá trị: 0,-1,1
int SoSanh2PhanSo(PHANSO a, PHANSO b)
{
	float kq1 = a.num / a.deno;
	float kq2 = b.num / b.deno;
	if (kq1 < kq2)
		return -1;
	if (kq1 > kq2)
		return 1;
	return 0;
}
// Định nghĩa toán tử operator + cho 2 phân số
PHANSO operator +(PHANSO a, PHANSO b)
{
	PHANSO kq;
	kq.num = a.num * b.deno + a.deno * b.num;
	kq.deno = a.deno * b.deno;
	return kq;
}
// toán tử operator - cho 2 phân số
PHANSO operator -(PHANSO a, PHANSO b)
{
	PHANSO kq;
	kq.num = a.num * b.deno - a.deno * b.num;
	kq.deno = a.deno * b.deno;
	return kq;
}
//toán tử operator * cho 2 phân số
PHANSO operator *(PHANSO a, PHANSO b)
{
	PHANSO kq;
	kq.num = a.num * b.num;
	kq.deno = a.deno * b.deno;
	return kq;
}
//toán tử operator / cho 2 phân số
PHANSO operator /(PHANSO a, PHANSO b)
{
	PHANSO kq;
	kq.num = a.num * b.deno;
	kq.deno = a.deno * b.num;
	return kq;
}

// toán tử operator ++ cho 2 phân số
PHANSO operator ++ (PHANSO& a)
{
	a.num += a.deno;
	return a;
}
//toán tử operator -- cho 2 phân số
PHANSO operator -- (PHANSO& a)
{
	a.num -= a.deno;
	return a;
}