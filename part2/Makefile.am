bin_PROGRAMS = cythonwalkthrough3
cythonwalkthrough3_CFLAGS = $(PYTHON_INCLUDE)
cythonwalkthrough3_SOURCES = src/main.c src/portal.c src/portal.h src/portal.pyx
cythonwalkthrough3_LDFLAGS = $(PYTHON_LDFLAGS)

src/main.c: src/portal.h

src/portal.h: src/portal.c

src/portal.c:
	cython3 src/portal.pyx

clean-local:
	rm -rf src/portal.c src/portal.h
