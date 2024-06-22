#include <algorithm>
#include <cstdlib> // for system("cls")
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Contact {
  int id;
  string name;
  string phone;
  string category;
  string email;
};

vector<Contact> contacts;
int nextId = 1;

void clearScreen() { system("cls"); }

void printContacts(const vector<Contact> &list) {
  for (const auto &contact : list) {
    cout << "ID: " << contact.id << ", Name: " << contact.name
         << ", Phone: " << contact.phone << ", Category: " << contact.category
         << ", Email: " << contact.email << endl;
  }
}

void viewContacts() {
  clearScreen();
  cout << "Select category to view:\n";
  cout << "A. Office\nB. Personal\nC. Business\n";
  char choice;
  cin >> choice;
  vector<Contact> filtered;
  switch (choice) {
  case 'A':
  case 'a':
    for (const auto &contact : contacts) {
      if (contact.category == "Office")
        filtered.push_back(contact);
    }
    break;
  case 'B':
  case 'b':
    for (const auto &contact : contacts) {
      if (contact.category == "Personal")
        filtered.push_back(contact);
    }
    break;
  case 'C':
  case 'c':
    for (const auto &contact : contacts) {
      if (contact.category == "Business")
        filtered.push_back(contact);
    }
    break;
  default:
    cout << "Invalid choice!\n";
    return;
  }
  printContacts(filtered);
}

bool isDuplicate(const string &name, const string &phone) {
  for (const auto &contact : contacts) {
    if (contact.name == name && contact.phone == phone)
      return true;
  }
  return false;
}

void addContact() {
  if (contacts.size() >= 15) {
    cout << "Storage full!\n";
    return;
  }
  Contact newContact;
  newContact.id = nextId++;
  cout << "Enter name: ";
  cin >> newContact.name;
  cout << "Enter phone: ";
  cin >> newContact.phone;
  if (isDuplicate(newContact.name, newContact.phone)) {
    cout << "Duplicate entry!\n";
    return;
  }
  cout << "Enter category (Office/Personal/Business): ";
  cin >> newContact.category;
  cout << "Enter email: ";
  cin >> newContact.email;
  contacts.push_back(newContact);
}

void dialContact() {
  clearScreen();
  cout << "Select a contact to dial:\n";
  for (const auto &contact : contacts) {
    cout << contact.name << endl;
  }
  string name;
  cin >> name;
  for (const auto &contact : contacts) {
    if (contact.name == name) {
      for (char digit : contact.phone) {
        cout << digit << flush;
        // Simulate dial sound, can be replaced with actual sound code
        cout << "\a";
        system("timeout /t 1 > nul");
      }
      cout << endl;
      return;
    }
  }
  cout << "Contact not found!\n";
}

void modifyContact() {
  clearScreen();
  cout << "Enter name of contact to modify: ";
  string name;
  cin >> name;
  for (auto &contact : contacts) {
    if (contact.name == name) {
      cout << "Enter new phone: ";
      cin >> contact.phone;
      cout << "Enter new category: ";
      cin >> contact.category;
      cout << "Enter new email: ";
      cin >> contact.email;
      return;
    }
  }
  cout << "Contact not found!\n";
}

void deleteContact() {
  clearScreen();
  cout << "Enter name of contact to delete: ";
  string name;
  cin >> name;
  for (auto it = contacts.begin(); it != contacts.end(); ++it) {
    if (it->name == name) {
      contacts.erase(it);
      cout << "Contact deleted!\n";
      return;
    }
  }
  cout << "Contact not found!\n";
}

int main() {
  while (true) {
    clearScreen();
    cout << "<Phone Contact Management System>\n";
    cout << "---------------------------------\n";
    cout << "|1. View Contacts               |\n";
    cout << "|2. Add Contact                 |\n";
    cout << "|3. Dial Contact                |\n";
    cout << "|4. Modify Contact              |\n";
    cout << "|5. Delete Contact              |\n";
    cout << "|6. Exit Program                |\n";
    cout << "---------------------------------\n";
    cout << ">>Enter your choice:  ";
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
      viewContacts();
      break;
    case 2:
      addContact();
      break;
    case 3:
      dialContact();
      break;
    case 4:
      modifyContact();
      break;
    case 5:
      deleteContact();
      break;
    case 6:
      return 0;
    default:
      cout << "Invalid choice!\n";
    }
    system("pause");
  }
  return 0;
}
