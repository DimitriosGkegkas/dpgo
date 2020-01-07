#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include "QuadraticProblem.h"

using namespace std;

/*Define the namespace*/
namespace AsynchPGO{

	QuadraticProblem::QuadraticProblem(unsigned int nIn, unsigned int dIn, unsigned int rIn, SparseMatrix& QIn, SparseMatrix& GIn)
	{
		n = nIn;
		d = dIn;
		r = rIn;
		Q = QIn;
		G = GIn;
	}

}