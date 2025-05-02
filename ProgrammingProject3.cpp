#include<iostream>
using namespace std;
class Complex
{

public:
	Complex();											//0 + 0*i
	Complex(double realPart);							//realPart + 0*i
	Complex(double realPart, double imaginaryPart);		//r + ima*i

	double getReal() const;
	double getImaginary() const;
	
	friend bool operator ==(const Complex& num1, const Complex& num2);
	friend Complex operator +(const Complex& num1, const Complex& num2);
	friend Complex operator -(const Complex& num1, const Complex& num2);
	friend Complex operator *(const Complex& num1, const Complex& num2);

	friend ostream& operator<<(ostream& out, const Complex& num);
	friend istream& operator>>(istream& in, Complex& num);

private:
	double real;
	double imaginary;
};
int main(void)
{
	Complex test1;
	cin >> test1;
	Complex test2(3, -8);
	cout << "test1 * test2 = " << test1 * test2 << endl;
	cout << "test1 + test2 = " << test1 + test2 << endl;
	cout << "test1 - test2 = " << test1 - test2 << endl;
	cout << "test1 == test2 :" << (test1 == test2) << endl;

	return 0;
}
Complex::Complex()
	:real(0),imaginary(0)
{
}
Complex::Complex(double realPart)
	:real(realPart), imaginary(0)
{
}
Complex::Complex(double realPart, double imaginaryPart)
	:real(realPart), imaginary(imaginaryPart)
{
}
double Complex::getReal() const
{
	return real;
}
double Complex::getImaginary() const
{
	return imaginary;
}
bool operator ==(const Complex& num1, const Complex& num2)
{
	if ((num1.imaginary == num2.imaginary) && (num1.real == num2.real))
		return true;
	else
		return false;
}
Complex operator +(const Complex& num1, const Complex& num2)
{
	double tempReal = num1.getReal() + num2.getReal();
	double tempImaginary = num1.getImaginary() + num2.getImaginary();
	Complex result(tempReal, tempImaginary);
	return result;
}
Complex operator -(const Complex& num1, const Complex& num2)
{
	double tempReal = num1.getReal() - num2.getReal();
	double tempImaginary = num1.getImaginary() - num2.getImaginary();
	Complex result(tempReal, tempImaginary);
	return result;
}
Complex operator *(const Complex& num1, const Complex& num2)
{
	double tempReal = (num1.getReal() * num2.getReal())
		- (num1.getImaginary() * num2.getImaginary());
	double tempImaginary = (num1.getReal() * num2.getImaginary())
		+ (num1.getImaginary() * num2.getReal());
	Complex result(tempReal, tempImaginary);
	return result;
}
ostream& operator<<(ostream& out, const Complex& num)
{
	out << num.getReal() << '+' << num.getImaginary() << 'i';
	return out;
}
istream& operator>>(istream& in, Complex& num)
{
	cout << "enter real" << endl;
	in >> num.real;
	cout << "enter imaginary" << endl;
	in >> num.imaginary;
	return in;
}