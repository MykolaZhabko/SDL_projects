#include <math.h>

#ifndef ___Vector2D___
#define ___Vector2D___



class Vector2D
{
public:
	Vector2D(float x, float y): m_x(x), m_y(y){}

	float getX() { return m_x; }
	float getY() { return m_y; }
	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	Vector2D operator+(const Vector2D& v2) const //addition of the vectors
	{
		return Vector2D(m_x + v2.m_x, m_y+ v2.m_y);
	}

	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2)
	{
		v1.m_x += v2.m_x;
		v1.m_y += v2.m_y;
		return v1;
	}

	Vector2D operator*(float scalar) // multiply the vector on scalar vlue (v1 * n)
	{
		return Vector2D(m_x * scalar, m_y * scalar);
	}

	Vector2D& operator*=(float scalar)
	{
		m_x *= scalar;
		m_y *= scalar;

		return *this;
	}

	Vector2D operator/(float scalar) // divide the vector on scalar value (v1 / n)
	{
		return Vector2D(m_x / scalar, m_y / scalar);
	}

	Vector2D& operator/=(float scalar)
	{
		m_x /= scalar;
		m_y /= scalar;

		return *this;
	}

	Vector2D operator-(const Vector2D& v2) const // subtract two vectors
	{
		return Vector2D(m_x - v2.m_x, m_y - v2.m_y);
	}

	friend Vector2D& operator-=(Vector2D& v1, Vector2D& v2)
	{
		v1.m_x -= v2.m_x;
		v1.m_y -= v2.m_y;

		return v1;
	}

	void normalize()
	{
		float l = length();

		if (l > 0) // to avoid zero devision
			(*this) *= 1 / l;
	}

	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }
private:
	float m_x;
	float m_y;

};
#endif // !___Vector2D___
