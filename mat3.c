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

inline void glmc_mat3f_input(mat3f dest)
{
	scanf("%f", &dest[0][0]);
	scanf("%f", &dest[1][0]);
	scanf("%f", &dest[2][0]);

	scanf("%f", &dest[0][1]);
	scanf("%f", &dest[1][1]);
	scanf("%f", &dest[2][1]);

	scanf("%f", &dest[0][2]);
	scanf("%f", &dest[1][2]);
	scanf("%f", &dest[2][2]);

	#ifdef NORMALISE 
		glmc_mat3f_normlize_dest(dest);
	#endif
}

inline void glmc_convert_3f_to_1D(oneD3f dest, mat3f src)
{
	dest[0] = src[0][0];
	dest[1] = src[1][0];
	dest[2] = src[2][0];

	dest[3] = src[0][1];
	dest[4] = src[1][1];
	dest[5] = src[2][1];

	dest[6] = src[0][2];
	dest[7] = src[1][2];
	dest[8] = src[2][2];
}
inline void glmc_convert_1D_to_3f(mat3f dest, oneD3f src)
{
	dest[0][0] = src[0];
	dest[1][0] = src[1];
	dest[2][0] = src[2];

	dest[0][1] = src[3];
	dest[1][1] = src[4];
	dest[2][1] = src[5];

	dest[0][2] = src[6];
	dest[1][2] = src[7];
	dest[2][2] = src[8];
}

inline void glmc_mat3f_transpose(mat3f dest, mat3f src)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];
	dest[0][2] = src[2][0];

	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];
	dest[1][2] = src[2][1];

	dest[2][0] = src[0][2];
	dest[2][1] = src[1][2];
	dest[2][2] = src[2][2];
}
inline void glmc_mat3f_transpose_dest(mat3f src_dest)
{
	float temp;

	temp = src_dest[0][1];
	src_dest[0][1] = src_dest[1][0];
	src_dest[1][0] = temp;

	temp = src_dest[0][2];
	src_dest[0][2] = src_dest[2][0];
	src_dest[2][0] = temp;

	temp = src_dest[1][2];
	src_dest[1][2] = src_dest[2][1];
	src_dest[2][1] = temp;
}

inline float glmc_mat3f_determinant(mat3f mat)
{
	float mat3f_det;
	mat3f_det = + (mat[0][0]*((mat[1][1]*mat[2][2])-(mat[2][1]*mat[1][2]))) 
				- (mat[1][0]*((mat[0][1]*mat[2][2])-(mat[2][1]*mat[0][2]))) 
				+ (mat[2][0]*((mat[0][1]*mat[1][2])-(mat[1][1]*mat[0][2])));
	return mat3f_det;
}

inline void glmc_mat3f_inverse(mat3f dest, mat3f src)
{
	float mat3f_det_inv;
	mat3f_det_inv = 1.0f/(glmc_mat3f_determinant(src));

	dest[0][0] = (src[1][1]*src[2][2] - src[2][1]*src[1][2])*mat3f_det_inv;
	dest[0][1] = -1.0f*(src[0][1]*src[2][2] - src[2][1]*src[0][2])*mat3f_det_inv;
	dest[0][2] = (src[0][1]*src[1][2] - src[1][1]*src[0][2])*mat3f_det_inv;

	dest[1][0] = -1.0f*(src[1][0]*src[2][2] - src[2][0]*src[1][2])*mat3f_det_inv;
	dest[1][1] = (src[0][0]*src[2][2] - src[2][0]*src[0][2])*mat3f_det_inv;
	dest[1][2] = -1.0f*(src[0][0]*src[1][2] - src[1][0]*src[0][2])*mat3f_det_inv;

	dest[2][0] = (src[1][0]*src[2][1] - src[2][0]*src[1][1])*mat3f_det_inv;
	dest[2][1] = -1.0f*(src[0][0]*src[2][1] - src[2][0]*src[0][1])*mat3f_det_inv;
	dest[2][2] = (src[0][0]*src[1][1] - src[1][0]*src[0][1])*mat3f_det_inv;	
}

