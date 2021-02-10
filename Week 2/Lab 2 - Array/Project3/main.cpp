#include"bai3.h"
int main()
{
	int* a;
	int na;
	do
	{
		cout << "Nhap so luong ptu mang a: ", cin >> na;
		if (na < 1 && na > 1000)
			cout << "So luong phan tu ko hop le, moi nhap lai:" << endl;
	} while (na < 1 && na > 1000);

	a = new int[na];
	Input(a, na);
	cout << "Mang a[]: ";
	Output(a, na);

	
	int nb = Count(a, na);

	int* b = new int[nb];

	cout << "\nMang b gom nhung phan tu khong phai so nguyen to tu mang a." << endl;
	cout << "Mang b[]: ";
	ArrayPrimes(a, b, na);
	Output(b, nb);

	cout << "\nSap xep giam dan cac so nguyen trong mang b." << endl;
	descendingSort(b, nb);
	Output(b, nb);

	cout << "\nXoa cac phan tu la so nguyen to trong mang a: " << endl;
	deletePrime(a, na);
	cout<<"Mang a sau khi xoa cac so ngto: ";
	Output(a, na);


	delete[] b;
	delete[] a;
	return 0;
}