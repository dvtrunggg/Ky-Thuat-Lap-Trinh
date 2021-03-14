#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

#define STR_SIZE 1000

using namespace std;

// Doc ma tran tu file cho truoc
void DocMaTranTuFile(char* file_name, int**& a, int& m, int& n)
{
	FILE *f;
    char ch[STR_SIZE];
    f = fopen(file_name, "r");
    if (f == NULL)
    {
        printf("Something wrong with file! \n");
        return;
    }
	fscanf(f, "%d", &m);	
	fscanf(f, "%d", &n);	
	a = new int* [m];
	for (int i = 0; i < m; i++)
		*(a + i) = new int[n];
    for(int i = 0; i<m; i++)
	{
    	for(int j = 0; j<n; j++)
    	{
    		fscanf(f, "%d", &*(*(a+i)+j));
		}
	}
	
	fclose(f);   
}
// Nhap ma tran tu ban phim
void NhapMaTran(int**& a, int& m, int& n) //m: Dong, n: Cot
{
	cout << "Nhap so dong: ";
	cin >> m;
	cout << "Nhap so cot: ";
	cin >> n;
	a = new int* [m];
	for (int i = 0; i < m; i++)
		*(a + i) = new int[n];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i << "][" << j << "] = ";
			cin >> *(*(a + i) + j);
		}
	}
}

void XuatMaTran(int** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << *(*(a + i) + j) << "	";
		}
		cout << endl;
	}
}

bool KiemTraMaPhuong(int **a, int m)
{
	int flag;
	//Kiem tra tong phan tu tren cac duong cheo
   	int sum = 0;
   	for (int i = 0; i < m; i++) 
   	{
      	for (int j = 0; j < m; j++) 
	  	{
         	if (i == j)
            	sum += *(*(a + i) + j);
      	}
   	}

   	//Kiem tra tong phan tu tren cac hang
   	for (int i = 0; i < m; i++) 
   	{
      	int sum1 = 0;
      	for (int j = 0; j < m; j++) 
		{
         	sum1 += *(*(a + i) + j);
      	}
      	if (sum == sum1)
         	flag = 1;
      	else 
		{
         	flag = 0;
         	break;
      	}
   	}

   	//Kiem tra tong phan tu tren cac cot
   	for (int i = 0; i < m; i++) 
	{
      	int sum2 = 0;
      	for (int j = 0; j < m; j++) 
		{
         	sum2 += *(*(a + j) + i);
      	}
      	if (sum == sum2)
         	flag = 1;
      	else 
		{
         	flag = 0;
         	break;
      	}
   	}
   	if (flag == 1)
      	return true;
   	else
      	return false;
}



void TimMaPhuong(int **a, int m, int n)
{
	int dem = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i > m-3)
				break;
			
			else
			{
				if(j <= n-3)
				{
					int size;
					if(m-i > n-j)
						size = n-j;
					else
						size = m-i;
					while(size > 2)
					{
						int **b;
						b = new int* [size];
						for (int row = 0; row < size; row++)
							*(b + row) = new int[size];
						for (int row = 0; row < size; row++)
						{
							for (int column = 0; column < size; column++)
							{
								
								*(*(b + row) + column) = *(*(a+(row+i))+(column+j));
							}
						}
						if(KiemTraMaPhuong(b, size))
						{
							dem ++;
							cout << "\nMa phuong: " << endl;
							XuatMaTran(b, size, size);
						}
						size--;
					}
				}	
			}
		}
	}
	if(dem==0)
		cout << "\nKhong ton tai ma phuong trong ma tran!\n";
}

int main()
{
	char* file;
	file = "matran.txt";
	int** a;
	int m;
	int n;
	NhapMaTran(a, m, n);
	DocMaTranTuFile(file, a, m, n);
	cout << "Xuat ma tran: " << endl;
	XuatMaTran(a, m, n);
	TimMaPhuong(a, m, n);
	return 0;
}
