
#include<iostream>
#include<unordered_map>

using namespace std;

bool isShuffle(string s1, string s2, string res) {

    int n1 = s1.length();
    int n2 = s2.length();
    int rn = res.length();

    if(rn != n1 + n2) {

        return false;
    }

    unordered_map<char, int> m;

    for(int i=0;i<rn;i++)
        m[res[i]]++;

    for(int i=0;i<n1;i++) {

        if(m.find(s1[i])==m.end()) {

            return false;
        }
        else {

            if(m[s1[i]]==0) {

                return false;
            }
            else {
                m[s1[i]]--;
            }
        }
    }

    for(int i=0;i<n2;i++) {

        if(m.find(s2[i])==m.end()) {

            return false;
        }
        else {

            if(m[s2[i]]==0) {

                return false;
            }
            else {
                m[s2[i]]--;
            }
        }
    }

    for(auto it: m) {

        if(it.second!=0) {

            return false;
        }
    }

    return true;
}

int main() {

    string s1 = "XY";
    string s2 = "12";
    string res = "X1Y2";

    system("clear");

    if(isShuffle(s1, s2, res)) {

        cout<<"Strings are valid shuffle!";
    }
    else {

        cout<<"They are not a valid shuffle!";
    }

    return 0;
}