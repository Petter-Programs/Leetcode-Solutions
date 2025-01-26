#define MAX_STACK 10000

typedef struct C_stack_struct
{
    char stack_arr[MAX_STACK];
    int stack_top;
} Stack;

void init_stack(Stack *the_stack)
{
    the_stack->stack_top = 0;
}

bool push_onto_stack(Stack *the_stack, char item)
{
    if(the_stack->stack_top >= MAX_STACK)
    {
        return false;
    }

    the_stack->stack_arr[the_stack->stack_top++] = item;

    return true;
}

char pop_off_stack(Stack *the_stack)
{
    if(the_stack->stack_top == 0)
    {
        return 'I';
    }

    return the_stack->stack_arr[--the_stack->stack_top];
}

char get_valid_match(char initial)
{
    if(initial == '(')
    {
        return ')';
    }
    else if(initial == '[')
    {
        return ']';
    }
    else if(initial == '{')
    {
        return '}';
    }

    return 'N';
}

bool isValid(char* s) 
{
    Stack the_stack;
    init_stack(&the_stack);

    while(*s != '\0')
    {
        if(*s == '(' || *s == '[' || *s == '{')
        {
            push_onto_stack(&the_stack, *s);
        }
        else
        {
            char returned = pop_off_stack(&the_stack);

            if(get_valid_match(returned) != *s)
            {
                return false;
            }
        }

        *s++;
    }

    return the_stack.stack_top == 0;
}