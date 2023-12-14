#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

struct person {
    char fName[50];
    char mName[50];
    char lName[50];
    int age;
    char address[50];
    int tNum;

    person* next;
};

person* head = NULL;
person* current = NULL;

void sort() {
    person* temp;
    person* trav;
    person* prev;

    bool startSort = true;
    while (startSort) {
        startSort = false;
        temp = head;
        prev = temp->next;

        // Check if prev is not nullptr before accessing its properties
        if (prev != nullptr) {
            trav = prev->next;

            if (_stricmp(head->lName, prev->lName) > 0) {
                temp->next = prev->next;
                prev->next = temp;
                head = prev;
                startSort = true;
            }
            else {
                while (trav != nullptr) {
                    if (_stricmp(prev->lName, trav->lName) > 0) {
                        temp->next = trav;
                        prev->next = trav->next;
                        trav->next = prev;
                        startSort = true;
                        break;
                    }
                    temp = temp->next;
                    prev = prev->next;
                    trav = trav->next;
                }
            }
        }
        else {
            // Handle the case where prev is nullptr
            // This could involve breaking out of the loop or other logic
            break;
        }
    }
}



void addEntry() {
    char fName[50];
    char mName[50];
    char lName[50];
    int age;
    char address[50];
    int tNum;

    cout << "First name: ";
    cin.ignore();
    cin.getline(fName, sizeof(fName));

    cout << "Middle name: ";
    cin.getline(mName, sizeof(mName));

    cout << "Last name: ";
    cin.getline(lName, sizeof(lName));

    cout << "Age: ";
    cin >> age;

    cout << "Address: ";
    cin.ignore();
    cin.getline(address, sizeof(address));

    cout << "Telephone Number: ";
    cin >> tNum;

    if (head == NULL) {
        head = (person*)malloc(sizeof(person));
        strcpy(head->fName, fName);
        strcpy(head->mName, mName);
        strcpy(head->lName, lName);
        head->age = age;
        strcpy(head->address, address);
        head->tNum = tNum;
        head->next = NULL;
    }
    else {
        current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = (person*)malloc(sizeof(person));
        strcpy(current->next->fName, fName);
        strcpy(current->next->mName, mName);
        strcpy(current->next->lName, lName);
        current->next->age = age;
        strcpy(current->next->address, address);
        current->next->tNum = tNum;
        current->next->next = NULL;
    }
}

void display() {
    current = head;
    int ctr = 0;

    while (current != NULL) {
        ctr++;
        cout << ctr << ". " << endl;
        cout << "\tName: " << current->fName << " " << current->mName << " " << current->lName << endl;
        cout << "\tAge: " << current->age << endl;
        cout << "\tAddress: " << current->address << endl;
        cout << "\tNumber: " << current->tNum << endl;
        current = current->next;
    }
    system("pause");
}

void RmvEntry() {
    int ctr = 0;
    char toRemove[50];
    current = head;
    person* prev = NULL;

    cout << "Enter last name that you want to remove: ";
    cin.ignore();
    cin.getline(toRemove, sizeof(toRemove));

    if (head == NULL) {
        cout << "List is empty." << endl;
        system("pause");
        return;
    }

    while (current != NULL) {
        if (strcmp(current->lName, toRemove) == 0) {
            if (prev == NULL) {
                head = current->next;
            }
            else {
                prev->next = current->next;
            }

            free(current);
            cout << "Entry removed successfully." << endl;
            system("pause");
            return;
        }

        prev = current;
        current = current->next;
        ctr++;
    }

    cout << "Entry not found." << endl;
    system("pause");
}

void searchEntry() {
    char toSearch[50];
    int ctr = 0;
    cout << "Enter the last name that you want to search: ";
    cin.ignore();
    cin.getline(toSearch, sizeof(toSearch));

    current = head;
    while (current != NULL) {
        ctr++;
        if (strcmp(current->lName, toSearch) == 0) {
            system("cls");
            cout << "Person found" << endl;
            cout << ctr << ". " << current->fName << " " << current->lName << endl;
            system("pause");
            return;
        }
        current = current->next;
    }

    cout << "Person not found." << endl;
    system("pause");
}

void editEntry() {
    char fName[50];
    char mName[50];
    char lName[50];
    int age;
    char address[50];
    int tNum;

    cout << "Enter last name: ";
    cin.ignore();
    cin.getline(lName, sizeof(lName));
    person* current = head;

    while (current != NULL) {
        if (strcmp(current->lName, lName) == 0) {
            cout << "Enter new first name: ";
            cin.getline(fName, sizeof(fName));
            strcpy(current->fName, fName);

            cout << "Enter new middle name: ";
            cin.getline(mName, sizeof(mName));
            strcpy(current->mName, mName);

            cout << "Enter new last name: ";
            cin.getline(lName, sizeof(lName));
            strcpy(current->lName, lName);

            cout << "Enter new age: ";
            cin >> age;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            current->age = age;

            cout << "Enter new address: ";
            cin.getline(address, sizeof(address));
            strcpy(current->address, address);

            cout << "Enter Telephone Number: ";
            cin >> tNum;
            current->tNum = tNum;

            cout << "Student information updated." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Student not found." << endl;
    system("pause");
}

void dltAll() {
    while (head != NULL) {
        person* temp = head;
        head = head->next;
        free(temp);
    }
}

void savefile() {
    FILE* fp;
    fp = fopen("file.dat", "wb");
    if (fp == NULL) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    person* savePtr = head;  // Separate pointer for traversing without modifying 'current'
    while (savePtr != NULL) {
        fwrite(savePtr, sizeof(person), 1, fp);
        savePtr = savePtr->next;
    }

    fclose(fp);
}

void openfile() {
    FILE* fp;
    fp = fopen("file.dat", "rb");
    if (fp == NULL) {
        cerr << "Error opening file or file doesn't exist. Creating a new file." << endl;
        fp = fopen("file.dat", "wb");  // Open for reading and writing, create if not exists
        if (fp == NULL) {
            cerr << "Error creating a new file." << endl;
            return;
        }
    }

    while (true) {
        person* newNode = (person*)malloc(sizeof(person));
        if (newNode == NULL) {
            cerr << "Memory allocation error." << endl;
            exit(EXIT_FAILURE);
            system("pause");
        }

        if (fread(newNode, sizeof(person), 1, fp) != 1) {
            free(newNode);
            break;
        }
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    fclose(fp);
}



int main() {
    openfile();
    char choice;

    while (true) {
        system("cls");
        cout << "\t1. Add an Entry" << endl;
        cout << "\t2. Delete an Entry" << endl;
        cout << "\t3. Show All Entries" << endl;
        cout << "\t4. Search an Entry" << endl;
        cout << "\t5. Edit an Entry" << endl;
        cout << "\t6. Delete All Entries" << endl;
        cout << "\t7. Exit" << endl;

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            addEntry();
            sort();
            break;

        case '2':
            RmvEntry();
            break;

        case '3':

            display();
            break;

        case '4':
            searchEntry();
            break;

        case '5':
            editEntry();
            sort();
            break;

        case '6':
            dltAll();
            break;

        case '7':
            savefile();
            dltAll();
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
        }
    }

    return 0;
}