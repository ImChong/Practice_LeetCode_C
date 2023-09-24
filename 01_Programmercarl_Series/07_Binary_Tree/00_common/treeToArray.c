#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

/* 树节点 */
struct TreeNode {
    int val;                    /* 节点的值 */
    struct TreeNode *left;      /* 左节点 */
    struct TreeNode *right;     /* 右节点 */
};

typedef struct {
    struct TreeNode* data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void enqueue(Queue* q, struct TreeNode* node) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("Queue overflow\n");
        exit(1);
    }
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

struct TreeNode* dequeue(Queue* q) {
    if (q->front == q->rear) {
        printf("Queue underflow\n");
        exit(1);
    }
    struct TreeNode* item = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return item;
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

int* treeToArray(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int* result = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));
    Queue q;
    q.front = q.rear = 0;

    enqueue(&q, root);
    int index = 0;

    while (!isEmpty(&q)) {
        struct TreeNode* current = dequeue(&q);
        if (current) {
            result[index] = current->val;
            enqueue(&q, current->left);
            enqueue(&q, current->right);
        } else {
            result[index] = -1;  // 使用-1表示NULL，仅适用于不包含负值的树
        }
        index++;
    }

    *returnSize = index;
    return result;
}

int main() {
    // 测试代码
    struct TreeNode a = {1, NULL, NULL};
    struct TreeNode b = {2, NULL, NULL};
    struct TreeNode c = {3, NULL, NULL};
    a.left = &b;
    a.right = &c;

    int size;
    int* arr = treeToArray(&a, &size);
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1)
            printf("%d ", arr[i]);
        else
            printf("NULL ");
    }
    free(arr);

    return 0;
}
