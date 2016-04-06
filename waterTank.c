#include <vxWorks.h> /* Always include this as the first thing in every program */
#include <stdio.h> /* we use printf */
#include <sysLib.h> /* we use sysClk... */
#include <taskLib.h> /* we use tasks... */
#include <tickLib.h> /* enable tickGet()... */

/* semaphore declarations */
SEM_ID semBinLevelSensor;
SEM_ID semBinPumpControl;

/* watchdog declarations */
WD_ID taskWD;

/* function definitions */
void display(void);
void tankSensors(void);
void valveControl(void);
void reset(void);
void run(void);
long getCurrentTime(void);

/* global variables */
int initialTime;
long uptime;
int tankLevel; /* 0-empty 1-half 2-full */
int pumpStatus; /* 0-off 1-on */

/* display function */
void display(void){
  while(1){
    /* read variables */
    uptime = getCurrentTime() - initialTime;

    /* update display */
    /* display includes tank level, temp status (good or bad), heater status, valve status, and uptime */

  }
}

/* get the current time in seconds */
long getCurrentTime(void){
  return (long) tickGet()/60;
}

/* check sensors */
void tankSensors(void){
  while(1){
    /* check sensors */


    /* update water level variables */


    /* update temperature variables */

  }
}

/* valve control */
void valveControl(void){
  while(1){
    /* read water level variables */

    /* set valve positions */

  }
}

/* initialize system */
void reset(void){
  /* initialize semaphores */
  /* semBinLevelSensor = semBCreate(SEM_Q_PRIORITY, SEM_FULL); /* create binary semaphore */
  /* semBinPumpControl = semBCreate(SEM_Q_PRIORITY, SEM_FULL); /* create binary semaphore */

  int initialTime = getCurrentTime();
  int uptime = 0;
  int tankLevel = 0; /* 0-empty 1-half 2-full 3-max */
  int pumpStatus = 0; /* 0-off 1-on */
}

void run(void){
  /* setup system */
  reset();

  /* create tasks */
  if((taskSpawn("display", 100, 0x0100, 2000,(FUNCPTR)display,0,0,0,0,0,0,0,0,0,0))== ERROR){
		printf("Error spawning display task.");
	}
	if((taskSpawn("sensors", 90, 0x0100, 2000,(FUNCPTR)tankSensors,0,0,0,0,0,0,0,0,0,0))== ERROR){
		printf("Error spawning sensors task.");
	}
	if((taskSpawn("control", 90, 0x0100, 2000,(FUNCPTR)valveControl,0,0,0,0,0,0,0,0,0,0))== ERROR){
		printf("Error spawning pump control task.");
	}
}
