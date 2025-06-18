#include <stdio.h>
#include <stdlib.h>
// Node structure for the singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL; // Head pointer to the start of the list

// Function to insert a node at the end
void insertAtEnd(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Inserted %d into the list.\n", value);
}

// Function to delete a node by value
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // If the node to be deleted is the head
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // If the value was not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    // Unlink and free the node
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

// Function to traverse and display the list
void traverseList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node* temp = head;
    printf("Singly Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with menu-driven options
int main() {
    int choice, value;

    while (1) {
        printf("\nSingly Linked List Operations Menu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete by value\n");
        printf("3. Traverse the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                traverseList();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
return 0;
}
