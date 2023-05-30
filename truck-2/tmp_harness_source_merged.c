
int christian_distance;
int gustav_distance;
int r_cab_position;

typedef struct Human {
    int distance_driven;
} *HumanPtr;

typedef struct Truck {
    int x;
    struct Human* driver;
} *TruckPtr;

/*@contract@*/
void tick(TruckPtr t) {
    t->x++;
    t->driver->distance_driven++;
}


int main2(void) {
    TruckPtr r_cab = malloc(sizeof(*r_cab));
    HumanPtr christian = malloc(sizeof(*christian));
    HumanPtr gustav = malloc(sizeof(*gustav));
    r_cab->x = 0;
    christian->distance_driven = 0;
    gustav->distance_driven = 0;
    
    r_cab->driver = christian;
    tick(r_cab);
    tick(r_cab);

    r_cab->driver = gustav;
    tick(r_cab);
    tick(r_cab);
    tick(r_cab);

    christian_distance = christian->distance_driven;
    gustav_distance = gustav->distance_driven;
    r_cab_position = r_cab->x;
}
extern int non_det_int();

void main()
{
  //Non-det assignment of global variables
  christian_distance = non_det_int();
  gustav_distance = non_det_int();
  r_cab_position = non_det_int();




  //The requires-clauses translated into assumes
  assume(1);


  //Function call that the harness function verifies
  int main_result = main2();

  //The ensures-clauses translated into asserts
  assert(((christian_distance == 2) && (gustav_distance == 3)));
  assert((r_cab_position == (christian_distance + gustav_distance)));
}
