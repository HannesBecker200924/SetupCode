#include "solid_state_processes.h"
#include "read_and_print.h"

struct Point
{
	float_x x;
	float_x y;
	float_x z;
};

// Funktion um die points zu erstellen benötigt: nx partikel in x richtung, ny , dz, height_points und einen vector vom typ <Point>
void generate_grid_points_substrate(int nx, int ny, float_x dz, float_x height_points, std::vector<Point> &points)
{
	// durch &points kann der Vektor der der Funktion übergeben wird selber überschrieben werden anstatt ihn zu kopeiren --> günstig

	for (int i = 0; i < nx; i++)
	{

		for (int j = 0; j < ny; j++)
		{

			// float_x x =  i * dz;   //Koordinatensystem außen
			// float_x y =  j * dz;   //j oder auch i mal dz ist dann der aktuelle punkt mal dem abstand von dz

			float_x x = -nx / 2.0 * dz + i * dz; // Koordinatensystem in der zentralen mitte (a/2 | b/2)
			float_x y = -ny / 2.0 * dz + j * dz;

			points.push_back(Point{x, y, height_points}); // vector um neuen punkt hinzuzufügen
		}
	}
}

void generate_grid_points_rod(float_x rod_diameter, float_x dz, float_x height_points, std::vector<Point> &points)
{

	float_x radius = rod_diameter / 2.0;

	for (float_x x = -radius; x <= radius; x += dz)
	{

		for (float_x y = -radius; y <= radius; y += dz)
		{

			float_x r = sqrt(x * x + y * y); // abstand vom punkt zur mitte der rod
			if (r <= radius)				 // nur wenn r vom punkt dann kleiner als der radius ist wird der punkt zum vector hinzugefügt
			{
				points.push_back(Point{x, y, height_points});
			}
		}
	}
}

void vector_in_array(float4_t *points_array, const std::vector<Point> &points_vector, unsigned int n)
{ // const nur zur sicherheit

	for (int i = 0; i < n; i++)
	{ // vector kopieren in den array

		points_array[i].x = points_vector[i].x;
		points_array[i].y = points_vector[i].y;
		points_array[i].z = points_vector[i].z;

		points_array[i].w = 0;
	}
}

void max_min(int n, std::vector<Point>& points_vector, float_x &x_min, float_x &y_min, float_x &z_min,
			 float_x &x_max, float_x &y_max, float_x &z_max)
{ // mit der referenz kann man dann die variable selber ändern

	for (int h = 0; h < n; h++)
	{

		if (points_vector[h].x < x_min)
		{

			x_min = points_vector[h].x;
		}

		if (points_vector[h].y < y_min)
		{

			y_min = points_vector[h].y;
		}

		if (points_vector[h].z < z_min)
		{

			z_min = points_vector[h].z;
		}

		if (points_vector[h].x > x_max)
		{

			x_max = points_vector[h].x;
		}

		if (points_vector[h].y > y_max)
		{

			y_max = points_vector[h].y;
		}

		if (points_vector[h].z > z_max)
		{

			z_max = points_vector[h].z;
		}
	}
}

void find_fixed(int *fixed, float4_t *points_array, int n, float_x x_min_substrate,
float_x y_min_substrate, float_x z_min_substrate, float_x x_max_substrate, float_x y_max_substrate, float_x z_max_rod)
{

	for (int i = 0; i < n; i++)
	{

		if (points_array[i].z == z_min_substrate)
		{

			fixed[i] = 2;
		}

		else if (points_array[i].x == x_min_substrate || points_array[i].x == x_max_substrate || points_array[i].y == y_min_substrate || points_array[i].y == y_max_substrate)
		{

			fixed[i] = 1;
		}

		else if (points_array[i].z == z_max_rod || points_array[i].z == z_max_rod -1 || points_array[i].z == z_max_rod - 2)
		{

			fixed[i] = 3;
		}

		else
		{

			fixed[i] = 0;
		}
	}
}

