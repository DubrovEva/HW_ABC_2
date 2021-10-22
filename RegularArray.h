#ifndef __RegularArray__
#define __RegularArray__

//------------------------------------------------------------------------------
// RegularArray.h - содержит описание обычного квадратного массива чисел
//------------------------------------------------------------------------------

#include <fstream>
using namespace std;

# include "rnd.h"
#include "SquareMatrix.h"

//------------------------------------------------------------------------------
// Обычный квадратный массив чисел
class RegularArray: public SquareMatrix {
public:
    virtual ~RegularArray() {}
    // Ввод параметров обычного квадратного массива из файла
    virtual void In(ifstream &ifst);
    // Случайный ввод параметров обычного квадратного массива чисел
    virtual void InRnd();
    // Вывод параметров обычного квадратного массива чисел в форматируемый поток
    virtual void Out(ofstream &ofst);
    // Вычисление среднего арифметического значений обычного квадратного массива
    virtual double Average();
};

#endif //__RegularArray__
