#include <iostream>
using namespace std;
int strtoi(string str,int i)
{
    if(i == 0)
    return 0;
    return  (str[i]-48) + 10*strtoi(str,i-1) ;
}
int main() {
	string str = "0238143";
	int i = strtoi(str,str.length()-1);
	cout<<i<<endl;
	return 0;
}
