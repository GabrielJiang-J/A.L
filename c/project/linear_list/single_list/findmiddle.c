#include <stdio.h>

struct list_node {
    int num;
    struct list_node *next;
};

struct list_node *findmiddle(struct list_node *head)
{
    struct list_node *fast = head;
    struct list_node *slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main(int argc, char *argv[])
{
    struct list_node *p = NULL;

#if 1
    struct list_node n1 = {
        .num = 5,
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
        .num = 8,
        .next = NULL,
    };
    struct list_node n5 = {
        .num = 7,
        .next = NULL,
    };
    struct list_node n6 = {
        .num = 9,
        .next = NULL,
    };

    n1.next = &n4;
    n4.next = &n2;
    n2.next = &n6;
    n6.next = &n5;
    n5.next = &n3;
#else
    struct list_node n1 = {
        .num = 1,
        .next = NULL, 
    };
#endif

    struct list_node *n9 = NULL;
    p = &n1;
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");

    p = findmiddle(n9);
    printf("%d ", p->num); 
    printf("\n");
}
