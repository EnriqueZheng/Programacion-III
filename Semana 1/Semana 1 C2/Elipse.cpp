#include "Elipse.h"
#include <cmath>

using namespace std;

double Elipse::calcular_area() {
    return M_1_PI * a_ * b_;
}

double Elipse::calcular_perimetro() {
    return 2 * M_PI * sqrt((pow(a_, 2) + pow(b_, 2))/2);
}

Elipse::Elipse(double a, double b):a_(a),b_(b) {}

