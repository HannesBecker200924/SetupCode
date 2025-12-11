#ifndef TYPES_H_
#define TYPES_H_
#include <glm/glm.hpp>

#define USE_DOUBLE

#ifdef USE_DOUBLE
//built in vector types
#define float_x double
#define float2_t glm::dvec2
#define float3_t glm::dvec3
#define float4_t glm::dvec4

// texture types and texture fetching
#define float_tex_t  int2
#define float2_tex_t int4
#define float4_tex_t int4

#define make_float2_t glm::dvec2
#define make_float3_t glm::dvec3
#define make_float4_t glm::dvec4

#define texfetch1 fetch_double
#define texfetch2 fetch_double2
#define texfetch4 fetch_double2

// glm types
#define mat3x3_t glm::dmat3x3
#define vec2_t glm::dvec2
#define vec3_t glm::dvec3

// mathematic functions
#define sqrt_t sqrt
#define exp_t exp
#define log_t log

#else

//-------------------------------------------------------------

// built in vector types
#define float_x float
#define float2_t float2
#define float3_t float3
#define float4_t float4

#define make_float2_t make_float2
#define make_float3_t make_float3
#define make_float4_t make_float4

// texture types
#define float_tex_t  float
#define float2_tex_t float2
#define float4_tex_t float4

#define texfetch1 tex1Dfetch
#define texfetch2 tex1Dfetch
#define texfetch4 tex1Dfetch

// glm types
#define mat3x3_t glm::mat3x3
#define vec2_t glm::vec2
#define vec3_t glm::vec3

// mathematic functions
#define sqrt_t sqrtf
#define exp_t expf
#define log_t logf

#endif

#define CSPM

//#define Thermal_Conduction_Brookshaw
#define Thermal_Conduction_PSE

// Customization of CUDA- Blocksizes
#define BLOCK_SIZE 256

#endif /* TYPES_H_ */
