#include "matrix.h"


void Matrix::load_matrix(vector<vector<int> > m1,vector<vector<int> > m2,int A,int B,int C)
{
	matrix_1 = m1;
	matrix_2 = m2;	
	this->A = A;
	this->B = B;
	this->C = C;
}

vector<vector<int> > Matrix::matrix_mult()
{
	vector<vector<int> > result_mtx(A, vector<int> (C, 0));
	for (int i=0; i<A; i++)
	{
		for(int j=0; j<C; j++)
		{
			for (int k=0; k<B; k++)
			{
				result_mtx[i][j] += matrix_1[i][k] * matrix_2[k][j];
			}
		}
	}
	return result_mtx;
}


