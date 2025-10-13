#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];

// Enqueue function
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
    }
}

// Dequeue function
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;  // Queue empty
    } else {
        int value = queue[front];
        front++;
        return value;
    }
}

// BFS function
void BFS(int adj[MAX][MAX], int start, int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int current = dequeue();
        if (current == -1) break;

        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    int adj[MAX][MAX];
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(adj, start, n);

    return 0;
}

