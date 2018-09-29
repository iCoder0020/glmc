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

inline void glmc_mat2f_mul_vec2f(vec2f dest, mat2f mat, vec2f vec)
{
	dest[0] = mat[0][0]*vec[0] + mat[1][0]*vec[1];
	dest[1] = mat[0][1]*vec[0] + mat[1][1]*vec[1];
}

inline void glmc_mat3f_mul_vec3f(vec3f dest, mat3f mat, vec3f vec)
{
	dest[0] = mat[0][0]*vec[0] + mat[1][0]*vec[1] + mat[2][0]*vec[2];
	dest[1] = mat[0][1]*vec[0] + mat[1][1]*vec[1] + mat[2][1]*vec[2];
	dest[2] = mat[0][2]*vec[0] + mat[1][2]*vec[1] + mat[2][2]*vec[2];
}

inline void glmc_mat4f_mul_vec4f(vec4f dest, mat4f mat, vec4f vec)
{
	dest[0] = mat[0][0]*vec[0] + mat[1][0]*vec[1] + mat[2][0]*vec[2] + mat[3][0]*vec[3];
	dest[1] = mat[0][1]*vec[0] + mat[1][1]*vec[1] + mat[2][1]*vec[2] + mat[3][1]*vec[3];
	dest[2] = mat[0][2]*vec[0] + mat[1][2]*vec[1] + mat[2][2]*vec[2] + mat[3][2]*vec[3];
	dest[3] = mat[0][3]*vec[0] + mat[1][3]*vec[1] + mat[2][3]*vec[2] + mat[3][3]*vec[3];
}

