CC=clang++

istarutils:\
bin/encodei16\
bin/encodeu64\
bin/encodef32\
bin/encodef64\
bin/decodei16\
bin/decodeu64\
bin/decodef32\
bin/decodef64\
bin/inclusivescan\
bin/convertkdtopkd\
bin/footerizetxt\
bin/footerizesdf\
bin/footerizepdbqt\
bin/splitsdf\
bin/splitmol2\
bin/splitpdbqt\
bin/boxmol2\
bin/boxpdbqt\
bin/rmsdpdbqt\

bin/encodei16: obj/encodei16.o
	${CC} -o $@ $^

bin/encodeu64: obj/encodeu64.o
	${CC} -o $@ $^

bin/encodef32: obj/encodef32.o
	${CC} -o $@ $^

bin/encodef64: obj/encodef64.o
	${CC} -o $@ $^

bin/decodei16: obj/decodei16.o
	${CC} -o $@ $^

bin/decodeu64: obj/decodeu64.o
	${CC} -o $@ $^

bin/decodef32: obj/decodef32.o
	${CC} -o $@ $^

bin/decodef64: obj/decodef64.o
	${CC} -o $@ $^

bin/inclusivescan: obj/inclusivescan.o
	${CC} -o $@ $^

bin/convertkdtopkd: obj/convertkdtopkd.o
	${CC} -o $@ $^

bin/footerizetxt: obj/footerizetxt.o
	${CC} -o $@ $^

bin/footerizesdf: obj/footerizesdf.o
	${CC} -o $@ $^

bin/footerizepdbqt: obj/footerizepdbqt.o
	${CC} -o $@ $^

bin/splitsdf: obj/splitsdf.o
	${CC} -o $@ $^

bin/splitmol2: obj/splitmol2.o
	${CC} -o $@ $^

bin/splitpdbqt: obj/splitpdbqt.o
	${CC} -o $@ $^

bin/boxmol2: obj/boxmol2.o
	${CC} -o $@ $^

bin/boxpdbqt: obj/boxpdbqt.o
	${CC} -o $@ $^

bin/rmsdpdbqt: obj/rmsdpdbqt.o
	${CC} -o $@ $^

obj/%.o: src/%.cpp
	${CC} -o $@ $< -c -std=c++14 -O2

clean:
	rm -f bin/* obj/*
