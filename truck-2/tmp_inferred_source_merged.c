
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

//No inferred contract found for tick
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
