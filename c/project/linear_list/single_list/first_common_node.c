#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int num;
    struct list_node *next;
};

struct list_node *find_first_common_node(struct list_node *head1, struct list_node *head2)
{
    int len1 = 0;
    int len2 = 0;
    int diflen = 0;
    struct list_node *p1 = head1;
    struct list_node *p2 = head2;

    if (head1 == NULL || head2 == NULL)
        return NULL;

    while (p1 != NULL) {
        p1 = p1->next;
        len1++;
    }

    while (p2 != NULL) {
        p2 = p2->next;
        len2++; 
    }

    diflen = len1 - len2;

    p1 = head1;
    p2 = head2;

    if (diflen >= 0) {
        while (diflen > 0) {
            p1 = p1->next; 
            diflen--;
        }

        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next; 
        }
        return p1;
    } else {
        diflen = -diflen;

        while (diflen > 0) {
            p2 = p2->next;
            diflen--; 
        }

        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next; 
        }

        return p2;
    }
    return NULL;
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

    n11.next = &n12;
    n12.next = &n13;
    n13.next = &n14;
    n14.next = &n15;
    n15.next = &n16;
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

    n21.next = &n22;
    n22.next = &n23;
    n23.next = &n15;

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

    p = find_first_common_node(&n11, &n21);

    printf("%d\n", p->num);
}
