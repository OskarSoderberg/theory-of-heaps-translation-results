
/*@
  requires c == result1 && result == result1;
  ensures \old(c) == c && a == \old(a) && b == \old(b) && result2 == \old(result2) && a_init == \old(a_init) && b_init == \old(b_init) && c_init == \old(c_init) && \old(c) == result1 && *c == \old(*x) + \old(*y);
*/
void addNumbers(int* x, int* y, int* result) {
    *result = *x + *y;
}

/*@
  requires x == a && y == b && c == result1 && result == result2 && \separated(x, y) && \separated(x, c) && \separated(x, result) && \separated(y, c) && \separated(y, result) && \separated(c, result) && \valid(x) && \valid(y) && \valid(c) && \valid(result);
  ensures \old(c) == \old(result1) && \old(x) == a && \old(y) == b && \old(c) == c && \old(result) == result2 && \old(x) == \old(a) && \old(y) == \old(b) && \old(result) == \old(result2) && a_init == \old(a_init) && b_init == \old(b_init) && c_init == \old(c_init) && \old(c) == result1 && \separated(x, y) && \separated(x, c) && \separated(x, result) && \separated(y, c) && \separated(y, result) && \separated(c, result) && \valid(x) && \valid(y) && \valid(c) && \valid(result) && *result == \old(*x) * \old(*y);
*/
void multiplyNumbers(int* x, int* y, int* result) {
    *result = *x * *y;
}

int* a;
int* b;
int* c;
int* result1;
int* result2;
int a_init;
int b_init;
int c_init;

/*@
  ensures *result1 == a_init + b_init + b_init;
  ensures *result2 == a_init * b_init;
  ensures *c == *result1;
  assigns a, *a, b, *b, c, *c, result1, *result1, *result2;
*/
int main(void) {
    a = (int*) malloc(sizeof(*a));
    b = (int*) malloc(sizeof(*b));
    result1 = (int*) malloc(sizeof(*result1));
    c = result1;
    result2 = (int*) malloc(sizeof(*result2));
    *a = a_init;
    *b = b_init;

    addNumbers(a, b, result1);
    multiplyNumbers(a, b, result2);
    addNumbers(b, c, c);

}

