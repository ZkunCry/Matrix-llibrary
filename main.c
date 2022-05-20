#include "..\StaticLib\matrix.h"
const double eps = 1e-9;

void outerror(int typeError, const char* errStr)
{
    switch (typeError)
    {
    case MATRIX_ERROR_INPUT:
        printf("Ошибка в функции заполнения матрицы!\n");
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

    }
    printf("Type error: %s", errStr);
}
void saveFile(Matrix* a)
{
    FILE* file = fopen("matrix.txt", "w");
    if (!file)
    {
        fprintf(stderr, "Ошибка! Не удалось открыть файл!\n");
        return;
    }
    int i = 0, j = 0;
    fprintf(file, "%d %d\n", a->line, a->column);
    for (i=0; i < a->line; i++)
    {
        for (j=0; j < a->column; j++)
        {
            fprintf(file,"%lg ", a->arr[i][j]);
        }
        fprintf(file, "\n");
    }
    printf("Матрицы была успешно сохранена!\n");
    fclose(file);
}
void removemem(Matrix* a)
{
    int i = 0, j = 0;
    if (a->line == 0 || a->column == 0)
        outerror(MATRIX_ERROR_DELETE, "Очистка памяти невозможна, посколькуо матрица не создана!\n");
    for (i = 0; i < a->line; i++)
        free(a->arr[i]);
      free(a->arr);
}
void input(Matrix* type)
{
    if (type->line <= 0 || type->column <= 0)
    {
        outerror(MATRIX_ERROR_INPUT, "Инициализация матрицы невозможна!\n");
        return;
    }
    int i = 0, j = 0;
    for (i = 0; i < type->line; i++)
    {
        for (j = 0; j < type->column; j++)
            scanf("%lf", &type->arr[i][j]);
    }
}
void getmemory(Matrix* matrix, int N, int M)
{
    if (N <= 0 || M <= 0)
    {
        outerror(MATRIX_ERROR_MEM, "При выделении памяти произошла ошибка!\nРазмерность матрицы меньше или равна нулю!\n");
        return;
    }
    int i = 0, j = 0;
    matrix->line = N;
    matrix->column = M;
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
    if (x->line <= 0 || x->column <= 0) {
        outerror(MARTIX_ERROR_PRINT, "Произошла ошибка при выводе матрицы на экран!\nЭлементы матрицы меньше или равны нулю!\n");
        return;
    }
    int i = 0, j = 0;
    for (i = 0; i < x->line; i++)
    {
        printf("| ");
        for (j = 0; j < x->column; j++)
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
    getmemory(&temp, x->line, x->column);
    if (subsum(x, y))
    {
        for (i = 0; i < x->line; i++)
        {
            for (j = 0; j < x->column; j++)
            {
                temp.arr[i][j] = x->arr[i][j] + y->arr[i][j];
            }
        }
        return temp;
    }
    else
    {
        outerror(MATRIX_ERROR_SUM, "Размерность матриц разная!\n");
        return;
    }
        
}

Matrix multiplication(Matrix* x, Matrix* y)
{
    int i = 0, j = 0, k = 0;
    Matrix c;
    getmemory(&c, x->line, y->column);
    if (multi(x, y))
    {
        for (i = 0; i < x->line; i++)
        {
            for (j = 0; j < y->column; j++)
            {
                for (k = 0; k < x->column; k++)
                {
                    c.arr[i][j] += (x->arr[i][k] * y->arr[k][j]);
                }
            }
        }
        return c;
    }
    else
    {
        outerror(MATRIX_ERROR_MUL, "Ошибка!\nМатрица(ы) не удовлетворяет(ют) правилу умножения!\n");
        return;
    }
}
Matrix subtraction(Matrix* x, Matrix* y)
{
    int i = 0, j = 0;
    Matrix temp;
    getmemory(&temp, x->line, x->column);
    if (subsum(x, y))
    {
        for (i = 0; i < x->line; i++)
        {
            for (j = 0; j < x->column; j++)
            {
                temp.arr[i][j] = x->arr[i][j] - y->arr[i][j];
            }
        }
        return temp;
    }
    else
    {
        outerror(MATRIX_ERROR_SUB, "Количество строк и столбцов матриц не равны!\n");
        return;
    } 
}
void equating(Matrix* a, Matrix* b)
{
    int i, j;
    for (i = 0; i < b->line; i++)
        for (j = 0; j < b->column; j++)
            a->arr[i][j] = b->arr[i][j];
}
int det(Matrix* matrix)
{
    if (matrix->line == matrix->column)
    {
        int i, j;
        Matrix temp;
        getmemory(&temp, matrix->line, matrix->column);
        equating(&temp, matrix);
        double determinant = 1;
        gauss(&temp);
        for (int i = 0; i < matrix->line; i++)
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
    if (a->line == a->column)
    {
        double temp;
        double** E = (double**)calloc(a->line , sizeof(double*)); 
        for (i = 0; i < a->line; i++)
            E[i] = (double*)calloc(a->column , sizeof(double));

        for (i = 0; i < a->line; i++)
            for (j = 0; j < a->line; j++)
            {
                E[i][j] = 0.0;

                if (i == j)
                    E[i][j] = 1.0;
            }

        for (k = 0; k < a->line; k++)
        {
            temp = a->arr[k][k];

            for (j = 0; j < a->line; j++)
            {
                a->arr[k][j] /= temp;
                E[k][j] /= temp;
            }

            for (i = k + 1; i < a->line; i++)
            {
                temp = a->arr[i][k];

                for (j = 0; j < a->line; j++)
                {
                    a->arr[i][j] -= a->arr[k][j] * temp;
                    E[i][j] -= E[k][j] * temp;
                }
            }
        }

        for (k = a->line - 1; k > 0; k--)
        {
            for (i = k - 1; i >= 0; i--)
            {
                temp = a->arr[i][k];

                for (j = 0; j < a->line; j++)
                {
                    a->arr[i][j] -= a->arr[k][j] * temp;
                    E[i][j] -= E[k][j] * temp;
                }
            }
        }

        for (i = 0; i < a->line; i++)
            for (j = 0; j < a->line; j++)
                a->arr[i][j] = E[i][j];

        for (i = 0; i < a->line; i++)
            free(E[i]);

        free(E);
    }
    else
    {
        outerror(MATRIX_ERROR_INV, "Количество строк и столбцов матрицы не равны!\n");
        return;
    }
       
}

Matrix transp(Matrix* a)
{
    if (a->line <= 0 || a->line == 1 || a->column == 0 || a->column == 1)
    {
        outerror(MATRIX_ERROR_TRANSP, "Ошибка при транспонировании матрицы!\n");
        return;
    }
    Matrix temp;
    int i = 0, j = 0;
    getmemory(&temp, a->column, a->line);
    for (i = 0; i < a->line; i++)
    {
        for (j = 0; j < a->column; j++)
            temp.arr[j][i] = a->arr[i][j];
    }
    return temp;
}

Matrix mulnum(Matrix* a, double k)
{
    int i = 0, j = 0;
    Matrix temp;
    getmemory(&temp, a->line, a->column);
    for (i = 0; i < a->line; ++i)
        for (j = 0; j < a->column; ++j)
            temp.arr[i][j] = a->arr[i][j] * k;
    return temp;
}
Matrix gauss(Matrix* a)
{
    int i = 0, j = 0, k;
    if (a->line != a->column)
    {
        outerror(MATRIX_ERROR_GAUS, "Матрица не является квадратной!\n");
        return;
    }
    double temp = 0;
    double countSwaps = 1;
    Matrix c = *a;
    for (i = 0; i < a->line; ++i)
    {
       
        int iMax = i;
        for (j = i + 1; j < a->line; ++j)
            if (fabs(c.arr[j][i]) > fabs(c.arr[iMax][i]))
                iMax = j;
        if (fabs(c.arr[iMax][i]) < eps)
            continue;
        for (k = 0; k < a->column; ++k)
        {
            temp = c.arr[i][k];
            c.arr[i][k] = c.arr[iMax][k];
            c.arr[iMax][k] = temp;
        }
        a->countSwaps = -1 * countSwaps * (i != iMax ? 1 : -1); 
        for (j = i + 1; j < a->line; ++j)
        {
            double q = -c.arr[j][i] / c.arr[i][i];
            for (k = a->column - 1; k >= i; --k)
                c.arr[j][k] += q * c.arr[i][k];
        }
    }
    return c;
}
int multi(Matrix* a, Matrix* b)
{
    return (a->line == b->column && a->column == b->line ||
        a->line == b->line && a->column == b->column);
}
int subsum(Matrix* x, Matrix* y)
{
    return (x->line == y->line && x->column == y->column);
}
//