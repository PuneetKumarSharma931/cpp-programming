
#include<iostream>
#define max_row 8
#define max_column 8

using namespace std;

void OutputMatrix(int arr[max_row][max_column], int m, int n) {

    for(int i=0;i<m;i++) {

        for(int j=0;j<n;j++) {

            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

class Matrix{

    int p,q,r,s;
    int A[max_row][max_column],B[max_row][max_column],C[max_row][max_column];

    public:

    void Input() {

        cout<<endl<<"Input rows and columns of first Matrix: ";
        cin>>p>>q;

        cout<<endl<<"Input rows and columns of second Matrix: ";
        cin>>r>>s;

       cout<<endl<<"Input elements of First Matrix: "<<endl;

       for(int i=0;i<p;i++) {

           for(int j=0;j<q;j++) {

               cin>>A[i][j];
           }

           cout<<endl;
       }

   cout<<endl<<"Input elements of Second Matrix: "<<endl;

   for(int i=0;i<r;i++) {

       for(int j=0;j<s;j++) {

           cin>>B[i][j];
       }

       cout<<endl;
   }

}

void Multiply() {

    if(q==r) {

        for(int i=0;i<p;i++) {

            for(int j=0;j<s;j++) {

                C[i][j] = 0;

                for(int k=0;k<q;k++) {

                    C[i][j]+=A[i][k]*B[k][j];
                }

            }
        }
    }
    else {

        cout<<endl<<"Error! Columns of First Matrix Must be equal to rows of second Matrix!";
    }
}

void Output() {

    cout<<endl<<"First Matrix is: "<<endl;
    OutputMatrix(A, p, q);

    cout<<endl<<"Second Matrix is: "<<endl;
    OutputMatrix(B, r, s);

    cout<<endl<<"Product Matrix is: "<<endl;
    OutputMatrix(C, p, s);
    
}

};



int main() {

    system("clear");

    Matrix mat;

    mat.Input();
    mat.Multiply();
    mat.Output();

    return 0;
}