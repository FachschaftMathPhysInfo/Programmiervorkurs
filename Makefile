
all: script clean

script: vorkurs.tex vorkurs.cls
	pdflatex -shell-escape vorkurs.tex
	pdflatex -shell-escape vorkurs.tex

clean:
	rm -f vorkurs.aux
	rm -f vorkurs.log
	rm -f vorkurs.out
	rm -f vorkurs.pyg
	rm -f vorkurs.toc
	rm -f basics/*.aux
	rm -f basics/*.log
	rm -rf _minted-vorkurs
	rm -f vorkurs.cls

# Die Dateien in "files" werden ins Skript eingebunden und müssen den Erstis
# im Verzeichnis "vorkurs" zur Verfügung gestellt werden.
# Diese Aufgabe übernimmt "make dir".
dir: files/*
	@echo "Verzeichnis erstellen…"
	@mkdir vorkurs > /dev/null
	@mkdir vorkurs/lektion01 > /dev/null
	@mkdir vorkurs/lektion02 > /dev/null
	@mkdir vorkurs/lektion03 > /dev/null
	@mkdir vorkurs/lektion04 > /dev/null
	@mkdir vorkurs/lektion05 > /dev/null
	@mkdir vorkurs/lektion06 > /dev/null
	@mkdir vorkurs/lektion07 > /dev/null
	@mkdir vorkurs/lektion08 > /dev/null
	@mkdir vorkurs/lektion09 > /dev/null
	@mkdir vorkurs/lektion10 > /dev/null
	@mkdir vorkurs/lektion11 > /dev/null
	@mkdir vorkurs/lektion12 > /dev/null
	@mkdir vorkurs/lektion13 > /dev/null
	@mkdir vorkurs/lektion14 > /dev/null
	@mkdir vorkurs/lektion15 > /dev/null
	@mkdir vorkurs/lektion16 > /dev/null
	@mkdir vorkurs/lektion17 > /dev/null
	@mkdir vorkurs/lektion18 > /dev/null
	@mkdir vorkurs/lektion19 > /dev/null
	@echo "Dateien kopieren…"
	@cp files/helloworld.cpp vorkurs/lektion01/. > /dev/null
	@cp files/basics.sh      vorkurs/lektion02/. > /dev/null
	@cp files/helloyou.cpp   vorkurs/lektion03/. > /dev/null
	@cp files/fehler1.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/fehler2.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/fehler3.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/fehler4.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/fehler5.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/strings.cpp    vorkurs/lektion05/. > /dev/null
	@cp files/arith1.cpp     vorkurs/lektion07/. > /dev/null
	@cp files/arith2.cpp     vorkurs/lektion07/. > /dev/null
	@cp files/arith3.cpp     vorkurs/lektion07/. > /dev/null
	@cp files/debugger.cpp   vorkurs/lektion08/. > /dev/null
	@cp files/arith4.cpp     vorkurs/lektion09/. > /dev/null
	@cp files/if.cpp         vorkurs/lektion09/. > /dev/null
	@cp files/prim.cpp       vorkurs/lektion11/. > /dev/null
	@cp files/whiletrue.cpp  vorkurs/lektion11/. > /dev/null
	@cp files/fizzbuzz.cpp   vorkurs/lektion12/. > /dev/null
	@cp files/funktion.cpp   vorkurs/lektion13/. > /dev/null
	@cp files/namespaces.cpp vorkurs/lektion14/. > /dev/null
	@cp files/array.cpp      vorkurs/lektion15/. > /dev/null
	@cp files/warnings.cpp   vorkurs/lektion16/. > /dev/null
	@cp files/warnprim.cpp   vorkurs/lektion16/. > /dev/null
	@cp files/collatz.cpp    vorkurs/lektion16/. > /dev/null
	@cp files/tictactoe.cpp  vorkurs/lektion17/. > /dev/null
	@cp files/assemble.cpp   vorkurs/lektion18/. > /dev/null
	@echo "TTT-Dateien kompilieren…"
	@g++ -c -o vorkurs/lektion17/tictactoe.o files/ttt_closed/tictactoe.cpp > /dev/null
	@g++ -c -o vorkurs/lektion19/frage_feld_nummer.o files/ttt_closed/frage_feld_nummer.cpp > /dev/null
	@g++ -c -o vorkurs/lektion19/gewinnerin.o files/ttt_closed/gewinnerin.cpp > /dev/null
	@g++ -c -o vorkurs/lektion19/gebe_feld_aus.o files/ttt_closed/gebe_feld_aus.cpp > /dev/null
	@echo "Vorkurs-Verzeichnis erstellt."
	@echo "Wenn du das Verzeichnis überall hin kopiert hast, nutze "make nodir", um sicherzustellen, dass das Skript nächstes Jahr wieder funktioniert"

nodir: vorkurs
	@echo "Verzeichnis wird entfernt…"
	@rm -rf vorkurs > /dev/null
	@echo "Verzeichnis erfolgreich entfernt"



