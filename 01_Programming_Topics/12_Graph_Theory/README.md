# 1. Graph_Theory：图论

图论（Graph Theory）是数学的一个分支，用于研究图（Graphs）的性质和应用。在计算机科学中，图论也有广泛的应用，用于解决诸如网络路由、社交网络分析、数据依赖等问题。

- [1. Graph\_Theory：图论](#1-graph_theory图论)
  - [1.1. 基本概念](#11-基本概念)
  - [1.2. 算法](#12-算法)
  - [1.3. 示例：使用邻接表表示图](#13-示例使用邻接表表示图)

在C语言中，图通常可以用几种不同的数据结构来表示：

1. **邻接矩阵（Adjacency Matrix）**：一个二维数组，其中`matrix[i][j]`表示节点`i`和节点`j`之间是否存在一条边。
2. **邻接表（Adjacency List）**：一个数组，其中每个元素是一个链表，代表与该节点相连的所有其他节点。
3. **边的数组（Edge Array）**：一个包含所有边的数组，每个边由一对节点表示。

## 1.1. 基本概念

- **节点（Vertices）和边（Edges）**：图由节点（也叫顶点）和连接这些节点的边组成。
- **有向图和无向图**：在有向图中，边有方向，从一个节点指向另一个节点；在无向图中，边没有方向。
- **权重（Weights）**：边可能有权重，代表从一个节点到另一个节点的“成本”或“距离”。
- **连通性（Connectivity）**：一个图可能是连通的或非连通的。在连通图中，任意两个节点之间都存在一条路径。

## 1.2. 算法

图论中有很多基本但重要的算法，例如：

1. **深度优先搜索（DFS）和广度优先搜索（BFS）**：用于遍历图以及解决如连通性、路径查找等问题。
2. **最短路径算法**：Dijkstra算法、Floyd-Warshall算法、A*算法等用于在带权图中查找最短路径。
3. **最小生成树（Minimum Spanning Tree）**：Prim算法和Kruskal算法用于找出无向连通图的最小生成树。
4. **拓扑排序（Topological Sort）**：用于有向无环图，用于任务调度等问题。

## 1.3. 示例：使用邻接表表示图

下面是一个简单的C语言代码示例，展示了如何使用邻接表来表示图，并进行深度优先搜索（DFS）：

```c
#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
struct Node {
    int vertex;
    struct Node* next;
};

// 添加边
struct Node* addEdge(struct Node* list, int vertex) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = list;
    return newNode;
}

// 深度优先搜索
void dfs(struct Node** graph, int* visited, int vertex) {
    printf("访问节点 %d\n", vertex);
    visited[vertex] = 1;
    struct Node* adj = graph[vertex];
    while (adj != NULL) {
        if (!visited[adj->vertex]) {
            dfs(graph, visited, adj->vertex);
        }
        adj = adj->next;
    }
}

int main() {
    int vertices = 5;
    struct Node* graph[vertices];
    int visited[vertices];

    // 初始化图和访问数组
    for (int i = 0; i < vertices; ++i) {
        graph[i] = NULL;
        visited[i] = 0;
    }

    // 添加边（这里是一个无向图的例子）
    graph[0] = addEdge(graph[0], 1);
    graph[0] = addEdge(graph[0], 4);
    graph[1] = addEdge(graph[1], 0);
    graph[1] = addEdge(graph[1], 3);
    graph[1] = addEdge(graph[1], 4);
    graph[2] = addEdge(graph[2], 3);
    graph[3] = addEdge(graph[3], 1);
    graph[3] = addEdge(graph[3], 2);
    graph[4] = addEdge(graph[4], 0);
    graph[4] = addEdge(graph[4], 1);

    // 进行深度优先搜索
    dfs(graph, visited, 0);

    return 0;
}
```

这个程序使用邻接表来表示图，并进行了一次从节点0开始的深度优先搜索。

总之，图论在C语言中主要通过各种数据结构和算法来实现，它在解决许多实际问题中具有重要作用。
