#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int array3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int sum1, sum2, sum3;
    sum1 = sum2 = sum3 = 0;

    int i;
    for(i=0; i < answers.size(); i++) {
        if(answers[i] == array1[i%5]) sum1++;
        if(answers[i] == array2[i%8]) sum2++;
        if(answers[i] == array3[i%10]) sum3++;
    }

    if(sum1 > sum3) {
        if(sum1 > sum2) answer.push_back(1);
        else if (sum1 == sum2) {
            answer.push_back(1);
            answer.push_back(2);
        }
        else answer.push_back(2);
    }
    else if (sum1 == sum3) {
        if(sum1 > sum2) {
            answer.push_back(1);
            answer.push_back(3);
        }
        else if (sum1 == sum2) {
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else answer.push_back(2);
    }
    else {
        if(sum3 > sum2) answer.push_back(3);
        else if (sum3 == sum2) {
            answer.push_back(2);
            answer.push_back(3);
        }
        else answer.push_back(2);
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