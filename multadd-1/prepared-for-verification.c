#include<stdlib.h>

int* a;
int* b;
int* result;
int a_init;
int b_init;

/*@
  requires num == a && \separated(num, b) && \separated(num, result) && \separated(b, result) && \valid(num) && \valid(b) && \valid(result);
  ensures \old(num) == a && \old(num) == \old(a) && b == \old(b) && result == \old(result) && a_init == \old(a_init) && b_init == \old(b_init) && \separated(num, b) && \separated(num, result) && \separated(b, result) && \valid(num) && \valid(b) && \valid(result) && *num == 2*\old(*num);
  assigns *num;
*/
void multiplyByTwo(int* num) {
    *num = *num * 2;
}

/*@
  requires a == a && b == b && result == result;
  ensures \old(a) == a && \old(b) == b && \old(result) == result && \old(a) == \old(a) && \old(b) == \old(b) && \old(result) == \old(result) && a_init == \old(a_init) && b_init == \old(b_init) && *result == \old(*a) + \old(*b);
  assigns *result;
*/
void addTwoNumbers(int* a, int* b, int* result) {
    *result = *a + *b;
}



/*@
  requires \true;
  ensures *a == a_init * 2;
  ensures *result == *a + b_init;
  assigns a, *a, b, *b, result, *result;
*/
int main(void) {
    a = (int*) malloc(sizeof(*a));
    b = (int*) malloc(sizeof(*b));
    result = (int*) malloc(sizeof(*result));
    //@ admit \valid(a) && \valid(b) && \valid(result);
    //@ admit \separated(a,b,result);
    
    *a = a_init;
    *b = b_init;

    multiplyByTwo(a);
    addTwoNumbers(a, b, result);
}

