template<typename T>
class QueueUsingArrays{
  int size;
  T *data;
  int nextIndex;
  int firstIndex;
  int capacity;
public:
  QueueUsingArrays(int s)
  {
    capacity  = s;
    data = new T[s];
    size = 0;
    nextIndex = 0;
    firstIndex = -1;
  }

  bool isEmpty(){
    return size==0;
  }
  int getSize(){
    return size;
  }
  T front(){
    if(isEmpty())
    {
      cout <<"Queue Is Empty !!"<<endl;
      return 0;
    }
    return data[firstIndex];
  }
  void enqueue(T element){
    if(size==capacity)
    {
      cout <<"Queue Is Full !!"<<endl;
      return;
    }
    data[nextIndex] = element;
    nextIndex = (nextIndex+1)%capacity;
    if(firstIndex==-1)
    {
      firstIndex++;
    }
    size++;
  }
  T dequeue()
  {
    if(isEmpty())
    {
      cout <<"Queue Is Empty !!"<<endl;
      return 0;
    }
    T ans = data[firstIndex];
    firstIndex = (firstIndex+1)%capacity;
    size--;
    return ans;
  }

};
