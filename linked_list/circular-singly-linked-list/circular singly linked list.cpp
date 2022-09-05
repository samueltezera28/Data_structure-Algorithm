#include<iostream>
#include<string>
using namespace std;
/*
 *struct Declaration
 */
struct node{
    string name;
    struct node *next;
};
 struct node* last;
/*
 * Class Declaration
 */
class linked_list{
    public:
    	
        void create_node(string value){
        	/*
			 * Create Circular Linked List
 			*/

        	struct node *temp;
    		temp = new(struct node);
    		temp->name = value;
    		if (last == NULL){
        		last = temp;
        		temp->next = last;   
    		}
    		else{
        		temp->next = last->next; 
        		last->next = temp;
        		last = temp;
    		}
		}
		
		
        void add_begin(string value){
        	/*
 			* Insertion of element at beginning of the list.
 			*/
	        if (last == NULL){
	        	cout<<"The list is empty."<<endl;
	        	return;
	    	}
		    struct node *temp;
		    temp = new(struct node);
		    temp->name = value;
		    temp->next = last->next;
		    last->next = temp;    	
			}
			
			
		void add_after(string value, int position){
			/*
 			* Insertion of element at a particular position of the list
 			*/
			if (last == NULL){
		        cout<<"The list is empty."<<endl;
		        return;
		    }
		    struct node *temp, *s;
		    s = last->next;
		    for (int i = 0;i < position-1;i++){
		        s = s->next;
		        if (s == last->next)
		        {
		            cout<<"There are less than ";
		            cout<<position<<" in the list"<<endl;
		            return;
		        }
		    }
		    temp = new(struct node);
		    temp->next = s->next;
		    temp->name = value;
		    s->next = temp;
		    /*Element inserted at the end*/
		    if (s == last){ 
		        last=temp;
		    }
		}
		
		
		void delete_element(string value){
			/*
 			* Deletion of element from the list
 			*/
			struct node *temp, *s;
		    s = last->next;
		      /* If List has only one element*/
		    if (last->next == last && last->name == value){
		        temp = last;
		        last = NULL;
		        delete temp;
		        return;
		    }
		    if (s->name == value){  /*First Element Deletion*/
		        temp = s;
		        last->next = s->next;
		        delete temp;
		        return;
		    }
		    while (s->next != last){
		        /*Deletion of Element in between*/
		        if (s->next->name == value)    
		        {
		            temp = s->next;
		            s->next = temp->next;
		            delete temp;
		            cout<<"Element "<<value;
		            cout<<" deleted from the list"<<endl;
		            return;
		        }
		        s = s->next;
		    }
		    /*Deletion of last element*/
		    if (s->next->name == value)    
		    {
		        temp = s->next;
		        s->next = last->next;
		        delete temp;	
		        last = s;
		        return;
		    }
		    cout<<"Element "<<value<<" not found in the list"<<endl;
		}
		
		
		void search_element(string value){
			/*
			 *searching element from list
			 */
			 
			struct node *s;
		    int counter = 0;
		    s = last->next;
		    while (s != last)
		    {
		        counter++;
		        if (s->name == value)    
		        {
		            cout<<"Element "<<value; 
		            cout<<" found at index "<<counter<<endl;
		            return;
		        }
		        s = s->next;
		    }
		    if (s->name == value)    
		    {
		        counter++;             
		        cout<<"Element "<<value;
		        cout<<" found at index "<<counter<<endl;
		        return;
		    }
		    cout<<"Element "<<value<<" not found in the list"<<endl;
		}
		
		
		void display_list(){
			/*
 			* Display Circular Link List 
 			*/
			struct node *s;
		    if (last == NULL){
		        cout<<"List is empty, nothing to display"<<endl;
		        return;
		    }
		    s = last->next;
		    cout<<"Circular Link List: "<<endl;
		    while (s != last){
		        cout<<s->name<<"->";
		        s = s->next;
		    }
		    cout<<s->name<<endl;
		}
		
		void sort(){
			/*
 			* Sort Circular Link List 
 			*/
			struct node *s, *ptr;
		    string temp;
		    if (last == NULL) {
		        cout<<"List is empty, nothing to sort"<<endl;
		        return;
		    }
		    s = last->next;
		    while (s != last){
		        ptr = s->next;
		        while (ptr != last->next){
		            if (ptr != last->next){
		                if (s->name > ptr->name){
		                    temp = s->name;
		                    s->name = ptr->name;
		                    ptr->name = temp;
		                }
		            }
		            else{
		                break;
		            }
		            ptr = ptr->next;    
		        }
		        s = s->next;         
		    }
			
		}
		        linked_list(){
		            last = NULL;           
		        }
};
 
/*
 * Main :contains menu 
 */
int main(){
    int choice,position;//declaration of integer variables
    string element;//declaration of string variable
    linked_list cls;//declaration of class 
    cout<<"Wellcome This is Circular linked list implementation in c++ and its operations\nfor this program i used String values so Please input STRING values only!! \nAuthor Samuel Tezera\ngithub:https://github.com/samueltezera28 "<<endl;
    system("pause");
    while (1)
    {
        cout<<endl<<"#######################################"<<endl;
        cout<<endl<<"\tCircular singly linked list"<<endl;
        cout<<endl<<"#######################################"<<endl;   
        cout<<"\t1.Create Node"<<endl;
        cout<<"\t2.Display"<<endl;
        cout<<"\t3.Add after"<<endl;
        cout<<"\t4.Search"<<endl;
        cout<<"\t5.Delete"<<endl;
        cout<<"\t6.Add at beginning"<<endl;
        cout<<"\t7.Sort"<<endl;
        cout<<"\t8.Quit"<<endl;
        cout<<"\tEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            cls.create_node(element);
            cout<<endl;
            break;
        case 2:
        	cls.display_list();
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element after position: ";
            cin>>position;
            cls.add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (last == NULL){
                cout<<"List Empty!! Can't search"<<endl;
                break;
            }
            cout<<"Enter the element to be searched: ";
            cin>>element;
            cls.search_element(element);
            cout<<endl;
            break;        	
        case 5:
            if (last == NULL){
                cout<<"List is empty, nothing to delete"<<endl;
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cls.delete_element(element);
            cout<<endl;
            break;

        case 6:
            cout<<"Enter the element: ";
            cin>>element;
            cls.add_begin(element);
            cout<<endl;        	
        	break;
        case 7:
            cls.sort();
            break;                      
        case 8:
        	cout<<"Thanks for using,good bye :)";
            exit(1);
            break;
        default:
            cout<<"please input a valid choice"<<endl;
        }
    }
    return 0;
}
 
