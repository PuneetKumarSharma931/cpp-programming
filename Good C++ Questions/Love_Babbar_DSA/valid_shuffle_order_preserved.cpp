
#include<iostream>

using namespace std;

bool isShuffled(string s1, string s2, string res) {

    int n1 = s1.length();
    int n2 = s2.length();
    int rn = res.length();

    if(rn!=(n1 + n2))
        return false;

    int i = 0;
    int j = 0;
    int k = 0;
    bool shuffled = true;

    while(i<n1 && j<n2) {

        if(s1[i]==res[k]) {

            i++;
            k++;
        }
        else if(s2[j]==res[k]) {

            j++;
            k++;
        }
        else {
            shuffled = false;
            break;
        }
    }

    while(i<n1) {

        if(s1[i]==res[k]) {

            i++;
            k++;
        }
        else {
            shuffled = false;
            break;
        }
    }

    while(j<n2) {

        if(s2[j]==res[k]) {

            j++;
            k++;
        }
        else {
            shuffled = false;
            break;
        }
    }

    return shuffled;
}

int main() {

    string s1 = "XY";
    string s2 = "12";
    string res = "1Y2X";

    system("clear");

    if(isShuffled(s1, s2, res)) {

        cout<<"The Strings are a valid shuffle!";
    }
    else {
        cout<<"They are not a valid shuffle!";
    }

    return 0;
}