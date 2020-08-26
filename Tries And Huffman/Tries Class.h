#include"TrieNode class.h"
#include<string>
class Trie{
  TrieNode *root;
public:
  Trie(){
    root = new TrieNode ('\0');
  }

  //Insert

  //Helper Function

  void insertWord(TrieNode *root,string word){
//Base Case
    if(word.size()==0){
      root->isTerminal = true;
      return ;
    }
//Small Calculation
   TrieNode *child;
   int index = word[0]-'a';
   if(root->children[index]!=NULL){
     child = root->children[index];
   }
   else{
     child = new TrieNode(word[0]);
     root->children[index] = child;
   }

//Recursive Call
    insertWord(child,word.substr(1));
  }

  //Main Insert Function

  void insertWord(string word){
    insertWord(root,word);
  }

//Search

//Helper
  bool search(TrieNode *root,string word){
    //Base Case
    if(word.size()==0){
      return root->isTerminal;
    }
    //Small Calculation
    bool ans;
    TrieNode *child;
    int index = word[0]-'a';
    if(root->children[index]==NULL){
      return false;
    }
    else{
      child = root->children[index];
      ans = search(child,word.substr(1));
    }

    return ans;
  }

//Main Function
  bool search(string word){
    return search(root,word);
  }

//Remove word
  //Helper function
  void removeWord(TrieNode *root, string word){
    if(word.size()==0){
      root->isTerminal = false;
      return;
    }

    TrieNode *child;
    int index = word[0]-'a';
    if(root->children[index]!=NULL){
      child = root->children[index];
    }
    else{
      return;
    }
    removeWord(child,word.substr(1));
    //Remove Useless letters

    if(child->isTerminal==false){
      for(int i=0;i<26;i++){
        if(root->children[i]!=NULL){
          return;
        }
      }
    else{
        delete child;
        root->children[i] = NULL;
      }
  }

  //Main function

  void removeWord(string word){
    removeWord(root,word);
  }



};
