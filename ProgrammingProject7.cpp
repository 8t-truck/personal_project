#include <iostream>
using namespace std;

// PrimeNumber Ŭ���� ����
class PrimeNumber {
public:
    // �⺻ ������: �Ҽ��� 1�� �ʱ�ȭ
    PrimeNumber() {
        prime = 1;
    }

    // �Ű������� �ִ� ������
    PrimeNumber(int n) {
        if (isPrime(n))
            prime = n;
        else
            prime = 1;  // �Ҽ��� �ƴϸ� 1�� �ʱ�ȭ
    }

    // �Ҽ��� �������� �Լ�
    int get() const {
        return prime;
    }

    // ���� ++ �����ε�
    PrimeNumber& operator++() {
        prime = nextPrime(prime);
        return *this;
    }

    // ���� ++ �����ε�
    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;
        prime = nextPrime(prime);
        return temp;
    }

    // ���� -- �����ε�
    PrimeNumber& operator--() {
        prime = prevPrime(prime);
        return *this;
    }

    // ���� -- �����ε�
    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        prime = prevPrime(prime);
        return temp;
    }

private:
    int prime;

    // �Ҽ� �Ǻ� �Լ�
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    // ���� �Ҽ� ã��
    int nextPrime(int n) {
        int next = n + 1;
        while (!isPrime(next))
            ++next;
        return next;
    }

    // ���� �Ҽ� ã�� (1 ���Ϸ� �������� ����)
    int prevPrime(int n) {
        if (n <= 2) return 1;
        int prev = n - 1;
        while (prev > 1 && !isPrime(prev))
            --prev;
        return prev;
    }
};

int main() {
    PrimeNumber p1;  // �⺻ ������ -> 1
    PrimeNumber p2(13);  // 13���� �ʱ�ȭ

    cout << "Initial p1: " << p1.get() << endl;
    cout << "Initial p2: " << p2.get() << endl;

    cout << "\nTesting ++ (prefix and postfix):" << endl;
    cout << "p2 (before): " << p2.get() << endl;
    ++p2;
    cout << "After prefix ++: " << p2.get() << endl;
    p2++;
    cout << "After postfix ++: " << p2.get() << endl;

    cout << "\nTesting -- (prefix and postfix):" << endl;
    cout << "p2 (before): " << p2.get() << endl;
    --p2;
    cout << "After prefix --: " << p2.get() << endl;
    p2--;
    cout << "After postfix --: " << p2.get() << endl;

    return 0;
}
