
all: folien clear

folien: folien.tex
	@echo "Folien werden gebaut..."
	@pdflatex folien.tex > /dev/null
	@echo "...Zweiter duchlauf..."
	@pdflatex folien.tex > /dev/null
	@echo "...Folien fertig"

clear:
	@rm folien.log
	@rm folien.aux
	@rm folien.nav
	@rm folien.out
	@rm folien.snm
	@rm folien.toc
	@echo "Überflüssiger Scheiß gelöscht"
