#ifndef PROGRA_III_P3_H
#define PROGRA_III_P3_H

        template<typename... Args>
        static auto calcular_total(const Args&... args) {
                return (args + ...);
        }

        template<typename T>
        static auto calcular_total(const T& valores) {
                auto suma = 0.0;
                for (const auto& valor : valores) {
                        suma = suma + valor;
                }
                return suma;
        }

#endif //PROGRA_III_P3_H