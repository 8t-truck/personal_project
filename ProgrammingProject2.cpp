#include <iostream>
#include <string>
using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;

	void normalize();
public:
	Rational();//clear						//default constructor
	Rational(int wholeNumber);//clear			//initialize wholeNumber/1
	Rational(int num, int demon);//clear

	int getNumerator() const;
	int getDenominator() const;

	//operator overload
	friend ostream& operator<<(ostream& out, const Rational& r);//clear
	friend istream& operator>>(istream& in, Rational& r);//clear
};

Rational::Rational()
	:numerator(0),denominator(1)
{
}//clear

Rational::Rational(int wholeNumber)
	:numerator(wholeNumber),denominator(1)
{
}//clear

Rational::Rational(int num, int demon)
	:numerator(num),denominator(demon)
{
}//clear
void Rational::normalize()
{

}//���ӤӤӤӤӤӤӤӤӤӤ�
int Rational::getNumerator() const
{
	return numerator;
}
int Rational::getDenominator() const
{
	return denominator;
}
ostream& operator<<(ostream& out, const Rational& r)		//C++ ��ü�� ��� �Լ���(��) ȣȯ���� �ʴ� ���� �����ڰ� �ֽ��ϴ�. The object has type qualifiers that are not compatible with the member function C++
{															//const�Լ��� �ƴ� �Լ��� const�Լ��� ������
	out << r.getNumerator() << '/' << r.getDenominator();

	return out;
}//clear
istream& operator>>(istream& in, Rational& r)
/*
string���� �Է��� �ް� 
/�� �������� �յڸ� string_to_int�� ���� numerator, denominator�� �й�
����� ���߿� �����Ұ�...
*/
{
	string input;
	cout << "Enter the rational number(ex 1/3)";
	in >> input;
	
	int slashPos = input.find('/');

	if (slashPos == string::npos) {
		// '/'�� ������ �߸��� �Է�
		in.setstate(ios::failbit);
		return in;
	}

	string numStr = input.substr(0, slashPos);
	string denomStr = input.substr(slashPos + 1);

	try {
		int num = stoi(numStr);
		int denom = stoi(denomStr);

		if (denom == 0) {
			in.setstate(ios::failbit);
			return in;
		}
		/*if (num * denom < 0)
		{
			���⼭ ������ ������ ���ٴ� 
			�Ʒ� normalize �Լ����� ������ ���� �����°�
			�� ���� ��
		}*/
		r.numerator = num;
		r.denominator = denom;
		r.normalize();	//���� ���� ����
	}
	catch (...) {
		// stoi ���� �� (��: "a/3") �Է� ���� ó��
		in.setstate(std::ios::failbit);
	}

	return in;
}