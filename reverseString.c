#include<stdio.h>
#include<string.h>
#define max 100
#include<stdbool.h>

int stack[max];
int top = -1;

bool isEmpty(){
    return top == -1;
}

bool isFull(){
    return top == max - 1;
}

void push(char ch){
    if (isFull())
    {
        printf("Overflow");
    }
    else{
        top++;
        stack[top] = ch;
    }
}

void pop(){
    if(isEmpty()){
        printf("Underflow");
    }
    else{
        printf("%c", stack[top]);
        top--;
    }
}

void main(){
    char str[] = "Aarav Halvadiya";
    int len = strlen(str);

    for(int i=0;i<len;i++){
        push(str[i]);
    }

    for(int i=0;i<len;i++){
        pop();
    }
}