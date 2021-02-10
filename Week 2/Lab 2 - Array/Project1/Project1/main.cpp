#include"bai1.h"

int main()
{
	int* a;
	int n;
	do
	{
		cout << "Nhap so luong ptu mang: ", cin >> n;
		if (n < 1 && n > 100000)
			cout << "So luong phan tu ko hop le, moi nhap lai:" << endl;
	} while (n < 1 && n > 100000);
	a = new int[n];
	Input(a, n);
	Output(a, n);

	int number;
	cout << "\nNhap so ban muon kiem tra: ", cin >> number;
	cout << "\nUoc cua " << number << ": " << endl;
	Uoc(a, n, number);
	cout <<"\nXu ly mang: cac phan tu la uoc don ve cuoi mang, khong phai la uoc thi don len dau. "<< endl;
	cout << "Mang sau khi xu ly: " << endl;

	specialArray(a, n, number);	
	Output(a, n);

	delete[] a;
	
	return 0;
}