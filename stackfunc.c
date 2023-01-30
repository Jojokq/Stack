#include "stackfunc.h"

enum stack_errorcode stackConstructor(stack_t *stack, size_t start_capacity)
{
    // проверки на то что все ок
    stack_t *temp_stack = stack;

    //temp_stack->stack_size = 0;
    
    temp_stack->capacity = start_capacity;

    temp_stack->data = (stack_type *)calloc(start_capacity, sizeof(stack_type)); // добавить режим дебага с канарейками

    temp_stack->stack_status = CONSTRUCTED; 

    return OK;
}

void push(stack_t *stack, const stack_type elem)
{
    assert(stack);
    if (stack->stack_size >= stack->capacity)
        stack_realloc(stack);
    stack->data[stack->stack_size] = elem;
    stack->stack_size++;
}

stack_type pop(stack_t *stack)
{
    assert(stack);
    if (stack->stack_size <= 0)
        exit(STACK_UNDERFLOW);
    stack->stack_size--;
    return stack->data[stack->stack_size];
}

enum stack_errorcode stack_realloc(stack_t *stack)
{
    assert(stack);
    //проверка что стек создан, что дата не ноль и на что-нибудь ещё
    stack->data = realloc (stack->data, STACK_EXPAND_SIZE * sizeof(stack_type));
    stack->capacity = STACK_EXPAND_SIZE * stack->capacity;
    return OK;
}

enum stack_errorcode multiassert(stack_t *stack) //пусть возвращает по нормальному без этих ваших енамов
{
    assert(stack);
    if (stack->stack_size <= 0)
        return STACK_UNDERFLOW;
    if (stack->data == NULL)
        return UNDEFINED_DATA;
        
    return OK;
}

enum stack_errorcode stackDestructor (stack_t *stack)
{
    assert(stack);
    free(stack->data);

    stack->capacity = 0;
    stack->stack_size = 0;
    stack->stack_status = DESTRUCTED;

    return OK;
}