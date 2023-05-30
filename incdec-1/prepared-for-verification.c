#include<stdlib.h>

int a_init;
int b_init;
int *a;
int *b;

/*@
  requires val == a && \separated(val, b) && \valid(val) && \valid(b);
  ensures \old(val) == a && a_init == \old(a_init) && b_init == \old(b_init) && \old(val) == \old(a) && b == \old(b) && \separated(val, b) && \valid(val) && \valid(b) && *val == 1 + \old(*val);
  assigns *val;
*/
void increment(int* val) {
    (*val)++;
}

/*@
  requires val == b;
  ensures \old(val) == b && a_init == \old(a_init) && b_init == \old(b_init) && a == \old(a) && \old(val) == \old(b) && *val == \old(*val) - 1;
  assigns *val;
*/
void decrement(int* val) {
    (*val)--;
}


/*@
  requires \true;
  ensures *a == a_init + 1 && *b == b_init - 1;
  assigns *a, *b, a, b;
*/
int main(void) {
  a = (int*) malloc(sizeof(*a));
  b = (int*) malloc(sizeof(*b));
  //@ admit \valid(a) && \valid(b);
  //@ admit \separated(a,b);
  
  *a = a_init;
  *b = b_init;

  increment(a);
  decrement(b);

}
