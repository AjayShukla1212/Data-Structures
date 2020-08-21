#include<string>

template<typename V>
class mapNode{
public:
  string key;
  V value;
  mapNode<V>* next;

// Constructor
  mapNode(string key,V value){
    this->key = key;
    this->value = value;
    next = NULL;
  }

// Destructor
  ~mapNode(){
      delete next;
  }
};

template<typename V>
class ourmap{
public:
  mapNode<V>** bucket;
  int count;
  int numbucket;
//Constructor
  ourmap(){
    numbucket = 5;
    count = 0;
    bucket = new mapNode<int>* [numbucket];
    for(int i=0;i<numbucket;i++){
      bucket[i] = NULL;
    }
  }
  //Destructor
  ~ourmap(){
    for(int i=0;i<numbucket;i++){
      delete bucket[i];
    }
    delete[] bucket;
  }

  //Return Size
  int size(){
    return count;
  }

  //Insert
private:

  //hashcode + compression function
  int getIndex(string key){
    int hashcode = 0;
    int currcoeff = 1;
    for(int i=key.length()-1;i>=0;i--){
      hashcode += key[i]*currcoeff;
      currcoeff*=37;
      hashcode = hashcode % numbucket;
      currcoeff = currcoeff % numbucket;
    }
    return hashcode % numbucket;
  }

public:
 void rehash(){
   mapNode<V>** temp = bucket;
    bucket = new mapNode<V>* [2*numbucket];
    for(int i=0;i<2*numbucket;i++){
      bucket[i] = NULL;
    }
    int oldBucketCount = numbucket;
    numbucket *=2;
    count = 0;
    for(int i=0;i<numbucket;i++){
      mapNode<int>* head = temp[i];
      while(head!=NULL){
        string key = head->key;
        V value = head->value;
        insert(key,value);
        head = head->next;
      }
    }
    for(int i=0;i<numbucket;i++){
      mapNode<V>* head2 = temp[i];
      delete head2;
    }
    delete temp;
 }


  void insert(string key,V value){
      int bucketIndex = getIndex(key);
      mapNode<V>* head = bucket[bucketIndex];

      while(head!=NULL){
        if(head->key==key){
          head->value = value;
          return;
        }
        head = head->next;
      }
      mapNode<V>* node = new mapNode<V> (key,value);
      node->next = head;
      bucket[bucketIndex] = node;
      count++;     // To Update The number of Filled Elements in the array
      double loadFactor = (1.0*count)/numbucket;
      if(loadFactor>0.7){
        rehash();
      }
  }


  // Delete or Remove
  V remove(string key){
    int bucketIndex = getIndex(key);
    mapNode<int>* head = bucket[bucketIndex];
    mapNode<V>* prev = NULL;
    while(head!=NULL){
      if(head->key==key){
        if(prev == NULL){
          bucket[bucketIndex] = head->next;
        }
        else{
          prev->next = head->next;
        }
        V value = head->value;
        head->next = NULL;
        delete head;
        count--;
        return value;
      }
      prev = head;
      head = head->next;
    }
    return 0;
  }

  // Search
  V getValue(string key){
    int bucketIndex = getIndex(key);
    mapNode<V>* head = bucket[bucketIndex];
    while(head!=NULL){
      if(head->key==key){
        return head->value;
      }
      head=head->next;
    }
    return 0;
  }
};
