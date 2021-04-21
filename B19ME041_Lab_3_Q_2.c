#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node *next;
};
typedef struct node node;
node* front =NULL;
node* rear = NULL;
void enqueue(int value){
    node *temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = NULL;
    if (front == NULL & rear ==NULL){
        front = temp; 
        rear = temp;
        return;
    } 
    rear->next = temp;
    rear = temp;
}
int dequeue(){
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
        free(head);
    }

return 0;
}
int Front(){
    return front->value;
}
int main(){
    int a,val;
    char ch;
    //printf("Enter the Maximum size of Queue\n ");
    //scanf("%d",&max_val);
    //arr = (int*)malloc(max_val*sizeof(int));
    do{
        printf("Enter 1 to insert element in queue.\n");
        printf("Enter 2 to delete elememt from queue.\n");
        scanf("%d",&a);
        if(a==1){
            //if (isfull()==1){
            //printf("OverFlow(Queue is Full).\n");}
            //else{
            printf("Insert value of element to be entered in queue.\n");
            scanf("%d",&val);
            enqueue(val);
            //}
        }
        
        else if (a==2){
           dequeue();
        }
        
        else{
            printf("Invalid Input\n");
        }
        printf("Enter 'Y' to Continue the program ");
        scanf("%s",&ch);
    }while(ch=='Y' | ch == 'y');
    
    return 0;
}