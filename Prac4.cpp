/* 
Write a C++ program that creates an output file, writes information to it, closes the file, 
open it again as an input file and read the information from the file.
*/
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class student{
	
	string name;
	int roll;
	
	public :
	
	void accept(){
		
		cout<<"\nEnter your name : ";
		cin.get();
		getline(cin,name);
		
		cout<<"\nEnter your roll no : ";
		cin>>roll;
		
		fstream f;
		f.open("Prac4.txt",ios::app);
	
		if(!f){
			cout<<"\nFile not Created !";
		}
		else{
			f<<name<<" ";
			f<<roll<<"\n";
		}
		
		f.close();		
	}
	
	void display(){
		fstream f;
		f.open("Prac4.txt",ios::in);
		
		if(!f){
			cout<<"\nFile doesn't exist !";
		}
		else{
			f>>name;
			f>>roll;
			cout<<"\nName : "<<name<<" ";
			cout<<"Roll No. : "<<roll<<"\n";				
			f.close();
			}			
	}
};

int main(){
	fstream f;
	int ch;
	int t;
	cout<<"\nEnter the No of student you want to enter : ";
	cin>>t;
	student s[t];
	
	f.open("Prac4.txt",ios::app);
	
	cout<<"\n-----------MENU------------";
	do{
		cout<<"\n1.Add student\n2.Display student\n0.Exit\nEnter your choice : ";
		cin>>ch;
		
		switch(ch){
			case 1: 
				for(int i=0;i<t;i++){
					s[i].accept();
					f.write((char*)&s[i],sizeof s[i]);	
				}
				break;
			case 2:
				for(int i=0;i<t;i++){
					cout<<"\n------STUDNET "<<i+1<<"------";
					
 					f.write((char*)&s[i],sizeof s[i]);
					s[i].display();	
				}
			case 0: exit(0);
		}
	}while(ch!=0);
}
	

