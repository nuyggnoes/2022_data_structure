#ifndef STACKADT_H_
#define STACKADT_H_
#include <stdbool.h>

typedef char *Item;
typedef struct stack_type *Stack;
Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);
void list(Stack s);

#endif