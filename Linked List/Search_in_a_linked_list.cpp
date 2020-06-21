/*
Find a Node in Linked List


You have been given a singly linked list of integers. Write a function that returns the index/position of an integer data denoted by 'N'(if it exists). -1 otherwise.
Note : Assume that the Indexing for the singly linked list always starts from 0.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the integer value 'N'. It denotes the data to be searched in the given singly linked list.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

Output format :
For each test case/query, print the index/position of 'N' in the singly linked list. -1, otherwise.

Output for every test case will be printed in a seperate line.
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.


Sample Input 1 :
2
3 4 5 2 6 1 9 -1
5
10 20 30 40 50 60 70 -1
6

Sample Output 1 :
2
-1

*/


#include <iostream>
using namespace std;
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



Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}


int findNode(Node *head, int N){
  int count = 0;
  Node *temp = head;
  while(temp!=NULL)
  {
    if(temp->data==N)
    {
      return count;
    }
    else{
      count++;
      temp = temp->next;
    }
  }
  return -1;
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
		int val;
    cout <<"Enter The No. You Want To Search For : ";
		cin >> val;
    cout <<"The Positon Of Required Element Is : ";
		cout << findNode(head, val) << endl;

	}
  cout << "\nNote : If The Output Is -1,\nMeans The Searched Element Is Not In The Linked List.";
}
