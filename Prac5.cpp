/* 
Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
*/
#include<iostream>
#define size 10
using namespace std;


template<class T>
void selectionsort(T a[size]){
	int j,min;
	T temp;
	
	for(int i=0;i<size;i++){
		min=i;
		for(j=i;j<size;j++){
			if(a[min]>a[j]){
				min=j;
			}
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
	
	cout<<"\nSorted array : ";
	for(int i=0;i<size;i++){
		cout<<"  "<<a[i]<<"  ";
	}
}

int main(){
	
	int it[size];
	float fl[size];
	cout<<"\nEnter 10 elements for int array : ";
	for(int i=0;i<size;i++){
		cin>>it[i];
	}
	selectionsort(it);
	
	cout<<"\nEnter 10 elements for float array : ";
	for(int i=0;i<size;i++){
		cin>>fl[i];
	}
	selectionsort(fl);
	
}
