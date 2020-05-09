#pragma once
#include <iostream>
class Matrix
{
private:
	int** data_row = nullptr;
	int row = 0;
	int column = 0;
public:
	Matrix() : data_row{ nullptr }, row{ 0 }, column{0} {}
	Matrix(int r, int c) : data_row{ new int*[r]}, row{ r }, column{c} {
		for (int i = 0; i < r; i++) {
			data_row[i] = new int[c];
			for (int j = 0; j < c; j++) {
				data_row[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix& a);
	Matrix& operator =(const Matrix& a);
	Matrix operator+(const Matrix& a);
	Matrix operator-(const Matrix& a);
	Matrix operator*(const Matrix& a);
	int* operator[](const int i);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& a);

	int getRow() { return this->row; }
	int getColumn() { return this->column; }

	~Matrix(){
		for (int i = 0; i < row; i++) {
			delete [] data_row[i];
			data_row[i] = nullptr;
		}
		delete[] data_row;
	}
};

