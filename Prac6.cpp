/* 
Write C++ program using STL for sorting and searching user defined records 
such as personal records (Name, DOB, Telephone number etc) using vector container.
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

class info{
	
	public : 
	
	string name;
	string dob;
	double long telephone;
	int code;
		
		info(){
			name="Not Entered";
			dob="00/00/0000";
			telephone=0000000000;
		}
		
		bool operator==(const info& i1) //Boolean operators allow you to create more complex conditional statements
 		{
 			if(code==i1.code) //operator will return 1 if the comparison is true, or 0 if the comparison is false
 				return 1;
		 return 0;
 		}
 		bool operator<(const info& i1)
 		{
 			if(code<i1.code) //operator will return 1 if the comparison is true, or 0 if the comparison is false
				return 1;
 			return 0;
		}
		
};
vector<info> i;
void accept(){
			
	info t;
	
	cout<<"Enter user id : ";
	cin>>t.code;
			
	cout<<"Enter the name : ";
	cin>>t.name;
			
	cout<<"Enter your BirthDate : ";
	cin>>t.dob;
			
	cout<<"Enter your telephone no : ";
	cin>>t.telephone;	
			
	i.push_back(t);
				
}
void search(){
	
	vector<info>::iterator p;
 	info i1;
 	cout<<"\nEnter Item Code to search : ";
 	cin>>i1.code;
 	p=find(i.begin(),i.end(),i1);
 	if(p==i.end())
 	{
		 cout<<"\nNot found!!!";
 	}
 	else
 	{
 		cout<<"\nFound!!!";
 	}
}
void print(info& it){
	
	cout<<"\n\n\nID : "<<it.code;
	cout<<"\nNAME : "<<it.name;
	cout<<"\nBIRTHDATE : "<<it.dob;
	cout<<"\nTELEPHONE : "<<it.telephone;
}
void display(){
	
	for_each(i.begin(),i.end(),print);
	
}
bool compare(const info &i1, const info &i2)
{
 	return i1.code < i2.code;
}

int main(){
	int ch;
	
	do 
	{
		cout<<"\n\n1.Accept Info\n2.Search User\n3.Sort all data\n4.Display\n0.Exit\nEnter your Choice : ";
		cin>>ch;
		
		switch(ch){
			case 1: accept();break;
			case 2:search();break;
			case 3:sort(i.begin(),i.end(),compare);
				   display();break;
			case 4:display();break;
			case 0:exit(1);break;
		}
	}while(ch!=0);	
}
