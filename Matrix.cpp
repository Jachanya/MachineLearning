#include "Matrix.h"
//copy constructor
Matrix::Matrix(const Matrix& a) {
	//copy matrix and the data into a new matrix
	if (this->data_row == nullptr) {
		this->column = a.column;
		this->row = a.row;
		data_row = new int* [a.row];
		for (int i = 0; i < a.row; i++) {
			data_row[i] = new int[a.column];
			for (int j = 0; j < a.column; j++) {
				data_row[i][j] = a.data_row[i][j];
			}
		}
	}
}
Matrix& Matrix::operator =(const Matrix& a) {
	//copy matrix and the data into a new matrix
	if (this->data_row == nullptr) {
		this->column = a.column;
		this->row = a.row;
		data_row = new int* [a.row];
		for (int i = 0; i < a.row; i++) {
			data_row[i] = new int[a.column];
			for (int j = 0; j < a.column; j++) {
				data_row[i][j] = a.data_row[i][j];
			}
		}
	}
	//rewrite values if current matrix is bigger
	//make extra part of matrix = to zero
	else if (this->row > a.row && this->column > a.column) {
		this->column = a.column;
		this->row = a.row;
		for (int i = 0; i < a.row; i++) {
			for (int j = 0; j < a.column; j++) {
				data_row[i][j] = a.data_row[i][j];
			}
			for (int z = a.column; z < this->column; z++) {
				data_row[i][z] = 0;
			}
		}
		for (int p = a.row; p < this->row; p++) {
			for (int q = 0; q < this->column; q++) {
				data_row[p][q] = 0;
			}
		}
	}
	//create new matrix if matrix is smaller
	else {
		for (int i = 0; i < this->row; i++) {
			delete[] data_row[i];
		}
		delete[] data_row;

		this->column = a.column;
		this->row = a.row;
		data_row = new int* [a.row];
		for (int i = 0; i < a.row; i++) {
			data_row[i] = new int[a.column];
			for (int j = 0; j < a.column; j++) {
				data_row[i][j] = a.data_row[i][j];
			}
		}
	}
	return *this;
}
int* Matrix::operator[](const int i){
	return this->data_row[i];
}
Matrix Matrix::operator+(const Matrix& a) {
	Matrix b(a.row, a.column);
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.column; j++) {
			b[i][j] = this->data_row[i][j] + a.data_row[i][j];
		}
	}
	return b;
}

Matrix Matrix::operator-(const Matrix& a) {
	Matrix b(a.row, a.column);
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.column; j++) {
			b[i][j] = this->data_row[i][j] - a.data_row[i][j];
		}
	}
	return b;
}

Matrix Matrix::operator*(const Matrix& a) {
	if (a.row != this->column && a.column != this->row) {
		std::cout << "Invalid operation, Matrix is not of the same size\n";
		throw - 1;
	}
	Matrix c(this->row, a.column);

	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < a.column; j++) {
			for (int z = 0; z < a.row; z++) {
				c[i][j]+= (this->data_row[i][z] * a.data_row[z][j]);
			}
		}
	}

	return c;
}
std::ostream& operator<<(std::ostream& os, const Matrix& a) {
	for (int i = 0; i < a.row; i++) {
		for (int j = 0; j < a.column; j++) {
			os << a.data_row[i][j] << " , ";
		}
		os << "\n";
	}
	return os;
}