#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class SinhVien
{
private:
	float diem;
	string ten;
	string MSSV;
public:
	friend ostream& operator << (ostream& os, SinhVien& sv);
	friend istream& operator >>(istream& is, SinhVien& sv);

};
ostream& operator << (ostream& os, SinhVien& sv)
{
	os << sv.MSSV << sv.ten << sv.diem;
	return os;
}
istream& operator >>(istream& is, SinhVien& sv)
{
	getline(is, sv.MSSV);
	char x;
	is >> x;
	getline(is, sv.ten);
	is >> x;
	is >> sv.diem;
	is.ignore();
	return is;
}

void readSinhVien(ifstream& fileIn, SinhVien ds[], ofstream& fileOut)
{
	fileIn.open("data.txt", ios_base::in);
	fileOut.open("sinhvien.txt", ios_base::out);
	int i = 0;
	string dummyLine;
	getline(fileIn, dummyLine);
	
	while (fileIn.eof() == false)
	{
		
		fileIn >> ds[i];
		fileOut << ds[i] << " ";
		i++;
	}
	fileIn.close();
	fileOut.close();
}