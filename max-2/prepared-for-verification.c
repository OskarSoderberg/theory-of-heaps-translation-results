#include<stdlib.h>

int* r;
int* a;
int* b;
int a_init;
int b_init;

/*@
  requires max == r && x == a && y == b && \separated(x, y) && \separated(x, max) && \separated(y, max) && \valid(x) && \valid(y) && \valid(max);
  ensures (\old(b_init) - \old(a_init) >= 1 || \old(a_init) >= \old(b_init)) && a == \old(x) && b == \old(y) && r == \old(max) && \old(a_init) == a_init && \old(b_init) == b_init;
  assigns *max;
*/
void findMax(int* x, int* y, int* max) {
    if(*x >= *y)
        *max = *x;
    else
        *max = *y;
}


/*@
  requires \true;
  ensures a_init >= b_init ==> *r == a_init;
  ensures b_init > a_init ==> *r == b_init;
  assigns r, a, b, *r, *a, *b;
*/
int main(void) {
    a = (int*) malloc(sizeof(*a));
    b = (int*) malloc(sizeof(*b));
    r = (int*) malloc(sizeof(*r));
    //@ admit \valid(a) && \valid(b) && \valid(r);
    //@ admit \separated(a,b,r);

    *a = a_init;
    *b = b_init;

    findMax(a, b, r);

}
