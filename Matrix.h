#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

template <class T>
class Matrix
{

public:
	//constructors
	//No value
	Matrix();
	//One value passed (fill a 3x3 with value)
	Matrix(T val);
	//rows and columns,no default value
	Matrix(int row, int col);
	//rows and columns,default value given
	Matrix(int row, int col, T val);

	template <class T> friend std::istream& operator>> (std::istream& is, const Matrix<T>& Matin);

	Matrix transpose();

	//template <class T> friend std::ostream& operator<< (std::ostream& out, const Matrix<T>& Matout);

	int size();

	T at(int x, int y);

	void set(int x, int y, T setter);

	void consolePrint(std::string name);

	int row() {
		return rows;
	}

	int col() {
		return columns;
	}

	Matrix multiply(Matrix b);

	Matrix add(Matrix b);

	Matrix subtract(Matrix b);

	Matrix operator*(Matrix b);

	Matrix operator+(Matrix b);

	Matrix operator-(Matrix b);

	T linearVal(int pos);

	void linearSet(int pos, T value);

	T Total();
private:
	int rows;
	int columns;
	int totalSize;

	std::vector<T> data;
};


template<class T>
Matrix<T>::Matrix() {
	rows = 3;
	columns = 3;
	totalSize = 9;
	data = vector<T>(totalSize, 0);
}


template<class T>
Matrix<T>::Matrix(T val) {
	rows = 3;
	columns = 3;
	totalSize = 9;
	data = vector<T>(totalSize, val);
}

template<class T>
Matrix<T>::Matrix(int row, int col) {
	rows = row;
	columns = col;
	totalSize = row*col;
	data = vector<T>(totalSize, 0);
}

template<class T>
Matrix<T>::Matrix(int row, int col, T val) {
	rows = row;
	columns = col;
	totalSize = row*col;
	data = vector<T>(totalSize, val);
}

template <class T>
Matrix<T> Matrix<T>::transpose() {
	Matrix<T> temp(columns, rows);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			temp.set(i, j, at(j, i));
		}
	}

	return temp;
}
//template <class T>
/*std::ostream& operator<< (std::ostream& out, Matrix<T>& Matout) {
	for (int i = 0; i < Matout.col(); i++) {
		for (int j = 0; j < Matout.row(); j++) {
			out << Matout.at(i, j) << " ";
		}
		out << std::endl;
	}
	return out;
}*/

template <class T>
std::istream& operator>> (std::istream& is, Matrix<T>& Matin) {
	T temp;

	for (int i = 0; i < Matin.col(); i++) {
		for (int j = 0; j < Matin.row(); j++) {
			is >> temp;
			Matin.set(i, j, temp);
		}

	}

	return is;
}

template<class T>
int Matrix<T>::size() {
	return totalSize;
}

template<class T>
T Matrix<T>::linearVal(int pos) {
	return data[pos];
}

template<class T>
void Matrix<T>::linearSet(int pos, T value) {
	data[pos] = value;
}

template<class T>
T Matrix<T>::at(int x, int y) {
	int position = (y*columns) + (x);
	return data[position];
}

template<class T>
void Matrix<T>::set(int x, int y, T setter) {
	//cout << endl << x << " " << y;
	assert(x < columns && y < rows);
	int position = (y*columns) + (x);
	data[position] = setter;
}

template<class T>
Matrix<T> Matrix<T>::add(Matrix b) {
	assert(rows == b.rows);
	assert(columns == b.columns);

	Matrix<T> temp(rows, columns);
	for (int i = 0; i < rows*columns; i++) {
		temp.linearSet(i, linearVal(i) + b.linearVal(i));
	}

	return temp;
}

template<class T>
Matrix<T> Matrix<T>::subtract(Matrix b) {
	assert(rows == b.rows);
	assert(columns == b.columns);

	Matrix<T> temp(rows, columns);
	for (int i = 0; i < rows*columns; i++) {
		temp.linearSet(i, linearVal(i) - b.linearVal(i));
	}

	return temp;
}

template <class T>
Matrix<T> Matrix<T>::multiply(Matrix b) {
	assert(rows == b.columns);

	Matrix<T> temp(b.rows, columns);
	int tempVal = 0, curLoc = 0;
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < b.rows; j++) {
			for (int k = 0; k < rows; k++) {
				//cout << endl << " " << i << " " << j << " " << k;
				tempVal += at(i, k) * b.at(k, j);
			}
			//cout << endl << "coord:" << rows;
			temp.set(i, j, tempVal);
			curLoc++;
			tempVal = 0;
		}

	}
	return temp;
}

template <class T>
Matrix<T> Matrix<T>::operator*(Matrix b) {
	return multiply(b);
}

template <class T>
Matrix<T> Matrix<T>::operator+(Matrix b) {
	return add(b);
}

template <class T>
Matrix<T> Matrix<T>::operator-(Matrix b) {
	return subtract(b);
}

template <class T>
void Matrix<T>::consolePrint(std::string name) {
	std::cout << "\n" + name + ":\n";
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << at(i, j) << " ";
		}
		cout << std::endl;
	}
}

template <class T>
T Matrix<T>::Total() {
	T temp = 0;
	for (int i = 0; i < totalSize; i++) {
		temp += data[i];
	}
	return temp;
}
#endif
