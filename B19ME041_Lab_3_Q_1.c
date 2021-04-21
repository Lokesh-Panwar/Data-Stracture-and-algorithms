#include<stdio.h>
#include<stdlib.h>
int front = -1;
int rear = -1;
int max_val=0;
int isempty(){
    if (front == -1 & rear ==-1)
        return 1;
    else
    return 0;
}
int isfull(){
    if ((rear+1)%max_val == front){
        return 1;
    }
    else return 0;
}
void enqueue(int queue[],int value){
    if (isfull()==1){
        printf("Queue is Full, (overflow)\n");
        return ;
        }
    if (isempty()==1){
        rear = 0;front=0;
        queue[rear] = value;
    }
    else{
        rear = (rear+1)%max_val;
        queue[rear] = value;
        
    }   
    return; 
}
int dequeue(int queue[]){
    int element = 0;
    if (isempty()==1){
        printf("Queue is Empty, (Underflow).\n");
        return 0;
    }
    if (rear == front){
        element = queue[rear];
        front = -1;
        rear = -1;
    }
    else{
        element =queue[front];
        front = (front+1)%max_val;   
    }
    return element;
}
int main(){
    int *arr,a,val;
    char ch;
    printf("Enter the Maximum size of Queue\n ");
    scanf("%d",&max_val);
    arr = (int*)malloc(max_val*sizeof(int));
    do{
        printf("Enter 1 to insert element in queue.\n");
        printf("Enter 2 to delete elememt from queue.\n");
        scanf("%d",&a);
        if(a==1){
            if (isfull()==1){
            printf("OverFlow(Queue is Full).\n");}
            else{
            printf("Insert value of element to be entered in queue.\n");
            scanf("%d",&val);
            enqueue(arr,val);
            }
        }
        
        else if (a==2){
           
                printf("Deleted element is : %d\n",dequeue(arr));
            }
        
        else{
            printf("Invalid Input");
        }
        printf("Enter 'Y' to Continue the program ");
        scanf("%s",&ch);
    }while(ch=='Y' | ch == 'y');
    
    return 0;
}