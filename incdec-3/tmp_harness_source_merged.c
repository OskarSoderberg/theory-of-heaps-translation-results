
int a_init;
int b_init;

/*@contract@*/
void increment(int* val) {
    (*val)++;
}

/*@contract@*/
void decrement(int* val) {
    increment(val);
    *val = *val - 2;
}

int *a;


int main2(void) {
  a = (int*) malloc(sizeof(*a));
  
  *a = a_init;

  increment(a);
  decrement(a);

}
extern int non_det_int();
extern int* non_det_int_ptr();

void main()
{
  //Non-det assignment of global variables
  a_init = non_det_int();
  b_init = non_det_int();
  a = non_det_int_ptr();




  //The requires-clauses translated into assumes
  assume(1);


  //Function call that the harness function verifies
  int main_result = main2();

  //The ensures-clauses translated into asserts
  assert((*a == a_init));
}
