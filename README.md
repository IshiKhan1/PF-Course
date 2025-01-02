[Up#include <iostream>
#include <string>
using namespace std;

string suvCars[3]={"Revo" , "V8" , "Fortuner"};
string sedanCars[3]={"Accord" , "Civic" , "Grande"};
string vanCars[3]={"Hiace" , "Bolan" , "Every"};
int suvAvailability[3]={1, 1, 1}; 
int sedanAvailability[3]={1, 1, 1};
int vanAvailability[3]={1, 1, 1}; 

string rentedCar= "";
string customerName= "";
string customerPhone= "";
string customerCNIC= "";
int main() {
    int choice;
    cout<<"Welcome to Rent a Car System!"<<endl;
    do {
        cout<<endl<<"Menu:"<<endl;
        cout<<"1. Display available cars"<<endl;
        cout<<"2. Rent a car"<<endl;
        cout<<"3. Return a car"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if (choice == 1) {
            cout<<endl<<"Available Cars:"<<endl;
            cout<<"SUVs:"<<endl;
            for(int i=0;i<3;i++) {
                if (suvAvailability[i] > 0) {
                    cout<<suvCars[i]<<endl;
                }
            }
            cout<<"Sedans:"<<endl;
            for(int i=0;i<3;i++) {
                if(sedanAvailability[i] > 0) {
                    cout<< sedanCars[i] <<endl;
                }
            }
            cout<<"Vans:"<<endl;
            for(int i=0;i<3;i++) {
                if(vanAvailability[i] > 0) {
                    cout<<vanCars[i]<<endl;
                }
            }
        }
        else if(choice == 2) {
            if(rentedCar != "") {
                cout<<endl<<"You have already rented a "<<rentedCar<<". Please return it before renting another car."<<endl;
                continue;
            }
            cout<<endl<<"Enter your name: ";
            cin.ignore(); 
            getline(cin, customerName);
            cout<<"Enter your phone number: ";
            getline(cin, customerPhone);
            cout<<"Enter your CNIC: ";
            getline(cin, customerCNIC);
            cout<<endl<<"Enter the category to rent (SUV, Sedan, Van): ";
            string category;
            cin>>category;
            if (category == "SUV" || category == "suv") {
                cout<<"Available SUVs to rent:"<<endl;
                for(int i=0;i<3;i++) {
                    if (suvAvailability[i] > 0) {
                        cout<<i + 1<<". "<<suvCars[i]<<endl;
                    }
                }
                int choiceCar;
                cout<<"Choose the SUV you want to rent: ";
                cin>>choiceCar;
                if (choiceCar >= 1 && choiceCar <= 3 && suvAvailability[choiceCar - 1] > 0) {
                    suvAvailability[choiceCar - 1]--;
                    rentedCar=suvCars[choiceCar - 1];
                    cout<<"You have rented "<<rentedCar<<". Please return it on time."<<endl;
                } else {
                    cout<<"Invalid choice or car not available."<<endl;
                }
            } 
            else if(category == "Sedan" || category == "sedan") {
                cout<<"Available Sedans to rent:"<<endl;
                for (int i=0;i<3;i++) {
                    if (sedanAvailability[i] > 0) {
                        cout<<i+1<< "."<<sedanCars[i]<<endl;
                    }
                }
                int choiceCar;
                cout<<"Choose the Sedan you want to rent: ";
                cin>>choiceCar;
                if (choiceCar >= 1 && choiceCar <= 3 && sedanAvailability[choiceCar - 1] > 0) {
                    sedanAvailability[choiceCar - 1]--;
                    rentedCar = sedanCars[choiceCar - 1];
                    cout<<"You have rented "<<rentedCar<<". Please return it on time."<<endl;
                } else {
                    cout<<"Invalid choice or car not available."<<endl;
                }
            } 
            else if(category == "Van" || category == "van") {
                cout<<"Available Vans to rent:"<<endl;
                for(int i = 0; i < 3; i++){
                    if(vanAvailability[i] > 0) {
                        cout<<i+1<<". "<<vanCars[i]<<endl;
                    }
                }
                int choiceCar;
                cout<<"Choose the Van you want to rent: ";
                cin>>choiceCar;
                if (choiceCar >= 1 && choiceCar <= 3 && vanAvailability[choiceCar - 1] > 0) {
                    vanAvailability[choiceCar - 1]--;
                    rentedCar = vanCars[choiceCar - 1];
                    cout<<"You have rented "<<rentedCar<<". Please return it on time."<<endl;
                } else {
                    cout<<"Invalid choice or car not available."<<endl;
                }
            } 
            else {
                cout<<"Invalid category. Please choose SUV, Sedan, or Van."<<endl;
            }
        } 
        else if (choice == 3) {
            if (rentedCar == "") {
                cout<<endl<<"You have not rented any car to return."<<endl;
                continue;
            }
            cout<<endl<<"Returning your rented "<<rentedCar<<" Thank you, "<<customerName<< "!" <<endl;
            for (int i = 0; i < 3; i++) {
                if (rentedCar == suvCars[i]) {
                    suvAvailability[i]++;
                    break;
                }
                if (rentedCar == sedanCars[i]) {
                    sedanAvailability[i]++;
                    break;
                }
                if (rentedCar == vanCars[i]) {
                    vanAvailability[i]++;
                    break;
                }
            }
            rentedCar = "";
            customerName = "";
            customerPhone = "";
            customerCNIC = "";
            cout<<endl<<"Would you like to give feedback? (yes/no): ";
            string feedbackChoice;
            cin>>feedbackChoice;
            if(feedbackChoice == "yes" || feedbackChoice == "Yes") {
                cout << "1 for Average :"<<endl;
                cout<< "2 for Good :" <<endl;
                cout<<"3 for Excellent :"<< endl;
                int feedback;
                cin>>feedback;
                if (feedback == 1) {
                    cout<<"Thank you for your feedback! We're sorry your experience was average. We'll strive to improve."<<endl;
                } else if (feedback == 2) {
                    cout<<"Thank you for your feedback! We're glad you had a good experience."<<endl;
                } else if (feedback == 3) {
                    cout<<"Thank you for your feedback! We're thrilled you had an excellent experience!"<<endl;
                } else {
                    cout<<"Invalid feedback option. Please rate between 1 and 3 next time."<< endl;
                }
            } else if (feedbackChoice == "no" || feedbackChoice == "No") {
                cout<<"Thank you! Feedback is optional, and we hope to see you again soon."<<endl;
            } else {
                cout<<"Invalid choice. Feedback option skipped." <<endl;
            }
        } 
        else if (choice == 4) {
            cout<<"Thank youfor using Rent-a-Car System. Goodbye!"<<endl;
        } 
        else {
            cout <<"Invalid choice. Please try again."<<endl;
        }
    } while (choice != 4);
    return 0;
}
loading MOIZKHAN renta car  67009 - PF PROJECT .cpp…]()
