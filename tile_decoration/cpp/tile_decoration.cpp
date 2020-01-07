/*
 * 직사각형 둘레의 길이
 * = 2*(N+1의 정사각형 한 변의 길이 + N의 정사각형 한 변의 길이)
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    long long m[80];
    m[0] = m[1] = 1;
    
    for(int i=2; i <= N; i++) {
        m[i] = m[i-1] + m[i-2];
    }
    
    answer = 2*(m[N]+m[N-1]);
    return answer;
    
}

int main(void) {
    int N[2] {5, 6};

    for(auto num: N) cout << solution(num) << " ";
    cout << endl;

    return 0;
}