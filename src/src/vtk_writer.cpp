#include "vtk_writer.h"
#include "types.h"

void vtk_writer_write_blanking(vec3_t bbmin, vec3_t bbmax, int step)
{
	char buf[256];
	sprintf(buf, "results/vtk_bbox_%09d.vtk", step);
	FILE *fp = fopen(buf, "w+");

	const int num_face = 6;
	const int num_corner = 8;

	// generate 8 corners of tool bbox
	vec3_t c000(bbmin.x, bbmin.y, bbmin.z);
	vec3_t c100(bbmax.x, bbmin.y, bbmin.z);
	vec3_t c110(bbmax.x, bbmax.y, bbmin.z);
	vec3_t c010(bbmin.x, bbmax.y, bbmin.z);

	vec3_t c001(bbmin.x, bbmin.y, bbmax.z);
	vec3_t c101(bbmax.x, bbmin.y, bbmax.z);
	vec3_t c111(bbmax.x, bbmax.y, bbmax.z);
	vec3_t c011(bbmin.x, bbmax.y, bbmax.z);

	std::vector<vec3_t> corners({c000, c100, c110, c010, c001, c101, c111, c011});

	fprintf(fp, "# vtk DataFile Version 2.0\n");
	fprintf(fp, "mfree iwf\n");
	fprintf(fp, "ASCII\n");
	fprintf(fp, "\n");

	fprintf(fp, "DATASET UNSTRUCTURED_GRID\n"); // Particle positions
	fprintf(fp, "POINTS %d float\n", num_corner);

	for (auto &it : corners)
	{
		fprintf(fp, "%f %f %f\n", it.x, it.y, it.z);
	}
	fprintf(fp, "\n");

	fprintf(fp, "CELL_TYPES %d\n", num_face);
	for (int i = 0; i < num_face; i++)
	{
		fprintf(fp, "%d\n", 9);
	}
	fprintf(fp, "\n");

	fprintf(fp, "CELLS %d %d\n", num_face, 5 * num_face);
	fprintf(fp, "4 %d %d %d %d\n", 0, 1, 2, 3);
	fprintf(fp, "4 %d %d %d %d\n", 0, 1, 5, 4);
	fprintf(fp, "4 %d %d %d %d\n", 1, 2, 6, 5);
	fprintf(fp, "4 %d %d %d %d\n", 0, 3, 7, 4);
	fprintf(fp, "4 %d %d %d %d\n", 3, 2, 6, 7);
	fprintf(fp, "4 %d %d %d %d\n", 4, 5, 6, 7);

	fprintf(fp, "\n");

	fclose(fp);
}

void vtk_writer_write(int n, float4_t* h_pos, int step, int* h_fixed, int* h_tool_p)

{

	char buf[256];
	sprintf(buf, "results/vtk_out_%09d.vtk", step);
	FILE *fp = fopen(buf, "w+");

	fprintf(fp, "# vtk DataFile Version 2.0\n");
	fprintf(fp, "mfree iwf\n");
	fprintf(fp, "ASCII\n");
	fprintf(fp, "\n");

	fprintf(fp, "DATASET UNSTRUCTURED_GRID\n"); // Particle positions
	fprintf(fp, "POINTS %d float\n", n);
	for (unsigned int i = 0; i < n; i++)
	{
		fprintf(fp, "%f %f %f\n", h_pos[i].x, h_pos[i].y, h_pos[i].z);
	}
	fprintf(fp, "\n");

	fprintf(fp, "CELLS %d %d\n", n, 2 * n);
	for (unsigned int i = 0; i < n; i++)
	{
		fprintf(fp, "%d %d\n", 1, i);
	}
	fprintf(fp, "\n");

	fprintf(fp, "CELL_TYPES %d\n", n);
	for (unsigned int i = 0; i < n; i++)
	{
		fprintf(fp, "%d\n", 1);
	}
	fprintf(fp, "\n");

	 // You will use the following to write additional data per point
	 // you will need to pass the relevant arrays to this function

	fprintf(fp, "POINT_DATA %d\n", n);/*
	fprintf(fp, "SCALARS density float 1\n"); 
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f\n", h_rho[i]);
	}
	fprintf(fp, "\n");

	fprintf(fp, "SCALARS Joined float 1\n"); 
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f\n", h_vel[i].w);
	}
	fprintf(fp, "\n");

	fprintf(fp, "VECTORS velocity float \n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f %f %f\n", h_vel[i].x, h_vel[i].y, h_vel[i].z);
	}
	fprintf(fp, "\n");

	fprintf(fp, "VECTORS fc float \n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f %f %f\n", h_contact[i].x, h_contact[i].y, h_contact[i].z);
	}
	fprintf(fp, "\n");

	fprintf(fp, "VECTORS normal float \n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f %f %f\n", h_normal[i].x, h_normal[i].y, h_normal[i].z);
	}
	fprintf(fp, "\n");

	fprintf(fp, "SCALARS contact float 1\n"); // Current particle density
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f\n", glm::length(vec3_t(h_contact[i].x, h_contact[i].y, h_contact[i].z)) > 0. ? 1. : 0.);
	}
	fprintf(fp, "\n");

	fprintf(fp, "SCALARS Temperature float 1\n"); // Current particle temperature
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f\n", h_T[i]);
	}
	fprintf(fp, "\n");*/

	
	fprintf(fp, "SCALARS Fixed float 1\n");
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%d\n", h_fixed[i]);
	}
	fprintf(fp, "\n");


	fprintf(fp, "SCALARS Tool float 1\n");
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%d\n", h_tool_p[i]);
	}
	fprintf(fp, "\n");

	/*fprintf(fp, "SCALARS idx float 1\n");
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f\n", h_pos[i].w);
	}
	fprintf(fp, "\n");

	fprintf(fp, "SCALARS EquivAccumPlasticStrain float 1\n"); // equivalent accumulated plastic strain
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		fprintf(fp, "%f\n", h_eps[i]);
	}
	fprintf(fp, "\n");

	fprintf(fp, "SCALARS Svm float 1\n");
	fprintf(fp, "LOOKUP_TABLE default\n");
	for (unsigned int i = 0; i < n; i++)
	{
		
		double sxx = h_S[i][0][0] - h_p[i];
		double sxy = h_S[i][0][1];
		double sxz = h_S[i][0][2];
		double syy = h_S[i][1][1] - h_p[i];
		double syz = h_S[i][1][2];
		double szz = h_S[i][2][2] - h_p[i];

		double svm2 = (sxx * sxx + syy * syy + szz * szz) - sxx * syy - sxx * szz - syy * szz + 3.0 * (sxy * sxy + syz * syz + sxz * sxz);
		double svm = (svm2 > 0) ? sqrt(svm2) : 0.;
		fprintf(fp, "%f\n", svm);
	}
	fprintf(fp, "\n"); */

	fclose(fp);
}
