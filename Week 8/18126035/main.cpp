#include"Lap8.h"
#include"Fraction.h"
#include"Dien2D.h"
#include"DuongTron.h"
#include"SinhVien.h"
int main()
{
	ifstream fileIn;
	ofstream fileOut;
	int n = 100;
	int* a1 = new int[n];

	cau1(fileIn, fileOut, a1, n);

	
	int rows = countRows(fileIn);
	int columns = countColumns(fileIn);
	int** a2;
	cau2Va3(fileIn, fileOut, a2, rows, columns);

	
	PhanSo dsps[100];
	readFraction(fileIn, dsps, fileOut);
	cout << endl;
	Diem2D dsDiem[100];
	readDiem(fileIn, dsDiem, fileOut);

	PhanSo** a3;
	cau10Va15(fileIn, fileOut, a3);
	DuongTron dsdt[100];
	readDuongTron(fileIn, dsdt, fileOut);

	Diem2D** a5;
	cau11Va17(fileIn, fileOut, a5);

	DuongTron** a4;
	cau12Va19(fileIn, fileOut, a4);

	SinhVien dssv[100];
	readSinhVien(fileIn, dssv, fileOut);


	return 0;
}