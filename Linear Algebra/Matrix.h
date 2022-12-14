#pragma once
#include <vector>
#include <iostream>

class Matrix {
// Variables
private:
	int nRows = 0;
	int nCols = 0;
	std::vector<std::vector<int>> ColVecs;
	std::vector<std::vector<int>> RowVecs;

// Functions
public:
	// Constructor/Destructor
	Matrix();
	Matrix(int n, int m, int value);
	Matrix(int n, int m);
	Matrix(std::vector<std::vector<int>>& ColVecs);
	Matrix(const Matrix& other);
	~Matrix() = default;

	// Operator Overload
	std::vector<int> operator[](int i) const; //Element Access Operator
	Matrix operator+(const Matrix& other) const; //Addition Operator
	Matrix operator*(int scaler) const; // Scalar Multiplication
	Matrix operator*(const Matrix& rhs) const; // Matrix  Multiplication
	Matrix operator-(const Matrix& other) const; //Subtraction Operator
	Matrix& operator+=(const Matrix& other); //Addition & equal Operator
	Matrix& operator*=(int scaler); // Scalar & equal Multiplication
	Matrix& operator*=(const Matrix& rhs); // Scalar & equal Multiplication
	Matrix& operator-=(const Matrix& other); //Subtraction & equal Operator
	bool operator==(const Matrix& other) const; //if equal Operator

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
	bool isSquare() const;
	bool isInvertiable() const;

	// Math
	int findDeterminant() const;
	int findTrace() const;
	Matrix findTranspose() const;
	Matrix findMinor(int i, int j) const;

	// Misc. Utility
	void print() const;

	// Elementary Row Operations
	void EROSwap(int row1, int row2);
	void EROScale(int row, int scaler);
	void EROAdd(int row1, int row2, int scaler);

	// Elementary Column Operations
	void ECOSwap(int col1, int col2);
	void ECOScale(int col, int scaler);
	void ECOAdd(int col1, int col2, int scaler);

	/**TODO**/
	// REF and RREF finding functions
	// Inverse Finding Function
	// Rework class using templates
	// Rework class using custom vector wrapper that defines operations.
};

