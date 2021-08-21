
#include "FVector4.h"
#include <math.h>

FVector4::FVector4() : x(0), y(0), z(0), w(0) {}

FVector4::FVector4(const FVector4& other) : x(other.x), y(other.y), z(other.z), w(other.w) {}

FVector4::FVector4(float px, float py, float pz, float pw) : x(px), y(py), z(pz), w(pw) {}

void FVector4::Zero()
{
	x = y = z = w = 0.0f;
}

void FVector4::Normalize()
{
	float squareSum = x * x + y * y + z * z + w * w;
	if (squareSum > 0.0f) {
		float invSquareSum = 1.0f / sqrtf(squareSum);
		x *= invSquareSum;
		y *= invSquareSum;
		z *= invSquareSum;
		w *= invSquareSum;
	}
}

FVector4 FVector4::GetSafeNormalize() const
{
	FVector4 out(x, y, z, w);
	out.Normalize();
	return out;
}

float FVector4::Magnitude() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

FVector4 FVector4::Cross(const FVector4& other) const
{
	return FVector4(
		y * other.z - z * other.y,
		z * other.x - x * other.z,
		x * other.y - y * other.x,
		0
	);
}

void FVector4::SetComponent(float px, float py, float pz, float pw)
{
	x = px; y = py; z = pz; w = pw;
}

FVector4& FVector4::operator = (const FVector4& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}

FVector4 FVector4::operator - () const
{
	return FVector4(-x, -y, -z, -w);
}

bool FVector4::operator == (const FVector4& other) const
{
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool FVector4::operator != (const FVector4& other) const
{
	return x != other.x || y != other.y || z != other.z || w != other.w;
}

FVector4 FVector4::operator + (const FVector4& other) const
{
	return FVector4(
		x + other.x,
		y + other.y,
		z + other.z,
		w + other.w
	);
}

FVector4 FVector4::operator - (const FVector4& other) const
{
	return FVector4(
		x - other.x,
		y - other.y,
		z - other.z,
		w - other.w
	);
}

FVector4& FVector4::operator += (const FVector4& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

FVector4& FVector4::operator -= (const FVector4& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

float FVector4::operator * (const FVector4& other) const
{
	return x * other.x + y * other.y + z * other.z + w * other.w;
}

FVector4 FVector4::operator * (float f) const
{
	return FVector4(x * f, y * f, z * f, w * f);
}

FVector4 FVector4::operator / (float f) const
{
	float invf = 1.0f / f;
	return operator*(invf);
}

FVector4& FVector4::operator *= (float f)
{
	x *= f; y *= f; z *= f; w *= f;
	return *this;
}

FVector4& FVector4::operator /= (float f)
{
	float invf = 1.0f / f;
	x *= invf; y *= invf; z *= invf; w *= invf;
	return *this;
}

std::ostream& operator << (std::ostream& fout, const FVector4& out)
{
	fout << "{" << out.x << "," << out.y << "," << out.z << "," << out.w << "}";
	return fout;
}

inline FVector4 operator * (float f, const FVector4& v)
{
	return v * f;
}

inline FVector4 CrossVector(const FVector4& v1, const FVector4& v2)
{
	return v1.Cross(v2);
}

inline float SquareDistance(const FVector4& v1, const FVector4 v2)
{
	float dx = (v1.x - v2.x);
	float dy = (v1.y - v2.y);
	float dz = (v1.z - v2.z);
	float dw = (v1.w - v2.w);
	return dx * dx + dy * dy + dz * dz + dw * dw;
}

inline float Distance(const FVector4& v1, const FVector4 v2)
{
	float dx = (v1.x - v2.x);
	float dy = (v1.y - v2.y);
	float dz = (v1.z - v2.z);
	float dw = (v1.w - v2.w);
	return sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
}

void FVector4::UnitTest()
{
	std::cout << "\n=====FVector4::UnitTest=====\n" << std::endl;

	FVector4 fVector4_1(1, 2, 3, 4);
	FVector4 fVector4_2(fVector4_1);
	std::cout << "fVector4_1:" << fVector4_1 << std::endl;
	std::cout << "fVector4_2:" << fVector4_2 << std::endl;
	std::cout << "testVector1 == testVector2 ? " << (fVector4_1 == fVector4_2) << std::endl;

	fVector4_1 = -fVector4_2;
	fVector4_2 += fVector4_1;
	std::cout << "fVector4_1:" << fVector4_1 << std::endl;
	std::cout << "fVector4_2:" << fVector4_2 << std::endl;
	std::cout << "testVector1 == testVector2 ? " << !(fVector4_1 != fVector4_2) << std::endl;

	fVector4_2 = -2 * fVector4_1;
	fVector4_1.x = 2;
	FVector4 fVector4_3 = CrossVector(fVector4_2, fVector4_1);
	std::cout << "fVector4_1:" << fVector4_1 << std::endl;
	std::cout << "fVector4_2:" << fVector4_2 << std::endl;
	std::cout << "fVector4_3:" << fVector4_3 << std::endl;
	std::cout << "Dot(fVector4_1, fVector4_3)=" << (fVector4_1 * fVector4_3) << std::endl;
	std::cout << "Add(fVector4_1, fVector4_3)=" << (fVector4_1 + fVector4_3) << std::endl;

	std::cout << "\n=====FVector4::UnitTest=====\n" << std::endl;
}
