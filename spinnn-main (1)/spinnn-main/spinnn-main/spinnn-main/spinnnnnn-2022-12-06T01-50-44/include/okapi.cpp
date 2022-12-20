#include "vex.h"

using namespace vex;

class drivebase {
  float radius;
  double kp;
  double ki;
  double kd;
  public: void d() {
    thread  (positiontrack());
  }
  float x= 0;
  float y = 0;
  float head = 0;
  void dnf(int x1,int y1, int r1){
    
    while(x1 !=x && y1!=y) {

      



    float xdif = x1-x;
    float ydif = y1-y;
    float rdif = r1-head;


    float thet = atan(ydif/xdif)-head;

    float rx = cos(thet)*xdif;
    float ry = sin(thet)*ydif;




    fl.spin(forward, ry+rx+rdif,pct);
    bl.spin(forward, ry-rx+rdif,pct);
    fr.spin(forward, ry-rx-rdif,pct);
    br.spin(forward, ry+rx-rdif,pct);
    }
    fl.stop();
    fr.stop();
    bl.stop();
    br.stop();

  }
  int xpos(){
    return x;
  }
  int ypos(){
    return y;
  }

  void ttp(int x1, int y1) {
    float degree = atan((y1-y)/(x1-x))*180/3.14159;

    while(fabs(inert.rotation()-degree)<1) {

      fr.spin(reverse, degree-inert.rotation(),pct);
      br.spin(reverse, degree-inert.rotation(),pct);
      fl.spin(forward, degree-inert.rotation(),pct);
      bl.spin(forward, degree-inert.rotation(),pct);
    }
    fr.stop();
    fl.stop();
    br.stop();
    bl.stop();
  }




  int positiontrack() {
    float theta =0;
    
    
    while (true)
    {
      head = inert.rotation(degrees);
      xrot.resetPosition();
      yrot.resetPosition();
      wait(10, msec);
      theta = inert.rotation(degrees) - head;
      float k = (180 - theta)/2 + head;
      float rad1 = 180*(xrot.position(degrees)*(2*radius*3.14159/360))/(theta*3.14159);
      float rad2 = 180*yrot.position(degrees)*(2*radius*3.14159/360)/(theta*3.14159);
      float Chord1 = 2*rad1*sin((xrot.position(degrees)/(2*rad1))*3.14159/180);
      float Chord2 = 2*rad2*sin((xrot.position(degrees)/(2*rad2))*3.14159/180);
      x = x+ sin(k*3.14159/180)*Chord2 + cos(k*3.14159/180)*Chord1;
      y = y+ sin(k*3.14159/180)*Chord1 + cos(k*3.14159/180)*Chord2;
    }
    return 0;
  }
  





};