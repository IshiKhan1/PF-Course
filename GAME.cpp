#include<iostream>  
#include<cstdlib>  //header file used to define general purpose functions//
using namespace std;
int main()
{

	     	          //**Rules of the game**//
	  cout<<"\t\t"<<"GAMES RULES:"<<endl;
	  cout<<"Rock beats scissors"<<endl;
	  cout<<"scissors beats paper"<<endl;
	  cout<<"paper beats Rock"<<endl;
	  cout<<endl; 
	int x;    
	cout<<"Enter The Mode:  "<<endl;   
	cout<<"press 1 for multiplayer mode"<<endl;  // for multiplayer mode press 1 //
	cout<<"press 2 for single player mode"<<endl; // for singleplayer mode press 2 //
	cin>>x;
	cout<<endl;
	 
	 
	switch(x)         
	   case 1:          //  multiplayer mode //
	   {          
	       {  
	       	int draw=0; 
	       	int win_1=0;
	       	int win_2=0;
	   	char again;
		string name_1,name_2;    
		cout<<"Player 1 enter your name:";
		cin>>name_1;                                      
		cout<<"Player 2 enter your name:";
		cin>>name_2;                                     
	    system("CLS");     
		do
		{
			int user_1,user_2;
			
			cout<<"--------------------------------------------------------------"<<endl;
			            cout<<"Lets play Rock paper  scissors game"<<endl;
			cout<<"--------------------------------------------------------------"<<endl;
			
			
			cout<<name_1<<endl;
			cout<<"what do you want to choose:"<<endl;
			cout<<"press 1 for Rock"<<endl;
			cout<<"press 2 for paper"<<endl;
			cout<<"press 3 for scissors"<<endl;
			cin>>user_1;           
            cout<<endl;
            
			system("CLS");
			
		cout<<"------------------------------------------------------------------"<<endl;
		                cout<<"Lets play Rock paper scissors game"<<endl;
		cout<<"------------------------------------------------------------------"<<endl;
		
		
		cout<<name_2<<endl;
		cout<<"what do you want to choose:"<<endl;
		cout<<"press 1 for  Rock"<<endl;
		cout<<"press 2 for paper"<<endl;
		cout<<"press 3 for scissor"<<endl;
		cin>>user_2;          
		cout<<endl;
		
		system("CLS");
		
			cout<<"-----------------------------------------------------"<<endl;
		            cout<<"Lets play Rock paper scissors game"<<endl;
		            cout<<name_1<<"      VS    "<<name_2<<endl;
		    cout<<"-----------------------------------------------------"<<endl;
		    cout<<endl;
		if (user_1==1 && user_2==1)        //when both the player choose is Rock //
		{
			cout<< name_1<<"\t" << "chose Rock" <<endl;
			cout<< name_2<<"\t" << "chose Rock" <<endl;
			cout<< " It,s a  Draw" <<endl;
			draw++;
		}
		else if(user_1==2 && user_2==2)    //when both player choose is paper  //
		{
			cout<<name_1<<"\t"<<"chose paper"<<endl;
			cout<<name_2<<"\t"<<"chose paper"<<endl;
			cout<<"It,s a draw"<<endl;
			draw++;
		}
		else if(user_1==2 && user_2==3)  // when first player choose paper and second player choose scissors //
		{
			cout<<name_1<<"\t"<<endl;
			cout<<name_2<<"\t"<<endl;
			cout<<"player 2 win"<<endl;
			win_2++;
		}
		else if(user_1==3 && user_2==3)      //when both player choose is scissors //
		{
			cout<<name_1<<"\t"<<"chose scissors"<<endl;
			cout<<name_2<<"\t"<<"chose scissors"<<endl;
			cout<<"It,s a draw"<<endl;
			draw++;
		}
	   else if(user_1==1 && user_2==2 )   // when first player choose is Rock and second player choose is paper //
		{
		cout<<name_1<<"\t"<<"chose Rock"<<endl;
		cout<<name_2<<"\t"<<"chose paper"<<endl;
		cout<<"player 2 win"<<endl;
		win_2++;	
		}
		else if (user_1==1 && user_2==3)    //when first player choose is Rock and second player choose is scissors //
		{
			cout<<name_1<<"\t"<<"chose Rock"<<endl;
			cout<<name_2<<"\t"<<"chose scissors"<<endl;
			cout<<"player 1 win"<<endl;
			win_1++;
		}
		else if(user_1==2 && user_2==1)   // when player one choose is paper and second player choose is Rock //
		{
			cout<<name_1<<"\t"<<"chose paper"<<endl;
			cout<<name_2<<"\t"<<"chose Rock"<<endl;
			cout<<"player 1 win"<<endl;
			win_1++;
		}
	    else if(user_1==3 && user_2==1)  //when player one choose is scissors and second player choose is Rock //
		{
			cout<<name_1<<"\t"<<"chose scissors"<<endl;
			cout<<name_2<<"\t"<<"chose Rock"<<endl;
			cout<<"player 2 win"<<endl;
			win_2++;
		}
		else if(user_1==3 && user_2==2)  //when player one choose is scissors and second player choose is paper //
		{
			cout<<name_1<<"\t"<<"chose scissors"<<endl;
			cout<<name_2<<"\t"<<"chose paper"<<endl;
			cout<<"player 1 win"<<endl;
			win_1++;
		}
		else
		{
			cout<<"you didn,t select from the given option"<<endl;
		}
		cout<<endl;
		cout<<name_1<<" Total Wins="<<win_1<<endl;
		cout<<name_2<<" Total Wins="<<win_2<<endl;
		cout<<" Total draws="<<draw<<endl;
		cout<<endl;
		
		cout<<"Do you want to play again"<<endl;   
		cout<<"for play again press 'y'or 'Y'"<<endl;
		cin>>again;
		system("CLS"); 
	}while( again=='y' || again=='Y');
	
	break;
}

  case 2:      //when player choose single mode //
   {
   	{
   		int win=0;
   		int lose=0;
   		int draw=0;
   		string name;
   		char again;
   		cout<<"enter your name:";
   		cin>>name;
   		system("CLS");
   		do
   		{
   			int user;
   			
   			cout<<"-----------------------------------------------------"<<endl;
   			      cout<<"Let,s play Rock paper  scissors game"<<endl;
   			cout<<"-----------------------------------------------------"<<endl;
			  
			  cout<<"what do you want to choose:"<<endl;
			  cout<<"press 1 for Rock"<<endl;
			  cout<<"press 2 for paper"<<endl;
			  cout<<"press 3 for scissors"<<endl;
			  cin>>user;     
		      cout<<endl;
			  system("CLS");
			    
			int computer=rand() %3+1;
			 
			cout<<"-----------------------------------------------------"<<endl;
   			      cout<<"Let,s play Rock paper  scissors game"<<endl;
   			cout<<"-----------------------------------------------------"<<endl;
   			
			 if (computer==1 && user==1)  
			 {
			 	cout<<user<<"\t"<<"you chose Rock "<<endl;
			 	cout<<computer<<"\t"<<"computer chose Rock"<<endl;
			 	cout<<"It,s a draw"<<endl;
			 	draw++;
					} 
			else if(computer==2 && user==2) 
			{
				cout<<user<<"\t"<<"you chose paper"<<endl;
				cout<<computer<<"\t"<<"copmuter chose is paper"<<endl;
				cout<<"It,s a draw"<<endl;
				draw++;
				  }    
		   else if(computer==3 && user==3) 
		   {
		   	cout<<user<<"\t"<<"you chose is scissors"<<endl;
		   	cout<<computer<<"\t"<<"computer chose is scissors"<<endl;
		   	cout<<"It,s a draw"<<endl;
		   	draw++;
			 }  
			else if(computer==1 && user==2) 
			{
				cout<<user<<"\t"<<"you chose paper"<<endl;
				cout<<computer<<"\t"<<"computer choose is Rock"<<endl;
				cout<<"player win "<<endl;
				win++;
			}
			else if(computer==1 && user==3) 
			{
				cout<<user<<"\t"<<"you chose scissors"<<endl;
				cout<<computer<<"\t"<<"computer choose is Rock"<<endl;
				cout<<"computer win"<<endl;
				lose++;
			}
			else if(computer==2 && user==1) 
			{
				cout<<user<<"\t"<<"you chose rock"<<endl;
				cout<<computer<<"\t"<<"computer choose  paper"<<endl;
				cout<<"computer win"<<endl;
				lose++;
			}
			else if(computer==3 && user==1) 
			{
				cout<<user<<"\t"<<"you chose Rock"<<endl;
				cout<<computer<<"\t"<<"computer choose  scissors"<<endl;
				cout<<"player  win"<<endl;
				win++;
			}
			else if(computer==2 && user==3) // when computer choose is paper and player choose is scissors //
			{
				cout<<user<<"\t"<<"you chose scissors"<<endl;
				cout<<computer<<"\t"<<"computer chose paper"<<endl;
				cout<<"player win"<<endl;
				win++;
			}
			else if(computer==3 && user==2) // when computer choose is scissors and player choose is paper //
			{
				cout<<user<<"\t"<<"you chose paper"<<endl;
				cout<<computer<<"\t"<<"computer chose scissors"<<endl;
				cout<<"computer win"<<endl;
				lose++;
			}
			else 
			{
				cout<<"your move is invaild"<<endl;
			}
          cout<<endl;
          
			cout<<name<< " Total loses="<<lose<<endl;
			cout<<name<< " Total draws="<<draw<<endl;
			cout<<name<<" Total Wins="<<win<<endl;
			cout<<endl;
			
			
			cout<<"Do you want to play again"<<endl;
			cout<<"yes  then press 'y' or 'Y'"<<endl;
			cin>>again;
			system("CLS");
			
		   }while( again=='y' || again=='Y');
		   break;
	   }
}
}
}

