# Task #6: Estructuras Basicas Adaptadores  
**course:** Programación Orientada a Objetos II  
**unit:** 6  
**cmake project:** poo2_unit6_adaptadores_poo_v2021_2
## Instructions

Los adaptadores deben implementarse en `stack_utec.h` y `queue_utec.h` dentro del namespace `utec`.

## Question #1 - merge_stacks (2 points)
Elaborar un template de función `merge_stacks`, que dado 2 stacks genere la unión con valores intercalados como se muestra en el diagrama.
```cpp
utec::stack<T> merge_stacks(utec::stack<T> a, utec::stack<T> b);
```

![img.png](img.png)

**Casos de uso**
```cpp
    utec::stack<int> stack_a;
    utec::stack<int> stack_b;
    int n {};
    cin >> n;
    while (n-- > 0) {
        int value {};
        cin >> value;
        stack_a.push(value);
    }
    cin >> n;
    while (n-- > 0) {
        int value {};
        cin >> value;
        stack_b.push(value);
    }
    
    auto stack_result = merge_stacks(stack_a, stack_b);
    
    while (!stack_result.empty()) {
        cout << stack_result.top() << " ";
        stack_result.pop();
    }
```

## Question #2 - join_stacks (2 points)
Elaborar un template de función `join_stacks`, donde
dada 2 stacks genere la unión como se muestra en el
diagrama.

```cpp
utec::stack<T> join_stacks(utec::stack<T> a, utec::stack<T> b);
```
![img_1.png](img_1.png)

**Casos de uso**
```cpp
utec::stack<int> stack_a;
utec::stack<int> stack_b;
int n {};
cin >> n;
while (n-- > 0) {
    int value {};
    cin >> value;
    stack_a.push(value);
}
cin >> n;
while (n-- > 0) {
    int value {};
    cin >> value;
    stack_b.push(value);
}

auto stack_result = join_stacks(stack_a, stack_b);

while (!stack_result.empty()) {
    cout << stack_result.top() << " ";
    stack_result.pop();
}
```

## Question #3 - process_text_by_stack (2 points)

Elaborar una función que utilizando stack cumpla con las siguientes reglas:
Una letra significa un `push` y un * significa un `pop`. Dada una secuencia de
caracteres el programa deberá retornar la secuencia de caracteres extraídos por el
`pop`.

Ejemplos:
```
EAS*Y*QUE***ST***IO*N*** --> SYEUQTSAONIE
UN*IV*ERS*IDADDEINGENIE*RIAYTECN***OLOGIA --> NVSENCE
COMPUTER*****S**CIEN**CE --> RETUPSMNE
```

```cpp
string process_text_by_stack(string source);
```

**Casos de uso**
```cpp
string text;
getline(cin, text);
cout << process_text_by_stack(text);
```

## Question #4 - process_text_by_queue (2 points)
Elaborar una función que utilizando queue cumpla con las siguientes reglas:

Una letra significa un `push` y un * significa un `pop`. Dada una secuencia de
caracteres el programa deberá retornar la secuencia de caracteres extraídos por el
`pop`.

Ejemplos:
```
EAS*Y*QUE***ST***IO*N*** --> EASYQUESTION
UN*IV*ERS*IDAD** --> UNIVE
COMPUTER*****S**CIEN**CE --> COMPUTERS
```

```cpp
string process_text_by_queue(const& string source); 
```

**Casos de uso**
```cpp
string text;
getline(cin, text);
cout << process_text_by_queue(text);
```

## Question #5 - is_equation_balanced (4 points)

Dada una ecuación, realizar una función basada en stack que determine si el balance de separadores es correcto.

Ejemplo:
```
((10 + 20) + 30)            Balanceado
((10 +(30 * 1 + 2))         No Balanceado
(10 + (15 + 4/2 - 5)))      No Balanceado
{ (6 + 20} + 4)             No Balanceado
{ [ (4 - 5) * 3] + 14}      Balanceado
```

```cpp
bool is_equation_balanced(string source);
```

**Casos de uso**
```cpp
string text;
getline(cin, text);
cout << boolalpha << is_equation_balanced(text);
```

## Question #6 - find_in_stack (4 points)

Utilizando la clase alumno_t que incluya los atributos `nombre, apellido y nota (double)`, se genere iterativamente. 
Elaborar un template de función `find_in_stack` que permita ubicar un valor basado en cualquier criterio.
```cpp
T find_in_stack(utec::stack<T> s, function<bool(T)> cmpr);
```

```cpp
// Crear un stack basado en un deque de alumnos
auto a1 = find_in_stack (stack, [](alumno_t a) { return a.apellido == "Perez"; });
```

**Casos de uso**
```cpp
utec::stack<alumno_t> s1;
int n{};
cin >> n;
string nombre;
string apellido;
double nota;
while (n-- > 0) {
    getline(cin, nombre);
    getline(cin, apellido);
    cin >> nota;
    s1.push(alumno_t{nombre, apellido, nota});
}

string name_tobe_found;
get_line(cin, name_tobe_found);
a1 = find_in_stack (s1, [=](auto a) { return a.get_nombre() == name_tobe_found; });
```

## Question #7 - complete_equation (4 points)

Elaborar una función basada en stack que tome un expresión sin el paréntesis izquierdo y que retorne la expresión infijo con los paréntesis completos.

Ejemplo:
```markdown
10 + 20) * 5 + 3)    -->  (10 + 20) * (5 + 3) 
10 +30) * 30)        -->  (10 + 30) * (30)
10 + 15) * 2 - 5))   -->  ((10 + 15) * (2 - 5))
```

```cpp
string complete_equation( string source);
```
**Casos de uso**
```cpp
    string text;
    getline(cin, text);
    cout << boolalpha << complete_equation(text);
```
