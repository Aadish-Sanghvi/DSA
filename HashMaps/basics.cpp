#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

// unorder map -> key n values ka random order hota hai and T.C = o(constant)
// order map -> key n values ka secquence me order hota hai and T.C = o(logn)

int main(){
    //creation:-
    map<string, int> m;

    //insertion:-
    //1
    pair<string, int> p = make_pair("babbar",1);
    m.insert(p);
    //2
    pair<string, int> q("love", 2);
    m.insert(q);
    //3
    m["bhaiya"] = 3;

    //search
    cout << m.at("babbar") << endl;
    cout << m["babbar"] << endl;

    cout << m["unknown"] << endl; // create a value '0' for the key
    cout << m.at("unknown") << endl; // it does not create a value '0' for the key

    //size
    cout << m.size() << endl;

    // to check presence of the value corrosponding to key
    cout << m.count("love") << endl;

    //eraze
    m.erase("love");
    cout << m.size() << endl;

    //access
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    //iterator
    map<string, int> :: iterator it = m.begin();
    while(it != m.end()){
        cout << it -> first << " " << it -> second << endl;
        it++;
    }
}