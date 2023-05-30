#include<stdlib.h>

int r1;
int n_init;
int* n;

/*@
  requires p == n && n_init >= 1;
  ensures ((\result == 0 && 0 >= \old(*p)) || \result >= 0) && r1 == \old(r1) && n_init == \old(n_init) && \old(n) == n;
*/
int get(int* p) {
    if (*p <= 0) {
        return 0;
    } else {
        *p = *p - 1;
        return 1 + get(p);
    }
}

/*@
  requires n_init > 0;
  ensures r1 >= n_init && r1 <= n_init;
  assigns r1, n, *n;
*/
int main(void) {
    n = (int*) malloc(sizeof(*n));
    //@ admit \valid(n);

    *n = n_init;

    r1 = get(n);
}
