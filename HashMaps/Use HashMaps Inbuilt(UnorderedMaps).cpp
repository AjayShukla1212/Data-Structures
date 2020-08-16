#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main(){
  unordered_map<string,int> ourmap;
  pair<string,int> p("abc",1);
  ourmap.insert(p);
  ourmap["ajay"] = 2;
  cout <<"Size : "<<ourmap.size()<<endl;
  cout <<ourmap.at("ajay")<<endl;
  cout <<ourmap.at("abc")<<endl;
  ourmap["Kumar"] = 5;
  cout <<"Size : "<<ourmap.size()<<endl;
  if(ourmap.count("ghi")>0){
    cout <<"ghi is present"<<endl;
  }
  else{
    cout <<"ghi is not present"<<endl;
  }
}
