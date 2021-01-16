#include<stdio.h>
#define MAX_STACK_SIZE 100

int stack[MAX_STACK_SIZE];
int top = -1;

int IsEmpty() {
    if (top < 0)
        return true;
    else
        return false;
}
int IsFull() {
    if (top >= MAX_STACK_SIZE - 1)
        return true;
    else
        return false;
}

void push_stack(int value) {
    if (IsFull() == true)
        printf("������ ���� á���ϴ�.");
    else
        stack[++top] = value;
}

int pop_stack() {
    if (IsEmpty() == true)
        printf("������ ������ϴ�.");
    else
        return stack[top--];
}

/*
int main() {

    push_stack(3);
    push_stack(5);
    push_stack(12);
    printf("%d ", pop_stack());
    printf("%d ", pop_stack());
    printf("%d ", pop_stack());

    return 0;
}
*/