#include <iostream>
using namespace std;

int atoin(char* s){
    int neg = 1;
    if(*s == '-'){
        neg = -1;
        s++;
    }
    int val = 0;
    while(*s != '\0'){
        int charVal = *s;
        if(!(charVal>='0' && charVal<='9')){
            break;
        }
        int digit = *s-'0';
        val = (val*10) + digit;
        s++;
    }
    return (neg*val);
}

int main(int argc, char* argv[]){
    cout << atoin(*(argv+1));
    return 0;
}