inline void glmc_mat3f_normlize(mat3f dest, mat3f src)
{
	float mat3f_det_inv;
	mat3f_det_inv = 1.0f/(glmc_mat3f_determinant(src));

	dest[0][0] = src[0][0]*mat3f_det_inv;
	dest[0][1] = src[0][1]*mat3f_det_inv;
	dest[0][2] = src[0][2]*mat3f_det_inv;

	dest[1][0] = src[1][0]*mat3f_det_inv;
	dest[1][1] = src[1][1]*mat3f_det_inv;
	dest[1][2] = src[1][2]*mat3f_det_inv;

	dest[2][0] = src[2][0]*mat3f_det_inv;
	dest[2][1] = src[2][1]*mat3f_det_inv;
	dest[2][2] = src[2][2]*mat3f_det_inv;
}
inline void glmc_mat3f_normlize_dest(mat3f src_dest)
{
	float mat3f_det_inv;
	mat3f_det_inv = 1.0f/(glmc_mat3f_determinant(src_dest));

	src_dest[0][0] = src_dest[0][0]*mat3f_det_inv;
	src_dest[0][1] = src_dest[0][1]*mat3f_det_inv;
	src_dest[0][2] = src_dest[0][2]*mat3f_det_inv;

	src_dest[1][0] = src_dest[1][0]*mat3f_det_inv;
	src_dest[1][1] = src_dest[1][1]*mat3f_det_inv;
	src_dest[1][2] = src_dest[1][2]*mat3f_det_inv;

	src_dest[2][0] = src_dest[2][0]*mat3f_det_inv;
	src_dest[2][1] = src_dest[2][1]*mat3f_det_inv;
	src_dest[2][2] = src_dest[2][2]*mat3f_det_inv;
}

inline void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[0][2] = src_a[0][2] + src_b[0][2];

	dest[1][0] = src_a[1][0] + src_b[1][0];
	dest[1][1] = src_a[1][1] + src_b[1][1];
	dest[1][2] = src_a[1][2] + src_b[1][2];

	dest[2][0] = src_a[2][0] + src_b[2][0];
	dest[2][1] = src_a[2][1] + src_b[2][1];
	dest[2][2] = src_a[2][2] + src_b[2][2];
}
inline void glmc_mat3f_add_dest(mat3f src_dest, mat3f src_b)
{
	src_dest[0][0] = src_dest[0][0] + src_b[0][0];
	src_dest[0][1] = src_dest[0][1] + src_b[0][1];
	src_dest[0][2] = src_dest[0][2] + src_b[0][2];

	src_dest[1][0] = src_dest[1][0] + src_b[1][0];
	src_dest[1][1] = src_dest[1][1] + src_b[1][1];
	src_dest[1][2] = src_dest[1][2] + src_b[1][2];

	src_dest[2][0] = src_dest[2][0] + src_b[2][0];
	src_dest[2][1] = src_dest[2][1] + src_b[2][1];
	src_dest[2][2] = src_dest[2][2] + src_b[2][2];
}

inline void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[0][2] = src_a[0][2] - src_b[0][2];

	dest[1][0] = src_a[1][0] - src_b[1][0];
	dest[1][1] = src_a[1][1] - src_b[1][1];
	dest[1][2] = src_a[1][2] - src_b[1][2];

	dest[2][0] = src_a[2][0] - src_b[2][0];
	dest[2][1] = src_a[2][1] - src_b[2][1];
	dest[2][2] = src_a[2][2] - src_b[2][2];
}
inline void glmc_mat3f_sub_dest(mat3f src_dest, mat3f src_b)
{
	src_dest[0][0] = src_dest[0][0] - src_b[0][0];
	src_dest[0][1] = src_dest[0][1] - src_b[0][1];
	src_dest[0][2] = src_dest[0][2] - src_b[0][2];

	src_dest[1][0] = src_dest[1][0] - src_b[1][0];
	src_dest[1][1] = src_dest[1][1] - src_b[1][1];
	src_dest[1][2] = src_dest[1][2] - src_b[1][2];

	src_dest[2][0] = src_dest[2][0] - src_b[2][0];
	src_dest[2][1] = src_dest[2][1] - src_b[2][1];
	src_dest[2][2] = src_dest[2][2] - src_b[2][2];
}

