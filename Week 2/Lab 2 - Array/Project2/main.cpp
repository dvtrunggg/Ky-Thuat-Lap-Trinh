#include"lap2.h"

int main()
{
	int n;
	int* a;
	do
	{
		cout << "Enter the numbers of array (n < 100 ): n = ", cin >> n;
		if (n >= 100)
		{
			cout << "The number of array have to be less than 100 (n<100)\n";
			cout << "Please enter again" << endl;
			cout << "\n\n==================================================================" << endl;
			cout << "\n\t";
		}
	} while (n >= 100);
	a = new int[n];
	Input(a, n);
	Output(a, n);
	cout << "\n--------------------------------------------------------" << endl;
	NumsEnding_In6(a, n);
	Divided_By6(a, n);
	Both(a, n);
	delete[] a;
	return 0;
}
