# Makefile para generar el pdf
SHELL := /bin/bash

# En este makefile estan las dos opciones para compilar latex:
# el comando `make` hace:
# latex -> div -> ps -> pdf 
# el comando `make pd` hace:
# pdflatex -> pdf
LATEX=latex
PDFLATEX=pdflatex
DVI=dvips
PS=ps2pdf
#PDFLATEX=xelatex
PDFLATEX_OPTS=-interaction=nonstopmode -halt-on-error -shell-escape

TEX_FILE=informe_final.tex
DVI_FILE=informe_final.dvi
PS_FILE=informe_final.ps

.PHONY: all pdf clean

all : pdf

pdf: $(TEX_FILE)
	$(LATEX) $(PDFLATEX_OPTS) $(TEX_FILE)
	$(DVI) $(DVI_FILE)
	$(PS) $(PS_FILE)

pd: $(TEX_FILE)
	$(PDFLATEX) $(PDFLATEX_OPTS) $(TEX_FILE)
clean:
	rm -fv *.{aux,log,nav,out,snm,toc,vrb}
