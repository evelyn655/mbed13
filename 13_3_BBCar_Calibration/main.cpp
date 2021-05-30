#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin5(D5), pin6(D6);

BBCar car(pin5, pin6, servo_ticker);

int main() {
   // please contruct you own calibration table with each servo
   double pwm_table0[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   // double speed_table0[] = {-8.929, -8.849, -9.008, -8.769, -5.979, 0.080, 6.298, 9.646, 8.371, 9.567, 9.168};
   double speed_table0[] = {-8.929, -8.849, -9.008, -8.769, -5.979, 0.000, 6.298, 9.646, 8.371, 9.567, 9.168};
   double pwm_table1[] = {-150, -120, -90, -60, -30, 0, 30, 60, 90, 120, 150};
   // double speed_table1[] = {-8.211, -8.052, -9.008, -8.610, -5.899, 0.080, 6.139, 7.653, 8.610, 8.052, 7.653};
   double speed_table1[] = {-8.211, -8.052, -9.008, -8.610, -5.899, 0.000, 6.139, 7.653, 8.610, 8.052, 7.653};

   // first and fourth argument : length of table
   car.setCalibTable(11, pwm_table0, speed_table0, 11, pwm_table1, speed_table1);

   while (1) {
      car.goStraightCalib(5);
      ThisThread::sleep_for(5s);
      car.stop();
      ThisThread::sleep_for(5s);
   }
}