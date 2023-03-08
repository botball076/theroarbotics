#include <kipr/wombat.h>

int main()
{
    //go foward, turn left if it sees red//
  
    int left_motor = 1;
    int right_motor = 0;
    int analog_sensor = 5;
    
 	//when robot is on white//
    while (analog(analog_sensor)<2000)
    {
      //turn right for red poms//
        motor (left_motor,100);
        motor (right_motor,0);
        
    if //robot isnt on white line do this//
    {
        
    }
    }
    return 0;
}
