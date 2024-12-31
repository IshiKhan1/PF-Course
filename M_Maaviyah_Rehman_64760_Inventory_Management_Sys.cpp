// Project: Inventory Management System
// University: Riphah INternational University
// Team Members: M.Maaviyah Rehman, M.Maaz

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
    string name;
    int quantity;
    double price;
};

vector<Item> inventory;

void displayMenu() {
    cout << "1. Add Item" << endl;
    cout << "2. Update Item" << endl;
    cout << "3. Delete Item" << endl;
    cout << "4. View Inventory" << endl;
    cout << "5. Exit" << endl;
}

void addItem() {
    Item newItem;
    cout << "Enter item name: ";
    cin >> newItem.name;
    cout << "Enter item quantity: ";
    cin >> newItem.quantity;
    cout << "Enter item price: ";
    cin >> newItem.price;
    inventory.push_back(newItem);
    cout << "Item added successfully!" << endl;
}

void updateItem() {
    string itemName;
    cout << "Enter the name of the item to update: ";
    cin >> itemName;
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == itemName) {
            cout << "Enter new quantity: ";
            cin >> inventory[i].quantity;
            cout << "Enter new price: ";
            cin >> inventory[i].price;
            cout << "Item updated successfully!" << endl;
            return;
        }
    }
    cout << "Item not found!" << endl;
}

void deleteItem() {
    string itemName;
    cout << "Enter the name of the item to delete: ";
    cin >> itemName;
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == itemName) {
            inventory.erase(inventory.begin() + i);
            cout << "Item deleted successfully!" << endl;
            return;
        }
    }
    cout << "Item not found!" << endl;
}

void viewInventory() {
    cout << "Inventory List:" << endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << "Name: " << inventory[i].name << ", Quantity: " << inventory[i].quantity << ", Price: $" << inventory[i].price << endl;
    }
}

int main() {
    int choice;
    while (true) {
    	cout << "----->----->----->----->----->----->----->----->-----------------------------------------<-----<-----<-----<-----<-----" << "\n\n";
    	cout << "----->----->----->----->----->----->----->----->-----> Inventory Management System <-----<-----<-----<-----<-----<-----" << "\n\n";
    	cout << "----->----->----->----->----->----->----->----->-----------------------------------------<-----<-----<-----<-----<-----" << "\n\n";
    	cout << "\n";
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateItem();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                viewInventory();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

