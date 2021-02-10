#include "Fraction.h"

int main()
{
	PHANSO ps1, ps2;
	Input(ps1);
	Output(ps1);
	Input(ps2);
	Output(ps2);

	PHANSO a = RutGonPhanSo(ps1);
	cout << "\nPhan so sau khi rut gon: ";
	Output(a);

	PHANSO b = RutGonPhanSo(ps2);
	cout << "\nPhan so sau khi rut gon: ";
	Output(b);


	PHANSO tong = Summation(a, b);
	cout << "\nTong 2 phan so: ";
	Output(tong);


	PHANSO hieu = Subtraction(a, b);
	cout << "\nHieu 2 phan so: ";
	Output(hieu);

	PHANSO tich = Multiplication(a, b);
	cout << "\nTich 2 phan so: ";
	Output(tich);


	PHANSO thuong = Division(a, b);
	cout << "\nThuong 2 phan so: ";
	Output(thuong);


	bool Check = isToiGian(a);
	if (Check)
		cout << "\n\tDay la phan so toi gian" << endl;
	else
		cout << "\n\tDay la phan so chua toi gian" << endl;


	QuiDong2PhanSo(ps1, ps2);
	cout << "Quy dong: ";
	Output(ps1);
	cout << "Quy dong: ";
	Output(ps2);

	return 0;
}