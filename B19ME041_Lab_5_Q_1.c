#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b){
    int z;
    z=*a;
    *a = *b;
    *b = z;
    return;
}

void slc_sort(int *arr,int n){
    int smallest;
    for(int i=0;i<n;i++){
        smallest = i;
        for(int j=i+1;j<n;j++){
            if (arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        swap(&arr[i],&arr[smallest]);
    }
    return;
}
void bub_srt(int *arr,int n){
    int f;
    for(int i=0;i<n;i++){
        f = 0;
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                f = 1;
            }
        }
        n = n-1;
        if (f=0){
            break;
        }
    }
    return;
}

void insrt_srt(int *arr,int n){
    int key,j; 
    for(int i = 0;i<n;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 & key<arr[j]){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1]=key;
    }
    return;
}
void merge(int arr[],int left[],int right[],int lsize,int rsize){
    int lindex=0,rindex=0,*a;
    int i=0;
    while(i<(lsize+rsize)){
        
        if(rindex>rsize | (lindex<lsize & left[lindex]<=right[rindex])){
            arr[i] = left[lindex];
            lindex++;
            
        }
        else{
            arr[i] = right[rindex];
            rindex++;
        }
    i++;
        
    }
}
void mrg_srt(int arr[],int n){
    if (n<=1){
        return;
    }
    int n1 = n/2;
    int n2 = n-n1;
    int L1[n1],L2[n2];
    int *L,*R;
    for(int i=0;i<n1;i++){
        L1[i] = arr[i];
    }
    for(int i=0;i<n2;i++){
        L2[i]=arr[n1+i];
    }
    mrg_srt(L1,n1);
    mrg_srt(L2,n2);
    merge(arr,L1,L2,n1,n2);
    return;
}
int partition(int *arr,int st,int ed){
    int pivot = arr[ed];
    int i = (st-1);
    for(int j=st;j<ed;j++){
        if (arr[j]<=pivot){
            i = i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[ed]);
    return i+1;
}
void qck_srt(int *arr,int start,int end){
    int pivot;
    if(start<end){
        pivot = partition(arr,start,end);
        qck_srt(arr,start,pivot-1);
        qck_srt(arr,pivot+1,end);
    }
    return;
}
void display(int n){
    double elapsed_time = 0.0;
    int arr[n];
     
    // Taking input sequence
    if(n==10){
    printf("Entered sequence is : ");
    for(int j=0;j<n;j++){
        arr[j]=rand()%n;
        printf("%d ",arr[j]);
    } }
    clock_t start = clock();
    // Selection sort       
    printf("\nArray sorted by Selection Sort: ");    
    slc_sort(arr,10);
    if(n==10){   
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }}
    clock_t end = clock();
    elapsed_time += ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nRuntime of Selection sort is: %f\n",elapsed_time);
    
    //Bubble sort display
    elapsed_time = 0.0;
    start = clock(); 
    printf("\nArray sorted by Bubble Sort: ");    
    bub_srt(arr,n);
    if (n==10){   
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }}
    end = clock();
    elapsed_time += ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nRuntime of bubble sort is: %f\n",elapsed_time);
    
    //insertion sort display
    elapsed_time = 0.0;
    start = clock(); 
    printf("\nArray sorted by Insertion Sort: ");    
    insrt_srt(arr,n);
    if (n==10){   
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }}
    end = clock();
    elapsed_time += ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nRuntime of insertion sort is: %f\n",elapsed_time);

    //merge sort display
    elapsed_time = 0.0;
    start = clock(); 
    printf("\nArray sorted by merge Sort: ");    
    mrg_srt(arr,n);
    if(n==10){   
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }}
    end = clock();
    elapsed_time += ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nRuntime of merge sort is: %f\n",elapsed_time);

    //quick sort display
    elapsed_time = 0.0;
    start = clock(); 
    printf("\nArray sorted by quick Sort: ");    
    qck_srt(arr,0,n);
    if(n==10){   
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }}
    end = clock();
    elapsed_time += ((double)(end-start))/CLOCKS_PER_SEC;
    printf("\nRuntime of quick sort is: %f\n",elapsed_time);
    return;
}

int main(){
    int a;
    while(1){
        printf("1) 10 input \n2) 100 input\n3) 1000 input\n4) 2000 input\n5) 3000 input\n6) n input(Entered by user)\n7) Exit\n");
        scanf("%d",&a);
        if (a==1){
            display(10);
        }
        else if(a==2){
            display(100);
        }
        else if(a==3){
            display(1000);
        }
        else if(a==4){
            display(2000);
        }
        else if(a==5){
            display(3000);
        }
        else if(a==6){
            int n;
            scanf("%d",&n);
            display(n);
        }
        else if(a==7){
            break;
        }
    }
    
    return 0;
}