all: folien clear

folien: folien_abschied.tex
	@echo "Folien werden gebaut..."
	@pdflatex folien_abschied.tex > /dev/null
	@echo "...Zweiter duchlauf..."
	@pdflatex folien_abschied.tex > /dev/null
	@echo "...Folien fertig"

clear:
	@rm folien_abschied.log
	@rm folien_abschied.aux
	@rm folien_abschied.nav
	@rm folien_abschied.snm
	@rm folien_abschied.toc
	@echo "Überflüssiger Scheiß gelöscht"
