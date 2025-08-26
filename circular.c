#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

int isFull()
{
    return (front == (rear + 1) % SIZE);
}

int isEmpty()  
{
    return (front == -1);
}

void enqueue(int item) 
{
    if (isFull()) 
    {
        printf("Queue overflow: cannot insert %d\n", item);
        return;
    }
    if (isEmpty()) 
    {
        front = 0;
    }
    rear = (rear + 1) % SIZE;
    queue[rear] = item;
}

int dequeue() 
{
    if (isEmpty()) 
    {
        printf("Queue underflow\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) 
    {
        front = -1;
        rear = -1;
    } 
    else 
    {
        front = (front + 1) % SIZE;
    }
    return item;
}

void display() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) 
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() 
{
    int choice, item;

    while (1) 
    {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

