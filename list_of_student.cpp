#include <iostream>
#include <cstdlib>
using namespace std;

struct student {
    char name[50];
    int age;
    struct student* next;
};

int main() {
    struct student* Head = NULL;
    struct student* temp = NULL;
    struct student* trav = NULL;

    char buff[50];
    int i;
    int ch;

    while (1) {
        system("cls");
        cout << "\nMENU\n";
        cout << "\n1) Add new student";
        cout << "\n2) Display student list";
        cout << "\n3) Search a student";
        cout << "\n4) Edit an entry";
        cout << "\n5) Delete an entry";
        cout << "\n6) Reset list";
        cout << "\n0) Exit";

        cout << "\n\nChoice: ";
        cin >> ch;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (ch) {
            case 1:
                temp = (struct student*)malloc(sizeof(struct student));
                if (temp == NULL) {
                    cout << "Memory Full";
                    system("pause");
                }
                else {
                    cout << "Name: ";
                    gets(temp->name);
                    cout << "Age: ";
                    gets(buff);
                    temp->age = atoi(buff); // Convert age to an integer

                    temp->next = NULL;

                    if (Head == NULL)
                        Head = temp;
                    else {
                        for (trav = Head; trav->next != NULL; trav = trav->next);
                        trav->next = temp;
                    }
                }
                break;

            case 2:
                cout << "\tName\t\t\tAge\n";
                for (i = 0, trav = Head; trav != NULL; trav = trav->next, i++) {
                    cout << i << ") " << trav->name << "\t\t" << trav->age << endl;
                }
                break;

            case 3:
                // Add code to search for a student by name or other criteria
                break;

            case 4:
                // Add code to edit a student record
                break;

            case 5:
                // Add code to delete a student record
                break;

            case 6:
                // Add code to reset the list
                break;

            case 0:
                for (temp = Head; Head != NULL; temp = Head) {
                    Head = Head->next;
                    free(temp);
                }
                exit(0); // Use 0 to indicate a successful exit
                break;

            default:
                cout << "Invalid choice. Please ty again." << endl;
        }
        cout << "\n\n";
        system("pause");
    }

    return 0;
}
