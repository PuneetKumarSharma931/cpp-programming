
#include<iostream>

using namespace std;

string reverseString(string str) {

    if(str.length()==1) {

        return str;
    }

    swap(str[0], str[str.length()-1]);

    string stri = reverseString(str.substr(1, str.length()-1));

    return stri;
    
}

int main() {

    system("clear");

   string str = "I am an engineer!";

    string temp = reverseString(str);

   cout<<temp<<endl;

    return 0;
}