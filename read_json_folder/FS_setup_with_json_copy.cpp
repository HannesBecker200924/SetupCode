particle_gpu *setup_FS_with_json_HaBe(int nbox, grid_base **grid)
{
	//this function is the same as the one above but has changeable units and reads the values from a json file
	//THIS ONE IS NOT WORKING. A FEW THINGS HAVE BEEN CHANGED


	//Units
	float_x length_Unit;
	float_x time_Unit;
	float_x mass_Unit;
	float_x temp_Unit;
	float_x angle_Unit;

	std::ifstream file("../Data/FS_values.json");

    if (!file.is_open())
    {
        std::cerr << "JSON file could not be opened / found!\n";
        std::exit(1);
    }

    nlohmann::json j;

    file >> j;

    //values for the units
    if (j["units"]["length_unit"].get<std::string>() == "m")
    {

        length_Unit = 1000;
    }
    else if (j["units"]["length_unit"].get<std::string>() == "cm")
    {

        length_Unit = 10;
    }
    else if (j["units"]["length_unit"].get<std::string>() == "mm")
    {

        length_Unit = 1;
    }

    if (j["units"]["time_unit"].get<std::string>() == "s")
    {

        time_Unit = 1;
    }
    else if (j["units"]["time_unit"].get<std::string>() == "ms")
    {

        time_Unit = 0.001;
    }
    else if (j["units"]["time_unit"].get<std::string>() == "min")
    {

        time_Unit = 60;
    }

    if (j["units"]["mass_unit"].get<std::string>() == "kg")
    {

        mass_Unit = 1000;
    }
    else if (j["units"]["mass_unit"].get<std::string>() == "g")
    {

        mass_Unit = 1;
    }

    if (j["units"]["temperature_unit"].get<std::string>() == "°C")
    {

        temp_Unit = 0;
    }
    else if (j["units"]["temperature_unit"].get<std::string>() == "K")
    {

        temp_Unit = 273.15;
    }

    if (j["units"]["angle_unit"].get<std::string>() == "degree")
    {

        angle_Unit = 0.0174533;
    }
    else if (j["units"]["angle_unit"].get<std::string>() == "rad")
    {

        angle_Unit = 1;
    }

	//calculated values
	float_x pressure_Unit = mass_Unit / (time_Unit * time_Unit * length_Unit);
	float_x energy_Unit = mass_Unit * length_Unit * length_Unit / (time_Unit * time_Unit);
	float_x power_Unit = mass_Unit * length_Unit * length_Unit / (time_Unit * time_Unit * time_Unit);
	

	//material propertie objects
	phys_constants phys = make_phys_constants();
	corr_constants corr = make_corr_constants();
	trml_constants trml_wp = make_trml_constants();
	trml_constants trml_tool = make_trml_constants();
	joco_constants joco = make_joco_constants();

	// Constants
	float_x ms = j["global_constants"]["mass_scale"].get<float_x>();
	global_Vsf = j["global_constants"]["vel_scale"].get<float_x>();
	float_x dz = j["global_constants"]["init_particle_dist"].get<float_x>() * length_Unit;
	global_dz = dz;
	float_x hdx = j["global_constants"]["smooth_len"].get<float_x>();

	// dimensions of the workpiece
	float_x wp_width = j["sub_rod_dimensions"]["sub_width"].get<float_x>() * length_Unit;
	float_x wp_length = j["sub_rod_dimensions"]["sub_length"].get<float_x>() * length_Unit;
	float_x wp_thickness = j["sub_rod_dimensions"]["sub_thickness"].get<float_x>() * length_Unit;
	float_x probe_diameter = j["sub_rod_dimensions"]["rod_diameter"].get<float_x>() * length_Unit;
	global_probe_raduis = probe_diameter / 2.0;
	float_x probe_hight = j["sub_rod_dimensions"]["rod_height"].get<float_x>() * length_Unit;

	float_x shift = wp_length / 2 - j["centering_substrate"]["shift_x"].get<float_x>(); //shift in x-direction
	float_x shift_y = wp_width / 2 - j["centering_substrate"]["shift_y"].get<float_x>();
	float_x shift_z = 0;

	int nx = static_cast<int>(wp_length / dz) + 1;
	int ny = static_cast<int>(wp_width / dz) + 1;

	// BC
	global_probe_velocity = j["Velocitys"]["rod_feed"].get<float_x>() * global_Vsf * length_Unit / time_Unit;
	global_substrate_velocity = j["Velocitys"]["vx_sub"].get<float_x>() * global_Vsf * length_Unit / time_Unit;
	global_substrate_velocity_y = j["Velocitys"]["vy_sub"].get<float_x>() * global_Vsf * length_Unit / time_Unit;
	global_substrate_velocity_z = j["Velocitys"]["vz_sub"].get<float_x>() * global_Vsf * length_Unit / time_Unit;

	global_wz = j["Velocitys"]["rpm"].get<float_x>() * angle_Unit * global_Vsf / time_Unit;
	glm::vec3 w(0.0, 0.0, global_wz);


	// physical constants   THERE SHOULD BE TWO SEPARATE PHYS OBJECTS: ONE FOR ROD AND ONE FOR SUBS (FOR NOW SUBS VALUES ARE USED)
	phys.E = j["constants-substrate"]["E_sub"].get<float_x>() * pressure_Unit;
	phys.nu = j["constants-substrate"]["nu_sub"].get<float_x>();
	phys.rho0 = j["constants-substrate"]["rho_sub"].get<float_x>() * ms * mass_Unit / (length_Unit * length_Unit * length_Unit);
	phys.G = phys.E / (2. * (1. + phys.nu));
	phys.K = 2.0 * phys.G * (1 + phys.nu) / (3 * (1 - 2 * phys.nu));
	phys.mass = dz * dz * dz * phys.rho0;
	

	// Johnson Cook Constants
	joco.A = j["constants-substrate"]["jc_A_sub"].get<float_x>() * pressure_Unit;
	joco.B = j["constants-substrate"]["jc_B_sub"].get<float_x>() * pressure_Unit;
	joco.C = j["constants-substrate"]["jc_C_sub"].get<float_x>();		
	joco.m = j["constants-substrate"]["jc_m_sub"].get<float_x>();	
	joco.n = j["constants-substrate"]["jc_n_sub"].get<float_x>();
	joco.Tref = j["constants-substrate"]["jc_Tref_sub"].get<float_x>() + temp_Unit;	
	joco.Tmelt = j["constants-substrate"]["jc_Tmelt_sub"].get<float_x>() + temp_Unit;	
	joco.eps_dot_ref = j["constants-substrate"]["jc_epsdot_sub"].get<float_x>() / time_Unit;
	joco.clamp_temp = 1.;

	// Thermal Constants
	trml_wp.cp = (j["constants-substrate"]["c_sub"].get<float_x>() / ms) * energy_Unit / mass_Unit;  // Heat Capacity
	trml_wp.tq = j["constants-substrate"]["tq_sub"].get<float_x>();			  // Taylor-Quinney Coefficient
	trml_wp.k = j["constants-substrate"]["k_sub"].get<float_x>() * global_Vsf * power_Unit / length_Unit;	  // Thermal Conduction
	trml_wp.alpha = trml_wp.k / (phys.rho0 * trml_wp.cp); // Thermal diffusivity
	trml_wp.eta = j["constants-substrate"]["therm_eff_sub"].get<float_x>();
	trml_wp.T_init = joco.Tref; // Initial Temperature



	phys_constants phys_rod = make_phys_constants();
	trml_constants trml_rod = make_trml_constants();
	trml_constants trml_tool_rod = make_trml_constants();
	joco_constants joco_rod = make_joco_constants();


	// physical constants   for the rod
	phys_rod.E = j["constants-rod"]["E_rod"].get<float_x>() * pressure_Unit;
	phys_rod.nu = j["constants-rod"]["nu_rod"].get<float_x>();
	phys_rod.rho0 = j["constants-rod"]["rho_rod"].get<float_x>() * ms * mass_Unit / (length_Unit * length_Unit * length_Unit);
	phys_rod.G = phys_rod.E / (2. * (1. + phys_rod.nu));
	phys_rod.K = 2.0 * phys_rod.G * (1 + phys_rod.nu) / (3 * (1 - 2 * phys_rod.nu));
	phys_rod.mass = dz * dz * dz * phys_rod.rho0;
	

	// Johnson Cook Constants
	joco_rod.A = j["constants-rod"]["jc_A_rod"].get<float_x>() * pressure_Unit;
	joco_rod.B = j["constants-rod"]["jc_B_rod"].get<float_x>() * pressure_Unit;
	joco_rod.C = j["constants-rod"]["jc_C_rod"].get<float_x>();		
	joco_rod.m = j["constants-rod"]["jc_m_rod"].get<float_x>();	
	joco_rod.n = j["constants-rod"]["jc_n_rod"].get<float_x>();
	joco_rod.Tref = j["constants-rod"]["jc_Tref_rod"].get<float_x>() + temp_Unit;	
	joco_rod.Tmelt = j["constants-rod"]["jc_Tmelt_rod"].get<float_x>() + temp_Unit;	
	joco_rod.eps_dot_ref = j["constants-rod"]["jc_epsdot_rod"].get<float_x>() / time_Unit;
	joco_rod.clamp_temp = 1.;

	// Thermal Constants
	trml_rod.cp = (j["constants-rod"]["c_rod"].get<float_x>() / ms) * energy_Unit / mass_Unit;	 // Heat Capacity
	trml_rod.tq = j["constants-rod"]["tq_rod"].get<float_x>();			  // Taylor-Quinney Coefficient
	trml_rod.k = j["constants-rod"]["k_rod"].get<float_x>() * global_Vsf * power_Unit / length_Unit;  // Thermal Conduction
	trml_rod.alpha = trml_rod.k / (phys_rod.rho0 * trml_rod.cp); // Thermal diffusivity
	trml_rod.eta = j["constants-rod"]["therm_eff_rod"].get<float_x>();
	trml_rod.T_init = joco_rod.Tref; // Initial Temperature

	// Corrector Constants THIS IS CORRECT FOR BOTH (SUB AND ROD) TOGETHER
	corr.alpha = j["corr_parameters"]["alpha_sph"].get<float_x>(); 
	corr.beta = j["corr_parameters"]["beta_sph"].get<float_x>();
	corr.eta = j["corr_parameters"]["eta_sph"].get<float_x>();
	corr.xspheps = j["corr_parameters"]["xsph_corr"].get<float_x>();
	corr.stresseps = j["corr_parameters"]["stress_reg"].get<float_x>();
	float_x h1 = 1. / (hdx * dz);
	float_x q = dz * h1;
	float_x fac = (M_1_PI)*h1 * h1 * h1;
	corr.wdeltap = fac * (1 - 1.5 * q * q * (1 - 0.5 * q));


	//heat convection
	float_x heco_wp_to_air = j["heat_convection"]["h_air"].get<float_x>() * global_Vsf * (power_Unit / (length_Unit * length_Unit));
	float_x heco_wp_to_metal = j["heat_convection"]["h_metal"].get<float_x>() * global_Vsf * (power_Unit / (length_Unit * length_Unit));







	std::vector<Point> points;
	float_x zz = 0;

	while (zz < wp_thickness + probe_hight)
	{
		if (zz < wp_thickness)
		{
			generate_grid_points(nx, ny, dz, zz, points);
		}
		else
		{
			generate_circular_points_hollow(probe_diameter, dz, zz, points);
		}
		zz += dz;
	}

	int n = static_cast<int>(points.size());

	// Compute bounds and lowest z in a single traversal to reduce passes over the data
	float_x lowest_point_z = std::numeric_limits<float_x>::max();
	float_x min_x = std::numeric_limits<float_x>::max();
	float_x max_x = std::numeric_limits<float_x>::lowest();
	float_x min_y = std::numeric_limits<float_x>::max();
	float_x max_y = std::numeric_limits<float_x>::lowest();
	float_x min_z = std::numeric_limits<float_x>::max();
	float_x max_z = std::numeric_limits<float_x>::lowest();

	for (const auto &pt : points)
	{
		if (pt.x < min_x)
			min_x = pt.x;
		if (pt.x > max_x)
			max_x = pt.x;
		if (pt.y < min_y)
			min_y = pt.y;
		if (pt.y > max_y)
			max_y = pt.y;
		if (pt.z < min_z)
			min_z = pt.z;
		if (pt.z > max_z)
			max_z = pt.z;
		if (pt.z < lowest_point_z)
			lowest_point_z = pt.z;
	}

	printf("lowest point z: %f\n", lowest_point_z);
	printf("min_x: %f, max_x: %f, min_y: %f, max_y: %f\n", min_x, max_x, min_y, max_y);

	*grid = new grid_gpu_green(n, make_float3_t(-1. - wp_length / 2. - shift, -1. - wp_width / 2, -1.), make_float3_t(+1. + wp_length / 2. - shift, +1. + wp_width / 2, +2 + wp_thickness + probe_hight), hdx * dz);
	(*grid)->set_bbox_vel(make_float3_t(global_substrate_velocity, 0., global_probe_velocity));
	global_blanking = new blanking(vec3_t(-1. - wp_length / 2 - shift, -1 - wp_width / 2, -1.), vec3_t(+1. + wp_length / 2 - shift, +1. + wp_width / 2, +2 + wp_thickness + probe_hight), vec3_t(global_substrate_velocity, 0., global_probe_velocity), global_wz * global_probe_raduis * global_wz * global_probe_raduis * 2.);
	printf("calculating with %d\n", n);

	float4_t *pos = new float4_t[n];
	float4_t *vel = new float4_t[n];
	float_x *h = new float_x[n];
	float_x *rho = new float_x[n];
	float_x *T = new float_x[n];
	float_x *tool_p = new float_x[n];
	float_x *fixed = new float_x[n];

	for (int i = 0; i < n; i++)
	{
		rho[i] = phys.rho0; 
		tool_p[i] = 1;
		fixed[i] = -2;

		float_x radius = sqrt(points[i].x * points[i].x + points[i].y * points[i].y);
		pos[i] = {points[i].x, points[i].y, points[i].z, i};
		h[i] = hdx * dz;
		vel[i] = {0.0, 0.0, 0.0, 0.0};
		T[i] = joco.Tref;

		// probe 3
		if (pos[i].z >= wp_thickness)
		{
			rho[i] = phys.rho0;
			tool_p[i] = 0;
			fixed[i] = 0;

			glm::vec3 r(pos[i].x, pos[i].y, 0.0);
			glm::vec3 v = glm::cross(w, r);
			vel[i] = {v.x, v.y, global_probe_velocity, 0.0};
			if (pos[i].z >= max_z - 2 * dz)
			{
				fixed[i] = -1; // top surface
			}
		}

		// thermal BC
		if (pos[i].x == min_x || pos[i].x == max_x || pos[i].y == min_y || pos[i].y == max_y)
		{
			fixed[i] = 7;
		}

		if (pos[i].z == 0 || pos[i].z == 0 + dz)
		{
			fixed[i] = 2; // bottom plate
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (tool_p[i] == 1)
		{

			pos[i].x -= shift;

			global_shoulder_contact_surface = std::max(global_shoulder_contact_surface, pos[i].z);
			global_top_surface = global_shoulder_contact_surface;
			global_probe_contact_surface = global_shoulder_contact_surface;
		}
	}

	actions_setup_corrector_constants(corr);
	actions_setup_physical_constants(phys);
	actions_setup_thermal_constants_wp(trml_wp);
	actions_setup_thermal_constants_tool(trml_wp);
	actions_setup_johnson_cook_constants(joco);

	interactions_setup_corrector_constants(corr);
	interactions_setup_physical_constants(phys);
	interactions_setup_geometry_constants(*grid);
	interactions_setup_thermal_constants_workpiece(trml_wp);
	interactions_setup_thermal_constants_tool(trml_wp);
	interactions_setup_johnson_cook_constants(joco);

	particle_gpu *particles = new particle_gpu(pos, vel, rho, T, h, fixed, tool_p, n);

	float_x max_vel = w.z * (probe_diameter / 2.0);
	float_x c0 = sqrt(phys.K / phys.rho0);
	constexpr float_x CFL = 0.3;
	float_x delta_t_max = CFL * hdx * dz / (sqrt(max_vel) + c0);
	global_time_dt = 0.5 * delta_t_max;


	global_time_final = j["global_constants"]["proc_time"].get<float_x>() / global_Vsf; // 0.7 s ramping

	global_time_dt_cooling = 1.e-6;
	global_time_cooling = 13.3 / global_Vsf;

	assert(check_cuda_error());
	return particles;
}