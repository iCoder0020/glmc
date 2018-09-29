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

inline void glmc_mat4f_input(mat4f dest)
{
	scanf("%f", &dest[0][0]);
	scanf("%f", &dest[1][0]);
	scanf("%f", &dest[2][0]);
	scanf("%f", &dest[3][0]);

	scanf("%f", &dest[0][1]);
	scanf("%f", &dest[1][1]);
	scanf("%f", &dest[2][1]);
	scanf("%f", &dest[3][1]);

	scanf("%f", &dest[0][2]);
	scanf("%f", &dest[1][2]);
	scanf("%f", &dest[2][2]);
	scanf("%f", &dest[3][2]);

	scanf("%f", &dest[0][3]);
	scanf("%f", &dest[1][3]);
	scanf("%f", &dest[2][3]);
	scanf("%f", &dest[3][3]);

	#ifdef NORMALISE 
		glmc_mat4f_normlize_dest(dest);
	#endif
}

inline void glmc_convert_4f_to_1D(oneD4f dest, mat4f src)
{
	dest[0] = src[0][0];
	dest[1] = src[1][0];
	dest[2] = src[2][0];
	dest[3] = src[3][0];

	dest[4] = src[0][1];
	dest[5] = src[1][1];
	dest[6] = src[2][1];
	dest[7] = src[3][1];

	dest[8] = src[0][2];
	dest[9] = src[1][2];
	dest[10] = src[2][2];
	dest[11] = src[3][2];

	dest[12] = src[0][3];
	dest[13] = src[1][3];
	dest[14] = src[2][3];
	dest[15] = src[3][3];
}
inline void glmc_convert_1D_to_4f(mat4f dest, oneD4f src)
{
	dest[0][0] = src[0];
	dest[1][0] = src[1];
	dest[2][0] = src[2];
	dest[3][0] = src[3];

	dest[0][1] = src[4];
	dest[1][1] = src[5];
	dest[2][1] = src[6];
	dest[3][1] = src[7];

	dest[0][2] = src[8];
	dest[1][2] = src[9];
	dest[2][2] = src[10];
	dest[3][2] = src[11];

	dest[0][3] = src[12];
	dest[1][3] = src[13];
	dest[2][3] = src[14];
	dest[3][3] = src[15];
}

inline void glmc_mat4f_transpose(mat4f dest, mat4f src)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[1][0];
	dest[0][2] = src[2][0];
	dest[0][3] = src[3][0];

	dest[1][0] = src[0][1];
	dest[1][1] = src[1][1];
	dest[1][2] = src[2][1];
	dest[1][3] = src[3][1];

	dest[2][0] = src[0][2];
	dest[2][1] = src[1][2];
	dest[2][2] = src[2][2];
	dest[2][3] = src[3][2];

	dest[3][0] = src[0][3];
	dest[3][1] = src[1][3];
	dest[3][2] = src[2][3];
	dest[3][3] = src[3][3];	
}
inline void glmc_mat4f_transpose_dest(mat4f src_dest)
{
	float temp;

	temp = src_dest[0][1];
	src_dest[0][1] = src_dest[1][0];
	src_dest[1][0] = temp;

	temp = src_dest[0][2];
	src_dest[0][2] = src_dest[2][0];
	src_dest[2][0] = temp;

	temp = src_dest[0][3];
	src_dest[0][3] = src_dest[3][0];
	src_dest[3][0] = temp;

	temp = src_dest[1][2];
	src_dest[1][2] = src_dest[2][1];
	src_dest[2][1] = temp;

	temp = src_dest[1][3];
	src_dest[1][3] = src_dest[3][1];
	src_dest[3][1] = temp;

	temp = src_dest[2][3];
	src_dest[2][3] = src_dest[3][2];
	src_dest[3][2] = temp;
}

inline float glmc_mat4f_determinant(mat4f mat)
{
	float mat4f_det;
	mat4f_det = + mat[0][0]*((mat[1][1]*((mat[2][2]*mat[3][3])-(mat[3][2]*mat[2][3]))) - (mat[2][1]*((mat[1][2]*mat[3][3])-(mat[3][2]*mat[1][3]))) + (mat[3][1]*((mat[1][2]*mat[2][3])-(mat[2][2]*mat[1][3]))))
				- mat[1][0]*((mat[0][1]*((mat[2][2]*mat[3][3])-(mat[3][2]*mat[2][3]))) - (mat[2][1]*((mat[0][2]*mat[3][3])-(mat[3][2]*mat[0][3]))) + (mat[3][1]*((mat[0][2]*mat[2][3])-(mat[2][2]*mat[0][3]))))
				+ mat[2][0]*((mat[0][1]*((mat[1][2]*mat[3][3])-(mat[3][2]*mat[1][3]))) - (mat[1][1]*((mat[0][2]*mat[3][3])-(mat[3][2]*mat[0][3]))) + (mat[3][1]*((mat[0][2]*mat[1][3])-(mat[1][2]*mat[0][3]))))
				- mat[3][0]*((mat[0][1]*((mat[1][2]*mat[2][3])-(mat[2][2]*mat[1][3]))) - (mat[1][1]*((mat[0][2]*mat[2][3])-(mat[2][2]*mat[0][3]))) + (mat[2][1]*((mat[0][2]*mat[1][3])-(mat[1][2]*mat[0][3]))));
	return mat4f_det;
}

