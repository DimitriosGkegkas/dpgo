#ifndef QUADRATICOPTIMIZER_H
#define QUADRATICOPTIMIZER_H

#include "manifold/LiftedSEManifold.h"
#include "manifold/LiftedSEVariable.h"
#include "manifold/LiftedSEVector.h"
#include "QuadraticProblem.h"
#include "distributed/PGOAgent.h"
#include "DPGO_types.h"

namespace DPGO{


	class QuadraticOptimizer{
	public:

		QuadraticOptimizer(QuadraticProblem* p);
		

		~QuadraticOptimizer();

		/**
		Optimize from the given initial guess
		*/
		Matrix optimize(const Matrix& Y) const;

		/**
		Optimize using chordal initialization
		*/
		Matrix optimize() const;

		/**
		Turn on/off verbose output
		*/
		void setVerbose(bool v) {verbose = v;}


		/**
		Set optimization algorithm
		*/
		void setAlgorithm(ROPTALG alg) {algorithm = alg;}


		/**
		Set maximum step size
		*/
		void setMaxStepsize(double s) {maxStepsize = s;}

	private:
		// Underlying Riemannian Optimization Problem
		QuadraticProblem* problem;

		// Optimization algorithm to be used
		ROPTALG algorithm;

		// Maximum step size
		double maxStepsize;

		// Verbose flag
		bool verbose;


	};

}




#endif