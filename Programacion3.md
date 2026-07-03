# Programación III — Mapeo de tareas del curso

Este documento mapea todas las tareas (evaluaciones continuas "EC" y ejercicios de "Semana") presentes en este repositorio, indicando el tema que cubre cada una, un resumen de lo resuelto y las funciones/clases desarrolladas con su ubicación exacta.

## Vista general

| Carpeta | Tema principal | Estado |
|---|---|---|
| `Semana 1` | Constructores, semántica de copia/movimiento (Regla de 5) | Completo |
| `Semana 1/Semana 1 C2` | Polimorfismo con clases abstractas; árbol de expresiones | Parcial (Node sin implementar) |
| `Semana 4` | Templates de función, parámetros no-tipo, funciones de orden superior | Completo |
| `Semana 7` | Lambdas, patrón Observer (EventBus), fold expressions | Completo |
| `EC 1` | Sistema de drones (POO) | Sin implementar (stub) |
| `EC 2` | Composición polimórfica, Regla de Tres, serialización a archivo | Completo |
| `EC 3` | Templates y programación genérica (unit 2) — 12 ejercicios | Completo |
| `EC 5` | Templates avanzados con contenedores genéricos (template template params) — 9 ejercicios | Completo |
| `EC 6` | Quiz: complejidad algorítmica e invariantes de ciclo | Sin archivos en el repositorio (evaluación teórica) |
| `EC 7` | Programación concurrente (unit 5) — 5 ejercicios | Completo |
| `EC 8` | Patrones de diseño modernos en C++20 (concepts, Strategy, Factory, Decorator) | Completo, con pruebas |
| `EC 9` | Adaptadores de contenedores STL (stack/queue) — 7 ejercicios | Completo |

El proyecto se compila con CMake (`CMakeLists.txt` en la raíz), que define un ejecutable por cada unidad (`Progra_III`, `Semana1`, `Elipse`, `Node`, `EC_1`, `EC2`, `Semana4`, `EC3`, `Semana7`, `EC5`, `EC7`).

---

## Semana 1 — Constructores y semántica de copia/movimiento

**Archivos:** `Semana 1/Persona.h`, `Semana 1/Persona.cpp`, `Semana 1/main.cpp`

Ejercicio introductorio de POO en C++: la clase `Persona` implementa la "regla de 5" (constructor por defecto, por parámetros, copia, movimiento, operadores de asignación por copia y movimiento, y destructor). `main.cpp` crea instancias por copia, por puntero (`new`) y las almacena en un `vector<Persona>` para demostrar el comportamiento.

| Función/Método | Descripción | Ubicación |
|---|---|---|
| `Persona::Persona()` | Constructor por defecto | `Semana 1/Persona.h/.cpp` |
| `Persona::Persona(name, apellido)` | Constructor por parámetros | `Semana 1/Persona.cpp` |
| `Persona::Persona(const Persona&)` | Constructor de copia | `Semana 1/Persona.cpp` |
| `Persona::Persona(Persona&&)` | Constructor de movimiento | `Semana 1/Persona.cpp` |
| `Persona::operator=` (copia y movimiento) | Operadores de asignación | `Semana 1/Persona.cpp` |
| `getName()` / `getApellido()` | Getters | `Semana 1/Persona.cpp` |

### Semana 1 / Semana 1 C2 — Polimorfismo y árbol de expresiones

**Archivos:** `Semana 1/Semana 1 C2/Elipse.h/.cpp`, `Semana 1/Semana 1 C2/Node.h/.cpp`

- `Elipse.h/.cpp`: clase abstracta `Figura` con métodos virtuales puros `calcular_area()` y `calcular_perimetro()`; `Elipse` la implementa (nótese que `calcular_area` usa `M_1_PI` en vez de `M_PI`, lo que produce un resultado incorrecto).
- `Node.h`: declara una jerarquía tipo *Composite/Interpreter* para expresiones aritméticas (`Node`, `Multiple`, `Addition`, `Number`, `Variable` con `eval`/`clone`), pero **`Node.cpp` solo incluye el header — no hay implementación**, por lo que este ejercicio quedó incompleto.

