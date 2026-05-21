#ifndef PROGRA_III_ELJPSE_H
#define PROGRA_III_ELJPSE_H

struct Figura {
    virtual double calcular_area() = 0;
    virtual double calcular_perimetro() = 0;
    virtual ~Figura() = default;
};



class Elipse final: public Figura{
    public:
    double calcular_area() override;
    double calcular_perimetro() override;
    Elipse() = default;
    Elipse(double a, double b);

private:
    double a_ = 0;
    double b_ = 0;
};


#endif //PROGRA_III_ELJPSE_H