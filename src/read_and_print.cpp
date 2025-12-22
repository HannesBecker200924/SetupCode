
#include"read_and_print.h"

const std::string filename = "Datasheet.txt";

void empty_textfile(){

    std::ofstream file(filename);  //file erstellen

    if(!file){

        std::cerr << "The file couldn't be created.\n";
        
        return;
    }

    //file << "" << << "\n";
    file << "Datasheet\n";
    file << "\n";
    file << "Units:\n";
    file << "\n";
    file << "Length unit: " << "\n";
    file << "Time unit: " << "\n";
    file << "Mass unit: " << "\n";
    file << "Temperature unit: " << "\n";
    file << "Pressure unit: " << "\n";
    file << "Energy unit: " << "\n";
    file << "Power unit: " << "\n";
    file << "Angle unit: " << "\n";
    file << "\n";
    file << "Point distanvce: " << "\n";
    file << "Mass scaling: " << "\n";
    file << "Smoothing length: " << "\n";
    file << "Velocity scale factor: " << "\n";
    //file << "Global Distance: " << "\n";
    file << "\n";
    file << "Velocitys:\n";
    file << "\n";
    file << "Velocity in x-direction: " << "\n";
    file << "Velocity in y-direction: " << "\n";
    file << "Velocity in z-irection: " << "\n";
    file << "Rod velocity: " << "\n";
    file << "Subtrate velocity: " << "\n";
    file << "Angular velocity: " << "\n";
    //file << "Velocity vector x" << "\n";
    //file << "Velocity vector y" << "\n";
    //file << "Velocity vector z" << "\n";
    file << "\n";

    file << "Constants for the substrate:\n";
    file << "\n";

    file << "Young's modulus: " << "\n";
    file << "Poission's ratio: " << "\n";
    file << "Reference density: " << "\n";
    file << "Shear modulus: " << "\n";
    file << "Bulk modululs: " << "\n";
    file << "Particle mass: " << "\n";
    file << "\n";

    file << "Yield stress (A parameter): " << "\n";
    file << "Hardening modulus: " << "\n";
    file << "Strain rate sensitivity coefficient: " << "\n";
    file << "Thermal softening exponent: " << "\n";
    file << "Strain hardening exponent: " << "\n";
    file << "Reference temperature: " << "\n";
    file << "Melting temperature: " << "\n";
    file << "Reference strain rate: " << "\n";
    file << "Temperature clamping flag: " << "\n";
    file << "\n";

    file << "Specific heat capacity: " << "\n";
    file << "Taylor–Quinney coefficient: " << "\n";
    file << "Thermal efficiency: " << "\n";
    file << "Thermal conductivity: " << "\n";
    file << "Thermal diffusivity: " << "\n";
    file << "Initial temperature: " << "\n";
    file << "\n";

    file << "Artificial viscosity coefficient: " << "\n";
    file << "Artificial viscosity coefficient: " << "\n";
    file << "Viscosity regularization parameter: " << "\n";
    file << "XSPH correction factor: " << "\n";
    file << "Stress regularization parameter: " << "\n";
    //file << "Inverse smoothing length factor: " << "\n";
    //file << "Normalized distance: " << "\n";
    //file << "Kernel normalization factor: " "\n";
    file << "Kernel weight (delta approximation): " << "\n";
    file << "\n";
    
    file << "Constants for the rod:\n";
    file << "\n";

    file << "Young's modulus: " << "\n";
    file << "Poission's ratio: " << "\n";
    file << "Reference density: " << "\n";
    file << "Shear modulus: " << "\n";
    file << "Bulk modululs: " << "\n";
    file << "Particle mass: " << "\n";
    file << "\n";

    file << "Yield stress (A parameter): " << "\n";
    file << "Hardening modulus: " << "\n";
    file << "Strain rate sensitivity coefficient: " << "\n";
    file << "Thermal softening exponent: " << "\n";
    file << "Strain hardening exponent: " << "\n";
    file << "Reference temperature: " << "\n";
    file << "Melting temperature: " << "\n";
    file << "Reference strain rate: " << "\n";
    file << "Temperature clamping flag: " << "\n";
    file << "\n";

    file << "Specific heat capacity: " << "\n";
    file << "Taylor–Quinney coefficient: " << "\n";
    file << "Thermal efficiency: " << "\n";
    file << "Thermal conductivity: " << "\n";
    file << "Thermal diffusivity: " << "\n";
    file << "Initial temperature: " << "\n";
    file << "\n";

    file << "Artificial viscosity coefficient: " << "\n";
    file << "Artificial viscosity coefficient: " << "\n";
    file << "Viscosity regularization parameter: " << "\n";
    file << "XSPH correction factor: " << "\n";
    file << "Stress regularization parameter: " << "\n";
    file << "Kernel weight (delta approximation): " << "\n";
    file << "\n";

    file << "Workpiece dimensions:\n";
    file << "\n"; 
    file << "Substrate width: " << "\n";
    file << "Substrate lentgh: " << "\n";
    file << "Substrate thickness: " << "\n";
    file << "Rod diameter: " << "\n";
    file << "Rod height: "<< "\n";
    file << "Shift in x-direction: " << "\n";
    file << "Shift in y-direction: " << "\n";
    file << "Shift in z-direction: " << "\n";
    file << "Courant–Friedrichs–Lewy (condition): " << "\n";
    file << "\n";

    file.close();
}

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
   float_x& CFl){

    std::ofstream file(filename);

    if(!file){

        std::cerr << "The file couldn't be created.\n";
        
        return;
    }

    //file << "" << << "\n";
    file << "Datasheet\n";
    file << "\n";
    file << "Units:\n";
    file << "\n";
    file << "length Unit: " << length_Unit << "\n";
    file << "Time Unit: " << time_Unit << "\n";
    file << "Mass Unit: " << mass_Unit << "\n";
    file << "Temperature Unit: " << temp_Unit << "\n";
    file << "Pressure Unit: " << pressure_Unit << "\n";
    file << "Energy Unit" << energy_Unit << "\n";
    file << "" << << "\n";



    return;
}*/

