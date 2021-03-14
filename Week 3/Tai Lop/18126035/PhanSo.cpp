#include"PhanSo.h"
PS * Nhap_PS()
{
	PS* p;
	p = new PS;
	if (p == NULL)
	{
		return NULL;
	}
	cout << "Nhap tu so:", cin >> p->tu;
	cout << "Nhap mau so:", cin >> p->mau;
	return p;
}
void XuatPS(PS *p)
{
	cout << p->tu << "/" << p->mau << endl;
}
PS *CongPS(PS *ps1, PS *ps2)
{
	PS *ketqua;
	ketqua = new PS;
	ketqua->tu = (ps1->tu * ps2->mau) + (ps2->tu * ps1->mau);
	ketqua->mau = ps1->mau * ps2->mau;
	return ketqua;
	
}

