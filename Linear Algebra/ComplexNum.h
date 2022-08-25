#pragma once
#include <iostream>

template<typename T>
class ComplexNum {
private:
	T Real;
	T Imaginary;

public:
	// Constructor, Destructor
	ComplexNum();
	ComplexNum(T real, T imaginary);
	ComplexNum<T>(const ComplexNum<T>& other);

	// Operator Overload
	bool operator==(ComplexNum<T> other) const;
	ComplexNum<T> operator+(const ComplexNum<T>& other) const;
	ComplexNum<T> operator-(const ComplexNum<T>& other) const;
	ComplexNum<T> operator*(const ComplexNum<T>& other) const;
	ComplexNum<T> operator/(const ComplexNum<T>& other) const;
	ComplexNum<T>& operator+=(const ComplexNum<T>& other);
	ComplexNum<T>& operator-=(const ComplexNum<T>& other);
	ComplexNum<T>& operator*=(const ComplexNum<T>& other);
	ComplexNum<T>& operator/=(const ComplexNum<T>& other);
	ComplexNum<T> operator+(T real) const;
	ComplexNum<T> operator-(T real) const;
	ComplexNum<T> operator*(T scaler) const;
	ComplexNum<T> operator/(T scaler) const;
	ComplexNum<T>& operator+=(T real);
	ComplexNum<T>& operator-=(T real);
	ComplexNum<T>& operator*=(T scaler);
	ComplexNum<T>& operator/=(T scaler);

	// Getters and Setters
	T GetReal() const;
	T GetImaginary() const;
	void SetReal(T value);
	void SetImaginary(T value);

	// Math
	ComplexNum<T> getMultiplicativeInverse() const;
	ComplexNum<T> getAdditiveInverse() const;
	ComplexNum<T> getConjugate() const;
	T getAbsoluteValue() const;
	T getDistance(const ComplexNum<T>& other) const;

	// Utility
	void print() const;

	/**TODO**/

	// Polar Coordinates (Requires Custom trig library)
};

/***********************Constructor/Destructor***********************************/

template<typename T>
ComplexNum<T>::ComplexNum() : Real(), Imaginary() {
}

template<typename T>
ComplexNum<T>::ComplexNum(T real, T imaginary) : Real(real), Imaginary(imaginary) {
}

template<typename T>
ComplexNum<T>::ComplexNum(const ComplexNum<T>& other) : Real(other.Real), Imaginary(other.Imaginary) {
}

/*****************************OPERATOR OVERLOADS**********************************/

template<typename T>
bool ComplexNum<T>::operator==(ComplexNum<T> other) const {
	return (this->Real == other.Real) && (this->Imaginary == other.Imaginary);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator+(const ComplexNum<T>& other) const {
	return ComplexNum<T>(this->Real + other.Real, this->Imaginary + other.Imaginary);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator-(const ComplexNum<T>& other) const {
	return ComplexNum<T>(this->Real - other.Real, this->Imaginary - other.Imaginary);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator*(const ComplexNum<T>& other) const {
	return ComplexNum<T>(this->Real * other.Real - this->Imaginary * other.Imaginary, this->Imaginary * other.Real + this->Real * other.Imaginary);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator/(const ComplexNum<T>& other) const {
	return ComplexNum<T>((this->Real * other.Real + this->Imaginary * other.Imaginary) / (other.Real * other.Real + other.Imaginary * other.Imaginary),
		(this->Imaginary * other.Real - this->Real * other.Imaginary) / (other.Real * other.Real + other.Imaginary * other.Imaginary));
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator+=(const ComplexNum<T>& other) {
	Real = this->Real + other.Real;
	Imaginary = this->Imaginary + other.Imaginary;
	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator-=(const ComplexNum<T>& other) {
	Real = this->Real - other.Real;
	Imaginary = this->Imaginary - other.Imaginary;
	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator*=(const ComplexNum<T>& other) {
	T temp = this->Real * other.Real - this->Imaginary * other.Imaginary;
	Imaginary = this->Imaginary * other.Real + this->Real * other.Imaginary;
	Real = temp;
	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator/=(const ComplexNum<T>& other) {
	T temp = (this->Real * other.Real + this->Imaginary * other.Imaginary) / (other.Real * other.Real + other.Imaginary * other.Imaginary);
	Imaginary = (this->Imaginary * other.Real - this->Real * other.Imaginary) / (other.Real * other.Real + other.Imaginary * other.Imaginary);
	Real = temp;
	return *this;
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator+(T real) const {
	return ComplexNum<T>(Real + real, Imaginary);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator-(T real) const {
	return ComplexNum<T>(Real - real, Imaginary);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator*(T scaler) const {
	return ComplexNum<T>(Real * scaler, Imaginary * scaler);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::operator/(T scaler) const {
	return ComplexNum<T>(Real / scaler, Imaginary / scaler);
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator+=(T real) {
	Real = Real + real;
	Imaginary = Imaginary;
	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator-=(T real) {
	Real = Real - real;
	Imaginary = Imaginary;
	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator*=(T scaler) {
	Real = Real * scaler;
	Imaginary = Imaginary * scaler;
	return *this;
}

template<typename T>
ComplexNum<T>& ComplexNum<T>::operator/=(T scaler) {
	Real = Real / scaler;
	Imaginary = Imaginary / scaler;
	return *this;
}

/*****************************GETTERS AND SETTERS*********************************/

template<typename T>
T ComplexNum<T>::GetReal() const {
	return Real;
}

template<typename T>
T ComplexNum<T>::GetImaginary() const {
	return Imaginary;
} 

template<typename T>
void ComplexNum<T>::SetReal(T value) {
	Real = value;
}

template<typename T>
void ComplexNum<T>::SetImaginary(T value) {
	Imaginary = value;
}

/*************************************MATH**************************************/

template<typename T>
ComplexNum<T> ComplexNum<T>::getMultiplicativeInverse() const {
	return ComplexNum<T>(Real / (Real * Real + Imaginary * Imaginary), -(Imaginary / (Real * Real + Imaginary * Imaginary)));
}

template<typename T>
ComplexNum<T> ComplexNum<T>::getAdditiveInverse() const {
	return ComplexNum<T>(-Real, -Imaginary);
}

template<typename T>
ComplexNum<T> ComplexNum<T>::getConjugate() const {
	return ComplexNum<T>(Real, -Imaginary);
}

template<typename T>
T ComplexNum<T>::getAbsoluteValue() const {
	return T(sqrt(Real * Real + Imaginary * Imaginary));
}

template<typename T>
inline T ComplexNum<T>::getDistance(const ComplexNum<T>& other) const {
	return T(sqrt((Real - other.Real) * (Real - other.Real) + (Imaginary - other.Imaginary) * (Imaginary - other.Imaginary)));
}

/************************************UTILITY***********************************/

template<typename T>
void ComplexNum<T>::print() const {
	std::cout << Real << "+" << Imaginary << "i\n";
}
