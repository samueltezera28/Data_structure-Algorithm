#include<iostream>
#include<iomanip>
#include<bits/stdc++.h> 
using namespace std;
#define max 200 //max size of array to be allocated 

void UserInput();
/*this function initialise 
creation of array and size of the array 
call binary_search function that handles the searching algorithm
*/
void UserInput2();
/*this function initialise 
creation of array and size of the array 
call seq_search function that handles the searching algorithm
*/
int binary_search(int array[],int n,int k,int l, int h, int m);//declaration of function
void seq_search(int array[],int key, int n);

int main(){
	int option;
	
	while(true){
		cout<<"********************************************************************"<<endl;
		cout<<"Wellcome To simple Search Algorithm"<<endl;
		cout<<"********************************************************************"<<endl<<endl;
		cout<<"1)Binary Search"<<endl;
		cout<<"2)Sequential Search"<<endl;
		cout<<"3)exit"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		
	switch(option){
		case 1:
			UserInput();
			break;
		case 2:
			UserInput2();
			break;
		case 3:
			break;
	}
	if(option == 3){
		cout<<"Bye:)";
		return 0;
	}
	if (option !=1 || option !=2 || option!=3){
			cout<<"Please Input A valid Choice"<<endl<<endl;
		}
			
}
}//end of main function

int array[max], glow = 0, ghigh, gmid;//global variables 
int binary_search(int array[],int n,int k,int l, int h, int m);//declaration of function

	
void UserInput(){

	int value, size, key, low = 0, high, mid,x;
	cout<<"***********************************************************************"<<endl<<endl;
	cout<<"Q2)Implement Binary Search in both using loop and recursive function"<<endl<<endl;
	cout<<"***********************************************************************"<<endl<<endl;
	cout<<"Input Size of an Array:";
	cin>>size;
	high=size-1;
	cout<<"Please Input Integers Only!!"<<endl;
	
	for(int i = 0; i < size; i++){
		//for loop to store values to an array
		cout<<"Input Value To Store["<<i<<"]:";
		cin>>value;
		array[i]=value;
	}
	sort(array, array+size);//sort function that will sort our values in ascending order
	cout<<"***********************************************************************"<<endl<<endl;
	for(int i = 0; i < size; i++){
		//for loop to display the stored values
		cout<<array[i]<<setw(4);
	}
	cout<<endl<<endl;
	cout<<"***********************************************************************"<<endl<<endl;
	cout<<"Input a Value to Search From The Above:";
	cin>>key;
	x=binary_search(array,size,key,low,high,mid);//calling binary search function
}//end of userInput
void UserInput2(){
	int value, size,key;
	cout<<"******************************************************"<<endl;
	cout<<"\t(Q1)Implement Linear Search Using c++\t"<<endl<<endl;
	cout<<"Input Size of an Array:";
	cin>>size;
	int array[size];//declaring array to store the values that we will implement linear search
	cout<<"Input Number Value Only!"<<endl;
	for(int i = 0; i < size; i++){
		//for loop to store values to the array
		cout<<"Input value["<<i<<"]:";
		cin>>value;
		array[i]=value;
	}
	cout<<endl<<endl;
	cout<<"******************************************************"<<endl;
	for(int i = 0; i < size; i++){
		//for loop to display values of the array
		cout<<array[i]<<setw(4);
	}
	cout<<endl<<endl;
	cout<<"******************************************************"<<endl;
	cout<<endl<<endl;
	cout<<"Input the value you want to search from the above :";
	cin>>key;
    seq_search(array, key, size);//calling the search function		
}//end of UserInput2


int binary_search(int array[],int size, int key ,int glow, int ghigh, int gmid){
 	//this function implements binary search algorithm by using recusive function
 	/*variable def 
 		int size ."size of the array"
		int key  ."key value to be searched"
		int glow ."the initial index of the array which is zero"
		int ghigh."the last index of the array which is size-1"
		int gmid ."the mid value of the array which will be using to find the value"
	*/ 
 	  
	gmid = (glow + ghigh)*0.5;
	if (key == array[gmid]){
		cout<<"value found at index ["<<gmid<<"]"<<endl;
		cout<<"value is:"<<key<<endl;
		return 0;
	}
	if(array[gmid] <= key){
		glow = gmid + 1;
		if(glow == size){
			cout<<"value not found"<<endl;
			return 0;
		}
		return binary_search(array, size, key, glow, ghigh, gmid);//recursive call
	}
	if(array[gmid] >= key){
			ghigh = gmid - 1;
		if (glow > ghigh){
			cout<<"Value Not Found"<<endl;
			return 0;
		}
		return binary_search(array, size, key, glow, ghigh, gmid);//recursive call
	}
}//end of binary search

void seq_search(int array[],int key, int n){
	/*this fuction implement linear search*/
	int A;
	for (int i = 0; i < n; i++){
		if (key == array[i]){
			cout<<"value found at index =["<<i<<"]"<<endl;
			cout<<"value is ="<<array[i]<<endl;
			A=i;
			break;
		}
	}
	if (key != array[A]){
		cout<<"Value Not Found"<<endl;	
	}
		
}//end of seq_search
