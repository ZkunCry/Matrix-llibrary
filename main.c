#include "..\StaticLib\matrix.h"
const double eps = 1e-9;
//
void outerror(int typeError, const char* errStr)
{
    switch (typeError)
    {
    case MATRIX_ERROR_INPUT:
        printf("Ошибка в функции заполнения матрицы!\nName Function:\ninput\n");
        break;
    case MARTIX_ERROR_PRINT:
        printf("Ошибка в функции вывода матрицы!\nName Function:\noutput\n");
        break;
    case MATRIX_ERROR_MEM:
        printf("Произошла ошибки при выделении памяти для матрицы!\nName Function:\ngetmemory\n");
        break;
    case MATRIX_ERROR_DELETE:
        printf("Произошла ошибка при очистке данных матрицы!\nName Function:\nremovemem\n");
        break;
    case MATRIX_ERROR_SUM:
        printf("Произошла ошибки при выполнении функции суммирования матриц!\nName Function:\nsummamatrix\n");
        break;
    case MATRIX_ERROR_INV:
        printf("Произошла ошибка при выполнении функции обратной матрицы!\nName Function:\ninversion\n");
        break;
    case  MATRIX_ERROR_SUB:
        printf("Произошла ошибка при выполнении функции разности!\nName Function:\nsubtraction\n");
        break;
    case  MATRIX_ERROR_MUL:
        printf("Произошла ошибка при выполнении функции умножения матриц!\nName Function:\nmultiplication\n");
        break;
    case MATRIX_ERROR_GAUS:
        printf("Произошла ошибка при выполнении функции нахождения матрицы методом гаусса!\nName Function:\ngauss\n");
        break;
    case MATRIX_ERROR_MULN:
        printf("Проиозшла ошибка при выполнении функции умножения матрицы на число!\nName Function:\nmulnum\n");
        break;
    }
    printf("Type error: %s\n\n", errStr);
}//
void saveFile(Matrix* a,char *filename)
{
    FILE* file = fopen(filename, "wt");
    if (!file || !a)
    {
        fprintf(stderr, "Ошибка! Не удалось открыть файл!\n");
        return;
    }
    int i = 0, j = 0;
    fprintf(file, "%d %d\n\n", a->n, a->m);
    for (i=0; i < a->n; i++)
    {
        for (j=0; j < a->m; j++)
        {
            fprintf(file,"%lg ", a->arr[i][j]);
        }
        fprintf(file, "\n");
    }
    printf("Матрицы была успешно сохранена!\n");
    fclose(file);
}
void loadFile(Matrix* a,char *filename)
{
    FILE* file = fopen(filename, "rt");
    if (!file|| !a)
    {
        fprintf(stderr, "Ошибка! Не удалось загрузить данные из файла!\n");
        return;
    }
    int i = 0, j = 0,n;
    if (fscanf(file, "%d %d\n\n", &a->n, &a->m) == 2 && a->n > 0 && a->m > 0)
    {
        getmemory(a, a->n, a->m);
            for (i = 0; i < a->n; i++)
            {
                for (j = 0; j < a->m; j++)
                    if (fscanf(file, "%lg ", &a->arr[i][j]) == 1)
                        continue;
            }
    }
    fclose(file);
}
void removemem(Matrix* a)
{
    int i = 0, j = 0;
    if (a->n < 1 || a->m < 1)
    {
        outerror(MATRIX_ERROR_DELETE,"Очистка памяти невозможна, посколькуо матрица не создана!");
        return;
    }
    for (i = 0; i < a->n; i++)
        free(a->arr[i]);
      free(a->arr);
}
void input(Matrix* type)
{
    if (type->n < 2 || type->m < 2)
    {
        outerror(MATRIX_ERROR_INPUT,"Размерность матрицы меньше двух");
        return;
    }
    int i = 0, j = 0;
    for (i = 0; i < type->n; i++)
    {
        for (j = 0; j < type->m; j++)
            scanf("%lf", &type->arr[i][j]);
    }
}
void getmemory(Matrix* matrix, int N, int M)
{
    if (N <= 0 || M <= 0)
    {
        outerror(MATRIX_ERROR_MEM, "При выделении памяти произошла ошибка! Размерность матрицы меньше или равна нулю!");
        return;
    }
    int i = 0, j = 0;
    matrix->n = N;
    matrix->m = M;
    matrix->arr = ((double**)calloc(N, sizeof(double*)));
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            matrix->arr[i] = (double*)calloc(M, sizeof(double));
        }
    }
}

