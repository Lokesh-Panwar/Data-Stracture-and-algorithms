#include<stdio.h>
#include<stdlib.h>
int max_heap[100],min_heap[100];
void swap(int *a,int *b){
    int z;
    z = *a;
    *a = *b;
    *b = z;
    return;
}
void max_heapify(int i){
    int left,right,n,largest;
    left = 2*i;
    right = 2*i + 1;
    n = max_heap[0];
    if (left<=n & max_heap[left]>max_heap[i]){
        largest = left;
    } 
    else{
        largest = i;
    }
    if (right<=n & max_heap[right]>max_heap[largest]){
        largest = right;
    }
    if (largest!=i){
        swap(&max_heap[i],&max_heap[largest]);
        max_heapify(largest);
    }
    return;
}
void min_heapify(int i){
    int left,right,n,smallest;
    left = 2*i;
    right = 2*i + 1;
    n = min_heap[0];
    if (left<=n & min_heap[left]<min_heap[i]){
        smallest = left;
    } 
    else{
        smallest = i;
    }
    if (right<=n & min_heap[right]<min_heap[smallest]){
        smallest = right;
    }
    if (smallest!=i){
        swap(&min_heap[i],&min_heap[smallest]);
        min_heapify(smallest);
    }
    return;
}
void build_max_heap(){
    int n = (max_heap[0]/2)+1;
    for(int i = n/2+1;i>=1;i--){
        max_heapify(i);
    }
}
void build_min_heap(){
    int n = (min_heap[0]/2)+1;
    for(int i = n/2+1;i>=1;i--){
        min_heapify(i);
    }
}
void insert_max_heap(int val){
    max_heap[0] = max_heap[0]+1;
    int n=max_heap[0];
    max_heap[n] = val;
    build_max_heap();
}
void insert_min_heap(int val){
    min_heap[0] = min_heap[0]+1;
    int n=min_heap[0];
    min_heap[n] = val;
    build_min_heap();
}
void delete_max_heap(int val){
    int p,n = max_heap[0],f=0;

    for(int i = 1;i<=n;i++){
        if(max_heap[i]==val){
            p = i;
            f = 1;
            break;
        }
    }
    if (f==0){
        return;
    }
    swap(&max_heap[p],&max_heap[n]);
    max_heap[0] = max_heap[0]-1;
    build_max_heap();
}
void delete_min_heap(int val){
    int p,n = min_heap[0],f=0;
    for(int i = 1;i<=n;i++){
        if(min_heap[i]==val){
            p = i;
            f = 1;
            break;
        }
    }
    if (f==0){
        return;
    }
    swap(&min_heap[p],&min_heap[n]);
    min_heap[0] = min_heap[0]-1;
    build_min_heap();
}
void del_max_max_heap(){
    delete_max_heap(max_heap[1]);
}
void del_min_min_heap(){
    delete_min_heap(min_heap[1]);
}
void display(int arr[]){
	int i;
	for(i=1;i<=arr[0];i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
int main(){
    int a,num;
    char ch;
    while (1){
        printf("1 X: To insert elements in max-heap followed by number of element and elements\n");
        printf("1 N: To insert elements in min-heap followed by number of element and elements\n");
        printf("2 X: To insert integer into the already existing max-heap followed by that integer\n");
        printf("2 N: To insert integer into the already existing min-heap followed by that integer\n");
        printf("3 X: To delete element from the existing max-heap followed by value of element\n");
        printf("3 N: To delete element from the existing min-heap followed by value of element\n");
        printf("4 X: TO delete maximum element from the existing max-heap\n");
        printf("4 N: TO delete minimum element from the existing min-heap\n");
        printf("5 Y: To exit the program\n");
        scanf("%d %c",&a,&ch);
        if(a == 1 & ch =='X'){
            scanf("%d",&num);
            max_heap[0] = num;
            for(int i=1;i<=num;i++){
                scanf("%d",&max_heap[i]); 
            }
            build_max_heap();
            display(max_heap);
        }
        else if(a == 1 & ch =='N'){
            scanf("%d",&num);
            min_heap[0] = num;
            for(int i=1;i<=num;i++){
                scanf("%d",&min_heap[i]); 
            }
            build_min_heap();
            display(min_heap);
        }
        else if(a == 2 & ch=='X'){
            scanf("%d",&num);
            insert_max_heap(num);
            display(max_heap);
        }
        else if(a == 2 & ch=='N'){
            scanf("%d",&num);
            insert_min_heap(num);
            display(min_heap);
        }
        else if(a == 3 & ch=='X'){
            scanf("%d",&num);
            delete_max_heap(num);
            display(max_heap);
        }
        else if(a == 3 & ch=='N'){
            scanf("%d",&num);
            delete_min_heap(num);
            display(min_heap);
        }
        else if(a == 4 & ch=='X'){
            del_max_max_heap();
            display(max_heap);
        }
        else if(a == 4 & ch== 'N'){
            del_min_min_heap();
            display(min_heap);
        }
        else if(a==5){
            break;
        }
        else
        {printf("Wrong input");}
    }
    return 0;

}