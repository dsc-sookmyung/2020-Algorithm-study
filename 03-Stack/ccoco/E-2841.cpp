#include <stdio.h>
#include <stdlib.h>

typedef struct stack_type {
    int item[500000];
    int top;
} Stack_type;

typedef Stack_type* Stack;

void push(Stack s, int item) {
    s->item[++(s->top)] = item;
}

int pop(Stack s) {
    if (s->top == -1)
        return -1;
    return s->item[s->top--];
}

int peek(Stack s) {
    if (s->top == -1)
        return -1;
    return s->item[s->top];
}
void solution() {
    Stack s[6];
    for (int i = 0; i < 6; i++) {
        s[i] = (Stack)malloc(sizeof(Stack_type));
        s[i]->top = -1;
    }
    int n, p;
    int count = 0;
    scanf("%d %d", &n, &p);
    
    for (int i = 0; i < n; i++) {
        int line, fret;
        scanf("%d %d", &line, &fret);
        while (peek(s[line-1]) > fret && s[line-1]->top != -1) {
            pop(s[line-1]);
            count++;
        }
        if (peek(s[line-1]) == fret)
            continue;
        if (peek(s[line-1]) < fret) {
            push(s[line-1], fret);
            count++;
        }
    }
    printf("%d\n", count);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    solution();
    return 0;
}