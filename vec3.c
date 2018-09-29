/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"

#define MIN_FLOAT 1.0e-7

inline void glmc_vec3f_from_2f(vec3f dest, vec2f src_a, float src_b)
{
	dest[0] = src_a[0];
	dest[1] = src_a[1];
	dest[2] = src_b; 
}
inline void glmc_vec3f_from_4f(vec3f dest, vec4f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}

inline void glmc_vec3f_copy(vec3f dest, vec3f src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
}

inline float glmc_vec3f_sqrlength(vec3f vec)
{
	float vec3f_sqrlength;
	vec3f_sqrlength = vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
	return vec3f_sqrlength;
}
inline float glmc_vec3f_length(vec3f vec)
{
	return sqrtf(glmc_vec3f_sqrlength(vec));
}

inline int glmc_vec3f_is_normalized(vec3f src)
{
	if(fabs(glmc_vec3f_sqrlength(src) - 1.0f) <= MIN_FLOAT)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
inline void glmc_vec3f_normlize(vec3f dest, vec3f src)
{
	if(glmc_vec3f_is_normalized(src) == 1)
	{
		dest[0] = src[0];
		dest[1] = src[1];
		dest[2] = src[2];
	}
	else
	{
		float vec3f_length_inv;
		vec3f_length_inv = 1.0f/(glmc_vec3f_length(src));
		dest[0] = src[0]*vec3f_length_inv;
		dest[1] = src[1]*vec3f_length_inv;
		dest[2] = src[2]*vec3f_length_inv;
	}
}
inline void glmc_vec3f_normlize_dest(vec3f src_dest)
{
	if(glmc_vec3f_is_normalized(src_dest) != 1)
	{
		float vec3f_length_inv;
		vec3f_length_inv = 1.0f/(glmc_vec3f_length(src_dest));
		src_dest[0] = src_dest[0]*vec3f_length_inv;
		src_dest[1] = src_dest[1]*vec3f_length_inv;
		src_dest[2] = src_dest[2]*vec3f_length_inv;
	}
}

inline void glmc_vec3f_add(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = src_a[0] + src_b[0];
	dest[1] = src_a[1] + src_b[1];
	dest[2] = src_a[2] + src_b[2];
}
inline void glmc_vec3f_add_dest(vec3f src_dest, vec3f src_b)
{
	src_dest[0] = src_dest[0] + src_b[0];
	src_dest[1] = src_dest[1] + src_b[1];
	src_dest[2] = src_dest[2] + src_b[2];
}

inline void glmc_vec3f_sub(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = src_a[0] - src_b[0];
	dest[1] = src_a[1] - src_b[1];
	dest[2] = src_a[2] - src_b[2];
}
inline void glmc_vec3f_sub_dest(vec3f src_dest, vec3f src_b)
{
	src_dest[0] = src_dest[0] - src_b[0];
	src_dest[1] = src_dest[1] - src_b[1];
	src_dest[2] = src_dest[2] - src_b[2];
}

inline void glmc_vec3f_mul(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = src_a[0] * src_b[0];
	dest[1] = src_a[1] * src_b[1];
	dest[2] = src_a[2] * src_b[2];
}
inline void glmc_vec3f_mul_dest(vec3f src_dest, vec3f src_b)
{
	src_dest[0] = src_dest[0] * src_b[0];
	src_dest[1] = src_dest[1] * src_b[1];
	src_dest[2] = src_dest[2] * src_b[2];
}
inline void glmc_vec3f_mul_s(vec3f dest, vec3f src_a, float src_b)
{
	dest[0] = src_a[0] * src_b;
	dest[1] = src_a[1] * src_b;
	dest[2] = src_a[2] * src_b;
}

inline void glmc_vec3f_div(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = src_a[0] / src_b[0];
	dest[1] = src_a[1] / src_b[1];
	dest[2] = src_a[2] / src_b[2];
}
inline void glmc_vec3f_div_dest(vec3f src_dest, vec3f src_b)
{
	src_dest[0] = src_dest[0] / src_b[0];
	src_dest[1] = src_dest[1] / src_b[1];
	src_dest[2] = src_dest[2] / src_b[2];
}
inline void glmc_vec3f_div_s(vec3f dest, vec3f src_a, float src_b)
{
	dest[0] = src_a[0] / src_b;
	dest[1] = src_a[1] / src_b;
	dest[2] = src_a[2] / src_b;
}

inline void glmc_vec3f_addadd(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = dest[0] + src_a[0] + src_b[0];
	dest[1] = dest[1] + src_a[1] + src_b[1];
	dest[2] = dest[2] + src_a[2] + src_b[2];
}
inline void glmc_vec3f_subadd(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = dest[0] + src_a[0] - src_b[0];
	dest[1] = dest[1] + src_a[1] - src_b[1];
	dest[2] = dest[2] + src_a[2] - src_b[2];
}

inline void glmc_vec3f_madd(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = dest[0] + (src_a[0] * src_b[0]);
	dest[1] = dest[1] + (src_a[1] * src_b[1]);
	dest[2] = dest[2] + (src_a[2] * src_b[2]);
}
inline void glmc_vec3f_msub(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = dest[0] - (src_a[0] * src_b[0]);
	dest[1] = dest[1] - (src_a[1] * src_b[1]);
	dest[2] = dest[2] - (src_a[2] * src_b[2]);
}

inline float glmc_vec3f_dot(vec3f src_a, vec3f src_b)
{
	float vec3f_dot;
	vec3f_dot = (src_a[0]*src_b[0]) + (src_a[1]*src_b[1]) + (src_a[2]*src_b[2]);
	return vec3f_dot;
}
inline void glmc_vec3f_cross(vec3f dest, vec3f src_a, vec3f src_b)
{
	dest[0] = src_a[1]*src_b[2] - src_a[2]*src_b[1];
	dest[1] = src_a[2]*src_b[0] - src_a[0]*src_b[2];
	dest[2] = src_a[0]*src_b[1] - src_a[1]*src_b[0];
}

inline void glmc_vec3f_reflection(vec3f dest, vec3f src, vec3f normal)
{
	glmc_vec3f_normlize_dest(normal);

	float vec3f_dot = 2*glmc_vec3f_dot(src, normal);
	vec3f temp;

	glmc_vec3f_mul_s(temp, src, vec3f_dot);

	glmc_vec3f_sub(dest, src, temp);
}
inline void glmc_vec3f_refraction(vec3f dest, vec3f src, vec3f normal, float src_mu)
{
	glmc_vec3f_normlize_dest(normal);
	glmc_vec3f_normlize_dest(src);
	
	float src_mu_inv = 1.0f/src_mu;
	vec3f temp1, temp2, temp3, temp4, temp5, temp6;
	
	glmc_vec3f_cross(temp1, src, normal);
	glmc_vec3f_cross(temp2, normal, temp1);
	glmc_vec3f_cross(temp3, normal, src);
	float temp7 = sqrtf(1 - src_mu_inv*src_mu_inv*glmc_vec3f_dot(temp3, temp3));

	glmc_vec3f_mul_s(temp5, temp2, src_mu_inv);
	glmc_vec3f_mul_s(temp6, normal, temp7);

	glmc_vec3f_sub(dest, temp5, temp6);
}