| Función/Método | Descripción | Ubicación |
|---|---|---|
| `Elipse::calcular_area()` | Área de la elipse | `Semana 1/Semana 1 C2/Elipse.cpp` |
| `Elipse::calcular_perimetro()` | Perímetro aproximado (Ramanujan) | `Semana 1/Semana 1 C2/Elipse.cpp` |
| `Node`, `Multiple`, `Addition`, `Number`, `Variable` | Jerarquía de nodos de expresión (declarada, sin implementar) | `Semana 1/Semana 1 C2/Node.h` |

---

## Semana 4 — Templates de función

**Archivo:** `Semana 4/Clase.cpp`

Ejercicios de introducción a templates: parámetros no-tipo, funciones genéricas, y una función de orden superior que aplica una función a cada elemento de un `vector`.

| Función | Descripción | Ubicación |
|---|---|---|
| `suma<A, B>()` | Suma dos enteros como parámetros de template (no-tipo) | `Semana 4/Clase.cpp` |
| `triplicar_num<T>(x)` | Triplica un valor genérico | `Semana 4/Clase.cpp` |
| `naximo<T>(a, b)` | Máximo de dos valores genéricos | `Semana 4/Clase.cpp` |
| `apply<T, F>(v, fun)` | Aplica una función/lambda a cada elemento de un `vector<T>` | `Semana 4/Clase.cpp` |
| `operator<<` para `vector<T>` | Imprime un vector | `Semana 4/Clase.cpp` |

---

## Semana 7 — Lambdas, Observer y fold expressions

**Archivo:** `Semana 7/main.cpp`

Implementa un patrón **Observer** (`EventBus`) usando `std::function` y lambdas con distintos tipos de captura (por valor, por copia de variable externa). También incluye una función variádica con *fold expression* y reutiliza `sumar` (concurrencia) de `EC 7/P1.h`.

| Función/Clase | Descripción | Ubicación |
|---|---|---|
| `EventBus::subscribe` / `publish` | Registro y notificación de suscriptores (Observer) | `Semana 7/main.cpp` |
| `f<Args...>(args...)` | Resta variádica mediante fold expression `(args - ...)` | `Semana 7/main.cpp` |

---

## EC 1 — Sistema de drones

**Archivos:** `EC 1/drone_system.h`, `EC 1/drone_system.cpp`

Ejercicio **sin desarrollar**: la clase `drone_system` está declarada vacía y el `.cpp` solo incluye el header. No hay lógica implementada.

---

## EC 2 — Sistema de "Tuits" (composición, Regla de Tres, serialización)

**Archivos:** `EC 2/tuit.h`, `EC 2/tuit.cpp`

Modela un sistema tipo Twitter con una jerarquía polimórfica de elementos embebidos (`Element` → `Emoji`, `Media`, `Poll`) y una clase `Tuit` que los contiene junto con respuestas anidadas (`vector<Tuit> replies`). Implementa la **Regla de Tres** (constructor de copia, `operator=`, destructor) con copia profunda de punteros polimórficos vía `dynamic_cast`, y serialización/deserialización a archivo de texto plano con formato `Tipo|campo|campo...` usando `operator<<`/`operator>>` sobrecargados.

| Función/Método | Descripción | Ubicación |
|---|---|---|
| `Emoji/Media/Poll::show/save` | Muestra y serializa cada tipo de elemento | `EC 2/tuit.cpp` |
| `Tuit::Tuit(copia)`, `operator=`, `~Tuit`, `clear()`, `copy_from()` | Regla de Tres con copia profunda polimórfica | `EC 2/tuit.cpp` |
| `Tuit::add_element` / `add_reply` | Agrega elementos y respuestas (encadenable, retorna `*this`) | `EC 2/tuit.cpp` |
| `Tuit::load_from` / `save_to` | Persistencia a archivo | `EC 2/tuit.cpp` |
| `Tuit::show` | Impresión recursiva del tuit y sus respuestas | `EC 2/tuit.cpp` |
| `operator<<` / `operator>>` (Tuit y cada Element) | Serialización/parseo por líneas delimitadas por `\|` | `EC 2/tuit.cpp` |

