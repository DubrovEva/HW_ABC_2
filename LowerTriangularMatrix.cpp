//------------------------------------------------------------------------------
// LowerTriangularMatrix.cpp - содержит методы нижней треугольной матрицы
//------------------------------------------------------------------------------

#include "LowerTriangularMatrix.h"

//------------------------------------------------------------------------------
// Ввод параметров нижней треугольной матрицы из файла
void LowerTriangularMatrix::In(ifstream &ifst) {
    ifst >> n;
    values = (double *) malloc(sizeof(double) * n * (n + 1) / 2);
    for (int i = 0, ind = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int extra;
            if (j <= i)
                ifst >> values[ind++];
            else
                ifst >> extra;
        }
    }
}

// Случайный ввод параметров нижней треугольной матрицы
void LowerTriangularMatrix::InRnd() {
    n = (int) SquareMatrix::rnd100000.Get() % 100 + 1;
    values = (double *) malloc(sizeof(double) * n * (n + 1) / 2);
    for (int i = 0; i < n * (n + 1) / 2; ++i) {
        values[i] = SquareMatrix::rnd100000.Get() / SquareMatrix::rnd100000.Get();
    }
}

//------------------------------------------------------------------------------
// Вывод параметров нижней треугольной матрицы в форматируемый поток
void LowerTriangularMatrix::Out(ofstream &ofst) {
    ofst << "It is a diagonal matrix. Dimension: n = "
         << n << ", values: \n";
    for (int i = 0, ind = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j <= i)
                ofst << values[ind++] << " ";
            else
                ofst << "0 ";
        }
        ofst << "\n";
    }
    ofst << "average: " << Average() << '\n';
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического значений диагональной матрицы
double LowerTriangularMatrix::Average() {
    double result = 0.0;
    for (int i = 0; i < n * (n + 1) / 2; ++i) {
        result += values[i];
    }
    return result / n / n;
}
