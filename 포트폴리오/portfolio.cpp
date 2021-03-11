#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <stack> // 스택으로 후위표기법으로 표기해서 * / () 문을 먼저 계산하게 할거임

int limit(char a , char b) {
    // if() b가 a보다 우선순위가 높을때 return 1, 아니면 return 0 
    if ((a=='-'||a=='+')&&(b == '*' || b == '/'))
        return 1;
    else
        return 0;
   
}
int main() {
	string cstr ;                                            
	int temp; 
    int num = 0; 
    int i; // 배열 칸 지정하는 변수 
    int num2;
	printf("수식을 입력 : "); 
	getline(cin , cstr);
    int loop = cstr.length();
    stack<char>s;    
    stack<int>f;
    num2 = 0;
    
    for (i=0;i<loop;i++) {
        temp = (cstr[i] - '0');
        if ((temp>=0) && (temp<=9)) {
            num = num * 10 + temp;  // num= 0 인 증감하면서 상태에서 자리수에 10을 곱헤 값을 구함
            num2 = 1;
        }
        else {
            if (cstr[i] == ' ') {
                continue;

            }
            if (num2 == 1) {
                f.push(num);
                num = 0;   
            }
            if (!s.empty()) {
                temp = s.top();
                if (limit(temp, cstr[i])) {
                    s.push(cstr[i]);
                }
                else {
                     //(!s.empty()) {
                        temp = s.top();
                        int a, b;
                        a = f.top();
                        f.pop();
                        b = f.top();
                        f.pop();
                        s.pop();
                        switch (temp) {
                        case '+':
                            a += b;
                            break;
                        case '-':
                            a -= b;
                            break;
                        case '*':
                            a *= b;
                            break;
                        case '/':
                            a /= b;
                            break; 
                            
                        }
                            f.push(a);
                           
                   

                   // } 
                    s.push(cstr[i]);
                }


            }
            else {
                s.push(cstr[i]);
            }
               
            num2 = 0; //기호가 먼저 나올때 num2 = 0  ! num2= 1
        }
        
    }
    f.push(num); // 여기서부터 꼬이는듯
    
    while (!s.empty()) {
        temp = s.top();
        int a, b;
        a = f.top();
        f.pop();
        b = f.top();
        f.pop();
        s.pop();
        switch (temp) {
        case '+':
            a += b;
            break;
        case '-':
            a -= b;
            break;
        case '*':
            a *= b;
            break;
        case '/':
            a /= b;
            break;
           
        } 
        f.push(a);
       
    }

    printf("%d", f.top());
									
								

    return 0;
}