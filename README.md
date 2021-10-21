# New_pushswap

https://sketchboard.me/FCT9dMd4OaPN#/

void show_stack_state(t_list *stack_a, t_list *stack_b)
{
    int i;

    move_top_list(&stack_a);
    move_top_list(&stack_b);
    if (stack_b != NULL)
    {
        i = (stack_size(stack_a) > stack_size(stack_b));
        if ( i == 1)
            i = stack_size(stack_a);
        else
            i = stack_size(stack_b);
    }
    else
        i = stack_size(stack_a);
    while (i > 0)
    {
        if (stack_a != NULL && stack_b != NULL)
            dprintf(2,"%d\t%d\n",stack_a->order,stack_b->order);
        else if (stack_a == NULL && stack_b)
            dprintf(2,"R\t%d\n", stack_b->order);
        else
            dprintf(2,"%d\tR\n",stack_a->order);
        if (stack_a != NULL)
        stack_a = stack_a->next;
        if (stack_b != NULL)
        stack_b = stack_b->next;
        i--;
    }
}


void show_node_info(t_list *node)
{
    dprintf(2,"Value\t=%d\nCurrent\t=%p\nPrev\t=%p\nNext\t=%p\n\n",node->order,node,node->prev,node->next);
}


ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG

ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG | wc -l >> test-100

ARG=$(python3 -c "import random;a = random.sample(range(1000), 100)
for x in range(len(a)): print(a[x], end=\" \")");./a.out $ARG | wc -l >> test-500