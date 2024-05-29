#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
struct obj{
    T p; //peso
    T b; //beneficio
    T c; //criterio
};

template<class T> // imprimir vector
void printVector(std::vector<T> &v, std::string t = ""){
    std::cout << t;
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template<class T> //inprimir los datos de obj
void printObj(T &v){
    std::cout << "(p,b,c) = " ;
    for(int i = 0; i < v.size(); i++){
        std::cout << "(" << v[i].p << ", " << v[i].b << ", " << v[i].c  << "), ";
    }
    std::cout << std::endl << std::endl;
}

template<class T, class S> //imprimir la solucion
void printSolution(std::vector<T> &s, std::vector<obj<S>> &o, std::string t = ""){
    T a = 0, b = 0; //peso y beneficio
    
    std::cout << t << std::endl;
    printObj(o);
    printVector(s, "    solucion(s):   ");

    std::cout << "    (p*s, b*s): ";
    for(int i = 0; i < s.size(); i++){
        std::cout << "(" << s[i]*o[i].p << ", " << s[i]*o[i].b << "), ";
        a += s[i]*o[i].p;
        b += s[i]*o[i].b;
    }
    std::cout << "= (" << a << ", " << b << ")\n\n";    
}

template<class T, class S>
void mochila(T &m, std::vector<obj<T>> &o, std::vector<S> &s){
    for(int i = 0; i < s.size(); i++) s[i] = 0;
    
    T a = 0;
    int i = 0;
    
    while(a < m){
        if(a + o[i].p <= m){
            s[i] = 1;
            a = a + o[i++].p;
        }
        else{
            s[i] = (m - a)/o[i].p;
            a = m;
        }
    }    
}

template<class T, class S> //obtener el criterio para la evaluacion de la mochila 
void criterion(std::vector<T> &o, std::vector<S> &p, std::vector<S> &b, bool (*op)(T&,T&), S (*c)(S&,S&)){
    for(int i = 0; i < o.size(); i++){
        o[i].p = p[i];
        o[i].b = b[i];
        o[i].c = c(b[i],p[i]);
    }
    std::sort(o.begin(), o.end(), op);
}


int main() {
    float m = 20; //capacidad
    std::vector<float> p = {18, 15, 10}; //peso
    std::vector<float> b = {25, 24, 15}; //beneficio
    std::vector<float> s(p.size()); //solucion

    std::vector<obj<float>> o(p.size());
    
    bool (*op[2])(obj<float>&,obj<float>&) = { //operacion
                [](obj<float> &a, obj<float> &b){ return a.c > b.c;},
                [](obj<float> &a, obj<float> &b){ return a.c < b.c;}};
    
    float (*c[3])(float&,float&) = { //criterio
                [](float &a, float &b){ return a/b;},
                [](float &a, float &b){ return a;},
                [](float &a, float &b){ return b;}};
    
    criterion(o, p, b, op[0], c[0]);
    mochila(m, o, s);
    printSolution(s, o, "Solucion por criterio de beneficio/peso:");

    criterion(o, p, b, op[1], c[1]);
    mochila(m, o, s);
    printSolution(s, o, "Solucion por criterio de numero de beneficios:");

    criterion(o, p, b, op[0], c[2]);
    mochila(m, o, s);
    printSolution(s, o, "Solucion por criterio de mayor peso:");
}