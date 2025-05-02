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
    // �⺻ ������ �׽�Ʈ
    CharPair cp1;
    cout << "cp1 (default constructor): ";
    for (int i = 0; i < 10; i++) {
        cout << cp1[i];
    }
    cout << endl;

    // �� ��° ������ �׽�Ʈ (size�� �ִ� ������)
    CharPair cp2(5);
    cout << "cp2 (size 5): ";
    for (int i = 0; i < 5; i++) {
        cout << cp2[i];
    }
    cout << endl;

    // �� ��° ������ �׽�Ʈ (size + �迭 ����)
    char sample[] = { 'A', 'B', 'C', 'D', 'E' };
    CharPair cp3(5, sample);
    cout << "cp3 (custom array): ";
    for (int i = 0; i < 5; i++) {
        cout << cp3[i];
    }
    cout << endl;

    // operator[] �׽�Ʈ: �� ����
    cp3[0] = 'Z';
    cout << "cp3 after modifying first element: ";
    for (int i = 0; i < 5; i++) {
        cout << cp3[i];
    }
    cout << endl;

    // ��谪 �׽�Ʈ (���� �߻� Ȯ��)
    // cp3[5] = 'X'; // �ּ� ���� �� ���� �޽��� ��� & ���α׷� ����

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