#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <sstream>

int main() {
	string cstr;                                            
    int A[100]; // cstr 에사 나눠진 수 배열
    char str[100];// cstr 에서 나눠진 기호 배열 
	int temp;
    int num = 0;
    int i, j = 0;
    int answer;
	printf("3가지 수를 입력 : ");
	getline(cin , cstr);
    int loop = cstr.length();
    for (i=0;i<loop;i++) {
        temp = (cstr[i] - '0');
        if ((temp>=0) && (temp<=9)) {
            num = num * 10 + temp;
        }
        else {
            if (cstr[i] == ' ') {
                continue;
            }
            A[j] = num;
            num = 0;
            str[j] = cstr[i];
            j++;
              
        }
    }
    for (int i = 0; i < j; i++) printf("%d ", A[i]);
    for (int i = 0; i < j; i++) printf("%c ", str[i]);
    answer = A[0];                                      //ex) A = 7,4,5 str = + - * 
    for (i = 1; i < j; i++) {
        
         switch (str[i-1]) {
        case '+' : 
            answer += A[i]; 
            break;
        case '-' : 
            answer -= A[i];
            break;
        case '*' :
            answer *= A[i];
            break;
        case '/' :
            answer /= A[i];
            break;


        }
       

    }

    printf("%d", answer);
									
								

    return 0;
}