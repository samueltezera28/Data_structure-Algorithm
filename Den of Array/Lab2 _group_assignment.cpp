#include<iostream>
using namespace std;
#define max 200
int row1,col1,row2,col2,option;//declaration of global variables
int array1[10][10],array2[10][10],product[10][10];//declaration of multi dimentional arrray
int show_menu();//menu function
int showmenu();//menu  function for array addition
void multiplay_matrix(int array1[10][10],int array2[10][10],int row1,int col1 ,int row2 ,int col2);//to multiplay the functions
void array_addition(int array[],int size);//addition of array
void input_array();//accepting array values
void create_matrix(){
	
   	char y;
   	cout<<"Input Size of first matrix row :";
   	cin>>row1;//size of first row
   	cout<<"Input Size of first matrix column :";
   	cin>>col1;//size of first columon
   	cout<<"Input Size of second matrix row :";
   	cin>>row2;//size of second row 
   	cout<<"Input Size of second matrix column :";
   	cin>>col2;//size of second column

   while (col1 != row2)//multiplication rule checker
    {
        cout << "column of first matrix not equal to row of second.";

   		cout<<"Input Size of first matrix row :";
   		cin>>row1;//size of first row
   		cout<<"Input Size of first matrix column :";
   		cin>>col1;//size of first columon
   		cout<<"Input Size of second matrix row :";
   		cin>>row2;//size of second row 
   		cout<<"Input Size of second matrix column :";
   		cin>>col2;
    }

   
   for(int i=0;i<row1;i++){//first multi dimentional array
	 	for(int j=0; j<col1; j++){
   			cout<<"Enter value for first matrix:"<<i+1<<j+1<<":";
   			cin>>array1[i][j];
	   	}
   	}
   
   for(int i=0;i<row2;i++){//second multi dimentional array
	 	for(int j=0; j<col2; j++){
   			cout<<"enter value for second matrix:"<<i+1<<j+1<<":";
   			cin>>array2[i][j];//size array2
	   }
   }
   
   for (int i = 0; i<row1; i++)//3rd matrix to store the product
   {
   		for(int j=0; j<col2; j++){
   			product [i][j]=0;//initialize to the elements to zero
	   }
	}
	cout<<"Two matrics are created successfuly"<<endl;
	cout<<"To multiplay and print the two matrix press (Y/y) for yes"<<endl;
	cout<<"Or press any key to return to the menu:";
	cin>>y;
	if (y == 'Y' || y == 'y'){
		multiplay_matrix(array1,array2,row1,col1,row2,col2);//callinng multiplay matrix
		
	}
	else{
		show_menu();//returing to menu function
	} 
	
}

void multiplay_matrix(int array1[10][10],int array2[10][10],int row1,int col1 ,int row2 ,int col2){
	/* a function def that multiplay the two matrix 
		and store it to product[i][j] matrix
	*/
   
   	for(int i=0; i<row1; i++){
   		for(int j=0; j<row2; j++){
   			
   			for(int k=0; k<row1; k++){
   				product[i][j]+=array1[i][k] * array2[k][j];
				}
		   }
	   }
	
   for(int i=0;i<row1;i++){
   		for(int j=0;j<col2;j++){
   			cout<<" "<<product[i][j];
   			if (j == row2 - 1)
   			cout<<endl;
	   }
   }
}

int show_menu(){
	int option;
	
		while(true){
		cout<<"\t\t********************************************************************"<<endl;
		cout<<"\t\t\tWellcome To The Den of Array"<<endl;
		cout<<"\t\t********************************************************************"<<endl<<endl;
	
		cout<<"1)Create two dimentional matrix"<<endl;
		cout<<"2)Array addition"<<endl;
		cout<<"3)exit"<<endl;
		cout<<"Enter Choice:";
		cin>>option;
		
	switch(option){
		case 1:
			create_matrix();
			break;
		case 2:
			showmenu();
			break;
		case 3:
			if(option == 3){
				cout<<"Bye:)";
				return 0;		
			}
		}
	}
}
int showmenu(){
	int option,size ,array[max];//variable declration
	while(true){
		cout<<"********************************************************"<<endl;
		cout<<"1. Input value"<<endl;
		cout<<"2. Display sum"<<endl;
		cout<<"3. Return to Menu"<<endl;
		cout<<"4. Exit the program"<<endl;
		cout<<"Enter choice";
		cin>>option;
		cout<<"********************************************************"<<endl;
		if (option==1){	
			input_array();
        }
        if (option == 2){
        	array_addition(array, size);
		}
        if(option==3){
        	show_menu();
		}
		if (option == 4){
			exit(0);
		}
}
}
void input_array(){
	char y;
	int size,array[20];
	cout<<"Input size of the array:";
    cin>>size;
    array[size];
    for(int i = 0; i<=size-1; i++){
    	cout<<"input value ["<<i+1<<"]:";
        cin>>array[i];
    }
    cout<<"Array created successfully"<<endl;
    cout<<"would you like to print the sum of the Array(y/Y):"<<endl;
    cin>>y;
	if (y == 'Y' || y == 'y'){
		array_addition(array,size);
	}
	else{
		show_menu();
	} 
}
void array_addition(int array[],int size){
	int sum ,new_sum;//declaration of variables
    sum = 0;
	for(int i = 0; i<size; i++){                                       
    	sum +=array[i];
        }
    cout<<"Sum of the array ="<<sum<<endl;
}
int main(){
	//this is the main function 
	show_menu();
}
