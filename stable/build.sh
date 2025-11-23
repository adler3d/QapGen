set -e
set -o errexit
set -o pipefail
g++ -O2 -std=c++17 QapGen/QapGen.cpp -o QapGen.elf
mv QapGen.elf Release
cd Release
./QapGen.elf input.qapdsl.hpp|head
cd ..
