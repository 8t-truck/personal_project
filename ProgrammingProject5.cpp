#include<iostream>
using namespace std;
class Vector2D
{
public:
	int operator*(const Vector2D& other);
	int getX() const;
	int getY() const;
	void setX(int xVal) { x = xVal; }
	void setY(int yVal) { y = yVal; }
private:
	int x;
	int y;
};
int main()
{
	Vector2D v1, v2;
	v1.setX(3);
	v1.setY(4);
	v2.setX(2);
	v2.setY(5);

	cout << "Dot product: " << (v1 * v2) << endl;

	return 0;
}

int Vector2D::operator* (const Vector2D& other)
{
	int result;
	result = x * other.getX() + y * other.getY();
	return result;
}
int Vector2D::getX() const
{
	return x;
}
int Vector2D::getY() const
{
	return y;
}
void Vector2D::setX(int xVal) { x = xVal; }
void Vector2D::setY(int yVal) { y = yVal; }