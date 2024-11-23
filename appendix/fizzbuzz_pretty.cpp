#include <string>
#include <iostream>
int main() {
    std::string output = ""; //Wir kreieren eine Variable für den Output
    for(int i = 1; i <= 100; i++){ //Für alle Zahlen von 1 bis 100:
        output = "";
        if(i % 3 == 0){
            output += "Fizz"; //Falls die Zahl durch 3 Teilbar ist, fügen wir dem Output "Fizz" hinzu
        }
        if(i % 5 == 0){
            output += "Buzz"; //Falls die Zahl durch 5 Teilbar ist, fügen wir dem Output "Buzz" hinzu
        }
        if(output == ""){
            output = std::to_string(i); //Falls der Output danach immer noch leer ist, wird die Zahl zum Output
        }
        std::cout << output << std::endl; //Wir geben den Output aus
    }
}

/*Sprich: Dieses Programm spielt das englische Kinderspiel "FizzBuzz"; Man sagt nacheinander jede Zahl, aber
- wenn die Zahl durch 3 teilbar ist (3, 6,...), sagt man "Fizz"
- wenn die Zahl durch 5 teilbar ist (5, 10,...), sagt man "Buzz"
- Wenn die Zahl durch beides teilbar ist (15, 30,...), sagt man "FizzBuzz".*/