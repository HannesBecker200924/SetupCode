#include <iostream>
#include <fstream>
#include "json.hpp"

struct fs_variables
{

    double length_unit;
    double time_unit;
    double mass_unit;
    double temperature_unit;
    double angle_unit;

    double sub_width;
    double sub_length;
    double sub_thickness;
    double rod_height;
    double rod_diameter;

    double vx_sub;
    double vy_sub;
    double vz_sub;
    double rod_feed;
    double rpm;

    double E_sub;
    double nu_sub;
    double rho_sub;
    double jc_A_sub;
    double jc_B_sub;
    double jc_C_sub;
    double jc_m_sub;
    double jc_n_sub;
    double jc_Tref_sub;
    double jc_Tmelt_sub;
    double jc_epsdot_sub;
    double c_sub;
    double tq_sub;
    double therm_eff_sub;
    double k_sub;

    double E_rod;
    double nu_rod;
    double rho_rod;
    double jc_A_rod;
    double jc_B_rod;
    double jc_C_rod;
    double jc_m_rod;
    double jc_n_rod;
    double jc_Tref_rod;
    double jc_Tmelt_rod;
    double jc_epsdot_rod;
    double c_rod;
    double tq_rod;
    double therm_eff_rod;
    double k_rod;

    double init_particle_dist;
    double mass_scale;
    double smooth_len;
    double vel_scale;
    double proc_time;

    double alpha_sph;
    double beta_sph;
    double eta_sph;
    double xsph_corr;
    double stress_reg;

    double h_air;
    double h_metal;

    double shift_x;
    double shift_y;
};

