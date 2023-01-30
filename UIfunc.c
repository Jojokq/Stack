#include "UIfunc.h"

int printStackValue(const stack_type elem)
{
    return printf("%d", elem);
}

int printStack(stack_t *stack)
{
    assert(stack);
    for (size_t i = 0; i < stack->stack_size; i++)
    {
        printf("%d\n", stack->data[i]);
    }
    printf("\n");
    return 0;
}