#pragma once
#include"Dien2D.h"

class DuongTron
{
private:
	int hoanh; 
	int tung;
	int BanKinh;
public:
	friend ostream& operator << (ostream& os, DuongTron& dt);
	friend istream& operator >>(istream& is, DuongTron& dt);
};

ostream& operator << (ostream& os, DuongTron& dt)
{
	os << "(" << dt.hoanh << ", " << dt.tung << ")" <<"ban kinh: "<<dt.BanKinh;	
	return os;
}
istream& operator >>(istream& is, DuongTron& dt)
{
	is >> dt.hoanh;
	char x;
	is >> x;
	is >> dt.tung;
	is >> dt.BanKinh;
	return is;
}

void readDuongTron(ifstream& fileIn, DuongTron ds[], ofstream& fileOut)
{
	fileIn.open("input6.txt", ios_base::in);
	fileOut.open("output8.txt", ios_base::out);
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

void readMatrix(ifstream& fileIn, DuongTron** a, int row, int column, ofstream& fileOut)
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

void cau12Va19(ifstream& fileIn, ofstream& fileOut, DuongTron**& a)
{
	fileIn.open("input8.txt", ios_base::in);
	int rows, columns;
	fileIn >> rows;
	fileIn >> columns;
	a = new DuongTron * [rows];
	for (int i = 0; i < rows; i++)
	{
		*(a + i) = new DuongTron[columns];
	}

	fileOut.open("output5.txt", ios_base::out);
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