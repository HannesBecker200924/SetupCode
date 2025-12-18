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
extern float_x vel_x;
extern float_x vel_y;
extern float_x vel_z;

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

struct data_struct{

	float_x length_Unit; 
	float_x time_Unit;
	float_x mass_Unit;
	float_x temp_Unit;
    float_x pressure_Unit; 
	float_x energy_Unit;
	float_x power_Unit;
	float_x angle_Unit;
    float_x dz;
	float_x ms;
	float_x hdx;
	float_x global_Vsf;
	float_x global_dz;
	float_x vel_x;
	float_x vel_y;
	float_x vel_z;
	float_x global_rod_vel;
	float_x global_substrate_vel;
	float_x global_wz; 
	glm::vec3 w; 
    int step;
	float_x global_time_final;
	float_x h1;
	float_x q;
	float_x fac;
    phys_constants phys_substrate;
	trml_constants trml_substrate;
	corr_constants corr_substrate;
	joco_constants joco_substrate;
    phys_constants phys_rod;
	joco_constants joco_rod;
	trml_constants trml_rod;
	corr_constants corr_rod;
    float_x substrate_width;
	float_x substrate_length;
	float_x substrate_thickness;
	float_x rod_diameter;
	float_x rod_height;
    float_x shift_x;
	float_x shift_y;
	float_x shift_z;
    float_x CFl;
};

data_struct setup_FS();
#endif  //SSP_H_ 
