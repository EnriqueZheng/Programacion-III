#include "Persona.h"
#include <vector>


int main() {
    Persona p1;
    Persona p2("Juan","Perez"); //Parametros
    Persona* p3 = new Persona("Maria","Diaz");
    Persona p4 = p2;
    p1 = *p3;

    vector  personas= {p1,p2,*p3,p4};
    for (const auto & persona : personas) {
        cout<<persona.getName()<<" "<<persona.getApellido()<<endl;
    }

    return 0;
}
