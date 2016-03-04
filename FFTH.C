/*
FFThunderHelper

(C)Copyright 2014 HoriKu.
All rights reserved.

*/
#include <wiringPi.h>  

int tCounter;

void loop()
{
    while (true)
    {
        int lightChecker = digitalRead(5);
        if (lightChecker == 0)
        {
            tCounter++;
            printf("ThunderPassed %d\n",tCounter);
            //change angle to pulse width
            int pulseNum = (60*11+500)/10;   //the first number is angle of motor
            system("echo 2=%d>/dev/servoblaster",pulseNum);   //execute
            dalay(100);
            system("echo 2=0>/dev/servoblaster");   //reset motor
            delay(1000);
        }
        else printf("debug\n");
    }
}

int main( )  
{
    tCounter = 0;
    // init
    wiringPiSetup();
    pinMode(5, INPUT);
    pinMode(1, OUTPUT);
    loop();
    return 0;
}  

