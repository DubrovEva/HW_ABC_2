//------------------------------------------------------------------------------
// rectangle.cpp - содержит методы диагональной матрицы
//------------------------------------------------------------------------------

#include "DiagonalMatrix.h"

//------------------------------------------------------------------------------
// Ввод параметров диагональной матрицы из файла
void DiagonalMatrix::In(ifstream &ifst) {
    ifst >> n;
    values = (double *) malloc(sizeof(double) * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int extra;
            if (i == j)
                ifst >> values[i];
            else
                ifst >> extra;
        }
    }
}

// Случайный ввод параметров диагональной матрицы
void DiagonalMatrix::InRnd() {
    n = (int) SquareMatrix::rnd100000.Get() % 100 + 1;
    values = (double *) malloc(sizeof(double) * n);
    for (int i = 0; i < n; ++i) {
        values[i] = SquareMatrix::rnd100000.Get() / SquareMatrix::rnd100000.Get();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров диагональной матрицы в форматируемый поток
void DiagonalMatrix::Out(ofstream &ofst) {
    ofst << "It is a diagonal matrix. Dimension: n = "
         << n << ", values: \n";
    for (int i = 0, ind = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                ofst << values[i] << " ";
            else
                ofst << "0 ";
            ++ind;
        }
        ofst << "\n";
    }
    ofst << "average: " << Average() << '\n';
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического значений диагональной матрицы
double DiagonalMatrix::Average() {
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        result += values[i];
    }
    return result / n / n;
}
