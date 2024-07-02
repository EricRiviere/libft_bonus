#include "libft.h"
#include <stdio.h>
#include <stdlib.h> // Para malloc y free
#include <string.h>

// Función auxiliar para imprimir el contenido de un nodo
void print_content(void *content)
{
    printf("%s\n", (char *)content);
}

// Función auxiliar para liberar la memoria de un string
void free_content(void *content)
{
    free(content);
}

int main(void)
{
    t_list *head = NULL;
    t_list *node2 = NULL;
    t_list *node3 = NULL;
    char *content1 = strdup("Node 1");
    char *content2 = strdup("Node 2");
    char *content3 = strdup("Node 3");

    // Crear los nodos
    head = ft_lstnew(content1);
    if (!head)
    {
        printf("Failed to create head node.\n");
        return 1;
    }

    node2 = ft_lstnew(content2);
    if (!node2)
    {
        printf("Failed to create second node.\n");
        ft_lstclear(&head, free_content);
        return 1;
    }

    node3 = ft_lstnew(content3);
    if (!node3)
    {
        printf("Failed to create third node.\n");
        ft_lstclear(&head, free_content);
        ft_lstclear(&node2, free_content);
        return 1;
    }

    // Añadir nodos al principio de la lista
    ft_lstadd_front(&head, node2);
    ft_lstadd_front(&head, node3);

    // Imprimir el contenido de la lista
    printf("Contents of the list:\n");
    ft_lstiter(head, print_content);

    // Mostrar el tamaño de la lista
    printf("Size of the list: %d\n", ft_lstsize(head));

    // Añadir nodo al final de la lista
    t_list *node4 = ft_lstnew(strdup("Node 4"));
    ft_lstadd_back(&head, node4);

    // Imprimir el contenido de la lista actualizada
    printf("Contents of the list after adding node 4:\n");
    ft_lstiter(head, print_content);

    // Eliminar el primer nodo de la lista
    t_list *first_node = head;
    head = head->next;
    ft_lstdelone(first_node, free_content);

    // Imprimir la lista después de eliminar el primer nodo
    printf("Contents of the list after deleting first node:\n");
    ft_lstiter(head, print_content);

    // Limpiar memoria usando ft_lstclear
    ft_lstclear(&head, free_content);

    return 0;
}

