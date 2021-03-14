#include"Lap8.h"


// cau 1
void read_AndWriteInteger(ifstream& fileIn, ofstream& fileOut, int* a, int& n)
{
	fileIn.open("input1.txt", ios_base::in);
	fileOut.open("output1.txt", ios_base::out);
	int i = 0;
	while (!fileIn.eof())
	{
		fileIn >> *(a + i);
		fileOut << *(a + i) << " ";
		i++;
	}
	fileIn.close();
	fileOut.close();
}
void cau1(ifstream& fileIn, ofstream& fileOut, int* a, int& n)
{
	read_AndWriteInteger(fileIn, fileOut, a, n);
	delete[] a;

}
// cau 2 - 3
int countRows(ifstream& fileIn)
{
	fileIn.open("input2.txt", ios_base::in);
	int num = 0;
	string line;

	while (getline(fileIn, line))
	{
		num++;
	}
	fileIn.close();
	return num;
}

int countColumns(ifstream& fileIn)
{
	int rows = countRows(fileIn);
	fileIn.open("input2.txt", ios_base::in);
	int columns = 0;
	int countInt = 0;

	string s;
	while (fileIn >> s)
	{
		countInt++;
	}
	fileIn.close();
	//file input2 chua ma tran.vd: ma tran 3x4 = > co 12 phan tu.so cot = so phan tu / so dong = 12 / 3 = 4
	columns = countInt / rows;
	return columns;
}
void readMatrix(ifstream& fileIn, int** a, int row, int column, ofstream& fileOut)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			fileIn >> *(*(a + i) + j);
			fileOut << *(*(a + i) + j)<<" ";
		}
		fileOut << endl;
	}

}
void cau2Va3(ifstream& fileIn, ofstream& fileOut, int**& a, int rows, int columns)
{
	a = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		*(a + i) = new int[columns];
	}
	fileIn.open("input2.txt", ios_base::in);
	fileOut.open("output2.txt", ios_base::out);
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


