#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;

    for (int i = 0; i < progresses.size(); ++i)
    {
        // 프로세스를 완료되는 데 걸리는 시간
        day = (99 - progresses[i]) / speeds[i] + 1;

        /* 
         * 현재 시간이 앞의 시간보다 크면 answer에 원소 추가
         * 그렇지 않으면, answer의 마지막 원소에 +1 추가
         */
        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        // 현재 시간이 앞의 시간보다 크면, 갱신
        if (max_day < day)
            max_day = day;
    }

    return answer;
}

int main(void) {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    for(auto result: solution(progresses, speeds)) {
        cout << result << " ";
    }
    cout << endl;

    vector<int>().swap(progresses);
    vector<int>().swap(speeds);

    return 0;
}