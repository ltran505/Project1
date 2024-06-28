// Tran, Lily

void bfs(const vector<vector<int>>& graph, 
         list<int>& bfsSequence, const int vertex)
{
   size_t numberOfVertices = graph.size();
   char *visitedVertices = new char[numberOfVertices];
   
   visitedVertices[vertex] = 'T';
   bfsSequence.push_back(vertex);
   
   int currentVertice = vertex;
   queue<int> aQueue;
   
   while (bfsSequence.size() < numberOfVertices)
   {
      if ( (bfsSequence.size() +  aQueue.size()) 
            < numberOfVertices)
      {
         for (size_t col = 0; col < numberOfVertices; ++col) 
         {
            if (graph[currentVertice][col] == 1 
                && visitedVertices[col] != 'T') 
            {
               visitedVertices[col] = 'T';
               aQueue.push(col);
            }
         }
      }
      
      currentVertice = aQueue.front();
      aQueue.pop();
      bfsSequence.push_back(currentVertice);
   }
   
   delete [] visitedVertices;
   visitedVertices = nullptr;
}
  
}
