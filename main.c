#include "stackfunc.h"
#include "UIfunc.h"

int main()
{
    stack_t *my_favorite_cum_collection;

    stackConstructor(my_favorite_cum_collection, 10);
    
    push(my_favorite_cum_collection, 3);

    printStackValue(pop(my_favorite_cum_collection));

    stackDestructor(my_favorite_cum_collection);
}
