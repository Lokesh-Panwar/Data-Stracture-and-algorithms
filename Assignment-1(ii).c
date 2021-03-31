#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top = -1;
char stack[100];
int isempty(){
    if (top == -1) return 1;
}
void push(char value){
    top++;
    stack[top] = value;
}
char pop(){
    return stack[top--];
    
}
char stackTop(){
    if (top == -1)
        return '0';
    else
        return stack[top];
}//
//////////////////////////

int pref(char a){
    if(a=='+'||a=='-'){return 1;}
	else if(a=='/'||a=='*'){return 2;}
	else if(a=='^'||a=='<' || a=='>'){return 3;}
	else if(a=='('||a==')'){return 4;}
	else{return 0;}
}
void disp(char postfix[]){
    int i = 0;
    printf("Postfix expression of given infix is: \n");
    while(postfix[i]!='\0'){
        if(postfix[i]=='<' || postfix[i]=='>'){
            printf("%c",postfix[i]);    
        }
        printf("%c,",postfix[i]);
        i++;
    }
    printf("\b.\n");
}

int Evaluate(char postfix[]){
    int i = 0;
    char a,b;
    char d,c='0';
    while(postfix[i]!= '\0'){
        if(pref(postfix[i])==0){
            push(postfix[i]);
            i++;
        }
        else if(postfix[i] == '^'){
            d = pop();
            push(((d-c) * (d-c))+c);
            i++;
        }
        else{
            b = pop();
            a = pop();
            b = b-c;
            a = a-c;
            if(postfix[i]=='+')
               { push((a + b)+c);}
            else if(postfix[i]=='-')
                push((a - b)+c);
            else if(postfix[i]=='*')
                push((a * b)+c);
            else if(postfix[i]=='/')
                push((a / b)+c);
            else if(postfix[i]=='>')
                push((a >> b)+c);
            else if(postfix[i]=='<')
                push((a << b)+c);
            i++;
        }
    }
    printf("Value of postfix expression after evaluation is : %d \n",(pop()-c));
    return 0;
}
int values(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')' || c=='>' || c=='<' || c=='^'){ return 1;}
    else if(c>='0' && c<='9'){ return 2;}
    else {return 0;}
}
int is_error(char input[]){
    int openbracket = 0;
    int n=strlen(input)-1;

    if( values(input[0]) !=2 && input[0]!='('){ printf("error: wrong input");  return  0;}
    if(input[0]=='(') openbracket++;

    for(int i=1; i<n; i++){
        if( values(input[i]) ==1 ){
        if( input[i]!=')' && input[i]!='(' && input[i]!='^' && ( (values(input[i-1]) !=2 && input[i-1]!='^' &&input[i-1]!=')' && input[i-1]!='<' && input[i-1]!='>' ) || ( values(input[i+1]) != 2) && input[i+1]!='(' ) && input[i+1]!='>' && input[i+1]!='<'  ) { printf("error: wrong input");  return  0;}
            if( input[i]=='^' && values(input[i-1]) !=2 && input[i-1]!=')' ) { return  0;}
            if(input[i]=='(') openbracket++;
            if(input[i]==')') openbracket--;
            if(openbracket<0){ return 0;}
            if( input[i]=='(' && values(input[i-1]) != 1 ){return  0;}
            if( input[i]==')' &&  values(input[i+1]) != 1 && i+1<n ){return  0;}
        }
    }

    if(openbracket!=0){
        return 0;
    }

    
}

int main(){
    char infix[100],postfix[100];
    int i=0,j=0,flag = 1;
    printf("Enter Infix Expression: \n");
    scanf("%s",infix);
    flag = is_error(infix);
if (flag == 1){
    while (infix[i]!='\0'){
        if (pref(infix[i])==0){

            postfix[j] = infix[i];
            j++;
            i++;
        }
        else if(infix[i] == ')'){
            while(stackTop()!= '('){
                postfix[j] = pop();
                j++;
            }
            pop();
            i++;
        }
        else{
            while(pref(stackTop())>=pref(infix[i]) && stackTop()!='(')
            {   postfix[j] = pop();
                j++;
        
			}//while ends
            if(infix[i] == '<' || infix[i] == '>'){
                push(infix[i]);
                i = i+2;
            }
            else{
            push(infix[i]);
            i++;
            }
        }//else above while ends
    }
    while(top!=-1){
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    disp(postfix);
    Evaluate(postfix);
}
else{
    printf("Wrong Input\n");
}
return 0;
}