#include<iostream>
using namespace std;

class trieNode{
public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class trie{
public: 
    trieNode* root;

    trie(){
        root = new trieNode('\0');
    }

    void insertUtil(trieNode* root, string word){
        //base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        //assumption, word will be in CAPS
        int index = word[0] - 'A';
        trieNode* child;

        //present 
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }

        //absent
        else{
            child = new trieNode(word[0]);
            root -> children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(trieNode* root, string word){
        //base case
        if(word.length() == 0){
            return root -> isTerminal;
        }
        int index = word[0] - 'A';
        trieNode* child;

        //present 
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            //absent 
            return false;
        }  
        return searchUtil(child, word.substr(1));
    }
    
    bool searchWord(string word){
        return searchUtil(root, word);
    }

    void removeUtil(trieNode* root, string word){
        //base case
        if(word.length() == 0){
            root -> isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        trieNode* child;

        //present 
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            //absent 
            return;
        }
        removeUtil(child, word.substr(1));
    }

    void removeWord(string word){
        removeUtil(root, word);
        return;
    }

    // To check if string is present or not with the given prefix.
    bool startsWithUtil(trieNode* root, string prefix){
         if(prefix.length() == 0){
            return true;
        }
        int index = prefix[0] - 'A';
        trieNode* child;

        //present 
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else{
            //absent 
            return false;
        }
        return startsWithUtil(child, prefix.substr(1));
    }

    bool startsWith(string prefix){
        return startsWithUtil(root, prefix);
    }
};

int main(){
    trie *t = new trie();
    t -> insertWord("ABCD");
    t -> insertWord("TIME");
    t -> insertWord("ARM");

    cout << "before removing: " << endl;
    cout << t -> searchWord("TIME") << endl;

    t -> removeWord("TIME");

    cout << "after removing: " << endl;
    cout << t -> searchWord("TIME") << endl;

    string prefix = "TIMER";
    cout << "Check the word with given prefix it's: " << t -> startsWith(prefix) << endl;

    return 0;
}