#include<stdlib.h>

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

/*@
  requires \valid(t) && \valid(t->driver) && \separated(t, t->driver);
  ensures t->x == \old(t->x) + 1 && t->driver->distance_driven == \old(t->driver->distance_driven) + 1;
  assigns t->x, t->driver->distance_driven;
*/
void tick(TruckPtr t) {
    t->x++;
    t->driver->distance_driven++;
}

/*@
  requires \true;
  ensures christian_distance == 2 && gustav_distance == 3;
  ensures r_cab_position == christian_distance + gustav_distance;
  assigns christian_distance, gustav_distance, r_cab_position;
*/
int main(void) {
    TruckPtr r_cab = malloc(sizeof(*r_cab));
    HumanPtr christian = malloc(sizeof(*christian));
    HumanPtr gustav = malloc(sizeof(*gustav));
    //@ admit \valid(r_cab) && \valid(christian) && \valid(gustav);
    //@ admit \separated(r_cab, christian, gustav);
    r_cab->x = 0;
    christian->distance_driven = 0;
    gustav->distance_driven = 0;

    r_cab->driver = christian;
    tick(r_cab);
    tick(r_cab);
    //@ assert christian->distance_driven == 2;
    r_cab->driver = gustav;
    tick(r_cab);
    tick(r_cab);
    tick(r_cab);
    //@ assert gustav->distance_driven == 3;

    christian_distance = christian->distance_driven;
    gustav_distance = gustav->distance_driven;
    r_cab_position = r_cab->x;
}