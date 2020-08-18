#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;
char* uniqueChar(char *str){
    // Write your code here
    char *output;
    int k=0;
    unordered_map<char,bool> ourmap;
    for(int i=0;i<strlen(str);i++){
        if(ourmap.count(str[i])>0){
            continue;
        }
        ourmap[str[i]] = true;
        output[k++] = str[i];

    }
    output[k] = '\0';
    return output;
}

int main() {

	char input[1000000];
  cout <<"Enter The Input String : ";
	cin >> input;
	cout << uniqueChar(input) << endl;
}
