#include "Circle.h"

Circle::Circle(const int a, const int b, const double r): x(a), y(b), radius(r) {}

Circle::Circle(const Circle& myObj): y(myObj.y), x(myObj.x), radius(myObj.radius){}

Circle::Circle(Circle&& myObj): y(myObj.y), x(myObj.x), radius(myObj.radius) {
	myObj.y = 0;
	myObj.x = 0;
	myObj.radius = 0;
}

Circle& Circle::operator=(Circle&& newObj) {
	if (this == &newObj) {
		return *this;
	}
	radius = newObj.radius;
	y = newObj.y;
	x = newObj.x;
	return *this;
}

bool Circle::operator==(const Circle newObj)
{
	return (radius == newObj.radius && x == newObj.x && y == newObj.y);
}

bool Circle::operator!=(const Circle newObj)
{
	return (!operator==(newObj));
}

bool Circle::operator>(const Circle newObj)
{
	return radius > newObj.radius;
}

bool Circle::operator<(const Circle newObj)
{
	return radius < newObj.radius;
}

Circle Circle::operator+(int newObj)
{
	Circle temp = *this;
	temp.radius = radius + newObj;
	return temp;
}

Circle Circle::operator-(int newObj)
{
	Circle temp = *this;
	temp.radius = radius - newObj;
	return temp;
}

Circle& Circle::operator++()
{
	++radius;
	return *this;
}

Circle& Circle::operator--()
{
	--radius;
	return *this;
}

Circle Circle::operator++(int)
{
	Circle temp = *this;
	radius++;
	return *this;
}

Circle Circle::operator--(int)
{
	Circle temp = *this;
	radius--;
	return *this;
}

void Circle::operator()(int newX, int newY, double newRadius) {
	x = newX;
	y = newY;
	radius = newRadius;
}

int Circle::getX() const {
	return x;
}
int Circle::getY() const {
	return y;
}
double Circle::getRadius() const {
	return radius;
}

double Circle::getAreaCircle() const {
	return PI * pow(radius, 2);
}

double Circle::getLengthCircle() const {
	return 2 * PI * radius;
}

void Circle::setX(const int s) {
	x = s;
}

void Circle::setY(const int s) {
	y = s;
}
void Circle::setRadius(const int s) {
	radius = s;
}
