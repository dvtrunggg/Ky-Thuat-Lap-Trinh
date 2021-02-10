#include"lap2.h"

void Input(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> *(a + i);
	}
}
void Output(int* a, int n)
{
	cout << "Your array: " << endl;
	for (int i = 0; i < n; i++)
		cout << *(a + i) << "   ";

}

// Numbers have the ending of 6
void NumsEnding_In6(int* a, int n) 
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int j = *(a + i);
		if (abs(j) == 6)
			count++;
		else if (abs(j)% 10 == 6)
			count++;

	}
	cout << "Array number elements have the ending of 6: " <<count<<endl;
}
//Numbers is divisible by 6  
void Divided_By6(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (*(a+i) % 6 == 0)
			count++;
	}
	cout << "Array elements is divisible by 6: " <<count<<endl;
}

// Numbers are divisible by 6 and have the ending of 6
void Both(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int j = abs(*(a + i));
		if (j % 10 == 6 && j % 6 == 0)
			count++;
	}
	cout << "Array elements are divisible by 6 and have the ending of 6 : " << count << endl;
}
