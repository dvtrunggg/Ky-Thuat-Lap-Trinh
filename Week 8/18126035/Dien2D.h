#pragma once
#include <iostream>
#include<fstream>
using namespace std;
class Diem2D
{
private:
	int hoanh; 
	int tung;
public:
	friend ostream& operator << (ostream& os, Diem2D& d);
	friend istream& operator >>(istream& is, Diem2D& d);
};

ostream& operator << (ostream& os, Diem2D& d)
{
	os << "(" << d.hoanh << ", " << d.tung << ")";
	return os;
}
istream& operator >>(istream& is, Diem2D& d)
{
	is >> d.hoanh;
	char x;
	is >> x;
	is >> d.tung;
	return is;
}

void readDiem(ifstream& fileIn, Diem2D ds[], ofstream& fileOut)
{
	fileIn.open("input4.txt", ios_base::in);
	fileOut.open("output7.txt", ios_base::out);
	int i = 0;
	while (fileIn.eof() == false)
	{
		fileIn >> ds[i];
		fileOut << ds[i] << " ";
		i++;
	}
	fileIn.close();
	fileOut.close();
}

void readMatrix(ifstream& fileIn, Diem2D** a, int row, int column, ofstream& fileOut)
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
void cau11Va17(ifstream& fileIn, ofstream& fileOut, Diem2D**& a)
{
	fileIn.open("input7.txt", ios_base::in);
	int rows, columns;
	fileIn >> rows;
	fileIn >> columns;
	a = new Diem2D * [rows];
	for (int i = 0; i < rows; i++)
	{
		*(a + i) = new Diem2D[columns];
	}

	fileOut.open("output4.txt", ios_base::out);
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