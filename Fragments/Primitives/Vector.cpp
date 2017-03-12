#include "Vector.h"

Vector2::Vector2()
	: x(0)
	, y(0)
{
}

Vector2::Vector2(float x, float y)
	: x(x)
	, y(y)
{
}

Vector2::Vector2(const Vector2& rhs)
	: x(rhs.x)
	, y(rhs.y)
{
}

Vector2::~Vector2()
{
}

void Vector2::operator+=(const Vector2& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
}

void Vector2::operator-=(const Vector2& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
}

void Vector2::operator*=(float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
}

void Vector2::operator*=(const Vector2& rhs)
{
	this->x *= rhs.x;
	this->y *= rhs.y;
}

void Vector2::operator/=(float rhs)
{
	this->x /= rhs;
	this->y /= rhs;
}

void Vector2::operator/=(const Vector2& rhs)
{
	this->x /= rhs.x;
	this->y /= rhs.y;
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
	Vector2 that;
	that.x = rhs.x;
	that.y = rhs.y;
	return *this;
}

Vector2& Vector2::operator=(const Vector2& rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

Vector2 operator + (const Vector2& lhs, const Vector2& rhs)
{
	return Vector2( lhs.x + rhs.x, lhs.y + rhs.y );
}

Vector2 operator -	(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2 operator *	(const Vector2& lhs, float rhs)
{
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

Vector2 operator *	(float lhs, const Vector2& rhs)
{
	return Vector2(lhs * rhs.x, lhs * rhs.y);
}

Vector2 operator *	(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x * rhs.x, lhs.y * rhs.y);
}

Vector2 operator /	(const Vector2& lhs, float rhs)
{
	return Vector2(lhs.x / rhs, lhs.y / rhs);
}

bool	operator == (const Vector2& lhs, const Vector2& rhs)
{
	return (lhs.x == rhs.x && lhs.y == rhs.y);
}

bool	operator != (const Vector2& lhs, const Vector2& rhs)
{
	return !(lhs == rhs);
}

bool	operator <	(const Vector2& lhs, const Vector2& rhs)
{
	return (lhs.x < rhs.x && lhs.y < rhs.y);
}