template<typename T>
class BTN{
public:
  T data;
  BTN* left;
  BTN* right;
  BTN(T data){
    this->data = data;
    left = NULL;
    right = NULL;
  }
  ~BTN(){
    delete left;
    delete right;
  }
};
