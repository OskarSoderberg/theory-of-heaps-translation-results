
int a_init;
int b_init;

/*@
  requires val == a;
  ensures \old(val) == a && a_init == \old(a_init) && b_init == \old(b_init) && *val == 1 + \old(*val);
*/
void increment(int* val) {
    (*val)++;
}

/*@
  requires val == a && \valid(val);
  ensures a_init == \old(a_init) && b_init == \old(b_init);
*/
void decrement(int* val) {
    increment(val);
    *val = *val - 2;
}

int *a;

/*@
  requires \true;
  ensures *a == a_init;
  assigns *a, a;
*/
int main(void) {
  a = (int*) malloc(sizeof(*a));
  
  *a = a_init;

  increment(a);
  decrement(a);

}
