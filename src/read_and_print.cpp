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
    file << "Angle unit: " << "\n";
    file << "\n";
    file << "Point distance: " << "\n";
    file << "Mass scaling: " << "\n";
    file << "Smoothing length: " << "\n";
    file << "Initial temperature: " << "\n";
    file << "Velocity scale factor: " << "\n";
    file << "Process time: " << "\n";
    //file << "Global Distance: " << "\n";
    file << "\n";
    file << "Velocitys:\n";
    file << "\n";
    file << "Velocity in x-direction: " << "\n";
    file << "Velocity in y-direction: " << "\n";
    file << "Velocity in z-direction: " << "\n";
    file << "Rod velocity: " << "\n";
    file << "Subtrate velocity: " << "\n";
    file << "Angular velocity: " << "\n";
    //file << "Velocity vector x" << "\n";
    //file << "Velocity vector y" << "\n";
    //file << "Velocity vector z" << "\n";
    file << "\n";

    file << "Constants for the substrate:\n";
    file << "\n";

    file << "Young's modulus (substrate): " << "\n";
    file << "Poission's ratio (substrate): " << "\n";
    file << "Reference density (substrate): " << "\n";
    //file << "Shear modulus: " << "\n";
    //file << "Bulk modululs: " << "\n";
    //file << "Particle mass: " << "\n";
    file << "\n";

    file << "Yield stress (substrate): " << "\n";
    file << "Hardening modulus (substrate): " << "\n";
    file << "Strain rate sensitivity coefficient (substrate): " << "\n";
    file << "Thermal softening exponent (substrate): " << "\n";
    file << "Strain hardening exponent (substrate): " << "\n";
    file << "Reference temperature (substrate): " << "\n";
    file << "Melting temperature (substrate): " << "\n";
    file << "Reference strain rate (substrate): " << "\n";
    file << "Temperature clamping flag (substrate): " << "\n";
    file << "\n";

    file << "Specific heat capacity (substrate): " << "\n";
    file << "Taylor–Quinney coefficient (substrate): " << "\n";
    file << "Thermal efficiency (substrate): " << "\n";
    file << "Thermal conductivity (substrate): " << "\n";
    //file << "Thermal diffusivity: " << "\n";
    //file << "Initial temperature: " << "\n";
    file << "\n";

    file << "Artificial viscosity coefficient alpha (substrate): " << "\n";
    file << "Artificial viscosity coefficient beta (substrate): " << "\n";
    file << "Viscosity regularization parameter (substrate): " << "\n";
    file << "XSPH correction factor (substrate): " << "\n";
    file << "Stress regularization parameter (substrate): " << "\n";
    //file << "Inverse smoothing length factor: " << "\n";
    //file << "Normalized distance: " << "\n";
    //file << "Kernel normalization factor: " "\n";
    //file << "Kernel weight (delta approximation): " << "\n";
    file << "\n";
    file << "Heat convection workpiece to air: " << "\n";
    file << "Heat convection workpiece to metal: " << "\n";
    file << "\n";
    
    file << "Constants for the rod:\n";
    file << "\n";

    file << "Young's modulus (rod): " << "\n";
    file << "Poission's ratio (rod): " << "\n";
    file << "Reference density (rod): " << "\n";
    //file << "Shear modulus (rod): " << "\n";
    //file << "Bulk modululs (rod): " << "\n";
    //file << "Particle mass (rod): " << "\n";
    file << "\n";

    file << "Yield stress (rod): " << "\n";
    file << "Hardening modulus (rod): " << "\n";
    file << "Strain rate sensitivity coefficient (rod): " << "\n";
    file << "Thermal softening exponent (rod): " << "\n";
    file << "Strain hardening exponent (rod): " << "\n";
    file << "Reference temperature (rod): " << "\n";
    file << "Melting temperature (rod): " << "\n";
    file << "Reference strain rate (rod): " << "\n";
    file << "Temperature clamping flag (rod): " << "\n";
    file << "\n";

    file << "Specific heat capacity (rod): " << "\n";
    file << "Taylor–Quinney coefficient (rod): " << "\n";
    file << "Thermal efficiency (rod): " << "\n";
    file << "Thermal conductivity (rod): " << "\n";
    //file << "Thermal diffusivity (rod): " << "\n";
    //file << "Initial temperature (rod): " << "\n";
    file << "\n";

    file << "Artificial viscosity coefficient alpha (rod): " << "\n";
    file << "Artificial viscosity coefficient beta (rod): " << "\n";
    file << "Viscosity regularization parameter (rod): " << "\n";
    file << "XSPH correction factor (rod): " << "\n";
    file << "Stress regularization parameter (rod): " << "\n";
    file << "\n";

    file << "Workpiece dimensions:\n";
    file << "\n"; 
    file << "Substrate width: " << "\n";
    file << "Substrate length: " << "\n";
    file << "Substrate thickness: " << "\n";
    file << "Rod diameter: " << "\n";
    file << "Rod height: "<< "\n";
    file << "Shift in x-direction: " << "\n";
    file << "Shift in y-direction: " << "\n";
    //file << "Shift in z-direction: " << "\n";
    file << "Courant–Friedrichs–Lewy (condition): " << "\n";
    file << "\n";

    file.close();
}

