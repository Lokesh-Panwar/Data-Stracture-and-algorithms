#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int value;
    struct node *next;
};
typedef struct node node;
node* front =NULL;
node* rear = NULL;
void enqueue_rear(int value){
    node *temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (front == NULL & rear ==NULL){
        front = temp; 
        rear = temp;
        return;
    } 
    rear->next = temp;
    temp->prev = rear;
    rear = temp;
    return;
}
void enqueue_front(int value){
    node *temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (front == NULL & rear ==NULL){
        front = temp; 
        rear = temp;
        return;
    } 
    front->prev = temp;
    temp->next = front;
    front = temp;
    return;
}
int dequeue_front(){
    node *head = front;
    if (front == NULL){
        printf("!!Queue is empty!! \n");
    }
    else if (front == rear){
        printf("Element deleted from queue is:  %d\n",front->value);
        front = NULL;
        rear = NULL;
    }
    else{
        printf("Element deleted from queue is:  %d\n",front->value);
        front = front->next;
        front->prev = NULL;
        free(head);
    }

return 0;
}
int dequeue_rear(){
    node *head = rear;
    if(front == NULL & rear == NULL){
        printf("!!Queue is empty!! \n");
    }
    else if (front == rear){
        printf("Element deleted from queue is:  %d\n",front->value);
        front = NULL;
        rear = NULL;
    }
    else{
        printf("Element deleted from queue is:  %d\n",rear->value);
        rear = rear->prev;
        rear->next = NULL;
        free(head);
    }

return 0;
}
void queueFront(){
     if (front == NULL){
        printf("!!Queue is empty!! \n");
        return;
    }
    printf("Element at Front is : %d\n",front->value);
    return;
}
void queueRear(){
    if(front == NULL & rear == NULL){
        printf("!!Queue is empty!! \n");
        return;
    }
    printf("Element at Front is : %d\n",rear->value);
    return;
    }
int main(){
    int a,val;
    char ch;
    do{
        printf("Enter 1 to enqueue element at rear.\n");
        printf("Enter 2 to enqueue element at front.\n");
        printf("Enter 3 to dequeue element at front.\n");
        printf("Enter 4 to dequeue element at rear.\n");
        printf("Enter 5 to view element at front.\n");
        printf("Enter 6 to view element at rear.\n");
        scanf("%d",&a);
        if(a==1){
            printf("Insert value of element to be entered in queue.\n");
            scanf("%d",&val);
            enqueue_rear(val);
        }
        
        else if (a==3){
           dequeue_front();
        }
        else if(a==2){
            printf("Insert value of element to be entered in queue.\n");
            scanf("%d",&val);
            enqueue_front(val);
        }
        else if (a==4){
           dequeue_rear();
        }
        else if (a==5){
           queueFront();
        }
        else if (a==6){
           queueRear();
        }
        
        else{
            printf("Invalid Input\n");
        }
        printf("Enter 'Y' to Continue the program ");
        scanf("%s",&ch);
    }while(ch=='Y' | ch == 'y');
    
    return 0;
}