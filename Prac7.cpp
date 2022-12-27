/* 
Write a program in C++ to use map associative container. 
The keys will be the names of states and the values will be the populations of the states. 
When the program runs, the user is prompted to type the name of a state. 
The program then looks in the map, using the state name as an index and returns the population of the state.
*/
#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
	
	int ch= 1;
	string check;
	map<string,int> mp;
	int key,value;
	
	mp.insert(pair<string,int>("Maharashtra",123));
	mp.insert(pair<string,int>("Punjab",76));
	mp.insert(pair<string,int>("Gujarat",42));
	mp.insert(pair<string,int>("Rajasthan",89));
	mp.insert(pair<string,int>("Bengal",65));
	
	cout<<"\n------LIST OF STATES-----\n*please note that we have data for following states only*\n";
	cout<<"1.Maharashtra\n2.Punjab\n3.Gujarat\n4.Rajasthan\n5.Bengal\n";
	
	do{	
		cout<<"\n1.Display population\n0.Exit\nEnter your choice : ";
		cin>>ch;
		
		switch(ch){
			
			case 1: cout<<"\nEnter the name of state to check population : ";
					cin>>check;
			
					if(mp.count(check)!=0){
						cout<<"POPULATION OF '"<<check<<"' IS : "<<mp.find(check)->second<<" Million"<<endl;
					}
					else {
							cout<<"\nElement not found !";
					}
					break;
			case 0:	cout<<"\n-----GOOD BYE-----";break;
			
			default : cout<<"\nInavlid choice !";
		}

	}while(ch);
}
