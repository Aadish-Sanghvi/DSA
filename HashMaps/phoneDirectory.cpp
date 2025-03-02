#include<iostream>
using namespace std;


class trieNode{
public:
    char data;
    trieNode* children[26];
    int childCount;
    bool isTerminal;

    trieNode(char ch){
        data = ch;
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class trie{
public: 
    trieNode* root;

    trie(char ch){
        root = new trieNode(ch);
    }

    void insertUtil(trieNode* root, string word){
        //base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        //assumption, word will be in CAPS
        int index = word[0] - 'a';
        trieNode* child;

        //present 
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }

        //absent
        else{
            root -> childCount++;
            child = new trieNode(word[0]);
            root -> children[index] = child;
        }

        //recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }
};

