#include <iostream>

class Vector {
    int *vect = NULL;
    int size, 
        max,
        addSize;

public:
    void resize();
    void insert(int data);
    void print();

    Vector(int max);
    ~Vector();
};

Vector::Vector(int max) : max(5){
    size = 0; 
    addSize = max;    
    vect = new int[max];
}

Vector::~Vector(){
    delete[] vect;
}

void Vector::resize(){
    if(size == max){
        int *pTemp = new int[max + addSize];
        for(int i = 0; i < max; i++){
            pTemp[i] = vect[i];
        }
        delete[] vect;
        vect = pTemp;
        max += addSize;
    }
}

void Vector::insert(int data){
    resize();
    vect[size++] = data;
}

void Vector::print(){
    for(int i = 0; i < size; i++)
        std::cout << vect[i] << " ";
}

int main() {
    Vector v(5);
    v.insert(1);
    v.insert(2);
    v.insert(3);
    v.insert(4);
    v.insert(5);
    v.insert(6);

    v.print();

    return 0;
}