inline void glmc_mat4f_inverse(mat4f dest, mat4f src)
{
	float mat4f_det_inv;
	mat4f_det_inv = 1.0f/(glmc_mat4f_determinant(src));

	dest[0][0] = ((src[1][1]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][1]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) + (src[3][1]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))))*mat4f_det_inv;
	dest[0][1] = -1.0f*((src[0][1]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][1]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][1]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))))*mat4f_det_inv;
	dest[0][2] = ((src[0][1]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) - (src[1][1]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][1]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*mat4f_det_inv;
	dest[0][3] = -1.0f*((src[0][1]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))) - (src[1][1]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))) + (src[2][1]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*mat4f_det_inv;

	dest[1][0] = -1.0f*((src[1][0]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][0]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) + (src[3][0]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))))*mat4f_det_inv;
	dest[1][1] = ((src[0][0]*((src[2][2]*src[3][3])-(src[3][2]*src[2][3]))) - (src[2][0]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][0]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))))*mat4f_det_inv;
	dest[1][2] = -1.0f*((src[0][0]*((src[1][2]*src[3][3])-(src[3][2]*src[1][3]))) - (src[1][0]*((src[0][2]*src[3][3])-(src[3][2]*src[0][3]))) + (src[3][0]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*mat4f_det_inv;
	dest[1][3] = ((src[0][0]*((src[1][2]*src[2][3])-(src[2][2]*src[1][3]))) - (src[1][0]*((src[0][2]*src[2][3])-(src[2][2]*src[0][3]))) + (src[2][0]*((src[0][2]*src[1][3])-(src[1][2]*src[0][3]))))*mat4f_det_inv;

	dest[2][0] = ((src[1][0]*((src[2][1]*src[3][3])-(src[3][1]*src[2][3]))) - (src[2][0]*((src[1][1]*src[3][3])-(src[3][1]*src[1][3]))) + (src[3][0]*((src[1][1]*src[2][3])-(src[2][1]*src[1][3]))))*mat4f_det_inv;
	dest[2][1] = -1.0f*((src[0][0]*((src[2][1]*src[3][3])-(src[3][1]*src[2][3]))) - (src[2][0]*((src[0][1]*src[3][3])-(src[3][1]*src[0][3]))) + (src[3][0]*((src[0][1]*src[2][3])-(src[2][1]*src[0][3]))))*mat4f_det_inv;
	dest[2][2] = ((src[0][0]*((src[1][1]*src[3][3])-(src[3][1]*src[1][3]))) - (src[1][0]*((src[0][1]*src[3][3])-(src[3][1]*src[0][3]))) + (src[3][0]*((src[0][1]*src[1][3])-(src[1][1]*src[0][3]))))*mat4f_det_inv;
	dest[2][3] = -1.0f*((src[0][0]*((src[1][1]*src[2][3])-(src[2][1]*src[1][3]))) - (src[1][0]*((src[0][1]*src[2][3])-(src[2][1]*src[0][3]))) + (src[2][0]*((src[0][1]*src[1][3])-(src[1][1]*src[0][3]))))*mat4f_det_inv;

	dest[3][0] = -1.0f*((src[1][0]*((src[2][1]*src[3][2])-(src[3][1]*src[2][2]))) - (src[2][0]*((src[1][1]*src[3][2])-(src[3][1]*src[1][2]))) + (src[3][0]*((src[1][1]*src[2][2])-(src[2][1]*src[1][2]))))*mat4f_det_inv;
	dest[3][1] = ((src[0][0]*((src[2][1]*src[3][2])-(src[3][1]*src[2][2]))) - (src[2][0]*((src[0][1]*src[3][2])-(src[3][1]*src[0][2]))) + (src[3][0]*((src[0][1]*src[2][2])-(src[2][1]*src[0][2]))))*mat4f_det_inv;
	dest[3][2] = -1.0f*((src[0][0]*((src[1][1]*src[3][2])-(src[3][1]*src[1][2]))) - (src[1][0]*((src[0][1]*src[3][2])-(src[3][1]*src[0][2]))) + (src[3][0]*((src[0][1]*src[1][2])-(src[1][1]*src[0][2]))))*mat4f_det_inv;
	dest[3][3] = ((src[0][0]*((src[1][1]*src[2][2])-(src[2][1]*src[1][2]))) - (src[1][0]*((src[0][1]*src[2][2])-(src[2][1]*src[0][2]))) + (src[2][0]*((src[0][1]*src[1][2])-(src[1][1]*src[0][2]))))*mat4f_det_inv;
}

inline void glmc_mat4f_normlize(mat4f dest, mat4f src)
{
	float mat4f_det_inv;
	mat4f_det_inv = 1.0f/(glmc_mat4f_determinant(src));

	dest[0][0] = src[0][0] * mat4f_det_inv;
	dest[0][1] = src[0][1] * mat4f_det_inv;
	dest[0][2] = src[0][2] * mat4f_det_inv;
	dest[0][3] = src[0][3] * mat4f_det_inv;

	dest[1][0] = src[1][0] * mat4f_det_inv;
	dest[1][1] = src[1][1] * mat4f_det_inv;
	dest[1][2] = src[1][2] * mat4f_det_inv;
	dest[1][3] = src[1][3] * mat4f_det_inv;

	dest[2][0] = src[2][0] * mat4f_det_inv;
	dest[2][1] = src[2][1] * mat4f_det_inv;
	dest[2][2] = src[2][2] * mat4f_det_inv;
	dest[2][3] = src[2][3] * mat4f_det_inv;

	dest[3][0] = src[3][0] * mat4f_det_inv;
	dest[3][1] = src[3][1] * mat4f_det_inv;
	dest[3][2] = src[3][2] * mat4f_det_inv;
	dest[3][3] = src[3][3] * mat4f_det_inv;
}
inline void glmc_mat4f_normlize_dest(mat4f src_dest)
{
	float mat4f_det_inv;
	mat4f_det_inv = 1.0f/(glmc_mat4f_determinant(src_dest));

	src_dest[0][0] = src_dest[0][0] * mat4f_det_inv;
	src_dest[0][1] = src_dest[0][1] * mat4f_det_inv;
	src_dest[0][2] = src_dest[0][2] * mat4f_det_inv;
	src_dest[0][3] = src_dest[0][3] * mat4f_det_inv;

	src_dest[1][0] = src_dest[1][0] * mat4f_det_inv;
	src_dest[1][1] = src_dest[1][1] * mat4f_det_inv;
	src_dest[1][2] = src_dest[1][2] * mat4f_det_inv;
	src_dest[1][3] = src_dest[1][3] * mat4f_det_inv;

	src_dest[2][0] = src_dest[2][0] * mat4f_det_inv;
	src_dest[2][1] = src_dest[2][1] * mat4f_det_inv;
	src_dest[2][2] = src_dest[2][2] * mat4f_det_inv;
	src_dest[2][3] = src_dest[2][3] * mat4f_det_inv;

	src_dest[3][0] = src_dest[3][0] * mat4f_det_inv;
	src_dest[3][1] = src_dest[3][1] * mat4f_det_inv;
	src_dest[3][2] = src_dest[3][2] * mat4f_det_inv;
	src_dest[3][3] = src_dest[3][3] * mat4f_det_inv;
}

inline void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = src_a[0][0] + src_b[0][0];
	dest[0][1] = src_a[0][1] + src_b[0][1];
	dest[0][2] = src_a[0][2] + src_b[0][2];
	dest[0][3] = src_a[0][3] + src_b[0][3];

	dest[1][0] = src_a[1][0] + src_b[1][0];
	dest[1][1] = src_a[1][1] + src_b[1][1];
	dest[1][2] = src_a[1][2] + src_b[1][2];
	dest[1][3] = src_a[1][3] + src_b[1][3];

	dest[2][0] = src_a[2][0] + src_b[2][0];
	dest[2][1] = src_a[2][1] + src_b[2][1];
	dest[2][2] = src_a[2][2] + src_b[2][2];
	dest[2][3] = src_a[2][3] + src_b[2][3];	

	dest[3][0] = src_a[3][0] + src_b[3][0];
	dest[3][1] = src_a[3][1] + src_b[3][1];
	dest[3][2] = src_a[3][2] + src_b[3][2];
	dest[3][3] = src_a[3][3] + src_b[3][3];
}
inline void glmc_mat4f_add_dest(mat4f src_dest, mat4f src_b)
{
	src_dest[0][0] = src_dest[0][0] + src_b[0][0];
	src_dest[0][1] = src_dest[0][1] + src_b[0][1];
	src_dest[0][2] = src_dest[0][2] + src_b[0][2];
	src_dest[0][3] = src_dest[0][3] + src_b[0][3];

	src_dest[1][0] = src_dest[1][0] + src_b[1][0];
	src_dest[1][1] = src_dest[1][1] + src_b[1][1];
	src_dest[1][2] = src_dest[1][2] + src_b[1][2];
	src_dest[1][3] = src_dest[1][3] + src_b[1][3];

	src_dest[2][0] = src_dest[2][0] + src_b[2][0];
	src_dest[2][1] = src_dest[2][1] + src_b[2][1];
	src_dest[2][2] = src_dest[2][2] + src_b[2][2];
	src_dest[2][3] = src_dest[2][3] + src_b[2][3];	

	src_dest[3][0] = src_dest[3][0] + src_b[3][0];
	src_dest[3][1] = src_dest[3][1] + src_b[3][1];
	src_dest[3][2] = src_dest[3][2] + src_b[3][2];
	src_dest[3][3] = src_dest[3][3] + src_b[3][3];	
}

