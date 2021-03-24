#include<stdio.h>
#include<stdlib.h>
// node of linked list
struct node{ 
    int pow;  //to store power 
    int coff; //to store coefficient
    struct node* next;
};
typedef struct node node;
//function to calculate a^b
int power(int a, int b){
    int v = 1;
    for(int i=0;i<b;i++){
        v = v*a;
    }
    return v;
}
//function to make linked list out of all node 
node* insert_at_last(node *head,int p,int c){
	if(head == NULL){ //if head is NULL, then assign memory to it.(to enter first element)
	    head = (node*)malloc(sizeof(node));
        head->pow = p;
	    head->coff = c;
	    head->next = NULL;
	}
    else{
		node* temp;
		temp = head;
        node* current;// it is current node on which you want to 
		current = (node*)malloc(sizeof(node));
		while(temp->next != NULL){ //iteration to go to at the end of linked list
			temp = temp->next;
		}
		current->pow = p; // add values at the last node
        current->coff = c;
		current->next = NULL;
		temp->next = current;
	}
    return head;
}
// function to add two polynomials 
node* poly_add(node* head,node* head1,node* head2){
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp1!=NULL && temp2!=NULL){
        //if power of one polynomial is greater than other, directly print that element
        if (temp1->pow > temp2->pow){
            head = insert_at_last(head,temp1->pow,temp1->coff);
            temp1 = temp1->next;
        }
        //if power of one polynomial is less than other, directly print that element
        else if (temp1->pow < temp2->pow){
            head = insert_at_last(head,temp2->pow,temp2->coff);
            temp2 = temp2->next;
        }
        //if both element are equal than add both the element
        else if (temp1->pow == temp2->pow){
            head = insert_at_last(head,temp1->pow,(temp1->coff + temp2->coff));
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

    }
    return head;
}
// function to substract the element
node* poly_sub(node* head,node* head1,node* head2){
    node* temp1 = head1;
    node* temp2 = head2;
    while(temp1!=NULL && temp2!=NULL){
        //if power of first polynomial is greater than other, directly print that element
        if (temp1->pow > temp2->pow){
            head = insert_at_last(head,temp1->pow,temp1->coff);
            temp1 = temp1->next;
        }
        //if power of second polynomial is greater than other, directly print that element with negative sign
        else if (temp1->pow < temp2->pow){
            head = insert_at_last(head,temp2->pow,-temp2->coff);
            temp2 = temp2->next;
        }
        //if both element are equal than substract them
        else if (temp1->pow == temp2->pow){
            head = insert_at_last(head,temp1->pow,(temp1->coff - temp2->coff));
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

    }
    return head;
}
//fiunction to print the element
void display(node *head){
    node* temp = head;
    if(head == NULL){// if no input is given, print 0
		printf("0\n");
		return;
	}
    else if(temp->pow == 0){// if power of first element is 0 print only coefficient
		printf("%d\n",temp->coff);
		return;
	}
    else {//print in standard notation
        printf("%dx^%d",temp->coff,temp->pow);}
	temp = temp->next;
	if(temp == NULL){//return if 2nd element is null  
		printf("\n");
		return;}
    else{//printing in std notation
        while(temp->next!= NULL){
			if(temp->coff > 0){
                printf(" + %dx^%d",temp->coff,temp->pow);}
            else if (temp->coff ==0){
                temp = temp->next; 
                continue;}
			else{
                printf(" - %dx^%d",abs(temp->coff),temp->pow);}
			temp = temp->next;
		}}
    //printing last coefficient(with power 0)
    if(temp->coff < 0) printf(" - %d\n",abs(temp->coff));
    else if (temp->coff == 0) printf("\n");
	else printf(" + %d\n",temp->coff);
}
// function to evaluate value of polynomial
int value(node* head, int x){
	int val = 0;
	if(head == NULL){
		printf("P(%d) = 0\n",x);
		return 0;
	}
	node* temp = head;
	while(temp->next != NULL){
		int count;
		count = power(x,(temp->pow));
		count = count*(temp->coff);
		val += count;
		temp = temp->next;
	}val += temp->coff;
	return val;
}
int main(){
    int k=0,coff=0,high=0,high2=0,val_x=0;
    node* head1 = NULL;
    node* head2 = NULL;
    node* head3 = NULL;
    node* head4 = NULL;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d",&high);
        for(int i = high;i>=0;i--){
            scanf("%d",&coff);
            if (coff == 0){continue;}
            head1 = insert_at_last(head1,i,coff);
        }
        scanf("%d",&high2);
        for(int i = high2;i>=0;i--){
            scanf("%d",&coff);
            if (coff == 0){continue;}
            head2 = insert_at_last(head2,i,coff);
        }
        scanf("%d",&val_x);
        head3 = poly_add(head3,head1,head2);
        head4 = poly_sub(head4,head1,head2);
        printf("P1(x) : ");
        display(head1);
        printf("P2(x) : ");
        display(head2);
        printf("P3(x) = P1(x) + P2(x) : ");
        display(head3);
        printf("P4(x) = P1(x) + P2(x) : ");
        display(head4);
        printf("P1(%d) = %d\n",val_x,value(head1,val_x));
        printf("P2(%d) = %d\n",val_x,value(head2,val_x));
        printf("P3(%d) = %d\n",val_x,value(head3,val_x));
        printf("P4(%d) = %d\n",val_x,value(head4,val_x));
}
return  0;
}