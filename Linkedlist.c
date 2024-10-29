#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* next;
};
struct node* start = NULL;


void insertAtBegening(int data){
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->info = data;
    t->next = start;
    start = t;
}

void insertAtEnd(int data){
    struct node *p = start;
    if (p == NULL)
        return insertAtBegening(data);
    while (p->next != NULL)
    {
        p = p->next;
    }
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->info = data;
    n->next = NULL;
    p->next = n;
}

void insertAfterSpecificElement(int data,int ele){
    if (start == NULL){
        printf("\n Linked list empty!");
        return;
    }

    struct node* p = start;
    while (p != NULL && p->info != ele)
    {
        p = p->next;
    }

    if (p->info != ele){
        printf("Element not found in list");
        return;
    }
    struct node *n = (struct node*)malloc(sizeof(struct node));
    n->info = data;
    n->next = p->next;
    p->next = n;

}

void deleteEnd(){
    if (start == NULL){printf("\nList empty");return;}
    struct node *p = start;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    free(p->next);
    p->next = NULL;
    return;
    }

void deleteFirst(){
    if (start == NULL){printf("\nList empty");return;}
    struct node *p = start->next;
    free(start);
    start = p;

}

void deleteSpecificNode(int ele){
    if (start == NULL)
    {printf("\nList empty");return;}

    struct node* p = start;
    struct node* prep = NULL;
    while (p->next != NULL && p->info != ele)
    {
        prep = p;
        p = p->next;
    }

    if (p->info != ele){
        printf("Element not found in list");
        return;
    }
    prep->next = p->next;
    free(p);
    return;

}

void display(struct node* head){
    while (head != NULL)
    {
        printf("\t%d",head->info);
        head = head->next;
    }
    
}

int main()
{
    int ch,info,ele;
    while(1){
        printf("\n******************************************************\n1. Insert at begening\n2. Insert at end\n3. Insert after specific element\n4. Delete end node\n5. Deleted first node\n6. Delete specific node\n7. Display\n8. Exit\n");
        scanf("%d",&ch);
    
        switch (ch)
        {
        case 1:
            printf("\n Enter info : ");
            scanf("%d",&info);
            insertAtBegening(info);
            break;

        case 2:
            printf("\n Enter info : ");
            scanf("%d",&info);
            insertAtEnd(info);
            break;
        
        case 3:
            printf("\n Enter info : ");
            scanf("%d",&info);
            printf("\n Enter element after which you want to insert : ");
            scanf("%d",&ele);
            insertAfterSpecificElement(info,ele);
            break;

        case 4:
            printf("\nDeleted end node");
            deleteEnd();
            break;
        
        case 5:
            printf("\nDeleted first node");
            deleteFirst();
            break;

        case 6:
            printf("\nDelete specific node");
            printf("\n Enter element to be deleted : ");
            scanf("%d",&ele);
            deleteSpecificNode(ele);
            break;

        case 7:
            display(start);
            break;
       
        case 8:
            exit(0);
        default:
                printf("\nInvalid choice");
            break;
        }
    }
    return 0;
}