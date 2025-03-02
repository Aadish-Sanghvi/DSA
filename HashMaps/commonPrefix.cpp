#include<iostream>
#include<string>
#include<vector>
using namespace std;

// // Approach - 1
// string longestCommonPrefix(vector<string> &arr, int n){
//     string ans = ""; 

//     // for traversing all char of first string
//     for(int i = 0; i < arr[0].length(); i++){
//         char ch = arr[0][i];
//         bool match = true;

//         // for traversing rest of the words
//         for(int j = 1; j<n; j++){
//             // not match
//             if(arr[0].size() > arr[j].size() || ch != arr[j][i]){
//                 match = false;
//                 break;
//             }
//         }
//         if(match  == false){
//             break;
//         }
//         else{
//             ans.push_back(ch);
//         }
//     }
// return ans;
// }



// Approach - 2 

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

    string lcp(string str, string &ans){
        for(int i = 0; i < str.length(); i++){
            char ch = str[i];

            if(root -> childCount == 1){
                ans.push_back(ch);
                //aage badho
                int index = ch - 'a';
                root = root -> children[index];
            }
            else{
                break;
            }
            if(root -> isTerminal){
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n){
    trie *t = new trie('\0');
    for(int i = 0; i < n; i++){
        t -> insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t -> lcp(first,ans);

    return ans;
}

int main(){
    vector<string> arr;
    arr.push_back("coding");
    arr.push_back("codzen");
    arr.push_back("codizz");
    arr.push_back("coders");

    string prefix = longestCommonPrefix(arr, 4);
    cout << "The longest string prefix is: " << prefix << endl;

    return 0;
}