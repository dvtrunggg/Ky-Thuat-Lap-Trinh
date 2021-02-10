#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;


// cau 1
typedef struct Date
{
	int ngay;
	int thang;
	int nam;
};
typedef struct SoTietKiem
{
	string maSo;
	string loai;
	string hoTen;
	float tienGui;
	Date thoiGian;

};
typedef struct DanhSach
{
	SoTietKiem STK;
	DanhSach* pNext;
};
typedef struct LIST
{
	DanhSach* pHead;
	DanhSach* pTail;
};

// cau 2 va 3
bool thang30Ngay(Date d);
bool thang31Ngay(Date d);
bool Thang2(Date d);
void nhapThoiGian(Date& d);
void nhapSoTietKiem(SoTietKiem& so);
void xuatSoTietKiem(SoTietKiem so);
void Init(LIST& l);
DanhSach* createNode(DanhSach data);
void addTail(LIST& l, DanhSach data);
void nhapDanhSach(LIST& l);
void xuatDanhSach(LIST l);

// cau 4
ostream& operator << (ostream& os, const SoTietKiem& stk);
void writeFile(ofstream& fileOut, LIST l, string fileName);

// cau 5
float tongTienGui(LIST l);

//cau 6
void deleteHead(LIST& l);
void deleteTail(LIST& l);
void deleteSTK(LIST& l, string ms);

//cau 7 (dung recursion)
int demSL(DanhSach* start, float x);
