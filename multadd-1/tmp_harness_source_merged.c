

/*@contract@*/
void multiplyByTwo(int* num) {
    *num = *num * 2;
}

/*@contract@*/
void addTwoNumbers(int* a, int* b, int* result) {
    *result = *a + *b;
}

int* a;
int* b;
int* result;
int a_init;
int b_init;


int main2(void) {
    a = (int*) malloc(sizeof(*a));
    b = (int*) malloc(sizeof(*b));
    result = (int*) malloc(sizeof(*result));

    *a = a_init;
    *b = b_init;

    multiplyByTwo(a);
    addTwoNumbers(a, b, result);
}

extern int non_det_int();
extern int* non_det_int_ptr();

void main()
{
  //Non-det assignment of global variables
  a = non_det_int_ptr();
  b = non_det_int_ptr();
  result = non_det_int_ptr();
  a_init = non_det_int();
  b_init = non_det_int();




  //The requires-clauses translated into assumes
  assume(1);


  //Function call that the harness function verifies
  int main_result = main2();

  //The ensures-clauses translated into asserts
  assert((*a == (a_init * 2)));
  assert((*result == (*a + b_init)));
}
