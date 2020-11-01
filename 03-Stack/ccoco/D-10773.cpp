#include <stdio.h>

int stack[100000];
int top = -1;
int sum = 0;

void push(int item) {
    stack[++top] = item;
    sum += stack[top];
}

int pop() {
    sum -= stack[top];
    return stack[top--];
}

int main(int argc, const char * argv[]) {
    int c; scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 0) {
            pop();
        } else {
            push(cmd);
        }
    }
    printf("%d", sum);
    return 0;
}
