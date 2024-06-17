#include <iomanip>
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 7

void addEdge(int adjMatrix[MAX][MAX], int u, int v, int src) {
  adjMatrix[u][v] = src;
  adjMatrix[v][u] = src;
}
void printAdjMatrix(int adjMatrix[MAX][MAX]) {
  cout << setw(2) << "";
  for (int i = 0; i < MAX; i++)
    cout << setw(3) << i;
  cout << "\n";
  for (int i = 0; i < MAX; i++) {
    cout << setw(2) << i;
    for (int j = 0; j < MAX; j++) {
      cout << setw(3) << adjMatrix[i][j];
    }
    cout << "\n";
  }
}
void printAdjList(int adjMatrix[MAX][MAX]) {
  int count = 0;
  for (int i = 0; i < MAX; i++) {
    cout << i << "-> ";
    for (int j = 0; j < MAX; j++) {
      if (adjMatrix[i][j] != 0) {
        count++;
        cout << j << "(" << adjMatrix[i][j] << ")  ";
      }
    }
    count = 0;
    cout << endl;
  }
}
void dij(int adjMatrix[MAX][MAX], int src) {
  int dist[MAX];
  bool sptSet[MAX];
  for (int i = 0; i < MAX; i++) {
    dist[i] = INT_MAX, sptSet[i] = false;
  }
  dist[src] = 0;
  for (int count = 0; count < MAX - 1; count++) {
    int min = INT_MAX;
    int min_index = INT_MAX;
    for (int vertex = 0; vertex < MAX; vertex++) {
      if (sptSet[vertex] == false && dist[vertex] <= min) {
        min = dist[vertex];
        min_index = vertex;
      }
    }
    int u = min_index;
    sptSet[u] = true;
    for (int vertex = 0; vertex < MAX; vertex++) {
      if (!sptSet[vertex] && adjMatrix[u][vertex] && dist[u] != INT_MAX &&
          dist[u] + adjMatrix[u][vertex] < dist[vertex]) {
        dist[vertex] = dist[u] + adjMatrix[u][vertex];
      }
    }
  }
  printf("\nStarting node:%d\n", src);
  for (int i = 0; i < MAX; i++) {
    if (i != src) {
      printf("\nDistance of node %d = %d", i, dist[i]);
    }
  }
}
void dfs(int adjMatrix[MAX][MAX], int source) {
  int i, j;
  bool change = false;
  int visited[MAX];
  int tos = 0;
  int stack[MAX];
  for (i = 0; i < MAX; i++) {
    visited[i] = 0;
  }
  visited[source] = 1;
  stack[tos] = source;
  printf("%d ", source);
  while (tos >= 0) {
    change = false;
    i = stack[tos];
    for (j = 0; j < MAX; j++) {
      if (visited[j] == 0 && adjMatrix[i][j] > 1) {
        visited[j] = 1;
        tos++;
        stack[tos] = j;
        printf("%d ", j);
        change = true;
        break;
      }
    }
    if (change == false) {
      tos--;
    }
  }
  printf("\n");
}
void bfs(int adjMatrix[MAX][MAX], int src) {
  int i, j;
  int queue[MAX];
  int visited[MAX];
  int queue_front = 0, queue_end = 0;
  for (i = 0; i < MAX; i++) {
    visited[i] = 0;
  }
  visited[src] = 1;
  queue[queue_end] = src;
  queue_end++;
  printf("%d ", src);
  while (queue_front <= queue_end) {
    int index = queue_front;
    queue_front++;
    i = queue[index];
    for (j = 0; j < MAX; j++) {
      if (visited[j] == 0 && adjMatrix[i][j] > 1) {
        visited[j] = 1;
        queue[queue_end] = j;
        queue_end++;
        printf("%d ", j);
      }
    }
  }
  printf("\n");
}
int main() {
  int adjMatrix[MAX][MAX];
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      adjMatrix[i][j] = 0;
    }
  }
  addEdge(adjMatrix, 0, 1, 7);
  addEdge(adjMatrix, 0, 2, 5);
  addEdge(adjMatrix, 1, 3, 5);
  addEdge(adjMatrix, 1, 4, 2);
  addEdge(adjMatrix, 2, 3, 9);
  addEdge(adjMatrix, 2, 5, 3);
  addEdge(adjMatrix, 3, 6, 8);
  addEdge(adjMatrix, 4, 6, 3);
  addEdge(adjMatrix, 4, 3, 1);
  addEdge(adjMatrix, 5, 6, 4);
  addEdge(adjMatrix, 5, 3, 1);
  cout << "Adjacency Matrix:" << endl;
  printAdjMatrix(adjMatrix);
  cout << "\nAdjacency List:" << endl;
  printAdjList(adjMatrix);
  cout << "\nDjikstra's algorithm:" << endl;
  dij(adjMatrix, 1);
  cout << "\n\nDepth First Search:" << endl;
  dfs(adjMatrix, 0);
  cout << "\nBreadth First Search:" << endl;
  bfs(adjMatrix, 0);
  return 0;
}