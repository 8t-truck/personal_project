#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class MyInteger
{
public:
	int get();
	void set(int input);
	int operator[] (int i);
private:
	int val;
};
int main()
{
	MyInteger myInt;
	myInt.set(9876);

	for (int i = 0; i < 6; i++)  // 0~5까지 테스트
	{
		cout << "Digit at position " << i << ": " << myInt[i] << endl;
	}

	return 0;
}

int MyInteger::get()
{
	return val;
}
void MyInteger::set(int input)
{
	val = input;
}
int MyInteger::operator[](int i)
{
	string temp = to_string(val);
	if (i + 1 > temp.length())
	{
		return -1;
	}
	for (int index = 0; index < i; index++)
		val = val / 10;
	return val % 10;
}