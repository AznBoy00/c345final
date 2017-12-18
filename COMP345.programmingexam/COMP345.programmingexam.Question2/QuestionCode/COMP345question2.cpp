// Original code from the web: 
// https://github.com/kamal-choudhary/singly-linked-list
// https://www.codementor.io/codementorteam/a-comprehensive-guide-to-implementation-of-singly-linked-list-using-c_plus_plus-ondlm5azr

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PART 1: 
// Implement a stream output operator (<<) that prints out to an output stream all the values contained in a List object.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PART 2: 
// Implement a stream input operator (>>) that allows the user to input an integer value on the keyboard, 
// which is then added at then end of an existing List object.  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PART 3: 
// Using operator overloading, implement an addition operator (operator+) that implements the addition of two List objects. 
// The operator must be implemented as a free operator (i.e. not a member of the List class).  
// It must be able to add two lists of different lengths, in which case it stops when it reaches the end 
// of the shortest of the two Lists. 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PART 4: 
// Implement an assignment operator that implements a proper assignment of one List object into another List object.  
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// PART 5: 
// Implement a copy constructor for the List class that performs a deep copy operation from an existing List object 
// to create another List object. 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
// The resulting code should be able to run with the following main() function: 
/*
int main(){
List obj;
obj.createnode(25);
obj.createnode(50);
obj.createnode(90);
obj.createnode(40);
cout << "\n--------------------------------------------------\n";
cout << "---------------Displaying All nodes---------------";
cout << "\n--------------------------------------------------\n";
obj.display();
cout << "\n--------------------------------------------------\n";
cout << "-----------------Inserting At End-----------------";
cout << "\n--------------------------------------------------\n";
obj.createnode(55);
obj.display();
cout << "\n--------------------------------------------------\n";
cout << "----------------Inserting At Start----------------";
cout << "\n--------------------------------------------------\n";
obj.insert_start(50);
obj.display();
cout << "\n--------------------------------------------------\n";
cout << "-------------Inserting At Particular--------------";
cout << "\n--------------------------------------------------\n";
obj.insert_position(5, 60);
obj.display();
cout << "\n--------------------------------------------------\n";
cout << "----------------Deleting At Start-----------------";
cout << "\n--------------------------------------------------\n";
obj.delete_first();
obj.display();
cout << "\n--------------------------------------------------\n";
cout << "-----------------Deleting At End-------------------";
cout << "\n--------------------------------------------------\n";
obj.delete_last();
obj.display();
cout << "\n--------------------------------------------------\n";
cout << "--------------Deleting At Particular--------------";
cout << "\n--------------------------------------------------\n";
obj.delete_position(4);
obj.display();

cout << "\n--------------------------------------------------\n";
cout << "--------------Using answer code-----------------";
cout << "\n--------------------------------------------------\n";

cout << "\n--------------------------------------------------\n";
cout << "--------------Using copy constructor-----------------";
cout << "\n--------------------------------------------------\n";
List obj1(obj);
cout << obj1 << endl;

cout << "\n--------------------------------------------------\n";
cout << "--------------Using assignment operator-----------------";
cout << "\n--------------------------------------------------\n";
List obj2;
obj2 = obj1;
cout << obj1 << endl;

cout << "\n--------------------------------------------------\n";
cout << "--------------Using stream input------------------";
cout << "\n--------------------------------------------------\n";
cin >> obj1 >> obj1;
cout << obj1 << endl;

cout << "\n--------------------------------------------------\n";
cout << "--------------Using operator+------------------";
cout << "\n--------------------------------------------------\n";
List obj3, obj4;
obj3.createnode(1);
obj3.createnode(2);
obj3.createnode(3);
obj3.createnode(3);
obj4.createnode(4);
obj4.createnode(5);
obj4.createnode(6);
cout << "obj3 List: " << endl << obj3 << endl;
cout << "obj4 List: " << endl << obj4 << endl;
cout << "obj3 + obj4: " << endl << obj3 + obj4 << endl;

system("pause");
return 0;
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// executing this main function should result in the following console output: 
/*
--------------------------------------------------
---------------Displaying All nodes---------------
--------------------------------------------------
25      50      90      40
--------------------------------------------------
-----------------Inserting At End-----------------
--------------------------------------------------
25      50      90      40      55
--------------------------------------------------
----------------Inserting At Start----------------
--------------------------------------------------
50      25      50      90      40      55
--------------------------------------------------
-------------Inserting At Particular--------------
--------------------------------------------------
50      25      50      90      60      40      55
--------------------------------------------------
----------------Deleting At Start-----------------
--------------------------------------------------
25      50      90      60      40      55
--------------------------------------------------
-----------------Deleting At End-------------------
--------------------------------------------------
25      50      90      60      40
--------------------------------------------------
--------------Deleting At Particular--------------
--------------------------------------------------
25      50      90      40
--------------------------------------------------
--------------Using answer code-------------------
--------------------------------------------------

--------------------------------------------------
--------------Using copy constructor--------------
--------------------------------------------------
25      50      90      40

--------------------------------------------------
--------------Using assignment operator-----------
--------------------------------------------------
25      50      90      40

--------------------------------------------------
--------------Using stream input------------------
--------------------------------------------------
1
2
25      50      90      40      1       2

--------------------------------------------------
--------------Using operator+---------------------
--------------------------------------------------
obj3 List :
1       2       3       3
obj4 List :
4       5       6
obj3 + obj4 :
5       7       9
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;
struct Node {
	int data;
	Node *next;	
};

class List {
private:
	Node *head, *tail;
public:
	List() {
		head=NULL;
		tail=NULL;
	}
	void createnode(int value){
		Node *temp=new Node;
		temp->data=value;
		temp->next=NULL;
		if(head==NULL){
			head=temp;
			tail=temp;
			temp=NULL;
		}
		else{	
			tail->next=temp;
			tail=temp;
		}
	}
	void display(){
		Node *temp=new Node;
		temp=head;
		while(temp!=NULL){
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}
	void insert_start(int value){
		Node *temp=new Node;
		temp->data=value;
		temp->next=head;
		head=temp;
	}
	void insert_position(int pos, int value){
		Node *pre=new Node;
		Node *cur=new Node;
		Node *temp=new Node;
		cur=head;
		for(int i=1;i<pos;i++){
			pre=cur;
			cur=cur->next;
		}
		temp->data=value;
		pre->next=temp;	
		temp->next=cur;
	}
	void delete_first(){
		Node *temp=new Node;
		temp=head;
		head=head->next;
		delete temp;
	}
	void delete_last(){
		Node *current=new Node;
		Node *previous=new Node;
		current=head;
		while(current->next!=NULL){
			previous=current;
			current=current->next;	
		}
		tail=previous;
		previous->next=NULL;
		delete current;
	}
	void delete_position(int pos){
		Node *current=new Node;
		Node *previous=new Node;
		current=head;
		for(int i=1;i<pos;i++){
			previous=current;
			current=current->next;
		}
		previous->next=current->next;
		delete current; 
	}
};
int main(){
	List obj;
	obj.createnode(25);
	obj.createnode(50);
	obj.createnode(90);
	obj.createnode(40);
	cout<<"\n--------------------------------------------------\n";
	cout<<"---------------Displaying All nodes---------------";
	cout<<"\n--------------------------------------------------\n";
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Inserting At End-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.createnode(55);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Inserting At Start----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_start(50);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-------------Inserting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.insert_position(5,60);
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"----------------Deleting At Start-----------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_first();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"-----------------Deleting At End-------------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_last();
	obj.display();
	cout<<"\n--------------------------------------------------\n";
	cout<<"--------------Deleting At Particular--------------";
	cout<<"\n--------------------------------------------------\n";
	obj.delete_position(4);
	obj.display();
	int x; cin >> x;
	return 0;
}