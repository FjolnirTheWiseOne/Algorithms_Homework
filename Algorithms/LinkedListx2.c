#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} DoublyLinkedList;

DoublyLinkedList* createList() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    return list;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(DoublyLinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void delete(DoublyLinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == data) {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            if (temp == list->head)
                list->head = temp->next;
            free(temp);
            printf("Deleted %d from list.\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found in list. Cannot delete.\n", data);
}

Node* search(DoublyLinkedList* list, int data) {
    Node* temp = list->head;
    while (temp != NULL) {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void display(DoublyLinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    DoublyLinkedList* list = createList();

    insert(list, 10);
    insert(list, 20);
    insert(list, 30);
    insert(list, 40);

    printf("Original list: ");
    display(list);

    Node* found = search(list, 20);
    if (found != NULL)
        printf("Element 20 found in list.\n");
    else
        printf("Element 20 not found in list.\n");

    delete(list, 20);

    printf("List after deletion: ");
    display(list);

    found = search(list, 20);
    if (found != NULL)
        printf("Element 20 found in list.\n");
    else
        printf("Element 20 not found in list.\n");

    // Free memory
    Node* temp = list->head;
    Node* next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);

    return 0;
}
