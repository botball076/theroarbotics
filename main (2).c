#include <kipr/wombat.h>
//takes left, right, and msleep
void move(int l, int r, int t)
{
    create_drive_direct(l,r);
    msleep(t);
}

//takes servo position and time
void servo(int a, int a_p, int a_t)
{ 
    set_servo_position(a,a_p);
    msleep(a_t);

}

//turns left
void tl()
{
    set_create_total_angle(0);
    while(get_create_total_angle()<90)
    {
        // printf("%d\n",get_create_total_angle());
        create_drive_direct(-100,100);
    }

}

//turns right
void tr()
{
    set_create_total_angle(0);
    while(get_create_total_angle()>-90)
    {

        create_drive_direct(100,-100);
    }

}


        
int claw = 1;
int arm = 0;
int threshold = 2000;


void turn(angle)
{
    set_create_total_angle(0);

    if(get_create_total_angle() < angle)
    {
    
        while(get_create_total_angle() < angle)
        {
            create_drive_direct(-100,100);
        }


    }
    else
    {
        while(get_create_total_angle() > angle)
        {
            create_drive_direct(100,-100);
        }
    }
}

void slowservo(int port,int target_position,int time)
{
    int current_position = get_servo_position(port);
    
    while(current_position != target_position)
    {
        if(current_position > target_position)
        {
            current_position = current_position -1;
        }
        else
        {
            current_position = current_position +1;
        }
        
        set_servo_position(port,current_position);
            msleep(time);
    }
}

//MAINNNNNN
int main()
{ 
   create_connect();
    create_full();
	printf("RUN");
    
    //robot off the line:2913. robot on the line:r.
    
    wait_for_light(0);
    shut_down_in(112);
    set_create_distance(0);
    enable_servos(0);
    enable_servos(1);
    servo(arm,46,1000);
    servo(claw,830,1000);
    //move forward
    move(450,450,2300);
    //servo(claw,830,1000);
    //turn
    turn(90);
    //bumb and back up
    
    while(get_create_lbump()== 0 && get_create_rbump()==0)
    {
        move(300,300,0);

    }
    move(-100,-100,1000);
    //move(100,100,500);
    //turn a bit
    servo(claw,818,1200);
    turn(-26);//35
    //move(100,20,2000);
    //get botgal
    move(0,0,0);
    servo(arm,1628,1000);
    move(100,100,2200);
    move(0,0,0);
    servo(claw,1900,1000);//1709
    servo(arm,691,1000);
    turn(148);
    move(0,0,0);
    msleep(500);
    move(100,100,1000);
    servo(arm,2031,1000);
    servo(claw,1016,1000);
   
    
   

    return 0;
    
}
