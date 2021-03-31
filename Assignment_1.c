#include<stdio.h>
int top = -1;
void push(int value,int stack[]){
    top++;
    stack[top] = value;
}
int pop(int stack[]){
    if (top == -1){
        printf("Empty Stack");
        return 0;
    }else
        return stack[top--];
}
int stackTop(int stack[]){
    if (top == -1)
        return 0;
    else
        return stack[top];
}

int main(){
    int n,*ptr;
    scanf("%d",&n);
    int seq[n],arr[n];
    //ptr = a;
    // Taking a list as input 
    for(int i=0;i<n;i++){
        scanf("%d",&seq[i]);
    }
    //Checking whether given sequence is possible or not
    int i = 0,element = 1,flag = 0;
    while(i!=n){
        if(stackTop(arr)== seq[i]){
            pop(arr);
            i++;
        }
        else if(seq[i]<element && stackTop(arr)!=seq[i]){flag = 1;break;}
		else{
			push(element,arr);
			element++;
		}
    }
    //Printing the operation, if sequence is possible
    i = 0,element = 1;
    if (flag == 0){
        printf("Yes\n");
        while(i!=n){
            if(stackTop(arr)== seq[i]){
                pop(arr);
                printf("pop(), ");
                i++;
            }
            else if(seq[i]<element && stackTop(arr)!=seq[i]){break;}
		    else{
			    push(element,arr);
                printf("push(%d), ",element);
			    element++;
		    }
        }
        printf("\n");
    }else{
        printf("No\n");
    }
    return 0;
}