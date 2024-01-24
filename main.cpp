#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//# Used:
//# 1. vector
//# 2. struct
//# 4. remove_if
//# 5. erase
//# 6. auto
//# 7. range based for loop
//# 8. pointer


//#TODO:
//     1. Add Contact (input only name and phone number, id should be auto generated)
//     2. Search Contact (search by id, name or phone number. Print all details of contact)
//     3. Delete Contact (search by id, name or phone number. Delete contact using id)
//     4. List Contacts (print all contacts)
//     5. Exit()

struct Contact {
    int id;
    string name;
    string phoneNumber;
};

vector<Contact> contacts;

void addContact(const Contact &contact) {
    contacts.push_back(contact);
}

Contact *searchContact(const string &name) {
    for (auto &contact: contacts) {
        if (contact.name == name) {
            return &contact;
        }
    }
    return nullptr;
}

void deleteContact(const string &name) {
    contacts.erase(remove_if(contacts.begin(), contacts.end(),
                             [&](const Contact &contact) { return contact.name == name; }),
                   contacts.end());
}

void listContacts() {
    for (const auto &contact: contacts) {
        cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << "\n";
    }
}

int main() {
    int choice;

    do {
        cout << "1. Add Contact\n2. Search Contact\n3. Delete Contact\n4. List Contacts\n5. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                Contact newContact;
                cout << "Enter name: ";
                cin >> newContact.name;
                cout << "Enter phone number: ";
                cin >> newContact.phoneNumber;
                addContact(newContact);
                break;
            }
            case 2: {
                string searchName;
                cout << "Enter name: ";
                cin >> searchName;
                Contact *foundContact = searchContact(searchName);
                if (foundContact) {
                    cout << "Name: " << foundContact->name << ", Phone Number: " << foundContact->phoneNumber << "\n";
                } else {
                    cout << "Contact not found\n";
                }
                break;
            }
            case 3: {
                string deleteName;
                cout << "Enter name: ";
                cin >> deleteName;
                deleteContact(deleteName);
                break;
            }
            case 4:
                listContacts();
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice\n";
                break;
        }
    } while (choice != 5);

    return 0;
}