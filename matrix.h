#pragma once 
#pragma execution_character_set("utf-8")

<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS  //Äèðåêòèâû äëÿ êîððåêòíîé ðàáîòû ïðîãðàììû
//Ïðèìå÷àíèå: Ðàáîòàåò òîëüêî íà Windows!
//Ñòàíäàðò ÿçûêà: C99.
=======
#define _CRT_SECURE_NO_WARNINGS  //Ð”Ð¸Ñ€ÐµÐºÑ‚Ð¸Ð²Ñ‹ Ð´Ð»Ñ ÐºÐ¾Ñ€Ñ€ÐµÐºÑ‚Ð½Ð¾Ð¹ Ñ€Ð°Ð±Ð¾Ñ‚Ñ‹ Ð¿Ñ€Ð¾Ð³Ñ€Ð°Ð¼Ð¼Ñ‹
//ÐŸÑ€Ð¸Ð¼ÐµÑ‡Ð°Ð½Ð¸Ðµ: Ð Ð°Ð±Ð¾Ñ‚Ð°ÐµÑ‚ Ñ‚Ð¾Ð»ÑŒÐºÐ¾ Ð½Ð° Windows!
//Ð¡Ñ‚Ð°Ð½Ð´Ð°Ñ€Ñ‚ ÑÐ·Ñ‹ÐºÐ°: C99.
>>>>>>> 28337a314bf6312dc224290ed877ece416d0b6e2
///
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

enum MatrixError
{
    MATRIX_ERROR_INPUT, 
    MARTIX_ERROR_PRINT,
    MATRIX_ERROR_MEM,
    MATRIX_ERROR_DELETE,
    MATRIX_ERROR_SUM,
    MATRIX_ERROR_SUB,
    MATRIX_ERROR_TRANSP,
    MATRIX_ERROR_MUL,
    MATRIX_ERROR_GAUS,
    MATRIX_ERROR_INV,
    MATRIX_ERROR_MULN
};

typedef struct Matrix
{
    int m, n;
    double countSwaps;
    double** arr;
}Matrix;

Matrix division(Matrix* a, Matrix* b);
Matrix summatrix(Matrix* x, Matrix* y);
Matrix subtraction(Matrix* x, Matrix* y);
Matrix multiplication(Matrix* x, Matrix* y);             
void transp(Matrix* a);
void mulnum(Matrix* a, double k);
Matrix gauss(Matrix* a);
void input(Matrix* x);
void getmemory(Matrix* x, int N, int M);
void output(Matrix* x);
void removemem(Matrix* a);
void inversion(Matrix* a);
int subsum(Matrix* x, Matrix* y);
int multi(Matrix* a, Matrix* b);
double det(Matrix* matrix);
void equating(Matrix* a, Matrix* b);
void saveFile(Matrix* a,char *filename);
void outerror(int typeError, const char* errStr);
void loadFile(Matrix* a,char *filename);
//