inline void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = src_a[0][0] - src_b[0][0];
	dest[0][1] = src_a[0][1] - src_b[0][1];
	dest[0][2] = src_a[0][2] - src_b[0][2];
	dest[0][3] = src_a[0][3] - src_b[0][3];

	dest[1][0] = src_a[1][0] - src_b[1][0];
	dest[1][1] = src_a[1][1] - src_b[1][1];
	dest[1][2] = src_a[1][2] - src_b[1][2];
	dest[1][3] = src_a[1][3] - src_b[1][3];

	dest[2][0] = src_a[2][0] - src_b[2][0];
	dest[2][1] = src_a[2][1] - src_b[2][1];
	dest[2][2] = src_a[2][2] - src_b[2][2];
	dest[2][3] = src_a[2][3] - src_b[2][3];

	dest[3][0] = src_a[3][0] - src_b[3][0];
	dest[3][1] = src_a[3][1] - src_b[3][1];
	dest[3][2] = src_a[3][2] - src_b[3][2];
	dest[3][3] = src_a[3][3] - src_b[3][3];
}
inline void glmc_mat4f_sub_dest(mat4f src_dest, mat4f src_b)
{
	src_dest[0][0] = src_dest[0][0] - src_b[0][0];
	src_dest[0][1] = src_dest[0][1] - src_b[0][1];
	src_dest[0][2] = src_dest[0][2] - src_b[0][2];
	src_dest[0][3] = src_dest[0][3] - src_b[0][3];

	src_dest[1][0] = src_dest[1][0] - src_b[1][0];
	src_dest[1][1] = src_dest[1][1] - src_b[1][1];
	src_dest[1][2] = src_dest[1][2] - src_b[1][2];
	src_dest[1][3] = src_dest[1][3] - src_b[1][3];

	src_dest[2][0] = src_dest[2][0] - src_b[2][0];
	src_dest[2][1] = src_dest[2][1] - src_b[2][1];
	src_dest[2][2] = src_dest[2][2] - src_b[2][2];
	src_dest[2][3] = src_dest[2][3] - src_b[2][3];

	src_dest[3][0] = src_dest[3][0] - src_b[3][0];
	src_dest[3][1] = src_dest[3][1] - src_b[3][1];
	src_dest[3][2] = src_dest[3][2] - src_b[3][2];
	src_dest[3][3] = src_dest[3][3] - src_b[3][3];		
}

