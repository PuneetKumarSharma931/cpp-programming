
#include<iostream>
#include<vector>

using namespace std;

int main() {

    system("clear");

    string str;
    cin>>str;

    vector<int> vect(256, -1);

    int start = -1, ans = 0;

    for(int i=0;i<str.length();i++) {

        if(vect[str[i]]>start) 
        start = vect[str[i]];

        vect[str[i]] = i;

        ans = max(ans, i-start);
    }

    cout<<ans<<endl;

    return 0;
}