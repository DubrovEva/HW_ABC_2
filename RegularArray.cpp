//------------------------------------------------------------------------------
// RegularArray.cpp - содержит функции обработки обычного квадратного массива чисел
//------------------------------------------------------------------------------

#include "RegularArray.h"

//------------------------------------------------------------------------------
// Ввод параметров обычного квадратного массива из потока
void RegularArray::In(ifstream &ifst) {
    ifst >> n;
    values = (double *) malloc(sizeof(double) * n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ifst >> values[i * n + j];
        }
    }
}

// Случайный ввод параметров обычного квадратного массива
void RegularArray::InRnd() {
    n = SquareMatrix::rnd100000.Get() % 100 + 1;
    values = (double *) malloc(sizeof(double) * n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            values[i * n + j] = SquareMatrix::rnd100000.Get() / SquareMatrix::rnd100000.Get();
        }
    }
}

//------------------------------------------------------------------------------
// Вывод параметров обычного квадратного массива в поток
void RegularArray::Out(ofstream &ofst) {
    ofst << "It is a regular array. Dimension: n = "
         << n << ", values: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ofst << values[i * n + j] << " ";
        }
        ofst << "\n";
    }
    ofst << "average: " << Average() << '\n';
}

//------------------------------------------------------------------------------
// Вычисление среднего арифметического значений обычного квадратного массива чисел
double RegularArray::Average() {
    double result = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result += values[i * n + j];
        }
    }
    return result / n / n;
}
