#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6358402730729926467) {
   out_6358402730729926467[0] = delta_x[0] + nom_x[0];
   out_6358402730729926467[1] = delta_x[1] + nom_x[1];
   out_6358402730729926467[2] = delta_x[2] + nom_x[2];
   out_6358402730729926467[3] = delta_x[3] + nom_x[3];
   out_6358402730729926467[4] = delta_x[4] + nom_x[4];
   out_6358402730729926467[5] = delta_x[5] + nom_x[5];
   out_6358402730729926467[6] = delta_x[6] + nom_x[6];
   out_6358402730729926467[7] = delta_x[7] + nom_x[7];
   out_6358402730729926467[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7996874691220589591) {
   out_7996874691220589591[0] = -nom_x[0] + true_x[0];
   out_7996874691220589591[1] = -nom_x[1] + true_x[1];
   out_7996874691220589591[2] = -nom_x[2] + true_x[2];
   out_7996874691220589591[3] = -nom_x[3] + true_x[3];
   out_7996874691220589591[4] = -nom_x[4] + true_x[4];
   out_7996874691220589591[5] = -nom_x[5] + true_x[5];
   out_7996874691220589591[6] = -nom_x[6] + true_x[6];
   out_7996874691220589591[7] = -nom_x[7] + true_x[7];
   out_7996874691220589591[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3303086367325051303) {
   out_3303086367325051303[0] = 1.0;
   out_3303086367325051303[1] = 0.0;
   out_3303086367325051303[2] = 0.0;
   out_3303086367325051303[3] = 0.0;
   out_3303086367325051303[4] = 0.0;
   out_3303086367325051303[5] = 0.0;
   out_3303086367325051303[6] = 0.0;
   out_3303086367325051303[7] = 0.0;
   out_3303086367325051303[8] = 0.0;
   out_3303086367325051303[9] = 0.0;
   out_3303086367325051303[10] = 1.0;
   out_3303086367325051303[11] = 0.0;
   out_3303086367325051303[12] = 0.0;
   out_3303086367325051303[13] = 0.0;
   out_3303086367325051303[14] = 0.0;
   out_3303086367325051303[15] = 0.0;
   out_3303086367325051303[16] = 0.0;
   out_3303086367325051303[17] = 0.0;
   out_3303086367325051303[18] = 0.0;
   out_3303086367325051303[19] = 0.0;
   out_3303086367325051303[20] = 1.0;
   out_3303086367325051303[21] = 0.0;
   out_3303086367325051303[22] = 0.0;
   out_3303086367325051303[23] = 0.0;
   out_3303086367325051303[24] = 0.0;
   out_3303086367325051303[25] = 0.0;
   out_3303086367325051303[26] = 0.0;
   out_3303086367325051303[27] = 0.0;
   out_3303086367325051303[28] = 0.0;
   out_3303086367325051303[29] = 0.0;
   out_3303086367325051303[30] = 1.0;
   out_3303086367325051303[31] = 0.0;
   out_3303086367325051303[32] = 0.0;
   out_3303086367325051303[33] = 0.0;
   out_3303086367325051303[34] = 0.0;
   out_3303086367325051303[35] = 0.0;
   out_3303086367325051303[36] = 0.0;
   out_3303086367325051303[37] = 0.0;
   out_3303086367325051303[38] = 0.0;
   out_3303086367325051303[39] = 0.0;
   out_3303086367325051303[40] = 1.0;
   out_3303086367325051303[41] = 0.0;
   out_3303086367325051303[42] = 0.0;
   out_3303086367325051303[43] = 0.0;
   out_3303086367325051303[44] = 0.0;
   out_3303086367325051303[45] = 0.0;
   out_3303086367325051303[46] = 0.0;
   out_3303086367325051303[47] = 0.0;
   out_3303086367325051303[48] = 0.0;
   out_3303086367325051303[49] = 0.0;
   out_3303086367325051303[50] = 1.0;
   out_3303086367325051303[51] = 0.0;
   out_3303086367325051303[52] = 0.0;
   out_3303086367325051303[53] = 0.0;
   out_3303086367325051303[54] = 0.0;
   out_3303086367325051303[55] = 0.0;
   out_3303086367325051303[56] = 0.0;
   out_3303086367325051303[57] = 0.0;
   out_3303086367325051303[58] = 0.0;
   out_3303086367325051303[59] = 0.0;
   out_3303086367325051303[60] = 1.0;
   out_3303086367325051303[61] = 0.0;
   out_3303086367325051303[62] = 0.0;
   out_3303086367325051303[63] = 0.0;
   out_3303086367325051303[64] = 0.0;
   out_3303086367325051303[65] = 0.0;
   out_3303086367325051303[66] = 0.0;
   out_3303086367325051303[67] = 0.0;
   out_3303086367325051303[68] = 0.0;
   out_3303086367325051303[69] = 0.0;
   out_3303086367325051303[70] = 1.0;
   out_3303086367325051303[71] = 0.0;
   out_3303086367325051303[72] = 0.0;
   out_3303086367325051303[73] = 0.0;
   out_3303086367325051303[74] = 0.0;
   out_3303086367325051303[75] = 0.0;
   out_3303086367325051303[76] = 0.0;
   out_3303086367325051303[77] = 0.0;
   out_3303086367325051303[78] = 0.0;
   out_3303086367325051303[79] = 0.0;
   out_3303086367325051303[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_3768865974634682340) {
   out_3768865974634682340[0] = state[0];
   out_3768865974634682340[1] = state[1];
   out_3768865974634682340[2] = state[2];
   out_3768865974634682340[3] = state[3];
   out_3768865974634682340[4] = state[4];
   out_3768865974634682340[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_3768865974634682340[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_3768865974634682340[7] = state[7];
   out_3768865974634682340[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7093580824576810369) {
   out_7093580824576810369[0] = 1;
   out_7093580824576810369[1] = 0;
   out_7093580824576810369[2] = 0;
   out_7093580824576810369[3] = 0;
   out_7093580824576810369[4] = 0;
   out_7093580824576810369[5] = 0;
   out_7093580824576810369[6] = 0;
   out_7093580824576810369[7] = 0;
   out_7093580824576810369[8] = 0;
   out_7093580824576810369[9] = 0;
   out_7093580824576810369[10] = 1;
   out_7093580824576810369[11] = 0;
   out_7093580824576810369[12] = 0;
   out_7093580824576810369[13] = 0;
   out_7093580824576810369[14] = 0;
   out_7093580824576810369[15] = 0;
   out_7093580824576810369[16] = 0;
   out_7093580824576810369[17] = 0;
   out_7093580824576810369[18] = 0;
   out_7093580824576810369[19] = 0;
   out_7093580824576810369[20] = 1;
   out_7093580824576810369[21] = 0;
   out_7093580824576810369[22] = 0;
   out_7093580824576810369[23] = 0;
   out_7093580824576810369[24] = 0;
   out_7093580824576810369[25] = 0;
   out_7093580824576810369[26] = 0;
   out_7093580824576810369[27] = 0;
   out_7093580824576810369[28] = 0;
   out_7093580824576810369[29] = 0;
   out_7093580824576810369[30] = 1;
   out_7093580824576810369[31] = 0;
   out_7093580824576810369[32] = 0;
   out_7093580824576810369[33] = 0;
   out_7093580824576810369[34] = 0;
   out_7093580824576810369[35] = 0;
   out_7093580824576810369[36] = 0;
   out_7093580824576810369[37] = 0;
   out_7093580824576810369[38] = 0;
   out_7093580824576810369[39] = 0;
   out_7093580824576810369[40] = 1;
   out_7093580824576810369[41] = 0;
   out_7093580824576810369[42] = 0;
   out_7093580824576810369[43] = 0;
   out_7093580824576810369[44] = 0;
   out_7093580824576810369[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7093580824576810369[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7093580824576810369[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7093580824576810369[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7093580824576810369[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7093580824576810369[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7093580824576810369[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7093580824576810369[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7093580824576810369[53] = -9.8000000000000007*dt;
   out_7093580824576810369[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7093580824576810369[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7093580824576810369[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7093580824576810369[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7093580824576810369[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7093580824576810369[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7093580824576810369[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7093580824576810369[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7093580824576810369[62] = 0;
   out_7093580824576810369[63] = 0;
   out_7093580824576810369[64] = 0;
   out_7093580824576810369[65] = 0;
   out_7093580824576810369[66] = 0;
   out_7093580824576810369[67] = 0;
   out_7093580824576810369[68] = 0;
   out_7093580824576810369[69] = 0;
   out_7093580824576810369[70] = 1;
   out_7093580824576810369[71] = 0;
   out_7093580824576810369[72] = 0;
   out_7093580824576810369[73] = 0;
   out_7093580824576810369[74] = 0;
   out_7093580824576810369[75] = 0;
   out_7093580824576810369[76] = 0;
   out_7093580824576810369[77] = 0;
   out_7093580824576810369[78] = 0;
   out_7093580824576810369[79] = 0;
   out_7093580824576810369[80] = 1;
}
void h_25(double *state, double *unused, double *out_7167534617944694236) {
   out_7167534617944694236[0] = state[6];
}
void H_25(double *state, double *unused, double *out_5950469480472263076) {
   out_5950469480472263076[0] = 0;
   out_5950469480472263076[1] = 0;
   out_5950469480472263076[2] = 0;
   out_5950469480472263076[3] = 0;
   out_5950469480472263076[4] = 0;
   out_5950469480472263076[5] = 0;
   out_5950469480472263076[6] = 1;
   out_5950469480472263076[7] = 0;
   out_5950469480472263076[8] = 0;
}
void h_24(double *state, double *unused, double *out_7538477621652212773) {
   out_7538477621652212773[0] = state[4];
   out_7538477621652212773[1] = state[5];
}
void H_24(double *state, double *unused, double *out_3777819881466763510) {
   out_3777819881466763510[0] = 0;
   out_3777819881466763510[1] = 0;
   out_3777819881466763510[2] = 0;
   out_3777819881466763510[3] = 0;
   out_3777819881466763510[4] = 1;
   out_3777819881466763510[5] = 0;
   out_3777819881466763510[6] = 0;
   out_3777819881466763510[7] = 0;
   out_3777819881466763510[8] = 0;
   out_3777819881466763510[9] = 0;
   out_3777819881466763510[10] = 0;
   out_3777819881466763510[11] = 0;
   out_3777819881466763510[12] = 0;
   out_3777819881466763510[13] = 0;
   out_3777819881466763510[14] = 1;
   out_3777819881466763510[15] = 0;
   out_3777819881466763510[16] = 0;
   out_3777819881466763510[17] = 0;
}
void h_30(double *state, double *unused, double *out_293024146304194089) {
   out_293024146304194089[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1422773150344654878) {
   out_1422773150344654878[0] = 0;
   out_1422773150344654878[1] = 0;
   out_1422773150344654878[2] = 0;
   out_1422773150344654878[3] = 0;
   out_1422773150344654878[4] = 1;
   out_1422773150344654878[5] = 0;
   out_1422773150344654878[6] = 0;
   out_1422773150344654878[7] = 0;
   out_1422773150344654878[8] = 0;
}
void h_26(double *state, double *unused, double *out_650485706597468346) {
   out_650485706597468346[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2208966161598206852) {
   out_2208966161598206852[0] = 0;
   out_2208966161598206852[1] = 0;
   out_2208966161598206852[2] = 0;
   out_2208966161598206852[3] = 0;
   out_2208966161598206852[4] = 0;
   out_2208966161598206852[5] = 0;
   out_2208966161598206852[6] = 0;
   out_2208966161598206852[7] = 1;
   out_2208966161598206852[8] = 0;
}
void h_27(double *state, double *unused, double *out_6277536188104011735) {
   out_6277536188104011735[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3646367221528598095) {
   out_3646367221528598095[0] = 0;
   out_3646367221528598095[1] = 0;
   out_3646367221528598095[2] = 0;
   out_3646367221528598095[3] = 1;
   out_3646367221528598095[4] = 0;
   out_3646367221528598095[5] = 0;
   out_3646367221528598095[6] = 0;
   out_3646367221528598095[7] = 0;
   out_3646367221528598095[8] = 0;
}
void h_29(double *state, double *unused, double *out_4708649121356651556) {
   out_4708649121356651556[0] = state[1];
}
void H_29(double *state, double *unused, double *out_1933004494659047062) {
   out_1933004494659047062[0] = 0;
   out_1933004494659047062[1] = 1;
   out_1933004494659047062[2] = 0;
   out_1933004494659047062[3] = 0;
   out_1933004494659047062[4] = 0;
   out_1933004494659047062[5] = 0;
   out_1933004494659047062[6] = 0;
   out_1933004494659047062[7] = 0;
   out_1933004494659047062[8] = 0;
}
void h_28(double *state, double *unused, double *out_8657707560738230084) {
   out_8657707560738230084[0] = state[0];
}
void H_28(double *state, double *unused, double *out_3896634766224373313) {
   out_3896634766224373313[0] = 1;
   out_3896634766224373313[1] = 0;
   out_3896634766224373313[2] = 0;
   out_3896634766224373313[3] = 0;
   out_3896634766224373313[4] = 0;
   out_3896634766224373313[5] = 0;
   out_3896634766224373313[6] = 0;
   out_3896634766224373313[7] = 0;
   out_3896634766224373313[8] = 0;
}
void h_31(double *state, double *unused, double *out_3530085089690671886) {
   out_3530085089690671886[0] = state[8];
}
void H_31(double *state, double *unused, double *out_5981115442349223504) {
   out_5981115442349223504[0] = 0;
   out_5981115442349223504[1] = 0;
   out_5981115442349223504[2] = 0;
   out_5981115442349223504[3] = 0;
   out_5981115442349223504[4] = 0;
   out_5981115442349223504[5] = 0;
   out_5981115442349223504[6] = 0;
   out_5981115442349223504[7] = 0;
   out_5981115442349223504[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_6358402730729926467) {
  err_fun(nom_x, delta_x, out_6358402730729926467);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7996874691220589591) {
  inv_err_fun(nom_x, true_x, out_7996874691220589591);
}
void car_H_mod_fun(double *state, double *out_3303086367325051303) {
  H_mod_fun(state, out_3303086367325051303);
}
void car_f_fun(double *state, double dt, double *out_3768865974634682340) {
  f_fun(state,  dt, out_3768865974634682340);
}
void car_F_fun(double *state, double dt, double *out_7093580824576810369) {
  F_fun(state,  dt, out_7093580824576810369);
}
void car_h_25(double *state, double *unused, double *out_7167534617944694236) {
  h_25(state, unused, out_7167534617944694236);
}
void car_H_25(double *state, double *unused, double *out_5950469480472263076) {
  H_25(state, unused, out_5950469480472263076);
}
void car_h_24(double *state, double *unused, double *out_7538477621652212773) {
  h_24(state, unused, out_7538477621652212773);
}
void car_H_24(double *state, double *unused, double *out_3777819881466763510) {
  H_24(state, unused, out_3777819881466763510);
}
void car_h_30(double *state, double *unused, double *out_293024146304194089) {
  h_30(state, unused, out_293024146304194089);
}
void car_H_30(double *state, double *unused, double *out_1422773150344654878) {
  H_30(state, unused, out_1422773150344654878);
}
void car_h_26(double *state, double *unused, double *out_650485706597468346) {
  h_26(state, unused, out_650485706597468346);
}
void car_H_26(double *state, double *unused, double *out_2208966161598206852) {
  H_26(state, unused, out_2208966161598206852);
}
void car_h_27(double *state, double *unused, double *out_6277536188104011735) {
  h_27(state, unused, out_6277536188104011735);
}
void car_H_27(double *state, double *unused, double *out_3646367221528598095) {
  H_27(state, unused, out_3646367221528598095);
}
void car_h_29(double *state, double *unused, double *out_4708649121356651556) {
  h_29(state, unused, out_4708649121356651556);
}
void car_H_29(double *state, double *unused, double *out_1933004494659047062) {
  H_29(state, unused, out_1933004494659047062);
}
void car_h_28(double *state, double *unused, double *out_8657707560738230084) {
  h_28(state, unused, out_8657707560738230084);
}
void car_H_28(double *state, double *unused, double *out_3896634766224373313) {
  H_28(state, unused, out_3896634766224373313);
}
void car_h_31(double *state, double *unused, double *out_3530085089690671886) {
  h_31(state, unused, out_3530085089690671886);
}
void car_H_31(double *state, double *unused, double *out_5981115442349223504) {
  H_31(state, unused, out_5981115442349223504);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
