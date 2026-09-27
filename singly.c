#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};  
struct node *head = NULL;
/* create linked list */
void createList()
{
    int n,i;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        struct node *newNode, *temp;
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data of node : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("Singly linked list created successfully.\n");
}
/* display linked list */
void displayList()
{
    struct node*temp=head;
    if(temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("\nCreated Singly Linked List: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
/* insert node at the beginning */
void insert_at_beg()
{
    struct node *newNode;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert at the beginning: ");
    scanf("%d",&newNode->data);
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning successfully.\n");
}
/* insert node at the end */
void insert_at_end()
{
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert at the end: ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end successfully.\n");
}
/* insert node at a specific position */
void insert_at_pos()
{
    int pos,i;
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the position to insert the new node: ");
    scanf("%d",&pos);
    printf("Enter the data to insert at position %d: ",pos);
    scanf("%d",&newNode->data);
    if(pos == 1)
    {
        newNode->next = head;
        head = newNode;
        printf("Node inserted at position %d successfully.\n",pos);
        return;
    }
    temp = head;
    for(i=1;i<pos-1 && temp != NULL;i++)
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d successfully.\n",pos);
}
/* delete node from the beginning */
void del_at_beg()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from the beginning successfully.\n");
}
/* delete node from the end */
void del_at_end()
{
    struct node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Node deleted from the end successfully.\n");
        return;
    }
    temp = head;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Node deleted from the end successfully.\n");
}
/* delete node from a specific position */
void del_at_pos()
{
    int pos,i;
    struct node *temp, *prev;
    if(head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Enter the position to delete the node: ");
    scanf("%d",&pos);
    if(pos == 1)
    {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted from position %d successfully.\n",pos);
        return;
    }
    temp = head;
    for(i=1;i<pos && temp != NULL;i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d successfully.\n",pos);
}
/* main function  */
int main()
{
    int choice,n;
    while(1)
    {
        printf("\nSingly Linked List Operations:\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Position\n");
        printf("6. Delete from Beginning\n");
        printf("7. Delete from End\n");
        printf("8. Delete from Position\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                insert_at_beg();
                break;
            case 4:
                insert_at_end();
                break;
            case 5:
                insert_at_pos();
                break;
            case 6:
                del_at_beg();
                break;
            case 7:
                del_at_end();
                break;
            case 8:
                del_at_pos();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
