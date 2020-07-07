#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
  int *data;
  int nextIndex,capacity;
public:
  StackUsingArray()
  {
    data = new int[8];
    capacity = 8;
    nextIndex = 0;
  }

 //Size Of The Stack

  int size(){
    return nextIndex;
  }

 //Check If Stack Is empty Or NOT

  bool isempty(){
    return nextIndex==0;
  }

 // Inserting Elements In A Stack

  void push(int element)
  {
    if(nextIndex==capacity)
    {
      int *NewData  = new int[2*capacity];
      for(int i=0;i,capacity;i++)
      {
        NewData[i] = data[i];
      }
      capacity =2*capacity;
      delete []data;
      data = NewData;
    }
    data[nextIndex] = element;
    nextIndex++;
  }

 // Deleting Elements From The Stack

  int pop(){
    if(isempty())
    {
      cout <<"Stack Is Empty";
      return INT_MIN;
    }
    nextIndex--;
    return data[nextIndex];
  }

 // Top Most Element Inthe Stack

 int top(){
   if(isempty())
   {
     cout <<"Stack Is Empty";
     return INT_MIN;
   }
   return data[nextIndex-1];
 }
};

int main(){
  StackUsingArray s;
  cout <<"Enter The Elements For Stacks : ";
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  cout <<"Current Length "<<s.size()<<endl;
  cout <<"Current Top "<<s.top()<<endl;
  s.push(50);
  cout <<"Current Top "<<s.top()<<endl;
  cout <<"Current Length "<<s.size()<<endl;
  cout <<s.pop()<<endl;
  cout <<s.pop()<<endl;
  cout <<s.pop()<<endl;
  cout <<"Current Length "<<s.size()<<endl;
  cout <<s.isempty()<<endl;
}
