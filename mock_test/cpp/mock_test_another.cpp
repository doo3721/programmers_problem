#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> they(3);

    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) they[0]++;
        if(answers[i] == two[i%two.size()]) they[1]++;
        if(answers[i] == thr[i%thr.size()]) they[2]++;
    }

    // max_element는 해당 배열(vector)의 최대값의 주소나 Iterator를 반환한다
    int they_max = *max_element(they.begin(),they.end());
    for(int i = 0; i< 3; i++) {
        if(they[i] == they_max) answer.push_back(i+1);
    }

    return answer;
}

int main(void) {
    int array1[5] = {1,2,3,4,5};
    int array2[5] = {1,3,2,4,2};
    vector<int> answers;

    for(auto num: array1) answers.push_back(num);
    for(auto answer: solution(answers))
        cout << answer << " ";
    cout << endl;
    answers.clear();

    for(auto num: array2) answers.push_back(num);
    for(auto answer: solution(answers))
        cout << answer << " ";
    cout << endl;
    vector<int>().swap(answers);

    return 0;
}