#include <vector> 
#include <list>
#include <iostream>

template <typename T> 
void Write(T &list, std::ostream &os){
    
    typename T::iterator iter = list.begin();
    
    for(; iter != list.end(); iter++)
        os << *iter << "\n";
}

int main() {
    std::list<float> list;
    std::vector<float> vector;
    
    for(int i = 0; i < 10; i++) {
        list.push_back(i);
        vector.push_back(i);
    }
    
    Write(list, std::cout);
    Write(vector, std::cout);
    
    return 0;
}