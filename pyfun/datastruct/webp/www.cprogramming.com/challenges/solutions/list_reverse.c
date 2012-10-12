struct node 
{
    int val;
    struct node* next;
};

struct node* reverse (struct node* list)
{
    /* initialization */
    struct node *reversed_list_head = 0;
    struct node *rest_orig_list = list;

    /* build up the reversed_list like a stack while the original list
       remains */
    while ( rest_orig_list != 0 )
    {
        struct node *orig_list_tail = rest_orig_list->next;
        /* the head of the remainder of the original list will be the
           new head of the new list */
        rest_orig_list->next = reversed_list_head;
        reversed_list_head = rest_orig_list;
        rest_orig_list = orig_list_tail;
    }

    return reversed_list_head;
}
