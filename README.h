# Matrix.h
#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <locale.h>

typedef struct Matrix
{
    int column, line, size;
    double** arr;
}Matrix;
//@return sum matrix N x M
Matrix summatrix(Matrix* x, Matrix* y);
//@return sub matrix N x M
Matrix subtraction(Matrix* x, Matrix* y);
//@return mul matrix N x M
Matrix multiplication(Matrix* x, Matrix* y);
/*@returnreturns a matrix M x N instead N x M
*/                   
Matrix transp(Matrix* a);
//@return matrix mul number
Matrix mulnum(Matrix* a, double k);
//@return triangle matrix
Matrix gauss(Matrix* a);
//input matrix
void input(Matrix* x);
//gives memory to a dynamic two-dimensional array
void getmemory(Matrix* x, int N, int M);
//prints a matrix on the display
void output(Matrix* x);
//removes allocated memory
void removemem(Matrix* a);
//finds the inverse matrix
void inversion(Matrix* a);
//checks the condition for finding the sum and difference of matrices
int subsum(Matrix* x, Matrix* y);
//checks the condition for finding the multiplication
int multi(Matrix* a, Matrix* b);
//find determinant
int det(Matrix* matrix);
//displays a matrix filled with zeros if the matrix does not satisfy the condition.
Matrix error(Matrix* a);
