#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

/*
 * 문제 영역
 */
vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size(), 0);
    stack<int> st;
    int i,j;
    
    for(i = 1; i < heights.size(); i++) {
        for(j=0; j < i; j++) st.push(heights[j]);
        
        int temp = i;
        
        while(!st.empty()) {
            
            if(st.top() > heights[i]) {
                answer[i] = temp;
                while(!st.empty()) st.pop();
                break;
            }
            else {
                st.pop();
                temp--;
            }
        } 
    }
    
    return answer;
}

/*
 * 테스트 영역
 */
int main()
{
    int h1[5] = {6,9,5,7,4};
    int h2[7] = {3,9,9,3,5,7,2};
    int h3[7] = {1,5,3,6,7,6,5};

    vector<int> heights;

    for(int height: h1) heights.push_back(height);
    for(int tower: solution(heights)) cout << tower << " ";
    cout << endl;
    heights.clear();

    for(int height: h2) heights.push_back(height);
    for(int tower: solution(heights)) cout << tower << " ";
    cout << endl;
    heights.clear();

    for(int height: h3) heights.push_back(height);
    for(int tower: solution(heights)) cout << tower << " ";
    cout << endl;
    vector<int>().swap(heights);

    return 0;
}