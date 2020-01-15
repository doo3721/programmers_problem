/*
 * 계산법
 * budgets의 총 합을 계산한 후 M보다 큰 지 비교한다
 * M이 더 크거나 같다면, budgets의 최대값을 리턴한다
 * M이 더 작으면, budgets의 총 합과 M의 차를 구한다. 이를 diff라고 합니다
 * M을 budgets의 크기만큼 나눕니다. 이를 mark라고 합니다
 * mark를 기준으로, mark보다 큰 수들을 다 더합니다. 이를 max_sum이라고 합니다
 * max_sum - diff를 한 뒤, max_sum을 구할때 더한 성분의 갯수만큼 나눕니다.
 * 이를 통해 나온 값보다 max_sum의 성분 중 낮은 값이 존재하면,
 * 그 수 들을 제외하고 다시 max_sum을 구해 반복 합니다.
 * 나온 값이 max_sum의 성분 중 최솟값보다 작거나 같다면, 이 값을 리턴합니다.
 * 결과 값의 소숫점은 생략됩니다
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int sum, mark, diff, max_sum, count;
    double stand = 0.0;
    vector<int>::reverse_iterator riter = budgets.rbegin();
    sort(budgets.begin(), budgets.end());
    
    sum = 0;
    for(int budget: budgets) sum += budget;
    
    if(sum <= M) { answer = budgets.back(); return answer;}
    
    diff = sum - M;
    mark = M/budgets.size();
    
    count = 0; max_sum = 0;
    for(; *riter > mark; riter++) {
        max_sum += *riter;
        count++;
    }
    
    stand = (double) (max_sum - diff)/count;
    
    --riter;
    while(stand > *riter) {
        max_sum -= *riter;
        count--;
        stand = (double) (max_sum - diff)/count;
        riter--;
    }
    
    answer = stand;
    
    
    return answer;
}

int main(void) {
    vector<vector<int>> budgets = {{120, 110, 140, 150},
                                   {120, 110, 140, 150},
                                   {120, 110, 140, 150},
                                   {1, 21, 22, 23, 24}};
    int M[4] = {485, 452, 520, 88};

    for(int i=0; i < budgets.size(); i++) {
        cout << solution(budgets[i], M[i]) << endl;
    }

    vector<vector<int>>().swap(budgets);

    return 0;
}