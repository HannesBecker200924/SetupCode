#ifndef read_and_print_H
#define read_and_print_H

#include"solid_state_processes.h"
#include"constants_structs.h"
#include<fstream>
#include<string>

void empty_textfile();

void print_to_textfile(data_struct data_for_print_f);   //wurde nicht definiert

void read_textfile(data_struct& data_for_print_f);

void read_textfile_HaBe(data_struct& data_for_print_f);

/*void print_to_textfile(float_x& length_Unit, float_x& time_Unit, float_x &mass_Unit, float_x &temp_Unit,
float_x &pressure_Unit, float_x &energy_Unit, float_x &power_Unit, float_x &angle_Unit,
float_x &dz, float_x &ms, float_x &hdx, float_x &global_Vsf, float_x &global_dz,
float_x& vel_x, float_x& vel_y, float_x& vel_z, float_x &global_rod_vel, float_x &global_substrate_vel, 
float_x &global_wz, glm::vec3 &w, 
int &step, float_x &global_time_final,
phys_constants& phys_substrate,trml_constants& trml_substrate,corr_constants& corr_substrate,joco_constants& joco_substrate,
phys_constants& phys_rod, joco_constants& joco_rod, trml_constants& trml_rod, corr_constants& corr_rod,
float_x &substrate_width, float_x &substrate_length, float_x &substrate_thickness, float_x &rod_diameter, float_x &rod_height,
float_x& shift_x, float_x& shift_y, float_x& shift_z,
float_x& CFl);

Diese Funktion funktioniert nur wenn jeder einzelne Parameter einzeln übergeben wird und nicht als array.
Dafür kann dann der Datentyp setup_FS funktion geändert werden.

Es fehlen ein paar werte


*/


