# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files zum Testen
OBJDIR = objs

# enthaelt das ausfuehrbare File zum Testen
BINDIRTEST = debug


AUTOMATDIR = ../Automat

BUFFERDIR = ../Buffer

SYMBOLTABLEDIR = ../Symboltable

SCANNERDIR = ../Scanner


## hier alle Object Files eintragen, ausser das File mit der Mainmethode
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Parser.o \
       $(OBJDIR)/Node.o \
       $(OBJDIR)/ParseTree.o \
	   $(OBJDIR)/ParseTreeVisitorType.o \
	   $(OBJDIR)/ParseTreeVisitorCode.o
	   
	#$(OBJDIR)/xx1.o \
	#$(OBJDIR)/xxn.o


## Variante mit wenig Makefile-Kenntnissen
# 
## linken der Object-files 
#makeTestScanner: $(OBJDIR)/Scanner.o $(OBJDIR)/TestScanner.o
#	g++ -g $(OBJDIR)/Scanner.o $(OBJDIR)/TestScanner.o   $(PROJECTOBJDIR)/Automat/*.o $(PROJECTOBJDIR)/Buffer/*.o $(PROJECTOBJDIR)/Symboltable/*.o -o $(BINDIRTEST)/ScannerTest
##	
##	
##	
### compilieren der source-files
#$(OBJDIR)/Scanner.o :  $(SRCDIR)/Scanner.cpp $(HEADERDIR)/Scanner.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/Scanner.o  $(SRCDIR)/Scanner.cpp
#	cp $(OBJDIR)/Scanner.o $(PROJECTOBJDIR)/Scanner
##
#$(OBJDIR)/TestScanner.o :  $(SRCDIR)/TestScanner.cpp 
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/TestScanner.o  $(SRCDIR)/TestScanner.cpp
#
	
	
# Variante mit guten Makefile-Kenntnissen
makeTestParser: $(OBJS) TestParser


$(OBJDIR)/%.o :  $(SRCDIR)/%.cpp $(HEADERDIR)/%.h
	@echo "g++ $*.cpp"
	g++ -g  -c -Wall  -o $@  $<

# 
# $@ name des object files
# $< erste abhaengigkeit


TestParser: $(SRCDIR)/TestParser.cpp $(HEADERDIR)/Parser.h
	g++ -g  -c -Wall src/TestParser.cpp -o $(BINDIRTEST)/TestParser.o  
	g++ -g $(BINDIRTEST)/TestParser.o $(OBJDIR)/*.o $(AUTOMATDIR)/$(OBJDIR)/*.o $(BUFFERDIR)/$(OBJDIR)/*.o $(SYMBOLTABLEDIR)/$(OBJDIR)/*.o $(SCANNERDIR)/$(OBJDIR)/*.o -o $(BINDIRTEST)/TestParser

# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu erstellen

cleanParser:
	del /Q $(OBJDIR)\*.o
	del /Q $(BINDIRTEST)\*
	$(MAKE) makeTestParser
	


