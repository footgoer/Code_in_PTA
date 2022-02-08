#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Stu {
    string name;
    string no;
    int grade;
} s[101]; 

struct Rule1 {
    bool operator () ( Stu s1, Stu s2 ) {
        return s1.grade > s2.grade;
    }
};

struct Rule2 {
    bool operator () ( Stu s1, Stu s2 ) {
        return s1.grade < s2.grade;
    }
};

int main()
{
    int num;
    cin >> num;
    // scanf("%d\n", &num);
    // cout << num;
    for ( int i=0; i<num; i++ ) {
        // scanf("%s %s %d\n", s[i].name, s[i].no, &s[i].grade);
        cin >> s[i].name >> s[i].no >> s[i].grade;
        // cout << s[i].name << s[i].no << s[i].grade << endl;
    }

    sort(s, s+num, Rule1());
    cout << s[0].name << " " << s[0].no << endl;
    sort(s, s+num, Rule2());
    cout << s[0].name << " " << s[0].no << endl;
    return 0;
}