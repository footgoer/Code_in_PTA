#include <iostream>
#include <stack>
using namespace std;

string num2pingyin( int num ) {
    string res;
    switch (num) {
        case 0: res = "ling"; break;
        case 1: res = "yi"; break;
        case 2: res = "er"; break;
        case 3: res = "san"; break;
        case 4: res = "si"; break;
        case 5: res = "wu"; break;
        case 6: res = "liu"; break;
        case 7: res = "qi"; break;
        case 8: res = "ba"; break;
        case 9: res = "jiu"; break;
        default: break;
    }

    return res;
}

int main()
{
    char c;
    int sum = -1;
    while ( cin >> c ) {
        // cout << c;
        sum = sum + (int)(c-'0');
    }
    
    stack<int> s;
    do {
        s.push(sum%10);
        sum = sum/10;
    } while ( sum != 0 );

    int flag = 0;
    while ( s.size() != 0 ) {
        if ( flag == 0 ) {
            flag = 1;
        } else {
            cout << " ";
        }
        cout << num2pingyin(s.top());
        s.pop();
    }


    return 0;
}