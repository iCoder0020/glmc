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
}

inline float glmc_mat4f_determinant(mat4f mat)
{
	float mat4f_det;
	mat3f_det = + mat[0][0]*((mat[1][1]*((mat[2][2]*mat[3][3])-(mat[2][3]*mat[3][2]))) - (mat[1][2]*((mat[2][1]*mat[3][3])-(mat[2][3]*mat[3][1]))) + (mat[1][3]*((mat[2][1]*mat[3][2])-(mat[2][2]*mat[3][1]))))
				- mat[0][1]*((mat[1][0]*((mat[2][2]*mat[3][3])-(mat[2][3]*mat[3][2]))) - (mat[1][2]*((mat[2][0]*mat[3][3])-(mat[2][3]*mat[3][0]))) + (mat[1][3]*((mat[2][0]*mat[3][2])-(mat[2][2]*mat[3][1]))))
				+ mat[0][2]*((mat[1][0]*((mat[2][1]*mat[3][3])-(mat[2][3]*mat[3][1]))) - (mat[1][1]*((mat[2][0]*mat[3][3])-(mat[2][3]*mat[3][0]))) + (mat[1][3]*((mat[2][0]*mat[3][1])-(mat[2][1]*mat[3][0]))))
				- mat[0][3]*((mat[1][0]*((mat[2][1]*mat[3][2])-(mat[2][2]*mat[3][1]))) - (mat[1][1]*((mat[2][0]*mat[3][2])-(mat[2][2]*mat[3][0]))) + (mat[1][2]*((mat[2][0]*mat[3][1])-(mat[2][1]*mat[3][0]))));
	return mat4f_det;
}

inline void glmc_mat4f_inverse(mat4f dest, mat4f src)
{
	float mat4f_det;
	mat4f_det = glmc_mat4f_determinant(src);

	dest[0][0] = (src[1][1]*src[2][2] - src[1][2]*src[2][1])/mat4f_det;
	dest[0][1] = (src[0][2]*src[2][1] - src[0][1]*src[2][2])/mat4f_det;
	dest[0][2] = (src[0][1]*src[1][2] - src[0][2]*src[1][1])/mat4f_det;

	dest[1][0] = (src[1][2]*src[2][0] - src[1][0]*src[2][2])/mat4f_det;
	dest[1][1] = (src[0][0]*src[2][2] - src[0][2]*src[2][0])/mat4f_det;
	dest[1][2] = (src[0][2]*src[1][0] - src[0][0]*src[1][2])/mat4f_det;

	dest[2][0] = (src[1][0]*src[2][1] - src[1][1]*src[2][0])/mat4f_det;
	dest[2][1] = (src[0][1]*src[2][0] - src[0][0]*src[2][1])/mat4f_det;
	dest[2][2] = (src[0][0]*src[1][1] - src[0][1]*src[1][0])/mat4f_det;	
}

inline void glmc_mat4f_normlize(mat4f dest, mat4f src)
{
	float mat4f_det;
	mat4f_det = glmc_mat4f_determinant(src);

	dest[0][0] = src[0][0]/mat4f_det;
	dest[0][1] = src[0][1]/mat4f_det;
	dest[0][2] = src[0][2]/mat4f_det;
	dest[0][3] = src[0][3]/mat4f_det;

	dest[1][0] = src[1][0]/mat4f_det;
	dest[1][1] = src[1][1]/mat4f_det;
	dest[1][2] = src[1][2]/mat4f_det;
	dest[1][3] = src[1][3]/mat4f_det;

	dest[2][0] = src[2][0]/mat4f_det;
	dest[2][1] = src[2][1]/mat4f_det;
	dest[2][2] = src[2][2]/mat4f_det;
	dest[2][3] = src[2][3]/mat4f_det;
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
}

inline void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = (src_a[0][0]*src_b[0][0] + src_a[0][1]*src_b[1][0] + src_a[0][2]*src_b[2][0] + src_a[0][3]*src_b[3][0]);
	dest[0][1] = (src_a[0][0]*src_b[0][1] + src_a[0][1]*src_b[1][1] + src_a[0][2]*src_b[2][1] + src_a[0][3]*src_b[3][1]);
	dest[0][2] = (src_a[0][0]*src_b[0][2] + src_a[0][1]*src_b[1][2] + src_a[0][2]*src_b[2][2]);

	dest[1][0] = (src_a[1][0]*src_b[0][0] + src_a[1][1]*src_b[1][0] + src_a[1][2]*src_b[2][0]);
	dest[1][1] = (src_a[1][0]*src_b[0][1] + src_a[1][1]*src_b[1][1] + src_a[1][2]*src_b[2][1]);
	dest[1][2] = (src_a[1][0]*src_b[0][2] + src_a[1][1]*src_b[1][2] + src_a[1][2]*src_b[2][2]);

	dest[2][0] = (src_a[2][0]*src_b[0][0] + src_a[2][1]*src_b[1][0] + src_a[2][2]*src_b[2][0]);
	dest[2][1] = (src_a[2][0]*src_b[0][1] + src_a[2][1]*src_b[1][1] + src_a[2][2]*src_b[2][1]);
	dest[2][2] = (src_a[2][0]*src_b[0][2] + src_a[2][1]*src_b[1][2] + src_a[2][2]*src_b[2][2]);
}
inline void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b)
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

