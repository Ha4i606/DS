#include <stdio.h>
#define MAX 5
int queue[MAX];
int front=-1,rear=-1;

int isFull() 
{
    return rear==MAX-1;
}

int isEmpty() 
{
    return front==-1||front>rear;
}

void enqueue(int item) 
{
    if(isFull()) 
    {
        printf("Overflow\n");
        return;
    }
    if(front==-1)front=0;
    rear++;
    queue[rear]=item;
    printf("%d inserted\n", item);
}

void dequeue() 
{
    if (isEmpty()) 
    {
        printf("Underflow\n");
        return;
    }
    int item = queue[front];
    front++;
    printf("%d deleted\n", item);

    if(front>rear) 
    {  
        front = rear = -1;
    }
}

void display() {
    if (isEmpty()) 
    {
        printf("Underflow\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) 
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int main() {
    int ch, item2;
    while (1) {
        printf("\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoose an option: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Enter item to enqueue: ");
                scanf("%d", &item2);
                enqueue(item2);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}



