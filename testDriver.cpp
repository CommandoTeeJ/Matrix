#include "Matrix.h"
#include <iostream>

using namespace std;

int main() {
	int rows, cols;

	cout << "A rows:";
	cin >> rows;
	cout << "A cols:";
	cin >> cols;
	Matrix<int> A(cols, rows);
	cout << "Enter Matrix A:\n";
	cin >> A;

	cout << "B rows:";
	cin >> rows;
	cout << "B cols:";
	cin >> cols;
	Matrix<int> B(cols, rows);
	cout << "Enter Matrix B:\n";
	cin >> B;
	Matrix<int> temp;
	cout << "\n\nA+B\n";
	temp = A + B;
	temp.consolePrint("");
	cout << "\nA-B\n";
	temp = A - B;
	temp.consolePrint("");
	cout << "\nA*B\n";
	temp = A * B;
	temp.consolePrint("");
	cout << "\nA transposed\n";
	temp = A.transpose();
	temp.consolePrint("");
	cout << "\nA total:\n";
	cout << A.Total();

	cin.get();
	cin.get();
	cin.get();
	cin.get();
	cin.get();
}
