#include"18126035.h"

int main()
{
	ifstream file;
	file.open("data.txt", ios_base::out);
	int row = countRows(file);
	file.close();

	file.open("data.txt", ios_base::out);
	int Ins = countIntegers(file);
	file.close();

	//count columns in file : columns = the number of intergers / rows.Đếm số cột ma trận : số cột = tổng số / số dòng
	int column = Ins / row;
	
	file.open("data.txt", ios_base::out);

	int** a = new int* [row];
	for (int i = 0; i < row; i++)
	{
		*(a + i) = new int[column];
	}

	readFile(file, a, row, column);
	Print(a, row, column);
	cout << "================================================" << endl;

	if (isMagicSquare(a, row, column) == true)
		cout << "true";
	else
		cout << "false";
	
	//test(a, column, row);
	file.close();
	for (int i = 0; i < row; i++)
	{
		delete[] * (a + i);
	}
	delete[] a;
	a = NULL;
	
	return 0;
}
