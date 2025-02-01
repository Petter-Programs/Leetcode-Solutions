#define MAX_STACK 15000

typedef struct {
    int the_elements[MAX_STACK];
    int min_elements[MAX_STACK];
    int top_idx;
    int minstack_top_idx;
} MinStack;


MinStack* minStackCreate() {
    MinStack* the_stack = malloc(sizeof(MinStack));
    the_stack->top_idx = 0;
    the_stack->minstack_top_idx = 0;
    return the_stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->the_elements[obj->top_idx++] = val;
    if(obj->minstack_top_idx == 0 || obj->min_elements[obj->minstack_top_idx-1] >= val)
    {
        obj->min_elements[obj->minstack_top_idx++] = val;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->top_idx == 0)
    {
        return;
    }
    
    int element = obj->the_elements[--(obj->top_idx)];

    if(element == obj->min_elements[obj->minstack_top_idx-1])
    {
        obj->minstack_top_idx--;
    }

}

int minStackTop(MinStack* obj) {
    return obj->the_elements[(obj->top_idx)-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min_elements[(obj->minstack_top_idx)-1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/