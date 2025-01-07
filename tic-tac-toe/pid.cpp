// Write a PID controller for speed u as a input and time and setpoint as well as error which we have in the system:
#include <iostream>
using namespace std;

float pid_controller(float speed,float time,float error, float setpoint,float kp,float ki,float kd){
    // u=kp*error+ki*integral_term*error+kd*differentiate_term*error
    float integral_term=
}

int main(){
    float speed=0;
    float time=0;
    float error=0;
    float setpoint=0;
    float kp=0;
    float ki=0;
    float kd=0;


}

