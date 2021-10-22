#ifndef __LowerTriangularMatrix__
#define __LowerTriangularMatrix__

//------------------------------------------------------------------------------
// DiagonalMatrix.h - содержит описание нижней треугольной матрицы
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"
#include "SquareMatrix.h"

// Нижняя треугольная матрица
class LowerTriangularMatrix: public SquareMatrix {
public:
    virtual ~LowerTriangularMatrix() {}
    // Ввод параметров нижней треугольной матрицы из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров нижней треугольной матрицы
    virtual void InRnd();
    // Вывод параметров нижней треугольной матрицы в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление среднего арифметического значений нижней треугольной матрицы
    virtual double Average();
};

#endif //__LowerTriangularMatrix__
