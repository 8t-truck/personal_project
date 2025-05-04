#include<iostream>
#include<vector>
using namespace std;
class BoxOfProduce
{
public:
    BoxOfProduce();
	BoxOfProduce(const vector<string>& items);
	string getProduce(int index) const;
	void setProduce(int index, const string& item);
	void addProduce(const string& item);
	void displayBox()const;
	BoxOfProduce operator+(const BoxOfProduce& other) const;

private:
	vector<string> produce;
};
int main() {
    // 첫 번째 상자
    BoxOfProduce box1;
    box1.addProduce("Broccoli");
    box1.addProduce("Tomato");
    box1.addProduce("Kiwi");

    cout << "Box 1 initial contents:" << endl;
    box1.displayBox();
    cout << endl;

    // 두 번째 상자
    BoxOfProduce box2;
    box2.addProduce("Kale");
    box2.addProduce("Tomatillo");

    cout << "Box 2 initial contents:" << endl;
    box2.displayBox();
    cout << endl;

    // + 연산자로 상자 합치기
    BoxOfProduce combinedBox = box1 + box2;

    cout << "Combined box contents:" << endl;
    combinedBox.displayBox();

    // 추가 테스트: box1에 더 추가
    cout << "\nAdding 'Cabbage' to Box 1..." << endl;
    box1.addProduce("Cabbage");
    box1.displayBox();

    return 0;
}
BoxOfProduce::BoxOfProduce()
{

}
BoxOfProduce::BoxOfProduce(const vector<string>& items)
{
    produce = items;
}
string BoxOfProduce::getProduce(int index) const {
    if (index >= 0 && index < produce.size()) {
        return produce[index];
    }
    return "";
}
void BoxOfProduce::setProduce(int index, const string& item)
{
    if (index >= 0 && index < produce.size()) {
        produce[index] = item;
    }
}
void BoxOfProduce::displayBox() const {
    cout << "Box contents:" << endl;
    for (int i = 0; i < produce.size(); i++) {
        cout << i + 1 << ". " << produce[i] << endl;
    }
}
void BoxOfProduce::addProduce(const string& item)
{
    produce.push_back(item);
}
BoxOfProduce BoxOfProduce::operator+(const BoxOfProduce& other) const {
    BoxOfProduce result;
    for (const auto& item : produce) {
        result.addProduce(item);
    }
    for (const auto& item : other.produce) {
        result.addProduce(item);
    }
    return result;
}