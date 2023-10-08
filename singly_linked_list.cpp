#include <iostream>
using namespace std;

struct Node{
  int data;
  Node* next;
};

int main(){
    Node* head = new Node();
    Node* first = new Node();
    Node* second = new Node();
    
    head->data = 10;
    first->data = 20;
    second->data = 30;
    
    head->next = first;
    first->next = second;
    second->next = nullptr;
    
    Node* current = head;
    
    while(current != nullptr){
        cout <<current->data << endl;
        current = current->next;
    }
}
