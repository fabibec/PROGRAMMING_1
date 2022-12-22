#include <stdio.h>
#include <stdlib.h>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))


const int upTo = 100000;

struct node{
    struct node *next;
    int num1;
    int num2;
};

typedef struct node node;

void findFriendlyNumbers(int limit, node** list);
int sumOfDividers(int num);
void insertNode(node** list, int num1, int num2);
void removeDuplicates(node * list);
void printList(node *list);
void freeList(node *list);

int main (void) {
    node *results = NULL;
    findFriendlyNumbers(upTo, &results);
    removeDuplicates(results);
    printList(results);
    freeList(results);
    return 0;
}

void findFriendlyNumbers(int limit, node** list) {
    int div_sum;

    for (int i = 1; i <= limit; i++) {
        div_sum = sumOfDividers(i);
        if (i == sumOfDividers(div_sum) && i != div_sum) {
            insertNode(list, MIN(i, div_sum), MAX(i, div_sum));
        }
    }
}

int sumOfDividers(int num) {
    int sum = 0;
    for (int i = 1; i <= (num/2); i++) {
        if(!(num % i)) {
            sum += i;
        }
    }
    return sum;
}

void insertNode(node** list, int num1, int num2){
    node *a_node = malloc(sizeof(node));
    a_node->num1 = num1;
    a_node->num2 = num2;
    a_node->next = *list;
    *list = a_node;
}

void removeDuplicates(node * list)
{
    node *ptr1, *ptr2, *dup;
    ptr1 = list;

    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        while (ptr2->next != NULL) {
            if (ptr1->num1 == ptr2->next->num1) {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

void printList(node *list) {
    node *cursor = list;
    while(cursor != NULL)
    {
        printf("A pair of amicable numbers found: %d, %d\n", cursor->num1, cursor->num2);
        cursor = cursor->next;
    }
}

void freeList(node *list)
{
    node *tmp, *cursor;
    tmp = list;
    cursor = list->next;
    while (cursor != NULL)
    {
        free(tmp);
        tmp = cursor;
        cursor = cursor->next;
    }
    free(tmp);
}