/*void print_to_textfile(data_struct data_for_print_f){

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
    //file << "Shift in x-direction: " << data_for_print_f.shift_x << "\n";
    //file << "Shift in y-direction: " << data_for_print_f.shift_y << "\n";
    //file << "Shift in z-direction: " << data_for_print_f.shift_z << "\n";
    file << "Courant–Friedrichs–Lewy (condition): " << data_for_print_f.CFl << "\n";
    file << "\n";

    file.close();
};*/

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
        data_for_print_f.length_Unit = float_x(std::stod(value));   //wandelt den string in float_x
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.time_Unit = float_x(std::stod(value));
    } 

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.mass_Unit = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.temp_Unit = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.angle_Unit = float_x(std::stod(value));
    }

    std::getline(file, line);

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.dz = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.ms = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.hdx = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.init_temp = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.global_Vsf = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.global_time_final = float_x(std::stod(value));
    }

    for (int i = 0; i < 3; ++i) {
        std::getline(file, line);
    }

    //velocitys
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.vel_x = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.vel_y = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.vel_z = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.global_rod_vel = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.global_substrate_vel = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.global_wz = float_x(std::stod(value));
    }

    for (int i = 0; i < 3; ++i) {
        std::getline(file, line);
    }
    
    //constants substrate
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_substrate.E = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_substrate.nu = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_substrate.rho0 = float_x(std::stod(value));
    }

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_substrate.G = float_x(std::stod(value));
    }*/

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_substrate.K = float_x(std::stod(value));
    }*/

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_substrate.mass = float_x(std::stod(value));
    }*/
    
    std::getline(file,line);

    //joco
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.A = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.B = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.C = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.m = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.n = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.Tref = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.Tmelt = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.eps_dot_ref = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_substrate.clamp_temp = float_x(std::stod(value));
    }

    std::getline(file,line);

    //trml
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_substrate.cp = float_x(std::stod(value));
    }
    
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_substrate.tq = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_substrate.eta = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_substrate.k = float_x(std::stod(value));
    }

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_substrate.alpha = float_x(std::stod(value));
    }*/

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_substrate.T_init = float_x(std::stod(value));
    }*/

    std::getline(file,line);

    //corr
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_substrate.alpha = float_x(std::stod(value));
    }  

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_substrate.beta = float_x(std::stod(value));
    }
    
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_substrate.eta = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_substrate.xspheps = float_x(std::stod(value));
    }
    
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_substrate.stresseps = float_x(std::stod(value));
    }

    std::getline(file,line);

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.heco_wp_to_air= float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.heco_wp_to_metal = float_x(std::stod(value));
    }

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_substrate.wdeltap = float_x(std::stod(value));
    }*/

    for (int i = 0; i < 3; ++i) {
        std::getline(file, line);
    }

    //constants rod
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_rod.E = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_rod.nu = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_rod.rho0 = float_x(std::stod(value));
    }

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_rod.G = float_x(std::stod(value));
    }*/

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_rod.K = float_x(std::stod(value));
    }*/

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.phys_rod.mass = float_x(std::stod(value));
    }*/
    
    std::getline(file,line);

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.A = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.B = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.C = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.m = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.n = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.Tref = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.Tmelt = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.eps_dot_ref = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.joco_rod.clamp_temp = float_x(std::stod(value));
    }

    std::getline(file,line);

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_rod.cp = float_x(std::stod(value));
    }
    
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_rod.tq = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_rod.eta = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_rod.k = float_x(std::stod(value));
    }

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_rod.alpha = float_x(std::stod(value));
    }*/

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.trml_rod.T_init = float_x(std::stod(value));
    }*/

    std::getline(file,line);

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_rod.alpha = float_x(std::stod(value));
    }    

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_rod.beta = float_x(std::stod(value));
    }
    
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_rod.eta = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_rod.xspheps = float_x(std::stod(value));
    }
    
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_rod.stresseps = float_x(std::stod(value));
    }

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.corr_rod.wdeltap = float_x(std::stod(value));
    }*/

    for (int i = 0; i < 3; ++i) {
        std::getline(file, line);
    }

    //dimensions
    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.substrate_width = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.substrate_length = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.substrate_thickness = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.rod_diameter = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.rod_height = float_x(std::stod(value));
    }

    std::getline(file, line);    //shift
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.shift_x = float_x(std::stod(value));
    }

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.shift_y = float_x(std::stod(value));
    }

    /*std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.shift_z = float_x(std::stod(value));
    }*/

    std::getline(file, line);
    pos = line.find(':');
    if (pos != std::string::npos) {
        std::string value = line.substr(pos + 1);
        data_for_print_f.CFl = float_x(std::stod(value));
    }
    
    file.close();
}

