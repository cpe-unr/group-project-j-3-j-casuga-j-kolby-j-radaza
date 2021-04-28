project: main.o libprocessor.so
	g++ -std=c++11 main.o -L. -lprocessor -o processor

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

libprocessor.so: echo.o noise_gate.o normalizer.o
	g++ -std=c++11 echo.o noise_gate.o normalizer.o -shared -o libprocessor.so

echo.o: echo.cpp echo.h processor.h
	g++ -std=c++11 -c echo.cpp -fpic

noise_gate.o: noise_gate.cpp noise_gate.h processor.h
	g++ -std=c++11 -c noise_gate.cpp -fpic

normalizer.o: normalizer.cpp normalizer.h processor.h
	g++ -std=c++11 -c normalizer.cpp -fpic

clean:
	rm *.o *.so processor
