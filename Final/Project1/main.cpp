#include"SoTietKiem.h"

int main()
{
	LIST l;
	Init(l);
	nhapDanhSach(l);
	xuatDanhSach(l);

	ofstream fileOut;
	writeFile(fileOut, l, "output.bin");

	cout << "\nTong tien gui tiet kiem trong danh sach: " << tongTienGui(l);

	string str;
	cout << "\nNhap ma so STK ban muon xoa: ";
	cin.ignore();
	getline(cin, str);
	deleteSTK(l, str);

	xuatDanhSach(l);

	float tien;
	cout << "\nNhap so tien ban muon so sanh: ", cin >> tien;
	cout << "\nSo luong so tiet kiem nho hon " << tien << " la: " << demSL(l.pHead, tien);
	
	return 0;
}