void print_to_textfile(data_struct data_for_print_f){

    std::ofstream file(filename);  //file erstellen

    if(!file){

        std::cerr << "The file couldn't be created.\n";
        
        return;
    }

    //file << "" << << "\n";
    file << "Datasheet\n";
    file << "\n";
    file << "Units:\n";
    file << "\n";
    file << "Length unit: " << data_for_print_f.length_Unit << "\n";
    file << "Time unit: " << data_for_print_f.time_Unit << "\n";
    file << "Mass unit: " << data_for_print_f.mass_Unit << "\n";
    file << "Temperature unit: " << data_for_print_f.temp_Unit << "\n";
    file << "Pressure unit: " << data_for_print_f.pressure_Unit << "\n";
    file << "Energy unit: " <<  data_for_print_f.energy_Unit << "\n";
    file << "Power unit: " << data_for_print_f.power_Unit << "\n";
    file << "Angle unit: " << data_for_print_f.angle_Unit << "\n";
    file << "\n";
    file << "Point distanvce: " << data_for_print_f.dz << "\n";
    file << "Mass scaling: " << data_for_print_f.ms << "\n";
    file << "Smoothing length: " << data_for_print_f.hdx << "\n";
    file << "Velocity scale factor: " << data_for_print_f.global_Vsf << "\n";
    //file << "Global Distance: " << data_for_print_f.global_dz << "\n";
    file << "\n";
    file << "Velocitys:\n";
    file << "\n";
    file << "Velocity in x-direction: " << data_for_print_f.vel_x << "\n";
    file << "Velocity in y-direction: " << data_for_print_f.vel_y << "\n";
    file << "Velocity in z-irection: " << data_for_print_f.vel_z << "\n";
    file << "Rod velocity: " << data_for_print_f.global_rod_vel << "\n";
    file << "Subtrate velocity: " << data_for_print_f.global_substrate_vel << "\n";
    file << "Angular velocity: " << data_for_print_f.global_wz << "\n";
    //file << "Velocity vector x" << data_for_print_f.w.x<< "\n";
    //file << "Velocity vector y" << data_for_print_f.w.y<< "\n";
    //file << "Velocity vector z" << data_for_print_f.w.z<< "\n";
    file << "\n";

    file << "Constants for the substrate:\n";
    file << "\n";

    file << "Young's modulus: " << data_for_print_f.phys_substrate.E << "\n";
    file << "Poission's ratio: " << data_for_print_f.phys_substrate.nu << "\n";
    file << "Reference density: " << data_for_print_f.phys_substrate.rho0 << "\n";
    file << "Shear modulus: " << data_for_print_f.phys_substrate.G << "\n";
    file << "Bulk modululs: " << data_for_print_f.phys_substrate.K << "\n";
    file << "Particle mass: " << data_for_print_f.phys_substrate.mass << "\n";
    file << "\n";

    file << "Yield stress (A parameter): " << data_for_print_f.joco_substrate.A << "\n";
    file << "Hardening modulus: " << data_for_print_f.joco_substrate.B << "\n";
    file << "Strain rate sensitivity coefficient: " << data_for_print_f.joco_substrate.C << "\n";
    file << "Thermal softening exponent: " << data_for_print_f.joco_substrate.m << "\n";
    file << "Strain hardening exponent: " << data_for_print_f.joco_substrate.n << "\n";
    file << "Reference temperature: " << data_for_print_f.joco_substrate.Tref << "\n";
    file << "Melting temperature: " << data_for_print_f.joco_substrate.Tmelt << "\n";
    file << "Reference strain rate: " << data_for_print_f.joco_substrate.eps_dot_ref << "\n";
    file << "Temperature clamping flag: " << data_for_print_f.joco_substrate.clamp_temp << "\n";
    file << "\n";

    file << "Specific heat capacity: " << data_for_print_f.trml_substrate.cp << "\n";
    file << "Taylor–Quinney coefficient: " << data_for_print_f.trml_substrate.tq << "\n";
    file << "Thermal efficiency: " << data_for_print_f.trml_substrate.eta << "\n";
    file << "Thermal conductivity: " << data_for_print_f.trml_substrate.k << "\n";
    file << "Thermal diffusivity: " << data_for_print_f.trml_substrate.alpha << "\n";
    file << "Initial temperature: " << data_for_print_f.trml_substrate.T_init << "\n";
    file << "\n";

    file << "Artificial viscosity coefficient: " << data_for_print_f.corr_substrate.alpha << "\n";
    file << "Artificial viscosity coefficient: " << data_for_print_f.corr_substrate.beta << "\n";
    file << "Viscosity regularization parameter: " << data_for_print_f.corr_substrate.eta << "\n";
    file << "XSPH correction factor: " << data_for_print_f.corr_substrate.xspheps << "\n";
    file << "Stress regularization parameter: " << data_for_print_f.corr_substrate.stresseps << "\n";
    //file << "Inverse smoothing length factor: " << data_for_print_f.h1 << "\n";
    //file << "Normalized distance: " << data_for_print_f.q << "\n";
    //file << "Kernel normalization factor: " << data_for_print_f.fac << "\n";
    file << "Kernel weight (delta approximation): " << data_for_print_f.corr_substrate.wdeltap << "\n";
    file << "\n";
    
    file << "Constants for the rod:\n";
    file << "\n";

    file << "Young's modulus: " << data_for_print_f.phys_rod.E << "\n";
    file << "Poission's ratio: " << data_for_print_f.phys_rod.nu << "\n";
    file << "Reference density: " << data_for_print_f.phys_rod.rho0 << "\n";
    file << "Shear modulus: " << data_for_print_f.phys_rod.G << "\n";
    file << "Bulk modululs: " << data_for_print_f.phys_rod.K << "\n";
    file << "Particle mass: " << data_for_print_f.phys_rod.mass << "\n";
    file << "\n";

    file << "Yield stress (A parameter): " << data_for_print_f.joco_rod.A << "\n";
    file << "Hardening modulus: " << data_for_print_f.joco_rod.B << "\n";
    file << "Strain rate sensitivity coefficient: " << data_for_print_f.joco_rod.C << "\n";
    file << "Thermal softening exponent: " << data_for_print_f.joco_rod.m << "\n";
    file << "Strain hardening exponent: " << data_for_print_f.joco_rod.n << "\n";
    file << "Reference temperature: " << data_for_print_f.joco_rod.Tref << "\n";
    file << "Melting temperature: " << data_for_print_f.joco_rod.Tmelt << "\n";
    file << "Reference strain rate: " << data_for_print_f.joco_rod.eps_dot_ref << "\n";
    file << "Temperature clamping flag: " << data_for_print_f.joco_rod.clamp_temp << "\n";
    file << "\n";

    file << "Specific heat capacity: " << data_for_print_f.trml_rod.cp << "\n";
    file << "Taylor–Quinney coefficient: " << data_for_print_f.trml_rod.tq << "\n";
    file << "Thermal efficiency: " << data_for_print_f.trml_rod.eta << "\n";
    file << "Thermal conductivity: " << data_for_print_f.trml_rod.k << "\n";
    file << "Thermal diffusivity: " << data_for_print_f.trml_rod.alpha << "\n";
    file << "Initial temperature: " << data_for_print_f.trml_rod.T_init << "\n";
    file << "\n";

    file << "Artificial viscosity coefficient: " << data_for_print_f.corr_rod.alpha << "\n";
    file << "Artificial viscosity coefficient: " << data_for_print_f.corr_rod.beta << "\n";
    file << "Viscosity regularization parameter: " << data_for_print_f.corr_rod.eta << "\n";
    file << "XSPH correction factor: " << data_for_print_f.corr_rod.xspheps << "\n";
    file << "Stress regularization parameter: " << data_for_print_f.corr_rod.stresseps << "\n";
    file << "Kernel weight (delta approximation): " << data_for_print_f.corr_rod.wdeltap << "\n";
    file << "\n";

    file << "Workpiece dimensions:\n";
    file << "\n"; 
    file << "Substrate width: " << data_for_print_f.substrate_width << "\n";
    file << "Substrate lentgh: " << data_for_print_f.substrate_length << "\n";
    file << "Substrate thickness: " << data_for_print_f.substrate_thickness << "\n";
    file << "Rod diameter: " << data_for_print_f.rod_diameter << "\n";
    file << "Rod height: " << data_for_print_f.rod_height<< "\n";
    file << "Shift in x-direction: " << data_for_print_f.shift_x << "\n";
    file << "Shift in y-direction: " << data_for_print_f.shift_y << "\n";
    file << "Shift in z-direction: " << data_for_print_f.shift_z << "\n";
    file << "Courant–Friedrichs–Lewy (condition): " << data_for_print_f.CFl << "\n";
    file << "\n";

    file.close();
};


void read_textfile(data_struct& data_for_print_f){

    std::string line;

    std::ifstream file(filename);

    for (int i = 0; i < 4; ++i) {    //skip to 5 fifth line
        std::getline(file, line);
    }

    std::getline(file, line);
    size_t pos = line.find(':');    //find sucht in der aktuellen zeile den ersten doppelpunkt
    if (pos != std::string::npos) { // wenn kein doppelpunkt gefunden wurde wird die zeile geskipped
        std::string value = line.substr(pos + 1);  //speichert alles nach dem : als neuer string
        data_for_print_f.length_Unit = float_x(std::stof(value));   //wandelt den string in float_x
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.time_Unit = float_x(std::stof(value));
    } 

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.mass_Unit = float_x(std::stof(value));
    }

















}