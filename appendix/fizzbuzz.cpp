#include <string>
#include <iostream>
int main() {std::string a="";
for(int i=1;i<=100;i++){a="";if(i%3==0){a+="Fizz";}
if(i%5==0){a+="Buzz";}if(a==""){a=std::to_string(i);}
std::cout<<a<<std::endl;}}