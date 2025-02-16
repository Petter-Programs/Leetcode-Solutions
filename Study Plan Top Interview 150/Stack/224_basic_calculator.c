// Test cases worked for me with only 100000, but technically this is the safe number
#define MAX_ELEMENTS 600000

typedef struct IntStack_t
{
    int the_stack[MAX_ELEMENTS];
    int stack_top;
} IntStack;

void init_stack(IntStack *stack_obj)
{
    stack_obj->stack_top = 0;
}

void push_onto_stack(IntStack *stack_obj, int item)
{
    stack_obj->the_stack[stack_obj->stack_top++] = item;
}

void increment_stack_top(IntStack *stack_obj, int item)
{
    if(stack_obj->stack_top-1 < 0)
    {
        printf("Stack not big enough to increment top?\n");
        return;
    }
    stack_obj->the_stack[stack_obj->stack_top-1] += item;
}

int pop_from_stack(IntStack *stack_obj)
{
    if(stack_obj->stack_top == 0)
        return INT_MIN;
    
    return stack_obj->the_stack[--stack_obj->stack_top];
}

int stack_size(IntStack *stack_obj)
{
    return stack_obj->stack_top;
}

bool is_numerical(char element)
{
    return element >= '0' && element <= '9';
}

bool should_add(IntStack *stack_obj)
{
    if(stack_obj->stack_top-2 < 0)
    {
        printf("Stack did not contain enough elements\n");
        return false;
    }
    return stack_obj->the_stack[stack_obj->stack_top-2] == 1;
}

void set_sign(IntStack *stack_obj, bool positive)
{
    if(stack_obj->stack_top-2 < 0)
    {
        printf("Stack did not contain enough elements\n");
        return;
    }
    stack_obj->the_stack[stack_obj->stack_top-2] = (positive ? 1 : -1);
}


int calculate(char* s) {

IntStack the_stack;
init_stack(&the_stack);

    while(*s != '\0')
    {
        if(*s == '(' || stack_size(&the_stack)==0)
        {
            push_onto_stack(&the_stack, 1); // The sign, positive to start with
            push_onto_stack(&the_stack, 0); // Actual value
        }

        if(is_numerical(*s))
        {
            int as_integer = atoi(s);

            while(is_numerical(*s))
            {
                s++;
            }

            if(!should_add(&the_stack))
                as_integer = -as_integer;

            increment_stack_top(&the_stack, as_integer);

            continue;
        }

        if(*s == ')' && stack_size(&the_stack)>2)
        {
            int popped = pop_from_stack(&the_stack);
            pop_from_stack(&the_stack); //sign, ignore

            if(!should_add(&the_stack))
                popped = -popped;
            
            increment_stack_top(&the_stack, popped);
        }

        if(*s == '+')
        {
            set_sign(&the_stack, true);
        }
        else if(*s == '-')
        {
            set_sign(&the_stack, false);
        }

        s++;
    }


    return the_stack.the_stack[the_stack.stack_top-1];

}
