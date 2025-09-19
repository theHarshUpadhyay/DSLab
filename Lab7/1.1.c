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

int isPalindrome(char c[]){
    int flag = 1;
    for(int i=0;c[i] != '\0';i++){
        push(tolower(c[i]));
    }
    for(int i=0;c[i] != '\0';i++){
        if(tolower(c[i]) != pop()){
            flag = 0;
        }
    }
    return flag;
}

void main(){
    printf("Enter String: ");
    char str[100];
    scanf("%s",str);
    if(isPalindrome(str)){
        printf("String is Palindrome!");
    }
    else printf("String is not Palindrome");
}
