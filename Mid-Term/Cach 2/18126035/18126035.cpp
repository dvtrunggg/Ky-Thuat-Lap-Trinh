#include"18126035.h"

void readFile(ifstream& fileName, int** a, int row, int column)
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			fileName>> *(*(a + i) + j);		
		}
	}
	if (fileName.fail())
	{
		cout << "File is now exist!. Please check again" << endl;
		exit(0);
	}

	/*while (!fileName.eof())
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				fileName >> *(*(a + i) + j);
			}
		}
	}*/
}
void Print(int** a, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << *(*(a + i) + j) << "\t";
		}
		cout << endl;
	}
}




// count lines in file  <=> count rows : đếm dòng ma trận 
int countRows(ifstream& fileName)
{
	int num = 0;
	string line;
	
	while (getline(fileName, line))
	{
		num++;
	}
	return num;
}
//count the number of integers
int countIntegers(ifstream& fileName)
{
	int numInt = 0;
	int countInt = 0;
	string s;
	while (fileName >> s)
	{
		countInt++;
	}
	return countInt;
}
// check magic square - hàm kiểm tra ma phương 

bool isMagicSquare(int** a, int row, int column)
{
	int N = Min(row, column);
	if (N == 1 || N == 0)
	{
		return false;
	}
	int sum1 = 0;
	for (int i = 0; i < N; i++)
	{
		sum1 += *(*(a + i) + i);
	}
	int sum2 = 0;
	for (int i = 0; i < N; i++)
	{
		sum2 += *(*(a + i) + N - i - 1);
	}
	if (sum1 != sum2)
	{
		return false;
	}

	for (int i = 0; i < N; i++)
	{
		int rowSum = 0;
		for (int j = 0; j < column; j++)
		{
			rowSum += *(*(a + i) + j);
		}
		if (rowSum != sum1)
		{
			return false;
		}
	}

	for (int i = 0; i < row; i++)
	{
		int columnSum = 0;
		for (int j = 0; j < column; j++)
		{
			columnSum += *(*(a + i) + j);
		}
		if (columnSum != sum1)
		{
			return false;
		}
	}
	return true;

}


 //check magic square is exist in matrix - kiểm tra ma trận có tồn tại ma phương ?

//void test(int** a, int column, int row)
//{
//
//	int i, j, ioff, joff, off_cnt;
//	int size = Min(column, row);	// vd: a[3][4] => tao toi da 1 ma tran vuong co size la a1[3][3]
//	
//	for (int k = size; k > 1; k--)
//	{
//
//		off_cnt = size - k + 1;
//		for (ioff = 0; ioff < off_cnt; ioff++)
//		{
//			for (joff = 0; joff < off_cnt; joff++)
//			{
//				for (i = 0; i < k; i++)
//				{
//					for (j = 0; j < k; j++)		//*(*(a + i + ioff) + j + joff)
//					{
//						{
//							cout << *(*(a + i + ioff) + j + joff) << "\t";
//						
//
//
//						}
//
//					}
//					cout << endl;
//				}
//				cout << endl;
//
//			}
//		}
//	}
//}

void test(int** a, int column, int row)
{

	int i, j, ioff, joff, off_cnt;
	int size = Min(column, row);	// vd: a[3][4] => tao toi da 1 ma tran vuong co size la a1[3][3]
	for (int k = size; k > 1; k--)
	{

		off_cnt = size - k + 1;
		for (ioff = 0; ioff < off_cnt; ioff++)
		{
			for (joff = 0; joff < off_cnt; joff++)
			{
				for (i = 0; i < k; i++)
				{
					for (j = 0; j < k; j++)		//*(*(a + i + ioff) + j + joff)
					{
						{
							cout << *(*(a + i + ioff) + j + joff) << "\t";
						


						}

					}
					cout << endl;
				}
				cout << endl;

			}
		}
	}
}

