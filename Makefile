
all: script clean

title: title.tex
	pdflatex title.tex

script: title vorkurs.tex vorkurs.cls
	pdflatex -shell-escape vorkurs.tex
	pdflatex -shell-escape vorkurs.tex

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

# Die Dateien in "files" werden ins Skript eingebunden und müssen den Erstis
# im Verzeichnis "vorkurs" zur Verfügung gestellt werden.
# Diese Aufgabe übernimmt "make dir".
dir: files/*
	@echo "Verzeichnis erstellen…"
	@mkdir vorkurs > /dev/null
	@for i in $(shell seq -w 1 19); do mkdir vorkurs/lektion$$i; done;
	@echo "Dateien kopieren…"
	@cp files/basics/helloworld.cpp vorkurs/lektion01/. > /dev/null
	@cp files/basics/helloyou.cpp   vorkurs/lektion03/. > /dev/null
	@cp files/basics/fehler1.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/basics/fehler2.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/basics/fehler3.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/basics/fehler4.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/basics/fehler5.cpp    vorkurs/lektion04/. > /dev/null
	@cp files/basics/variablen.cpp  vorkurs/lektion05/. > /dev/null
	@cp files/basics/arith1.cpp     vorkurs/lektion07/. > /dev/null
	@cp files/basics/arith2.cpp     vorkurs/lektion07/. > /dev/null
	@cp files/basics/arith3.cpp     vorkurs/lektion07/. > /dev/null
	@cp files/basics/debugger.cpp   vorkurs/lektion08/. > /dev/null
	@cp files/basics/arith4.cpp     vorkurs/lektion09/. > /dev/null
	@cp files/basics/if.cpp         vorkurs/lektion09/. > /dev/null
	@cp files/basics/prim.cpp       vorkurs/lektion11/. > /dev/null
	@cp files/basics/whiletrue.cpp  vorkurs/lektion11/. > /dev/null
	@cp files/basics/fizzbuzz.cpp   vorkurs/lektion12/. > /dev/null
	@cp files/basics/funktion.cpp   vorkurs/lektion13/. > /dev/null
	@cp files/basics/namespaces.cpp vorkurs/lektion14/. > /dev/null
	@cp files/basics/vector.cpp     vorkurs/lektion15/. > /dev/null
	@cp files/basics/warnings.cpp   vorkurs/lektion16/. > /dev/null
	@cp files/basics/warnprim.cpp   vorkurs/lektion16/. > /dev/null
	@cp files/basics/tictactoe.cpp  vorkurs/lektion17/. > /dev/null
	@cp files/basics/assemble.cpp   vorkurs/lektion18/. > /dev/null
	@echo "TTT-Dateien kompilieren…"
	@g++ -c -o vorkurs/lektion17/tictactoe.o files/basics/ttt_closed/tictactoe.cpp > /dev/null
	@g++ -c -o vorkurs/lektion19/frage_feld_nummer.o files/basics/ttt_closed/frage_feld_nummer.cpp > /dev/null
	@g++ -c -o vorkurs/lektion19/gewinnerin.o files/basics/ttt_closed/gewinnerin.cpp > /dev/null
	@g++ -c -o vorkurs/lektion19/gebe_feld_aus.o files/basics/ttt_closed/gebe_feld_aus.cpp > /dev/null
	@echo "Vorkurs-Verzeichnis erstellt."
	@echo "Wenn du das Verzeichnis überall hin kopiert hast, nutze "make nodir", um sicherzustellen, dass das Skript nächstes Jahr wieder funktioniert"

nodir: vorkurs
	@echo "Verzeichnis wird entfernt…"
	@rm -rf vorkurs > /dev/null
	@echo "Verzeichnis erfolgreich entfernt"

zip: dir
	# @echo "Lass vorher einmal "make dir" laufen, um das vorkurs-verzeichnis in der benötigten Form zu erstellen."
	@echo "Zip-File wird erstellt…"
	@zip -r vorkurs.zip vorkurs vorkurs.pdf
	@echo "Zip-File erstellt. Fertig zum hochladen."


