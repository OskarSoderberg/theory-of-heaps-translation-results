#include<stdlib.h>

int a_init;
int b_init;
int *a;
/*@
  requires val == a;
  ensures \old(val) == a && a_init == \old(a_init) && b_init == \old(b_init) && *val == 1 + \old(*val);
  assigns *val;
*/
void increment(int* val) {
    (*val)++;
}

/*@
  requires val == a && \valid(val);
  ensures a_init == \old(a_init) && b_init == \old(b_init);
  assigns *val;
*/
void decrement(int* val) {
    increment(val);
    *val = *val - 2;
}

/*@
  requires \true;
  ensures *a == a_init;
  assigns *a, a;
*/
int main(void) {
  a = (int*) malloc(sizeof(*a));
  //@ admit \valid(a);
  *a = a_init;

  increment(a);
  decrement(a);

}
