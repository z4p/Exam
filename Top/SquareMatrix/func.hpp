#ifndef FUNC_HPP_INCLUDED
#define FUNC_HPP_INCLUDED

#include <fstream>
#include <iostream>

class SquareMatrix
{
    int n;
    double **M;
    SquareMatrix(const SquareMatrix &Base);
    SquareMatrix& operator=(const SquareMatrix &Base);
public:
    SquareMatrix(): n(0), M(nullptr) {};
    SquareMatrix(const SquareMatrix &Base, int k);
    ~SquareMatrix();

    double Det();

    friend std::ostream & operator<<(std::ostream & mystream, const SquareMatrix & rhs);
    friend std::istream & operator>>(std::istream & mystream, SquareMatrix & rhs);
};



#endif // FUNC_HPP_INCLUDED
