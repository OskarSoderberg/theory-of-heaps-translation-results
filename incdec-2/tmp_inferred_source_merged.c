
int a_init;

/*@
  requires val == a && \valid(val);
  ensures \old(val) == a && a_init == \old(a_init) && \valid(val) && *val == 1 + \old(*val);
*/
void increment(int* val) {
    (*val)++;
}

/*@
  requires val == a;
  ensures \old(val) == a && a_init == \old(a_init) && \old(val) == \old(a) && *val == \old(*val) - 1;
*/
void decrement(int* val) {
    (*val)--;
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
