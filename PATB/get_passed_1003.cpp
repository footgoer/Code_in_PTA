#include <iostream>
#include <string>
using namespace std;

int main()
{
    int times, flag = 1;
    string s;
    cin >> times;
    for ( int i=0; i<times; i++ ) {
        flag = 1;  //judge YES or NO
        cin >> s;
        int len = s.length();
        int a_f=0, a_m=0, a_l=0;
        int numt=0, nump=0;
        //body of judge
        for ( int j=0; j<len; j++ ) {
            char c = s[j];
            if ( c!='P' && c!='A' && c!='T' ) {
                flag = 0;
                break;
            }

            if ( c == 'P' ) {
                nump++;
                if ( nump > 1 || numt != 0 ) {
                    flag = 0;
                    break;
                }
            } else if ( c == 'T' ) {
                numt++;
                if ( numt > 1 || nump != 1 ) {
                    flag = 0;
                    break;
                }
            } else if ( c == 'A' ) {
                if ( numt == 0 && nump == 0 ) {
                    a_f++;
                } else if ( numt == 0 && nump == 1 ) {
                    a_m++;
                } else if ( numt == 1 && nump == 1 ) {
                    a_l++;
                }
            }
        }
        
        if ( flag == 1 ) {
            //judge the case: 1P, 0T, like PA
            if ( nump !=1 || numt !=1 ) {
                flag = 0;
            }
            //judge the number of A
            if ( a_m == 0 ) {
                flag = 0;
            } else {
                if ( a_l != (a_m*a_f) ) {
                    flag = 0;
                }
            }
        }

        //output res
        if ( i != 0 ) cout << endl;
        if ( flag == 1 ) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }

    return 0;
}