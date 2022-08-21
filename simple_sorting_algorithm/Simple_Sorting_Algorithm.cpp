#include<iostream>
#include <string>
#include<iomanip>
using namespace std;
#define max 200 //max size of array to be allocated 

void UserInput(int option);
/*this function initialise 
creation of array and size of the array 
call bubble sort function that handles the sorting algorithm
*/
void Bubble_sort(string array[], int size);
void Insertion_Sort(string array[], int size);
void Selection_Sort(string array[], int size);
int main(){
	int option;
	
	while(true){
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tWellcome To simple sorting Algorithm"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
	
		cout<<"1)Bubble Sort"<<endl;
		cout<<"2)Insertion Sort"<<endl;
		cout<<"3)Selection Sort"<<endl;
		cout<<"4)Exit"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		
	switch(option){
		case 1:
			UserInput(option);
			break;
		case 2:
			UserInput(option);
			break;
		case 3:
			UserInput(option);
			break;
		case 4:
			break;
		default:
			cout<<"Please Input A valid Choice"<<endl<<endl;
	}
	if(option == 4){
		cout<<"Bye:)";
		return 0;
	}
	
			
}
}//end of main


void UserInput(int option){
	
	int size;
	string value;
	cout<<"******************************************************"<<endl;
	cout<<"\t Implement Sorting Algorithm Using c++\t"<<endl<<endl;
	cout<<"Input Size of an Array:";
	cin>>size;
	string array[size];//declaring array to store the values 
	cout<<"Input string Value Only!"<<endl;
	for(int i = 0; i < size; i++){
		//for loop to store values to the array
		cout<<"Input string["<<i<<"]:";
		cin>>value;
		array[i]=value;
	}
	cout<<endl<<endl;
	cout<<"******************************************************"<<endl;
	for(int i = 0; i < size; i++){
		//for loop to display values of the array
		cout<<array[i]<<setw(10);
	}
	cout<<endl<<endl;
	cout<<"******************************************************"<<endl;
	cout<<endl<<endl;
	cout<<"******************************************************"<<endl;
	cout<<"Array Created Successfully"<<endl;
	cout<<"******************************************************"<<endl;
	
	if(option == 1){
		Bubble_sort(array,size);
	}
	if (option == 2){
		Insertion_Sort(array, size);
	}
	if (option == 3){
		Selection_Sort(array, size);
	}
}

void Bubble_sort(string array[],int size){
	string temp;
	char y;
	
	for(int i = 1; i < size; i++){
		for (int j = 0; j< size-1; j++){
			if (array[j]>array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1]=temp;
			}
		}
	}
	cout<<"would you like to print the values by using bubble sorting Algoritm?"<<endl;
	cout<<"press (y or Y)for yes:";
	cin>>y;
	cout<<endl<<endl;
	if (y== 'y' || y=='Y'){
	
	cout<<"******************************************************"<<endl;	
	for (int i=0; i<size;i++){
		cout<<array[i]<<setw(10);
	}
	cout<<endl<<endl;
	cout<<"******************************************************"<<endl;
	cout<<endl<<endl<<endl;
}
	else{
		main();
	}
}


  
// Function to sort an array using insertion sort
void Insertion_Sort(string array[], int size) { 
    int j;
    char y;
	string key; 
    for (int i = 1; i < size; i++)
    { 
        key = array[i]; 
        j = i - 1; 
  
        // Move elements of arr[0..i-1],  
        // that are greater than key, to one 
        // position ahead of their 
        // current position
        while (j >= 0 && array[j] > key)
        { 
            array[j + 1] = array[j]; 
            j = j - 1; 
        } 
        array[j + 1] = key; 
    }
    
    cout<<"would you like to print the values by using bubble sorting Algoritm?"<<endl;
	cout<<"press (y or Y)for yes:";
	cin>>y;
	cout<<endl<<endl;
	if (y == 'y' || y == 'Y'){
	
		cout<<"******************************************************"<<endl;
			for (int i=0; i<size;i++){
			cout<<array[i]<<setw(10);
		}
		cout<<endl<<endl;
		cout<<"******************************************************"<<endl;
	}
	else{
		main();
	}	
}


 
void Selection_Sort(string array[], int size){
    int  min;
	string temp; 
	char y;
    // One by one move boundary of
    // unsorted subarray
    for (int i = 0; i < size; i++)
    {
       
        // Find the minimum element in
        // unsorted array
        min = i;
        for (int j = i+1; j < size; j++)
        if (array[j] < array[min])
            min = j;
 
        // Swap the found minimum element
        // with the first element
        if(min!=i)
         
            temp = array[min];
    		array[min] = array[i];
    		array[i] = temp;
    }
 	cout<<"would you like to print the values by using bubble sorting Algoritm?"<<endl;
	cout<<"press (y or Y)for yes:";
	cin>>y;
	cout<<endl<<endl;
	if (y == 'y' || y == 'Y'){
	
		cout<<"******************************************************"<<endl;
			for (int i=0; i<size;i++){
			cout<<array[i]<<setw(10);
		}
		cout<<endl<<endl;
		cout<<"******************************************************"<<endl;	
	}
	else{
		main();
	}
}



