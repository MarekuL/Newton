#pragma once
#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;
const int  N = 2;
void Gauss(double x[N], double J[N][N], double b[N]);
double dF2_dx2(double x[N]);
double dF2_dx1(double x[N]);
double dF1_dx2(double x[N]);
double dF1_dx1(double x[N]);
double F2(double x[N]);
double max(double a, double b);
double F1(double x[N]);
