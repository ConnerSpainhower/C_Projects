#include "open_interface.h"
#include "movement.h"
#include "resetSimulation.h"
void main() {
//resetSimulationBoard();
//part 1
 oi_t *sensor_data = oi_alloc();
 oi_init(sensor_data);
 /*double sum = 0;
 oi_setWheels(500, 500); // move forward; full speed
 while (sum < 1000) {
 oi_update(sensor_data);
 sum += sensor_data->distance;
 }
 oi_setWheels(0, 0); // stop */
 
 
 //part 2
 
/*forward(50, sensor_data);
turn(90, sensor_data);

forward(50, sensor_data);
turn(90, sensor_data);

forward(50, sensor_data);
turn(90, sensor_data);

forward(50, sensor_data);
turn(90, sensor_data);

 oi_free(sensor_data);*/
 
 // part 3
 
moveWithOb(200, sensor_data);
oi_free(sensor_data);
}