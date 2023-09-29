#include <iostream>
#include <vector>
#include <queue>

 //bfs algorithm

void  breadth_first_search(const std::vector<std::vector<int>>& graph, int root){
     int numOfVertices = graph.size();
     std::vector<bool> visitedNodes(numOfVertices);
   std::queue<int> q;

    int rootNode{root};
   //pushing the root node (node #0) into the queue
   q.push(rootNode);

   //marking the root node as visited
   visitedNodes[rootNode] =  true;

   while(!q.empty()){
        int node{q.front()};
        std::cout<<node<<' ';
        q.pop();
        for(int adjacent{0}; adjacent < numOfVertices;++adjacent){
             //visiting all unvisited neighbours of the current node
            if((graph[node][adjacent] == 1) && (!visitedNodes[adjacent])){ 
                visitedNodes[adjacent] = true;
                q.push(adjacent);
            }
        }
   }
}


int main(){
   const size_t numberOfVertices{6};

   //initialization of the adjacency matrix
   std::vector<std::vector<int>> graph{
          { 1, 0, 0, 1, 1, 0},
          { 0, 1, 0, 0, 1, 1},
          { 0, 0, 1, 1, 0, 1},
          { 0, 1, 0, 0, 0, 1},
          {0, 0, 1, 1, 0, 1},
          {1, 0, 1, 0, 0, 0}
   };

   
   breadth_first_search(graph,0);


}