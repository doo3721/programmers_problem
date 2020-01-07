/*
 * x: 홀수번째 숫자, y: 짝수번째 숫자
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long x = 1, y = 1;

    for (int n = 2; n <= N; n++) {
        if (n % 2)  y += x;
        else        x += y;
    }
    return 2*(x+y);
}

int main(void) {
    int N[2] {5, 6};

    for(auto num: N) cout << solution(num) << " ";
    cout << endl;

    return 0;
}