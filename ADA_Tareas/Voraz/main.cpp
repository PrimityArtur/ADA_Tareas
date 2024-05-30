#include <iostream>
#include <vector>
#include <algorithm>

class Grafo{
public:
    int v;
    std::vector<std::vector<std::pair<int,int>>> adj;

    Grafo(int _v);
    void addArista(int v1, int v2, int w);
    void printGrafo();
};

Grafo::Grafo(int _v){
    v = _v;
    adj.resize(v);
};

void Grafo::addArista(int v1, int v2, int w){
    adj[v1].emplace_back(v2,w);
    adj[v2].emplace_back(v1,w);
}

void Grafo::printGrafo(){
    for(int i = 0; i < v; i++){
        std::cout << "V " << i << ": ";
        for(int j = 0; j < adj[i].size(); j++){
            std::cout << "(" << adj[i][j].first << ", " << adj[i][j].second << ") ";
        }
        std::cout << std::endl;
    }
}

//       Kruskal

void kruskal(Grafo &g){
    std::vector<std::pair<int,std::pair<int,int>>> edges; // (weight, (v1,v2))
    std::vector<std::pair<int,std::pair<int,int>>> solution; // (weight, (v1,v2))
    
    for(int i = 0; i < g.v; i++){
        for(int j = 0; j < g.adj[i].size(); j++){
            edges.emplace_back(g.adj[i][j].second, std::make_pair(i,g.adj[i][j].first));
        }
    }
    std::sort(edges.begin(), edges.end(), 
        []( const std::pair<int,std::pair<int,int>> &a, 
            const std::pair<int,std::pair<int,int>> &b)
    {return a.first < b.first;});

    while(!edges.empty() && solution.size() != g.v-1){
        auto edge = edges.back();
        if(std::find(solution.begin(), solution.end(), edge.second) != std::find(solution.begin(), solution.end(), edge.first)){
            
            solution.emplace_back(edge);
            
        }
        
    }
    
        
}

int main() {
    Grafo g(9);
    g.addArista(0,1,5);
    g.addArista(0,2,6);
    g.addArista(0,3,4);
    g.addArista(1,2,7);
    g.addArista(1,7,12);
    g.addArista(2,4,3);
    g.addArista(2,6,4);
    g.addArista(2,3,8);
    g.addArista(3,5,9);
    g.addArista(4,7,5);
    g.addArista(5,6,7);
    g.addArista(5,8,10);
    g.addArista(6,8,6);
    g.addArista(6,7,5);
    g.addArista(7,8,11);

    g.printGrafo();
    
    
    
}
