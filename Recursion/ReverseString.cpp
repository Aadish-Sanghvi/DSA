// #include<iostream>
// using namespace std;

// void reversestring(string& str, int i, int j){
//     if(i > j)
//     return;
    
//     swap(str[i],str[j]);
//     i++;
//     j--;

//     reversestring(str,i,j);
// }

// int main(){
//     string name = "aadish";
//     int i = 0;
//     int j = 5;

//     reversestring(name,i,j);
//     cout<<name;
    
//     return 0;
// }


// using only one pointer
#include<iostream>
using namespace std;
void reversestring(string& str, int i){
    
    int j = str.length()- i - 1;
    
    if(i > j)
    return;
    
    swap(str[i],str[j]);
    i++;
    reversestring(str,i);
}

int main(){
    string name = "aadish";
    int i = 0;
    reversestring(name,i);
    cout<<name;
    
    return 0;
}