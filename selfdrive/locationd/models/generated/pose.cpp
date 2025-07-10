#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_1023796063612672548) {
   out_1023796063612672548[0] = delta_x[0] + nom_x[0];
   out_1023796063612672548[1] = delta_x[1] + nom_x[1];
   out_1023796063612672548[2] = delta_x[2] + nom_x[2];
   out_1023796063612672548[3] = delta_x[3] + nom_x[3];
   out_1023796063612672548[4] = delta_x[4] + nom_x[4];
   out_1023796063612672548[5] = delta_x[5] + nom_x[5];
   out_1023796063612672548[6] = delta_x[6] + nom_x[6];
   out_1023796063612672548[7] = delta_x[7] + nom_x[7];
   out_1023796063612672548[8] = delta_x[8] + nom_x[8];
   out_1023796063612672548[9] = delta_x[9] + nom_x[9];
   out_1023796063612672548[10] = delta_x[10] + nom_x[10];
   out_1023796063612672548[11] = delta_x[11] + nom_x[11];
   out_1023796063612672548[12] = delta_x[12] + nom_x[12];
   out_1023796063612672548[13] = delta_x[13] + nom_x[13];
   out_1023796063612672548[14] = delta_x[14] + nom_x[14];
   out_1023796063612672548[15] = delta_x[15] + nom_x[15];
   out_1023796063612672548[16] = delta_x[16] + nom_x[16];
   out_1023796063612672548[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_365637776418829726) {
   out_365637776418829726[0] = -nom_x[0] + true_x[0];
   out_365637776418829726[1] = -nom_x[1] + true_x[1];
   out_365637776418829726[2] = -nom_x[2] + true_x[2];
   out_365637776418829726[3] = -nom_x[3] + true_x[3];
   out_365637776418829726[4] = -nom_x[4] + true_x[4];
   out_365637776418829726[5] = -nom_x[5] + true_x[5];
   out_365637776418829726[6] = -nom_x[6] + true_x[6];
   out_365637776418829726[7] = -nom_x[7] + true_x[7];
   out_365637776418829726[8] = -nom_x[8] + true_x[8];
   out_365637776418829726[9] = -nom_x[9] + true_x[9];
   out_365637776418829726[10] = -nom_x[10] + true_x[10];
   out_365637776418829726[11] = -nom_x[11] + true_x[11];
   out_365637776418829726[12] = -nom_x[12] + true_x[12];
   out_365637776418829726[13] = -nom_x[13] + true_x[13];
   out_365637776418829726[14] = -nom_x[14] + true_x[14];
   out_365637776418829726[15] = -nom_x[15] + true_x[15];
   out_365637776418829726[16] = -nom_x[16] + true_x[16];
   out_365637776418829726[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3196048199274518526) {
   out_3196048199274518526[0] = 1.0;
   out_3196048199274518526[1] = 0.0;
   out_3196048199274518526[2] = 0.0;
   out_3196048199274518526[3] = 0.0;
   out_3196048199274518526[4] = 0.0;
   out_3196048199274518526[5] = 0.0;
   out_3196048199274518526[6] = 0.0;
   out_3196048199274518526[7] = 0.0;
   out_3196048199274518526[8] = 0.0;
   out_3196048199274518526[9] = 0.0;
   out_3196048199274518526[10] = 0.0;
   out_3196048199274518526[11] = 0.0;
   out_3196048199274518526[12] = 0.0;
   out_3196048199274518526[13] = 0.0;
   out_3196048199274518526[14] = 0.0;
   out_3196048199274518526[15] = 0.0;
   out_3196048199274518526[16] = 0.0;
   out_3196048199274518526[17] = 0.0;
   out_3196048199274518526[18] = 0.0;
   out_3196048199274518526[19] = 1.0;
   out_3196048199274518526[20] = 0.0;
   out_3196048199274518526[21] = 0.0;
   out_3196048199274518526[22] = 0.0;
   out_3196048199274518526[23] = 0.0;
   out_3196048199274518526[24] = 0.0;
   out_3196048199274518526[25] = 0.0;
   out_3196048199274518526[26] = 0.0;
   out_3196048199274518526[27] = 0.0;
   out_3196048199274518526[28] = 0.0;
   out_3196048199274518526[29] = 0.0;
   out_3196048199274518526[30] = 0.0;
   out_3196048199274518526[31] = 0.0;
   out_3196048199274518526[32] = 0.0;
   out_3196048199274518526[33] = 0.0;
   out_3196048199274518526[34] = 0.0;
   out_3196048199274518526[35] = 0.0;
   out_3196048199274518526[36] = 0.0;
   out_3196048199274518526[37] = 0.0;
   out_3196048199274518526[38] = 1.0;
   out_3196048199274518526[39] = 0.0;
   out_3196048199274518526[40] = 0.0;
   out_3196048199274518526[41] = 0.0;
   out_3196048199274518526[42] = 0.0;
   out_3196048199274518526[43] = 0.0;
   out_3196048199274518526[44] = 0.0;
   out_3196048199274518526[45] = 0.0;
   out_3196048199274518526[46] = 0.0;
   out_3196048199274518526[47] = 0.0;
   out_3196048199274518526[48] = 0.0;
   out_3196048199274518526[49] = 0.0;
   out_3196048199274518526[50] = 0.0;
   out_3196048199274518526[51] = 0.0;
   out_3196048199274518526[52] = 0.0;
   out_3196048199274518526[53] = 0.0;
   out_3196048199274518526[54] = 0.0;
   out_3196048199274518526[55] = 0.0;
   out_3196048199274518526[56] = 0.0;
   out_3196048199274518526[57] = 1.0;
   out_3196048199274518526[58] = 0.0;
   out_3196048199274518526[59] = 0.0;
   out_3196048199274518526[60] = 0.0;
   out_3196048199274518526[61] = 0.0;
   out_3196048199274518526[62] = 0.0;
   out_3196048199274518526[63] = 0.0;
   out_3196048199274518526[64] = 0.0;
   out_3196048199274518526[65] = 0.0;
   out_3196048199274518526[66] = 0.0;
   out_3196048199274518526[67] = 0.0;
   out_3196048199274518526[68] = 0.0;
   out_3196048199274518526[69] = 0.0;
   out_3196048199274518526[70] = 0.0;
   out_3196048199274518526[71] = 0.0;
   out_3196048199274518526[72] = 0.0;
   out_3196048199274518526[73] = 0.0;
   out_3196048199274518526[74] = 0.0;
   out_3196048199274518526[75] = 0.0;
   out_3196048199274518526[76] = 1.0;
   out_3196048199274518526[77] = 0.0;
   out_3196048199274518526[78] = 0.0;
   out_3196048199274518526[79] = 0.0;
   out_3196048199274518526[80] = 0.0;
   out_3196048199274518526[81] = 0.0;
   out_3196048199274518526[82] = 0.0;
   out_3196048199274518526[83] = 0.0;
   out_3196048199274518526[84] = 0.0;
   out_3196048199274518526[85] = 0.0;
   out_3196048199274518526[86] = 0.0;
   out_3196048199274518526[87] = 0.0;
   out_3196048199274518526[88] = 0.0;
   out_3196048199274518526[89] = 0.0;
   out_3196048199274518526[90] = 0.0;
   out_3196048199274518526[91] = 0.0;
   out_3196048199274518526[92] = 0.0;
   out_3196048199274518526[93] = 0.0;
   out_3196048199274518526[94] = 0.0;
   out_3196048199274518526[95] = 1.0;
   out_3196048199274518526[96] = 0.0;
   out_3196048199274518526[97] = 0.0;
   out_3196048199274518526[98] = 0.0;
   out_3196048199274518526[99] = 0.0;
   out_3196048199274518526[100] = 0.0;
   out_3196048199274518526[101] = 0.0;
   out_3196048199274518526[102] = 0.0;
   out_3196048199274518526[103] = 0.0;
   out_3196048199274518526[104] = 0.0;
   out_3196048199274518526[105] = 0.0;
   out_3196048199274518526[106] = 0.0;
   out_3196048199274518526[107] = 0.0;
   out_3196048199274518526[108] = 0.0;
   out_3196048199274518526[109] = 0.0;
   out_3196048199274518526[110] = 0.0;
   out_3196048199274518526[111] = 0.0;
   out_3196048199274518526[112] = 0.0;
   out_3196048199274518526[113] = 0.0;
   out_3196048199274518526[114] = 1.0;
   out_3196048199274518526[115] = 0.0;
   out_3196048199274518526[116] = 0.0;
   out_3196048199274518526[117] = 0.0;
   out_3196048199274518526[118] = 0.0;
   out_3196048199274518526[119] = 0.0;
   out_3196048199274518526[120] = 0.0;
   out_3196048199274518526[121] = 0.0;
   out_3196048199274518526[122] = 0.0;
   out_3196048199274518526[123] = 0.0;
   out_3196048199274518526[124] = 0.0;
   out_3196048199274518526[125] = 0.0;
   out_3196048199274518526[126] = 0.0;
   out_3196048199274518526[127] = 0.0;
   out_3196048199274518526[128] = 0.0;
   out_3196048199274518526[129] = 0.0;
   out_3196048199274518526[130] = 0.0;
   out_3196048199274518526[131] = 0.0;
   out_3196048199274518526[132] = 0.0;
   out_3196048199274518526[133] = 1.0;
   out_3196048199274518526[134] = 0.0;
   out_3196048199274518526[135] = 0.0;
   out_3196048199274518526[136] = 0.0;
   out_3196048199274518526[137] = 0.0;
   out_3196048199274518526[138] = 0.0;
   out_3196048199274518526[139] = 0.0;
   out_3196048199274518526[140] = 0.0;
   out_3196048199274518526[141] = 0.0;
   out_3196048199274518526[142] = 0.0;
   out_3196048199274518526[143] = 0.0;
   out_3196048199274518526[144] = 0.0;
   out_3196048199274518526[145] = 0.0;
   out_3196048199274518526[146] = 0.0;
   out_3196048199274518526[147] = 0.0;
   out_3196048199274518526[148] = 0.0;
   out_3196048199274518526[149] = 0.0;
   out_3196048199274518526[150] = 0.0;
   out_3196048199274518526[151] = 0.0;
   out_3196048199274518526[152] = 1.0;
   out_3196048199274518526[153] = 0.0;
   out_3196048199274518526[154] = 0.0;
   out_3196048199274518526[155] = 0.0;
   out_3196048199274518526[156] = 0.0;
   out_3196048199274518526[157] = 0.0;
   out_3196048199274518526[158] = 0.0;
   out_3196048199274518526[159] = 0.0;
   out_3196048199274518526[160] = 0.0;
   out_3196048199274518526[161] = 0.0;
   out_3196048199274518526[162] = 0.0;
   out_3196048199274518526[163] = 0.0;
   out_3196048199274518526[164] = 0.0;
   out_3196048199274518526[165] = 0.0;
   out_3196048199274518526[166] = 0.0;
   out_3196048199274518526[167] = 0.0;
   out_3196048199274518526[168] = 0.0;
   out_3196048199274518526[169] = 0.0;
   out_3196048199274518526[170] = 0.0;
   out_3196048199274518526[171] = 1.0;
   out_3196048199274518526[172] = 0.0;
   out_3196048199274518526[173] = 0.0;
   out_3196048199274518526[174] = 0.0;
   out_3196048199274518526[175] = 0.0;
   out_3196048199274518526[176] = 0.0;
   out_3196048199274518526[177] = 0.0;
   out_3196048199274518526[178] = 0.0;
   out_3196048199274518526[179] = 0.0;
   out_3196048199274518526[180] = 0.0;
   out_3196048199274518526[181] = 0.0;
   out_3196048199274518526[182] = 0.0;
   out_3196048199274518526[183] = 0.0;
   out_3196048199274518526[184] = 0.0;
   out_3196048199274518526[185] = 0.0;
   out_3196048199274518526[186] = 0.0;
   out_3196048199274518526[187] = 0.0;
   out_3196048199274518526[188] = 0.0;
   out_3196048199274518526[189] = 0.0;
   out_3196048199274518526[190] = 1.0;
   out_3196048199274518526[191] = 0.0;
   out_3196048199274518526[192] = 0.0;
   out_3196048199274518526[193] = 0.0;
   out_3196048199274518526[194] = 0.0;
   out_3196048199274518526[195] = 0.0;
   out_3196048199274518526[196] = 0.0;
   out_3196048199274518526[197] = 0.0;
   out_3196048199274518526[198] = 0.0;
   out_3196048199274518526[199] = 0.0;
   out_3196048199274518526[200] = 0.0;
   out_3196048199274518526[201] = 0.0;
   out_3196048199274518526[202] = 0.0;
   out_3196048199274518526[203] = 0.0;
   out_3196048199274518526[204] = 0.0;
   out_3196048199274518526[205] = 0.0;
   out_3196048199274518526[206] = 0.0;
   out_3196048199274518526[207] = 0.0;
   out_3196048199274518526[208] = 0.0;
   out_3196048199274518526[209] = 1.0;
   out_3196048199274518526[210] = 0.0;
   out_3196048199274518526[211] = 0.0;
   out_3196048199274518526[212] = 0.0;
   out_3196048199274518526[213] = 0.0;
   out_3196048199274518526[214] = 0.0;
   out_3196048199274518526[215] = 0.0;
   out_3196048199274518526[216] = 0.0;
   out_3196048199274518526[217] = 0.0;
   out_3196048199274518526[218] = 0.0;
   out_3196048199274518526[219] = 0.0;
   out_3196048199274518526[220] = 0.0;
   out_3196048199274518526[221] = 0.0;
   out_3196048199274518526[222] = 0.0;
   out_3196048199274518526[223] = 0.0;
   out_3196048199274518526[224] = 0.0;
   out_3196048199274518526[225] = 0.0;
   out_3196048199274518526[226] = 0.0;
   out_3196048199274518526[227] = 0.0;
   out_3196048199274518526[228] = 1.0;
   out_3196048199274518526[229] = 0.0;
   out_3196048199274518526[230] = 0.0;
   out_3196048199274518526[231] = 0.0;
   out_3196048199274518526[232] = 0.0;
   out_3196048199274518526[233] = 0.0;
   out_3196048199274518526[234] = 0.0;
   out_3196048199274518526[235] = 0.0;
   out_3196048199274518526[236] = 0.0;
   out_3196048199274518526[237] = 0.0;
   out_3196048199274518526[238] = 0.0;
   out_3196048199274518526[239] = 0.0;
   out_3196048199274518526[240] = 0.0;
   out_3196048199274518526[241] = 0.0;
   out_3196048199274518526[242] = 0.0;
   out_3196048199274518526[243] = 0.0;
   out_3196048199274518526[244] = 0.0;
   out_3196048199274518526[245] = 0.0;
   out_3196048199274518526[246] = 0.0;
   out_3196048199274518526[247] = 1.0;
   out_3196048199274518526[248] = 0.0;
   out_3196048199274518526[249] = 0.0;
   out_3196048199274518526[250] = 0.0;
   out_3196048199274518526[251] = 0.0;
   out_3196048199274518526[252] = 0.0;
   out_3196048199274518526[253] = 0.0;
   out_3196048199274518526[254] = 0.0;
   out_3196048199274518526[255] = 0.0;
   out_3196048199274518526[256] = 0.0;
   out_3196048199274518526[257] = 0.0;
   out_3196048199274518526[258] = 0.0;
   out_3196048199274518526[259] = 0.0;
   out_3196048199274518526[260] = 0.0;
   out_3196048199274518526[261] = 0.0;
   out_3196048199274518526[262] = 0.0;
   out_3196048199274518526[263] = 0.0;
   out_3196048199274518526[264] = 0.0;
   out_3196048199274518526[265] = 0.0;
   out_3196048199274518526[266] = 1.0;
   out_3196048199274518526[267] = 0.0;
   out_3196048199274518526[268] = 0.0;
   out_3196048199274518526[269] = 0.0;
   out_3196048199274518526[270] = 0.0;
   out_3196048199274518526[271] = 0.0;
   out_3196048199274518526[272] = 0.0;
   out_3196048199274518526[273] = 0.0;
   out_3196048199274518526[274] = 0.0;
   out_3196048199274518526[275] = 0.0;
   out_3196048199274518526[276] = 0.0;
   out_3196048199274518526[277] = 0.0;
   out_3196048199274518526[278] = 0.0;
   out_3196048199274518526[279] = 0.0;
   out_3196048199274518526[280] = 0.0;
   out_3196048199274518526[281] = 0.0;
   out_3196048199274518526[282] = 0.0;
   out_3196048199274518526[283] = 0.0;
   out_3196048199274518526[284] = 0.0;
   out_3196048199274518526[285] = 1.0;
   out_3196048199274518526[286] = 0.0;
   out_3196048199274518526[287] = 0.0;
   out_3196048199274518526[288] = 0.0;
   out_3196048199274518526[289] = 0.0;
   out_3196048199274518526[290] = 0.0;
   out_3196048199274518526[291] = 0.0;
   out_3196048199274518526[292] = 0.0;
   out_3196048199274518526[293] = 0.0;
   out_3196048199274518526[294] = 0.0;
   out_3196048199274518526[295] = 0.0;
   out_3196048199274518526[296] = 0.0;
   out_3196048199274518526[297] = 0.0;
   out_3196048199274518526[298] = 0.0;
   out_3196048199274518526[299] = 0.0;
   out_3196048199274518526[300] = 0.0;
   out_3196048199274518526[301] = 0.0;
   out_3196048199274518526[302] = 0.0;
   out_3196048199274518526[303] = 0.0;
   out_3196048199274518526[304] = 1.0;
   out_3196048199274518526[305] = 0.0;
   out_3196048199274518526[306] = 0.0;
   out_3196048199274518526[307] = 0.0;
   out_3196048199274518526[308] = 0.0;
   out_3196048199274518526[309] = 0.0;
   out_3196048199274518526[310] = 0.0;
   out_3196048199274518526[311] = 0.0;
   out_3196048199274518526[312] = 0.0;
   out_3196048199274518526[313] = 0.0;
   out_3196048199274518526[314] = 0.0;
   out_3196048199274518526[315] = 0.0;
   out_3196048199274518526[316] = 0.0;
   out_3196048199274518526[317] = 0.0;
   out_3196048199274518526[318] = 0.0;
   out_3196048199274518526[319] = 0.0;
   out_3196048199274518526[320] = 0.0;
   out_3196048199274518526[321] = 0.0;
   out_3196048199274518526[322] = 0.0;
   out_3196048199274518526[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_6154479985514166504) {
   out_6154479985514166504[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_6154479985514166504[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_6154479985514166504[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_6154479985514166504[3] = dt*state[12] + state[3];
   out_6154479985514166504[4] = dt*state[13] + state[4];
   out_6154479985514166504[5] = dt*state[14] + state[5];
   out_6154479985514166504[6] = state[6];
   out_6154479985514166504[7] = state[7];
   out_6154479985514166504[8] = state[8];
   out_6154479985514166504[9] = state[9];
   out_6154479985514166504[10] = state[10];
   out_6154479985514166504[11] = state[11];
   out_6154479985514166504[12] = state[12];
   out_6154479985514166504[13] = state[13];
   out_6154479985514166504[14] = state[14];
   out_6154479985514166504[15] = state[15];
   out_6154479985514166504[16] = state[16];
   out_6154479985514166504[17] = state[17];
}
void F_fun(double *state, double dt, double *out_7765851612513458719) {
   out_7765851612513458719[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7765851612513458719[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7765851612513458719[2] = 0;
   out_7765851612513458719[3] = 0;
   out_7765851612513458719[4] = 0;
   out_7765851612513458719[5] = 0;
   out_7765851612513458719[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7765851612513458719[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7765851612513458719[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_7765851612513458719[9] = 0;
   out_7765851612513458719[10] = 0;
   out_7765851612513458719[11] = 0;
   out_7765851612513458719[12] = 0;
   out_7765851612513458719[13] = 0;
   out_7765851612513458719[14] = 0;
   out_7765851612513458719[15] = 0;
   out_7765851612513458719[16] = 0;
   out_7765851612513458719[17] = 0;
   out_7765851612513458719[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7765851612513458719[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7765851612513458719[20] = 0;
   out_7765851612513458719[21] = 0;
   out_7765851612513458719[22] = 0;
   out_7765851612513458719[23] = 0;
   out_7765851612513458719[24] = 0;
   out_7765851612513458719[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7765851612513458719[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_7765851612513458719[27] = 0;
   out_7765851612513458719[28] = 0;
   out_7765851612513458719[29] = 0;
   out_7765851612513458719[30] = 0;
   out_7765851612513458719[31] = 0;
   out_7765851612513458719[32] = 0;
   out_7765851612513458719[33] = 0;
   out_7765851612513458719[34] = 0;
   out_7765851612513458719[35] = 0;
   out_7765851612513458719[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7765851612513458719[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7765851612513458719[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7765851612513458719[39] = 0;
   out_7765851612513458719[40] = 0;
   out_7765851612513458719[41] = 0;
   out_7765851612513458719[42] = 0;
   out_7765851612513458719[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7765851612513458719[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_7765851612513458719[45] = 0;
   out_7765851612513458719[46] = 0;
   out_7765851612513458719[47] = 0;
   out_7765851612513458719[48] = 0;
   out_7765851612513458719[49] = 0;
   out_7765851612513458719[50] = 0;
   out_7765851612513458719[51] = 0;
   out_7765851612513458719[52] = 0;
   out_7765851612513458719[53] = 0;
   out_7765851612513458719[54] = 0;
   out_7765851612513458719[55] = 0;
   out_7765851612513458719[56] = 0;
   out_7765851612513458719[57] = 1;
   out_7765851612513458719[58] = 0;
   out_7765851612513458719[59] = 0;
   out_7765851612513458719[60] = 0;
   out_7765851612513458719[61] = 0;
   out_7765851612513458719[62] = 0;
   out_7765851612513458719[63] = 0;
   out_7765851612513458719[64] = 0;
   out_7765851612513458719[65] = 0;
   out_7765851612513458719[66] = dt;
   out_7765851612513458719[67] = 0;
   out_7765851612513458719[68] = 0;
   out_7765851612513458719[69] = 0;
   out_7765851612513458719[70] = 0;
   out_7765851612513458719[71] = 0;
   out_7765851612513458719[72] = 0;
   out_7765851612513458719[73] = 0;
   out_7765851612513458719[74] = 0;
   out_7765851612513458719[75] = 0;
   out_7765851612513458719[76] = 1;
   out_7765851612513458719[77] = 0;
   out_7765851612513458719[78] = 0;
   out_7765851612513458719[79] = 0;
   out_7765851612513458719[80] = 0;
   out_7765851612513458719[81] = 0;
   out_7765851612513458719[82] = 0;
   out_7765851612513458719[83] = 0;
   out_7765851612513458719[84] = 0;
   out_7765851612513458719[85] = dt;
   out_7765851612513458719[86] = 0;
   out_7765851612513458719[87] = 0;
   out_7765851612513458719[88] = 0;
   out_7765851612513458719[89] = 0;
   out_7765851612513458719[90] = 0;
   out_7765851612513458719[91] = 0;
   out_7765851612513458719[92] = 0;
   out_7765851612513458719[93] = 0;
   out_7765851612513458719[94] = 0;
   out_7765851612513458719[95] = 1;
   out_7765851612513458719[96] = 0;
   out_7765851612513458719[97] = 0;
   out_7765851612513458719[98] = 0;
   out_7765851612513458719[99] = 0;
   out_7765851612513458719[100] = 0;
   out_7765851612513458719[101] = 0;
   out_7765851612513458719[102] = 0;
   out_7765851612513458719[103] = 0;
   out_7765851612513458719[104] = dt;
   out_7765851612513458719[105] = 0;
   out_7765851612513458719[106] = 0;
   out_7765851612513458719[107] = 0;
   out_7765851612513458719[108] = 0;
   out_7765851612513458719[109] = 0;
   out_7765851612513458719[110] = 0;
   out_7765851612513458719[111] = 0;
   out_7765851612513458719[112] = 0;
   out_7765851612513458719[113] = 0;
   out_7765851612513458719[114] = 1;
   out_7765851612513458719[115] = 0;
   out_7765851612513458719[116] = 0;
   out_7765851612513458719[117] = 0;
   out_7765851612513458719[118] = 0;
   out_7765851612513458719[119] = 0;
   out_7765851612513458719[120] = 0;
   out_7765851612513458719[121] = 0;
   out_7765851612513458719[122] = 0;
   out_7765851612513458719[123] = 0;
   out_7765851612513458719[124] = 0;
   out_7765851612513458719[125] = 0;
   out_7765851612513458719[126] = 0;
   out_7765851612513458719[127] = 0;
   out_7765851612513458719[128] = 0;
   out_7765851612513458719[129] = 0;
   out_7765851612513458719[130] = 0;
   out_7765851612513458719[131] = 0;
   out_7765851612513458719[132] = 0;
   out_7765851612513458719[133] = 1;
   out_7765851612513458719[134] = 0;
   out_7765851612513458719[135] = 0;
   out_7765851612513458719[136] = 0;
   out_7765851612513458719[137] = 0;
   out_7765851612513458719[138] = 0;
   out_7765851612513458719[139] = 0;
   out_7765851612513458719[140] = 0;
   out_7765851612513458719[141] = 0;
   out_7765851612513458719[142] = 0;
   out_7765851612513458719[143] = 0;
   out_7765851612513458719[144] = 0;
   out_7765851612513458719[145] = 0;
   out_7765851612513458719[146] = 0;
   out_7765851612513458719[147] = 0;
   out_7765851612513458719[148] = 0;
   out_7765851612513458719[149] = 0;
   out_7765851612513458719[150] = 0;
   out_7765851612513458719[151] = 0;
   out_7765851612513458719[152] = 1;
   out_7765851612513458719[153] = 0;
   out_7765851612513458719[154] = 0;
   out_7765851612513458719[155] = 0;
   out_7765851612513458719[156] = 0;
   out_7765851612513458719[157] = 0;
   out_7765851612513458719[158] = 0;
   out_7765851612513458719[159] = 0;
   out_7765851612513458719[160] = 0;
   out_7765851612513458719[161] = 0;
   out_7765851612513458719[162] = 0;
   out_7765851612513458719[163] = 0;
   out_7765851612513458719[164] = 0;
   out_7765851612513458719[165] = 0;
   out_7765851612513458719[166] = 0;
   out_7765851612513458719[167] = 0;
   out_7765851612513458719[168] = 0;
   out_7765851612513458719[169] = 0;
   out_7765851612513458719[170] = 0;
   out_7765851612513458719[171] = 1;
   out_7765851612513458719[172] = 0;
   out_7765851612513458719[173] = 0;
   out_7765851612513458719[174] = 0;
   out_7765851612513458719[175] = 0;
   out_7765851612513458719[176] = 0;
   out_7765851612513458719[177] = 0;
   out_7765851612513458719[178] = 0;
   out_7765851612513458719[179] = 0;
   out_7765851612513458719[180] = 0;
   out_7765851612513458719[181] = 0;
   out_7765851612513458719[182] = 0;
   out_7765851612513458719[183] = 0;
   out_7765851612513458719[184] = 0;
   out_7765851612513458719[185] = 0;
   out_7765851612513458719[186] = 0;
   out_7765851612513458719[187] = 0;
   out_7765851612513458719[188] = 0;
   out_7765851612513458719[189] = 0;
   out_7765851612513458719[190] = 1;
   out_7765851612513458719[191] = 0;
   out_7765851612513458719[192] = 0;
   out_7765851612513458719[193] = 0;
   out_7765851612513458719[194] = 0;
   out_7765851612513458719[195] = 0;
   out_7765851612513458719[196] = 0;
   out_7765851612513458719[197] = 0;
   out_7765851612513458719[198] = 0;
   out_7765851612513458719[199] = 0;
   out_7765851612513458719[200] = 0;
   out_7765851612513458719[201] = 0;
   out_7765851612513458719[202] = 0;
   out_7765851612513458719[203] = 0;
   out_7765851612513458719[204] = 0;
   out_7765851612513458719[205] = 0;
   out_7765851612513458719[206] = 0;
   out_7765851612513458719[207] = 0;
   out_7765851612513458719[208] = 0;
   out_7765851612513458719[209] = 1;
   out_7765851612513458719[210] = 0;
   out_7765851612513458719[211] = 0;
   out_7765851612513458719[212] = 0;
   out_7765851612513458719[213] = 0;
   out_7765851612513458719[214] = 0;
   out_7765851612513458719[215] = 0;
   out_7765851612513458719[216] = 0;
   out_7765851612513458719[217] = 0;
   out_7765851612513458719[218] = 0;
   out_7765851612513458719[219] = 0;
   out_7765851612513458719[220] = 0;
   out_7765851612513458719[221] = 0;
   out_7765851612513458719[222] = 0;
   out_7765851612513458719[223] = 0;
   out_7765851612513458719[224] = 0;
   out_7765851612513458719[225] = 0;
   out_7765851612513458719[226] = 0;
   out_7765851612513458719[227] = 0;
   out_7765851612513458719[228] = 1;
   out_7765851612513458719[229] = 0;
   out_7765851612513458719[230] = 0;
   out_7765851612513458719[231] = 0;
   out_7765851612513458719[232] = 0;
   out_7765851612513458719[233] = 0;
   out_7765851612513458719[234] = 0;
   out_7765851612513458719[235] = 0;
   out_7765851612513458719[236] = 0;
   out_7765851612513458719[237] = 0;
   out_7765851612513458719[238] = 0;
   out_7765851612513458719[239] = 0;
   out_7765851612513458719[240] = 0;
   out_7765851612513458719[241] = 0;
   out_7765851612513458719[242] = 0;
   out_7765851612513458719[243] = 0;
   out_7765851612513458719[244] = 0;
   out_7765851612513458719[245] = 0;
   out_7765851612513458719[246] = 0;
   out_7765851612513458719[247] = 1;
   out_7765851612513458719[248] = 0;
   out_7765851612513458719[249] = 0;
   out_7765851612513458719[250] = 0;
   out_7765851612513458719[251] = 0;
   out_7765851612513458719[252] = 0;
   out_7765851612513458719[253] = 0;
   out_7765851612513458719[254] = 0;
   out_7765851612513458719[255] = 0;
   out_7765851612513458719[256] = 0;
   out_7765851612513458719[257] = 0;
   out_7765851612513458719[258] = 0;
   out_7765851612513458719[259] = 0;
   out_7765851612513458719[260] = 0;
   out_7765851612513458719[261] = 0;
   out_7765851612513458719[262] = 0;
   out_7765851612513458719[263] = 0;
   out_7765851612513458719[264] = 0;
   out_7765851612513458719[265] = 0;
   out_7765851612513458719[266] = 1;
   out_7765851612513458719[267] = 0;
   out_7765851612513458719[268] = 0;
   out_7765851612513458719[269] = 0;
   out_7765851612513458719[270] = 0;
   out_7765851612513458719[271] = 0;
   out_7765851612513458719[272] = 0;
   out_7765851612513458719[273] = 0;
   out_7765851612513458719[274] = 0;
   out_7765851612513458719[275] = 0;
   out_7765851612513458719[276] = 0;
   out_7765851612513458719[277] = 0;
   out_7765851612513458719[278] = 0;
   out_7765851612513458719[279] = 0;
   out_7765851612513458719[280] = 0;
   out_7765851612513458719[281] = 0;
   out_7765851612513458719[282] = 0;
   out_7765851612513458719[283] = 0;
   out_7765851612513458719[284] = 0;
   out_7765851612513458719[285] = 1;
   out_7765851612513458719[286] = 0;
   out_7765851612513458719[287] = 0;
   out_7765851612513458719[288] = 0;
   out_7765851612513458719[289] = 0;
   out_7765851612513458719[290] = 0;
   out_7765851612513458719[291] = 0;
   out_7765851612513458719[292] = 0;
   out_7765851612513458719[293] = 0;
   out_7765851612513458719[294] = 0;
   out_7765851612513458719[295] = 0;
   out_7765851612513458719[296] = 0;
   out_7765851612513458719[297] = 0;
   out_7765851612513458719[298] = 0;
   out_7765851612513458719[299] = 0;
   out_7765851612513458719[300] = 0;
   out_7765851612513458719[301] = 0;
   out_7765851612513458719[302] = 0;
   out_7765851612513458719[303] = 0;
   out_7765851612513458719[304] = 1;
   out_7765851612513458719[305] = 0;
   out_7765851612513458719[306] = 0;
   out_7765851612513458719[307] = 0;
   out_7765851612513458719[308] = 0;
   out_7765851612513458719[309] = 0;
   out_7765851612513458719[310] = 0;
   out_7765851612513458719[311] = 0;
   out_7765851612513458719[312] = 0;
   out_7765851612513458719[313] = 0;
   out_7765851612513458719[314] = 0;
   out_7765851612513458719[315] = 0;
   out_7765851612513458719[316] = 0;
   out_7765851612513458719[317] = 0;
   out_7765851612513458719[318] = 0;
   out_7765851612513458719[319] = 0;
   out_7765851612513458719[320] = 0;
   out_7765851612513458719[321] = 0;
   out_7765851612513458719[322] = 0;
   out_7765851612513458719[323] = 1;
}
void h_4(double *state, double *unused, double *out_1383274130387931186) {
   out_1383274130387931186[0] = state[6] + state[9];
   out_1383274130387931186[1] = state[7] + state[10];
   out_1383274130387931186[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_2652033607477440195) {
   out_2652033607477440195[0] = 0;
   out_2652033607477440195[1] = 0;
   out_2652033607477440195[2] = 0;
   out_2652033607477440195[3] = 0;
   out_2652033607477440195[4] = 0;
   out_2652033607477440195[5] = 0;
   out_2652033607477440195[6] = 1;
   out_2652033607477440195[7] = 0;
   out_2652033607477440195[8] = 0;
   out_2652033607477440195[9] = 1;
   out_2652033607477440195[10] = 0;
   out_2652033607477440195[11] = 0;
   out_2652033607477440195[12] = 0;
   out_2652033607477440195[13] = 0;
   out_2652033607477440195[14] = 0;
   out_2652033607477440195[15] = 0;
   out_2652033607477440195[16] = 0;
   out_2652033607477440195[17] = 0;
   out_2652033607477440195[18] = 0;
   out_2652033607477440195[19] = 0;
   out_2652033607477440195[20] = 0;
   out_2652033607477440195[21] = 0;
   out_2652033607477440195[22] = 0;
   out_2652033607477440195[23] = 0;
   out_2652033607477440195[24] = 0;
   out_2652033607477440195[25] = 1;
   out_2652033607477440195[26] = 0;
   out_2652033607477440195[27] = 0;
   out_2652033607477440195[28] = 1;
   out_2652033607477440195[29] = 0;
   out_2652033607477440195[30] = 0;
   out_2652033607477440195[31] = 0;
   out_2652033607477440195[32] = 0;
   out_2652033607477440195[33] = 0;
   out_2652033607477440195[34] = 0;
   out_2652033607477440195[35] = 0;
   out_2652033607477440195[36] = 0;
   out_2652033607477440195[37] = 0;
   out_2652033607477440195[38] = 0;
   out_2652033607477440195[39] = 0;
   out_2652033607477440195[40] = 0;
   out_2652033607477440195[41] = 0;
   out_2652033607477440195[42] = 0;
   out_2652033607477440195[43] = 0;
   out_2652033607477440195[44] = 1;
   out_2652033607477440195[45] = 0;
   out_2652033607477440195[46] = 0;
   out_2652033607477440195[47] = 1;
   out_2652033607477440195[48] = 0;
   out_2652033607477440195[49] = 0;
   out_2652033607477440195[50] = 0;
   out_2652033607477440195[51] = 0;
   out_2652033607477440195[52] = 0;
   out_2652033607477440195[53] = 0;
}
void h_10(double *state, double *unused, double *out_4232344790676656617) {
   out_4232344790676656617[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_4232344790676656617[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_4232344790676656617[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_607666458428180519) {
   out_607666458428180519[0] = 0;
   out_607666458428180519[1] = 9.8100000000000005*cos(state[1]);
   out_607666458428180519[2] = 0;
   out_607666458428180519[3] = 0;
   out_607666458428180519[4] = -state[8];
   out_607666458428180519[5] = state[7];
   out_607666458428180519[6] = 0;
   out_607666458428180519[7] = state[5];
   out_607666458428180519[8] = -state[4];
   out_607666458428180519[9] = 0;
   out_607666458428180519[10] = 0;
   out_607666458428180519[11] = 0;
   out_607666458428180519[12] = 1;
   out_607666458428180519[13] = 0;
   out_607666458428180519[14] = 0;
   out_607666458428180519[15] = 1;
   out_607666458428180519[16] = 0;
   out_607666458428180519[17] = 0;
   out_607666458428180519[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_607666458428180519[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_607666458428180519[20] = 0;
   out_607666458428180519[21] = state[8];
   out_607666458428180519[22] = 0;
   out_607666458428180519[23] = -state[6];
   out_607666458428180519[24] = -state[5];
   out_607666458428180519[25] = 0;
   out_607666458428180519[26] = state[3];
   out_607666458428180519[27] = 0;
   out_607666458428180519[28] = 0;
   out_607666458428180519[29] = 0;
   out_607666458428180519[30] = 0;
   out_607666458428180519[31] = 1;
   out_607666458428180519[32] = 0;
   out_607666458428180519[33] = 0;
   out_607666458428180519[34] = 1;
   out_607666458428180519[35] = 0;
   out_607666458428180519[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_607666458428180519[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_607666458428180519[38] = 0;
   out_607666458428180519[39] = -state[7];
   out_607666458428180519[40] = state[6];
   out_607666458428180519[41] = 0;
   out_607666458428180519[42] = state[4];
   out_607666458428180519[43] = -state[3];
   out_607666458428180519[44] = 0;
   out_607666458428180519[45] = 0;
   out_607666458428180519[46] = 0;
   out_607666458428180519[47] = 0;
   out_607666458428180519[48] = 0;
   out_607666458428180519[49] = 0;
   out_607666458428180519[50] = 1;
   out_607666458428180519[51] = 0;
   out_607666458428180519[52] = 0;
   out_607666458428180519[53] = 1;
}
void h_13(double *state, double *unused, double *out_1877530148311847870) {
   out_1877530148311847870[0] = state[3];
   out_1877530148311847870[1] = state[4];
   out_1877530148311847870[2] = state[5];
}
void H_13(double *state, double *unused, double *out_560240217854892606) {
   out_560240217854892606[0] = 0;
   out_560240217854892606[1] = 0;
   out_560240217854892606[2] = 0;
   out_560240217854892606[3] = 1;
   out_560240217854892606[4] = 0;
   out_560240217854892606[5] = 0;
   out_560240217854892606[6] = 0;
   out_560240217854892606[7] = 0;
   out_560240217854892606[8] = 0;
   out_560240217854892606[9] = 0;
   out_560240217854892606[10] = 0;
   out_560240217854892606[11] = 0;
   out_560240217854892606[12] = 0;
   out_560240217854892606[13] = 0;
   out_560240217854892606[14] = 0;
   out_560240217854892606[15] = 0;
   out_560240217854892606[16] = 0;
   out_560240217854892606[17] = 0;
   out_560240217854892606[18] = 0;
   out_560240217854892606[19] = 0;
   out_560240217854892606[20] = 0;
   out_560240217854892606[21] = 0;
   out_560240217854892606[22] = 1;
   out_560240217854892606[23] = 0;
   out_560240217854892606[24] = 0;
   out_560240217854892606[25] = 0;
   out_560240217854892606[26] = 0;
   out_560240217854892606[27] = 0;
   out_560240217854892606[28] = 0;
   out_560240217854892606[29] = 0;
   out_560240217854892606[30] = 0;
   out_560240217854892606[31] = 0;
   out_560240217854892606[32] = 0;
   out_560240217854892606[33] = 0;
   out_560240217854892606[34] = 0;
   out_560240217854892606[35] = 0;
   out_560240217854892606[36] = 0;
   out_560240217854892606[37] = 0;
   out_560240217854892606[38] = 0;
   out_560240217854892606[39] = 0;
   out_560240217854892606[40] = 0;
   out_560240217854892606[41] = 1;
   out_560240217854892606[42] = 0;
   out_560240217854892606[43] = 0;
   out_560240217854892606[44] = 0;
   out_560240217854892606[45] = 0;
   out_560240217854892606[46] = 0;
   out_560240217854892606[47] = 0;
   out_560240217854892606[48] = 0;
   out_560240217854892606[49] = 0;
   out_560240217854892606[50] = 0;
   out_560240217854892606[51] = 0;
   out_560240217854892606[52] = 0;
   out_560240217854892606[53] = 0;
}
void h_14(double *state, double *unused, double *out_7515914152585400517) {
   out_7515914152585400517[0] = state[6];
   out_7515914152585400517[1] = state[7];
   out_7515914152585400517[2] = state[8];
}
void H_14(double *state, double *unused, double *out_1311207248862044334) {
   out_1311207248862044334[0] = 0;
   out_1311207248862044334[1] = 0;
   out_1311207248862044334[2] = 0;
   out_1311207248862044334[3] = 0;
   out_1311207248862044334[4] = 0;
   out_1311207248862044334[5] = 0;
   out_1311207248862044334[6] = 1;
   out_1311207248862044334[7] = 0;
   out_1311207248862044334[8] = 0;
   out_1311207248862044334[9] = 0;
   out_1311207248862044334[10] = 0;
   out_1311207248862044334[11] = 0;
   out_1311207248862044334[12] = 0;
   out_1311207248862044334[13] = 0;
   out_1311207248862044334[14] = 0;
   out_1311207248862044334[15] = 0;
   out_1311207248862044334[16] = 0;
   out_1311207248862044334[17] = 0;
   out_1311207248862044334[18] = 0;
   out_1311207248862044334[19] = 0;
   out_1311207248862044334[20] = 0;
   out_1311207248862044334[21] = 0;
   out_1311207248862044334[22] = 0;
   out_1311207248862044334[23] = 0;
   out_1311207248862044334[24] = 0;
   out_1311207248862044334[25] = 1;
   out_1311207248862044334[26] = 0;
   out_1311207248862044334[27] = 0;
   out_1311207248862044334[28] = 0;
   out_1311207248862044334[29] = 0;
   out_1311207248862044334[30] = 0;
   out_1311207248862044334[31] = 0;
   out_1311207248862044334[32] = 0;
   out_1311207248862044334[33] = 0;
   out_1311207248862044334[34] = 0;
   out_1311207248862044334[35] = 0;
   out_1311207248862044334[36] = 0;
   out_1311207248862044334[37] = 0;
   out_1311207248862044334[38] = 0;
   out_1311207248862044334[39] = 0;
   out_1311207248862044334[40] = 0;
   out_1311207248862044334[41] = 0;
   out_1311207248862044334[42] = 0;
   out_1311207248862044334[43] = 0;
   out_1311207248862044334[44] = 1;
   out_1311207248862044334[45] = 0;
   out_1311207248862044334[46] = 0;
   out_1311207248862044334[47] = 0;
   out_1311207248862044334[48] = 0;
   out_1311207248862044334[49] = 0;
   out_1311207248862044334[50] = 0;
   out_1311207248862044334[51] = 0;
   out_1311207248862044334[52] = 0;
   out_1311207248862044334[53] = 0;
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

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_1023796063612672548) {
  err_fun(nom_x, delta_x, out_1023796063612672548);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_365637776418829726) {
  inv_err_fun(nom_x, true_x, out_365637776418829726);
}
void pose_H_mod_fun(double *state, double *out_3196048199274518526) {
  H_mod_fun(state, out_3196048199274518526);
}
void pose_f_fun(double *state, double dt, double *out_6154479985514166504) {
  f_fun(state,  dt, out_6154479985514166504);
}
void pose_F_fun(double *state, double dt, double *out_7765851612513458719) {
  F_fun(state,  dt, out_7765851612513458719);
}
void pose_h_4(double *state, double *unused, double *out_1383274130387931186) {
  h_4(state, unused, out_1383274130387931186);
}
void pose_H_4(double *state, double *unused, double *out_2652033607477440195) {
  H_4(state, unused, out_2652033607477440195);
}
void pose_h_10(double *state, double *unused, double *out_4232344790676656617) {
  h_10(state, unused, out_4232344790676656617);
}
void pose_H_10(double *state, double *unused, double *out_607666458428180519) {
  H_10(state, unused, out_607666458428180519);
}
void pose_h_13(double *state, double *unused, double *out_1877530148311847870) {
  h_13(state, unused, out_1877530148311847870);
}
void pose_H_13(double *state, double *unused, double *out_560240217854892606) {
  H_13(state, unused, out_560240217854892606);
}
void pose_h_14(double *state, double *unused, double *out_7515914152585400517) {
  h_14(state, unused, out_7515914152585400517);
}
void pose_H_14(double *state, double *unused, double *out_1311207248862044334) {
  H_14(state, unused, out_1311207248862044334);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
