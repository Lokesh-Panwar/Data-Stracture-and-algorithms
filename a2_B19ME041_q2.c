#include <stdio.h>  
#include <stdlib.h>
struct AVLTREE{
    int data;
    int height;
    struct AVLTREE* left;
    struct AVLTREE* right;
};
typedef struct AVLTREE node;

node* root = NULL;
int height(node* temp){
	int leftSub_hgt, rightSub_hgt, z;
	if(temp == NULL){
		return 0;
	}else{
		leftSub_hgt = height(temp->left);
		rightSub_hgt = height(temp->right);
		z = leftSub_hgt >= rightSub_hgt ? leftSub_hgt : rightSub_hgt;
		return 1+z;
	}
}
int Balance_Factor(node* temp){
    if (temp ==NULL){
        return 0;
    }
    else{
    return (height(temp->left) - height(temp->right));
    }
}
node* LR(node *temp) {
    node* a = temp->left;
    node* b = a->right;
 
    a->right = temp;
    temp->left = b;
   // Update height
    temp->height = height(temp);
    a->height = height(a);
    // Update root
    if (root == temp){
        root = a;
    }
    return a;
}
 
node* RR(node *temp) {
    node* a = temp->right;
    node* b = a->left;
    a->left = temp;
    temp->right = b;
    // Update height
    temp->height = height(temp);
    a->height = height(a); 
    // Update root
    if(root == temp){
        root = a;
    }
    return a;
}
node* LRR(node *temp) {
    node* a = temp->left;
    node* b = a->right;
    a->right = b->left;
    temp->left = b->right;
    b->left = a;
    b->right = temp;
    // Update height
    a->height = height(a);
    temp->height = height(temp);
    b->height = height(b);
    // Update root
    if (temp == root){
        root = b;
    }
    return b;
}
node* RLR(node *temp) {
    node* a = temp->right;
    node* b = a->left;
    a->left = b->right;
    temp->right = b->left;
    b->right = a;
    b->left = temp;
    // Update height
    a->height = height(a);
    temp->height = height(temp);
    b->height = height(b);
    // Update root
    if (root == temp){
        root = b;
    }
    return b;
}
//----------------------------------------------------------
node* insert(node *temp, int val){
    if (temp == NULL){
        node* ptr;
        ptr = (node*)malloc(sizeof(node));
        ptr->data = val;
        ptr->left = NULL;
        ptr->height = 1;
        ptr->right = NULL;
        return ptr;
    }
 
    if (val < temp->data){
        temp->left = insert(temp->left,val);
    }else if (val > temp->data){
        temp->right = insert(temp->right,val);
    }
    temp->height = height(temp);
    // Balance Factor and Rotation
    if (Balance_Factor(temp) == 2 && Balance_Factor(temp->left) == 1) {
        return LR(temp);
    } else if (Balance_Factor(temp) == 2 && Balance_Factor(temp->left) == -1){
        return LRR(temp);
    } else if (Balance_Factor(temp) == -2 && Balance_Factor(temp->right) == -1){
        return RR(temp);
    } else if (Balance_Factor(temp) == -2 && Balance_Factor(temp->right) == 1){
        return RLR(temp);
    }
    return temp;
}
//------------------------------------------------------------------
int wdth(node* temp){
    if (temp == NULL)
        return 0;
    int left_height = height(temp->left);
    int right_height = height(temp->right);
    int a = 1+left_height+right_height;
    int w1 = wdth(temp->left);
    int w2 = wdth(temp->right);
    int b = w1 > w2 ? w1 : w2;
    int c = a > b ? a : b;
    return c;
}
void leaves(node* temp){ 
    if (temp == NULL) 
        return; 
    leaves(temp->right); 
    if ((temp->right) == NULL && (temp->left) == NULL) 
        printf("%d ",temp->data); 
    leaves(temp->left); 
}
// print all left boundary nodes,
void left_boundary(node* temp){ 
    if (temp == NULL) 
        return; 
    if (temp->left != NULL){ 
        left_boundary(temp->left);
        printf("%d ",temp->data); 
    } 
    else if(temp->right != NULL){         
        left_boundary(temp->right);
        printf("%d ",temp->data); 
    }
}  
//print all right boundary nodes
void right_boundary(node* temp){ 
    if (temp == NULL) 
        return;
    if (temp->right != NULL){
        printf("%d ",temp->data);
        right_boundary(temp->right); 
         
    } 
    else if(temp->left != NULL){ 
        printf("%d ",temp->data);
        right_boundary(temp->left); 
         
    } 
}
//boundary traversal
void perimeter(node* temp){
    if (temp == NULL) 
        return; 
    printf("%d ",temp->data); 
    right_boundary(temp->right);   
    leaves(temp->right); 
    leaves(temp->left); 
    left_boundary(temp->left); 
} 
//-------------------------------------------------------------------------------------
node* c_ancestor(node* temp,int a,int b){
    if(temp==NULL){
        return NULL;
    }
    if(temp->data > a && temp->data > b){
        return c_ancestor(temp->left,a,b);
    }
    else if(temp->data < a && temp->data < b){
        return c_ancestor(temp->right,a,b);
    }
    return temp;
}
//---------------------------------------------------------------------------------
node* node_search(node* temp,int a){
    if(temp == NULL){
        return NULL;
    }
    if(a == temp->data){
        return temp;
    }
    if(temp->data > a){
        temp->left  = node_search(temp->left,a);
    }
    else if(temp->data < a){
        temp->right = node_search(temp->right,a);
    }
}
void inter_mediate(node* temp, int a, int b){
    if (b==temp->data){
        return ;
    }    
    if (b > temp->data)
    {   
        if(temp->right->data !=b)
            printf("%d ", temp->right->data);
        inter_mediate(temp->right, temp->right->data, b);
    }
    else if (b < temp->data)
    {   if(temp->left->data !=b)
            printf("%d ", temp->left->data);
        inter_mediate(temp->left, temp->left->data, b);
    }
    //else if(b == temp->data){
     //   printf("%d", temp->data);
    //}
}
node* precedence(node* p) {
    while (p && p->right != NULL){
        p = p->right;
    }
    return p;
}
node* succ(node* p) {
    while (p && p->left != NULL){
        p = p->left;
    }
    return p;
}
node* delete(node *temp, int val) {
    if (temp == NULL){
        return NULL;
    }
    if (temp->left == NULL && temp->right == NULL){
        if (temp == root){
            root = NULL;
        }
        free(temp);
        return NULL;
    }
    if(val < temp->data){
        if(temp->left != NULL){
            temp->left = delete(temp->left, val);
        }else{
            return NULL;
        }
    }else if(val > temp->data){
        if(temp->right != NULL){
            temp->right = delete(temp->right, val);
        }else{
            return NULL;
        }
    }else{
        node* q;
        if (height(temp->left) > height(temp->right)){
            q = precedence(temp->left);
            temp->data = q->data;
            temp->left = delete(temp->left, q->data);
        } else {
            q = succ(temp->right);
            temp->data = q->data;
            temp->right = delete(temp->right,q->data);
        }
    }
    // Update height
    temp->height = height(temp);
    // Balance Factor and Rotation
    if (Balance_Factor(temp) == 2 && Balance_Factor(temp->left) == 1){
        return LR(temp);
    } else if (Balance_Factor(temp) == 2 && Balance_Factor(temp->left) == -1){
        return LRR(temp);
    } else if (Balance_Factor(temp) == -2 && Balance_Factor(temp->right) == -1){
        return RR(temp);
    } else if (Balance_Factor(temp) == -2 && Balance_Factor(temp->right) == 1){
        return RLR(temp);
    } else if (Balance_Factor(temp) == 2 && Balance_Factor(temp->left) == 0){
        return LR(temp);
    } else if (Balance_Factor(temp) == -2 && Balance_Factor(temp->right) == 0){
        return RR(temp);
    }
    return temp;
}
void inorder(node* temp){
    if (temp == NULL)
        return;
    inorder(temp->left); 
    printf("(%d,%d,%d),",temp->data,temp->height-1,-(Balance_Factor(temp)));
    inorder(temp->right);
}   
int main(){
    printf("Enter the instruction:\n");
    int option;
    do{	
		scanf("%d",&option);
        node* temp1 = root;
        node* temp2 = root;
        node* ptr = root;
        int n,m,a,b,width;
		switch(option){
			case 0:
				break;
			case 1:
				scanf("%d",&n);
                for(int i = 0; i < n; i++){
                    scanf("%d",&m);
                    root = insert(root,m);
                }
				break;
			case 2:
				scanf("%d",&m);
                insert(root,m);
				break;
			case 3:
				scanf("%d",&m);
                delete(root,m);
				break;
			case 4:
                inorder(root);
                printf("\b");
                printf("\n");
				break;
            case 5:
				width = wdth(root);
                printf("Width = %d\n",width);
                printf("Perimeter = ");
                perimeter(root);
                printf("\n");
				break;
			case 6:
                scanf("%d",&a);
                scanf("%d",&b);
				temp1 = c_ancestor(temp1,a,b);
				printf("%d\n",temp1->data);
                break;
            case 7:
                scanf("%d",&a);
                scanf("%d",&b);
                temp2 = c_ancestor(temp2,a,b);
                if(temp2->data != a){
                    printf("%d\n",-1);
                    break;
                }
                inter_mediate(temp2,a,b);
                printf("\n");
                break; 
			default:
				printf("Wrong input option\n");
		}
	}
	while (option != 0);
    return 0;
}