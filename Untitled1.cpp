#include<iostream>
using namespace std;
struct travel{ 
	string location;
	int price;
	int seats;
};
void mainmenu(){
	cout<<"Wlcome to Raja Travel";
	cout<<"     \n1. Admin Section       "<<endl;
	cout<<"     2. Passenger Section   "<<endl;
}
void adminmenu(){      
	cout<<"1. add a location"<<endl;
	cout<<"2. update a location"<<endl;
	cout<<"3. view list"<<endl;
	cout<<"4. remove a location"<<endl;
}
void customermenu(){
	cout<<" 1. View List "<<endl;
	cout<<" 2. Book Holidays "<<endl;
}
int main(){
	travel agency[100];     
	int n;
	int tickets;
	int total;
	int option;
	int choice;
	while(true){                  
	mainmenu();
	cin>>option;
	if(option==1){
    int pin=1234;
	cout<<"Enter your Pin"<<endl;
	cin>>pin;
	if(pin==1234){
	adminmenu();                 
	cin>>option;
	if(option==1){                  

	cout<<"How many Locations You Want to add"<<endl;
	cin>>n;
		for(int i=0;i<n;i++){
			cout<<"Enter Location no: "<<i+1<<endl;
			cin>>agency[i].location;
	        cout<<"Enter price for Location No: "<<i+1<<endl;
	        cin>>agency[i].price;
	        cout<<"Enter total no of seats in Location No:  "<<i+1<<endl;
	        cin>>agency[i].seats;
		}
		
	}
	else if(option==2){
		for(int i=0;i<n;i++){       
			cout<<i+1<<":"<<agency[i].location<<endl;
		}
		cout<<"enter location number to update"<<endl;
		cin>>choice;
		cout<<"enter new  name of location "<<endl;
		cin>>agency[choice-1].location;
		cout<<"Enter new Price "<<endl;
		cin>>agency[choice-1].price;
		cout<<"Enter Total no of Seats "<<endl;
		cin>>agency[choice-1].seats;
	}
	else if(option==3){     
		for(int i=0;i<n;i++){
			cout<<i+1<<": "<<agency[i].location <<", Rs: "<<agency[i].price<<","<<agency[i].seats<<" Seats left"<<endl;
		}
	}
	else if(option==4){  
		for(int i=0;i<n;i++){
			cout<<i+1<<"."<<agency[i].location<<endl;
		}
		cout<<"enter the location number you want to delete"<<endl;
		break;
		cin>>choice;
	for(int i=choice-1;i<n-1;i++){
			agency[i]=agency[i+1];
	}
	n--;
		cout<<"Location deleted succesfully"<<endl;
		
	
	}
}
else{
	cout<<"Incorrect Pin Try Again "<<endl;
}
}

else if(option==2){         
	customermenu();
	cin>>option;
	if(option==1){            
		for(int i=0;i<n;i++){
			cout<<i+1<<" "<<agency[i].location<<" , Rs-"<<agency[i].price<<", Seats left"<<agency[i].seats<<endl;
		}
	}
	else if(option==2){    
	for(int i=0;i<n;i++){
			cout<<i+1<<" "<<agency[i].location<<" , Rs-"<<agency[i].price<<", Seats left: "<<agency[i].seats<<endl;
		}
		cout<<"Select your Package "<<endl;
		string cities[]={"Islamabad", "Lahore", "Karachi"};
                for (int i=0; i<3; i++) {
                    cout<<i+1<<". "<<cities[i]<<endl;
                }
		cin>>choice;
		
                if (choice>0 && choice <= 3) {
                    cout<<"You selected: " <<cities[choice - 1]<<endl;
                    cout<<"Booking complete. Program will now exit."<<endl;
                    break;
                } else {
		cout<<"Booking Information"<<endl;
			cout<<"Package: "<<agency[choice-1].location<<endl;
			
		cin>>tickets;
		total=agency[choice-1].price*tickets;
		if(tickets<=agency[choice-1].seats){
			agency[choice-1].seats-=tickets;
			cout<<"price per Seat "<<agency[choice-1].price<<endl;
			cout<<"No of Seats Booked  "<<tickets<<endl;
			cout<<"Total Bill Rs- "<<total<<endl;
		cout<<"Please Enter No of Tickets "<<endl;
		
		}
		else{
			cout<<"Not Enough Seats Available "<<endl;
			
		}
		
		
	}
	}