inline void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2] + src_a[3][0]*src_b[0][3]);
	dest[0][1] = (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2] + src_a[3][1]*src_b[0][3]);
	dest[0][2] = (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2] + src_a[3][2]*src_b[0][3]);
	dest[0][3] = (src_a[0][3]*src_b[0][0] + src_a[1][3]*src_b[0][1] + src_a[2][3]*src_b[0][2] + src_a[3][3]*src_b[0][3]);

	dest[1][0] = (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2] + src_a[3][0]*src_b[1][3]);
	dest[1][1] = (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2] + src_a[3][1]*src_b[1][3]);
	dest[1][2] = (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2] + src_a[3][2]*src_b[1][3]);
	dest[1][3] = (src_a[0][3]*src_b[1][0] + src_a[1][3]*src_b[1][1] + src_a[2][3]*src_b[1][2] + src_a[3][3]*src_b[1][3]);

	dest[2][0] = (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2] + src_a[3][0]*src_b[2][3]);
	dest[2][1] = (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2] + src_a[3][1]*src_b[2][3]);
	dest[2][2] = (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2] + src_a[3][2]*src_b[2][3]);
	dest[2][3] = (src_a[0][3]*src_b[2][0] + src_a[1][3]*src_b[2][1] + src_a[2][3]*src_b[2][2] + src_a[3][3]*src_b[2][3]);

	dest[3][0] = (src_a[0][0]*src_b[3][0] + src_a[1][0]*src_b[3][1] + src_a[2][0]*src_b[3][2] + src_a[3][0]*src_b[3][3]);
	dest[3][1] = (src_a[0][1]*src_b[3][0] + src_a[1][1]*src_b[3][1] + src_a[2][1]*src_b[3][2] + src_a[3][1]*src_b[3][3]);
	dest[3][2] = (src_a[0][2]*src_b[3][0] + src_a[1][2]*src_b[3][1] + src_a[2][2]*src_b[3][2] + src_a[3][2]*src_b[3][3]);
	dest[3][3] = (src_a[0][3]*src_b[3][0] + src_a[1][3]*src_b[3][1] + src_a[2][3]*src_b[3][2] + src_a[3][3]*src_b[3][3]);
}
inline void glmc_mat4f_mul_dest(mat4f src_dest, mat4f src_b)
{
	mat4f temp;

	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[0][2] = src_dest[0][2];
	temp[0][3] = src_dest[0][3];

	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	temp[1][2] = src_dest[1][2];
	temp[1][3] = src_dest[1][3];

	temp[2][0] = src_dest[2][0];
	temp[2][1] = src_dest[2][1];
	temp[2][2] = src_dest[2][2];
	temp[2][3] = src_dest[2][3];

	temp[3][0] = src_dest[3][0];
	temp[3][1] = src_dest[3][1];
	temp[3][2] = src_dest[3][2];
	temp[3][3] = src_dest[3][3];

	src_dest[0][0] = (temp[0][0]*src_b[0][0] + temp[1][0]*src_b[0][1] + temp[2][0]*src_b[0][2] + temp[3][0]*src_b[0][3]);
	src_dest[0][1] = (temp[0][1]*src_b[0][0] + temp[1][1]*src_b[0][1] + temp[2][1]*src_b[0][2] + temp[3][1]*src_b[0][3]);
	src_dest[0][2] = (temp[0][2]*src_b[0][0] + temp[1][2]*src_b[0][1] + temp[2][2]*src_b[0][2] + temp[3][2]*src_b[0][3]);
	src_dest[0][3] = (temp[0][3]*src_b[0][0] + temp[1][3]*src_b[0][1] + temp[2][3]*src_b[0][2] + temp[3][3]*src_b[0][3]);

	src_dest[1][0] = (temp[0][0]*src_b[1][0] + temp[1][0]*src_b[1][1] + temp[2][0]*src_b[1][2] + temp[3][0]*src_b[1][3]);
	src_dest[1][1] = (temp[0][1]*src_b[1][0] + temp[1][1]*src_b[1][1] + temp[2][1]*src_b[1][2] + temp[3][1]*src_b[1][3]);
	src_dest[1][2] = (temp[0][2]*src_b[1][0] + temp[1][2]*src_b[1][1] + temp[2][2]*src_b[1][2] + temp[3][2]*src_b[1][3]);
	src_dest[1][3] = (temp[0][3]*src_b[1][0] + temp[1][3]*src_b[1][1] + temp[2][3]*src_b[1][2] + temp[3][3]*src_b[1][3]);

	src_dest[2][0] = (temp[0][0]*src_b[2][0] + temp[1][0]*src_b[2][1] + temp[2][0]*src_b[2][2] + temp[3][0]*src_b[2][3]);
	src_dest[2][1] = (temp[0][1]*src_b[2][0] + temp[1][1]*src_b[2][1] + temp[2][1]*src_b[2][2] + temp[3][1]*src_b[2][3]);
	src_dest[2][2] = (temp[0][2]*src_b[2][0] + temp[1][2]*src_b[2][1] + temp[2][2]*src_b[2][2] + temp[3][2]*src_b[2][3]);
	src_dest[2][3] = (temp[0][3]*src_b[2][0] + temp[1][3]*src_b[2][1] + temp[2][3]*src_b[2][2] + temp[3][3]*src_b[2][3]);

	src_dest[3][0] = (temp[0][0]*src_b[3][0] + temp[1][0]*src_b[3][1] + temp[2][0]*src_b[3][2] + temp[3][0]*src_b[3][3]);
	src_dest[3][1] = (temp[0][1]*src_b[3][0] + temp[1][1]*src_b[3][1] + temp[2][1]*src_b[3][2] + temp[3][1]*src_b[3][3]);
	src_dest[3][2] = (temp[0][2]*src_b[3][0] + temp[1][2]*src_b[3][1] + temp[2][2]*src_b[3][2] + temp[3][2]*src_b[3][3]);
	src_dest[3][3] = (temp[0][3]*src_b[3][0] + temp[1][3]*src_b[3][1] + temp[2][3]*src_b[3][2] + temp[3][3]*src_b[3][3]);
}
inline void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] * src_b;
	dest[0][1] = src_a[0][1] * src_b;
	dest[0][2] = src_a[0][2] * src_b;
	dest[0][3] = src_a[0][3] * src_b;

	dest[1][0] = src_a[1][0] * src_b;
	dest[1][1] = src_a[1][1] * src_b;
	dest[1][2] = src_a[1][2] * src_b;
	dest[1][3] = src_a[1][3] * src_b;

	dest[2][0] = src_a[2][0] * src_b;
	dest[2][1] = src_a[2][1] * src_b;
	dest[2][2] = src_a[2][2] * src_b;
	dest[2][3] = src_a[2][3] * src_b;

	dest[3][0] = src_a[3][0] * src_b;
	dest[3][1] = src_a[3][1] * src_b;
	dest[3][2] = src_a[3][2] * src_b;
	dest[3][3] = src_a[3][3] * src_b;
}

