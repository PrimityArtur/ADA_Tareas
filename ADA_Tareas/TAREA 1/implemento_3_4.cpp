#include <iostream>

template<class T>
class Vector {
    T *vect = NULL;
    int size, 
        max,
        addSize;

public:
    void resize();
    void insert(T data);
    void print();

    Vector(int max);
    ~Vector();
};

template<class T>
Vector<T>::Vector(int max) : max(5){
    size = 0; 
    addSize = max;    
    vect = new int[max];
}

template<class T>
Vector<T>::~Vector(){
    delete[] vect;
}

template<class T>
void Vector<T>::resize(){
    if(size == max){
        T *pTemp = new T[max + addSize];
        for(int i = 0; i < max; i++){
            pTemp[i] = vect[i];
        }
        delete[] vect;
        vect = pTemp;
        max += addSize;
    }
}

template<class T>
void Vector<T>::insert(T data){
    resize();
    vect[size++] = data;
}

template<class T>
void Vector<T>::print(){
    for(int i = 0; i < size; i++)
        std::cout << vect[i] << " ";
}

int main() {
    Vector<int> v(5);
    v.insert(1);
    v.insert(2);
    v.insert(3);
    v.insert(4);
    v.insert(5);
    v.insert(6);

    v.print();
    
    return 0;
}