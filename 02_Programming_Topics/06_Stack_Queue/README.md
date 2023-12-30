# 1. Stack_Queue：栈和队列

栈（Stack）和队列（Queue）是两种基础的数据结构，它们用于存储和管理数据集合。尽管这两种数据结构在很多高级编程语言中都有内置的实现，C语言本身并没有提供这些数据结构的内置支持。然而，你可以使用数组或链表来实现它们。

- [1. Stack\_Queue：栈和队列](#1-stack_queue栈和队列)
  - [1.1. 栈（Stack）](#11-栈stack)
  - [1.2. 队列（Queue）](#12-队列queue)
  - [Question List](#question-list)

## 1.1. 栈（Stack）

栈是一个后进先出（Last-In-First-Out，LIFO）的数据结构。这意味着最后一个被添加到栈中的元素将是第一个被移除的。栈主要有两个基本操作：

1. **压栈（Push）**：在栈顶添加一个元素。
2. **出栈（Pop）**：移除并返回栈顶元素。

下面是使用数组实现栈的一个简单示例：

```c
#define MAX 10 // 定义栈的最大容量

int stack[MAX];
int top = -1; // 初始化栈顶指针

// 压栈操作
void push(int x) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = x;
}

// 出栈操作
int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
```

## 1.2. 队列（Queue）

队列是一个先进先出（First-In-First-Out，FIFO）的数据结构。这意味着第一个被添加到队列中的元素将是第一个被移除的。队列主要有两个基本操作：

1. **入队（Enqueue）**：在队尾添加一个元素。
2. **出队（Dequeue）**：移除并返回队首元素。

下面是使用数组实现队列的一个简单示例：

```c
#define MAX 10 // 定义队列的最大容量

int queue[MAX];
int front = 0; // 初始化队首指针
int rear = -1; // 初始化队尾指针

// 入队操作
void enqueue(int x) {
    if (rear >= MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    queue[++rear] = x;
}

// 出队操作
int dequeue() {
    if (front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    return queue[front++];
}
```

需要注意的是，以上的示例代码为了简单明了，并没有涉及动态分配内存或其他高级特性。

栈常用于实现函数调用、深度优先搜索（DFS）、表达式求值等；而队列常用于广度优先搜索（BFS）、任务调度等。在C语言中，你可以根据具体的需求，使用数组或链表等基础数据结构来实现这些高级数据结构。

## Question List

```txt
.
├───01_myQueueCreate
│   ├───cfg
│   ├───inc
│   └───src
├───02_myStackCreate
│   ├───cfg
│   ├───inc
│   └───src
├───03_isValid
├───04_removeDuplicates
├───05_evalRPN
├───06_maxSlidingWindow
└───07_topKFrequent
```
