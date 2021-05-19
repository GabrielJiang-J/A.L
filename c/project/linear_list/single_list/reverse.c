#include <stdio.h>

struct list_node {
    int num;
    struct list_node *next;
};

struct list_node *reverse(struct list_node *head)
{
    struct list_node *next = NULL;
    struct list_node *prev = NULL;

    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next; 
    }

    return prev;
}

int main(int argc, char *argv[])
{
    struct list_node *p = NULL;

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

    n1.next = &n4;
    n4.next = &n2;
    n2.next = &n5;
    n5.next = &n3;

    p = &n1;
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");

    p = reverse(&n1);
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");
}
