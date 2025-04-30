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

}//企奄びびびびびびびびびびび
int Rational::getNumerator() const
{
	return numerator;
}
int Rational::getDenominator() const
{
	return denominator;
}
ostream& operator<<(ostream& out, const Rational& r)		//C++ 鯵端拭 呉獄 敗呪引(人) 硲発鞠走 省澗 莫縦 廃舛切亜 赤柔艦陥. The object has type qualifiers that are not compatible with the member function C++
{															//const敗呪亜 焼観 敗呪亜 const敗呪研 亜閃身
	out << r.getNumerator() << '/' << r.getDenominator();

	return out;
}//clear
istream& operator>>(istream& in, Rational& r)
/*
string生稽 脊径聖 閤壱 
/研 奄層生稽 蒋及研 string_to_int稽 唖唖 numerator, denominator稽 歳壕
鉦歳精 蟹掻拭 持唖拝惟...
*/
{
	string input;
	cout << "Enter the rational number(ex 1/3)";
	in >> input;
	
	int slashPos = input.find('/');

	if (slashPos == string::npos) {
		// '/'亜 蒸生檎 設公吉 脊径
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
			食奄辞 製丞聖 魚走奄 左陥澗 
			焼掘 normalize 敗呪拭辞 製丞聖 旭戚 魚走澗惟
			希 疏聖 牛
		}*/
		r.numerator = num;
		r.denominator = denom;
		r.normalize();	//焼送 姥薄 照敗
	}
	catch (...) {
		// stoi 叔鳶 獣 (森: "a/3") 脊径 叔鳶 坦軒
		in.setstate(std::ios::failbit);
	}

	return in;
}