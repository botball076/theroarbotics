#include <kipr/wombat.h>

int main()
{
    //go foward, turn left if it sees red//
  
    int left_motor = 1;
    int right_motor = 0;
    int analog_sensor = 5;
    int servo = 3;
    
    //Blue cup & follow the black line mission
    
    enable_servo(servo);
    
     //lift the servo
    set_servo_position(servo,0);
    
     //forward
    motor(left_motor,100);
    motor(right_motor,100);
    msleep(1500);
    //1150
    
    //turning right
    motor (left_motor,200);
    motor (right_motor,0);
    msleep (2000);
    
    //stop
    motor(left_motor,0);
    motor(right_motor,0);
    msleep (1000);
    
    //resets right motor
    cmpc(right_motor);
        
    //line follow
    //put when distance sensor sees the white 

    while(gmpc(right_motor) < 6550)
    { 
        printf("help me get bubble wand");
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
    
    //stop
    motor (left_motor,0);
    motor (right_motor,0);
    msleep (1000);
    
    //attempt to drag blue cup and get switch
     	
    set_servo_position(servo, 0);
    
    motor (left_motor, 0);
    motor (right_motor, 0);
    msleep (200);
    
    set_servo_position(servo, 900);
    
    //stop
    motor (left_motor, 0);
    motor (right_motor, 0);
    msleep (200);
    	
    //turns to go get ping pongs
    
    //turn right
    motor (left_motor, 0);
    motor (right_motor, 100);
    msleep (3600);
    
    //forward
    motor (left_motor, 100);
    motor (right_motor, 100);
    msleep (1500);
    
    //turn left
    motor (left_motor, 100);
    motor (right_motor, 0);
    msleep (800);
    
    cmpc (right_motor);
    
    //goes back towards the black line
        while(gmpc(right_motor) < 3000)
    { 
        printf("%d",gmpc(right_motor));
        //tophat senses black line
       if (analog(analog_sensor) > 1500)
       {
           //turn right
           
           motor (left_motor,100);
           motor (right_motor,0);
       }
        //tophat senses white
        else 
        {
            //turn left
            motor (left_motor,0);
            motor (right_motor,100);
        }
    }
    
    set_servo_position(servo,0);
    
    motor (left_motor, 100);
    motor (right_motor, 87);
    msleep (3000);
    
    //backwards
    motor (left_motor, -100);
    motor (right_motor, -90);
    msleep (400);
    
    //servo up
    set_servo_position(servo,900);
    
    //stop
    motor (left_motor, 0);
    motor (right_motor, 0);
    msleep (300);
    
    //motor reset
    cmpc (right_motor);
    
    //linefollowing after 1 sec of passing the cross
    
    while(gmpc(right_motor) < 7100)
    { 
        printf("%d",gmpc(right_motor));
        //tophat senses black line
       if (analog(analog_sensor) > 1500)
       {
           //turn right
           
           motor (left_motor,100);
           motor (right_motor,0);
       }
        //tophat senses white
        else 
        {
            //turn left
            motor (left_motor,0);
            motor (right_motor,100);
        }
    }
    
    set_servo_position(servo,0);
    
    motor (left_motor, 100);
    motor (right_motor, 100);
    msleep (1200);
    
    //make a u turn to put poms in analyis lab
    
    //backwards
    motor (left_motor, -100);
    motor (right_motor, -100);
    msleep (1000);
    
    //stop
    motor (left_motor, 0);
    motor (right_motor, 0);
    msleep (400);
    
    //turn
    motor (left_motor, 0);
    motor (right_motor, 100);
    msleep (3000);
    
    //straight
    motor (left_motor, 100);
    motor (right_motor, 100);
    msleep (700);
    
    //backwards
    motor (left_motor,-100);
    motor (right_motor, -100);
    msleep (400);
    
    //U-turn
    motor (left_motor,-100);
    motor (right_motor, 0);
    msleep (1000);
    
    //stop
    motor (left_motor,0);
    motor(right_motor,0);
    msleep (1000);
    
    
          
    return 0;
  }