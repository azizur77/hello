
#include <assert.h> // for assert()>

#include <stdio.h>
#include<iostream>

using namespace std;
template <typename T>
class Array
{
private:
    int m_nLength;
    T *m_ptData;

public:
    Array()
    {
        m_nLength = 0;
        m_ptData = 0;
    }

    Array(int nLength)
    {
        m_ptData= new T[nLength];
        m_nLength = nLength;
    }

    ~Array()
    {
        delete[] m_ptData;
    }

    void Erase()
    {
        delete[] m_ptData;
        // We need to make sure we set m_pnData to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_ptData= 0;
        m_nLength = 0;
    }

    T& operator[](int nIndex)
    {
        assert(nIndex >= 0 && nIndex < m_nLength);
        return m_ptData[nIndex];
    }

    // The length of the array is always an integer
    // It does not depend on the data type of the array
    int GetLength(); // templated GetLength() function defined below
};

template <typename T>
int Array<T>::GetLength() { return m_nLength; }




int main()
{cout << "good" ;
    Array<int> anArray(12);
    Array<double> adArray(12);

    for (int nCount = 0; nCount < 12; nCount++)
    {
        anArray[nCount] = nCount;
        adArray[nCount] = nCount + 0.5;
    }

    for (int nCount = 11; nCount >= 0; nCount--)
        cout << anArray[nCount] << "\t" << adArray[nCount]<<endl ;

    return 0;
}
