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

void print_list_1(struct list_node *head)
{
    struct list_node *p = head->next;
    while (p != NULL) {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}

struct list_node *get_entry_node_of_loop(struct list_node *head)
{
    /*
    struct list_node *slow = head->next;
    struct list_node *fast = head->next->next;

    if (head->next == NULL || head->next->next == NULL)
        return NULL;

    while (fast != NULL) {
        if (fast == slow)  {
            fast = head;

            while (fast != slow)  {
                fast = fast->next;
                slow = slow->next; 
            }

            return fast;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return NULL;
    */

    struct list_node *slow = head;
    struct list_node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)  {
            fast = head;

            while (fast != slow)  {
                fast = fast->next;
                slow = slow->next; 
            }

            return fast;
        }

    }

    return NULL;

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

    head->next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n4;

    //print_list_1(head);

    printf("%d\n", get_entry_node_of_loop(head)->num);

    return 0;
}
