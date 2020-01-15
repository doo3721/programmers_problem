/*
 * 계산법
 * budgets의 크기를 numbers에 저장하고, budgets을 정렬한다
 * 반복자로 처음부터 순회하면서, 해당 반복자와 M/numbers를 비교한다
 * 해당 반복자가 크면 M/numbers를 반환
 * 아니면 M에서 해당 반복자를 빼고, 원소갯수(numbers)를 줄인다
 * 끝까지 순회한 경우(예산이 충분한 경우), budgets의 마지막 원소를 반환한다
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int numbers = budgets.size();

    sort(budgets.begin(),budgets.end());

    for(auto itr=budgets.begin(); itr!= budgets.end(); itr++){
        if(*itr > (M / numbers)) return M/numbers;
        else{
            M -= *itr;
            numbers--;
        }
    }

    return budgets.back();
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