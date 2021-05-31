#include <stdio.h>

struct list_node {
    int num;
    struct list_node *next;
};


struct list_node *rotate_right(struct list_node* head, int k) {
#if 0
    struct list_node* p1;
    struct list_node* p2;
    struct list_node* p3;
    int len=1;
    p1=head;
    p2=head;
    p3=head;

    if(!head||!head->next)
        return head;
    while(p1->next)
    {
        len++;
        p1=p1->next;
    }
    k=k%len; 
    if(k==0)
        return head;
    len=len-k-1;
    while(len--)
        p2=p2->next;
    p3=p2->next;
    p1=p3;
    while(p1->next)
        p1=p1->next;
    p2->next=NULL;
    p1->next=head;
    return p3;
#else
    if (head != NULL || head->next != NULL)
        return head;

    int len = 1;
    struct list_node *p1 = head;
    while (p1->next != NULL) {
        ++len;
        p1 = p1->next;
    }

    k %= len;
    if (k == 0)
        return head;

    len -= k + 1;

    p1 = head;
    while (len--)
        p1 = p1->next; 

    struct list_node *p2 = p1->next;
    p1->next = NULL;

    p1 = p2;
    while (p1->next) {
        p1 = p1->next; 
    }
    p1->next = head;
    return p2;
#endif
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

    p = rotate_right(&n1, 8);
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");
}
