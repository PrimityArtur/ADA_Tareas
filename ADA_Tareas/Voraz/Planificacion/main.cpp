#include <iostream>
#include <vector>
#include <algorithm>

struct Task{
    int b;
    int d;
    int indx;
};

void printTask(std::vector<Task> &t){
    std::cout << "(b, d, T) = ";
    for(int i = 0; i < t.size(); i++){
        std::cout << "(" << t[i].b << ", " << t[i].d << ", " << t[i].indx + 1 << "), ";
    }
    std::cout << std::endl;
}

void printSolution(std::vector<int> &s, std::string t = ""){
    std::cout << t;
    for(int i = 0; i < s.size(); i++){
        std::cout << s[i] + 1 << ", ";
    }
    std::cout << std::endl;
}

void criterion(std::vector<Task> &arr, bool (*op)(Task&, Task&)){
    std::sort(arr.begin(), arr.end(), op);
}

void taskPlanner(std::vector<Task> &t, std::vector<int> &s, bool (*op)(Task&, Task&)){
    criterion(t, op); // ordenar
    
    for(int i = 0; i < t.size(); i++){
        for(int j = t[i].d - 1; j >= 0; j--){
            if(s[j] == -1){
                s[j] = t[i].indx;
                break;
            }
        }
    }
}

void fillTask(std::vector<Task> &t, std::vector<int> &b, std::vector<int> &d){
    for(int i = 0; i < t.size(); i++){
        t[i].b = b[i];
        t[i].d = d[i];
        t[i].indx = i;
    }
}

int main() {
    std::vector<int> b = {20, 15, 10, 7, 5, 3}; //beneficio de la tarea
    std::vector<int> d = {3, 1, 1, 3, 1, 3}; //plazo maximo 
    std::vector<int> s(*std::max_element(d.begin(), d.end()), -1); //Solucion
    
    std::vector<Task> t(b.size()); //tareas
    fillTask(t, b, d); //llenar el vector con las tareas
    
    
    taskPlanner(t, s, *[](Task &a, Task &b){ return a.b > b.b;}); //algoritmo voraz
    printTask(t);
    printSolution(s, "    Solution(T): ");
    
}