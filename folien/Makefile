all: folien clean
.PHONY: all folien clean

folien: folien.pdf folien_abschied.pdf

folien.pdf: folien.tex header.tex accounts.tex passwort.tex media/*
	@echo "Intro Folien werden gebaut..."
	@pdflatex folien.tex > /dev/null
	@echo "...Zweiter duchlauf..."
	@pdflatex folien.tex > /dev/null
	@echo "...Folien fertig"

folien_abschied.pdf: folien_abschied.tex header.tex media/*
	@echo "Outro Folien werden gebaut..."
	@pdflatex folien_abschied.tex > /dev/null
	@echo "...Zweiter duchlauf..."
	@pdflatex folien_abschied.tex > /dev/null
	@echo "...Folien fertig"

clean:
	@rm *.log
	@rm *.aux
	@rm *.nav
	@rm *.snm
	@rm *.toc
	@echo "Überflüssiger Scheiß gelöscht"
