/*
 * movement.c
 *
 *  Created on: Sep 3, 2020
 *      Author: cspainho
 */
#include "open_interface.h"

double forward(int dist, oi_t *sensor_data){
     double sum = 0;
     if(dist < 0){
         oi_setWheels(-250, -250);
         while (sum > dist*10) {
                oi_update(sensor_data);
                lcd_init();
                lcd_printf("%d, %d", sensor_data->bumpLeft, sensor_data->bumpRight);
                sum += sensor_data->distance;
             }
     }
     else if(dist > 0){
         oi_setWheels(500, 500);
         while (sum < dist*10 && !(sensor_data->bumpLeft || sensor_data->bumpRight)) {
                oi_update(sensor_data);
                lcd_init();
                lcd_printf("%d, %d", sensor_data->bumpLeft, sensor_data->bumpRight);
                sum += sensor_data->distance;
             }
     }
     oi_setWheels(0, 0); // stop
     return sum;
}

void turn(int angle, oi_t *sensor_data){
    double sum = 0;
    if(angle > 0){
        oi_setWheels(100, -100); // move forward; full speed
    }else{
        oi_setWheels(-100, 100); //move backwards; full speed
    }
    while (abs((int) sum) < abs(angle)) {
       oi_update(sensor_data);
       sum += sensor_data->angle;
     }
     oi_setWheels(0, 0); // stop
}

/*void distance(int dist, oi_t *sensor_data){
     double sum = 0;
     oi_setWheels(500, 500); // move forward; full speed
     while (sum < dist*10) {
         oi_update(sensor_data);
         sum += sensor_data->distance;
     }

     if(dist < 0){
        oi_setWheels(-250, -250);
     }
}*/

/*void turn(int angle, oi_t *sensor_data){
    double sum = 0;
    oi_setWheels(100, -100); // move forward; full speed
    while (sum < angle) {
       oi_update(sensor_data);
       sum += sensor_data->angle;
     }
     oi_setWheels(0, 0); // stop
}*/

void moveWithOb(int dist, oi_t *sensor_data){
    double sum = 0;
    while(sum < dist*10){
        sum += forward(dist-(sum/10), sensor_data);
        if (sensor_data->bumpLeft) {
            oi_setWheels(0, 0);
            sum += forward(-15, sensor_data);
            turn(90, sensor_data);
            forward(25, sensor_data);
            turn(-90, sensor_data);
           }

        if (sensor_data->bumpRight) {
              oi_setWheels(0, 0);
              sum += forward(-15, sensor_data);
              turn(-90, sensor_data);
              forward(25, sensor_data);
              turn(90, sensor_data);
           }
    }
}
