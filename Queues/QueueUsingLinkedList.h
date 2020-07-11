template<typename s>
class Node{
  public:
    s data;
    Node<s> *next;

    Node(s data){
      this->data = data;
      next = NULL;
    }
};

template<typename T>
class QueueUsingLL{
  Node<T> *head;
  Node<T> *tail;
  int size;
public:
  QueueUsingLL(){
    head = NULL;
    tail = NULL;
    size = 0;
  }

  bool isEmpty(){
    return size==0;
  }

  int getSize()
  {
    return size;
  }

  void enqueue(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    if(head==NULL)
    {
      head = newNode;
      tail = newNode;
    }
    else{
      tail->next = newNode;
      tail = newNode;
    }
    size++;
  }

  T front(){
    if(isEmpty())
    {
      cout <<"Empty Queue !! "<<endl;
      return 0;
    }
    return head->data;
  }
  T dequeue(){
    if(isEmpty())
    {
      cout <<"Empty Queue !! "<<endl;
      return 0;
    }
    T ans = head->data;
    Node<T> *temp = head;
    head = head->next;
    delete []temp;
    size--;
    return ans;
  }
};
