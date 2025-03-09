#include <iostream>
using namespace std;
int sum(int matrix[5][5]);
int sumofdiamond(int matrix[5][5]);
void printmatrix(int matrix[5][5]);
void print_diamond_ofmatrix(int matrix[5][5]);


int main()
{

	int result1, result2;
	int matrix[5][5];
	for (int row = 0; row < 5; row++)
		for (int col = 0; col < 5; col++)
		{
			cout << "enter the valu" << "\t" << row << "," << col << "\n";
			cin >> matrix[row][col];
		}
	result1 = sum(matrix);
	result2 = sumofdiamond(matrix);


	cout << "sum of matrix=" << result1 << "\n";
	cout << "sum of diamond matrix=" << result2 << "\n";
	cout << "matrix:\n";
	printmatrix(matrix);
	cout << "\n";
	cout << "this is the diamond of matrix\n";
	print_diamond_ofmatrix(matrix);


}
int sum(int matrix[5][5])
{
	int sum = 0;
	for (int row = 0; row < 5; row++)
		for (int col = 0; col < 5; col++)
			sum += matrix[row][col];
	return sum;

}
int sumofdiamond(int matrix[5][5])
{
	int sum_of_diamond = 0;
	for (int row = 0; row < 5; row++)
		for (int col = 0; col < 5; col++)
		{
			if (row == col)

				sum_of_diamond += matrix[row][col];


		}
	return sum_of_diamond;
}
void printmatrix(int matrix[5][5])
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 5; col++)


			cout << matrix[row][col] << "\t";



		cout << "\n";

	}
}
void print_diamond_ofmatrix(int matrix[5][5])
{
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++)
		{
			if (row == col)
			{
				cout << matrix[row][col] << "\t";
			}
			else

				cout << "\t";

		}
		cout << endl;
	}
}

