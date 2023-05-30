#include<stdlib.h>

int a_init;
int *a;

/*@
  requires val == a && \valid(val);
  ensures \old(val) == a && a_init == \old(a_init) && \valid(val) && *val == 1 + \old(*val);
  assigns *val;
*/
void increment(int* val) {
    (*val)++;
}

/*@
  requires val == a;
  ensures \old(val) == a && a_init == \old(a_init) && \old(val) == \old(a) && *val == \old(*val) - 1;
  assigns *val;
*/
void decrement(int* val) {
    (*val)--;
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