---

## EC 3 — Templates y programación genérica (12 ejercicios)

**Archivos:** `EC 3/P1.h` … `EC 3/P12.h` (+ `.cpp` correspondientes), `EC 3/main.cpp`

Batería de ejercicios sobre templates de función y reimplementación manual de algoritmos clásicos de `<algorithm>` (find, copy, remove, replace, count) usando iteradores genéricos, además de templates variádicos (fold expressions y recursión).

| # | Función | Descripción | Ubicación |
|---|---|---|---|
| P1 | `utec::count_char(t, caracter)` | Cuenta ocurrencias de un carácter en un contenedor | `EC 3/P1.h` |
| P2 | `utec::split(t, c)` | Divide un string por delimitador *(nota: el `push_back` inserta el string completo, no el token — posible bug)* | `EC 3/P2.h` |
| P3 | `calcular_total(args...)` / `calcular_total(valores)` | Suma variádica (fold expression) y suma sobre un contenedor | `EC 3/P3.h` |
| P4 | `point_t`, `sort::partition/quick_sort`, `utec::quick_sort` | Clase punto 3D + implementación manual de Quicksort | `EC 3/P4.h` |
| P5 | `utec::buscar(n1, n2, objetivo)` | Búsqueda lineal tipo `std::find` | `EC 3/P5.h` |
| P6 | `utec::copiar(dir1, dir2, copia)` | Copia de rango tipo `std::copy` | `EC 3/P6.h` |
| P7 | `utec::remover(dir1, dir2, valor)` | Elimina valores tipo `std::remove` | `EC 3/P7.h` |
| P8 | `utec::reemplazar(dir1, dir2, valor, reemplazo)` | Reemplaza valores tipo `std::replace` | `EC 3/P8.h` |
| P9 | `utec::contar(dir1, dir2, valor)` | Cuenta ocurrencias tipo `std::count` | `EC 3/P9.h` |
| P10 | `utec::sum(v1, args...)` | Suma variádica recursiva | `EC 3/P10.h` |
| P11 | `utec::concat(p1, args...)`, `operator+` para `vector<T>` | Concatenación variádica de strings/vectores | `EC 3/P11.h` |
| P12 | `utec::max(n1, args...)` | Máximo variádico recursivo | `EC 3/P12.h` |

`EC 3/main.cpp` demuestra `utec::concat` uniendo tres `vector<int>`.

---

## EC 5 — Templates avanzados con contenedores genéricos (9 ejercicios)

**Archivos:** `EC 5/p1.h` … `EC 5/p9.h` (+ `.cpp`)

Ejercicios de templates con **parámetros de template-template** (`template<typename...> class ResultContainer`) para escribir algoritmos independientes del contenedor de salida (`vector`, `deque`, etc.), variádicos con `std::tuple`, y un contenedor propio con iterador de salida personalizado.

