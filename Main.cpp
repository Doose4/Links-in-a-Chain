#include <iostream>
#include <string>

using namespace std;

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
};

class Node {
public:
	ChainLink* node_data;
	Node* next;
};

Node* create_node(ChainLink* data, Node* previous_node) {
	Node foo;
	Node* new_node = &foo;
	previous_node->next = new_node;
	new_node->node_data = data;
	return new_node;
}

int main(){
	ChainLink link_one = ChainLink(80);
	ChainLink link_two = ChainLink(40);
	ChainLink link_three = ChainLink(60);
	ChainLink link_four = ChainLink(100);

	Node head = Node();
	Node* head_ptr = &head;
	Node *two = create_node(&link_two, head_ptr);
	//Node* three = NULL;
	//head = create_node(&link_three, nullptr);
	//Node* four = NULL;
	//head = create_node(&link_four, nullptr);

	return 0;
}

//bl = 0
//r = 1-14
//o = 28
//y = 42
//g = 56
//b = 70
//i = 84
//v = 99
//w = 100