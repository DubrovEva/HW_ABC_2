//------------------------------------------------------------------------------
// SquareMatrix.cpp - содержит процедуры связанные с обработкой обобщенной квадратной матрицы
// и создания произвольной квадратной матрицы
//------------------------------------------------------------------------------

#include "DiagonalMatrix.h"
#include "RegularArray.h"
#include "LowerTriangularMatrix.h"

//------------------------------------------------------------------------------
Random SquareMatrix::rnd100000(1, 100000);
Random SquareMatrix::rnd3(1,3);

//------------------------------------------------------------------------------
// Ввод параметров обобщенной квадратной матрицы из файла
SquareMatrix* SquareMatrix::StaticIn(ifstream &ifst) {
    int k;
    ifst >> k;
    SquareMatrix* matrix = nullptr;
    switch(k) {
        case 1:
            matrix = new RegularArray;
            break;
        case 2:
            matrix = new DiagonalMatrix;
            break;
        case 3:
            matrix = new LowerTriangularMatrix;
            break;
    }
    matrix->In(ifst);
    return matrix;
}

// Случайный ввод обобщенной квадратной матрицы
SquareMatrix *SquareMatrix::StaticInRnd() {
    auto k = SquareMatrix::rnd3.Get();
    SquareMatrix* matrix = nullptr;
    switch(k) {
        case 1:
            matrix = new RegularArray;
            break;
        case 2:
            matrix = new DiagonalMatrix;
            break;
        case 3:
            matrix = new LowerTriangularMatrix;
            break;
    }
    matrix->InRnd();
    return matrix;
}
