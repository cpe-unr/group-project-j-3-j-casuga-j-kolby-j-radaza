
project: main.cpp processorlib.a
	g++ -std=c++11 main.cpp -o processor -I/cs202/GroupProject/group-project-j-3-j-casuga-j-kolby-j-radaza #-lprocessorlib.a

echo.o: echo.cpp echo.h processor.h
	g++ -std=c++11 -c echo.cpp

noise_gate.o: noise_gate.cpp noise_gate.h processor.h
	g++ -std=c++11 -c noise_gate.cpp

normalizer.o: normalizer.cpp normalizer.h processor.h
	g++ -std=c++11 -c normalizer.cpp

processorlib.a: echo.o noise_gate.o normalizer.o
	ar rcs processorlib.a echo.o noise_gate.o normalizer.o 

libs: processorlib.a

clean:
	rm *.o *.a processor
