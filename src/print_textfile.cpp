
#include"print_textfile.h"


int print_to_textfile(float_x* length_Unit, float_x* time_Unit, float_x &mass_Unit, float_x &temp_Unit,
    float_x &pressure_Unit, float_x &energy_Unit, float_x &power_Unit, float_x &angle_Unit,
    float_x &dz, float_x &ms, float_x &hdx, float_x &global_Vsf, float_x &global_dz,
    float_x &global_rod_vel, float_x &global_substrate_vel, float_x &global_wz, glm::vec3 &w, 
    int &step, float_x &global_time_final,
    phys_constants phys_substrate,trml_constants trml_substrate,corr_constants corr_substrate,joco_constants joco_substrate,
    phys_constants& phys_rod, joco_constants& joco_rod, trml_constants& trml_rod, corr_constants& corr_rod,
   float_x &substrate_width, float_x &substrate_length, float_x &substrate_thickness, float_x &rod_diameter, float_x &rod_height,
   float_x& shift_x, float_x& shift_y, float_x& shift_z,
   float_x& CFl){

    const std::string filename = "Datasheet.txt";

    std::ofstream file(filename);

    if(!file){

        std::cerr << "The file couldn't be created.\n";
        
        return 1;
    }

    file << "Datasheet\n";
    file << "\n";
    file << "Units:\n";
    file << "\n";
    file << "length Unit: " << length_Unit << "\n";


    




















    return 0;
}