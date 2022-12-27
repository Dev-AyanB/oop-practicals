/* 
Develop a program in C++ to create a database of student’s information system containing the following information: 
Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, 
Telephone number, Driving license no. and other. 
Construct the database with suitable member functions. 
Make use of constructor, default constructor, copy constructor, destructor, static member functions,
friend class, this pointer, inline code and dynamic memory allocation operators-
new and delete as well as exception handling.
*/

#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;

class personalinfo;

class student{
	
	int roll;
	string name,div;
	char class_name;
	static int count;
	public :
		student()
		{
			roll=0;
			name="Empty";
			div="Empty";
			class_name='0';	
		}
		
		void getdata()
		{
			cout<<"\nEnter your roll no : ";
			cin>>roll;
			cout<<"\nEnter your name : ";
			cin>>name;
			cout<<"\nEnter your division : ";
			cin>>div;
			cout<<"\nEnter your class name : ";
			cin>>class_name;
			
			count++;
		}
		
		void putdata(){
			
			cout<<"\nYour Roll no : "<<roll;
			cout<<"\nYour Name : "<<name;
			cout<<"\nYour Division : "<<div;
			cout<<"\nYour Class Name : "<<class_name;
		}
		
		static int getcount()
		{
			return count;
		}
		
		
		
		~student(){
			
			cout<<"\nDestructor is called ";
		}
		
		friend class personalinfo;
};

class personalinfo{
		
	string dob;
	string address;
	double long telephone;
	string bg,dl;
	
	public :
	personalinfo(){
		dob="dd/mm/yy";
		telephone=0000000000;
		bg="Not entered";
		dl="MH00000000";
	}
	
	void getinfo(student* st)
	{
		cout<<"======= NEW STUDENT =======";
		st->getdata();
		cout<<"\nEnter your birthdate : ";
		cin>>dob;
		
		cout<<"\nEnter your address : ";
		cin.get();
		getline(cin,address);
		
		cout<<"\nEnter your telephone number : ";
		cin>>telephone;
		
		cout<<"\nEnter your bloodgroup : ";
		cin>>bg;
		
		cout<<"\nEnter your driving license : ";
		cin>>dl;
	}
	
	inline void displayinfo(student* st)
	{
		st->putdata();
		cout<<"\nYour Birth Date : "<<dob;
		cout<<"\nYour Address : "<<address;
		cout<<"\nYour Telephone : "<<telephone;
		cout<<"\nYour BloodGroup : "<<bg;
		cout<<"\nYour Driving License No. : "<<dl;	
		
	}
	
	
};

int student::count;

int main()
{
	student* s[50];
	personalinfo* p[50];
	
	int n=0;
	int c;
	char ch;
	
	cout<<"\nEnter no of students you want to enter : ";
	cin>>c;
		
	
	do{
		s[n]=new student;	
		p[n]=new personalinfo;
		
		p[n]->getinfo(s[n]);
		
		n++;
		
	}while(n!=c);
	
	cout<<"\nDo you want to display the student data ?\n Enter y for YES and n for NO : ";
	cin>>ch;
	if(ch=='y'||ch=='Y'){
		
		cout<<"\nTOTAL NUMBER OF STUDENTS : "<<student::getcount();
		
		for(int i=0;i<c;i++)
		{
			cout<<"\n=========STUDENT "<<i+1<<"=========";
			p[i]->displayinfo(s[i]);
		}		
	}
	else{
		
		cout<<"========== GOOD BYE ==========";
	}
	for(int i=0;i<c;i++){
		
		delete s[i];
		delete p[i];
	}
	
	return 0;
}
