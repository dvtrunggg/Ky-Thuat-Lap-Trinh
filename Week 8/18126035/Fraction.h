#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class PhanSo
{
private:
	int tuSo;
	int mauSo;
public:
	friend ostream& operator << (ostream& os, PhanSo& ps);
	friend istream& operator >>(istream& is, PhanSo& ps);
};
istream& operator >>(istream& is, PhanSo& ps)
{
	is >> ps.tuSo;
	char x;
	is >> x;
	is >> ps.mauSo;
	return is;
}
ostream& operator << (ostream& os, PhanSo& ps)
{
	os << ps.tuSo << "/" << ps.mauSo;
	return os;
}

// cau 4-5
void readFraction(ifstream& fileIn, PhanSo ds[], ofstream& fileOut)
{
	fileIn.open("input3.txt", ios_base::in);
	fileOut.open("output6.txt", ios_base::out);
	int i = 0;
	while (fileIn.eof() == false)
	{
		fileIn >> ds[i];
		fileOut << ds[i]<<" ";
		i++;
	}
	fileIn.close();
	fileOut.close();
}


void readMatrix(ifstream& fileIn, PhanSo** a, int row, int column, ofstream& fileOut)
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			fileIn >> *(*(a + i) + j);
			fileOut << *(*(a + i) + j) << " ";
		}
		fileOut << endl;
	}

}

void cau10Va15(ifstream& fileIn, ofstream& fileOut, PhanSo**& a)
{
	fileIn.open("input5.txt", ios_base::in);
	int rows, columns;
	fileIn >> rows;
	fileIn >> columns;
	a = new PhanSo* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(a + i) = new PhanSo[columns];
	}
	
	fileOut.open("output3.txt", ios_base::out);
	readMatrix(fileIn, a, rows, columns, fileOut);
	fileIn.close();
	fileOut.close();
	for (int i = 0; i < rows; i++)
	{
		delete[] * (a + i);
	}
	delete[] a;
	a = NULL;
}