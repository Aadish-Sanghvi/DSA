#include<iostream>
using namespace std;
void checkpalindrom(string str, int i, int j){
    
    if(i > j)
    {
    	cout<<"yes it is palindrome";
    	return ;
    }
    
    if(str[i]!=str[j])
    {
    	cout<<"no it is not palindrome";
    	return;
	}
    else
	{
        i++;
        j--;
    }
    checkpalindrom(str,i,j);
}

int main(){
    string name = "abccba";
    int i = 0;
    int j = name.length() - 1;
    checkpalindrom(name,i,j);

	return 0;
}