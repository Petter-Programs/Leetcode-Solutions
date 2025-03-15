 struct Node* copyRandomList(struct Node* head) 
 {
    // interweaving approach

    if(head == NULL)
    {
        return NULL;
    }

    struct Node* list_ptr = head;

    struct Node* new_list_start = NULL;

    // First pass: interweave the lists
    while(list_ptr != NULL)
    {
        struct Node* new_elem = malloc(sizeof(struct Node));

        new_elem->val = list_ptr->val;
        new_elem->random = NULL;

        struct Node* prev_ptr = list_ptr;
        list_ptr = list_ptr->next;

        prev_ptr->next = new_elem;
        new_elem->next = list_ptr;
    }

    // Second pass: set the randoms
    list_ptr = head;

    while(list_ptr != NULL)
    {
        struct Node* orig_node = list_ptr;
        struct Node* copied_node = list_ptr->next;

        if(orig_node->random != NULL)
        {
            copied_node->random = orig_node->random->next;
        }

        list_ptr = copied_node->next;
    }

    list_ptr = head;

    // Save this information for later
    new_list_start = head->next;

    // Unweave
    while(list_ptr != NULL)
    {
        struct Node* orig_node = list_ptr;
        struct Node* copied_node = list_ptr->next;

        // Prepare for processing next original list item and restore old structure
        list_ptr = copied_node->next;
        orig_node->next = list_ptr;

        copied_node->next = copied_node->next ? copied_node->next->next : NULL;
    }

    return new_list_start;

 }