void setup_FS()
{

	data_struct data_for_print_f;

	// empty_textfile();                          //for an empty sheet that has to be changed

	//read_textfile(data_for_print_f);            //old function

	read_textfile_HaBe(data_for_print_f);

	// units converter values (umrechnungen einheiten)
	// standard Einheiten: meter, sekunde, gramm, grad celsius,
	float_x length_Unit = data_for_print_f.length_Unit; // standard m = 1     mm = 0.001
	float_x time_Unit = data_for_print_f.time_Unit;		// standard s = 1      min = 60
	float_x mass_Unit = data_for_print_f.mass_Unit;		// standard kg = 1      g = 0.001
	float_x temp_Unit = data_for_print_f.temp_Unit;		// standard C° = 0     Kelvin K = - 273.15

	float_x pressure_Unit = mass_Unit / (time_Unit * time_Unit * length_Unit);
	float_x energy_Unit = length_Unit * length_Unit / (time_Unit * time_Unit);
	float_x power_Unit = mass_Unit * length_Unit * length_Unit / (time_Unit * time_Unit * time_Unit);
	float_x angle_Unit = data_for_print_f.angle_Unit;		// standard Bogenmaß rad = 1    Grad = (pii/180)

	// bevor die konstanten definiert werden können müssen erst mass scaling und distance bestimmt werden
	float_x dz = data_for_print_f.dz * length_Unit;
	float_x ms = data_for_print_f.ms;
	float_x hdx = data_for_print_f.hdx;
	float_x init_temp = data_for_print_f.init_temp + temp_Unit;
	global_Vsf = data_for_print_f.global_Vsf;
	global_dz = dz;

	float_x vel_x = data_for_print_f.vel_x * global_Vsf * length_Unit / time_Unit;
	float_x vel_y = data_for_print_f.vel_y * global_Vsf * length_Unit / time_Unit;
	float_x vel_z = data_for_print_f.vel_z * global_Vsf * length_Unit / time_Unit;

	float_x global_rod_vel = data_for_print_f.global_rod_vel * global_Vsf * length_Unit / time_Unit; // negativ da nach unten und mal Vsf für den Faktor
	float_x global_substrate_vel = data_for_print_f.global_substrate_vel * global_Vsf * length_Unit / time_Unit;
	float_x global_wz = data_for_print_f.global_wz * revolution_to_rad * global_Vsf / time_Unit; // Winkelgeschwindigkeit (rad/s)
	glm::vec3 w(0.0, 0.0, global_wz);

	int step = 0;						 // Anfangsposition
	global_time_final = data_for_print_f.global_time_final / global_Vsf; // 0.7 s ramping

	// Substrate
	phys_constants phys_substrate = make_phys_constants(); // ein Objekt der konstanten erstmal nur erstellen
	trml_constants trml_substrate = make_trml_constants();
	corr_constants corr_substrate = make_corr_constants();
	joco_constants joco_substrate = make_joco_constants();

	phys_substrate.E = data_for_print_f.phys_substrate.E * pressure_Unit;
	phys_substrate.nu = data_for_print_f.phys_substrate.nu;
	phys_substrate.rho0 = data_for_print_f.phys_substrate.rho0 * ms * mass_Unit / (length_Unit * length_Unit * length_Unit);
	phys_substrate.G = phys_substrate.E / (2. * (1. + phys_substrate.nu));
	phys_substrate.K = 2.0 * phys_substrate.G * (1 + phys_substrate.nu) / (3 * (1 - 2 * phys_substrate.nu));
	phys_substrate.mass = dz * dz * dz * phys_substrate.rho0;

	joco_substrate.A = data_for_print_f.joco_substrate.A * pressure_Unit;
	joco_substrate.B = data_for_print_f.joco_substrate.B * pressure_Unit;
	joco_substrate.C = data_for_print_f.joco_substrate.C;
	joco_substrate.m = data_for_print_f.joco_substrate.m;
	joco_substrate.n = data_for_print_f.joco_substrate.n;
	joco_substrate.Tref = data_for_print_f.joco_substrate.Tref + temp_Unit;
	joco_substrate.Tmelt = data_for_print_f.joco_substrate.Tmelt + temp_Unit;
	joco_substrate.eps_dot_ref = data_for_print_f.joco_substrate.eps_dot_ref / time_Unit;
	joco_substrate.clamp_temp = data_for_print_f.joco_substrate.clamp_temp;

	trml_substrate.cp = (data_for_print_f.trml_substrate.cp / ms) * energy_Unit / mass_Unit; // wärmekapazität
	trml_substrate.tq = data_for_print_f.trml_substrate.tq;
	trml_substrate.eta = data_for_print_f.trml_substrate.eta;
	trml_substrate.k = data_for_print_f.trml_substrate.k * global_Vsf * power_Unit / length_Unit; // wärmeleitfähigkeit
	trml_substrate.alpha = trml_substrate.k / (phys_substrate.rho0 * trml_substrate.cp);
	trml_substrate.T_init = joco_substrate.Tref + temp_Unit; // referenztemperatur

	corr_substrate.alpha = data_for_print_f.corr_substrate.alpha;
	corr_substrate.beta = data_for_print_f.corr_substrate.beta;
	corr_substrate.eta = data_for_print_f.corr_substrate.eta;
	corr_substrate.xspheps = data_for_print_f.corr_substrate.xspheps;
	corr_substrate.stresseps = data_for_print_f.corr_substrate.stresseps;
	float_x h1 = 1. / (hdx * dz);
	float_x q = dz * h1;
	float_x fac = (M_1_PI)*h1 * h1 * h1;
	corr_substrate.wdeltap = fac * (1 - 1.5 * q * q * (1 - 0.5 * q));

	float_x heco_wp_to_air = data_for_print_f.heco_wp_to_air * global_Vsf * (power_Unit / (length_Unit * length_Unit));
	float_x heco_wp_to_metal = data_for_print_f.heco_wp_to_metal * global_Vsf * (power_Unit / (length_Unit * length_Unit));

	// Rod
	phys_constants phys_rod = make_phys_constants();
	joco_constants joco_rod = make_joco_constants();
	trml_constants trml_rod = make_trml_constants();
	corr_constants corr_rod = make_corr_constants();

	phys_rod.E = data_for_print_f.phys_rod.E * pressure_Unit;
	phys_rod.nu = data_for_print_f.phys_rod.nu;
	phys_rod.rho0 = data_for_print_f.phys_rod.rho0 * 1.0e-6 * ms * mass_Unit / (length_Unit * length_Unit * length_Unit);
	phys_rod.G = phys_rod.E / (2. * (1. + phys_rod.nu));
	phys_rod.K = 2.0 * phys_rod.G * (1 + phys_rod.nu) / (3 * (1 - 2 * phys_rod.nu));
	phys_rod.mass = dz * dz * dz * phys_rod.rho0;

	joco_rod.A = data_for_print_f.joco_rod.A * pressure_Unit;
	joco_rod.B = data_for_print_f.joco_rod.B * pressure_Unit;
	joco_rod.C = data_for_print_f.joco_rod.C;
	joco_rod.m = data_for_print_f.joco_rod.m;
	joco_rod.n = data_for_print_f.joco_rod.n;
	joco_rod.Tref = data_for_print_f.joco_rod.Tref + temp_Unit;
	joco_rod.Tmelt = data_for_print_f.joco_rod.Tmelt + temp_Unit;
	joco_rod.eps_dot_ref = data_for_print_f.joco_rod.eps_dot_ref / time_Unit;
	joco_rod.clamp_temp = data_for_print_f.joco_rod.clamp_temp;

	trml_rod.cp = (data_for_print_f.trml_rod.cp / ms) * energy_Unit / mass_Unit; // wärmekapazität
	trml_rod.tq = data_for_print_f.trml_rod.tq;
	trml_rod.eta = data_for_print_f.trml_rod.eta;
	trml_rod.k = data_for_print_f.trml_rod.k * global_Vsf * power_Unit / mass_Unit; // wärmeleitfähigkeit
	trml_rod.alpha = trml_rod.k / (phys_rod.rho0 * trml_rod.cp);
	trml_rod.T_init = joco_rod.Tref + temp_Unit; // referenztemperatur

	corr_rod.alpha = data_for_print_f.corr_rod.alpha;
	corr_rod.beta = data_for_print_f.corr_rod.beta;
	corr_rod.eta = data_for_print_f.corr_rod.eta;
	corr_rod.xspheps = data_for_print_f.corr_rod.xspheps;
	corr_rod.stresseps = data_for_print_f.corr_rod.stresseps;
	corr_rod.wdeltap = fac * (1 - 1.5 * q * q * (1 - 0.5 * q));

	// 2.3   substrate dimensionen
	const float_x substrate_width = data_for_print_f.substrate_width * length_Unit;
	const float_x substrate_length = data_for_print_f.substrate_length * length_Unit;
	const float_x substrate_thickness = data_for_print_f.substrate_thickness * length_Unit;
	const float_x rod_diameter = data_for_print_f.rod_diameter * length_Unit;
	const float_x rod_height = data_for_print_f.rod_height * length_Unit;

	// 2.4
	//float_x shift_x = substrate_length / 4.0;

	//mit shift soll der user die moeglichkeit haben die rod an einer bestimmten stelle zu starten
	//dabei gib er dem Abstand vom linken rand an Bsp: sub lentgh = 100 und er will bei 1/4 die rod starten dann gibt er 25 ein 
	float_x shift_x = data_for_print_f.substrate_length / 2 - data_for_print_f.shift_x;
	float_x shift_y = data_for_print_f.substrate_width / 2 - data_for_print_f.shift_y;
	float_x shift_z = 0;

	int nx = static_cast<int>(substrate_length / dz) + 1; // Partikel in x richtung
	int ny = static_cast<int>(substrate_width / dz) + 1;  // static cast da wir ja ganze zahlen bei einer anzahl brauchen

	// da ich nicht weiß wie viele Points ich brauche erstelle ich einen vector
	std::vector<Point> points_vector_substrate;
	std::vector<Point> points_vector_rod;

	// als nächstes muss ich stück für stück durch die breite und höhe des wp und der rod gehen um die punkte zu erschaffen
	// dafür erstelle ich eine variable die die aktuelle höhe in der schleife sein soll
	float_x height_points = 0;

	while (height_points <= substrate_thickness)
	{ // substrate Punkte

		// punkte ertellen für substrat
		generate_grid_points_substrate(nx, ny, dz, height_points, points_vector_substrate);
		height_points += dz; // Punkte darüber sollen im Abstand dz liegen
	}

	while (height_points <= substrate_thickness + rod_height)
	{ // rod Punkte

		// punkte erstellen für rod
		generate_grid_points_rod(rod_diameter, dz, height_points, points_vector_rod);
		height_points += dz; // Punkte darüber sollen im Abstand dz liegen
	}

	// shift substrate
	unsigned int n_substrate = points_vector_substrate.size();
	unsigned int n_rod = points_vector_rod.size();
	unsigned int n = n_substrate + n_rod;
	for (int i = 0; i < n_substrate; i++)  //if-abfrage is eig unnoetig
	{
		if (points_vector_substrate[i].z <= substrate_thickness)
		{
			points_vector_substrate[i].x += shift_x;
			points_vector_substrate[i].y += shift_y;
		}
	}

	std::vector<Point> combined_vector;
	// zuerst den substrate-Vektor einfügen
	combined_vector.insert(combined_vector.end(), points_vector_substrate.begin(), points_vector_substrate.end());
	// danach den rod-Vektor anhängen
	combined_vector.insert(combined_vector.end(), points_vector_rod.begin(), points_vector_rod.end());

	// 3.3 Anfangswerte als vtk file ausgeben
	float4_t points_array[n];
	float4_t *array_ptr = points_array;
	vector_in_array(array_ptr, combined_vector, n);

	// 4  minmalen und maximalen Wert von allen richtungen bestimmen
	float_x x_min_substrate = std::numeric_limits<float_x>::max();
	float_x y_min_substrate = std::numeric_limits<float_x>::max();
	float_x z_min_substrate = std::numeric_limits<float_x>::max();
	float_x x_max_substrate = std::numeric_limits<float_x>::min();
	float_x y_max_substrate = std::numeric_limits<float_x>::min();
	float_x z_max_substrate = std::numeric_limits<float_x>::min();

	float_x x_min_rod = std::numeric_limits<float_x>::max();
	float_x y_min_rod = std::numeric_limits<float_x>::max();
	float_x z_min_rod = std::numeric_limits<float_x>::max();
	float_x x_max_rod = std::numeric_limits<float_x>::min();
	float_x y_max_rod = std::numeric_limits<float_x>::min();
	float_x z_max_rod = std::numeric_limits<float_x>::min();

	// substrate min_max
	max_min(n_substrate, points_vector_substrate, x_min_substrate, y_min_substrate, z_min_substrate,
			x_max_substrate, y_max_substrate, z_max_substrate);
	// rod min_max
	max_min(n_rod, points_vector_rod, x_min_rod, y_min_rod, z_min_rod,
			x_max_rod, y_max_rod, z_max_rod);

	float4_t *pos = new float4_t[n];
	float4_t *vel = new float4_t[n];
	float_x *h = new float_x[n];   // smoothing length
	float_x *rho = new float_x[n]; // density              trennen in rod und subtrate
	float_x *T = new float_x[n];   // trennen in rod und subtrate
	int *tool_p = new int[n];
	int *fixed = new int[n];

	// 6.2
	find_fixed(fixed, points_array, n, x_min_substrate, y_min_substrate,
	z_min_substrate, x_max_substrate, y_max_substrate, z_max_rod);

	// 6.3
	for (int i = 0; i < n; i++)
	{

		if (i < n_substrate)
		{

			tool_p[i] = 1;
			rho[i] = phys_substrate.rho0;
		}
		else
		{

			tool_p[i] = 0;
			rho[i] = phys_rod.rho0;
		}

		pos[i].x = points_array[i].x;
		pos[i].y = points_array[i].y;
		pos[i].z = points_array[i].z;
		T[i] = init_temp;
		vel[i].x = vel_x;
		vel[i].y = vel_y;
		vel[i].z = vel_z;
		h[i] = hdx;
		T[i] = init_temp;
	}

	// bounding box
	vec3_t bbmin;
	bbmin.x = x_min_substrate - dz; // minimaler x wert der bounding box
	bbmin.y = y_min_substrate - dz;
	bbmin.z = z_min_substrate - dz;

	vec3_t bbmax;
	bbmax.x = x_max_substrate + dz;
	bbmax.y = y_max_substrate + dz;
	bbmax.z = z_max_rod + dz;
	vtk_writer_write_blanking(bbmin, bbmax, step);
	vtk_writer_write(n, points_array, step, rho, vel, fixed, tool_p);

	float_x max_vel = w.z * (rod_diameter / 2.0);
	float_x c0_substrate = sqrt(phys_substrate.K / phys_substrate.rho0);
	float_x c0_rod = sqrt(phys_rod.K / phys_rod.rho0);
	float_x c0 = std::max(c0_substrate, c0_rod);
	const float_x CFL = data_for_print_f.CFl;
	float_x delta_t_max = CFL * hdx * dz / (sqrt(max_vel) + c0);
	global_time_dt = 0.5 * delta_t_max;

	delete[] pos;
	delete[] vel;
	delete[] h;
	delete[] rho;
	delete[] T;
	delete[] tool_p;
	delete[] fixed; //*/

	return;
}
