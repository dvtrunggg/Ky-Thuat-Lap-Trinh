#include"PhanSo.h"
int main()
{
	PS *ps1;
	PS* ps2;
	ps1 = new PS;
	ps2 = new PS;
	if (ps1 == NULL || ps2 == NULL)
	{
		cout << "khong du bo nho" << endl;
		exit(0);
	}
	ps1 = Nhap_PS();
	XuatPS ( ps1 );
	ps2 = Nhap_PS();
	XuatPS ( ps2 );
	cout << "Cong 2 phan so: ";
	XuatPS(CongPS(ps1,ps2));
	delete ps1;
	delete ps2;
	return 0;
}
