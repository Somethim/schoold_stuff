#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
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
    auto newEnd = remove_if(contacts.begin(), contacts.end(),
                            [&](const Contact &contact) { return contact.name == name; });
    if (newEnd != contacts.end()) {
        contacts.erase(newEnd, contacts.end());
        cout << "Contact deleted\n";
    } else {
        cout << "Contact not found\n";
    }
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

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (cin.fail()) {
            cin.clear();
            cout << "Invalid choice\n";
            continue;
        }

        switch (choice) {
            case 1: {
                Contact newContact;
                cout << "Enter name: ";
                getline(cin, newContact.name);
                cout << "Enter phone number: ";
                getline(cin, newContact.phoneNumber);
                addContact(newContact);
                break;
            }
            case 2: {
                string searchName;
                cout << "Enter name: ";
                getline(cin, searchName);
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
                getline(cin, deleteName);
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
