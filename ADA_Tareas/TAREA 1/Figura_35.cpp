#include <iostream>

template <class T>
T Addition(T a, T b){
    return a + b;
}

template <class T>
T Subtraction(T a, T b){
    return a - b;
}

template <class T>
T Multiplication(T a, T b){
    return a * b;
}

template <class T>
T Division(T a, T b){
    T result = 0;
    
    try{
        result = a / b;
    }
    catch(std::exception e){
        std::cout << e.what() << std::endl;
    }
    
    return result;
}

int main() {
    typedef float (*operation)(float, float);
    
    operation oper[4] = {&::Addition, &::Subtraction,
    &::Multiplication, &::Division};
    
    float a, b, c; int opt;

    std::cout << "Ingresa dos numeros y la operacion: " << std::endl;
    
    std::cin >> a >> b >> opt;
    
    c = (*oper[opt])(a, b);
    std::cout << c << std::endl;
}