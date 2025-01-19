#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> bracket_stack;  // 괄호를 저장하는 스택
    int total_pieces = 0;       // 총 잘려진 쇠막대기의 조각 수
    string input;               // 입력 문자열

    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '(') {
            bracket_stack.push(input[i]);  // 여는 괄호를 스택에 추가
        }
        else { // input[i] == ')'
            if (input[i - 1] == '(') {
                // 레이저인 경우
                bracket_stack.pop();      // 레이저의 여는 괄호 제거
                total_pieces += bracket_stack.size();  // 현재 스택 크기만큼 조각 추가
            }
            else {
                // 쇠막대기의 끝인 경우
                bracket_stack.pop();      // 쇠막대기의 끝을 처리
                total_pieces++;           // 하나의 조각 추가
            }
        }
    }

    cout << total_pieces << "\n";

    return 0;
}
