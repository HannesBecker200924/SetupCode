//Copyright ETH Zurich, IWF

//This file is part of iwf_mfree_gpu_3d.

//iwf_mfree_gpu_3d is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.

//iwf_mfree_gpu_3d is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.

//You should have received a copy of the GNU General Public License
//along with mfree_iwf.  If not, see <http://www.gnu.org/licenses/>.

#ifndef CONSTANTS_STRUCTS_H_
#define CONSTANTS_STRUCTS_H_

#include "types.h"

#include <cstring>

struct phys_constants {
	float_x E;		// youngs modulus                    Pa = N/m²    N = kg * m/s²  --> kg / (s² * m)
	float_x nu;		// poisson ratio                     keine Einheit
	float_x rho0;	// reference density                 kg/m³
	float_x K;		// bulk modulus                      Pa = N/m² --> kg / (s² * m)
	float_x G;		// shear modulus                     Pa = N/m² --> kg / (s² * m)
	float_x mass;	// particle mass                     kg
};

phys_constants make_phys_constants();

struct trml_constants {
	float_x cp;     // thermal capacity                  J/(kg*K)     J = N * m = kg * m² / s²  --> m² / (s² * K)
	float_x tq;	    // taylor quinney constant           keine einheit
	float_x k;	    // thermal conductivity              W/(m*K)  = (J/s)/(m*k) --> (kg * m) / (s³ * K)
	float_x alpha;	// thermal diffusitivty              m²/s
	float_x T_init;	// initial temperature               K
	float_x eta;	// fraction of frictional power turned to heat  keine Einheit
};

trml_constants make_trml_constants();

struct corr_constants { //alle keine Einheit
	float_x wdeltap  ;	// value of kernel function at init particle spacing (for artificial stress)
	float_x stresseps;	// intensity of artificial stress
	float_x xspheps  ;	// XSPH factor (balance between interpolated and advection velocity)
	float_x alpha    ;	// artificial viscosity constant
	float_x beta     ;  // artificial viscosity constant
	float_x eta      ;  // artificial viscosity constant
};

corr_constants make_corr_constants();

//johnson cook material constants
struct joco_constants {
	float_x A;                            //Pa = N/m²  --> kg / (s² * m)
	float_x B;                            //Pa = N/m²  --> kg / (s² * m)
	float_x C;                            //keine Einheit
	float_x n;                            //keine Einheit
	float_x m;                            //keine Einheit
	float_x Tmelt;                        //K
	float_x Tref;                         //K
	float_x eps_dot_ref;                  //1/s
	float_x clamp_temp;			//limit temperature of particles to melting temp in johnson cook?  K
};

joco_constants make_joco_constants();

//geometrical constants for spatial hashing
struct geom_constants {

	// number of cells in each direction
	int nx;
	int ny;
	int nz;

	// extents of spatial hashing grid    in m
	float_x bbmin_x;                   
	float_x bbmin_y;
	float_x bbmin_z;

	float_x bbmax_x;
	float_x bbmax_y;
	float_x bbmax_z;

	// edge length of a cell  in m
	float_x dx;      
};

geom_constants make_geom_constants();

extern float_x pii;
extern float_x revolution_to_rad;

#endif /* CONSTANTS_STRUCTS_H_ */
