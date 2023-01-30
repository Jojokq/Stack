#ifndef STACKFUNC
#define STACKFUNC

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
#include <assert.h>

#define STACK_EXPAND_SIZE 2

enum stack_status
{
    CONSTRUCTED,
    DESTRUCTED,
    STACK_DOESNT_EXIST,
};

enum stack_errorcode
{
    OK,
    STACK_UNDERFLOW,
    UNDEFINED_DATA,
};

typedef int stack_type; // after redo for double

typedef struct Stack 
{
    stack_type *data;
    size_t stack_size;
    size_t capacity;
    enum stack_status stack_status;
    //todo : add for-debug stack status
} stack_t;

enum stack_errorcode stackConstructor(stack_t *stack, size_t start_capacity);

void push(stack_t *stack, const stack_type elem);

stack_type pop(stack_t *stack);

enum stack_errorcode stack_realloc(stack_t *stack);

enum stack_errorcode multiassert(stack_t *stack);

enum stack_errorcode stackDestructor (stack_t *stack);

#endif

//лог файл в коммите от 11 сентября