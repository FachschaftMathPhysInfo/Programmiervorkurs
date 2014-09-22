
all: script

script: vorkurs.tex vorkurs.cls
	pdflatex -shell-escape vorkurs.tex
	pdflatex -shell-escape vorkurs.tex
	rm vorkurs.aux
	rm vorkurs.log
	rm vorkurs.out
	rm vorkurs.pyg
	rm vorkurs.toc
