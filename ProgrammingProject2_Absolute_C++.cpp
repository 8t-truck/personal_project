#include <iostream>
#include <string>
#include <cstdlib>
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
	friend int gcd(int a, int b);
	friend void reduceFraction(int& numerator, int& denominator);
	friend ostream& operator<<(ostream& out, const Rational& r);//clear
	friend istream& operator>>(istream& in, Rational& r);//clear
};

int main(void)
{
	int n, d;
	cin >> n >> d;
	Rational test(n, d);
	cout << test;
	return 0;
}

Rational::Rational()
	:numerator(0),denominator(1)
{
	normalize();
}//clear

Rational::Rational(int wholeNumber)
	:numerator(wholeNumber),denominator(1)
{
	normalize();
}//clear

Rational::Rational(int num, int demon)
	:numerator(num),denominator(demon)
{
	normalize();
}//clear
int gcd(int a, int b)
{
	a = abs(a);
	b = abs(b);
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
void reduceFraction(int& numerator, int& denominator)
{
	if (numerator == 0) {
		denominator = 1; // 0일 땐 0/1로 처리
		return;
	}

	int g = gcd(numerator, denominator);
	numerator /= g;
	denominator /= g;

	// 분모를 양수로 유지 (부호를 분자로 넘김)
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}
void Rational::normalize()
{
	//음양 판정
	if ((numerator < 0) ^ (denominator < 0))
	{
		numerator = -abs(numerator);
		denominator = abs(denominator);
	}
	else if ((numerator < 0) && (denominator < 0))
	{
		numerator = abs(numerator);
		denominator = abs(denominator);
	}
	//유클리드 호제법을 이용한 약분함수 구하기
	reduceFraction(numerator, denominator);
}


int Rational::getNumerator() const
{
	return numerator;
}
int Rational::getDenominator() const
{
	return denominator;
}
ostream& operator<<(ostream& out, const Rational& r)		//C++ 개체에 멤버 함수과(와) 호환되지 않는 형식 한정자가 있습니다. The object has type qualifiers that are not compatible with the member function C++
{															//const함수가 아닌 함수가 const함수를 가져옴
	out << r.getNumerator() << '/' << r.getDenominator();

	return out;
}//clear
istream& operator>>(istream& in, Rational& r)
/*
string으로 입력을 받고 
/를 기준으로 앞뒤를 string_to_int로 각각 numerator, denominator로 분배
약분은 나중에 생각할게...
*/
{
	string input;
	cout << "Enter the rational number(ex 1/3)";
	in >> input;
	
	int slashPos = input.find('/');

	if (slashPos == string::npos) {
		// '/'가 없으면 잘못된 입력
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
		/*
		if (num * denom < 0)
		{
			여기서 음양을 따지기 보다는 
			아래 normalize 함수에서 음양을 같이 따지는게
			더 좋을 듯
		}
		*/
		r.numerator = num;
		r.denominator = denom;
		r.normalize();	//아직 구현 안함
	}
	catch (...) {
		// stoi 실패 시 (예: "a/3") 입력 실패 처리
		in.setstate(std::ios::failbit);
	}

	return in;
}
