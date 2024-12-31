#include<iostream>
using namespace std;
    long long calculate(long long a,long long b,char op){
    	switch (op){
    		case'+':
    		
			 return a+b;
    		case'-':
    		
			
			 return a-b;
    		case'*':
		
			 return a*b;
    		case'%': 
		
			return a%b;
    		case'/': 
    		if(b != 0){
    		
    			return a/b;
			}
			else {
				cout<<"ERROR : DIVISION BY ZERO"<<endl;
			}
		}
    	
    	
	}
	double calculate(double a,double b,char op){
			switch (op){
    		case'+':
    		
			 return a+b;
    		case'-':
    		
			
			 return a-b;
    		case'*':
		
			 return a*b;

		
			
    		case'/': 
    		if(b != 0){
    		
    			return a/b;
		
	}
}}

        	double calculate(long long a,double b,char op){
		switch (op){
    		case'+':
    		
			 return a+b;
    		case'-':
    		
			
			 return a-b;
    		case'*':
		
			 return a*b;
    
		
		
    		case'/': 
    		if(b != 0){
    		
    			return a/b;
		}
	}}
		double calculate(double a,long long b,char op){
		switch (op){
    		case'+':
    		
			 return a+b;
    		case'-':
    		
			
			 return a-b;
    		case'*':
		
			 return a*b;
    	
    		case'/': 
    		if(b != 0){
    		
    			return a/b;
			}
		}
	}
	int main(){
		double num1,num3,res;
	    char op;
	    int opt;
		double num2;
		cout<<"        "<<endl;
		cout<<"WELCOME TO CALCULATOR"<<endl;
			
		    cout<<"ENTER YOUR CHOICE TO ADD=  +  ,  SUBTRACT=  -  , MULTIPLY=  *  ,  DIVIDE=  /" <<endl;
		    cin>>op;
		    cout<<"ENTER NUMBER 1 "<<endl;
			cin>>num1; 
		     
		    cout<<"ENTER NUMBER 2 "<<endl;
			cin>>num2; 
			while(opt!=3){
			
		    
	    if(static_cast<long long>(num1)==num1 && static_cast<long long>(num2)==num2){
       res=calculate(static_cast<long long>(num1), static_cast<long long>(num2),op);
        cout << "Result: " << res << endl;
    }
        else if(static_cast<long long>(num1)==num1){
        res= calculate(static_cast<long long>(num1), num2,op) ;
        cout << "Result: " <<res<< endl;
    }   
        else if(static_cast<long long>(num2)==num2 ){
        res= calculate(num1, static_cast<long long>(num2),op);
        cout << "Result: " <<res << endl;
        
}       else{
	    res= calculate(num1, num2,op);
       
        cout << "Result: " <<res << endl;
}

      cout<<"ENTER (1) IF YOU WANT FURTHER CALCULATION  "<<endl;
     
      
      
       cout<<"ENTER (2) IF YOU WANT new CALCULATOR "<<endl;
       
        cout<<"ENTER (3) IF YOU TO TERMINATE CALCULATION"<<endl;
      
     cin>>opt;
           if(opt==1){
    	   
    		 cout<<"ENTER YOUR CHOICE TO ADD=  +  SUBTRACT=  -  MULTIPLY=  *  DIVIDE=  /  MODULUS FOR INT ONLY=   % " <<endl;
    		cin>>op;
    			cout<<"enter further num to proceed calculation"<<endl;
    		cin>>num3;
    		cout<<calculate(res,num3,op)<<endl;
    	

	}
	 
      else if(opt==2){
      	 
		    cout<<"ENTER YOUR CHOICE TO ADD=  +  SUBTRACT=  -  MULTIPLY=  *  DIVIDE=  /  MODULUS FOR INT ONLY=   % " <<endl;
		     cin>>op;
		     cout<<"ENTER NUMBER 1 "<<endl;
			cin>>num1;
		    cout<<"ENTER NUMBER 2 "<<endl;
			cin>>num2; 
			cout<<"result "<<res<<endl;
	  }
      
	     else if(opt==3) {
		cout<<"THANKS FOR USING CALCULATOR "<<endl;
		break ;
	
      } 

  
      else {
	      	cout<<"CHOSE A VALID NUMBER (1) OR (2) OR (3)"<<endl;
}
  }

}