| # | Función/Clase | Descripción | Ubicación |
|---|---|---|---|
| p1 | `split_range(contenedor, n)` | Divide un contenedor en `n` sub-contenedores balanceados | `EC 5/p1.h` |
| p2 | `sum_range(c1, c2)` | Suma elemento a elemento con "wrap-around" si difieren en tamaño | `EC 5/p2.h` |
| p3 | `delete_range(...)` (3 sobrecargas) | Elimina elementos iguales a un valor o a una lista de valores | `EC 5/p3.h` |
| p4 | `delete_duplicated(container)` | Elimina duplicados preservando el orden | `EC 5/p4.h` |
| p5 | `unpack(args...)` | Crea `tuple<Args&...>` de referencias a partir de argumentos variádicos | `EC 5/p5.h` |
| p6 | `zip(first, rest...)` | Combina N contenedores en un contenedor de filas (`vector` por fila) | `EC 5/p6.h` |
| p7 | `rotate_range(container, n)` | Rota los elementos del contenedor `n` posiciones | `EC 5/p7.h` |
| p8 | `filter_codes(filename, letter)` | Lee un archivo, filtra códigos por regex (`[a-z]{4}[0-9]{3}`) y letra inicial, y los ordena | `EC 5/p8.h` |
| p9 | `fixed_stack<T, sz>`, `fixed_stack_pusher` | Pila de tamaño fijo basada en `std::array` + adaptador de iterador de salida (`output_iterator`) | `EC 5/p9.h` |

---

## EC 6 — Quiz: complejidad algorítmica e invariantes

**Archivos:** no hay carpeta ni código fuente en este repositorio; fue una evaluación de tipo quiz resuelta fuera del entorno de código.

Quiz teórico centrado en dos temas: análisis de **complejidad algorítmica** (notación Big-O, comparación de costos temporales/espaciales entre algoritmos) y **invariantes de ciclo** (propiedades que se mantienen constantes en cada iteración de un bucle, usadas para razonar formalmente sobre la corrección de un algoritmo). Al no requerir entrega de código, no generó archivos `.cpp`/`.h` en el repositorio.

---

## EC 7 — Programación concurrente (5 ejercicios)

**Archivos:** `EC 7/P1.h` … `EC 7/P5.h`, `EC 7/main.cpp`, `EC 7/README.md`

Unidad 5 del curso: paralelización de operaciones sobre contenedores con `std::thread`, protección de secciones críticas con `std::mutex`, y un forward iterator para una estructura de datos concurrente.

| # | Función/Clase | Descripción | Ubicación |
|---|---|---|---|
| P1 | `sumar(cnt)` | Suma concurrente de un contenedor, particionando el trabajo entre hilos (`hardware_concurrency`) | `EC 7/P1.h` |
| P2 | `increase_values(cnt, value)` | Incrementa todos los valores de un contenedor en paralelo | `EC 7/P2.h` |
| P3 | `get_primes(cnt, start, stop)` / `is_prime(n)` | Búsqueda concurrente de números primos en un rango, con resultados ordenados | `EC 7/P3.h` |
| P4 | `linked_list_t<T>` (+ `iterator`) | Lista simplemente enlazada *thread-safe* (`push_front`, `pop_front`, `empty`, `size`) con `forward_iterator` propio, protegida por `std::mutex` | `EC 7/P4.h` |
| P5 | `utec::stadium::reserve(tribune, row, col)` | Sistema de reserva de asientos de estadio (4 tribunas) seguro ante condiciones de carrera, protegido por `std::mutex` | `EC 7/P5.h` |

`EC 7/main.cpp` prueba `increase_values` (P2); `main.cpp` (raíz) y `Semana 7/main.cpp` prueban `sumar` (P1).

---

## EC 8 — Patrones de diseño modernos (C++20: concepts, Strategy, Factory, Decorator)

**Archivos:** `EC 8/include/Expenses.h`, `EC 8/src/main.cpp`, `EC 8/tests/expenses_tests.cpp`, `EC 8/patrones_diseno_ejercicio_2.pdf`

Sistema de gestión de gastos (`Expense`) que combina varios patrones de diseño usando *concepts* de C++20: **Strategy** para el criterio de ordenamiento, **Factory** para construir exportadores a partir de un `concept ExpenseExporter`, y **Decorator** para añadir auditoría/resumen a cualquier exportador de forma componible. Incluye batería de pruebas unitarias con `assert`.

