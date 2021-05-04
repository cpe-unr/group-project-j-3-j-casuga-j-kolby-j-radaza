project: main.o libprocessor.a Menu.h header.o 8_bit_mono.o
	g++ -std=c++11 main.o libprocessor.a header.o 8_bit_mono.o -o processor

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

8bitstereo.o: 8_bit_stereo.h 8_bit_stereo.cpp header.h wave_header.h 
	g++ -std=c++11 -c 8_bit_stereo.cpp
	
16bitmono.o: 16_bit_mono.h 16_bit_mono.cpp header.h wave_header.h 
	g++ -std=c++11 -c 16_bit_mono.cpp
	
16bitstereo.o: 16_bit_stereo.h 16_bit_stereo.cpp header.h wave_header.h
	g++ -std=c++11 -c 16_bit_stereo.cpp

csv.o: csv.cpp csv.h header.h
	g++ -std=c++11 -c csv.cpp
	
test: test.o header.o 8_bit_mono.o 8_bit_stereo.o 16_bit_mono.o 16_bit_stereo.o
	g++ -std=c++11 test.cpp header.o 8_bit_mono.o 8_bit_stereo.o 16_bit_mono.o 16_bit_stereo.o -o test



clean:
	rm *.o processor test
