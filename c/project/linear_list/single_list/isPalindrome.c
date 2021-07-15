#include <stdio.h>

struct list_node {
    int num;
    struct list_node *next;
};

int isPalindrome_1(struct list_node *head)
{
    int rsp = -1;
    int length = 0;
    int i = 0;
    struct list_node *p = head;
    struct list_node *stack[16] = { NULL };
    int is_even = 0;

    if (head == NULL)
        return 0;

    while (p) {
        length++;
        p = p->next;
    }

    if (length == 1)
        return 1;

    if ((length % 2) != 0) {
        ++length;
        is_even = 1;
    }

    p = head;
    while (p) {
        if (i != (length / 2) && !is_even) {
            stack[++rsp] = p;
            ++i;
        } else {
            if ((stack[rsp--])->num != p->num) 
                return 0;
        }
        p = p->next;
    }
    if (rsp != -1)
        return 0;

    return 1;
}

int isPalindrome_2(struct list_node *head)
{
    struct list_node *p = head;

    int base = 11, mod = 1000000007;
    int left = 0, right = 0, mul = 1;

    while (p != NULL) {
        left = (int)(((long)left * base + p->num) % mod);
        right = (int)((right + (long)mul * p->num) % mod);
        mul = (int)((long)mul * base % mod);
        p = p->next;
    }

    return left == right;
}

int main(int argc, char *argv[])
{
    struct list_node *p = NULL;
    int is = 0;

    /*
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
        .num = 3,
        .next = NULL,
    };
    struct list_node n5 = {
        .num = 2,
        .next = NULL,
    };
    struct list_node n6 = {
        .num = 1,
        .next = NULL,
    };

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    */
    struct list_node n1 = {
        .num = 1,
        .next = NULL,
    };
    struct list_node n2 = {
        .num = 0,
        .next = NULL,
    };
    struct list_node n3 = {
        .num = 1,
        .next = NULL,
    };

    n1.next = &n2;
    n2.next = &n3;

    p = &n1;
    while (p != NULL) {
        printf("%d ", p->num); 
        p = p->next;
    }
    printf("\n");

    is = isPalindrome_2(&n1);
    printf("%d\n", is);

    return 0;
}
