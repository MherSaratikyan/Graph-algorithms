#include <iostream>
#include <array>
#include <queue>

int main(){
   const size_t numberOfVertices{6};

   //initialization of the adjacency matrix
   std::array<std::array<int,numberOfVertices>,numberOfVertices> graph{
        1, 0, 0, 1, 1, 0,
        0, 1, 0, 0, 1, 1,
        0, 0, 1, 1, 0, 1,
        0, 1, 0, 0, 0, 1,
        0, 0, 1, 1, 0, 1,
        1, 0, 1, 0, 0, 0
   };

    //bfs algorithm
   std::array<bool,numberOfVertices> visitedNodes;

   std::queue<int> q;

    int rootNode{0};
   //pushing the root node (node #0) into the queue
   q.push(rootNode);

   //marking the root node as visited
   visitedNodes[rootNode] =  true;

   while(!q.empty()){
        int node{q.front()};
        std::cout<<node<<' ';
        q.pop();
        for(int adjacent{0}; adjacent < numberOfVertices;++adjacent){
            if((graph[node][adjacent] == 1) && (!visitedNodes[adjacent])){
                visitedNodes[adjacent] = true;
                q.push(adjacent);
            }
        }
   }


}