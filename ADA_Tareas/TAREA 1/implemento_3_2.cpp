#include <iostream>

struct Vector {
    int *vector = NULL;
    int size = 0,        //tamaño del vector
        max = 0,         //tamaño maximo del vector
        addSize = 5;     //tamaño a incrementar
};

void resize(Vector *vector){
    if(vector->size == vector->max){
        int *pTemp = new int[vector->max + vector->addSize];
        for(int i = 0; i < vector->max; i++){
            pTemp[i] = vector->vector[i];
        }
        delete[] vector->vector;
        vector->vector = pTemp;
        vector->max += vector->addSize;
    }
}

void insert(int data, Vector *vector){
    resize(vector);
    vector->vector[vector->size++] = data;
}

void print(Vector *vector){
    for(int i = 0; i < vector->size; i++)
        std::cout << vector->vector[i] << " ";
}

int main() {

    Vector *vector = new Vector;

    insert(1, vector);
    insert(2, vector);
    insert(3, vector);
    insert(4, vector);
    insert(5, vector);

    insert(6, vector);
    print(vector);

    return 0;
}