#include <kipr/wombat.h>

int main()
{
    //go foward, turn left if it sees red//
  
    int left_motor = 1;
    int right_motor = 0;
    int analog_sensor = 5;
    int servo = 0;
    
    //ping pong mission/
    
 	//when robot is on white
    
    enable_servo(servo);
    
     //forward
    motor(left_motor,100);
    motor(right_motor,100);
    msleep(1150);
    
    //turning right
    motor (left_motor,200);
    motor (right_motor,0);
    msleep (1600);
    
    //stop
    motor (left_motor,0);
    motor (right_motor,0);
    msleep (1000);
    
    cmpc(right_motor);
        
    //line follow
    //put when distance sensor sees the white 

    while(gmpc(right_motor) < 6000)
    { 
        printf("hfjdklbiqhrg");
        //tophat senses black line
       if (analog(analog_sensor) > 1500)
       {
           //turn right
           motor (left_motor,0);
           motor (right_motor,100);
       }
        //tophat senses white
        else 
        {
            //turn left
            motor (left_motor,100);
            motor (right_motor,0);
        }
   	 }
    	//attempt to drag blue cup
    	
    	set_servo_position(0,
  		return 0;
  }
