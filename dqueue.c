#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

int isFull() {

    return (front == 0 && rear == MAX - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void insertFront(int item) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) 
    {
        front = rear = 0;
    } else if (front == 0) 
    {
        front = MAX - 1;
    } else 
    {
        front = front - 1;
    }
    deque[front] = item;
    printf("%d inserted at front\n", item);
}

void insertRear(int item) 
{
    if (isFull()) 
    {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) 
    {
        front = rear = 0;
    } else if (rear == MAX - 1) 
    {
        rear = 0;
    } else {
        rear = rear + 1;
    }
    deque[rear] = item;
    printf("%d inserted at rear\n", item);
}

void deleteFront() 
{
    if (isEmpty()) 
    {
        printf("Underflow\n");
        return;
    }

    int item = deque[front];
    if (front == rear) 
    {

        front = rear = -1;
    } else if (front == MAX - 1) 
    {
        front = 0;
    } else 
    {
        front = front + 1;
    }
    printf("%d deleted from front\n", item);
}

void deleteRear() 
{
    if (isEmpty()) 
    {
        printf("Underflow\n");
        return;
    }

    int item = deque[rear];
    if (front == rear) 
    {
        front = rear = -1;
    } else if (rear == 0) 
    {
        rear = MAX - 1;
    } else 
    {
        rear = rear - 1;
    }
    printf("%d deleted from rear\n", item);
}

void display() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) 
    {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int ch, item;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter item to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter item to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