inline void glmc_mat4f_div(mat4f dest, mat4f src_a, mat4f src_b)
{
	mat4f src_b_inv;
	glmc_mat4f_inverse(src_b_inv, src_b);
	glmc_mat4f_mul(dest, src_a, src_b_inv);
}
inline void glmc_mat4f_div_dest(mat4f src_dest, mat4f src_b)
{
	mat4f temp;

	temp[0][0] = src_dest[0][0];
	temp[0][1] = src_dest[0][1];
	temp[0][2] = src_dest[0][2];
	temp[0][3] = src_dest[0][3];

	temp[1][0] = src_dest[1][0];
	temp[1][1] = src_dest[1][1];
	temp[1][2] = src_dest[1][2];
	temp[1][3] = src_dest[1][3];

	temp[2][0] = src_dest[2][0];
	temp[2][1] = src_dest[2][1];
	temp[2][2] = src_dest[2][2];
	temp[2][3] = src_dest[2][3];

	temp[3][0] = src_dest[3][0];
	temp[3][1] = src_dest[3][1];
	temp[3][2] = src_dest[3][2];
	temp[3][3] = src_dest[3][3];

	mat4f src_b_inv;
	glmc_mat4f_inverse(src_b_inv, src_b);
	glmc_mat4f_mul(src_dest, temp, src_b_inv);
}
inline void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b)
{
	float src_b_inv = 1.0f/(src_b);

	dest[0][0] = src_a[0][0] * src_b_inv;
	dest[0][1] = src_a[0][1] * src_b_inv;
	dest[0][2] = src_a[0][2] * src_b_inv;
	dest[0][3] = src_a[0][3] * src_b_inv;

	dest[1][0] = src_a[1][0] * src_b_inv;
	dest[1][1] = src_a[1][1] * src_b_inv;
	dest[1][2] = src_a[1][2] * src_b_inv;
	dest[1][3] = src_a[1][3] * src_b_inv;

	dest[2][0] = src_a[2][0] * src_b_inv;
	dest[2][1] = src_a[2][1] * src_b_inv;
	dest[2][2] = src_a[2][2] * src_b_inv;
	dest[2][3] = src_a[2][3] * src_b_inv;

	dest[3][0] = src_a[3][0] * src_b_inv;
	dest[3][1] = src_a[3][1] * src_b_inv;
	dest[3][2] = src_a[3][2] * src_b_inv;
	dest[3][3] = src_a[3][3] * src_b_inv;
}

