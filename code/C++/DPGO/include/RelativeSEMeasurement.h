#ifndef RELATIVESEMEASUREMENT_H
#define RELATIVESEMEASUREMENT_H

#include <iostream>
#include "DPGO_types.h"
#include <Eigen/Dense>

namespace DPGO {

/** A simple struct that contains the elements of a relative SE measurement
    from pose (r1, p1) to (r2, p2)
 */
struct RelativeSEMeasurement {
  /** 0-based index of first robot */
  size_t r1;

  /** 0-based index of second robot */
  size_t r2;

  /** 0-based index of first pose */
  size_t p1;

  /** 0-based index of second pose */
  size_t p2;

  /** Rotational measurement */
  Matrix R;

  /** Translational measurement */
  Matrix t;

  /** Rotational measurement precision */
  double kappa;

  /** Translational measurement precision */
  double tau;

  /** Simple default constructor; does nothing */
  RelativeSEMeasurement() {}

  /** Basic constructor */
  RelativeSEMeasurement(size_t first_robot, size_t second_robot,
                          size_t first_pose, size_t second_pose,
                          const Eigen::MatrixXd &relative_rotation,
                          const Eigen::VectorXd &relative_translation,
                          double rotational_precision,
                          double translational_precision)
      : r1(first_robot), r2(second_robot), 
        p1(first_pose), p2(second_pose), R(relative_rotation),
        t(relative_translation), kappa(rotational_precision),
        tau(translational_precision) {}

  /** A utility function for streaming Nodes to cout */
  inline friend std::ostream &
  operator<<(std::ostream &os, const RelativeSEMeasurement &measurement) {
    os << "r1: " << measurement.r1 << std::endl;
    os << "p1: " << measurement.p1 << std::endl;
    os << "r2: " << measurement.r2 << std::endl;
    os << "p2: " << measurement.p2 << std::endl;
    os << "R: " << std::endl << measurement.R << std::endl;
    os << "t: " << std::endl << measurement.t << std::endl;
    os << "Kappa: " << measurement.kappa << std::endl;
    os << "Tau: " << measurement.tau << std::endl;

    return os;
  }
};
};
#endif