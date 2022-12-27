/* 
Imagine a publishing company which does marketing for book and audio cassette versions. 
Create a class publication that stores the title (a string) and price (type float) of publications. 
From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). 
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. 
If an exception is caught, replace all the data member values with zero values.
*/
#include<iostream>
#include<string>

using namespace std;

class publication{
	
	string name;
	float price;
	
	public : 
	publication(){
		
		price=00.00;
	}
	void getdata(){
		
		cout<<"Enter the name : ";
		cin>>name;
		
		cout<<"Enter the price : ";
		cin>>price;
	}
	
	void display(){
		
		cout<<"\n\nBook Name : "<<name;
		cout<<"\nPrice : "<<price;
	}
};

class book:public publication{
	int pagecount;
	
	public :
		book(){
			pagecount=0;
		}
		
		void getpagecount(){
			
			cout<<"Enter the page count : ";
			cin>>pagecount;
			
			try{
				if(pagecount==0){
				throw pagecount;
				}		
			}
			catch(int x){
				cout<<"\n!Invalid pagecount";
			}
		}
		
		void displaybook(){
			
			display();
			
			cout<<"\nPageCount : "<<pagecount;
			
		}
};

class tape:public publication{
	float duration;
	
	public :
		tape(){
			duration=0.0;
		}
		
		void getduration(){
			
			cout<<"Enter the duration : ";
			cin>>duration;
			
			try{
				
				if(duration==0.0){
					
					throw duration;
				}
			}
			catch(float d){
				
				cout<<"\n!Invalid duration entered";
			}
		
		}
		
		void displaytape(){
			
			display();
			
			cout<<"\nDuration of tape : "<<duration;			
		}
};

int main(){
	
	int ch;
	int i=0;
	int j=0;
	book* b[10];
	tape* t[10];
	
	do{
		cout<<"\n1.Add book\n2.Add tape\n3.Display book\n4.Display tape\n0.Exit\nEnter the Choice : ";
		cin>>ch;

		if(ch==1){
			b[i]=new book;
			b[i]->getdata();
			b[i]->getpagecount();
			i++;
		}
		else if(ch==2){
			t[j]=new tape;
			 t[j]->getdata();
			 t[j]->getduration();
			 j++;
		}
		else if(ch==3){
			cout<<"\n\n--------------------------Book List--------------------------------";
			for(int n=0;n<i;n++){
				b[n]->displaybook();
			}
			cout<<"\n\n-----------------------------End-------------------------------";
		}
		else if(ch==4){
			cout<<"\n\n--------------------------Tape List--------------------------------";
			for(int n=0;n<j;n++){
				t[n]->displaytape();
			}
			cout<<"\n\n-----------------------------End-------------------------------";	
		}
	}while(ch!=0);
}
