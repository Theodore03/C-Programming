#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Create List */
void createlist(int n) {
    int i, data;
    struct node *newnode, *temp;

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &data);

        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    printf("-- Successfully created --\n");
}

/* Display */
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty..!\n");
        return;
    }

    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Insert at Beginning */
void insert_at_beg(int data) {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }

    head = newnode;

    printf("Successfully inserted......\n");
}

/* Insert at End */
void insert_at_end(int data) {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Successfully inserted......\n");
}

/* Insert at Position */
void insert_at_pos(int data, int pos) {
    int i;
    struct node *newnode, *temp;

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;

    if (pos == 1) {
        newnode->prev = NULL;
        newnode->next = head;

        if (head != NULL) {
            head->prev = newnode;
        }

        head = newnode;

        printf("Successfully inserted......\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;

    printf("Successfully inserted......\n");
}

/* Delete at Beginning */
void det_at_beg() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty..!\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);

    printf("Successfully Deleted......\n");
}

/* Delete at End */
void det_at_end() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty..!\n");
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);

    printf("Successfully Deleted......\n");
}

/* Delete at Position */
void det_at_pos(int pos) {
    int i;
    struct node *temp;

    if (head == NULL) {
        printf("List is empty..!\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);

    printf("Successfully Deleted......\n");
}

/* Main */
int main() {
    int choice, n, data, pos;

    while (1) {

        printf("\n");
        printf("1. Create list\n");
        printf("2. Display list\n");
        printf("3. Insertion at beginning\n");
        printf("4. Insertion at end\n");
        printf("5. Insertion at position\n");
        printf("6. Deletion at beginning\n");
        printf("7. Deletion at end\n");
        printf("8. Deletion at position\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);

                createlist(n);
                display();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter data: ");
                scanf("%d", &data);

                insert_at_beg(data);
                display();
                break;

            case 4:
                printf("Enter data: ");
                scanf("%d", &data);

                insert_at_end(data);
                display();  
                break;

            case 5:
                printf("Enter data: ");
                scanf("%d", &data);

                printf("Enter position: ");
                scanf("%d", &pos);

                insert_at_pos(data, pos);
                display();
                break;

            case 6:
                det_at_beg();
                display();
                break;

            case 7:
                det_at_end();
                display();
                break;

            case 8:
                printf("Enter position: ");
                scanf("%d", &pos);

                det_at_pos(pos);
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}