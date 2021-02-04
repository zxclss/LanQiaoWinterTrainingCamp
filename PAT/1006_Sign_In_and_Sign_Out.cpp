#include <iostream>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    string sname, ename;
    int stime = 1e9, etime = 0;
    char name [20];
    int hh, mm, ss, sum;
    
    for (int i = 1; i <= n; ++i) {
        //计算早到的人
        scanf("%s %d:%d:%d", name, &hh, &mm, &ss);
        sum = ss + mm * 60 + hh * 3600;
        if (sum < stime) sname = name, stime = sum;
        
        //计算晚走的人
        scanf("%d:%d:%d", &hh, &mm, &ss);
        sum = ss + mm * 60 + hh * 3600;
        if (sum > etime) ename = name, etime = sum;
    }
    printf("%s %s\n", sname.c_str(), ename.c_str());
    return 0;
}
