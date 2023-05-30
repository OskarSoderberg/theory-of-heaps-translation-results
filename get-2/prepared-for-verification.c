#include<stdlib.h>

int r1;
int n_init;
int* n;

// replaced TOH-type quantification with \true
/*@
  requires p == n && (n_init >= 2 || (n_init >= 1 && *n == n_init && (n_init != 1 || n_init == 1 || \forall int v0; n_init == v0 - 1) && (n_init != 1 || n_init == 1) && (n_init != 1 || \true) && (1 >= n_init || *n == n_init || *p >= 1)) || (n_init >= 1 && *p == n_init - 1 && (n_init != 1 || n_init == 1 || \forall int v0; n_init == v0 - 1) && (n_init != 1 || n_init == 1) && (1 >= n_init || *n == n_init || *p >= 1)));
  ensures ((\result == 0 && 0 >= \old(*p)) || (\result == 1 && \old(*p) == 1) || (((\result == 5 && \old(*p) >= 3) || 2*\old(*p) - \result >= 2) && \result >= \old(*p))) && r1 == \old(r1) && n_init == \old(n_init) && \old(n) == n;
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
  ensures r1 >= n_init && r1 <= n_init * n_init;
  assigns r1, n, *n;
*/
int main(void) {
    n = (int*) malloc(sizeof(*n));
    //@ admit \valid(n);

    *n = n_init;

    r1 = get(n);
}