void read_json(fs_variables &variables)
{

    std::ifstream file("FS_values.json");

    if (!file.is_open())
    {
        std::cerr << "JSON Datei konnte nicht geöffnet werden!\n";
        return;
    }

    nlohmann::json j;

    file >> j;

    //values for the units
    if (j["units"]["length_unit"].get<std::string>() == "m")
    {

        variables.length_unit = 1;
    }
    else if (j["units"]["length_unit"].get<std::string>() == "cm")
    {

        variables.length_unit = 100;
    }
    else if (j["units"]["length_unit"].get<std::string>() == "mm")
    {

        variables.length_unit = 1000;
    }

    if (j["units"]["time_unit"].get<std::string>() == "s")
    {

        variables.time_unit = 1;
    }
    else if (j["units"]["time_unit"].get<std::string>() == "ms")
    {

        variables.time_unit = 1000;
    }
    else if (j["units"]["time_unit"].get<std::string>() == "min")
    {

        variables.time_unit = 0.0166667;
    }

    if (j["units"]["mass_unit"].get<std::string>() == "kg")
    {

        variables.mass_unit = 1;
    }
    else if (j["units"]["mass_unit"].get<std::string>() == "g")
    {

        variables.mass_unit = 1000;
    }

    if (j["units"]["temperature_unit"].get<std::string>() == "°C")
    {

        variables.temperature_unit = 1;
    }
    else if (j["units"]["temperature_unit"].get<std::string>() == "K")
    {

        variables.temperature_unit = 273.15;
    }

    if (j["units"]["angle_unit"].get<std::string>() == "degree")
    {

        variables.angle_unit = 1;
    }
    else if (j["units"]["angle_unit"].get<std::string>() == "rad")
    {

        variables.angle_unit = 0.0174533;
    }
    
    //values for the rest variables
    variables.sub_width = j["sub_rod_dimensions"]["sub_width"].get<double>();
    variables.sub_length = j["sub_rod_dimensions"]["sub_length"].get<double>();
    variables.sub_thickness = j["sub_rod_dimensions"]["sub_thickness"].get<double>();
    variables.rod_height = j["sub_rod_dimensions"]["rod_height"].get<double>();
    variables.rod_diameter = j["sub_rod_dimensions"]["rod_diameter"].get<double>();

    variables.vx_sub = j["Velocitys"]["vx_sub"].get<double>();
    variables.vy_sub = j["Velocitys"]["vy_sub"].get<double>();
    variables.vz_sub = j["Velocitys"]["vz_sub"].get<double>();
    variables.rod_feed = j["Velocitys"]["rod_feed"].get<double>();
    variables.rpm = j["Velocitys"]["rpm"].get<double>();

    variables.E_sub = j["constants-substrate"]["E_sub"].get<double>();
    variables.nu_sub = j["constants-substrate"]["nu_sub"].get<double>();
    variables.rho_sub = j["constants-substrate"]["rho_sub"].get<double>();
    variables.jc_A_sub = j["constants-substrate"]["jc_A_sub"].get<double>();
    variables.jc_B_sub = j["constants-substrate"]["jc_B_sub"].get<double>();
    variables.jc_C_sub = j["constants-substrate"]["jc_C_sub"].get<double>();
    variables.jc_m_sub = j["constants-substrate"]["jc_m_sub"].get<double>();
    variables.jc_n_sub = j["constants-substrate"]["jc_n_sub"].get<double>();
    variables.jc_Tref_sub = j["constants-substrate"]["jc_Tref_sub"].get<double>();
    variables.jc_Tmelt_sub = j["constants-substrate"]["jc_Tmelt_sub"].get<double>();
    variables.jc_epsdot_sub = j["constants-substrate"]["jc_epsdot_sub"].get<double>();
    variables.c_sub = j["constants-substrate"]["c_sub"].get<double>();
    variables.tq_sub = j["constants-substrate"]["tq_sub"].get<double>();
    variables.therm_eff_sub = j["constants-substrate"]["therm_eff_sub"].get<double>();
    variables.k_sub = j["constants-substrate"]["k_sub"].get<double>();

    variables.E_rod = j["constants-rod"]["E_rod"].get<double>();
    variables.nu_rod = j["constants-rod"]["nu_rod"].get<double>();
    variables.rho_rod = j["constants-rod"]["rho_rod"].get<double>();
    variables.jc_A_rod = j["constants-rod"]["jc_A_rod"].get<double>();
    variables.jc_B_rod = j["constants-rod"]["jc_B_rod"].get<double>();
    variables.jc_C_rod = j["constants-rod"]["jc_C_rod"].get<double>();
    variables.jc_m_rod = j["constants-rod"]["jc_m_rod"].get<double>();
    variables.jc_n_rod = j["constants-rod"]["jc_n_rod"].get<double>();
    variables.jc_Tref_rod = j["constants-rod"]["jc_Tref_rod"].get<double>();
    variables.jc_Tmelt_rod = j["constants-rod"]["jc_Tmelt_rod"].get<double>();
    variables.jc_epsdot_rod = j["constants-rod"]["jc_epsdot_rod"].get<double>();
    variables.c_rod = j["constants-rod"]["c_rod"].get<double>();
    variables.tq_rod = j["constants-rod"]["tq_rod"].get<double>();
    variables.therm_eff_rod = j["constants-rod"]["therm_eff_rod"].get<double>();
    variables.k_rod = j["constants-rod"]["k_rod"].get<double>();

    variables.init_particle_dist = j["global_constants"]["init_particle_dist"].get<double>();
    variables.mass_scale = j["global_constants"]["mass_scale"].get<double>();
    variables.smooth_len = j["global_constants"]["smooth_len"].get<double>();
    variables.vel_scale = j["global_constants"]["vel_scale"].get<double>();
    variables.proc_time = j["global_constants"]["proc_time"].get<double>();

    variables.alpha_sph = j["corr_parameters"]["alpha_sph"].get<double>();
    variables.beta_sph = j["corr_parameters"]["beta_sph"].get<double>();
    variables.eta_sph = j["corr_parameters"]["eta_sph"].get<double>();
    variables.xsph_corr = j["corr_parameters"]["xsph_corr"].get<double>();
    variables.stress_reg = j["corr_parameters"]["stress_reg"].get<double>();

    variables.h_air = j["heat_convection"]["h_air"].get<double>();
    variables.h_metal = j["heat_convection"]["h_metal"].get<double>();

    variables.shift_x = j["centering_substrate"]["shift_x"].get<double>();
    variables.shift_y = j["centering_substrate"]["shift_y"].get<double>();

    file.close();
}

int main()
{

    fs_variables variables;

    read_json(variables);

    return 0;
}
