#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char op;
    float num1, num2;

    
    cout << "Enter operator (+, -, *, /): ";
    cin >> op;
   
    cout << "Enter two operands: ";
    cin>>num1>>num2;

    switch (op) {
// If user enters +
    case '+':
        cout << "Result: " << num1 + num2;
        break;
// If user enters -
    case '-':
        cout << "Result: " << num1 - num2;
        break;
// If user enters *
    case '*':
        cout << "Result: " << num1 * num2;
        break;
// If user enters /
    case '/':
    if (num2 != 0) {
        cout << "Result: " << fixed << setprecision(2) <<num1 / num2;
    } else {
        cout << "Error! Division by zero is not allowed.";
    }
    break;

default:
    cout << "Error! Operator is not correct";
} 
return 0;
}
