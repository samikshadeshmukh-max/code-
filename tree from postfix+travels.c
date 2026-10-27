#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

struct Node {
    char data;
    struct Node *left, *right;
};

struct Node *stack[MAX];
int top = -1;

struct Node *newNode(char c) {
    struct Node *n = malloc(sizeof(struct Node));
    n->data = c;
    n->left = n->right = NULL;
    return n;
}

void inorder(struct Node *r) {
    if (r) {
        inorder(r->left);
        printf("%c ", r->data);
        inorder(r->right);
    }
}

void preorder(struct Node *r) {
    if (r) {
        printf("%c ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct Node *r) {
    if (r) {
        postorder(r->left);
        postorder(r->right);
        printf("%c ", r->data);
    }
}

int main() {
    char s[MAX];
    struct Node *a, *b, *n, *root;

    printf("Enter postfix expression: ");
    scanf("%99s", s);

    for (int i = 0; s[i]; i++) {
        n = newNode(s[i]);

        if (isalnum((unsigned char)s[i]))
            stack[++top] = n;
        else {
            if (top < 1) {
                printf("Invalid expression\n");
                return 1;
            }
            b = stack[top--];
            a = stack[top--];
            n->left = a;
            n->right = b;
            stack[++top] = n;
        }
    }

    if (top != 0) {
        printf("Invalid expression\n");
        return 1;
    }

    root = stack[top];

    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
