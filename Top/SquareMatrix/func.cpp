#include "func.hpp"
#include <cmath>

using namespace std;

SquareMatrix::SquareMatrix(const SquareMatrix &Base, int k)
{
    n = Base.n - 1;
    M = new double* [n];
    for(int i=0; i<n; i++)
        M[i] = new double [n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            M[i][j] = Base.M[i+1][j];
        }
        for(int j=k; j<n; j++)
        {
            M[i][j] = Base.M[i+1][j+1];
        }
    }
}

SquareMatrix::~SquareMatrix()
{
    for(int i=0; i<n; i++)
    {
        delete [] M[i];
    }
    delete [] M;
    M = nullptr;
    n=0;
}

std::ostream & operator<<(std::ostream & mystream, const SquareMatrix & rhs)
{
    for(int i=0; i<rhs.n; i++)
    {
        for(int j=0; j<rhs.n; j++)
            mystream<<rhs.M[i][j]<<" ";
        mystream<<endl;
    }
    return mystream;
}

std::istream & operator>>(std::istream & mystream, SquareMatrix & rhs)
{
    cout<<"Enter number of cols and rows:"<<endl;
    mystream>>rhs.n;
    rhs.M = new double* [rhs.n];
    for(int i=0; i<rhs.n; i++)
        rhs.M[i] = new double [rhs.n];
    for(int i=0; i<rhs.n; i++)
    {
        cout<<"Enter elements of row "<<i+1<<endl;
        for(int j=0; j<rhs.n; j++)
            mystream>>rhs.M[i][j];
    }
    return mystream;
}

double SquareMatrix::Det()
{
    switch (n)
    {
    case 0:
        return 0;
        break;
    case 1:
        return  M[0][0];
        break;
    case 2:
        return ( M[0][0]*M[1][1] ) - ( M[0][1]*M[1][0] );
        break;
    default:
        double answer=0;
        for (int k=0; k<n; k++)
        {
            SquareMatrix T(*this,k);
            answer+= pow( -1, k) * M[0][k] * T.Det();
        }
        return answer;
        break;
    }
}
