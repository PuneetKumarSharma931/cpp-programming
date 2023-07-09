#include <iostream>

using namespace std;

int main() {
	
	int T;
	int N;
	int count = 0;
	int temp;

	cin>>T;

	for(int i=0;i<T;i++) {

		cin>>N;
		int arr[N];
		count = 0;
		int swap = 0;

		for(int j=0;j<N;j++)
			cin>>arr[j];

		for(int k=0;k<N-1;k++) {

			swap = 0;

			for(int l=k;l<N-1;l++) {

				if(arr[l]==1 && arr[l+1]==0) {

					temp = arr[l];
					arr[l] = arr[l+1];
					arr[l+1] = temp;
					count++;
					l = l+1;
					swap++;
				}
			}

			if(swap==0)
				break;
		}

		cout<<count<<endl;

	}

	return 0;
}
