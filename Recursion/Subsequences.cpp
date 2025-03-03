// #include<iostream>
// #include<vector>
// using namespace std;

// void helper(string s, string tempans, int index){
//     if(s.size() == index){
//         cout<<tempans<<" ";
//         return;
//     }
//     //take
//     helper(s,tempans+s[index],index+1);
//     //not take
//     helper(s,tempans,index+1);
// }

// vector<string> allpossstring(string s){
//     vector<string> ans;
//     helper(s,"",0);
//     return ans;
// }

// int main(){
//     string name = "aadi";
//     allpossstring(name);
//     return 0;
// }


//Using only one function 
#include<iostream>
#include<vector>
using namespace std;
vector<string> ans;
vector<string> helper(string s, string tempans, int index){
    //vector<string> ans;
    if(s.size() == index){
        cout<<tempans<<" ";
        return ans;
    }
    //take
    helper(s,tempans+s[index],index+1);
    //not take
    helper(s,tempans,index+1);
    return ans;
}

int main(){
    string name = "aadi";
    helper(name,"",0);
    return 0;
}