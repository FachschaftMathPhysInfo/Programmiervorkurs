all: script clean
.PHONY: all clean dir nodir zip folien script

script: vorkurs.pdf

vorkurs.pdf: vorkurs.tex vorkurs.cls kapitel/* files/*
	pdflatex -shell-escape vorkurs.tex
	@echo "Running second time silently"
	pdflatex -shell-escape vorkurs.tex > /dev/null

helper.mk: vorkurs.pdf

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
# Diese Aufgabe übernimmt "make dir" in `helper.mk`.
# `helper.mk` wird automatisch beim kompilieren des Skriptes erstellt,
# damit die Dateien immer im richtigen Ordner landen.
dir: helper.mk
	make -f helper.mk dir
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