inline void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2]);
	dest[0][1] = (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2]);
	dest[0][2] = (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2]);

	dest[1][0] = (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2]);
	dest[1][1] = (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2]);
	dest[1][2] = (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2]);

	dest[2][0] = (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2]);
	dest[2][1] = (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2]);
	dest[2][2] = (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2]);
}
inline void glmc_mat3f_mul_dest(mat3f src_dest, mat3f src_b)
{
	mat3f temp;

	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[0][2] = src_dest[0][2];

	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	temp[1][2] = src_dest[1][2];

	temp[2][0] = src_dest[2][0];
	temp[2][1] = src_dest[2][1];
	temp[2][2] = src_dest[2][2];

	src_dest[0][0] = (temp[0][0]*src_b[0][0] + temp[1][0]*src_b[0][1] + temp[2][0]*src_b[0][2]);
	src_dest[0][1] = (temp[0][1]*src_b[0][0] + temp[1][1]*src_b[0][1] + temp[2][1]*src_b[0][2]);
	src_dest[0][2] = (temp[0][2]*src_b[0][0] + temp[1][2]*src_b[0][1] + temp[2][2]*src_b[0][2]);

	src_dest[1][0] = (temp[0][0]*src_b[1][0] + temp[1][0]*src_b[1][1] + temp[2][0]*src_b[1][2]);
	src_dest[1][1] = (temp[0][1]*src_b[1][0] + temp[1][1]*src_b[1][1] + temp[2][1]*src_b[1][2]);
	src_dest[1][2] = (temp[0][2]*src_b[1][0] + temp[1][2]*src_b[1][1] + temp[2][2]*src_b[1][2]);

	src_dest[2][0] = (temp[0][0]*src_b[2][0] + temp[1][0]*src_b[2][1] + temp[2][0]*src_b[2][2]);
	src_dest[2][1] = (temp[0][1]*src_b[2][0] + temp[1][1]*src_b[2][1] + temp[2][1]*src_b[2][2]);
	src_dest[2][2] = (temp[0][2]*src_b[2][0] + temp[1][2]*src_b[2][1] + temp[2][2]*src_b[2][2]);
}
inline void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] * src_b;
	dest[0][1] = src_a[0][1] * src_b;
	dest[0][2] = src_a[0][2] * src_b;

	dest[1][0] = src_a[1][0] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
	dest[1][2] = src_a[1][2] * src_b;

	dest[2][0] = src_a[2][0] * src_b;
	dest[2][1] = src_a[2][1] * src_b;
	dest[2][2] = src_a[2][2] * src_b;
}

inline void glmc_mat3f_div(mat3f dest, mat3f src_a, mat3f src_b)
{
	mat3f src_b_inv;
	glmc_mat3f_inverse(src_b_inv, src_b);
	glmc_mat3f_mul(dest, src_a, src_b_inv);
}
inline void glmc_mat3f_div_dest(mat3f src_dest, mat3f src_b)
{
	mat3f temp;

	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[0][2] = src_dest[0][2];

	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	temp[1][2] = src_dest[1][2];

	temp[2][0] = src_dest[2][0];
	temp[2][1] = src_dest[2][1];
	temp[2][2] = src_dest[2][2];

	mat3f src_b_inv;
	glmc_mat3f_inverse(src_b_inv, src_b);
	glmc_mat3f_mul(src_dest, temp, src_b_inv);	
}
inline void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b)
{
	float src_b_inv = 1.0f/(src_b);
	
	dest[0][0] = src_a[0][0] * src_b_inv;
	dest[0][1] = src_a[0][1] * src_b_inv;
	dest[0][2] = src_a[0][2] * src_b_inv;

	dest[1][0] = src_a[1][0] * src_b_inv;
	dest[1][1] = src_a[1][1] * src_b_inv;
	dest[1][2] = src_a[1][2] * src_b_inv;

	dest[2][0] = src_a[2][0] * src_b_inv;
	dest[2][1] = src_a[2][1] * src_b_inv;
	dest[2][2] = src_a[2][2] * src_b_inv;
}

