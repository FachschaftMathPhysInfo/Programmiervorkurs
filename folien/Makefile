all: folien clean

folien: folien.tex
	@echo "Folien werden gebaut..."
	@pdflatex folien.tex
	@echo "...Zweiter duchlauf..."
	@pdflatex folien.tex
	@echo "...Folien fertig"

clean:
	@rm folien.log
	@rm folien.aux
	@rm folien.nav
	@rm folien.snm
	@rm folien.toc
	@echo "Überflüssiger Scheiß gelöscht"
