#include<stdio.h>
#include<stdlib.h>
struct AVLnode{
    int data;
    struct AVLnode *left;
    struct AVLnode *right;
    int ht; 
};
typedef struct AVLnode node;
node *root = NULL;
int height(node *temp){
    int leftSub_hgt,rightSub_hgt;
	if(temp==NULL){return -1;}
	else{
		leftSub_hgt=height(temp->left);
		rightSub_hgt=height(temp->right);
		if(leftSub_hgt>=rightSub_hgt){return leftSub_hgt+1;}
		else{return rightSub_hgt+1;}
	}
}
int Balance_Factor(node *temp){
    if(temp==NULL){
		return 0;
	}
    else
    {return height(temp->right)-height(temp->left);}
}
node *RR(node *temp){
	node *a=temp->left;
	node *b=a->right;
	a->right=temp;
	temp->left=b;
	temp->ht=height(temp);
	a->ht=height(a);
	if (root==temp){
		root = a;
	}
	return a;
}
node *LR(node *temp){
    node *a=temp->right;
	node *b=a->left;
    a->left=temp;
    temp->right=b;
    temp->ht=height(temp);
    a->ht=height(a);
	if (root==temp){
		root = a;
	}
    return a;
}
node* LRR(node *temp){
    node *a=temp->left;
	node *b=a->right;
    a->right=b->left;
    temp->left=b->right;
	b->left=a;
	b->right=temp;
	a->ht=height(a);
    temp->ht=height(temp);
    b->ht=height(b);
	if (root==temp){
		root = b;
	}
    return b;
}
node* RLR(node *temp){
    node *a=temp->right;
	node *b=a->left;
    a->left=b->right;
    temp->right=b->left;
    b->right=a;
    b->left=temp;
    a->ht=height(a);
    temp->ht=height(temp);
    b->ht=height(b);
	if (root==temp){
		root = b;
	}
        return b;
}

node* insert(int val,node *temp){
	if(temp==NULL){
		node *new;new=(node *)malloc(sizeof(node));
		new->data=val;
		new->ht=0;
        new->left=NULL;
		new->right=NULL;
		return new;
	}
	if(val < temp->data){
		temp->left=insert(val,temp->left);

	}
	else if(val > temp->data){
		temp->right=insert(val,temp->right);
	}
	temp->ht=height(temp);
	
	//balancing
	if(Balance_Factor(temp)<-1 && val<(temp->left->data)){
		return RR(temp);
	}
	else if(Balance_Factor(temp)>1 && val>(temp->right->data)){
                return LR(temp);
    }
	else if(Balance_Factor(temp)<-1 && val> (temp->left->data)){
                return LRR(temp);
    }
	else if(Balance_Factor(temp)>1 && val< temp->right->data){
                return RLR(temp);
    }
	return temp;
}
node* delete(int val,node* Root){
	node* temp;
	if(Root==NULL){
		return NULL;
	}else if(val<Root->data){
		Root->left=delete(val,Root->left);
	}else if(val>Root->data){
                Root->right=delete(val,Root->right);
	}else if(val==Root->data){
		if(Root->left==NULL && Root->right==NULL){
			free(Root);
			return NULL;
		}else if(Root->left==NULL && Root->right!=NULL){
			temp=Root->right;
			free(root);
			return temp;
		}else if(Root->right==NULL&& Root->left!=NULL){
			temp=Root->left;
            free(Root);
			return temp;
		}else if(Root->left!=NULL && Root->right!=NULL){
			temp=Root->right;
			while(temp->left!=NULL){temp=temp->left;}
			Root->data=temp->data;
			Root->right=delete(temp->data,Root->right);
		}
	}
	Root->ht=height(Root);
        if(Balance_Factor(Root)<-1 && val<Root->left->data){
                return RR(Root);
        }else if(Balance_Factor(Root)>1 && val>Root->right->data){
                return LR(Root);
        }else if(Balance_Factor(Root)<-1 && val>Root->left->data){
                return LRR(Root);
        }else if(Balance_Factor(Root)>1 && val<Root->right->data){
                return RLR(Root);
        }
        return Root;

}
node* inorder(node* Root){
	if(Root==NULL){return NULL;}
	else{
		inorder(Root->left);
		printf("(%d,%d,%d),",Root->data,Root->ht,Balance_Factor(Root));
		inorder(Root->right);
	}
}
int main(){
	int a,n,val;
	int flip=1;
	printf("//Enter any number other than 1,2,3,4 to exit from the program\n");
	while(flip){
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				scanf("%d",&val);
				root=insert(val,root);
			}
		}
		if(a==2){
			scanf("%d",&val);
			root=insert(val,root);
		}
		if(a==3){
			scanf("%d",&val);
			root=delete(val,root);
		}
		if(a==4){
			inorder(root);
			printf("\b");
			printf(".\n");
		}if(a>4 || a<1){flip=0;}
	}
	return 0;
}