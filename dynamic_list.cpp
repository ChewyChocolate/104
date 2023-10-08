#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = nullptr; // Initialize an empty linked list

    // Add elements to the linked list
    for (int i = 1; i <= 5; ++i) {
        Node* newNode = new Node(); // Create a new node
        newNode->data = i;         // Set the data for the node
        newNode->next = nullptr;   // Initialize the next pointer to nullptr

        // If the list is empty, make the new node the head
        if (head == nullptr) {
            head = newNode;
        } else {
            // Otherwise, traverse the list to find the last node and link the new node
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Print the elements of the linked list
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    // Don't forget to free the memory when you're done
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}