void output(Matrix* x)
{
    if (x->n <= 0 || x->m <= 0) {
        outerror(MARTIX_ERROR_PRINT, "Произошла ошибка при выводе матрицы на экран!Элементы матрицы меньше или равны нулю!");
        return;
    }
    int i = 0, j = 0;
    for (i = 0; i < x->n; i++)
    {
        printf("| ");
        for (j = 0; j < x->m; j++)
        {
            printf("%11.5lf ", x->arr[i][j]);
        }
        printf("  |\n");
    }
    printf("\n\n");
}

Matrix summatrix(Matrix* x, Matrix* y)
{
    int i = 0, j = 0;
    Matrix temp;
    getmemory(&temp, x->n, x->m);
    if (subsum(x, y))
    {
        for (i = 0; i < x->n; i++)
        {
            for (j = 0; j < x->m; j++)
            {
                temp.arr[i][j] = x->arr[i][j] + y->arr[i][j];
            }
        }
        return temp;
    }
    else
    {
        outerror(MATRIX_ERROR_SUM, "Размерность матриц разная!");
        return;
    }
        
}

Matrix multiplication(Matrix* x, Matrix* y)
{
    int i = 0, j = 0, k = 0;
    Matrix c;
    getmemory(&c, x->n, y->m);
    if (multi(x, y))
    {
        for (i = 0; i < x->n; i++)
        {
            for (j = 0; j < y->m; j++)
            {
                for (k = 0; k < x->m; k++)
                {
                    c.arr[i][j] += (x->arr[i][k] * y->arr[k][j]);
                }
            }
        }
        return c;
    }
    else
    {
        outerror(MATRIX_ERROR_MUL, "Ошибка!Матрица(ы) не удовлетворяет(ют) правилу умножения!");
        return;
    }
}
Matrix subtraction(Matrix* x, Matrix* y)
{
    int i = 0, j = 0;
    Matrix temp;
    getmemory(&temp, x->n, x->m);
    if (subsum(x, y))
    {
        for (i = 0; i < x->n; i++)
        {
            for (j = 0; j < x->m; j++)
            {
                temp.arr[i][j] = x->arr[i][j] - y->arr[i][j];
            }
        }
        return temp;
    }
    else
    {
        outerror(MATRIX_ERROR_SUB, "Количество строк и столбцов матриц не равны!");
        return;
    } 
}
void equating(Matrix* a, Matrix* b)
{
    int i, j;
    for (i = 0; i < b->n; i++)
        for (j = 0; j < b->m; j++)
            a->arr[i][j] = b->arr[i][j];
}
double det(Matrix* matrix)
{
    if (matrix->n == matrix->m)
    {
        int i, j;
        Matrix temp;
        getmemory(&temp, matrix->n, matrix->m);
        equating(&temp, matrix);
        double determinant = 1;
        gauss(&temp);
        for (int i = 0; i < matrix->n; i++)
        {
            determinant *= temp.arr[i][i];
        }
        return determinant * temp.countSwaps;
    }
    else
        return -1;
}

