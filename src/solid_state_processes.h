#ifndef SSP_H_	
#define SSP_H_

#include "constants_structs.h"
#include "types.h"
#include "vtk_writer.h"
#include<vector>
#include<iostream>

//variablen

extern float_x dz;
extern float_x ms;
extern float_x global_dz;
extern float_x global_Vsf;  //velocity scale factor
extern float_x hdx;


//geschwindigkeiten

extern float_x global_rod_vel;
extern float_x global_substrate_vel;

//bounding box

extern float_x x_min_bb; //minimaler x wert der bounding box
extern float_x y_min_bb;
extern float_x z_min_bb;

extern float_x x_max_bb;
extern float_x y_max_bb;
extern float_x z_max_bb;


//time

extern float_x global_time_dt;
extern float_x	global_time_final;


















void setup_FS();
#endif /* SSP_H_ */