/*In dieser file sollen alle daten die gesammelt wurden(konstanten) in eine textfile geprintet werden

// units converter values (umrechnungen einheiten)
// standard Einheiten: millimeter, sekunde, gramm, grad celsius,
float_x length_Unit = 1.;	// standard mm = 1     m = 1000
float_x time_Unit = 1.;		// standard s = 1      min = 60
float_x mass_Unit = 1.;		// standard g = 1      kg = 1000
float_x temp_Unit = 0.;		// standard C° = 0     Kelvin K = - 273.15
float_x pressure_Unit = 1.; // standard Pa = 1     GPa = 1,000,000,000
float_x energy_Unit = 1.;	// standard J = 1      kJ =  * 1000
float_x power_Unit = 1.;	// standard Watt = 1   kW = * 1000
float_x angle_Unit = 1.;	// standard Bogenmaß rad = 1    Grad = (pii/180)

float_x dz = 1.0 * length_Unit;
	float_x ms = 1.0;
	float_x hdx = 1.7;
    global_Vsf = 10;
	global_dz = dz;

    float_x global_rod_vel = (-2.0 * global_Vsf) * length_Unit / time_Unit; // negativ da nach unten und mal Vsf für den Faktor
	float_x global_substrate_vel = 5. * global_Vsf * length_Unit / time_Unit;
	float_x global_wz = (900. * 0.104719755 * global_Vsf) * angle_Unit / time_Unit; // Winkelgeschwindigkeit (rad/s)
	glm::vec3 w(0.0, 0.0, global_wz);

    int step = 0; // Anfangsposition
	global_time_final = 8. / global_Vsf; // 0.7 s ramping

	phys_constants phys_substrate = make_phys_constants(); // ein Objekt der konstanten erstmal nur erstellen
	trml_constants trml_substrate = make_trml_constants();
	corr_constants corr_substrate = make_corr_constants();
	joco_constants joco_substrate = make_joco_constants();
//Konstanten
	phys_substrate.E = 70.e9 * pressure_Unit;
	phys_substrate.nu = 0.3;
	phys_substrate.rho0 = 2700.0 * 1.0e-6 * ms * mass_Unit / (length_Unit * length_Unit * length_Unit);
	phys_substrate.G = phys_substrate.E / (2. * (1. + phys_substrate.nu));
	phys_substrate.K = 2.0 * phys_substrate.G * (1 + phys_substrate.nu) / (3 * (1 - 2 * phys_substrate.nu));
	phys_substrate.mass = dz * dz * dz * phys_substrate.rho0;

	joco_substrate.A = 167.e6 * pressure_Unit;
	joco_substrate.B = 0 * pressure_Unit;
	joco_substrate.C = 0.001;
	joco_substrate.m = 0.859;
	joco_substrate.n = 0;
	joco_substrate.Tref = 20 + temp_Unit;
	joco_substrate.Tmelt = 620 + temp_Unit;
	joco_substrate.eps_dot_ref = 1. / time_Unit;
	joco_substrate.clamp_temp = 1;

	trml_substrate.cp = ((910. * 1.0e6) / ms) * energy_Unit / mass_Unit; // wärmekapazität
	trml_substrate.tq = 0.9;
	trml_substrate.eta = 0.9;									
	trml_substrate.k = 117. * 1.0e6 * global_Vsf * power_Unit / length_Unit; // wärmeleitfähigkeit
	trml_substrate.alpha = trml_substrate.k / (phys_substrate.rho0 * trml_substrate.cp);
	trml_substrate.T_init = joco_substrate.Tref + temp_Unit; // referenztemperatur

	corr_substrate.alpha = 1.;
	corr_substrate.beta = 1.;
	corr_substrate.eta = 0.1;
	corr_substrate.xspheps = 0.01;
	corr_substrate.stresseps = 0.3;
	float_x h1 = 1. / (hdx * dz);
	float_x q = dz * h1;
	float_x fac = (M_1_PI)*h1 * h1 * h1;
	corr_substrate.wdeltap = fac * (1 - 1.5 * q * q * (1 - 0.5 * q));

	phys_constants phys_rod = make_phys_constants();
	joco_constants joco_rod = make_joco_constants();
	trml_constants trml_rod = make_trml_constants();
	corr_constants corr_rod = make_corr_constants();

	phys_rod.E = 70.e9 * pressure_Unit;
	phys_rod.rho0 = (2700.0 * 1.0e-6) * ms * mass_Unit / (length_Unit * length_Unit * length_Unit);
	phys_rod.nu = 0.3;
	phys_rod.G = phys_rod.E / (2. * (1. + phys_rod.nu));
	phys_rod.K = 2.0 * phys_rod.G * (1 + phys_rod.nu) / (3 * (1 - 2 * phys_rod.nu));
	phys_rod.mass = dz * dz * dz * phys_rod.rho0;

	joco_rod.A = 167.e6 * pressure_Unit;
	joco_rod.B = 0 * pressure_Unit;
	joco_rod.C = 0.001;
	joco_rod.m = 0.859;
	joco_rod.n = 0;
	joco_rod.Tref = 20 + temp_Unit;
	joco_rod.Tmelt = 620 + temp_Unit;
	joco_rod.eps_dot_ref = 1. / time_Unit;
	joco_rod.clamp_temp = 1.;

	trml_rod.cp = ((910. * 1.0e6) / ms) * energy_Unit / mass_Unit; // wärmekapazität
	trml_rod.tq = 0.9;
	trml_rod.eta = 0.9;												
	trml_rod.k = 117. * 1.0e6 * global_Vsf * power_Unit / mass_Unit; // wärmeleitfähigkeit
	trml_rod.alpha = trml_rod.k / (phys_rod.rho0 * trml_rod.cp);
	trml_rod.T_init = joco_rod.Tref + temp_Unit; // referenztemperatur

	corr_rod.alpha = 1.;
	corr_rod.beta = 1.;
	corr_rod.eta = 0.1;
	corr_rod.xspheps = 0.01;
	corr_rod.stresseps = 0.3;
	corr_rod.wdeltap = fac * (1 - 1.5 * q * q * (1 - 0.5 * q));

	// 2.3   substrate dimensionen
	const float_x substrate_width = 50. * length_Unit;
	const float_x substrate_length = 100. * length_Unit;
	const float_x substrate_thickness = 8.0 * length_Unit;
	const float_x rod_diameter = 20.0 * length_Unit;
	const float_x rod_height = 40.0 * length_Unit;

	float_x shift_x = substrate_length / 4.0;
	float_x shift_y;
	float_x shift_z;
        
    constexpr float_x CFL = 0.3;
    
    */
#endif

