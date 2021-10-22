# HW_ABC_2
Домашнее задание номер 1 по курсу "Архитектура вычислительных систем"

# Отчет по заданию 1

## Описание полученного задания
**Обобщенный артефакт, используемый в задании:** Квадратные матрицы с действительными числами
**Базовые альтернативы
(уникальные параметры,
задающие отличительные
признаки альтернатив):**
1. Обычный двумерный
массив
2. Диагональная (на основе
одномерного массива)
3. Нижняя треугольная
матрица (одномерный массив с формулой пересчета)
**Общие для всех альтернатив переменные:** Размерность – целое число

**Общие для всех альтернатив функции:** Вычисление среднего арифметического (действительное число)

**Обработка контейнера:** Упорядочить элементы контейнера по возрастанию используя сортировку с помощью прямого включения (Straight Insertion). В качестве ключей для сортировки и других действий используются результаты функции, общей для всех альтернатив.

## Характеристики программы
**Число интерфейсных модулей**: 6

**Число модулей реализации**: 6

**Результаты тестирования:**
1. test_for_all_types_of_square_matrix - (real) 0.007s, (user) 0.007s, (sys) 0.000s
2. test_for_diagonal_matrix - (real) 0.005s, (user) 0.005s, (sys) 0.000s
3. test_for_lower_triangular_matrix - (real) 0.005s, (user) 0.005s, (sys) 0.000s
4. test_for_reqular_array - (real) 0.013s, (user) 0.013s, (sys) 0.004s
5. big_test_for_all_types - (real) 0.030s, (user) 0.029s, (sys) 0.000s

## Архитектура вычислительной системы

Память считаем в байтах.
int: 4
double: 4
char: 1
bool: 1

**Struct regular_array**

int n - 4, отступ 0;

double* array: n * n * sizeof(double*) = n * n * 4 в оперативной памяти, 8 на стеке, отступ 4;

Всего: 4 + n * n * 4 в оперативной памяти, 12 на стеке.

**Struct diagonal_matrix**

int n - 4, отступ 0;

double* array: n * sizeof(double) = n * 4 в оперативной памяти, 8 на стеке, отступ 4;

Всего: 4 + 4 n в оперативной памяти, 8 на стеке.

**Struct lower_triangular_matrix**

int n - 4, отступ 0;

double* array: n * (n + 1) / 2 * sizeof(double) = n * (n + 1) * 2 в оперативной памяти, 8 на стеке, отступ 4;

Всего: 4 + n * (n + 1) * 2 в оперативной памяти, 12 на стеке.

**Struct square_matrix**

enum key {REGULAR_ARRAY, DIAGONAL_MATRIX, LOWER_TRIANGULAR_MATRIX}: 4, отступ 0;

key k: 4, отступ 4;

union: 12 (на стеке), отступ 8;
r - 12, отступ 4;
d - 12, отступ 4;
l - 12, отступ 4;

Всего: 16.

**Struct conteiner**

enum {max_len = 10000}: 4, отступ 0;

int len: 4, отступ 4;

square_matrix* cont[max_len] - 10000 * sizeof(square_matrix) = 160000, отступ 8;

Всего: 160008.
