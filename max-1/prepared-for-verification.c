#include<stdlib.h>

int r;
int* a;
int* b;
int a_init;
int b_init;

// added *x == a_init && *y == b_init
/*@
  requires *x == a_init && *y == b_init && x == a && y == b && \separated(x, y) && \valid(x) && \valid(y);
  ensures ((b_init == \result && \result - a_init >= 1) || (a_init == \result && a_init >= b_init)) && r == \old(r) && a_init == \old(a_init) && b_init == \old(b_init) && \old(a) == a && \old(b) == b;
  assigns \nothing;
*/
int findMax(int* x, int* y) {
    if(*x >= *y)
        return *x;
    else
        return *y;
}

/*@
  requires \true;
  ensures a_init >= b_init ==> r == a_init;
  ensures b_init > a_init ==> r == b_init;
  assigns r, a, b, *a, *b;
*/
int main(void) {
    a = (int*) malloc(sizeof(*a));
    b = (int*) malloc(sizeof(*b));
    //@ admit \valid(a) && \valid(b);
    //@ admit \separated(a,b);

    *a = a_init;
    *b = b_init;

    r = findMax(a, b);

}
