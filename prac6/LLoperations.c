#include <stdio.h> 
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int countNodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
struct Node *copyList(struct Node *head)
{
    if (head == NULL)
        return NULL;
    struct Node *newHead = createNode(head->data);
    struct Node *temp = newHead;
    head = head->next;
    while (head != NULL)
    {
        temp->next = createNode(head->data);
        temp = temp->next;
        head = head->next;
    }
    return newHead;
}
struct Node *concatenateLists(struct Node *list1, struct Node *list2)
{
    if (list1 == NULL)
        return list2;
    struct Node *temp = list1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}
struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void splitList(struct Node *head, struct Node **list1, struct Node **list2)
{
    if (head == NULL)
    {
        *list1 = NULL;
        *list2 = NULL;
        return;
    }
    struct Node *slow = head;
    struct Node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *list1 = head;
    *list2 = slow->next;
    slow->next = NULL;
}
int main()
{
    struct Node *head = NULL;
    int choice, data;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert Node\n");
        printf("2. Display List\n");
        printf("3. Count Nodes\n");
        printf("4. Copy List\n");
        printf("5. Concatenate Lists\n");
        printf("6. Reverse List\n");
        printf("7. Split List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertEnd(&head, data);
            break;
        case 2:
            printf("The linked list is: ");
            display(head);
            break;
        case 3:
            printf("Number of nodes: %d\n", countNodes(head));
            break;
        case 4:
        {
            struct Node *copiedList = copyList(head);
            printf("Copied List: ");
            display(copiedList);
            free(copiedList);
            break;
        }
        case 5:
        {
            struct Node *list2 = NULL;
            int n, data;
            printf("Enter number of nodes for second list: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter data for node %d: ", i + 1);
                scanf("%d", &data);
                insertEnd(&list2, data);
            }
            struct Node *concatenatedList = concatenateLists(head, list2);
            printf("Concatenated List: ");
            display(concatenatedList);
            free(list2); // Freeing memory for list2 
            free(concatenatedList); 
            break;
        }
        case 6:
        {
            struct Node *reversedList = reverseList(head);
            printf("Reversed List: ");
            display(reversedList);
            break;
        }
        case 7:
        {
            struct Node *list1 = NULL;
            struct Node *list2 = NULL;
            splitList(head, &list1, &list2);
            printf("First Half: ");
            display(list1);
            printf("Second Half: ");
            display(list2);
            free(list1);
            free(list2);
            break;
        }
        case 0:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
