g++ -O2 -std=c++17 SimpleCalc/SimpleCalc.cpp -o SimpleCalc.elf
mv SimpleCalc.elf Release
cd Release
./SimpleCalc.elf
cd ..