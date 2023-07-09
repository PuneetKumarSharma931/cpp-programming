
#include<iostream>

using namespace std;

bool isRotated(string s1, string s2) {

    int n = s1.length();
    int count = 1;
    int pos = -1;
    int i;

    for(i=0;i<n;i++) {

        if(s1[0]==s2[i]) {

            pos = i;
            break;
        }
    }

    if(pos==-1)
        return false;

    i = 0;

    while(count<=n) {

        if(s1[i]!=s2[pos])
            return false;

        i++;
        pos = (pos + 1)%n;
        count++;

    }

    return true;

}

int main() {

    string s1 = "Puneet";
    string s2 = "eePtun";

    system("clear");

    if(isRotated(s1, s2)) {

        cout<<"The Strings are rotated!";
    }
    else {

        cout<<"They are not rotated!";
    }

    return 0;
}