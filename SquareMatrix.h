#ifndef __SquareMatrix__
#define __SquareMatrix__

//------------------------------------------------------------------------------
// SquareMatrix.h - содержит описание обобщающей квадратной матрицы
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

#include "rnd.h"

//------------------------------------------------------------------------------
// Структура, обобщающая все имеющиеся квадратные матрицы
class SquareMatrix {
protected:
    static Random rnd100000;
    static Random rnd3;
    size_t n;
    double * values;
public:
    virtual ~SquareMatrix() {};
    // Ввод обобщенной квадратной матрицы
    static SquareMatrix *StaticIn(ifstream &ifdt);
    // Ввод обобщенной квадратной матрицы
    virtual void In(ifstream &ifdt) = 0;
    // Случайный ввод обобщенной квадратной матрицы
    static SquareMatrix *StaticInRnd();
    // Виртуальный метод ввода случайной квадратной матрицы
    virtual void InRnd() = 0;
    // Вывод обобщенной квадратной матрицы
    virtual void Out(ofstream &ofst) = 0;
    // Вычисление среднего арифметического значений обобщенной квадратной матрицы
    virtual double Average() = 0;
};


#endif
