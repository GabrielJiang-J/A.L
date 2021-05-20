#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int num;
    struct list_node *next;
};

struct list_node *merge_list(struct list_node *head1, struct list_node *head2)
{
    struct list_node *head = (struct list_node *)malloc(sizeof(struct list_node));
    struct list_node *p = head;
    struct list_node *h1 = head1;
    struct list_node *h2 = head2;

    while (head1 != NULL && head2 != NULL) {
        if (head1->num <= head2->num) {
            p->next = head1; 
            head1 = head1->next;
        } else {
            p->next = head2;
            head2 = head2->next; 
        }

        p = p->next;
    }

    p->next = head1 ? head1 : head2;

    return head->next;
}

int main(int argc, char *argv[])
{
    struct list_node *p = NULL;

    struct list_node n11 = {
        .num = 10,
        .next = NULL,
    };
    struct list_node n12 = {
        .num = 87,
        .next = NULL,
    };
    struct list_node n13 = {
        .num = 100,
        .next = NULL,
    };
    struct list_node n14 = {
        .num = 21,
        .next = NULL,
    };
    struct list_node n15 = {
        .num = 97,
        .next = NULL,
    };
    struct list_node n16 = {
        .num = 500,
        .next = NULL,
    };
    struct list_node n17 = {
        .num = 600,
        .next = NULL,
    };
    struct list_node n18 = {
        .num = 700,
        .next = NULL,
    };

    n11.next = &n14;
    n14.next = &n12;
    n12.next = &n15;
    n15.next = &n13;
    n13.next = &n16;
    n16.next = &n17;
    n17.next = &n18;

    struct list_node n21 = {
        .num = 2,
        .next = NULL,
    };
    struct list_node n22 = {
        .num = 32,
        .next = NULL,
    };
    struct list_node n23 = {
        .num = 300,
        .next = NULL,
    };
    struct list_node n24 = {
        .num = 18,
        .next = NULL,
    };
    struct list_node n25 = {
        .num = 50,
        .next = NULL,
    };

    n21.next = &n24;
    n24.next = &n22;
    n22.next = &n25;
    n25.next = &n23;

    p = &n11;
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");

    p = &n21;
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");

#if 1
    p = merge_list(&n11, &n21);
    //p = merge_list(NULL, NULL);
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");
#endif
    p = &n11;
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");

    p = &n21;
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");

}