inline void glmc_mat3f_addadd(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = dest[0][0] + src_a[0][0] + src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] + src_b[0][1];
	dest[0][2] = dest[0][2] + src_a[0][2] + src_b[0][2];

	dest[1][0] = dest[1][0] + src_a[1][0] + src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] + src_b[1][1];
	dest[1][2] = dest[1][2] + src_a[1][2] + src_b[1][2];

	dest[2][0] = dest[2][0] + src_a[2][0] + src_b[2][0];
	dest[2][1] = dest[2][1] + src_a[2][1] + src_b[2][1];
	dest[2][2] = dest[2][2] + src_a[2][2] + src_b[2][2];
}
inline void glmc_mat3f_subadd(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = dest[0][0] + src_a[0][0] - src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] - src_b[0][1];
	dest[0][2] = dest[0][2] + src_a[0][2] - src_b[0][2];

	dest[1][0] = dest[1][0] + src_a[1][0] - src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] - src_b[1][1];
	dest[1][2] = dest[1][2] + src_a[1][2] - src_b[1][2];

	dest[2][0] = dest[2][0] + src_a[2][0] - src_b[2][0];
	dest[2][1] = dest[2][1] + src_a[2][1] - src_b[2][1];
	dest[2][2] = dest[2][2] + src_a[2][2] - src_b[2][2];
}

inline void glmc_mat3f_madd(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = dest[0][0] + (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2]);
	dest[0][1] = dest[0][1] + (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2]);
	dest[0][2] = dest[0][2] + (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2]);

	dest[1][0] = dest[1][0] + (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2]);
	dest[1][1] = dest[1][1] + (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2]);
	dest[1][2] = dest[1][2] + (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2]);

	dest[2][0] = dest[2][0] + (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2]);
	dest[2][1] = dest[2][1] + (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2]);
	dest[2][2] = dest[2][2] + (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2]);
}
inline void glmc_mat3f_msub(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = dest[0][0] - (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2]);
	dest[0][1] = dest[0][1] - (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2]);
	dest[0][2] = dest[0][2] - (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2]);

	dest[1][0] = dest[1][0] - (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2]);
	dest[1][1] = dest[1][1] - (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2]);
	dest[1][2] = dest[1][2] - (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2]);

	dest[2][0] = dest[2][0] - (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2]);
	dest[2][1] = dest[2][1] - (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2]);
	dest[2][2] = dest[2][2] - (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2]);
}

inline void glmc_mat3f_identity(mat3f dest)
{
	dest[0][0] = 1.0f;
	dest[0][1] = 0;
	dest[0][2] = 0;

	dest[1][0] = 0;
	dest[1][1] = 1.0f;
	dest[1][2] = 0;

	dest[2][0] = 0;
	dest[2][1] = 0;
	dest[2][2] = 1.0f;
}
inline void glmc_mat3f_scale(mat3f dest, float src_sx, float src_sy)
{
	dest[0][0] = src_sx;
	dest[0][1] = 0;
	dest[0][2] = 0;

	dest[1][0] = 0;
	dest[1][1] = src_sy;
	dest[1][2] = 0;

	dest[2][0] = 0;
	dest[2][1] = 0;
	dest[2][2] = 1.0f;
}
inline void glmc_mat3f_translation(mat3f dest, float src_t1, float src_t2)
{
	dest[0][0] = 1.0f;
	dest[0][1] = 0;
	dest[0][2] = 0;

	dest[1][0] = 0;
	dest[1][1] = 1.0f;
	dest[1][2] = 0;

	dest[2][0] = src_t1;
	dest[2][1] = src_t2;
	dest[2][2] = 1.0f;
}
