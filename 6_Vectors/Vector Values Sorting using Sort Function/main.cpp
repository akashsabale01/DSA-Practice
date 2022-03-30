#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcTotalMarks(vector<int> marks)
{
    return marks[0]+ marks[1] + marks[2];
}

bool compare(pair<string,vector<int>> s1, pair<string,vector<int>> s2)
{
    vector<int> m1 = s1.second;
    vector<int> m2 = s2.second;
    return calcTotalMarks(m1)>calcTotalMarks(m2);
}

int main()
{
    vector< pair<string,vector<int>> > student_marks = {
        {"John",{10,20,11}},
        {"Tom",{10,21,3}},
        {"Brad",{4,5,6}},
        {"Elon",{10,13,20}}
    };

    sort(student_marks.begin(),student_marks.end(),compare);

    for(int i=0;i<int(student_marks.size());i++)
    {
        cout<<student_marks[i].first<<" "<<calcTotalMarks(student_marks[i].second)<<endl;
    }
    return 0;
}
