#include <iostream>
#include <string>
using namespace std;

const int MAX_PROPERTIES = 100;

struct Property {
    string address;
    string type;
    int bedrooms;
    int bathrooms;
    double price;
};

Property properties[MAX_PROPERTIES];
int total_property = 0;

void displayMenu();
void addProperty();
void viewProperties();
void searchProperties();
void applyDiscount();

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addProperty();
                break;
            case 2:
                viewProperties();
                break;
            case 3:
                searchProperties();
                break;
            case 4:
                applyDiscount();
                break;
            case 5:
                cout << "Exiting the application." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "                                ****SHANDAAR PROPERTIES****                            " << endl;
	cout << "                               ****Level Level Ki Baat Na Kar****                            " << endl;  
    cout << "                          ***%%% PROPERTY BUSINESS APPLICATION ***%%%                  " <<endl;
    cout <<endl;
    cout << "1. Add Property" << endl;
    cout << "2. View All Properties" << endl;
    cout << "3. Search Properties by Price Range" << endl;
    cout << "4. Apply Discount to All Properties" << endl;
    cout << "5. Exit" << endl;
    cout << " ----------------------------- "<<endl;
    cout << " ----------------------------- "<<endl;
    
    cout << "Enter your choice: ";
}

void addProperty() {
    if (total_property < MAX_PROPERTIES) {
        Property newProperty;
        cout << "Enter address: "<<endl;
        cout << "-------------------"<<endl;
        cin >> newProperty.address;
        cout << "-------------------"<<endl;
        cout << "Enter type (e.g., house, apartment): "<<endl;
        cin >> newProperty.type;
        cout << "-------------------"<<endl;
        cout << "Enter number of bedrooms: "<<endl;
        cin >> newProperty.bedrooms;
        cout << "-------------------"<<endl;
        cout << "Enter number of bathrooms: ";
        cin >> newProperty.bathrooms;
        cout << "-------------------"<<endl;
        cout << "Enter price: "<<endl;
        cin >> newProperty.price;
        cout << "-------------------"<<endl;
        properties[total_property++] = newProperty;
        
        cout << "-------------------"<<endl;
        cout << "Property added successfully!" << endl;
    } else {
        cout << "Sorry, maximum number of properties reached." << endl;
        cout << "REMAINING LAND BELONGS TO IMPORTED HAKUMAT ";
    }
}

void viewProperties() {
    if (total_property == 0) {
        cout << "No properties to display." << endl;
    } else {
        cout << "-------------------" << endl;
        cout << "*** Property List ***" << endl;
        cout << "-------------------" << endl;

        for (int i = 0; i < total_property; ++i) {
            cout << "Property " << i + 1 << ":" << endl;
            cout << "Address: " << properties[i].address << endl;
            cout << "Type: " << properties[i].type << endl;
            cout << "Bedrooms: " << properties[i].bedrooms << endl;
            cout << "Bathrooms: " << properties[i].bathrooms << endl;
            cout << "Price: $" << properties[i].price << endl;
            cout << "-------------------------" << endl;
        }
    }
}

void searchProperties() {
    double minPrice, maxPrice;
    cout << "Enter minimum price: ";
    cin >> minPrice;
    cout << "Enter maximum price: ";
    cin >> maxPrice;

    bool found = false;
    for (int i = 0; i < total_property; ++i) {
        if (properties[i].price >= minPrice && properties[i].price <= maxPrice) {
        	cout << "-------------------"<<endl;
            cout << "Property " << i + 1 << ":" << endl;
            cout << "Address: " << properties[i].address << endl;
            cout << "Type: " << properties[i].type << endl;
            cout << "Bedrooms: " << properties[i].bedrooms << endl;
            cout << "Bathrooms: " << properties[i].bathrooms << endl;
            cout << "Price: $" << properties[i].price << endl;
            cout << "-------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "-------------------"<<endl;
        cout << "No properties found in the given price range." << endl;
        cout << "OCCUPIED BY LUMBER 1 "<<endl;
    }
}

void applyDiscount() {
    if (total_property == 0) {
    	cout << "-------------------"<<endl;
        cout << "No properties to apply a discount." << endl;
        return;
    }

    double discount;
    cout << "Enter discount percentage: ";
    cin >> discount;

    for (int i = 0; i < total_property; ++i) {
        properties[i].price -= properties[i].price * (discount / 100);
    }
    cout<<"-------------------"<<endl;
	cout<<"-------------------"<<endl;
    cout<<"Discount applied to all properties." << endl;
    cout<<"SHERA AUR KUCH MERAY LAIQ "<<endl;
    
}

