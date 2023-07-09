
#include<iostream>

using namespace std;

bool checkPalindrome(string str, int i, int j) {

    if(i>j) {

        return true;
    }

    if(str[i]!=str[j])
        return false;

    i++;
    j--;

    return checkPalindrome(str, i, j);
} 

int main() {

    string str = "racecar";

    system("clear");

    if(checkPalindrome(str, 0, str.length()-1)) {

        cout<<"Palindrome!";
    }
    else {

        cout<<"Not Palindrome!";
    }
    
    return 0;
}