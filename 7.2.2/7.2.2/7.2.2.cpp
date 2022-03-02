#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
bool SearchMinEven(int** a, const int n, const int k, int& minEven);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -10;
	int High = 10;
	int n;
	int k;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	CreateRows(a, k, n, Low, High, 0);
	Print(a, k, n, 0, 0);
	
	int minEven;
	if (SearchMinEven(a, k, n, minEven))
		cout << "min even = " << minEven << endl;
	else
		cout << "there are no even elements" << endl;
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void CreateRows(int** a, const int rowCount, const int colCount, const int Low,

	const int High, int rowNo)

{
	CreateRow(a, rowNo, colCount, Low, High, 0);
	if (rowNo < rowCount - 1)
		CreateRows(a, rowCount, colCount, Low, High, rowNo + 1);

}
void CreateRow(int** a, const int rowNo, const int colCount, const int Low,

	const int High, int colNo)

{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < colCount - 1)
		CreateRow(a, rowNo, colCount, Low, High, colNo + 1);

}
void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	cout << setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl << endl;

}

bool SearchMinEven(int** a, const int k, const int n, int& minEven)
{
	minEven = -10;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (minEven < a[j][i]) {
			minEven = a[j][i];
		}
	}
	if (j + 2 < k) {
		j + 2;
		for (int i = 0; i < n; i++)
		{
			if (minEven < a[j][i]) {
				minEven = a[j][i];
			}
		}
	}
	else {
		if (j + 2 < k) {
			j + 2;
			for (int i = 0; i < n; i++)
			{
				if (minEven < a[j][i]) {
					minEven = a[j][i];
				}
			}
		}
		else {
			if (j + 2 < k) {
				j + 2;
				for (int i = 0; i < n; i++)
				{
					if (minEven < a[j][i]) {
						minEven = a[j][i];
					}
				}
			}
			else {
				if (j + 2 < k) {
					j + 2;
					for (int i = 0; i < n; i++)
					{
						if (minEven < a[j][i]) {
							minEven = a[j][i];
						}
					}
				}
				else {

				}
			}
		}
	}

	return true;
}