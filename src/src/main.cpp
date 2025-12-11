#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fenv.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "solid_state_processes.h"
#include "types.h"

// globals
float_x global_time_dt = 0.0;
float_x global_time_final = 0.0;
float_x global_wz = 0.0;
float_x global_substrate_velocity = 0.0;
float_x global_rod_feeding_rate = 0.0;
float_x global_Vsf = 0.0;
float_x global_dz = 0.0;



int main(int argc, char *argv[])
{
	// make results directoy if not present
	struct stat st = {0};
	if (stat("results", &st) == -1)
	{
		mkdir("results", 0777);
	}

	// clear files from result directory
	int ret;
	ret = system("rm results/*");

	// setup and run FS process simulation
	setup_FS();

	return 0;
}