void read_textfile_new(data_struct& data_for_print_f){

    int number_of_true_flags = 0;

    bool length_Unit_flag = false;           
	bool time_Unit_flag = false;
	bool mass_Unit_flag = false;
	bool temp_Unit_flag = false;
	bool angle_Unit_flag = false;

    bool dz_flag = false;
	bool ms_flag = false;
	bool hdx_flag = false;
	bool init_temp_flag = false;
	bool global_Vsf_flag = false;
	bool global_dz_flag = false;
	bool vel_x_flag = false;
	bool vel_y_flag = false;
	bool vel_z_flag = false;
	bool global_rod_vel_flag = false;
	bool global_substrate_vel_flag = false;
	bool global_wz_flag = false; 
	bool global_time_final_flag = false;

    bool phys_substrate_flag_E = false;
    bool phys_substrate_flag_nu = false;
    bool phys_substrate_flag_rho0 = false;

    bool joco_substrate_flag_A = false;
    bool joco_substrate_flag_B = false;
    bool joco_substrate_flag_C = false;
    bool joco_substrate_flag_m = false;
    bool joco_substrate_flag_n = false;
    bool joco_substrate_flag_Tref = false;
    bool joco_substrate_flag_Tmelt = false;
    bool joco_substrate_flag_eps_dot_ref = false;
    bool joco_substrate_flag_clamp_temp = false;

	bool trml_substrate_flag_cp = false;
    bool trml_substrate_flag_tq = false;
    bool trml_substrate_flag_eta = false;
    bool trml_substrate_flag_k = false;

	bool corr_substrate_flag_alpha = false;
    bool corr_substrate_flag_beta = false;
    bool corr_substrate_flag_eta = false;
    bool corr_substrate_flag_xspheps = false;
    bool corr_substrate_flag_stresseps = false;
    
    bool heco_wp_to_air_flag = false;
	bool heco_wp_to_metal_flag = false;

    bool phys_rod_flag_E = false;
    bool phys_rod_flag_nu = false;
    bool phys_rod_flag_rho0 = false;

    bool joco_rod_flag_A = false;
    bool joco_rod_flag_B = false;
    bool joco_rod_flag_C = false;
    bool joco_rod_flag_m = false;
    bool joco_rod_flag_n = false;
    bool joco_rod_flag_Tref = false;
    bool joco_rod_flag_Tmelt = false;
    bool joco_rod_flag_eps_dot_ref = false;
    bool joco_rod_flag_clamp_temp = false;

	bool trml_rod_flag_cp = false;
    bool trml_rod_flag_tq = false;
    bool trml_rod_flag_eta = false;
    bool trml_rod_flag_k = false;

	bool corr_rod_flag_alpha = false;
    bool corr_rod_flag_beta = false;
    bool corr_rod_flag_eta = false;
    bool corr_rod_flag_xspheps = false;
    bool corr_rod_flag_stresseps = false;

    bool substrate_width_flag = false;
	bool substrate_length_flag = false;
	bool substrate_thickness_flag = false;
	bool rod_diameter_flag = false;
	bool rod_height_flag = false;
    bool shift_x_flag = false;
	bool shift_y_flag = false;
	//bool shift_z_flag = false;
    bool CFl_flag = false;


    std::ifstream file(filename);
    std::string line;

    while(std::getline(file,line)) {
        
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
    
            std::string keyword = line.substr(0, pos);
            std::string value = line.substr(pos + 1);
    
            if (keyword == "Length unit"){

                data_for_print_f.length_Unit = double(std::stod(value));


                length_Unit_flag = true;

                number_of_true_flags += 1;
            }
            
            else if (keyword == "Time unit"){

                data_for_print_f.time_Unit = double(std::stod(value));


                time_Unit_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Mass unit"){

                data_for_print_f.mass_Unit = double(std::stod(value));


                mass_Unit_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Temperature unit"){

                data_for_print_f.temp_Unit = double(std::stod(value));


                temp_Unit_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Angle unit"){

                data_for_print_f.angle_Unit = double(std::stod(value));


                angle_Unit_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Point distance"){

                data_for_print_f.dz = double(std::stod(value));


                dz_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Mass scaling"){

                data_for_print_f.ms = double(std::stod(value));


                ms_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Smoothing length"){

                data_for_print_f.hdx = double(std::stod(value));


                hdx_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Initial temperature"){

                data_for_print_f.init_temp = double(std::stod(value));


                init_temp_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Velocity scale factor"){

                data_for_print_f.global_Vsf = double(std::stod(value));


                global_Vsf_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Process time"){

                data_for_print_f.global_time_final = double(std::stod(value));


                global_time_final_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Velocity in x-direction"){

                data_for_print_f.vel_x = double(std::stod(value));


                vel_x_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Velocity in y-direction"){

                data_for_print_f.vel_y = double(std::stod(value));


                vel_y_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Velocity in z-direction"){

                data_for_print_f.vel_z = double(std::stod(value));


                vel_z_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Rod velocity"){

                data_for_print_f.global_rod_vel = double(std::stod(value));


                global_rod_vel_flag = true;
                
                number_of_true_flags += 1;

            }

            else if (keyword == "Substrate velocity"){

                data_for_print_f.global_substrate_vel = double(std::stod(value));


                global_substrate_vel_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Angular velocity"){

                data_for_print_f.global_wz = double(std::stod(value));


                global_wz_flag = true;
                
                number_of_true_flags += 1;
            }

            //substrate constants
            //phys (substrate)

            else if (keyword == "Young's modulus (substrate)"){

                data_for_print_f.phys_substrate.E = double(std::stod(value));


                phys_substrate_flag_E = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Poission's ratio (substrate)"){

                data_for_print_f.phys_substrate.nu = double(std::stod(value));


                phys_rod_flag_nu = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Reference density (substrate)"){

                data_for_print_f.phys_substrate.rho0 = double(std::stod(value));


                phys_rod_flag_rho0 = true;
                
                number_of_true_flags += 1;
            }

            //joco (substrate)

            else if (keyword == "Yield stress (substrate)"){

                data_for_print_f.joco_substrate.A = double(std::stod(value));


                joco_rod_flag_A = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Hardening modulus (substrate)"){

                data_for_print_f.joco_substrate.B = double(std::stod(value));


                joco_rod_flag_B = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Strain rate sensitivity coefficient (substrate)"){

                data_for_print_f.joco_substrate.C = double(std::stod(value));


                joco_rod_flag_C = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Thermal softening exponent (substrate)"){

                data_for_print_f.joco_substrate.m = double(std::stod(value));


                joco_rod_flag_m = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Strain hardening exponent (substrate):"){

                data_for_print_f.joco_substrate.n = double(std::stod(value));


                joco_rod_flag_n = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Reference temperature (substrate)"){

                data_for_print_f.joco_substrate.Tref = double(std::stod(value));


                joco_rod_flag_Tref = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Melting temperature (substrate)"){

                data_for_print_f.joco_substrate.Tmelt = double(std::stod(value));


                joco_rod_flag_Tmelt = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Reference strain rate (substrate)"){

                data_for_print_f.joco_substrate.eps_dot_ref = double(std::stod(value));


                joco_rod_flag_eps_dot_ref = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Temperature clamping flag (substrate)"){

                data_for_print_f.joco_substrate.clamp_temp = double(std::stod(value));


                joco_rod_flag_clamp_temp = true;
                
                number_of_true_flags += 1;
            }

            //trml (substrate)

            else if (keyword == "Specific heat capacity (substrate)"){

                data_for_print_f.trml_substrate.cp = double(std::stod(value));


                trml_substrate_flag_cp = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Taylor–Quinney coefficient (substrate)"){

                data_for_print_f.trml_substrate.tq = double(std::stod(value));


                trml_substrate_flag_tq = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Thermal efficiency (substrate)"){

                data_for_print_f.trml_substrate.eta = double(std::stod(value));


                trml_substrate_flag_eta = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Thermal conductivity (substrate)"){

                data_for_print_f.trml_substrate.k = double(std::stod(value));


                trml_substrate_flag_k = true;
                 
                number_of_true_flags += 1;
            }

            //corr (substrate)

            else if (keyword == "Artificial viscosity coefficient alpha (substrate)"){

                data_for_print_f.corr_substrate.alpha = double(std::stod(value));


                corr_substrate_flag_alpha = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Artificial viscosity coefficient beta (substrate)"){

                data_for_print_f.corr_substrate.beta = double(std::stod(value));


                corr_substrate_flag_beta = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Viscosity regularization parameter (substrate)"){

                data_for_print_f.corr_substrate.eta = double(std::stod(value));


                corr_substrate_flag_eta = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "XSPH correction factor (substrate)"){

                data_for_print_f.corr_substrate.xspheps = double(std::stod(value));


                corr_substrate_flag_xspheps = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == ""){

                data_for_print_f.corr_substrate.stresseps = double(std::stod(value));


                corr_substrate_flag_stresseps = true;
                
                number_of_true_flags += 1;
            }

            //heat convection

            else if (keyword == "Heat convection workpiece to air"){

                data_for_print_f.heco_wp_to_air = double(std::stod(value));


                heco_wp_to_air_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Heat convection workpiece to metal"){

                data_for_print_f.heco_wp_to_metal = double(std::stod(value));


                heco_wp_to_metal_flag = true;
                
                number_of_true_flags += 1;
            }

            //rod constants
            //phys (rod)

            else if (keyword == "Young's modulus (rod)"){

                data_for_print_f.phys_rod.E = double(std::stod(value));


                phys_rod_flag_E = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Poission's ratio (rod)"){

                data_for_print_f.phys_rod.nu = double(std::stod(value));


                phys_rod_flag_nu = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Reference density (rod)"){

                data_for_print_f.phys_rod.rho0 = double(std::stod(value));


                phys_rod_flag_rho0 = true;
                
                number_of_true_flags += 1;
            }

            //joco (rod)

            else if (keyword == "Yield stress (rod)"){

                data_for_print_f.joco_rod.A = double(std::stod(value));


                joco_rod_flag_A = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Hardening modulus (rod)"){

                data_for_print_f.joco_rod.B = double(std::stod(value));


                joco_rod_flag_B = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Strain rate sensitivity coefficient (rod)"){

                data_for_print_f.joco_rod.C = double(std::stod(value));


                joco_rod_flag_C = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Thermal softening exponent (rod)"){

                data_for_print_f.joco_rod.m = double(std::stod(value));


                joco_rod_flag_m = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Strain hardening exponent (rod):"){

                data_for_print_f.joco_rod.n = double(std::stod(value));


                joco_rod_flag_n = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Reference temperature (rod)"){

                data_for_print_f.joco_rod.Tref = double(std::stod(value));


                joco_rod_flag_Tref = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Melting temperature (rod)"){

                data_for_print_f.joco_rod.Tmelt = double(std::stod(value));


                joco_rod_flag_Tmelt = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Reference strain rate (rod)"){

                data_for_print_f.joco_rod.eps_dot_ref = double(std::stod(value));


                joco_rod_flag_eps_dot_ref = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Temperature clamping flag (rod)"){

                data_for_print_f.joco_rod.clamp_temp = double(std::stod(value));


                joco_rod_flag_clamp_temp = true;
                
                number_of_true_flags += 1;
            }

            //trml (rod)

            else if (keyword == "Specific heat capacity (rod)"){

                data_for_print_f.trml_rod.cp = double(std::stod(value));


                trml_rod_flag_cp = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Taylor–Quinney coefficient (rod)"){

                data_for_print_f.trml_rod.tq = double(std::stod(value));


                trml_rod_flag_tq = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Thermal efficiency (rod)"){

                data_for_print_f.trml_rod.eta = double(std::stod(value));


                trml_rod_flag_eta = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Thermal conductivity (rod)"){

                data_for_print_f.trml_rod.k = double(std::stod(value));


                trml_rod_flag_k = true;
                 
                number_of_true_flags += 1;
            }

            //corr (rod)

            else if (keyword == "Artificial viscosity coefficient alpha (rod)"){

                data_for_print_f.corr_rod.alpha = double(std::stod(value));


                corr_rod_flag_alpha = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Artificial viscosity coefficient beta (rod)"){

                data_for_print_f.corr_rod.beta = double(std::stod(value));


                corr_rod_flag_beta = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Viscosity regularization parameter (rod)"){

                data_for_print_f.corr_rod.eta = double(std::stod(value));


                corr_rod_flag_eta = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "XSPH correction factor (rod)"){

                data_for_print_f.corr_rod.xspheps = double(std::stod(value));


                corr_rod_flag_xspheps = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == ""){

                data_for_print_f.corr_rod.stresseps = double(std::stod(value));


                corr_rod_flag_stresseps = true;
                
                number_of_true_flags += 1;
            }

            //workpiece dimensions

            else if (keyword == "Substrate width"){

                data_for_print_f.substrate_width = double(std::stod(value));


                substrate_width_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Substrate length"){

                data_for_print_f.substrate_length = double(std::stod(value));


                substrate_length_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Substrate thickness"){

                data_for_print_f.substrate_thickness = double(std::stod(value));


                substrate_thickness_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Rod diameter"){

                data_for_print_f.rod_diameter = double(std::stod(value));


                rod_diameter_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Rod height"){

                data_for_print_f.rod_height = double(std::stod(value));


                rod_height_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Shift in x_driection"){

                data_for_print_f.shift_x = double(std::stod(value));


                shift_x_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Shift in y_driection"){

                data_for_print_f.shift_y = double(std::stod(value));


                shift_y_flag = true;
                
                number_of_true_flags += 1;
            }

            else if (keyword == "Courant–Friedrichs–Lewy (condition)"){

                data_for_print_f.CFl = double(std::stod(value));


                CFl_flag = true;
                
                number_of_true_flags += 1;
            }

            /*else if (keyword == ""){

                data_for_print_f. = double(std::stod(value));


                 = true;
                 
                number_of_true_flags += 1;
            }*/
            
        }

    }

    std::cout << number_of_true_flags << " true flags" << std::endl;
    
    //number_of_true_flags should be 63 right now 

    if (number_of_true_flags != 63){

        printf("One or more values are missing:\n");
        printf("It should look like this:\n");
        printf("\n");
        printf("Length unit: 1\n");
        printf("\n");
    

        if(length_Unit_flag == false){
            printf("Copy in file: Length unit: add_your_value\n");
        }

        if(time_Unit_flag == false){
            printf("Copy in file: Time unit: add_your_value\n");
        }










        //hier weitermachen











        exit(0);
    }
    

    file.close();
}