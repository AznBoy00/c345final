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

	List(const List& aList) : List() {
		//we called the default constructor to initialize the members of this list to nullptr (head and tail to nullptr)

		//Making a deep copy of aList into this list:
		Node* nodeToCopy = aList.head;
		Node* temp;
		while (nodeToCopy != nullptr)
		{
			if (head == nullptr)
			{
				head = new Node;
				head->data = nodeToCopy->data;
				head->next = nullptr;
				tail = head;
			}
			else
			{
				temp = new Node();
				temp->data = nodeToCopy->data;
				temp->next = nullptr;
				tail->next = temp;
				tail = tail->next;
			}
			nodeToCopy = nodeToCopy->next;
		}
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

	Node *getHead() const {
		return head;
	}

	List& operator = (const List& inputList) {
		if (this == &inputList) {
			return *this;
		}

		Node *temp;
		temp = inputList.getHead();

		while (temp != NULL) {
			this->createnode(temp->data);
			temp = temp->next;
		}
		return *this;
	}

	friend std::ostream &operator<<(std::ostream &stream, const List &l);
	friend std::istream& operator>> (istream& is, List& l);
};

std::ostream &operator<<(std::ostream &stream, const List &l) {
	Node *temp = new Node;
	temp = l.head;
	while (temp != nullptr) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
	delete temp;
	return stream;
}

std::istream& operator>> (istream& is, List& l) {
	int val;
	is >> val;
	Node* temp = new Node;
	temp->data = val;
	temp->next = nullptr;
	if (l.head == nullptr)
	{
		l.head = temp;
		l.tail = temp;
		temp = nullptr;
	}
	else {
		l.tail->next = temp;
		l.tail = temp;
	}
	return is;
}

List operator + (const List &a, const List &b) {
	List sum;
	Node* temp_a = a.getHead();
	Node* temp_b = b.getHead();
	if (temp_a == nullptr || temp_b == nullptr)
	{
		return List();
	}
	while (temp_a != nullptr && temp_b != nullptr)
	{
		sum.createnode(temp_a->data + temp_b->data);
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	return sum;
}

int main() {
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