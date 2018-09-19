#include <stdio.h>
#include "glmc.h"

void print_2f(mat2f mat, int precision)
{
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<2; j++)
		{
			printf("%.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
}

void print_3f(mat3f mat, int precision)
{
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			printf("%.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
}

void print_4f(mat4f mat, int precision)
{
	for(int i = 0; i<4; i++)
	{
		for(int j = 0; j<4; j++)
		{
			printf("%.*f ",precision, mat[j][i]);
		}
		printf("\n");
	}
}

int main(int arg, char **argc)
{
	mat2f A = {{1,2}, {3,4}};
	mat2f B = {{1,0}, {0,1}};
	mat2f C;
	mat3f D = {{1,2,3}, {4,5,6}, {7,8,10}};
	mat3f E = {{1,0,0}, {0,1,0}, {0,0,1}};
	mat3f F;
	mat4f G = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
	mat4f H = {{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}};
	mat4f I;

	glmc_mat2f_transpose(C, A);
	print_2f(C, 0);

	glmc_mat3f_inverse(F,D);
	print_3f(F,2);

	glmc_mat4f_mul(I, G, H);
	print_4f(I, 0);

	return 0;
}