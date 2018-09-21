#include <stdio.h>
#include "glmc.h"

void print_vec_2f(vec2f vec, int precision)
{
	for(int i = 0; i<2; i++)
	{
		printf("%8.*f ",precision, vec[i]);
		printf("\n");
	}
	printf("\n");
}
void print_vec_3f(vec3f vec, int precision)
{
	for(int i = 0; i<3; i++)
	{
		printf("%8.*f ",precision, vec[i]);
		printf("\n");
	}
	printf("\n");
}
void print_vec_4f(vec4f vec, int precision)
{
	for(int i = 0; i<4; i++)
	{
		printf("%8.*f ",precision, vec[i]);
		printf("\n");
	}
	printf("\n");
}

void print_mat_2f(mat2f mat, int precision)
{
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<2; j++)
		{
			printf("%8.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}
void print_mat_3f(mat3f mat, int precision)
{
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			printf("%8.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}
void print_mat_4f(mat4f mat, int precision)
{
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			printf("%8.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(int arg, char **argc)
{
	vec2f X2 = {0, 1};
	vec2f Y2 = {1, 3};
	vec2f Z2;

	glmc_vec2f_add(Z2, X2, Y2);
	print_vec_2f(Z2, 0);

	vec3f X3 = {7, 5, 8};
	vec3f Y3 = {1, 4 ,5};
	vec3f Z3;

	glmc_vec3f_normlize(Z3, X3);
	print_vec_3f(Z3, 4);

	vec4f X4 = {1, 2, 3, 4};
	vec4f Y4 = {1, 0, 0, 1};
	vec4f Z4;	

	glmc_vec4f_div(Z4, Y4, X4);
	print_vec_4f(Z4, 2);

	mat2f A2 = {{2,4}, {-3,-7}};
	mat2f B2 = {{1,0}, {0,1}};
	mat2f C2;

	glmc_mat2f_inverse(C2, A2);
	print_mat_2f(C2, 1);

	glmc_mat2f_transpose(C2, A2);
	print_mat_2f(C2, 0);

	
	mat3f A3 = {{1,2,3}, {4,5,6}, {7,8,10}};
	mat3f B3 = {{1,0,0}, {0,1,3}, {0,0,1}};
	mat3f C3;

	glmc_mat3f_div(C3,A3,B3);
	print_mat_3f(C3,0);

	
	mat4f A4 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4f B4 = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}};
	mat4f C4;

	glmc_mat4f_mul(C4, A4, B4);
	print_mat_4f(C4, 0);

	return 0;
}