#include "PID.h"

#include <numeric>
#include <iostream>

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    first_iteration = true;
}

void PID::UpdateError(double cte) {
    if (first_iteration) {
        first_iteration = false;
        p_error = cte; // thereby set d-value to zero for first iteration
    }
    d_error = (cte - p_error); // delta t is 1 second; p_error is the value from last iteration
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return -(Kp * p_error + Ki * i_error + Kd * d_error);
}

