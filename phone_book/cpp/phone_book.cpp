#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 조합처럼 순회하여 풀어준다
    for(int i = 0; i < phone_book.size(); i++) {
        for(int j = i+1; j <phone_book.size(); j++) {
            if(phone_book[i].length() < phone_book[j].length()) {
                if(phone_book[j].find(phone_book[i]) == 0) {
                    answer = false;
                    break;
                }
            }
            else {
                if(phone_book[i].find(phone_book[j]) == 0) {
                    answer = false;
                    break;
                }
            }
        }

        if(!answer) break;
    }

    return answer;
}

int main(void) {
    vector<vector<string>> phone_books = {{"119", "97674223", "1195524421"},
                                            {"123", "456", "789"},
                                            {"12", "123", "1235", "567", "88"}};
    
    for(vector<string> phone_book: phone_books) {
        cout << solution(phone_book) << endl;
    }

    vector<vector<string>>().swap(phone_books);

    return 0;
    
}