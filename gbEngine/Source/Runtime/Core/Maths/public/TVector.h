
#include <iostream>
#include <initializer_list>

template <class T, int d>
class TVector
{
public:
	using FElement = T;
	static const int g_NumElements = d;

	TVector(){}

	~TVector(){}

	explicit TVector(const FElement& element)
	{
		for (int i = 0; i < g_NumElements; i++)
		{
			m_Elements[i] = element;
		}
	}

	TVector(std::initializer_list<T> inElements)
	{
		auto iter = inElements.begin();
		for (int i = 0; i < g_NumElements; iter++, i++)
		{
			m_Elements[i] = *iter;
		}
	}

	template<class T2>
	TVector(const TVector<T2, d>& other)
	{
		memcpy(this->m_Elements, other.m_Elements, g_NumElements * sizeof(FElement));
	}

	TVector(std::istream& stream)
	{
		for (int i = 0; i < g_NumElements; i++)
		{
			stream.read(reinterpret_cast<char*>(&m_Elements[i]), sizeof(FElement));
		}
	}

	TVector<T, d>& operator = (const TVector<T, d>&other)
	{
		if (this != &other)
		{
			memcpy(this->m_Elements, other.m_Elements, g_NumElements * sizeof(FElement));
		}
		return *this;
	}

	FElement& operator[](int index)
	{
		return m_Elements[index];
	}

	const FElement& operator[](int index) const
	{
		return m_Elements[index];
	}

	void Write(std::ostream& stream) const
	{
		for (int i = 0; i < g_NumElements; i++)
		{
			stream.write(reinterpret_cast<const char*>(&m_Elements[i]), sizeof(FElement));
		}
	}

	friend std::ostream& operator << (std::ostream& fout, TVector<T, d> out)
	{
		fout << "{";
		for (int i = 0; i < g_NumElements - 1; i++)
		{
			fout << out.m_Elements[i] << ",";
		}
		fout << out.m_Elements[g_NumElements - 1] << "}";
		return fout;
	}

	friend bool operator==(const TVector<T, d>& L, const TVector<T, d>& R)
	{
		for (int i = 0; i < g_NumElements; i++)
		{
			if (L.m_Elements[i] != R.m_Elements[i])
			{
				return false;
			}
		}
		return true;
	}

	friend bool operator!=(const TVector<T, d>& L, const TVector<T, d>& R)
	{
		return !(L == R);
	}

	static void UnitTest()
	{
		std::cout << "\n=====TVector::UnitTest=====\n" << std::endl;

		TVector<int, 4> testVector1({ 1, 2, 3, 4 });
		TVector<int, 4> testVector2(testVector1);
		std::cout << "testVector1:" << testVector1 << std::endl;
		std::cout << "testVector2:" << testVector2 << std::endl;
		std::cout << "testVector1 != testVector2 ? " << (testVector1 != testVector2) << std::endl;

		std::cout << "make testVector2[2] = 2" << std::endl;
		testVector2[2] = 2;
		std::cout << "testVector1:" << testVector1 << std::endl;
		std::cout << "testVector2:" << testVector2 << std::endl;
		std::cout << "testVector1 != testVector2 ? " << (testVector1 != testVector2) << std::endl;
		

		std::cout << "make testVector1 = testVector2" << std::endl;
		testVector1 = testVector2;
		std::cout << "testVector1:" << testVector1 << std::endl;
		std::cout << "testVector2:" << testVector2 << std::endl;
		std::cout << "testVector1 != testVector2 ? " << (testVector1 != testVector2) << std::endl;

		std::cout << "\n=====TVector::UnitTest=====\n" << std::endl;
	}

private:
	FElement m_Elements[g_NumElements];
};
