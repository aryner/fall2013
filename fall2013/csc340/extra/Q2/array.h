#include <iostream>

using namespace::std;

template<class T>
class Array
{
public:
	Array(int initialSize)
	{
		m_nSize = initialSize;
		try{
			m_pData = new T[m_nSize];
		} catch (...) {}
		currSize = 0;
	}

	~Array()
	{
		delete m_pData;
	}

	T & operator[](int i)
	{
		return m_pData[i];
	}

	void append(const T & item)
	{
		m_pData[currSize] = item;
		currSize++;
	}

	void remove(int i)
	{
		for(;i<currSize-1; i++)
		{
			m_pData[i] = m_pData[i+1];
		}
		currSize--;
	}

	int length()
	{
		return currSize;
	}

	friend ostream & operator<<(ostream & out, const Array<T> & myArr)
	{

		out << "<";
		for(int i=0; i<myArr.currSize; i++) {
			out << myArr.m_pData[i];
			if(i<myArr.currSize-1)
				out << ",";
		}
		out << ">";

		return out;
	}

private:
	T * m_pData;
	int m_nSize;
	int currSize;
};

