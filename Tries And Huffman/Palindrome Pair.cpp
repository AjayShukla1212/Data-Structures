
#include <bits/stdc++.h>
using namespace std;

#include <string>
#include <vector>

class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    // For user
    void add(string word)
    {
        if (add(root, word))
        {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    bool swapcheck(string temp){
        int i= 0;
        int j=temp.size()-1;
        while(i<j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    bool isPalindromePair(vector<string> words)
    {
        if(words.size()==1){
            return swapcheck(words[0]);
        }
        int size = words.size();
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(i!=j){
                    string temp = words[i]+words[j];
                    add(temp);
                    bool pali = swapcheck(temp);
                    if(pali==true){
                        return true;
                    }
                }
            }
        }
		//Write your code here
        return false;
    }

};




int main()
{
	Trie t;
	int n;
  cout <<"Enter The Number Of Words You Want To Enter : ";
	cin >> n;
  cout <<"Enter The Words :"<<endl;
	vector<string> words(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> words[i];
	}
	bool ans = t.isPalindromePair(words);
  cout <<"::: ";
	if (ans)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}