inline void glmc_mat4f_addadd(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = dest[0][0] + src_a[0][0] + src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] + src_b[0][1];
	dest[0][2] = dest[0][2] + src_a[0][2] + src_b[0][2];
	dest[0][3] = dest[0][3] + src_a[0][3] + src_b[0][3];

	dest[1][0] = dest[1][0] + src_a[1][0] + src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] + src_b[1][1];
	dest[1][2] = dest[1][2] + src_a[1][2] + src_b[1][2];
	dest[1][3] = dest[1][3] + src_a[1][3] + src_b[1][3];

	dest[2][0] = dest[2][0] + src_a[2][0] + src_b[2][0];
	dest[2][1] = dest[2][1] + src_a[2][1] + src_b[2][1];
	dest[2][2] = dest[2][2] + src_a[2][2] + src_b[2][2];
	dest[2][3] = dest[2][3] + src_a[2][3] + src_b[2][3];	

	dest[3][0] = dest[3][0] + src_a[3][0] + src_b[3][0];
	dest[3][1] = dest[3][1] + src_a[3][1] + src_b[3][1];
	dest[3][2] = dest[3][2] + src_a[3][2] + src_b[3][2];
	dest[3][3] = dest[3][3] + src_a[3][3] + src_b[3][3];	
}
inline void glmc_mat4f_subadd(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = dest[0][0] + src_a[0][0] - src_b[0][0];
	dest[0][1] = dest[0][1] + src_a[0][1] - src_b[0][1];
	dest[0][2] = dest[0][2] + src_a[0][2] - src_b[0][2];
	dest[0][3] = dest[0][3] + src_a[0][3] - src_b[0][3];

	dest[1][0] = dest[1][0] + src_a[1][0] - src_b[1][0];
	dest[1][1] = dest[1][1] + src_a[1][1] - src_b[1][1];
	dest[1][2] = dest[1][2] + src_a[1][2] - src_b[1][2];
	dest[1][3] = dest[1][3] + src_a[1][3] - src_b[1][3];

	dest[2][0] = dest[2][0] + src_a[2][0] - src_b[2][0];
	dest[2][1] = dest[2][1] + src_a[2][1] - src_b[2][1];
	dest[2][2] = dest[2][2] + src_a[2][2] - src_b[2][2];
	dest[2][3] = dest[2][3] + src_a[2][3] - src_b[2][3];	

	dest[3][0] = dest[3][0] + src_a[3][0] - src_b[3][0];
	dest[3][1] = dest[3][1] + src_a[3][1] - src_b[3][1];
	dest[3][2] = dest[3][2] + src_a[3][2] - src_b[3][2];
	dest[3][3] = dest[3][3] + src_a[3][3] - src_b[3][3];	
}

