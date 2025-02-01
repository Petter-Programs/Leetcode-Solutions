#define MAX_STACK 10001

typedef struct stack_struct{
    int stack_items[MAX_STACK];
    int stack_top;
    int malloced_count;
} Stack;

void init_stack(Stack *the_stack)
{
    the_stack->stack_top = 0;
}

int pop_from_stack(Stack *the_stack)
{
    return the_stack->stack_items[--(the_stack->stack_top)];
}

void push_onto_stack(Stack *the_stack, int the_number)
{
    the_stack->stack_items[the_stack->stack_top++] = the_number;
}

bool is_addition(char *the_string)
{
    return strcmp(the_string, "+") == 0;
}

bool is_subtraction(char *the_string)
{
    return strcmp(the_string, "-") == 0;
}

bool is_multiplication(char *the_string)
{
    return strcmp(the_string, "*") == 0;
}

bool is_division(char *the_string)
{
    return strcmp(the_string, "/") == 0;
}

bool is_operator(char *the_string)
{
    return is_addition(the_string) || is_subtraction(the_string)
    || is_multiplication(the_string) || is_division(the_string);
}

int evalRPN(char** tokens, int tokensSize) 
{
    Stack the_stack;

    init_stack(&the_stack);

    // so basically
    // whenever encountering an operand
    // it applies to the top two elements of the stack
    // and the result will replace them on the stack

    for(int i = 0; i<tokensSize; i++)
    {
        char* current = tokens[i];

        if(!is_operator(current))
        {
            int current_as_int = atoi(current);
            push_onto_stack(&the_stack, current_as_int);
        }
        else
        {
            int number_two = pop_from_stack(&the_stack);
            int number_one = pop_from_stack(&the_stack);

            int result = INT_MIN;

            if(is_addition(current))
            {
                result = number_one+number_two;
            }

            else if(is_subtraction(current))
            {
                result = number_one-number_two;
            }

            else if(is_division(current))
            {
                result = number_one/number_two;
            }

            else if(is_multiplication(current))
            {
                result = number_one*number_two;
            }

            push_onto_stack(&the_stack, result);
        }
    }


    return pop_from_stack(&the_stack);
}