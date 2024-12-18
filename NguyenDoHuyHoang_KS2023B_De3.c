#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* topNode;
    int stackSize;
} Stack;

void initializeStack(Stack* stack) {
    stack->topNode = NULL;
    stack->stackSize = 0;
}

void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = stack->topNode;
    stack->topNode = newNode;
    stack->stackSize++;
}

int isEmpty(Stack* stack) {
    return stack->topNode == NULL;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ngan xep rong\n");
        return -1;
    }
    int poppedValue = stack->topNode->data;
    Node* temp = stack->topNode;
    stack->topNode = stack->topNode->next;
    free(temp);
    stack->stackSize--;
    return poppedValue;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ngan xep rong\n");
        return -1;
    }
    return stack->topNode->data;
}

int size(Stack* stack) {
    return stack->stackSize;
}

void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ngan xep rong\n");
        return;
    }
    Node* current = stack->topNode;
    printf("phan tu cua ngan xep: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL");
    printf("\n");
}

void clear(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

void displayReverse(Node* node) {
    if (node == NULL) {
        return;
    }
    displayReverse(node->next);
    printf("%d <- ", node->data);
}

void reverse(Stack* stack) {
    if (isEmpty(stack)) {
        printf("ngan xep rong!\n");
        return;
    }
    printf("danh sach dao nguoc: ");
    displayReverse(stack->topNode);
}

int main() {
    Stack stack;
    initializeStack(&stack);
    int choice, value;
    do {
        printf("\n==================MENU=================\n");
        printf("1. them phan tu vao ngan xep (push)\n");
        printf("2. lay phan tu dau tien ra khoi ngan xep (pop)\n");
        printf("3. kiem tra phan tu tren cung cua ngan xep (peek/top)\n");
        printf("4. kiem tra ngan xep co rong khong (isEmpty)\n");
        printf("5. lay kich thuoc cua ngan xep (size)\n");
        printf("6. in toan bo ngan xep (display)\n");
        printf("7. xoa toan bo ngan xep (clear)\n");
        printf("8. in nguoc ngan xep (reverse)\n");
        printf("0. thoat\n");
        printf("=========================================\n");
        printf("nhap lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("nhap phan tu muon them: ");
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            if (pop(&stack) == -1){
                break;
            } else {
                printf("phan tu duoc lay ra: %d\n", pop(&stack));
            }
            break;
        case 3:
            if (peek(&stack) == -1){
                break;
            } else {
                printf("phan tu tren cung la: %d\n", peek(&stack));
            }
            break;
        case 4:
            printf("%s\n", isEmpty(&stack) ? "ngan xep rong" : "ngan xep khong rong");
            break;
        case 5:
            printf("kich thuoc ngan xep: %d\n", size(&stack));
            break;
        case 6:
            display(&stack);
            break;
        case 7:
            clear(&stack);
            printf("ngan xep da duoc xoa!\n");
            break;
        case 8:
            reverse(&stack);
            printf("NULL");
            printf("\n");
            break;
        case 9:
            printf("thoat chuong trinh\n");
            break;
        default:
            printf("vui long lua chon lai\n");
            break;
        }
    } while (choice != 0);
}
