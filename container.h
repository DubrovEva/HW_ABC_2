#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "SquareMatrix.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
class Container {
public:
    Container();
    ~Container();

    // Ввод содержимого контейнера из указанного потока
    void In(ifstream &ifst);
    // Случайный ввод содержимого контейнера
    void InRnd(int size);
    // Вывод содержимого контейнера в указанный поток
    void Out(ofstream &ofst);
    // Сортировка контейнера по возрастанию среднего арифметического методом прямого включения
    void StraightSelectionSort();

private:
    void Clear();    // Очистка контейнера от данных
    int len; // текущая длина
    SquareMatrix* storage[10000];
};

#endif
