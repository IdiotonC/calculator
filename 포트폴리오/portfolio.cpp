#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <stack> // �������� ����ǥ������� ǥ���ؼ� * / () ���� ���� ����ϰ� �Ұ���

int limit(char a , char b) {
    // if() b�� a���� �켱������ ������ return 1, �ƴϸ� return 0 
    if ((a=='-'||a=='+')&&(b == '*' || b == '/'))
        return 1;
    else
        return 0;
   
}
int main() {
	string cstr ;                                            
	int temp; 
    int num = 0; 
    int i; // �迭 ĭ �����ϴ� ���� 
    int num2;
	printf("������ �Է� : "); 
	getline(cin , cstr);
    int loop = cstr.length();
    stack<char>s;    
    stack<int>f;
    num2 = 0;
    
    for (i=0;i<loop;i++) {
        temp = (cstr[i] - '0');
        if ((temp>=0) && (temp<=9)) {
            num = num * 10 + temp;  // num= 0 �� �����ϸ鼭 ���¿��� �ڸ����� 10�� ���� ���� ����
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
               
            num2 = 0; //��ȣ�� ���� ���ö� num2 = 0  ! num2= 1
        }
        
    }
    f.push(num); // ���⼭���� ���̴µ�
    
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