all: script clean
.PHONY: all clean dir nodir zip folien script

script: vorkurs.pdf

vorkurs.pdf: title.tex vorkurs.tex vorkurs.cls kapitel/* files/*
	pdflatex -shell-escape vorkurs.tex
	@echo "Running second time silently"
	pdflatex -shell-escape vorkurs.tex > /dev/null

clean:
	rm -f vorkurs.aux
	rm -f vorkurs.log
	rm -f vorkurs.out
	rm -f vorkurs.pyg
	rm -f vorkurs.toc
	rm -f kapitel/basics/*.aux
	rm -f kapitel/basics/*.log
	rm -f kapitel/classes/*.aux
	rm -f kapitel/classes/*.log
	rm -rf _minted-vorkurs
	rm -f title.aux
	rm -f title.log

folien:
	make -C folien/ all

# Die Dateien in "files" werden ins Skript eingebunden und müssen den Erstis
# im Verzeichnis "vorkurs" zur Verfügung gestellt werden.
# Diese Aufgabe übernimmt "make dir".
dir: nodir files/*
	@echo "Verzeichnis erstellen…"
	@mkdir vorkurs > /dev/null
	@mkdir vorkurs/basics > /dev/null
	@for i in $(shell seq -w 1 19); do mkdir vorkurs/basics/lektion$$i; done;
	@mkdir vorkurs/classes > /dev/null
	@for i in $(shell seq -w 1 3); do mkdir vorkurs/classes/lektion0$$i; done;
	@echo "Dateien kopieren…"
	@cp files/basics/helloworld.cpp vorkurs/basics/lektion01/.  > /dev/null
	@cp files/basics/helloyou.cpp   vorkurs/basics/lektion03/.  > /dev/null
	@cp files/basics/fehler1.cpp    vorkurs/basics/lektion04/.  > /dev/null
	@cp files/basics/fehler2.cpp    vorkurs/basics/lektion04/.  > /dev/null
	@cp files/basics/fehler3.cpp    vorkurs/basics/lektion04/.  > /dev/null
	@cp files/basics/fehler4.cpp    vorkurs/basics/lektion04/.  > /dev/null
	@cp files/basics/fehler5.cpp    vorkurs/basics/lektion04/.  > /dev/null
	@cp files/basics/variablen.cpp  vorkurs/basics/lektion05/.  > /dev/null
	@cp files/basics/arith1.cpp     vorkurs/basics/lektion07/.  > /dev/null
	@cp files/basics/arith2.cpp     vorkurs/basics/lektion07/.  > /dev/null
	@cp files/basics/arith3.cpp     vorkurs/basics/lektion07/.  > /dev/null
	@cp files/basics/debugger.cpp   vorkurs/basics/lektion08/.  > /dev/null
	@cp files/basics/arith4.cpp     vorkurs/basics/lektion09/.  > /dev/null
	@cp files/basics/if.cpp         vorkurs/basics/lektion09/.  > /dev/null
	@cp files/basics/prim.cpp       vorkurs/basics/lektion11/.  > /dev/null
	@cp files/basics/whiletrue.cpp  vorkurs/basics/lektion11/.  > /dev/null
	@cp files/basics/fizzbuzz.cpp   vorkurs/basics/lektion12/.  > /dev/null
	@cp files/basics/funktion.cpp   vorkurs/basics/lektion13/.  > /dev/null
	@cp files/basics/namespaces.cpp vorkurs/basics/lektion14/.  > /dev/null
	@cp files/basics/vector.cpp     vorkurs/basics/lektion15/.  > /dev/null
	@cp files/basics/warnings.cpp   vorkurs/basics/lektion16/.  > /dev/null
	@cp files/basics/warnprim.cpp   vorkurs/basics/lektion16/.  > /dev/null
	@cp files/basics/tictactoe.cpp  vorkurs/basics/lektion17/.  > /dev/null
	@cp files/basics/assemble.cpp   vorkurs/basics/lektion18/.  > /dev/null
	@cp files/classes/runden.cpp    vorkurs/classes/lektion01/. > /dev/null
	@cp files/classes/runden2.cpp   vorkurs/classes/lektion01/. > /dev/null
	@cp files/classes/struct.cpp    vorkurs/classes/lektion02/. > /dev/null
	@cp files/classes/class.cpp     vorkurs/classes/lektion03/. > /dev/null
	@echo "TTT-Dateien kompilieren…"
	@g++ -c -o vorkurs/basics/lektion17/tictactoe.o files/basics/ttt_closed/tictactoe.cpp > /dev/null
	@g++ -c -o vorkurs/basics/lektion19/frage_feld_nummer.o files/basics/ttt_closed/frage_feld_nummer.cpp > /dev/null
	@g++ -c -o vorkurs/basics/lektion19/gewinnerin.o files/basics/ttt_closed/gewinnerin.cpp > /dev/null
	@g++ -c -o vorkurs/basics/lektion19/gebe_feld_aus.o files/basics/ttt_closed/gebe_feld_aus.cpp > /dev/null
	@echo "Vorkurs-Verzeichnis erstellt."
	@echo "Wenn du das Verzeichnis überall hin kopiert hast, nutze "make nodir", um sicherzustellen, dass das Skript nächstes Jahr wieder funktioniert"

nodir:
	@echo "Verzeichnis wird entfernt…"
	@rm -rf vorkurs > /dev/null
	@echo "Verzeichnis erfolgreich entfernt"

zip: dir
	# @echo "Lass vorher einmal "make dir" laufen, um das vorkurs-verzeichnis in der benötigten Form zu erstellen."
	@echo "Zip-File wird erstellt…"
	@zip -r vorkurs.zip vorkurs vorkurs.pdf
	@echo "Zip-File erstellt. Fertig zum hochladen."


