#include <iostream>
using namespace std;

// PrimeNumber 클래스 정의
class PrimeNumber {
public:
    // 기본 생성자: 소수를 1로 초기화
    PrimeNumber() {
        prime = 1;
    }

    // 매개변수가 있는 생성자
    PrimeNumber(int n) {
        if (isPrime(n))
            prime = n;
        else
            prime = 1;  // 소수가 아니면 1로 초기화
    }

    // 소수를 가져오는 함수
    int get() const {
        return prime;
    }

    // 전위 ++ 오버로딩
    PrimeNumber& operator++() {
        prime = nextPrime(prime);
        return *this;
    }

    // 후위 ++ 오버로딩
    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;
        prime = nextPrime(prime);
        return temp;
    }

    // 전위 -- 오버로딩
    PrimeNumber& operator--() {
        prime = prevPrime(prime);
        return *this;
    }

    // 후위 -- 오버로딩
    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        prime = prevPrime(prime);
        return temp;
    }

private:
    int prime;

    // 소수 판별 함수
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    // 다음 소수 찾기
    int nextPrime(int n) {
        int next = n + 1;
        while (!isPrime(next))
            ++next;
        return next;
    }

    // 이전 소수 찾기 (1 이하로 내려가지 않음)
    int prevPrime(int n) {
        if (n <= 2) return 1;
        int prev = n - 1;
        while (prev > 1 && !isPrime(prev))
            --prev;
        return prev;
    }
};

int main() {
    PrimeNumber p1;  // 기본 생성자 -> 1
    PrimeNumber p2(13);  // 13으로 초기화

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
