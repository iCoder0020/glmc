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

void glmc_mat3f_transpose(mat3f dest, mat3f src)
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

float glmc_mat3f_determinant(mat3f mat)
{
	float mat3f_det;
	mat3f_det = (mat[0][0]*((mat[1][1]*mat[2][2])-(mat[1][2]*mat[2][1]))) - (mat[0][1]*((mat[1][0]*mat[2][2])-(mat[1][2]*mat[2][0]))) + (mat[0][2]*((mat[1][0]*mat[2][1])-(mat[1][1]*mat[2][0])));
	return mat3f_det;
}

void glmc_mat3f_inverse(mat3f dest, mat3f src)
{
	float mat3f_det;
	mat3f_det = glmc_mat3f_determinant(src);

	dest[0][0] = (src[1][1]*src[2][2] - src[1][2]*src[2][1])/mat3f_det;
	dest[0][1] = (src[0][2]*src[2][1] - src[0][1]*src[2][2])/mat3f_det;
	dest[0][2] = (src[0][1]*src[1][2] - src[0][2]*src[1][1])/mat3f_det;

	dest[1][0] = (src[1][2]*src[2][0] - src[1][0]*src[2][2])/mat3f_det;
	dest[1][1] = (src[0][0]*src[2][2] - src[0][2]*src[2][0])/mat3f_det;
	dest[1][2] = (src[0][2]*src[1][0] - src[0][0]*src[1][2])/mat3f_det;

	dest[2][0] = (src[1][0]*src[2][1] - src[1][1]*src[2][0])/mat3f_det;
	dest[2][1] = (src[0][1]*src[2][0] - src[0][0]*src[2][1])/mat3f_det;
	dest[2][2] = (src[0][0]*src[1][1] - src[0][1]*src[1][0])/mat3f_det;	
}

void glmc_mat3f_normlize(mat3f dest, mat3f src)
{
	float mat3f_det;
	mat3f_det = glmc_mat3f_determinant(src);

	dest[0][0] = src[0][0]/mat3f_det;
	dest[0][1] = src[0][1]/mat3f_det;
	dest[0][2] = src[0][2]/mat3f_det;

	dest[1][0] = src[1][0]/mat3f_det;
	dest[1][1] = src[1][1]/mat3f_det;
	dest[1][2] = src[1][2]/mat3f_det;

	dest[2][0] = src[2][0]/mat3f_det;
	dest[2][1] = src[2][1]/mat3f_det;
	dest[2][2] = src[2][2]/mat3f_det;
}

void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b)
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

void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b)
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

void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b)
{
	dest[0][0] = (src_a[0][0]*src_b[0][0] + src_a[0][1]*src_b[1][0] + src_a[0][2]*src_b[2][0]);
	dest[0][1] = (src_a[0][0]*src_b[0][1] + src_a[0][1]*src_b[1][1] + src_a[0][2]*src_b[2][1]);
	dest[0][2] = (src_a[0][0]*src_b[0][2] + src_a[0][1]*src_b[1][2] + src_a[0][2]*src_b[2][2]);

	dest[1][0] = (src_a[1][0]*src_b[0][0] + src_a[1][1]*src_b[1][0] + src_a[1][2]*src_b[2][0]);
	dest[1][1] = (src_a[1][0]*src_b[0][1] + src_a[1][1]*src_b[1][1] + src_a[1][2]*src_b[2][1]);
	dest[1][2] = (src_a[1][0]*src_b[0][2] + src_a[1][1]*src_b[1][2] + src_a[1][2]*src_b[2][2]);

	dest[2][0] = (src_a[2][0]*src_b[0][0] + src_a[2][1]*src_b[1][0] + src_a[2][2]*src_b[2][0]);
	dest[2][1] = (src_a[2][0]*src_b[0][1] + src_a[2][1]*src_b[1][1] + src_a[2][2]*src_b[2][1]);
	dest[2][2] = (src_a[2][0]*src_b[0][2] + src_a[2][1]*src_b[1][2] + src_a[2][2]*src_b[2][2]);
}
void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b)
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

void glmc_mat3f_div(mat3f dest, mat3f src_a, mat3f src_b)
{
	mat3f src_b_inv;
	glmc_mat3f_inverse(src_b_inv, src_b);
	glmc_mat3f_mul(dest, src_a, src_b_inv);
}
void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b)
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

void glmc_mat3f_madd(mat3f dest, mat3f src_a, mat3f src_b)
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
void glmc_mat3f_msub(mat3f dest, mat3f src_a, mat3f src_b)
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