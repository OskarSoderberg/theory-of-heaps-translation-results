
int a_init;
int b_init;

/*@
  requires val == a && \separated(val, b) && \valid(val) && \valid(b);
  ensures \old(val) == a && a_init == \old(a_init) && b_init == \old(b_init) && \old(val) == \old(a) && b == \old(b) && \separated(val, b) && \valid(val) && \valid(b) && *val == 1 + \old(*val);
*/
void increment(int* val) {
    (*val)++;
}

/*@
  requires val == b && \separated(a, val) && \valid(a) && \valid(val);
  ensures \old(val) == b && a_init == \old(a_init) && b_init == \old(b_init) && a == \old(a) && \old(val) == \old(b) && *val == \old(*val) - 1;
*/
void decrement(int* val) {
    (*val)--;
}

int *a;
int *b;
/*@
  requires \true;
  ensures *a == a_init + 1 && *b == b_init - 1;
  assigns *a, *b, a, b;
*/
int main(void) {
  a = (int*) malloc(sizeof(*a));
  b = (int*) malloc(sizeof(*b));
  
  *a = a_init;
  *b = b_init;

  increment(a);
  decrement(b);

}
