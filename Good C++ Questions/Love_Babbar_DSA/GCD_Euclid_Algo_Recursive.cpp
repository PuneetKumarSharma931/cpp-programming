
#include<iostream>

using namespace std;

int GCD_Recursive(int num1, int num2) {

    if(num1==0) {

        return num2;
    }

    if(num2==0) {

        return num1;
    }

    if(num1<num2) {

        return GCD_Recursive(num1, num2-num1);
    }
    else {

        return GCD_Recursive(num1 - num2, num2);
    }

    return 1;
}

int main() {

    system("clear");

    cout<<"The GCD is: "<<GCD_Recursive(72, 24);

    return 0;
}