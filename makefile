
project: main.cpp processorLib.a
	g++ -std=c++11 main.cpp processorLib.a -o processor

echo.o: echo.cpp echo.h processor.h
	g++ -std=c++11 -c echo.cpp

noise_gate.o: noise_gate.cpp noise_gate.h processor.h
	g++ -std=c++11 -c noise_gate.cpp

normalizer.o: normalizer.cpp normalizer.h processor.h
	g++ -std=c++11 -c normalizer.cpp

processorLib.a: echo.o noise_gate.o normalizer.o
	ar rcs processorLib.a echo.o noise_gate.o normalizer.o 

clean:
	rm *.o *.a processor
