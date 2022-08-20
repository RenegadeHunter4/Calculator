#pragma once
#include <vector>
#include <iostream>

class Matrix {
// Variables
private:
	int nRows = 1;
	int nCols = 1;
	std::vector<std::vector<int>> ColVecs;
	std::vector<std::vector<int>> RowVecs;

// Functions
public:
	// Constructor/Destructor
	Matrix(int n, int m, int value);
	Matrix(int n, int m);
	Matrix(std::vector<std::vector<int>> ColVecs);
	Matrix(const Matrix& other);
	~Matrix() = default;

	// Operator Overload
	std::vector<int> operator[](int i) const; //Element Access Operator
	Matrix operator+(Matrix other) const; //Addition Operator
	Matrix operator*(int scaler) const; // Scalar Multiplication
	Matrix operator*(Matrix lhs) const; // Scalar Multiplication
	Matrix operator-(Matrix other) const; //Subtraction Operator

	// Getting/Setting Matrix Elements
	void setElement(int row, int col, int value);
	void pushBackRow(std::vector<int> row);
	void pushBackColumn(std::vector<int> column);
	void insertRow(int pos, std::vector<int> row);
	void insertColumn(int pos, std::vector<int> column);
	void eraseRow(int pos);
	void eraseColumn(int pos);
	std::vector<int> getRow(int pos) const;
	std::vector<int> getColumn(int pos) const;

	// Getting Other variables
	int getNumColumns() const;
	int getNumRows() const;

	// Checks For Math
	bool isMultipliable(const Matrix& other) const;

	// Math

	// Misc. Utility
	void print() const;
private:
};

