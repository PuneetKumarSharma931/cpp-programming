
#include<iostream>

using namespace std;

int GCD(int num1, int num2) {

    while(num1>0 && num2>0) {

        if(num1<num2) {

            num2 = num2 - num1;
        }
        else {

            num1 = num1 - num2;
        }
    }

    if(num1!=0)
        return num1;

    return num2;
}

int main() {

    system("clear");

    cout<<"The GCD is: "<<GCD(47, 97);

    return 0;
}