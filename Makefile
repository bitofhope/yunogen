srcdir  =   src
bindir  =   bin
objdir  =   obj
docdir  =   doc
CFLAGS  +=  -std=c99
LDFLAGS +=  -lncurses
PREFIX  ?=  /usr/local

all: yunogen
	
yunogen: yunogen.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(bindir)/yunogen $(objdir)/$<
	
yunogen.o: $(srcdir)/yunogen.c
	$(CC) $(CFLAGS) -c -o $(objdir)/yunogen.o $(srcdir)/yunogen.c
	
clean:
	rm -f $(bindir)/*
	rm -f $(objdir)/*.o

install:
	mkdir -p "$(PREFIX)/bin"
	cp -r $(bindir)/* "$(PREFIX)/bin/"
	cp -r $(docdir)/*.1* "$(PREFIX)/share/man/man1"

