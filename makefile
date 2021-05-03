project: main.o libprocessor.a
	g++ -std=c++11 main.o libprocessor.a -o processor

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

echo.o: echo.cpp echo.h processor.h
	g++ -std=c++11 -c echo.cpp 

noise_gate.o: noise_gate.cpp noise_gate.h processor.h
	g++ -std=c++11 -c noise_gate.cpp 

normalizer.o: normalizer.cpp normalizer.h processor.h
	g++ -std=c++11 -c normalizer.cpp 

libprocessor.a: echo.o noise_gate.o normalizer.o
	ar rcs libprocessor.a echo.o noise_gate.o normalizer.o 



header.o: header.h header.cpp wave_header.h
	g++ -std=c++11 -c header.cpp
	
8bitmono.o: 8_bit_mono.h 8_bit_mono.cpp header.h wave_header.h
	g++ -std=c++11 -c 8_bit_mono.cpp
	
test.o:
	g++ -std=c++11 -c test.cpp -o test.o
	
test: test.o header.o 8_bit_mono.o
	g++ -std=c++11 test.o header.o 8_bit_mono.o -o test



clean:
	rm *.o processor test
