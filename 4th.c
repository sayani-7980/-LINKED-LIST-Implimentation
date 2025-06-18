#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Linked list structure
typedef struct LinkedList {
    Node* head;
} LinkedList;

// Function to initialize the list
void initList(LinkedList* list) {
    list->head = NULL;
}

// Insert at the beginning
void insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

// Insert at the end
void insertAtEnd(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
        return;
    }

    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Delete a node by value
void deleteNode(LinkedList* list, int key) {
    Node* temp = list->head;
    Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Not found

    if (prev == NULL) {
        list->head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

// Search a node
int searchNode(LinkedList* list, int key) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

// Display the list
void displayList(const LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Free memory used by the list
void freeList(LinkedList* list) {
    Node* current = list->head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    list->head = NULL;
}

// Main function for demonstration
int main() {
    LinkedList list;
    initList(&list);

    insertAtBeginning(&list, 10);
    insertAtEnd(&list, 20);
    insertAtBeginning(&list, 5);
    insertAtEnd(&list, 30);

    printf("List: ");
    displayList(&list);

    printf("Searching for 20: %s\n", searchNode(&list, 20) ? "Found" : "Not Found");

    deleteNode(&list, 10);
    printf("After deleting 10: ");
    displayList(&list);

    freeList(&list);
 return 0;
}