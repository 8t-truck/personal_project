#include<iostream>
#include <cstdlib>
using namespace std;
class CharPair
{
public:
	CharPair()
		:size(10)
	{
		for (int i = 0; i < 10; i++)
			arr[i] = '#';
	}
	CharPair(int sz)
		:size(sz)
	{
		for (int i = 0; i < size; i++)
			arr[i] = '#';
	}
	CharPair(int sz, char a[])
		:size(sz)
	{
		for (int i = 0; i < size; i++)
			arr[i] = a[i];
	}
	char& operator[](int index);

private:
	char arr[100];
	int size;

};
int main() {
    // 기본 생성자 테스트
    CharPair cp1;
    cout << "cp1 (default constructor): ";
    for (int i = 0; i < 10; i++) {
        cout << cp1[i];
    }
    cout << endl;

    // 두 번째 생성자 테스트 (size만 주는 생성자)
    CharPair cp2(5);
    cout << "cp2 (size 5): ";
    for (int i = 0; i < 5; i++) {
        cout << cp2[i];
    }
    cout << endl;

    // 세 번째 생성자 테스트 (size + 배열 전달)
    char sample[] = { 'A', 'B', 'C', 'D', 'E' };
    CharPair cp3(5, sample);
    cout << "cp3 (custom array): ";
    for (int i = 0; i < 5; i++) {
        cout << cp3[i];
    }
    cout << endl;

    // operator[] 테스트: 값 변경
    cp3[0] = 'Z';
    cout << "cp3 after modifying first element: ";
    for (int i = 0; i < 5; i++) {
        cout << cp3[i];
    }
    cout << endl;

    // 경계값 테스트 (에러 발생 확인)
    // cp3[5] = 'X'; // 주석 해제 시 오류 메시지 출력 & 프로그램 종료

    return 0;
}

char& CharPair::operator[](int index)
{
	if ((index < 0) || (index > size))
	{
		cout << "index must be upper than 0&lower than size" << endl;
		exit(1);
	}

	return arr[index];
}
