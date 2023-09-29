#include <iostream>
#include <vector>
#include <stack>

//dfs algorithm

void depth_first_search(const std::vector<std::vector<int>>& graph,int root){

    int numberOfVertices = graph.size();
    std::vector<bool> visited(numberOfVertices);
    std::stack<int> stack; //we will use the stack for backtracking

   int rootNode{root};

   //pushing the root node into the stack
   stack.push(rootNode);
   visited[rootNode] = true;//marking root node as visited

   while (!stack.empty()) {
            int currentVertex = stack.top();
            std::cout << currentVertex << " ";
            stack.pop();

            for (int i = 0; i < numberOfVertices; ++i) {
                if (graph[currentVertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    stack.push(i);
                }
            }
        }
}


int main(){
    const int numberOfVertices{6};

    //initialization of the adjacency matrix
   std::vector<std::vector<int>> graph{
        {1, 0, 1, 0, 0, 1},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0, 0}
   };

   depth_first_search(graph,0);
}