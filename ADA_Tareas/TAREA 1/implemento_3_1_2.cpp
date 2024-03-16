#include <iostream>

int *vector = NULL;
int size = 0,        //tamaño del vector
    max = 5,         //tamaño maximo del vector
    addSize = 5;     //tamaño a incrementar


void resize(){
    if(size == max){
        int *pTemp = new int[max + addSize];
        for(int i = 0; i < max; i++){
            pTemp[i] = vector[i];
        }
        delete[] vector;
        vector= pTemp;
        max += addSize;
    }
}

void insert(int data){
    resize();
    vector[size++] = data;
}

void print(){
    for(int i = 0; i < size; i++)
        std::cout << vector[i] << " ";
}

int main() {

    vector = new int[max];
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    insert(6);
    print();

    delete[] vector;

    return 0;
}