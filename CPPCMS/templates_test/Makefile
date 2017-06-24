LIBS=-lcppcms -lbooster

all: clean foobar

foobar: foobar.cc view.cc content.h
	$(CXX) -Wall foobar.cc view.cc -o foobar ${LIBS}

view.cc: view.tmpl content.h
	cppcms_tmpl_cc view.tmpl -o view.cc

clean:
	rm -fr foobar *.exe *.so view.cc cppcms_rundir
