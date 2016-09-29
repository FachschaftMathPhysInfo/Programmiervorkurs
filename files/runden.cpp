#include <iostream>

int runden(double d, int mode){
	 int i = d; //speichert Double in Integer, schneidet Kommastellen ab
    if(mode == 0){ //mathematisch runden
       if(d - i < 0.5){
		     return i;
		 }
		 else {
			 return i + 1;
		 }
	 }
	 else if (mode == 1){ //abrunden
		 return i;
	 }
	 else if (mode == 2){ //aufrunden
		 return i + 1;
	 }
	 else {
		 return 0; //Hier sollte ein Fehler geworfen werden. Das könnt ihr noch nicht
	 }
}

int main(){
	 //hier lässt sich nicht intuitiv erkennen, was das Programm tut
    std::cout << runden(2.7, 0) << std::endl;
	 std::cout << runden(2.3, 0) << std::endl;
	 std::cout << runden(2.7, 1) << std::endl;
	 std::cout << runden(2.7, 2) << std::endl;
}
