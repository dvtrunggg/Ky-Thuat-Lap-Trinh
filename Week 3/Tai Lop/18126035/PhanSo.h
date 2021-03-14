#include<iostream>
using namespace std;

typedef struct PhanSo
{
	int tu;
	int mau;
}PS;
PS *Nhap_PS();
void XuatPS(PS *p);
PS *CongPS(PS *ps1, PS *ps2);

