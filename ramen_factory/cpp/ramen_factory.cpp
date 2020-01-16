#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int j = 0;
    priority_queue<int> pri_que;

    for (int i = 0; (stock < k) && (i<k); i++) {

        if (dates[j] == i) {
            pri_que.push(supplies[j]);
            if (j < supplies.size()) j++;
        }

        if (stock == 0) {
            stock += pri_que.top();
            pri_que.pop();
            answer++;
        }

        stock--;
    }

    priority_queue<int>().swap(pri_que);
    
    return answer;
}

int main(void) {

    int stock = 4;
    vector<int> dates = {4,10,15};
    vector<int> supplies = {20,5,10};
    int k = 30;

    cout << solution(stock, dates, supplies, k) << endl;

    vector<int>().swap(dates);
    vector<int>().swap(supplies);

    return 0;
}