
/*@contract@*/
void addNumbers(int* x, int* y, int* result) {
    *result = *x + *y;
}

/*@contract@*/
void multiplyNumbers(int* x, int* y, int* result) {
    *result = *x * *y;
}

int* a;
int* b;
int* c;
int* result1;
int* result2;
int a_init;
int b_init;
int c_init;


int main2(void) {
    a = (int*) malloc(sizeof(*a));
    b = (int*) malloc(sizeof(*b));
    c = (int*) malloc(sizeof(*c));
    result1 = (int*) malloc(sizeof(*result1));
    result2 = (int*) malloc(sizeof(*result2));
    *a = a_init;
    *b = b_init;
    *c = c_init;

    addNumbers(a, b, result1);
    multiplyNumbers(a, b, result2);
    addNumbers(b, c, c); 

}

extern int non_det_int();
extern int* non_det_int_ptr();

void main()
{
  //Non-det assignment of global variables
  a = non_det_int_ptr();
  b = non_det_int_ptr();
  c = non_det_int_ptr();
  result1 = non_det_int_ptr();
  result2 = non_det_int_ptr();
  a_init = non_det_int();
  b_init = non_det_int();
  c_init = non_det_int();






  //Function call that the harness function verifies
  int main_result = main2();

  //The ensures-clauses translated into asserts
  assert((*result1 == (a_init + b_init)));
  assert((*result2 == (a_init * b_init)));
  assert((*c == (b_init + c_init)));
}