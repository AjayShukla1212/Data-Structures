/*
Code: Merge Two Sorted LL

Given two linked lists sorted in increasing order. Merge them in such a way that the result list is also sorted (in increasing order).
Try solving with O(1) auxiliary space (in-place). You just need to return the head of new linked list, don't print the elements.

Input format :
Line 1 : Linked list 1 elements of length n (separated by space and terminated by -1)
Line 2 : Linked list 2 elements of length m (separated by space and terminated by -1)

Output format :
Merged list elements (separated by space)

Constraints :
1 <= n, m <= 10^4

Sample Input :
 2 5 8 12 -1
 3 6 9 -1

Sample Output :
 2 3 5 6 8 9 12
 */
 #include <iostream>
 class Node{
 public:
     int data;
     Node *next;
     Node(int data){
         this -> data = data;
         this -> next = NULL;
     }
 };

 using namespace std;

 Node* mergeTwoLLs(Node *h1, Node *h2) {
     int data;
     Node *fh = NULL;
     Node *ft = NULL;
     // putting final head And Final Tail
     if(fh==NULL)
     {
         if(h1->data > h2->data)
     	{
         	fh = h2;
         	ft = h2;
          	h2 = h2->next;
     	}
     	else
         {
         	fh = h1;
         	ft = h1;
             h1 = h1->next;
         }
     }
     while(h1!=NULL && h2!=NULL)
     {
         if(h1->data > h2->data)
     	{
         	ft->next = h2;
         	ft = ft->next;
          	h2 = h2->next;
     	}
     	else
         {
         	ft->next = h1;
         	ft = ft->next;
             h1 = h1->next;
         }
     }
     if(h2==NULL){
         ft->next = h1;
     }
 	if(h1==NULL){
         ft->next = h2;
     }

     return fh;
 }


 Node* takeinput() {
     int data;
     cin >> data;
     Node* head = NULL, *tail = NULL;
     while(data != -1){
         Node *newNode = new Node(data);
         if(head == NULL)                  {
             head = newNode;
             tail = newNode;
         }
         else{
             tail -> next = newNode;
             tail = newNode;
         }
         cin >> data;
     }
     return head;
 }

 void print(Node *head) {
     Node *temp = head;
     while(temp != NULL) {
         cout << temp -> data << " ";
         temp = temp -> next;
     }
     cout<<endl;
 }

 int main() {
     cout <<"Enter First Linked List : ";
     Node *head1 = takeinput();
     cout <<"Enter Second Linked list : ";
     Node *head2 = takeinput();
     Node *head3 = mergeTwoLLs(head1, head2);
     cout <<"After Merging : ";
     print(head3);
     return 0;
 }
