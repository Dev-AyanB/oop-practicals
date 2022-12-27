/*
Implement a class Complex which represents the Complex Number data type. Implement the following 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overload operator+ to add two complex numbers. 
3. Overload operator* to multiply two complex numbers. 
4. Overload operators << and >> to print and read Complex Numbers.
*/

#include<iostream>

using namespace std;

class Complex{
	
	int real;
	int img;
	
	public:
		
		Complex()
		{
			real=0;
			img=0;
		}
		Complex(int r , int i){
			
			real=r;
			img=i;	

		}
		
		Complex operator +(Complex c)
		{
			Complex temp;
			
			temp.real=real+c.real;
			temp.img=img+c.img;
			
			return temp;
		}
		
		Complex operator *(Complex c)
		{
			Complex temp;
			
			temp.real=real * c.real - img * c.img;
			temp.img=real * c.img+ img * c.real;
			
			return temp;
		}
		
		friend istream& operator >>(istream& in,Complex &comp)
		{
			cin>>comp.real>>comp.img;
			
			return in;
			
		}
		
		friend ostream& operator <<(ostream& out,Complex &comp)
		{
			 cout<<comp.real<<"+"<<comp.img<<"i"<<endl;
			 
			 return out;
		}
		
};

int main()
{
	int r1,i1;
	
	cout<<" Enter real part for 1st complex no : ";
	cin>>r1;
	cout<<" Enter img part for 1st complex no : ";
	cin>>i1;
	Complex c1(r1,i1);
	
	cout<<" Enter real part for 2nd complex no : ";
	cin>>r1;
	cout<<" Enter real part for 2nd complex no : ";
	cin>>i1;
	Complex c2(r1,i1);
	
	Complex c3;
	c3=c1+c2;
	
	cout<<"Addition : "<<c3;
	
	c3=c1*c2;
	
	cout<<"Multiplication : "<<c3;
	
	
}
