/********Matrix-library********\
						//??????????? ??????????//
??????????? ?????????? ?????????? ????? ???????:
??? ?????? ???????????? ????? ??????? ? github ??????????(.lib ????, .h ?????????) ? ???????? ? ????? ?????? ???????.
????? ?????????? ??????? .lib ???? ????????, ?????????? ? ???????/?????? ????? ?????????, ? ??????? ????????? ????????????? #pragma
#pragma comment(lib, "StaticLib.lib")
????? ?????????? ???????????? ???? "matrix.h"(????? ?????? ???????, ??? ??? ?? ????? ????????)
?????? ?? github : https://github.com/ZkunCry/Matrix-llibrary
//////////////////
							
??? ???????, ??????? ?????????? ?????????? ? ????????(????? ?????????) ????????? ????????? ?? ???????.
??????? ??? ???????? ???????? ??????? ? ???????, ????? ????????? ??????? ????? ????????? ?????????(&), ?? ????
???????? ????? ??????? ? ??????.
?????, ????? ?????????????? ?????? ??????? ??????? ???????????? ? ?????????? ??? ?????????, ????? ??? ?????????????
?????? ???????  ?? ?????????? ??????.
/////
					////////??????? ??? ?????? ? ????????(?????????)///////
Matrix division(Matrix* a, Matrix* b);
??????? ??????? ??????. ?? ???? ???????? ??? ???????-??????? ? ? ??????? ?, ?? ??????? ???? ????????.
?????????? ? ???????? ?????????? ????? ???????.


Matrix summatrix(Matrix* x, Matrix* y);
??????? ???????? ??????. ?? ???? ???????? ????? ??? ???????, ??????? ????? ???????.
? ???????? ?????????? ?????????? ???????, ??????? ?????????? ? ?????????? ????????.

Matrix subtraction(Matrix* x, Matrix* y);
??????? ?????????? ???????? ??????. ?? ???? ???????? ????? ??? ???????, ? ??????? ????? ????? ????????.
? ???????? ?????????? ?????????? ????? ???????.

Matrix multiplication(Matrix* x, Matrix* y);
??????? ????????? ??????. ?? ???? ???????? ??????? ???????? N x M ? M x N(?? ???????? ??????? ????????? ??????).
? ???????? ?????????? ?????????? ??????? N x M.
            
void transp(Matrix* a);
??????? ???????????????? ???????. ?? ???? ???????? ??????? ???????????? N x M.
? ???????? ?????????? ???????? ???????? ???????.

void mulnum(Matrix* a, double k);
??????? ????????? ??????? ?? ?????. ?? ???? ???????? ??????? ????? ??????????? ? ?????.
?????? ??????? ?????? ?? ??????????, ? ???????? ???????, ??????? ???????????? ??????? ? ???????.

Matrix gauss(Matrix* a);
??????? ?????????? ??????????? ??????? ?? ?????? ??????. ?? ???? ???????? ?????????? ???????.
? ???????? ?????????? ?????????? ????? ???????.

void input(Matrix* x);
??????? ????? ??????? ? ??????????.

void getmemory(Matrix* x, int N, int M);
??????? ????????????? ???????,?.? "??????" ?????? ??? ???????. ?? ???? ???????? ??????? ? ??????????? ??.

void output(Matrix* x);
??????? ?????? ??????? ?? ?????.

void removemem(Matrix* a);
??????? ??????? ???????.? ?????? ?????? ???????????? ??????? ?????????? ?????? ?????????? ???????, ?? ????????? ?????? ??????.

void inversion(Matrix* a);
??????? ?????????? ???????? ???????. ????????? ? ???????? ????????? ?????????? ??????? ? ? ???????? ?????????? ????? ???????
???????????? ? ????????.

////??????????? ??? ???????
int subsum(Matrix* x, Matrix* y);
? ?????? ?????? ??????????? ??????????,????????? ?? ??????? ????????,????????? ? ????????? ??????.
???? ??????? ???????????? ??????????????? ???????, ?? ??????? ?????????? 0(????), ? ?????? ?????? 1(??????).
int multi(Matrix* a, Matrix* b);
////
double det(Matrix* matrix);
??????? ?????????? ???????????? ???????. ?? ???? ???????? ?????? ?????????? ???????.
?????????? ? ???????? ?????????? ???????????? ???????.

void equating(Matrix* a, Matrix* b);
???????, ??????? ???????????? ???????. ?? ????, ? ??????? ? ???????????? ??? ???????? ? ??????????? ??????? ?.

void saveFile(Matrix* a,char *filename);
??????? ?????????? ??????? ? ????. ????????? ??????? ? ??? ?????.

void outerror(int typeError, const char* errStr);
??????? ????????? ??????.
???? ??? ????????????? ?????-???? ???????, ???????????? ?? ????????? ???????, ?? ?? ????? ????????? ??????, ???????? ???????,
? ??????? ????????? ?????? ? ??? ??????.

void loadFile(Matrix* a,char *filename);
??????? ???????? ??????? ?? ?????. ????? ????????? ??????? ? ??? ?????.

//