| Función/Clase | Descripción | Ubicación |
|---|---|---|
| `sort_with(values, cmp)` (requiere `SortStrategy`) | Patrón Strategy: ordena cualquier rango con el comparador dado | `EC 8/include/Expenses.h` |
| `make_exporter<E>(args...)` | Patrón Factory: crea una `ExportFunction` a partir de un exportador que cumple `ExpenseExporter` | `EC 8/include/Expenses.h` |
| `CsvExporter`, `JsonExporter`, `TextExporter` | Exportadores concretos (CSV, JSON, texto) | `EC 8/include/Expenses.h` |
| `AuditedExporter<Inner>`, `SummaryExporter<Inner>` | Patrón Decorator: envuelven un exportador agregando auditoría o totales | `EC 8/include/Expenses.h` |
| `format_amount(amount)` | Formatea montos con 2 decimales | `EC 8/include/Expenses.h` |
| Pruebas unitarias (`test_strategy_*`, `test_factory_*`, `test_decorator_*`, `test_integration_*`) | Verifican Strategy, Factory, Decorator e integración | `EC 8/tests/expenses_tests.cpp` |

---

## EC 9 — Adaptadores de contenedores STL: stack y queue (7 ejercicios)

**Archivos:** `EC 9/src/stack_utec.h`, `EC 9/src/queue_utec.h`, `EC 9/src/P1.h` … `EC 9/src/P7.h`, `EC 9/main.cpp`, `EC 9/README.md`

> Nota: el `README.md` de esta carpeta indica que corresponde a la unidad 6 del curso **"Programación Orientada a Objetos II"** (no Programación III), aunque el código está alojado en este repositorio.

Implementa adaptadores de contenedor `utec::stack` (LIFO) y `utec::queue` (FIFO) sobre un `std::deque` configurable mediante *concepts* (`PopBackConcept`/`PopFrontConcept`), y 7 ejercicios de aplicación práctica sobre pilas y colas.

| # | Función | Descripción | Ubicación |
|---|---|---|---|
| — | `utec::stack<T, Container>` | Adaptador LIFO genérico | `EC 9/src/stack_utec.h` |
| — | `utec::queue<T, Container>` | Adaptador FIFO genérico | `EC 9/src/queue_utec.h` |
| P1 | `merge_stacks(a, b)` | Combina 2 pilas intercalando sus valores | `EC 9/src/P1.h` |
| P2 | `join_stacks(a, b)` | Concatena 2 pilas | `EC 9/src/P2.h` |
| P3 | `process_text_by_stack(source)` | Procesa texto con reglas push/pop usando una pila (LIFO) | `EC 9/src/P3.h/.cpp` |
| P4 | `process_text_by_queue(source)` | Igual que P3 pero usando una cola (FIFO) | `EC 9/src/P4.h/.cpp` |
| P5 | `is_equation_balanced(source)` | Verifica balance de `()`, `[]`, `{}` con una pila | `EC 9/src/P5.h/.cpp` |
| P6 | `find_in_stack(s, cmpr)` | Búsqueda genérica en una pila según predicado | `EC 9/src/P6.h` |
| P7 | `complete_equation(source)` | Reconstruye una expresión infija agregando los paréntesis izquierdos faltantes | `EC 9/src/P7.h` |

`EC 9/main.cpp` prueba `merge_stacks` (P1). La carpeta `EC 9/autograder/` contiene la configuración y pruebas (Catch2) usadas para calificación automática en Gradescope.

---

## Resumen de temas cubiertos en el curso

En orden progresivo de complejidad: fundamentos de POO y semántica de copia/movimiento (`Semana 1`) → polimorfismo con clases abstractas (`Semana 1 C2`, `EC 2`) → templates de función básicos (`Semana 4`) → templates y programación genérica avanzada, incluyendo variádicos y algoritmos manuales (`EC 3`, `EC 5`) → complejidad algorítmica e invariantes de ciclo, evaluados en quiz (`EC 6`) → lambdas y patrón Observer (`Semana 7`) → programación concurrente con hilos y mutex (`EC 7`) → patrones de diseño modernos con concepts de C++20 (`EC 8`) → adaptadores de contenedores STL (`EC 9`).