inline void glmc_mat4f_div(mat4f dest, mat4f src_a, mat4f src_b)
{
	mat4f src_b_inv;
	glmc_mat4f_inverse(src_b_inv, src_b);
	glmc_mat4f_mul(dest, src_a, src_b_inv);
}
inline void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b)
{
	dest[0][0] = src_a[0][0] / src_b;
	dest[0][1] = src_a[0][1] / src_b;
	dest[0][2] = src_a[0][2] / src_b;

	dest[1][0] = src_a[1][0] / src_b;
	dest[1][1] = src_a[1][1] / src_b;
	dest[1][2] = src_a[1][2] / src_b;

	dest[2][0] = src_a[2][0] / src_b;
	dest[2][1] = src_a[2][1] / src_b;
	dest[2][2] = src_a[2][2] / src_b;
}

inline void glmc_mat4f_madd(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = dest[0][0] + (src_a[0][0]*src_b[0][0] + src_a[0][1]*src_b[1][0] + src_a[0][2]*src_b[2][0]);
	dest[0][1] = dest[0][1] + (src_a[0][0]*src_b[0][1] + src_a[0][1]*src_b[1][1] + src_a[0][2]*src_b[2][1]);
	dest[0][2] = dest[0][2] + (src_a[0][0]*src_b[0][2] + src_a[0][1]*src_b[1][2] + src_a[0][2]*src_b[2][2]);

	dest[1][0] = dest[1][0] + (src_a[1][0]*src_b[0][0] + src_a[1][1]*src_b[1][0] + src_a[1][2]*src_b[2][0]);
	dest[1][1] = dest[1][1] + (src_a[1][0]*src_b[0][1] + src_a[1][1]*src_b[1][1] + src_a[1][2]*src_b[2][1]);
	dest[1][2] = dest[1][2] + (src_a[1][0]*src_b[0][2] + src_a[1][1]*src_b[1][2] + src_a[1][2]*src_b[2][2]);

	dest[2][0] = dest[2][0] + (src_a[2][0]*src_b[0][0] + src_a[2][1]*src_b[1][0] + src_a[2][2]*src_b[2][0]);
	dest[2][1] = dest[2][1] + (src_a[2][0]*src_b[0][1] + src_a[2][1]*src_b[1][1] + src_a[2][2]*src_b[2][1]);
	dest[2][2] = dest[2][2] + (src_a[2][0]*src_b[0][2] + src_a[2][1]*src_b[1][2] + src_a[2][2]*src_b[2][2]);
}
inline void glmc_mat4f_msub(mat4f dest, mat4f src_a, mat4f src_b)
{
	dest[0][0] = dest[0][0] - (src_a[0][0]*src_b[0][0] + src_a[0][1]*src_b[1][0] + src_a[0][2]*src_b[2][0]);
	dest[0][1] = dest[0][1] - (src_a[0][0]*src_b[0][1] + src_a[0][1]*src_b[1][1] + src_a[0][2]*src_b[2][1]);
	dest[0][2] = dest[0][2] - (src_a[0][0]*src_b[0][2] + src_a[0][1]*src_b[1][2] + src_a[0][2]*src_b[2][2]);

	dest[1][0] = dest[1][0] - (src_a[1][0]*src_b[0][0] + src_a[1][1]*src_b[1][0] + src_a[1][2]*src_b[2][0]);
	dest[1][1] = dest[1][1] - (src_a[1][0]*src_b[0][1] + src_a[1][1]*src_b[1][1] + src_a[1][2]*src_b[2][1]);
	dest[1][2] = dest[1][2] - (src_a[1][0]*src_b[0][2] + src_a[1][1]*src_b[1][2] + src_a[1][2]*src_b[2][2]);

	dest[2][0] = dest[2][0] - (src_a[2][0]*src_b[0][0] + src_a[2][1]*src_b[1][0] + src_a[2][2]*src_b[2][0]);
	dest[2][1] = dest[2][1] - (src_a[2][0]*src_b[0][1] + src_a[2][1]*src_b[1][1] + src_a[2][2]*src_b[2][1]);
	dest[2][2] = dest[2][2] - (src_a[2][0]*src_b[0][2] + src_a[2][1]*src_b[1][2] + src_a[2][2]*src_b[2][2]);
}