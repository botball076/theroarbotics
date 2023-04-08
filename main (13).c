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

//MAINNNNNNNNNNNN
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
    servo(arm,197,1000);
    servo(claw,1110,1000);

    //drive a bit

 //  while((get_create_lfcliff_amt()>2000) && (get_create_rfcliff_amt()>2000))
  // {
    //   move(100,100,0);
  // }
    
    move(100,100,4500);
    printf("Alnb");
    //turn right
    turn(-85);
   

    //drive forward until line
    while( (get_create_lfcliff_amt()>2000) && (get_create_rfcliff_amt()>2000) )
    { 

        move(300,300,0);


    }

    //if one of the sensors are on white, square up

    while( (get_create_lfcliff_amt() > threshold) || (get_create_rfcliff_amt() > threshold) )
    {
        //Go forwards if both sensors touch white
        if( (get_create_lfcliff_amt() > threshold) || (get_create_rfcliff_amt() > threshold) )

        {

            move(300,300,0);
        }
        //Turn right if left sensor touches white
        if( get_create_lfcliff_amt() > threshold)

        {
            move(100,-100,0);
        }
        //Turn left if right sensor touches right
        if (get_create_rfcliff_amt() > threshold)

        {
            move(-100,100,0);
        }

    }


    //drive a bit
    move(100,100,800);

    //turn left
    tl();

    //drive forward till bump    
    while(get_create_lbump()== 0 && get_create_rbump()==0)
    {
        move(300,300,0);

    }
    

    //go backwards
    move(-100,-100,1000);
    //turn a bit
    
   // move(100,60,1000);
    move(100,100,500);
    turn(-27);//20-25
    move(100,100,500);
	move(0,0,0);
//get botgall //turn more //claww higher
    servo(arm,1647,1000);
   	servo(claw,1951,1000);
	servo(arm,616,1000);
    
    //Drop botgal
    turn(-90);
    move(0,0,0);
   servo(arm,1699,1000);
   servo(claw,1024,1000);
   slowservo(arm,353,3);
    servo(claw,1838,1000);
    //Get cube // turn more
    turn(-190);
   move(200,200,1000);
    servo(claw,1225,1000);
    turn(-115);
    move(100,100,550);
    move(0,0,0);
    servo(claw,983,1000);
    servo(arm,1419,1000);
    servo(claw,2047,1000);
    slowservo(arm,333,5);
    turn(180);
    move(300,300,1000);
    servo(arm,1519,1000);
    servo(claw,1167,1000);
    
    
    
    
    create_disconnect();





    return 0;
}
