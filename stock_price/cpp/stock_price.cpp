/*
 * 해당 시점에서 가격이 떨어질때까지의 시간을 계산
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int time;
    
    for(int i=0; i < prices.size(); i++) {
        time = 0;
        
        for(int j=i+1; j < prices.size(); j++) {
            if(prices[i] > prices[j]) {
                time++;
                break;
            }
            else time++;
        }
        
        answer.push_back(time);
    }
    
    return answer;
}

int main(void) {
    vector<int> prices = {1,2,3,2,3};

    for(int result: solution(prices)) {
        cout << result << " ";
    }
    cout << endl;

    vector<int>().swap(prices);

    return 0;
}