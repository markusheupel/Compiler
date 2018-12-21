#
#	baut das komplette Scanner Projekt
#
OBJDIR = objs

AUTOMATDIR = Automat

BUFFERDIR = Buffer

SYMBOLTABLEDIR = Symboltable

SCANNERDIR = Scanner

PARSERDIR = Parser


all:	automatOBJs bufferOBJs symboltableOBJs scanner  
	@echo "target all"

	
# rm 	remove
# -f	force, ohne nachfragen
clean:
	del /Q $(AUTOMATDIR)\$(OBJDIR)\*.o
	del /Q $(BUFFERDIR)\$(OBJDIR)\*.o
	del /Q $(SYMBOLTABLEDIR)\$(OBJDIR)\*.o
	del /Q $(PARSERDIR)\$(OBJDIR)\*.o
	del /Q $(SCANNERDIR)\$(OBJDIR)\*.o
	del /Q $(SCANNERDIR)\debug\*
	

automatOBJs:
	$(MAKE) -C $(AUTOMATDIR) AutomatOBJTarget
	
	
bufferOBJs:
	$(MAKE) -C $(BUFFERDIR) BufferOBJTarget

	
symboltableOBJs:
	$(MAKE) -C $(SYMBOLTABLEDIR) SymboltableOBJTarget
	

scanner: 
	$(MAKE) -C $(SCANNERDIR) makeStartScanner

parser: 
	$(MAKE) -C $(PARSERDIR) makeTestParser
	