void inversion(Matrix* a)
{
    int i = 0, j = 0, k = 0;
    if (a->n == a->m)
    {
        double temp;
        double** E = (double**)calloc(a->n , sizeof(double*)); 
        for (i = 0; i < a->n; i++)
            E[i] = (double*)calloc(a->m , sizeof(double));

        for (i = 0; i < a->n; i++)
            for (j = 0; j < a->n; j++)
            {
                E[i][j] = 0.0;

                if (i == j)
                    E[i][j] = 1.0;
            }

        for (k = 0; k < a->n; k++)
        {
            temp = a->arr[k][k];

            for (j = 0; j < a->n; j++)
            {
                a->arr[k][j] /= temp;
                E[k][j] /= temp;
            }

            for (i = k + 1; i < a->n; i++)
            {
                temp = a->arr[i][k];

                for (j = 0; j < a->n; j++)
                {
                    a->arr[i][j] -= a->arr[k][j] * temp;
                    E[i][j] -= E[k][j] * temp;
                }
            }
        }

        for (k = a->n - 1; k > 0; k--)
        {
            for (i = k - 1; i >= 0; i--)
            {
                temp = a->arr[i][k];

                for (j = 0; j < a->n; j++)
                {
                    a->arr[i][j] -= a->arr[k][j] * temp;
                    E[i][j] -= E[k][j] * temp;
                }
            }
        }

        for (i = 0; i < a->n; i++)
            for (j = 0; j < a->n; j++)
                a->arr[i][j] = E[i][j];

        for (i = 0; i < a->n; i++)
            free(E[i]);

        free(E);
    }
    else
    {
        outerror(MATRIX_ERROR_INV, "Количество строк и столбцов матрицы не равны!");
        return;
    }  
}

Matrix transp(Matrix* a)
{
    if (a->n <= 0 || a->n == 1 || a->m == 0 || a->m == 1)
    {
        outerror(MATRIX_ERROR_TRANSP, "Ошибка при транспонировании матрицы!");
        return;
    }
    Matrix temp;
    int i = 0, j = 0;
    getmemory(&temp, a->m, a->n);
    for (i = 0; i < a->n; i++)
    {
        for (j = 0; j < a->m; j++)
            temp.arr[j][i] = a->arr[i][j];
    }
    return temp;
}

void mulnum(Matrix* a, double k)
{
    if (a->n > 1 && a->m > 1)
    {
        int i = 0, j = 0;
        for (i = 0; i < a->n; ++i)
            for (j = 0; j < a->m; ++j)
                a->arr[i][j] = a->arr[i][j] * k;
    }
    else
    {
        outerror(MATRIX_ERROR_MULN,"Размерность матрицы меньше двух!");
        return;
    }
}
Matrix gauss(Matrix* a)
{
    int i = 0, j = 0, k;
    if (a->n != a->m)
    {
        outerror(MATRIX_ERROR_GAUS, "Матрица не является квадратной!");
        return;
    }
    double temp = 0;
    double countSwaps = 1;
    Matrix c = *a;
    for (i = 0; i < a->n; ++i)
    {
       
        int iMax = i;
        for (j = i + 1; j < a->n; ++j)
            if (fabs(c.arr[j][i]) > fabs(c.arr[iMax][i]))
                iMax = j;
        if (fabs(c.arr[iMax][i]) < eps)
            continue;
        for (k = 0; k < a->m; ++k)
        {
            temp = c.arr[i][k];
            c.arr[i][k] = c.arr[iMax][k];
            c.arr[iMax][k] = temp;
        }
        a->countSwaps = -1 * countSwaps * (i != iMax ? 1 : -1); 
        for (j = i + 1; j < a->n; ++j)
        {
            double q = -c.arr[j][i] / c.arr[i][i];
            for (k = a->m - 1; k >= i; --k)
                c.arr[j][k] += q * c.arr[i][k];
        }
    }
    return c;
}
int multi(Matrix* a, Matrix* b)
{
    return (a->n == b->m && a->m == b->n ||
        a->n == b->n && a->m == b->m);
}
int subsum(Matrix* x, Matrix* y)
{
    return (x->n == y->n && x->m == y->m);
}
Matrix division(Matrix* a, Matrix* b)
{
    Matrix c;
    getmemory(&c,a->n,a->m);
    inversion(b);
    c = multiplication(a, b);
    return c;
}
//