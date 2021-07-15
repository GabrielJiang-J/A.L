#include <stdio.h>

struct list_node {
    int num;
    struct list_node *next;
};

int isPalindrome_1(struct list_node *head)
{
    if (!head) 
        return 1;//链表为空时

    int i = 0;
    int len = 1;
    struct list_node *p = head;

    //链表长度为1时
    if (p->next == NULL)
        return 1;

    //长度大于1时：先计算链表长度，再定义数组，把链表的值全部导如数组，循环遍历数组至数组长度二分之一处以验证是否为回文数组
    while (p->next != NULL) {
        len++;
        p = p->next;
    }

    p = head;
    int a[len + 1];
    while (p->next != NULL) {
        a[i] = p->num;
        i++;
        p = p->next;
    }

    a[i] = p->num;
    for (i = 0; i < len / 2; i++) {
        if (a[i] != a[len - 1 - i])
            return 0;
    }

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

    is = isPalindrome_1(&n1);
    printf("%d\n", is);

    return 0;
}
