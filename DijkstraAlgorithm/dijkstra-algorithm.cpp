#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>


std::vector<int> dijkstra(const std::vector<std::vector<int>>& adjacencyMatrix,int root){
    int numberOfVertices = adjacencyMatrix.size();

    //initialization
    std::vector<int> visited(numberOfVertices,false); //set of uvisisted vertices
    std::vector<int> distances(numberOfVertices,INT_MAX);//for sorting tentative shortest distance from root vertex to each vertex
    
    int rootVertex{root};
    distances[root] = 0;

    std::vector<int> predecessors(numberOfVertices,-1); //for keeping track of previous vertex on the shortest path f toach vertex

    std::priority_queue<int,std::vector<int>,std::greater<int>> minHeap;
    minHeap.push(rootVertex);
    while(!minHeap.empty()){
        int currentNode = minHeap.top();
        minHeap.pop();
        for(int adjacent{0};adjacent < numberOfVertices;++adjacent){
            if(adjacencyMatrix[currentNode][adjacent] > 0){

                int distFromRoot = distances[currentNode] + adjacencyMatrix[currentNode][adjacent]; 
                if((!visited[adjacent]) && (distFromRoot < distances[adjacent])){
                    distances[adjacent] = distFromRoot;
                    minHeap.push(adjacent);
                }
            }
        }

        visited[currentNode] = true;
    }

    
    return distances;
}

int main(){
    const size_t numberOfVertices{6};

   //initialization of the adjacency matrix
   //-1 means that vertices are not connected
   std::vector<std::vector<int>> graph{
          { -1, -1, -1, 4, 9, -1},
          { -1, -1, -1, -1, 2, 6},
          { -1, -1, -1, 2, -1, 7},
          { -1, 6, -1, -1, -1, 3},
          { -1, -1, 5, 10, -1, 1},
          { 6, -1, 9, -1, -1, -1}
   };
    std::vector<int> shortestPaths = dijkstra(graph,0);
   for(int i = 0;i < numberOfVertices;++i){
    std::cout<<"\nThe length of the shortest path from vertix 0 to vertix "<<i<<" is: "<<shortestPaths[i];
   }
}