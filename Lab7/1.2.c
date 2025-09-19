#include<stdio.h>

#define MAX_SIZE 10000000
char stk[MAX_SIZE];
int top = -1;

char push(char c){
    if(top < MAX_SIZE){
        top++;
        stk[top] = c;
    }
    else {
        printf("STACK OVERFLOW!!!");
    }
}

char pop(){
    if(top>=0){
        return stk[top--];
    }
    else {
        printf("STACK UNDERFLOW!!!\n");
        return -1;
    }
}

int peek(){
    return stk[top];
}

int isBalanced(char c[]){
    int flag = 1;
    for(int i=0;c[i] != '\0';i++){
        if(c[i] == '(' || c[i] == '{' || c[i] == '[')
            push(c[i]);
        else{
            switch(c[i]){
                case (')'):
                    if(pop() != '('){
                        flag = 0;
                    }
                    break;
                case ('}'):
                    if(pop() != '{'){
                        flag = 0;
                    }
                    break;
                case (']'):
                    if(pop() != '['){
                        flag = 0;
                    }
                    break;
            }
        }
    }
    return flag;
}

void main(){
    printf("Enter String: ");
    char str[100];
    scanf("%s",str);
    if(isBalanced(str)){
        printf("Parantheses are balanced.");
    }
    else printf("Paranthese are not balanced.");
}
