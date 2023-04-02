#pragma once

#define PI 3.14159265359
#define DEG2RAD PI / 180
#define RAD2DEG 180 / PI

struct Vector2D
{
	float x, y;

	/*
		Constructor
	*/
	Vector2D(float x, float y);
	Vector2D(int x, int y);
	/*
		Init to x = 0, y = 0;
	*/
	Vector2D();
	/*
		distance from v1 to v2 squared
		faster than vector_distance_to
	*/
	float DistanceSquared(const Vector2D& v);
	/*
		distance from v1 to v2
		slower than vector_distance_to_squared
		more accurate than vector_distance_to_squared
	*/
	float Distance(const Vector2D& v);
	/*
		returns the magnitude of v1
	*/
	float Length() const;
	/*
		returns angle from v1 to v2 (radians)
	*/
	float AngleTo(const Vector2D& v);
	/*
		returns sum of the 2 vectors
		v1 + v2
	*/
	Vector2D operator+(const Vector2D& v);
	/*
		returns difference between the 2 vectors
		v1 - v2
	*/
	Vector2D operator-(const Vector2D& v);
	/*
		returns sum of the 2 vectors
	*/
	float DotProduct(const Vector2D& v);
	/*
		returns sum of the 2 vectors
	*/
	float operator*(const Vector2D& v);
	/*
		returns sum of the vector and scalar
		v1 + (f, f)
	*/
	Vector2D operator+(float f);
	/*
		returns difference between the vector and scalar
		v1 - (f, f)
	*/
	Vector2D operator-(float f);
	/*
		returns product of the vector and scalar
		v1 * f
	*/
	Vector2D operator*(float f);
	/*
		returns quotient of the vector and scalar
		v1 * f
	*/
	Vector2D operator/(float f);

public:
	static const Vector2D& ZeroVector;
};
