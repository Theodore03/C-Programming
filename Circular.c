#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *tail = NULL;

/* Create Circular Linked List */
void createlist(int n) {
    int i, data;
    struct node *newnode;

    for (i = 0; i < n; i++) {

        printf("Enter data: ");
        scanf("%d", &data);

        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = data;

        if (tail == NULL) {
            tail = newnode;
            tail->next = tail;
        } else {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
    }

    printf("-- Successfully created --\n");
}

/* Display */
void display() {
    struct node *temp;

    if (tail == NULL) {
        printf("List is empty..!\n");
        return;
    }

    temp = tail->next;

    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("(back to first node)\n");
}

/* Insert at Beginning */
void insert_at_beg(int data) {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;

    if (tail == NULL) {
        tail = newnode;
        tail->next = tail;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
    }

    printf("Successfully inserted......\n");
}

/* Insert at End */
void insert_at_end(int data) {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;

    if (tail == NULL) {
        tail = newnode;
        tail->next = tail;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
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

    /* Insert at beginning */
    if (pos == 1) {

        if (tail == NULL) {
            tail = newnode;
            tail->next = tail;
        } else {
            newnode->next = tail->next;
            tail->next = newnode;
        }

        printf("Successfully inserted......\n");
        return;
    }

    if (tail == NULL) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    temp = tail->next;

    for (i = 1; i < pos - 1 && temp != tail; i++) {
        temp = temp->next;
    }

    if (i != pos - 1) {
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    /* If inserted after tail */
    if (temp == tail) {
        tail = newnode;
    }

    printf("Successfully inserted......\n");
}

/* Delete at Beginning */
void det_at_beg() {
    struct node *temp;

    if (tail == NULL) {
        printf("List is empty..!\n");
        return;
    }

    temp = tail->next;

    /* Only one node */
    if (tail == temp) {
        tail = NULL;
    } else {
        tail->next = temp->next;
    }

    free(temp);

    printf("Successfully Deleted......\n");
}

/* Delete at End */
void det_at_end() {
    struct node *temp, *prev;

    if (tail == NULL) {
        printf("List is empty..!\n");
        return;
    }

    /* Only one node */
    if (tail->next == tail) {
        free(tail);
        tail = NULL;

        printf("Successfully Deleted......\n");
        return;
    }

    temp = tail->next;

    while (temp->next != tail) {
        temp = temp->next;
    }

    prev = temp;
    temp = tail;

    prev->next = tail->next;
    tail = prev;

    free(temp);

    printf("Successfully Deleted......\n");
}

/* Delete at Position */
void det_at_pos(int pos) {
    int i;
    struct node *temp, *nextnode;

    if (tail == NULL) {
        printf("List is empty..!\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    /* Delete first node */
    if (pos == 1) {
        det_at_beg();
        return;
    }

    temp = tail->next;

    for (i = 1; i < pos - 1 && temp != tail; i++) {
        temp = temp->next;
    }

    if (temp == tail) {
        printf("Invalid position!\n");
        return;
    }

    nextnode = temp->next;
    temp->next = nextnode->next;

    /* If deleting last node */
    if (nextnode == tail) {
        tail = temp;
    }

    free(nextnode);

    printf("Successfully Deleted......\n");
}

/* Main Function */
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

        printf("\nEnter your choice: ");
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