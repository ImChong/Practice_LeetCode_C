# Breadth_First_Search：回溯算法
广度优先搜索（Breadth-First Search，简称BFS）是一种用于遍历或搜索树或图的算法。这种方法从根（选择某一节点作为根）开始，探索尽可能靠近根的节点，然后再移动到下一层邻近节点。

BFS在C语言中通常使用队列（Queue）来实现。队列是一种先进先出（FIFO）的数据结构，用于存储待访问的节点。

### 算法步骤

1. 将起始节点加入到一个队列中，并标记为已访问。
2. 当队列不为空时，执行以下操作：
    - 出队列，取出一个节点。
    - 处理当前节点（例如，打印节点信息）。
    - 将当前节点的所有未访问过的邻居节点加入队列，并标记为已访问。

### C语言代码示例

下面是一个使用BFS遍历图的简单C语言示例。这里用一个邻接矩阵来表示图：

```c
#include <stdio.h>
#include <stdlib.h>

// 定义一个队列和相关操作
struct Queue {
    int* data;
    int capacity;
    int front;
    int rear;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->data = (int*) malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    return queue;
}

void enqueue(struct Queue* queue, int item) {
    if (queue->rear == queue->capacity - 1) {
        return; // 队列已满
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->data[++queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    if (queue->front == -1) {
        return -1; // 队列为空
    }
    int item = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; // 队列变空
    } else {
        queue->front++;
    }
    return item;
}

// BFS算法实现
void bfs(int** graph, int vertices, int start) {
    int visited[vertices];
    for (int i = 0; i < vertices; ++i) {
        visited[i] = 0;
    }

    struct Queue* queue = createQueue(vertices);
    enqueue(queue, start);
    visited[start] = 1;

    while (queue->front != -1) {
        int currentVertex = dequeue(queue);
        printf("访问节点 %d\n", currentVertex);

        for (int i = 0; i < vertices; ++i) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    free(queue->data);
    free(queue);
}

int main() {
    int vertices = 5;
    int** graph = (int**) malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; ++i) {
        graph[i] = (int*) malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; ++j) {
            graph[i][j] = 0;
        }
    }

    // 添加边（无向图）
    graph[0][1] = graph[1][0] = 1;
    graph[0][2] = graph[2][0] = 1;
    graph[1][3] = graph[3][1] = 1;
    graph[2][4] = graph[4][2] = 1;

    // 执行BFS
    bfs(graph, vertices, 0);

    // 释放内存
    for (int i = 0; i < vertices; ++i) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
```

### 应用

广度优先搜索在图算法中有很多应用，包括但不限于：

1. 查找最短路径（无权图）。
2. 网络爬虫。
3. 社交网络分析，如找出某个人的“六度空间”。
4. 解决迷宫问题。

这种算法在许多实际问题中都有应用，是图论和计算机科学中一个非常重要的算法。