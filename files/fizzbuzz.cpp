#include <iostream>

int main() {
int i=1;
while (i<100){
if (i%3==0){
if (i%5==0){
std::cout<<"FizzBuzz"<<std::endl;
}else{
std::cout<<"Fizz"<<std::endl;
}}else if(i%5==0){
if(i%3==0){
std::cout<<"FizzBuzz"<<std::endl;
}else{
std::cout<<"Buzz"<<std::endl;
}}else{
std::cout<<i<<std::endl;
}
i=i+1;
}return 0;}
