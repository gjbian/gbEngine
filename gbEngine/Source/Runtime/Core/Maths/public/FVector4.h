
#include <iostream>

#pragma pack(16)
class FVector4
{
public:
	FVector4();

	FVector4(const FVector4& other);

	FVector4(float px, float py, float pz, float pw);

	void Zero();

	void Normalize();

	FVector4 GetSafeNormalize() const;

	float Magnitude() const;

	FVector4 Cross(const FVector4& other) const;

	void SetComponent(float px, float py, float pz, float pw);

	FVector4& operator = (const FVector4& other);

	FVector4 operator - () const;

	bool operator == (const FVector4& other) const;

	bool operator != (const FVector4& other) const;

	FVector4 operator + (const FVector4& other) const;

	FVector4 operator - (const FVector4& other) const;

	FVector4& operator += (const FVector4& other);

	FVector4& operator -= (const FVector4& other);

	float operator * (const FVector4& other) const;

	FVector4 operator * (float f) const;

	FVector4 operator / (float f) const;

	FVector4& operator *= (float f);

	FVector4& operator /= (float f);

	friend std::ostream& operator << (std::ostream& fout, const FVector4& out);

	static void UnitTest();

public:
	float x, y, z, w;
};

inline FVector4 operator * (float f, const FVector4& v);

inline FVector4 CrossVector(const FVector4& v1, const FVector4& v2);

inline float SquareDistance(const FVector4& v1, const FVector4 v2);

inline float Distance(const FVector4& v1, const FVector4 v2);
