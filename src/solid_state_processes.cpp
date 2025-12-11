#include "solid_state_processes.h"

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

void max_min(int n, std::vector<Point> points_vector, float_x &x_min, float_x &y_min, float_x &z_min,
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

/*void Units(float_x& length_Unit){

	string Unit_abfrage;

	cout << "Unit?" << endl;
	cin >> Unit_abfrage;

	if(Unit_abfrage == "mm"){

		length_Unit = 1.;

	}
	else if(Unit_abfrage == "m"){


		length_Unit = 0.001;

	}



}*/

void find_fixed(int *fixed, float4_t *points_array, int n, float_x x_min_substrate,
float_x y_min_substrate, float_x z_min_substrate, float_x x_max_substrate, float_x y_max_substrate)
{

	for (int i = 0; i < n; i++)
	{

		if (points_array[i].x == x_min_substrate || points_array[i].x == x_max_substrate || points_array[i].y == y_min_substrate || points_array[i].y == y_max_substrate || points_array[i].z == z_min_substrate)
		{

			fixed[i] = 1;
		}

		else
		{

			fixed[i] = 0;
		}
	}
}

void setup_FS()
{
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

	// bevor die konstanten definiert werden können müssen erst mass scaling und distance bestimmt werden
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

	// Substrate
	phys_constants phys_substrate = make_phys_constants(); // ein Objekt der konstanten erstmal nur erstellen
	trml_constants trml_substrate = make_trml_constants();
	corr_constants corr_substrate = make_corr_constants();
	joco_constants joco_substrate = make_joco_constants();

	// Für das verwendete aluminium: AL5083H116
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

	// Rod
	phys_constants phys_rod = make_phys_constants();
	joco_constants joco_rod = make_joco_constants();
	trml_constants trml_rod = make_trml_constants();
	corr_constants corr_rod = make_corr_constants();

	// Für das verwendete aluminium: AL5083H116

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

	// 2.4
	float_x shift_x = substrate_length / 4.0;
	float_x shift_y;
	float_x shift_z;

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
	for (int i = 0; i < n_substrate; i++)
	{
		if (points_vector_substrate[i].z <= substrate_thickness)
		{
			points_vector_substrate[i].x += shift_x;
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

	/* cout << x_min_substrate << endl;
	cout << y_min_substrate << endl;
	cout << z_min_substrate << endl;
	cout << x_max_substrate << endl;
	cout << y_max_substrate << endl;
	cout << z_max_substrate << endl;

	cout << x_min_rod << endl;
	cout << y_min_rod << endl;
	cout << z_min_rod << endl;
	cout << x_max_rod << endl;
	cout << y_max_rod << endl;
	cout << z_max_rod << endl; */

	float4_t *pos = new float4_t[n];
	float4_t *vel = new float4_t[n];
	float_x *h = new float_x[n];   // smoothing length
	float_x *rho = new float_x[n]; // density              trennen in rod und subtrate 
	float_x *T = new float_x[n];   // trennen in rod und subtrate
	int *tool_p = new int[n];
	int *fixed = new int[n];

	// 6.2
	find_fixed(fixed, points_array, n, x_min_substrate, y_min_substrate,
			   z_min_substrate, x_max_substrate, y_max_substrate);

	// 6.3
	for (int i = 0; i < n; i++)
	{
		
		if (i < n_substrate)
		{

			tool_p[i] = 1;

		}
		else
		{

			tool_p[i] = 0;
		}

		pos[i].x = points_array[i].x;
		pos[i].y = points_array[i].y;
		pos[i].z = points_array[i].z;


		//vel hier



		h[i] = hdx;

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
	vtk_writer_write(n, points_array, step, fixed, tool_p);

	float_x max_vel = w.z * (rod_diameter / 2.0);
	float_x c0_substrate = sqrt(phys_substrate.K / phys_substrate.rho0);
	float_x c0_rod = sqrt(phys_rod.K / phys_rod.rho0);
	float_x c0 = std::max(c0_substrate, c0_rod);
	constexpr float_x CFL = 0.3;
	float_x delta_t_max = CFL * hdx * dz / (sqrt(max_vel) + c0);
	global_time_dt = 0.5 * delta_t_max;

	delete[] pos;
	delete[] vel;
	delete[] h;
	delete[] rho;
	delete[] T;
	delete[] tool_p;
	delete[] fixed;
}