inline void glmc_mat4f_madd(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = dest[0][0] + (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2] + src_a[3][0]*src_b[0][3]);
	dest[0][1] = dest[0][1] + (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2] + src_a[3][1]*src_b[0][3]);
	dest[0][2] = dest[0][2] + (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2] + src_a[3][2]*src_b[0][3]);
	dest[0][3] = dest[0][3] + (src_a[0][3]*src_b[0][0] + src_a[1][3]*src_b[0][1] + src_a[2][3]*src_b[0][2] + src_a[3][3]*src_b[0][3]);

	dest[1][0] = dest[1][0] + (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2] + src_a[3][0]*src_b[1][3]);
	dest[1][1] = dest[1][1] + (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2] + src_a[3][1]*src_b[1][3]);
	dest[1][2] = dest[1][2] + (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2] + src_a[3][2]*src_b[1][3]);
	dest[1][3] = dest[1][3] + (src_a[0][3]*src_b[1][0] + src_a[1][3]*src_b[1][1] + src_a[2][3]*src_b[1][2] + src_a[3][3]*src_b[1][3]);

	dest[2][0] = dest[2][0] + (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2] + src_a[3][0]*src_b[2][3]);
	dest[2][1] = dest[2][1] + (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2] + src_a[3][1]*src_b[2][3]);
	dest[2][2] = dest[2][2] + (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2] + src_a[3][2]*src_b[2][3]);
	dest[2][3] = dest[2][3] + (src_a[0][3]*src_b[2][0] + src_a[1][3]*src_b[2][1] + src_a[2][3]*src_b[2][2] + src_a[3][3]*src_b[2][3]);

	dest[3][0] = dest[3][0] + (src_a[0][0]*src_b[3][0] + src_a[1][0]*src_b[3][1] + src_a[2][0]*src_b[3][2] + src_a[3][0]*src_b[3][3]);
	dest[3][1] = dest[3][1] + (src_a[0][1]*src_b[3][0] + src_a[1][1]*src_b[3][1] + src_a[2][1]*src_b[3][2] + src_a[3][1]*src_b[3][3]);
	dest[3][2] = dest[3][2] + (src_a[0][2]*src_b[3][0] + src_a[1][2]*src_b[3][1] + src_a[2][2]*src_b[3][2] + src_a[3][2]*src_b[3][3]);
	dest[3][3] = dest[3][3] + (src_a[0][3]*src_b[3][0] + src_a[1][3]*src_b[3][1] + src_a[2][3]*src_b[3][2] + src_a[3][3]*src_b[3][3]);
}
inline void glmc_mat4f_msub(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = dest[0][0] - (src_a[0][0]*src_b[0][0] + src_a[1][0]*src_b[0][1] + src_a[2][0]*src_b[0][2] + src_a[3][0]*src_b[0][3]);
	dest[0][1] = dest[0][1] - (src_a[0][1]*src_b[0][0] + src_a[1][1]*src_b[0][1] + src_a[2][1]*src_b[0][2] + src_a[3][1]*src_b[0][3]);
	dest[0][2] = dest[0][2] - (src_a[0][2]*src_b[0][0] + src_a[1][2]*src_b[0][1] + src_a[2][2]*src_b[0][2] + src_a[3][2]*src_b[0][3]);
	dest[0][3] = dest[0][3] - (src_a[0][3]*src_b[0][0] + src_a[1][3]*src_b[0][1] + src_a[2][3]*src_b[0][2] + src_a[3][3]*src_b[0][3]);

	dest[1][0] = dest[1][0] - (src_a[0][0]*src_b[1][0] + src_a[1][0]*src_b[1][1] + src_a[2][0]*src_b[1][2] + src_a[3][0]*src_b[1][3]);
	dest[1][1] = dest[1][1] - (src_a[0][1]*src_b[1][0] + src_a[1][1]*src_b[1][1] + src_a[2][1]*src_b[1][2] + src_a[3][1]*src_b[1][3]);
	dest[1][2] = dest[1][2] - (src_a[0][2]*src_b[1][0] + src_a[1][2]*src_b[1][1] + src_a[2][2]*src_b[1][2] + src_a[3][2]*src_b[1][3]);
	dest[1][3] = dest[1][3] - (src_a[0][3]*src_b[1][0] + src_a[1][3]*src_b[1][1] + src_a[2][3]*src_b[1][2] + src_a[3][3]*src_b[1][3]);

	dest[2][0] = dest[2][0] - (src_a[0][0]*src_b[2][0] + src_a[1][0]*src_b[2][1] + src_a[2][0]*src_b[2][2] + src_a[3][0]*src_b[2][3]);
	dest[2][1] = dest[2][1] - (src_a[0][1]*src_b[2][0] + src_a[1][1]*src_b[2][1] + src_a[2][1]*src_b[2][2] + src_a[3][1]*src_b[2][3]);
	dest[2][2] = dest[2][2] - (src_a[0][2]*src_b[2][0] + src_a[1][2]*src_b[2][1] + src_a[2][2]*src_b[2][2] + src_a[3][2]*src_b[2][3]);
	dest[2][3] = dest[2][3] - (src_a[0][3]*src_b[2][0] + src_a[1][3]*src_b[2][1] + src_a[2][3]*src_b[2][2] + src_a[3][3]*src_b[2][3]);

	dest[3][0] = dest[3][0] - (src_a[0][0]*src_b[3][0] + src_a[1][0]*src_b[3][1] + src_a[2][0]*src_b[3][2] + src_a[3][0]*src_b[3][3]);
	dest[3][1] = dest[3][1] - (src_a[0][1]*src_b[3][0] + src_a[1][1]*src_b[3][1] + src_a[2][1]*src_b[3][2] + src_a[3][1]*src_b[3][3]);
	dest[3][2] = dest[3][2] - (src_a[0][2]*src_b[3][0] + src_a[1][2]*src_b[3][1] + src_a[2][2]*src_b[3][2] + src_a[3][2]*src_b[3][3]);
	dest[3][3] = dest[3][3] - (src_a[0][3]*src_b[3][0] + src_a[1][3]*src_b[3][1] + src_a[2][3]*src_b[3][2] + src_a[3][3]*src_b[3][3]);	
}

