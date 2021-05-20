#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int num;
    struct list_node *next;
};

struct list_node *create_list(void)
{
    struct list_node *head = (struct list_node *)malloc(sizeof(struct list_node));

    head->num = -333;
    head->next = NULL;

    return head;
}

int insert_list(struct list_node *head, struct list_node *node, int pos)
{
    int i = 0;
    struct list_node *p = head;

    if (p->next == NULL) {
        head->next = node;
        return 0;
    }

    if (pos == 0) {
        node->next = head->next;
        head->next = node;
        return 0;
    }

    while (p->next != NULL)  {
        if (pos == ++i) {
            node->next = p->next->next;
            p->next->next = node; 
            return 0;
        }

        p = p->next;
    }

    p->next = node;

    return 0;
}

int delete_list(struct list_node *head, int pos)
{
    int i = 0;
    struct list_node *p = head;

    if (p->next == NULL) {
        return 0; 
    }

    while (p->next != NULL && p->next->next != NULL) {
        if (pos == ++i) {
            p->next = p->next->next;
            return 0;
        }

        p = p->next;
    }

    p->next = NULL;

    return 0;
}

void print_list_1(struct list_node *head)
{
    struct list_node *p = head->next;
    while (p != NULL) {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}

void print_list_2(struct list_node *head)
{
    if (head != NULL) {
        if (head->next != NULL) {
            printf("%d ", head->next->num);
            print_list_2(head->next);
        } else {
            printf("\n"); 
        }
    }
}

void print_list_3(struct list_node *head)
{
    struct list_node *stack[1024] = {0};
    int rsp = -1;

    struct list_node *p = head->next;
    struct list_node *t = NULL;

    while (p != NULL) {
        stack[++rsp] = p;
        p = p->next;
    }

    while (rsp != -1) {
        t = stack[rsp--];
        printf("%d ", t->num);
    }
    printf("\n");
}

void print_list_4(struct list_node *head)
{
#define SIZE 1024 
    struct list_node *queue[SIZE] = {NULL};
    int front = -1;
    int tail = -1;

    struct list_node *p = head->next;
    struct list_node *t = NULL;

    while (p != NULL) {
        queue[(++tail)%SIZE] = p;
        p = p->next;
    }

    while (front != tail) {
        t = queue[(++front)%SIZE];
        printf("%d ", t->num);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    struct list_node *head = create_list();
    printf("%d\n", head->num);

    struct list_node n1 = {
        .num = 1,
        .next = NULL, 
    };

    struct list_node n2 = {
        .num = 2,
        .next = NULL, 
    };

    struct list_node n3 = {
        .num = 3,
        .next = NULL, 
    };

    struct list_node n4 = {
        .num = 4,
        .next = NULL, 
    };

    struct list_node n5 = {
        .num = 5,
        .next = NULL, 
    };

    struct list_node n6 = {
        .num = 6,
        .next = NULL, 
    };

    struct list_node n7 = {
        .num = 7,
        .next = NULL, 
    };

    insert_list(head, &n1, -1);
    insert_list(head, &n2, 0);
    insert_list(head, &n3, 1);
    insert_list(head, &n4, 100);
    insert_list(head, &n5, -100);
    insert_list(head, &n6, 3);
    insert_list(head, &n7, 5);

    //print_list_1(head);
    //print_list_2(head);
    //print_list_3(head);
    print_list_1(head);

    delete_list(head, 3);
    print_list_1(head);

    delete_list(head, -1);
    print_list_1(head);

    delete_list(head, 100);
    print_list_1(head);

    delete_list(head, 1);
    print_list_1(head);

    delete_list(head, -100);
    print_list_1(head);

    delete_list(head, 0);
    print_list_1(head);

    delete_list(head, 5);
    print_list_1(head);

    return 0;
}
