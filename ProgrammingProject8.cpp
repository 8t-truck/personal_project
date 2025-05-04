#include <iostream>
using namespace std;

class Temperature {
public:
    Temperature(double f = 32.0) {
        fahrenheit = f;
    }

    bool operator==(const Temperature& other) const {
        return fahrenheit == other.fahrenheit;
    }

    void operator<<(ostream& out) const {
        out << fahrenheit << " degrees Fahrenheit";
    }

    void operator>>(istream& in) {
        in >> fahrenheit;
    }

private:
    double fahrenheit;
};

int main() {
    Temperature temp1(98.6);
    Temperature temp2;

    cout << "Enter a temperature in Fahrenheit: ";
    temp2 >> cin;  // 사용자로부터 입력

    cout << "\nYou entered: ";
    temp2 << cout;  // temp2 출력

    cout << "\nComparing with temp1 (98.6 F): ";
    if (temp1 == temp2) {
        cout << "They are the same temperature!" << endl;
    }
    else {
        cout << "They are different temperatures." << endl;
    }

    cout << "\nTemp1 is: ";
    temp1 << cout;  // temp1 출력
    cout << endl;

    return 0;
}
