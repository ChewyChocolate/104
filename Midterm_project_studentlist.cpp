#include <iostream>
#include <cstring>
using namespace std;

struct student {
    char name[50];
    int age;
    student* next;
};

void DisplayStudent(student* head) {
    int counter = 0;
    for (student* current = head; current != NULL; current = current->next) {
        counter++;
        cout << "\n";
        cout << counter << ". ";
        cout << "\t" << "name: " << current->name << endl;
        cout << "\t" << "age: " << current->age << endl;
        cout << "\n";
    }
    system("pause");
    system("cls");
}

student* SearchStudents(student* head, const char* name) {
			student* match = (student*)malloc(sizeof(student));
			while(head != NULL){
		    	if(strcmp(head->name, name) == 0){
		    		strcpy(match->name, head->name);
		    		match->age = head->age;
		    		match->next = NULL;
					return 	match;
				}
		    	head = head->next;
			}
			free(match);
		    return NULL;
		}	
		
void FindNthStudent(student* head, int n) {
    int count = 0;
    student* current = head;

    while (current != NULL) {
        count++;
        if (count == n) {
            cout << "Nth Student: ";
            cout << "\n";
            cout << "\t" << "name: " << current->name << endl;
            cout << "\t" << "age: " << current->age << endl;
            cout << "\n";
            return; 
        }
        current = current->next;
    }
    cout << "number not found or out of range." << endl;
}

void EditStudent(student* head, const char* name) {
    student* current = head;

    while (current != NULL) {
        if (strstr(current->name, name) != NULL) {
            cout << "Enter the new name for the student: ";
            cin.getline(current->name, 50);
            cout << "Enter the new age for the student: ";
            cin >> current->age;
            cin.ignore(); // Clear the newline character
            cout << "Student information updated." << endl;
            return;
        }
        current = current->next;
    }
    cout << "Student not found." << endl;
    system("pause");
    system("cls");
}	

void InsertStudentAt(student*& head, const char* name, int age, int index) {
    if (index < 1) {
        cout << "Invalid index. Index should be greater than or equal to 1." << endl;
        return;
    }

    student* newStudent = new student();
    strcpy(newStudent->name, name);
    newStudent->age = age;

    if (index == 1) {
        newStudent->next = head;
        head = newStudent;
    } else {
        student* current = head;
        int currentIndex = 1;

        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        if (current == nullptr) {
            cout << "Index out of range. Student not inserted." << endl;
            delete newStudent;
            return;
        }
        
        newStudent->next = current->next;
        current->next = newStudent;
    }
    cout << "Student inserted at index " << index << "." << endl;
}

void DeleteStudent(student*& head, const char* name) {
    student* current = head;
    student* previous = NULL;

    while (current != NULL) {
        if (strstr(current->name, name) != NULL) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            cout << "Student deleted." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Student not found." << endl;
}

int main() {
    student* Head = NULL;
    char name[50];
    int ch;

    while (1) {
        cout << "\nMENU\n";
        cout << "\n1) Add new student";
        cout << "\n2) Display student list";
        cout << "\n3) Search a student";
		cout << "\n4) Find Nth";        
        cout << "\n5) Edit an entry";
        cout << "\n6) Insert an entry";
        cout << "\n7) Delete an entry";
        cout << "\n8) Reset list";
        cout << "\n0) Exit";

        cout << "\n\nChoice: ";
        cin >> ch;
        cin.ignore();
        system("cls");

        switch (ch) {
            case 1: {
                student* temp = new student();
                cout << "Name: ";
                cin.getline(temp->name, 50);
                cout << "Age: ";
                cin >> temp->age;
                cin.ignore(); // Clear the newline character
                temp->next = NULL;

                if (Head == NULL)
                    Head = temp;
                else {
                    student* trav = Head;
                    while (trav->next != NULL)
                        trav = trav->next;
                    trav->next = temp;
                }
                system("cls");
                break;
            }
            case 2:
                DisplayStudent(Head);
                break;
            case 3: {
                cout << "Enter the name of the student: ";
                cin.getline(name, 50);
                student* display = SearchStudents(Head, name);
                DisplayStudent(display);
                break;
            }
			case 4: {
			    int Nth;
			    cout << "Enter the Nth number: ";
			    cin >> Nth;
			    FindNthStudent(Head, Nth);
	    		system("pause");
    			system("cls");		    
			    break;
			}
            case 5: {
                cout << "Enter the name of the student you want to edit: ";
                cin.getline(name, 50);
                EditStudent(Head, name);
                break;
            }
            case 6: {
			    char newName[50];
			    int newAge;
			    int index;
			
			    cout << "Enter the name of the new student: ";
			    cin.getline(newName, 50);
			    cout << "Enter the age of the new student: ";
			    cin >> newAge;
			    cout << "Enter the index at which you want to insert the student: ";
			    cin >> index;
			    cin.ignore();
			
			    InsertStudentAt(Head, newName, newAge, index);
			    break;
			}
            case 7: {
                cout << "Enter the name of the student you want to delete: ";
                cin.getline(name, 50);
                DeleteStudent(Head, name);
                break;
            }
            case 8:{
            	student* current = Head;
                while (current != NULL) {
                    student* temp = current;
                    current = current->next;
                    delete temp;
                }
            	break;
        	}
            case 0:
                student* current = Head;
                while (current != NULL) {
                    student* temp = current;
                    current = current->next;
                    delete temp;
                }
                return 0;
        }
    }
    return 0;
}
