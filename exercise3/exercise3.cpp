#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** ngasubala, Node** badai);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() {
	Node* newNode = new Node();
	cout << "\nEnter the roll number: ";
	cin >> newNode->rollNumber;
	cout << "Enter the name: ";
	cin.ignore();
	getline(cin, newNode->name);

	if (listEmpty()) {
		newNode->next = newNode;
		LAST = newNode;
	}
	else {
		newNode->next = LAST->next;
		LAST->next = newNode;
		LAST = newNode;
	}

		cout << "Record added successfully.\n";
}


bool CircularLinkedList::search(int rollno, Node** ngasubala, Node** badai) {
	*ngasubala = LAST->next;
	*badai = LAST->next;
	while (*badai != LAST) {
		if (rollno == (*badai)->rollNumber) {
			return true;
		}
		*ngasubala= *badai;
		*badai = (*badai)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {
	if (listEmpty()) {
		cout << "\nList is empty. Deletion not possible.\n"
		return false;
	}

	int rollno;
	cout << "\nEnter the roll number to delete: ";
	cin >> rollno;

	Node* ngasubala  = NULL;
	Node* badai = NULL;
	bool found = search(rollno, &ngasubala, &badai);

	if (found) {
		if (badai == LAST) {
			LAST = ngasubala;
		}
		ngasubala->next = badai->next;
		delete badai;
		cout << "Record deleted successfully.\n";
		return true;
	}
	else {
		cout << "Record not found.\n";
		return false;
	}
}


void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}