#include<stdlib.h>

int* a;
int* b;
int* c;
int* result1;
int* result2;
int a_init;
int b_init;
int c_init;

/*@
  requires \true;
  ensures a == \old(a) && b == \old(b) && c == \old(c) && result1 == \old(result1) && result2 == \old(result2) && a_init == \old(a_init) && b_init == \old(b_init) && c_init == \old(c_init) && *result == \old(*x) + \old(*y);
  assigns *result;
*/
void addNumbers(int* x, int* y, int* result) {
    *result = *x + *y;
}

/*@
  requires x == a && y == b && result == result2 && \separated(x, y) && \separated(x, result) && \separated(x, c) && \separated(x, result1) && \separated(y, result) && \separated(y, c) && \separated(y, result1) && \separated(result, c) && \separated(result, result1) && \separated(c, result1) && \valid(x) && \valid(y) && \valid(result) && \valid(c) && \valid(result1);
  ensures \old(x) == a && \old(y) == b && \old(result) == result2 && \old(x) == \old(a) && \old(y) == \old(b) && c == \old(c) && result1 == \old(result1) && \old(result) == \old(result2) && a_init == \old(a_init) && b_init == \old(b_init) && c_init == \old(c_init) && \separated(x, y) && \separated(x, result) && \separated(x, c) && \separated(x, result1) && \separated(y, result) && \separated(y, c) && \separated(y, result1) && \separated(result, c) && \separated(result, result1) && \separated(c, result1) && \valid(x) && \valid(y) && \valid(result) && \valid(c) && \valid(result1) && *result == \old(*x) * \old(*y);
  assigns *result;
*/
void multiplyNumbers(int* x, int* y, int* result) {
    *result = *x * *y;
}

/*@
  ensures *result1 == a_init + b_init;
  ensures *result2 == a_init * b_init;
  ensures *c == b_init + c_init;
  assigns a, *a, b, *b, c, *c, result1, *result1, *result2;
*/
int main(void) {
    a = (int*) malloc(sizeof(*a));
    b = (int*) malloc(sizeof(*b));
    c = (int*) malloc(sizeof(*c));
    result1 = (int*) malloc(sizeof(*result1));
    result2 = (int*) malloc(sizeof(*result2));
    //@ admit \valid(a) && \valid(b) && \valid(c) && \valid(result1) && \valid(result2);
    //@ admit \separated(a,b,c, result1, result2);
    *a = a_init;
    *b = b_init;
    *c = c_init;

    addNumbers(a, b, result1);
    multiplyNumbers(a, b, result2);
    addNumbers(b, c, c); 

}

