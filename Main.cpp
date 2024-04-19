#include <iostream>
#include <string>

using namespace std;

//chainlink class where the color is dependent on the strength of the link
class ChainLink {
public:
	int strength;
	string colour;
	ChainLink(int strn) {
		this->strength = strn;
		string temp = "White";
		if (strn == 0){
			temp = "Black";
		}else if(strn <15){
			temp = "Red";
		}else if(strn < 29){
			temp = "Orange";
		}else if (strn < 43) {
			temp = "Yellow";
		}else if (strn < 57) {
			temp = "Green";
		}else if (strn < 71) {
			temp = "Blue";
		}else if (strn < 85) {
			temp = "Indigo";
		}else if (strn < 100) {
			temp = "Violet";
		}else {
			temp = "White";
		}

		this->colour = temp;
	};
	string get_color() {
		return this->colour;
	}
};

//Node class
class Node {
public:
	ChainLink* node_data;
	Node* next;
	void create_node(ChainLink* data, Node* previous_node=nullptr) {
		if (previous_node != nullptr)
		{
			previous_node->next = this;
		}
		this->node_data = data;
		this->next = NULL;
	}
};

//gives size of a list based of a header pointer
int list_size(Node* n) {
	int size = 0;
	while (n != NULL) {
		n = n->next;
		size++;
	}
	return size;
}

//prints list starting from header
void print_list(Node* n, int depth = 0) {
	if (depth==0|| list_size(n) <= depth)
	{
		while (n != NULL) {
			cout << n->node_data->get_color() << " ";
			n = n->next;
		}
	}
	else {
		for (int i = 0; i < depth; i++)
		{
			cout << n->node_data->get_color() << " ";
			n = n->next;
		}
	}
	
}

//main program
int main(){
	ChainLink link_one = ChainLink(80);
	ChainLink link_two = ChainLink(40);
	ChainLink link_three = ChainLink(60);
	ChainLink link_four = ChainLink(100);

	Node head;
	head.create_node(&link_one);
	cout << head.node_data->get_color() << endl;
	Node two;
	two.create_node(&link_two, &head);

	cout << head.node_data->get_color() << endl;
	cout << two.node_data->get_color() << endl;
	cout << head.next->node_data->get_color() << endl;

	Node three;
	three.create_node(&link_three, &two);
	Node four;
	four.create_node(&link_four, &three);

	print_list(&head); 
	cout << endl;
	print_list(&head,2);
	cout << endl;
	print_list(&head, 4);
	cout << endl;
	print_list(&head, 6);

	return 0;
}

//bl = 0
//r = 1-14
//o = 15-28
//y = 29-42
//g = 43-56
//b = 57-70
//i = 71-84
//v = 85-99
//w = 100