Wave: main.cpp Console.o Echo.o Normalizer.o Reverse.o LowPass.o HighPass.o BassBooster.o Controller.o WavModel.o WavReader.o WavWriter.o 
	g++ -std=c++11 -o Wave main.cpp Console.o Echo.o Normalizer.o Reverse.o Controller.o WavModel.o WavReader.o WavWriter.o LowPass.o HighPass.o BassBooster.o
Console.o: Console.cpp
	g++ -std=c++11 -c Console.cpp
Echo.o: Echo.cpp
	g++ -std=c++11 -c Echo.cpp
Normalizer.o: Normalizer.cpp
	g++ -std=c++11 -c Normalizer.cpp
Reverse.o: Reverse.cpp
	g++ -std=c++11 -c Reverse.cpp
LowPass.o: LowPass.cpp
	g++ -std=c++11 -c LowPass.cpp
HighPass.o: HighPass.cpp
	g++ -std=c++11 -c HighPass.cpp
BassBooster.o: BassBooster.cpp
	g++ -std=c++11 -c BassBooster.cpp
Controller.o: Controller.cpp
	g++ -std=c++11 -c Controller.cpp
WavModel.o: WavModel.cpp
	g++ -std=c++11 -c WavModel.cpp
WavReader.o: WavReader.cpp
	g++ -std=c++11 -c WavReader.cpp
WavWriter.o: WavWriter.cpp
	g++ -std=c++11 -c WavWriter.cpp
clean:
	rm *.o Wave 8bitmonoecho.wav 8bitmononormal.wav 8bitstereoecho.wav 8bitstereonormal.wav 16bitmonoecho.wav 16bitmononormal.wav 16bitstereoecho.wav 16bitstereonormal.wav 8bitmonoreverse.wav 8bitstereoreverse.wav 16bitmonoreverse.wav 16bitstereoreverse.wav