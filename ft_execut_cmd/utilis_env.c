#include "../minishell.h"

t_environment  *new_node(void *var, void *data)
{
        t_environment  *elem;

        elem = (t_environment *)malloc(sizeof(t_environment));
        if (!elem)
                return (NULL);
        elem->var = var;
		elem->data = data;
        elem->next = NULL;
        return (elem);
}


void    add_back_node(t_environment **lst, t_environment *new)
{
        t_environment  *p;

        p = *lst;
        if (!lst || !new)
                return ;
        if (!(*lst))
        {
                *lst = new;
                return ;
        }
            while (p->next)
    {
       p=p->next;
    }
    p->next =new;
}