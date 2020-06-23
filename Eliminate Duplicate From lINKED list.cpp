/*Eliminate duplicates from LL

You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.

 Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.

 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

 Output format :
For each test case/query, print the resulting singly linked list of integers in a row, separated by a single space.

Output for every test case will be printed in a seperate line.

Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Sample Input 1 :
1
1 2 3 3 4 3 4 5 4 5 5 7 -1
Sample Output 1 :
1 2 3 4 3 4 5 4 5 7
*/




#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;


int length(Node *head){
    if(head==NULL){
        return 0;
    }
    else{
        return length(head->next)+1;
    }
}

Node *removeDuplicates(Node *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    //Write your code here
    Node *t1 = head;
    Node *t2 = head->next;
    while(t2!=NULL)
    {
        if(t1->data==t2->data)
        {
            t2 = t2->next;
        }
        else{
            t1->next = t2;
            t1 = t2;
            t2 = t2->next;
        }
    }
    t1->next = t2;
    return head;
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
  cout <<"Enter The Number Of Test Cases : ";
	cin >> t;
	while (t--)
	{
    cout <<"Enter The Elements : ";
		Node *head = takeinput();
		head = removeDuplicates(head);
    cout <<"Here Is YOur Output : ";
		print(head);
	}
	return 0;
}
