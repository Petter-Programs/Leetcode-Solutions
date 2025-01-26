typedef struct char_stack_struct
{
    char *char_stack;
    int empty_slot_idx;
} CharStack;

void initialize_stack(CharStack *the_stack)
{
    the_stack->empty_slot_idx = 0;
    the_stack->char_stack = malloc(sizeof(char) * 3000);
}

int get_stack_size(CharStack *the_stack)
{
    return the_stack->empty_slot_idx;
}

char pop_off_stack(CharStack *the_stack)
{
    if(the_stack->empty_slot_idx == 0)
    {
        return '\0';
    }
    the_stack->empty_slot_idx--;
    return the_stack->char_stack[the_stack->empty_slot_idx];
}

char peek_off_stack(CharStack *the_stack, int steps)
{
    if(the_stack->empty_slot_idx - steps < 0)
    {
        return '\0';
    }

    return the_stack->char_stack[the_stack->empty_slot_idx - steps];
}

void push_onto_stack(CharStack *the_stack, char the_char)
{
    the_stack->char_stack[the_stack->empty_slot_idx] = the_char;
    the_stack->empty_slot_idx++;
}

char* simplifyPath(char* path) {

    CharStack the_stack;
    initialize_stack(&the_stack);
    bool done = (*path == '\0');
    while(!done)
    {
        char current_char = *path;
        path++;
        done = (current_char == '\0');

        if(current_char != '/' && current_char != '\0')
        {
            push_onto_stack(&the_stack, current_char);
        }

        else
        {
            char previous_three[3];
            previous_three[0] = peek_off_stack(&the_stack, 1);
            previous_three[1] = peek_off_stack(&the_stack, 2);
            previous_three[2] = peek_off_stack(&the_stack, 3);

            // Multiple slashes in a row, ignore
            if(previous_three[0] == '/')
            {
                continue;
            }

            // We can add like normally now if anything other than a dot
            if(previous_three[0] != '.')
            {
                push_onto_stack(&the_stack, current_char);
                continue;
            }

            // The \a\.\ -> \a case
            if(previous_three[1] == '/')
            {
                // Remove the dot off the stack and ignore the second backslash
                pop_off_stack(&the_stack);
                continue;
            }

            // The a\b\..\ case
            if(previous_three[1] == '.' && previous_three[2] == '/')
            {
                int found_backslashes = 0;
                char current = peek_off_stack(&the_stack, 1);

                // Remove off the stack until empty or found second backslash
                while(current != '\0')
                {
                    if(current == '/')
                    {
                        found_backslashes++;

                        if(found_backslashes >= 2)
                        {
                            break;
                        }
                    }
                    pop_off_stack(&the_stack);
                    current = peek_off_stack(&the_stack, 1);
                }

                if(current == '\0')
                {
                    push_onto_stack(&the_stack, '/');
                }
                
                continue;
            }

            else
            {
                push_onto_stack(&the_stack, current_char);
                continue;
            }

        }
    }

    int size_at_end = get_stack_size(&the_stack);
    if(size_at_end == 0)
    {
        push_onto_stack(&the_stack, '/');
    }
    else if(size_at_end > 1 && peek_off_stack(&the_stack, 1) == '/')
    {
        pop_off_stack(&the_stack);
    }

    push_onto_stack(&the_stack, '\0');
    
    return the_stack.char_stack; 
}

