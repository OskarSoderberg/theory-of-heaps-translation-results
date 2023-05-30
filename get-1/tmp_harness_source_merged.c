
int r1;
int n_init;


/*@contract@*/
int get(int* p) {
    if (*p <= 0) {
        return 0;
    } else {
        *p = *p - 1;
        return 1 + get(p);
    }
}

int* n;

int main2(void) {
    n = (int*) malloc(sizeof(*n));

    *n = n_init;

    r1 = get(n);
}
extern int non_det_int();
extern int* non_det_int_ptr();

void main()
{
  //Non-det assignment of global variables
  r1 = non_det_int();
  n_init = non_det_int();
  n = non_det_int_ptr();




  //The requires-clauses translated into assumes
  assume((n_init > 0));


  //Function call that the harness function verifies
  int main_result = main2();

  //The ensures-clauses translated into asserts
  assert(((r1 >= n_init) && (r1 <= n_init)));
}
