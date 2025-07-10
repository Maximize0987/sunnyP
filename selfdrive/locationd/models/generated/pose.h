#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_1023796063612672548);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_365637776418829726);
void pose_H_mod_fun(double *state, double *out_3196048199274518526);
void pose_f_fun(double *state, double dt, double *out_6154479985514166504);
void pose_F_fun(double *state, double dt, double *out_7765851612513458719);
void pose_h_4(double *state, double *unused, double *out_1383274130387931186);
void pose_H_4(double *state, double *unused, double *out_2652033607477440195);
void pose_h_10(double *state, double *unused, double *out_4232344790676656617);
void pose_H_10(double *state, double *unused, double *out_607666458428180519);
void pose_h_13(double *state, double *unused, double *out_1877530148311847870);
void pose_H_13(double *state, double *unused, double *out_560240217854892606);
void pose_h_14(double *state, double *unused, double *out_7515914152585400517);
void pose_H_14(double *state, double *unused, double *out_1311207248862044334);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}