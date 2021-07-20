#include<stdio.h>
#include<stdlib.h>
//make node
struct node{
    int value;
    struct node* right;
    struct node* left;
};
typedef struct node node;
int no_node=0,top=-1;   // take number of node as global variable, top is for stack
// function to insert element in a node(recursively)
node* insert(node* root,int val){
    if (root==NULL){
        node* new = (node*)malloc(sizeof(node));
        new->value = val;
        new->right = NULL;
        new->left = NULL;
        root = new;
        return root;
    }   
    else if(val > (root->value)){
        root->right = insert(root->right,val);
    }
    else if(val < (root->value)){
        root->left = insert(root->left,val);
    }
    return root;
    }
// function to search a a node with value val in BST
node* search(node *root,int val){
    if (root==NULL){
        printf("error");
        return NULL;
    }

    if (val == root->value){
        return root;
    }
    else if(val > (root->value)){
        return search(root->right,val);
    }
    else if(val < (root->value)){
        return search(root->left,val);
    }
}
// function to find minimum value node in BST. i.e. left most
node* min(node* root){
    while (root->left!=NULL){
        root = root->left;
    }
    return root;
}
// function to find parent of a node
node* find_parent(node* root,node* child){
    if((child == root->right || child == root->left )){
        return root;
    }
    else if((child->value) > (root->value)){
        return find_parent(root->right,child);
    }
    else if((child->value) < (root->value)){
        return find_parent(root,root->left);
    }
}
// function to find successor of a node
node* find_successor(node* root,node* succ){
    if(succ->right!=NULL){ // if right tree exist
        return min(succ->right);
    }
    else if(succ->right==NULL){
        node* parent = find_parent(root,succ);
        if (parent->left == succ){
            return parent;
        }
        else{
            while (parent!=NULL & succ==parent->right){
                succ = parent;
                parent = find_parent(root,parent);
            }
            return parent;
        }
    }
}
//function to count number of leaves
int leaves_count(node* temp){ 
	if(temp==NULL){return 0;}
	else if(temp->left==NULL && temp->right==NULL){return 1;}
	else{return leaves_count(temp->left)+leaves_count(temp->right);}
} 
// function to find height of tree
int height(node* temp){
	int leftSub_height,rightSub_height;
	if(temp==NULL){return -1;}
	else{
		leftSub_height=height(temp->left);
		rightSub_height=height(temp->right);
		if(leftSub_height>=rightSub_height){return leftSub_height+1;}
		else{return rightSub_height+1;}
	}
}
// function to delete node (itertively)
void delete(node* root,int val){
    node* del,*parent;
    del = search(root,val);
    if(root == NULL){printf("error");}
    parent = find_parent(root,del);
    if (del->right == NULL & del->left==NULL){
        if (parent->right==del){
            parent->right = NULL;
            free(del);
        }
        else{
            parent->left = NULL;
            free(del);
        }
    }
    else if(del->right == NULL){
        if(parent->right == del){
            parent->right = del->left;
            free(del);
        }
        else if(parent->left == del){
            parent->left = del->left;
            free(del);
        }
    }
    else if(del->left==NULL){
        if(parent->right == del){
            parent->right = del->right;
            free(del);
        }
        else if(parent->left == del){
            parent->left = del->right;
            free(del);
        }
    }
    else if(del->left!=NULL & del->right!=NULL){
        node* succ = find_successor(root, del);
        node* temp = find_parent(root,succ);
        if (succ->right==NULL){
            del->value = succ->value;
            if (temp->right == succ){
                temp->right = succ->left;
                free(succ);
            }
            else{
                temp->left = succ->left;
                free(succ);
            }
        }
        else{
            del->value = succ->value;
            temp = succ->right;
            succ->value = temp->value;
            succ->right = temp->right;
            free(temp);
        }
    }
    return;
}
// defining stack
void push(node *v,node arr[]){
	top++;
	arr[top]=*v;
}
node* pop(node arr[]){
	return &arr[top--]; 
}
node* stackTop(node arr[]){
	return &arr[top];
}
//inorder traversal
void inorder(node* root){
    node *temp=root,*ar;int f=1;
	ar=(node *)malloc(no_node * sizeof(node));
	if(temp==NULL){printf("\n");return;}
	while(f==1){
		if(temp!=NULL){
			push(temp,ar);
			temp=temp->left;
		}else if(temp==NULL && top!=-1){
			temp=pop(ar);
			printf("%d ",temp->value);
			temp=temp->right;
		}else if(temp==NULL && top==-1){
			printf("\n\n");
			f=0;
		}
	}
}
// pre order traversal
void preorder(node* root){
	node *temp=root,*ar;int f=1;
        ar=(node *)malloc(no_node * sizeof(node));
	if(temp==NULL){printf("\n");return;}
        while(f==1){
                if(temp!=NULL){
			printf("%d ",temp->value);
                        push(temp,ar);
                        temp=temp->left;
                }else if (temp==NULL && top!=-1){
                        temp=pop(ar);
                        temp=temp->right;
                }else if(temp==NULL && top==-1){
                        printf("\n\n");
                        f=0;
                }
        }
}
// post order traversal
void postorder(node* root){
	node *temp=root,*temp1=NULL,*ar;
	ar=(node *)malloc(no_node*sizeof(node));
	if(temp==NULL){printf("\n");return;}
	do{
		while(temp!=NULL){
			if(temp->right!=NULL){
				push(temp->right,ar);
			}
			push(temp,ar);
			temp=temp->left;
		}
		temp=pop(ar);
		if(temp->right!=NULL && temp->right->value==stackTop(ar)->value){
			pop(ar);
			push(temp,ar);
			temp=temp->right;
		}else{printf("%d ",temp->value);temp=NULL;}
	}while(top!=-1);
	printf("\n\n");
}
int main(){
    int i=0,j,val,k,leave_node,internal_node,ht;
    node* root=NULL;
	while (i>=0 & i<8){
		printf("Menu=>\n1:Insert element to BST\n2:Delete element from BST\n3:Display tree's info\n4:In-order traversal\n5:Pre-order traversal\n6:Post-order traversal\n7:Exit\n");
		printf("Enter your choice :");
		scanf("%d",&i);
		if(i==1){
			printf("Enter the no.of nodes followed by the sequence :");
			scanf("%d",&k);
			no_node=no_node+k;
			for(int j=0;j<k;j++){
				scanf("%d",&val);
				root = insert(root,val);
			}
			printf("\n");		
		}
		else if(i==2){
			printf("Enter the value of the node to be deleted:");
			scanf("%d",&val);
			delete(root,val);
			printf("\n");
		}
		else if(i==3){
			leave_node=leaves_count(root);
			printf("no.of leaves=%d\n",leave_node);
			internal_node=no_node-leave_node;
            printf("no.of internal nodes=%d\n",internal_node);
			ht=height(root);
			printf("Height=%d\n",ht);
			printf("\n");	
		}
		else if(i==4){inorder(root);}
		else if(i==5){preorder(root);}
		else if(i==6){postorder(root);}
        else if(i==7){break;}
        else{printf("invalid input\n\n");i=0;}    
    }
	return 0;
}
