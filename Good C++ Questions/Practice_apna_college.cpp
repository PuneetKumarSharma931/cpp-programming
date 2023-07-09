
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int main() {

    system("clear");
    int n;
    int k;

    cout<<"Input Data: "<<endl;
    
    cin>>n;
    cin>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++) {

        cin>>a[i];
    }

    multiset<int,greater<int> > st;
    vector<int> ans;

    for(int i=0;i<k;i++) {

        st.insert(a[i]);
    }

    ans.push_back(*st.begin());

    for(int i=k;i<n;i++) {

        st.erase(st.lower_bound(a[i-k]));
        st.insert(a[i]);
        ans.push_back(*st.begin());
    }

    for(int i=0;i<ans.size();i++) {

        cout<<ans[i]<<" ";
    }


    return 0;
}