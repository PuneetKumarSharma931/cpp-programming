
#include<iostream>
#define max_row 8
#define max_column 8

using namespace std;

void Input(int arr[max_row][max_column], int m, int n) {

    for(int i=0;i<m;i++) {

        for(int j=0;j<n;j++) {

            cin>>arr[i][j];
        }

        cout<<endl;
    }
}

void Output(int arr[max_row][max_column], int m, int n) {

    for(int i=0;i<m;i++) {

        for(int j=0;j<n;j++) {

            cout<<arr[i][j]<<" ";
        }

        cout<<endl;
    }
}

int main() {

    system("clear");

    int p,q,r,s;
    int A[max_row][max_column],B[max_row][max_column],C[max_row][max_column];

    cout<<endl<<"Input the rows and columns of first matrix: ";
    cin>>p>>q;

    cout<<endl<<"Input the rows and columns of second matrix: ";
    cin>>r>>s;

    if(q==r) {

        cout<<endl<<"Input First Matrix: "<<endl;
        Input(A, p, q);
        cout<<endl<<"Input Second Matrix: "<<endl;
        Input(B, r, s);

        cout<<endl<<"The two matrices are: "<<endl;
        Output(A, p, q);
        cout<<endl;
        Output(B, r, s);


        for(int i=0;i<p;i++) {

            for(int j=0;j<s;j++) {

                C[i][j] = 0;

                for(int k=0;k<q;k++) 
                C[i][j]+=A[i][k]*B[k][j];
            }
        }

        cout<<endl<<"Matrix after Mutiplication of the two matrices is"<<endl;
        Output(C, p,s);

    }
    else {
        cout<<endl<<"Error!! for multiplication the number of columns of first matrix must be equal to the number of rows of the second matrix";
    }

    return 0;
}