#include <iostream>
using namespace std;
int main()
{
    char ch;
    int num1, num2;
    cin>>ch;
    do
    {
        switch (ch)
        {
        case '+':
            cin >> num1 >> num2;
            cout << num1 + num2 << endl;
            break;
        case '-':
            cin >> num1 >> num2;
            cout << num1 - num2 << endl;
            break;
        case '*':
            cin >> num1 >> num2;
            cout << num1 * num2 << endl;
            break;
        case '/':
            cin >> num1 >> num2;
            cout << num1 / num2 << endl;
            break;
        case '%':
            cin >> num1 >> num2;
            cout << num1 % num2 << endl;
            break;
        default:
            cout << "Invalid operation. Try again." << endl;
            break;
        }
        cin>>ch;
    } while (ch != 'X' and ch != 'x');
    return 0;
}