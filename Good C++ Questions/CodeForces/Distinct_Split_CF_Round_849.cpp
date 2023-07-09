
#include <iostream>
#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

int main() {
    
    int t;
    int n;
    int ans;
    unordered_set<char> st;
    
    cin>>t;
    
    for(int i=0; i<t; i++) {
        
        string s;
        
        cin>>n;
        cin>>s;
        
        ans = INT_MIN;
        
        vector<int> ldp(n, 0);
        vector<int> rdp(n, 0);
        
        st.clear();
        
        st.insert(s[0]);
        
        ldp[0] = 1;
        
        for(int j=1; j<n; j++) {
            
            if(st.find(s[j]) == st.end()) {
                
                st.insert(s[j]);
                ldp[j] = ldp[j-1] + 1;
            }
            else {
                
                ldp[j] = ldp[j-1];
            }
        }
        
        st.clear();
        
        st.insert(s[n-1]);
        
        rdp[n-1] = 1;
        
        for(int j=n-2; j>=0; j--) {
            
            if(st.find(s[j]) == st.end()) {
                
                st.insert(s[j]);
                rdp[j] = rdp[j+1] + 1;
            }
            else {
                
                rdp[j] = rdp[j+1];
            }
        }
        
        for(int i=0; i<n-1; i++) {
            
            ans = max(ans, ldp[i] + rdp[i+1]);
        }
        
        cout<<ans<<endl;
        
    }
    
    return 0;
}