
int driver_distance;
int r_cab_position;

typedef struct Human {
    int distance_driven;
} Human;

typedef struct Truck {
    int x;
    struct Human driver;
} *TruckPtr;

/*@
  requires \true;
  ensures \old(driver_distance) == driver_distance && \old(r_cab_position) == r_cab_position && t->x == 1 + \old(t->x) && t->driver.distance_driven == 1 + \old(t->driver).distance_driven;
*/
void tick(TruckPtr t) {
    t->x++;
    t->driver.distance_driven++;
}

/*@
  requires \true;
  ensures driver_distance == 2;
  ensures r_cab_position == 2;
  assigns driver_distance, r_cab_position;
*/
int main(void) {
    TruckPtr r_cab = malloc(sizeof(*r_cab));
    r_cab->x = 0;
    r_cab->driver.distance_driven = 0;
    tick(r_cab);
    tick(r_cab);

    driver_distance = r_cab->driver.distance_driven;
    r_cab_position = r_cab->x;
}
