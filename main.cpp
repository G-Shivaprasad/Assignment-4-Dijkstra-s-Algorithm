#include <iostream>
#include <limits.h>

#define VERTICES 9

int minDistance(int distances[VERTICES], bool spaceSet[VERTICES]) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < VERTICES; v++) {
    
    if (spaceSet[v] == false && distances[v] <= min) {
      min = distances[v]; 
      min_index = v;
    }
    
  }  

  return min_index;
}


struct Result {
  int index;
  int distance;
};

Result dijkstra(int graph[VERTICES][VERTICES], int src) {
  int distances[VERTICES];

  bool spaceSet[VERTICES];


  for (int i = 0; i < VERTICES; i++) {
    distances[i] = INT_MAX;
    spaceSet[i] = false;
  }

  distances[src] = 0;

  for (int count = 0; count < VERTICES - 1; count++) {
    int u = minDistance(distances, spaceSet);
    spaceSet[u] = true;

    for (int v = 0; v < VERTICES; v++) {

      if (!spaceSet[v] && graph[u][v]
          && distances[u] != INT_MAX
          && distances[u] + graph[u][v] < distances[v]
      ) {
        distances[v] = distances[u] + graph[u][v];
      }
    }
  }

  int min = INT_MIN;
  int closest_index = 0;
  for(int i = 0; i < VERTICES; i++) {
    if (distances[i] > min) {
      min = distances[i];
      closest_index = i;
    }
  }

  return {
    .index = closest_index,
    .distance = min, 
  };
}

int main() {

  int graph[VERTICES][VERTICES] = {
    {3, 38, 87, 67, 98, 100, 6, 4, 23},
    {3, 42, 12, 12, 2, 32, 6, 4, 23},
    {9, 134, 23, 25, 9, 21, 0, 1, 23},
    {4, 4, 3, 56, 54, 8, 200, 3, 23},
    {2, 82, 3, 12, 74, 5, 12, 11, 23},
    {10, 15, 3, 5, 6, 2, 6, 33, 23},
    {100, 81, 0, 90, 6, 2, 12, 4, 23},
    {3, 34, 4, 1, 25, 5, 8, 8, 23},
    {59, 34, 5, 5, 8, 2, 6, 4, 23},
  };

  
  Result min_distance = dijkstra(graph, 2);
  std::cout << "Distance = " << min_distance.distance << "; Vertice = " << min_distance.index << std::endl;
  return 0;
}