inline void glmc_mat4f_identity(mat4f dest)
{
	dest[0][0] = 1.0f;
	dest[0][1] = 0;
	dest[0][2] = 0;
	dest[0][3] = 0;

	dest[1][0] = 0;
	dest[1][1] = 1.0f;
	dest[1][2] = 0;
	dest[1][3] = 0;

	dest[2][0] = 0;
	dest[2][1] = 0;
	dest[2][2] = 1.0f;
	dest[2][3] = 0;

	dest[3][0] = 0;
	dest[3][1] = 0;
	dest[3][2] = 0;
	dest[3][3] = 1.0f;
}
inline void glmc_mat4f_scale(mat4f dest, float src_sx, float src_sy, float src_sz)
{
	dest[0][0] = src_sx;
	dest[0][1] = 0;
	dest[0][2] = 0;
	dest[0][3] = 0;

	dest[1][0] = 0;
	dest[1][1] = src_sy;
	dest[1][2] = 0;
	dest[1][3] = 0;

	dest[2][0] = 0;
	dest[2][1] = 0;
	dest[2][2] = src_sz;
	dest[2][3] = 0;

	dest[3][0] = 0;
	dest[3][1] = 0;
	dest[3][2] = 0;
	dest[3][3] = 1.0f;
}
inline void glmc_mat4f_translation(mat4f dest, float src_t1, float src_t2, float src_t3)
{
	dest[0][0] = 1.0f;
	dest[0][1] = 0;
	dest[0][2] = 0;
	dest[0][3] = 0;

	dest[1][0] = 0;
	dest[1][1] = 1.0f;
	dest[1][2] = 0;
	dest[1][3] = 0;

	dest[2][0] = 0;
	dest[2][1] = 0;
	dest[2][2] = 1.0f;
	dest[2][3] = 0;

	dest[3][0] = src_t1;
	dest[3][1] = src_t2;
	dest[3][2] = src_t3;
	dest[3][3] = 1.0f;
}
inline void glmc_mat4f_rotation(mat4f dest, float src_ux, float src_uy, float src_uz, float theta)
{
	float c = cos(theta);
	float s = sin(theta);

	dest[0][0] = c + src_ux*src_ux*(1-c);
	dest[0][1] = src_uy*src_ux*(1-c) + src_uz*s;
	dest[0][2] = src_uz*src_ux*(1-c) - src_uy*s;
	dest[0][3] = 0;

	dest[1][0] = src_ux*src_uy*(1-c) - src_uz*s;
	dest[1][1] = c + src_uy*src_uy*(1-c);
	dest[1][2] = src_uz*src_uy*(1-c) + src_ux*(s);
	dest[1][3] = 0;

	dest[2][0] = src_ux*src_uz*(1-c) + src_uy*s;
	dest[2][1] = src_uy*src_uz*(1-c) - src_ux*s;
	dest[2][2] = c + src_uz*src_uz*(1-c);
	dest[2][3] = 0;

	dest[3][0] = 0;
	dest[3][1] = 0;
	dest[3][2] = 0;
	dest[3][3] = 1.0f;
}

inline void glmc_mat4f_perspective_projection(mat4f dest, float src_fovy, float src_aspect, float src_zNear, float src_zFar)
{
	float tanHalfFovy = tan(src_fovy/2);

	dest[0][0] = 1.0f/(src_aspect*tanHalfFovy);
	dest[0][1] = 0;
	dest[0][2] = 0;
	dest[0][3] = 0;

	dest[1][0] = 0;
	dest[1][1] = 1.0f/tanHalfFovy;
	dest[1][2] = 0;
	dest[1][3] = 0;

	dest[2][0] = 0;
	dest[2][1] = 0;
	dest[2][2] = src_zFar/(src_zFar - src_zNear);
	dest[2][3] = 1.0f;

	dest[3][0] = 0;
	dest[3][1] = 0;
	dest[3][2] = 0;
	dest[3][3] = -1.0f*(src_zFar*src_zNear)/(src_zFar - src_zNear);
}
inline void glmc_mat4f_ortho_projection(mat4f dest, float src_left, float src_right, float src_bottom, float src_top)
{
	dest[0][0] = 2.0f/(src_right - src_left);
	dest[0][1] = 1.0f;
	dest[0][2] = 1.0f;
	dest[0][3] = 1.0f;

	dest[1][0] = 1.0f;
	dest[1][1] = 2.0f/(src_top - src_bottom);
	dest[1][2] = 1.0f;
	dest[1][3] = 1.0f;

	dest[2][0] = 1.0f;
	dest[2][1] = 1.0f;
	dest[2][2] = 1.0f;
	dest[2][3] = 1.0f;

	dest[3][0] = -1.0f*(src_right + src_left)/(src_right - src_left);
	dest[3][1] = -1.0f*(src_top + src_bottom)/(src_top - src_bottom);
	dest[3][2] = 1.0f;
	dest[3][3] = 1.0f;
}