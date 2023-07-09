
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<array>

using namespace std;


vector<vector<int> > findConflictingAppointments(array<int, 2> arr[6], int m, int n) {

    vector<vector<int> > ans;
    set<vector<int> > s;
    vector<int> temp;
    int Max = -1;
    int Min = -1;

    for(int i=0; i<m; i++) {

        if(i==0) {

            Min = arr[i][0];
            Max = arr[i][1];

            continue;
        }

        if(arr[i][0] >= Min && arr[i][0] <= Max || arr[i][0] <= Min && arr[i][1] >= Max || arr[i][0] <= Min && arr[i][1] >= Max) {

            temp.push_back(arr[i][0]);
            temp.push_back(arr[i][1]);

            s.insert(temp);

            temp.clear();

            Min = min(Min, arr[i][0]);
            Max = max(Max, arr[i][1]);
        }
        else {

            Min = min(Min, arr[i][0]);
            Max = max(Max, arr[i][1]);
        }
    }

    for(auto iter : s) {

        ans.push_back(iter);
    }

    return ans;
}

int main() {

    array<int, 2> arr[6] = {{1,5},
    {3,7},
    {2,6},
    {10,15},
    {5,6},
    {4,100}
    };

    system("clear");

    vector<vector<int> > ans;

    ans = findConflictingAppointments(arr, 6, 2);

    for(int i=0; i<ans.size(); i++) {

        for(int j=0; j<ans[0].size(); j++) {

            cout<<ans[i][j]<<" ";
        }

        cout<<endl;
    }

    return 0;
}