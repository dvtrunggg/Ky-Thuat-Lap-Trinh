#include "SoTietKiem.h"

//cau 1: khai bao o file.h

// cau 2 va 3:
bool thang30Ngay(Date d)
{
	if (d.thang == 4 || d.thang == 6 || d.thang == 9 || d.thang == 11)
	{
		if (d.ngay > 30)
			return false;
		return true;
	}
}
bool thang31Ngay(Date d)
{
	if (d.thang == 1 || d.thang == 3 || d.thang == 5 || d.thang == 7 || d.thang == 8 || d.thang == 10 || d.thang == 12)
	{
		if (d.ngay > 31)
			return false;
		return true;
	}
}
bool Thang2(Date d)
{
	if (d.thang == 2)
	{
		if (d.nam % 400 == 0 || d.nam % 4 == 0 && d.nam % 100 != 0)
		{
			if (d.ngay > 29)
				return false;
		}
		else
		{
			if (d.ngay > 28)
				return false;
		}
		return true;
	}
}
void nhapThoiGian(Date& d)
{
	do
	{
		cout << "\tNhap nam: ";
		cin >> d.nam;
		if (d.nam < 1)
		{
			cout << "\t\tso nam khong hop le, moi nhap lai. " << endl;
		}
	} while (d.nam < 1);
	do
	{
		cout << "\tNhap thang: ";
		cin >> d.thang;
		if (d.thang <= 0 || d.thang > 12)
		{
			cout << "\t\tso thang khong hop le, moi nhap lai. " << endl;
		}
	} while (d.thang <= 0 || d.thang > 12);
	do
	{
		cout << "\tNhap ngay: ";
		cin >> d.ngay;
		if (d.ngay > 31 || d.ngay <= 0 || thang30Ngay(d) == false || thang31Ngay(d) == false || Thang2(d) == false)
		{
			cout << "\t\tso ngay khong hop le, moi nhap lai. " << endl;
		}
	} while (d.ngay > 31 || d.ngay <= 0 || thang30Ngay(d) == false || thang31Ngay(d) == false || Thang2(d) == false);
}


void nhapSoTietKiem(SoTietKiem& so)
{
	cout << "-----------------------------------------" << endl;
	do
	{
		cout << "Nhap ma so: ";
		cin.ignore();
		getline(cin, so.maSo);
		if (so.maSo.length() > 8)
		{
			cout << "Ma so toi da la 8 ky tu, moi nhap lai. " << endl;
		}
	} while (so.maSo.length() > 8);
	do
	{
		cout << "Nhap ho ten: ";
		getline(cin, so.hoTen);
		if (so.hoTen.length() > 30)
		{
			cout << "Ho ten toi da la 30 ky tu, moi nhap lai" << endl;
		}
	} while (so.hoTen.length() > 30);

	do
	{
		cout << "Nhap loai tiet kiem: ";
		getline(cin, so.loai);
		if (so.loai.length() > 30)
		{
			cout << "Loai so tiet kiem toi da la 30 ky tu, moi nhap lai" << endl;
		}
	} while (so.loai.length() > 30);
	cout << "Nhap ngay mo so: " << endl;
	nhapThoiGian(so.thoiGian);

	cout << "Nhap so tien gui: ";
	cin >> so.tienGui;
}

void xuatSoTietKiem(SoTietKiem so)
{
	cout << "\n================================================" << endl;
	cout << "Ma so: " << so.maSo << endl;
	cout << "Ho ten khach hang: " << so.hoTen << endl;
	cout << "Loai so: " << so.loai << endl;
	cout << "Ngay mo so (dinh dang day/month/year): " << so.thoiGian.ngay << " / " << so.thoiGian.thang << " / " << so.thoiGian.nam << endl;
	cout << "So tien gui: " << so.tienGui;
}

void Init(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

DanhSach* createNode(DanhSach data)
{
	DanhSach* p = new DanhSach();
	if (p == NULL)
		return NULL;		
	p->STK.hoTen = data.STK.hoTen;
	p->STK.loai = data.STK.loai;
	p->STK.maSo = data.STK.maSo;
	p->STK.thoiGian = data.STK.thoiGian;
	p->STK.tienGui = data.STK.tienGui;
	p->pNext = NULL;
	return p;
}

void addTail(LIST& l, DanhSach data)
{
	DanhSach* p = createNode(data);
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void nhapDanhSach(LIST& l)
{
	int n;
	cout << "Nhap so luong so tiet kiem: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		DanhSach* p = new DanhSach;
		nhapSoTietKiem(p->STK);
		addTail(l, *p);
	}
}

void xuatDanhSach(LIST l)
{
	for (DanhSach* i = l.pHead; i != NULL; i = i->pNext)
	{
		xuatSoTietKiem(i->STK);
	}
}

// cau 4
ostream& operator << (ostream& os, const SoTietKiem& stk)
{
	os << stk.maSo << ", " << stk.loai << ", " << stk.hoTen << ", ";
	os<<stk.thoiGian.ngay<< "/" << stk.thoiGian.thang<<"/"<<stk.thoiGian.nam<<", ";
	os << stk.tienGui<<endl;
	return os;
}
void writeFile(ofstream& fileOut, LIST l, string fileName)
{
	fileOut.open(fileName, ios_base::out | ios_base::binary);
	fileOut << "Ma So, Loai Tiet Kiem, Ho Ten Khach Hang, Ngay Mo So, So Tien Gui" << endl;
	for (DanhSach* i = l.pHead; i != NULL; i = i->pNext)
	{
		fileOut << i->STK;
	}

	fileOut.close();
}

//cau 5
float tongTienGui(LIST l)
{
	float sum = 0;
	for (DanhSach* i = l.pHead; i != NULL; i = i->pNext)
	{
		sum += i->STK.tienGui;
	}
	return sum;
}

//cau 6
void deleteHead(LIST& l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	DanhSach* p = l.pHead; 
	l.pHead = l.pHead->pNext;
	delete p;
}
void deleteTail(LIST& l)
{
	if (l.pHead == NULL)
	{
		return;
	}
	if (l.pHead->pNext == NULL)
	{
		deleteHead(l);
		return;
	}
	for (DanhSach* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->pNext == l.pTail)
		{
			delete l.pTail; 
			k->pNext = NULL; 
			l.pTail = k; 
			return;
		}
	}
}


void deleteSTK(LIST& l, string ms)
{
	if (l.pHead == NULL)
	{
		return;
	}
	if (l.pHead->STK.maSo == ms)
	{
		deleteHead(l);
		return;
	}
	if (l.pHead->STK.maSo == ms)
	{
		deleteTail(l);
		return;
	}

	DanhSach* g = new DanhSach; 
	for (DanhSach* k = l.pHead; k != NULL; k = k->pNext)
	{
		if (k->STK.maSo == ms)
		{
			g->pNext = k->pNext; 
			delete k; 	
			return;
		}
		g = k; 
	}
}

// cau 7
int demSL(DanhSach* start, float x)
{
	int count = 0;
	if (start == NULL)
		return 0;
	else if (start->STK.tienGui < x)
		count = 1;
	else
		count = 0;
	return count + demSL(start->pNext, x);
}