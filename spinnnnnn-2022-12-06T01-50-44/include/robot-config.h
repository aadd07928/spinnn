using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor side;
extern digital_out numatics;
extern digital_out numatics2;
extern controller Controller1;
extern motor i;
extern motor fly1;
extern motor fly2;
extern optical Optic1;
extern optical Optic2;
extern motor fl;
extern motor fr;
extern motor bl;
extern motor br;
extern inertial inert;
extern rotation xrot;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );