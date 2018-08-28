AM_LDFLAGS=-lpython3.6m

bin_PROGRAMS = cythonwalkthrough3
cythonwalkthrough3_CFLAGS = $(PYTHON_INCLUDE)
cythonwalkthrough3_SOURCES = src/main.c src/portal.c src/portal.h src/portal.pyx

src/main.c: src/portal.c

src/portal.c: src/portal.h

src/portal.h:
	cython3 src/portal.pyx

clean-local:
	rm -rf src/portal.c src/portal.h
