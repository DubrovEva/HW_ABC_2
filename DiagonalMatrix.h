#ifndef __DiagonalMatrix__
#define __DiagonalMatrix__

//------------------------------------------------------------------------------
// DiagonalMatrix.h - содержит описание диагональной матрицы
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "SquareMatrix.h"

// Диагональная матрица
class DiagonalMatrix: public SquareMatrix {
public:
    virtual ~DiagonalMatrix() {}
    // Ввод параметров диагональной матрицы из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров диагональной матрицы
    virtual void InRnd();
    // Вывод параметров диагональной матрицы в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление среднего арифметического значений диагональной матрицы
    virtual double Average();
};

#endif //__DiagonalMatrix__
