/*
In This Program I have tried to check the implementation of templates !!!
*/






#include<iostream>
using namespace std;

template<typename T, typename V>
class Pair{
  T x;
  V y;
public:
  void setX(T x)
  {
    this->x = x;
  }
  T getX(){
    return x;
  }
  void setY(V y)
  {
    this->y = y;
  }
  V getY(){
    return y;
  }
};

int main()

{
  Pair <Pair<int,int> , string> p1;
  Pair <int,int> p2;
  p2.setX(15);
  p2.setY(16);
  p1.setX(p2);
  p1.setY("Ajay");
  cout <<p1.getX().getX() <<" "<<p1.getX().getY()<<" "<<p1.getY()<<endl;
}
