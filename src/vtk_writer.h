#ifndef VTK_WRITER_H_
#define VTK_WRITER_H_

#include <stdio.h>
#include <math.h>
#include <numeric>
#include "types.h"
#include <vector>

void vtk_writer_write(int n, float4_t* h_pos, int step, float_x* h_rho, float4_t* h_vel, int* h_fixed, int* h_tool_p);
void vtk_writer_write_blanking(vec3_t bbmin, vec3_t bbmax, int step);

#endif /* VTK_WRITER_H_ */
