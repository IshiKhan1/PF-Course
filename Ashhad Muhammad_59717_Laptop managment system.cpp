// Project: Laptop Shop Management System.
// University: Riphah International University.
// Team Members: Ashhad Muhammad, Zain Mazhar, Awais Asad.
// SAPID: 59717, 62971, 55233.

#include<iostream>

using namespace std;

struct shop {          
    string brand;            
    int price;                  
    int quantity;              
}; 

void menu(){                                 
	cout<<"       1.Admin       "<<endl;
	cout<<"       2.Customer    "<<endl;}


void menuadmin1(){                                 				
	cout<<"       1. Insert brand"<<endl;
    cout<<"       2. Update&Delete section"<<endl;
	cout<<"       0. Main Menu"<<endl;
}


void submenuadmin2(){                                
		cout<<"     1.  View Added brands"<<endl;
		cout<<"     2.  Modify List"<<endl;
		cout<<"     0.  Main Menu"<<endl;
}

void submenuadmin3(){                      
	cout << "   0. Main Menu" << endl;
    cout << "   1. Update brand " << endl;
    cout << "   2. Delete brand from List" << endl;
}
int main()
 {
    int n, choice,totalquantity, total;   
    shop laptop[100]; 
    while(true){  
    	

    	system ("cls");  
menu();           
int option,suboption;   
cin>>option;  
if(option==1){        
	int pin=1234;           
cout<<"    Enter Your Security Code "<<endl;
cin>>pin;
if(pin==1234){
cout<<"    Laptop Shop  "<<endl;
menuadmin1();
cin>>suboption;
if(suboption==1){
	 
   	cout<<"    No of brands to be added   "<<endl;
	cin>>n;
	 for (int i = 0; i < n; i++) {
        cout << "   Enter brand " << i + 1 << " name: "<<endl;
  cin>>laptop[i].brand;                                       
        cout << "   Enter price for brand " << i+1  << endl;      
cin >>laptop[i].price;
        cout<<"Enter Total Quantity for brand no." << i+1<<endl;
cin>>laptop[i].quantity;
}
cout<<"press 0 tdhen Enter to return to main menu"<<endl;
cin.ignore();
cin.get();
}
else if(suboption==2){
	submenuadmin2();
	int select;
	cin>>select;
	switch(select){
		case 1:
			 
    cout << "     Laptop Shop's Menu" << endl;
    for (int i = 0; i < n; i++) {
      
           cout << i + 1 << ". " << laptop[i].brand << "  - Rs" 	<< laptop[i].price	<< "      Available quantity : " << laptop[i].quantity << endl;

    }
cin.ignore();
cin.get();
    break;
    case 2:
    	 for (int i = 0; i < n; i++) {      
        cout << i + 1 << ". " << laptop[i].brand << "   - Rs" 	<< laptop[i].price	<< "      Available quantity : " << laptop[i].quantity << endl;  

    }
    cout<<"    Select brand to Update"<<endl;  
    cin>>choice;
    
submenuadmin3();
    cout << "Enter choice:" << endl;
   int subchoice;
    cin>>subchoice;

    if(subchoice==0)
	{ 
	menu();
	}
	else if(subchoice==1)
	{ 
		  cout << "Enter New brand : " <<endl; 
		       cin >>laptop[choice - 1].brand;

        cout << "Enter New price for brand: " <<endl;
		 cin >>laptop[choice - 1].price;
        cout << "Menu Updated successfully"<<endl;
    }
	else if(subchoice==2){  
		 for (int i = choice - 1; i < n - 1; i++) {
            laptop[i] = laptop[i + 1];
        }
        n--;
        cout << "brand deleted successfully"<<endl;
	}
	break;
	default:
		cout<<"Invalid entry"<<endl;
	break;
	}
	
	
	}
}
else{
	cout<<"   Invalid Code Try Again"<<endl;
}
cin.ignore();
cin.get();
}
else if(option==2){
	cout<<"    1.  Check Shop's offerings "<<endl; 
	cout<<"    2.  Buy "<<endl;
	cout<<"    0.  Main Menu"<<endl;
	
	  cin>>choice;
if(choice==0){
	
	menu();
}	  

else if(choice==1){ 
	  for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << laptop[i].brand << "  - Rs " << laptop[i].price << endl;
    }
    cin.ignore();
    cin.get();
      } 
else if(choice==2){          
  cout << "  Buying Menu " << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << laptop[i].brand << "  - Rs" << laptop[i].price << endl;}
	   
	    cin>>choice;      
    cout  << "   Enter Quantity: "<<endl;
    cin >>totalquantity; 
    total = laptop[choice - 1].price *totalquantity; 
    
  
    if (totalquantity <= laptop[choice - 1].quantity) {

       
        laptop[choice - 1].quantity -=totalquantity;
    
    cout << "  brands:  " << laptop[choice - 1].brand << endl;
    cout << "  Price: Rs  " << laptop[choice - 1].price << endl;
    cout << "  Total Quantity:  " <<totalquantity << endl;
    cout << "Total price: Rs" << total << endl;
	 cin.ignore();
    cin.get();
	}
    else{
    	cout<<"Not Enough Quantity Available"<<endl;
	}
	cin.ignore();
	cin.get();
	}
}
      }}

    	

