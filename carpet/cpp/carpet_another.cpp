/*
 * w + h = brown/2 + 2
 * w * h = brown + red
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {

    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while(w >= h){
        if(w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}

int main(void) {

    vector<int> brown = {10,8,24};
    vector<int> red = {2,1,24};

    for(int i=0; i < brown.size(); i++) {
        for(int result: solution(brown[i], red[i]))
            cout << result << " ";
        cout << endl;
    }

    vector<int>().swap(brown);
    vector<int>().swap(red);

    return 0;
}