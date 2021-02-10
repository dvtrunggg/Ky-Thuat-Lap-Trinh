#include"bai4.h"

int main()
{
	int* a;
	int* b;
	int* c;
	int n1,n2,n3;
	do
	{
		cout << "Nhap so luong ptu mang a : ";
		cin >> n1;
		cout << "Nhap so luong ptu mang b : ";
		cin >> n2;
		if (n1 < 1 && n1 > 25 && n2 < 1 && n2 > 25)
			cout << "So luong phan tu ko hop le, moi nhap lai:" << endl;
	} while (n1 < 1 && n1 > 25 && n2 < 1 && n2 > 25);
	a = new int[n1];
	b = new int[n2];
	n3 = n1 + n2;
	c = new int[n3];

	cout << "Nhap a[]: "<<endl;
	Input(a, n1);
	cout << endl;
	Output(a, n1);
	
	cout << "\nNhap b[]: "<<endl;
	Input(b, n2);
	cout << endl;
	Output(b, n2);
	
	cout << "\nptu mang a co ma mang b ko co:" << endl;
	OutputA(a, b, n1, n2);
	cout << endl;
	cout << "Ghep mang A va B thanh mang C sao cho C khong co cac phan tu trung nhau. " << endl;
	cout << "Mang C[]: ";
	arrayC(a, n1, b, n2, c, n3);
	Output(c, n3);
	delete[] a;
	delete[] b;
	delete[] c;

	return 0;
}