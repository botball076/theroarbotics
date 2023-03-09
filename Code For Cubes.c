#include <kipr/wombat.h>
void move(int l, int r, int t)
{
    create_drive_direct(l,r);
    msleep(t);
}

void servo(int a, int a_p, int a_t)
{
    set_servo_position(a,a_p);
    msleep(a_t);
    
}
void rl()
{
    create_drive_direct(-100,100);
    
}

void tr()
{
    create_drive_direct(100,-100);
}


int main()
{ 
    
    create_connect();
    //robot off the line:. robot on the line:r.
    while (1)
    {
        printf("%d\n", get_create_lfcliff_amt());
       // printf("%d\n", get_create_rfcliff_amt());
    }
           

        /*
   //wait_for_light(0);
    //shut_down_in(112);
   // set_create_distance(0);
    //set_create_total_angle(0);
  

    
    
  //printf("%d\n", get_create_distance());
   
    
   
    while(get_create_distance()<50)
    { if (get_create_lfcliff_amt()<=50&&(get_create_rfcliff_amt()<=50))create_drive_direct(100,100);
    }
    create_disconnect();
    */
   
    return 0;
}
