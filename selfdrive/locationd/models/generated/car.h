#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6358402730729926467);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7996874691220589591);
void car_H_mod_fun(double *state, double *out_3303086367325051303);
void car_f_fun(double *state, double dt, double *out_3768865974634682340);
void car_F_fun(double *state, double dt, double *out_7093580824576810369);
void car_h_25(double *state, double *unused, double *out_7167534617944694236);
void car_H_25(double *state, double *unused, double *out_5950469480472263076);
void car_h_24(double *state, double *unused, double *out_7538477621652212773);
void car_H_24(double *state, double *unused, double *out_3777819881466763510);
void car_h_30(double *state, double *unused, double *out_293024146304194089);
void car_H_30(double *state, double *unused, double *out_1422773150344654878);
void car_h_26(double *state, double *unused, double *out_650485706597468346);
void car_H_26(double *state, double *unused, double *out_2208966161598206852);
void car_h_27(double *state, double *unused, double *out_6277536188104011735);
void car_H_27(double *state, double *unused, double *out_3646367221528598095);
void car_h_29(double *state, double *unused, double *out_4708649121356651556);
void car_H_29(double *state, double *unused, double *out_1933004494659047062);
void car_h_28(double *state, double *unused, double *out_8657707560738230084);
void car_H_28(double *state, double *unused, double *out_3896634766224373313);
void car_h_31(double *state, double *unused, double *out_3530085089690671886);
void car_H_31(double *state, double *unused, double *out_5981115442349223504);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}