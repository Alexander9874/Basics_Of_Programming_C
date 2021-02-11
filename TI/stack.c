#include <stdlib.h>
#include <stdio.h>

typedef struct Item {
    int data;
    struct Item *next;
} Item;

typedef struct Stack {
    Item *head;
} Stack;

Stack *stack_new() {
    return (Stack *) calloc(1, sizeof(Stack));
}

void stack_delete(Stack *stack) {
    Item *ptr = stack->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(stack);
}

int stack_push(Stack *stack, int data) {
    Item *new = (Item *) malloc(sizeof(Item));
    if (!new) {
        return -1;
    }
    new->data = data;
    new->next = stack->head;
    stack->head = new;
    return 0;
}

int stack_pop(Stack *stack, int *output) {
    if (!stack->head) {
        return -1;
    }
    *output = stack->head->data;
    Item *head = stack->head;
    stack->head = head->next;
    free(head);
    return 0;
}

void stack_print(const Stack *stack) {
    Item *ptr = stack->head;
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    Stack *s = stack_new();
    for (int i = 1; i <= 10; ++i) {
        stack_push(s, i);
        stack_print(s);
    }
    int res, data;
    while ((res = stack_pop(s, &data)) != -1) {
        printf("(%d) ", data);
        stack_print(s);
    }
    stack_delete(s);
    return 0;
}
