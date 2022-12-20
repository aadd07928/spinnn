/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Student                                          */
/*    Created:      Wed Nov 30 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// side                 motor         8               
// i                    motor         9               
// fly1                 motor         2               
// fly2                 motor         3               
// Optic1               optical       6               
// Optic2               optical       4               
// fl                   motor         1               
// fr                   motor         10              
// bl                   motor         11              
// br                   motor         20              
// inert                inertial      7               
// xrot                 rotation      5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

//vex::digital_out numatics = vex::digital_out(Brain.ThreeWirePort.A);

// int piston() {
//   wait(.5,sec);
//   numatics = 1;
//   wait(.2,sec);
//   numatics = 0;

//   wait(.5,sec);
//   numatics = 1;
//   wait(.2,sec);
//   numatics = 0;


//   return 0;
// 
#include "okapi.cpp"

drivebase drive();

void driveforward(int deg) {
  xrot.resetPosition();
  while (xrot.position(degrees)<deg){
    fl.spin(forward,50,pct);
    fr.spin(forward,50,pct);
    bl.spin(forward,50,pct);
    br.spin(forward,50,pct);
  }
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}

void drivebackward(int deg) {
  xrot.resetPosition();
  while (xrot.position(degrees)>-deg){
    fl.spin(reverse,50,pct);
    fr.spin(reverse,50,pct);
    bl.spin(reverse,50,pct);
    br.spin(reverse,50,pct);
  }
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}
void tl(int deg) {
  
  while (inert.rotation(degrees) >deg){
    fl.spin(reverse,50,pct);
    fr.spin(forward,50,pct);
    bl.spin(reverse,50,pct);
    br.spin(forward,50,pct);
  }
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}

void tr(int deg) {
  
  while (inert.rotation(degrees) <deg){
    fl.spin(forward,50,pct);
    fr.spin(reverse,50,pct);
    bl.spin(forward,50,pct);
    br.spin(reverse,50,pct);
  }
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}

void ttg() {

}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  drivebase fd;
  fd.d();
  int num = 1;
  int num2 = 1;
  int f = 0;
  int speed=80;
  int intak = 0;
inert.calibrate();
while(true) {

  fl.spin(forward, Controller1.Axis3.position()+ Controller1.Axis4.position()+ Controller1.Axis1.position(), pct);
  fr.spin(forward, Controller1.Axis3.position()- Controller1.Axis4.position()- Controller1.Axis1.position(), pct);
  bl.spin(forward, Controller1.Axis3.position()+ Controller1.Axis4.position()- Controller1.Axis1.position(), pct);
  br.spin(forward, Controller1.Axis3.position()- Controller1.Axis4.position()+ Controller1.Axis1.position(), pct);


  if(Controller1.ButtonA.pressing()) {
    while(Controller1.ButtonA.pressing()) {
      wait(10,msec);
    }

  num = num+1;
  if (num >1) {
    num = 0;
  }

  numatics2 = num;
  wait(.5,seconds);
  numatics = num;
  


  }



  if(Controller1.ButtonR1.pressing()) {
    while(Controller1.ButtonR1.pressing()) {
      wait(10,msec);
    }

  num2 = num2+1;
  if (num2 >1) {
    num2 = 0;
  }

  numatics2 = num2;
  
  


  }


  if(Controller1.ButtonL1.pressing()) {
    while(Controller1.ButtonL1.pressing()) {
      wait(10,msec);
    }

  f = f+1;
  if (f >1) {
    f = 0;
  }

  }

  if(Controller1.ButtonL2.pressing()) {
    while(Controller1.ButtonL2.pressing()) {
      wait(10,msec);
    }

  intak = intak+1;
  if (intak >1) {
    intak = 0;
  }

  }

  if(Controller1.ButtonUp.pressing()&& speed <101) {
    while(Controller1.ButtonUp.pressing()){
      wait(10,msec);
    }
    speed = speed + 10;
    
  }
  if(Controller1.ButtonDown.pressing() && speed >0) {
    while(Controller1.ButtonDown.pressing()){
      wait(10,msec);
    }
    speed = speed - 10;
    
  }


  int act = speed - (fly1.velocity(pct) + fly2.velocity(pct))/2;


  if (f == 0) {
  fly1.stop();
  fly2.stop();}
  if (f==1) {
    fly1.spin(forward, speed+act*.1, pct);
    fly2.spin(forward, speed+act*.1, pct);
  }
  if (intak ==0) {
  i.stop();
  side.stop();}
  if (intak==1) {
    i.spin(forward, 100, pct);
    side.spin(forward, 100, pct);
  }






}
  

  // while(Optic1.color()!=red) {
  //   wait(10,msec);
  // }
  // i.stop();
}
