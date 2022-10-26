# dps-laboratory2.
Para instalar el cmake y gtest me he ayudado de las siguientes paginas:
https://www.linuxfordevices.com/tutorials/install-cmake-on-linux
https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/

Para instalar se han utilizado los siguientes comandos:
Cmake: sudo apt install cmake g++ make
Gtest: 
sudo  apt-get install libgtest-dev
cd  /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
cp ./lib/libgtest*.a /usr/lib

Despues de realizar la instalacion de CMake y Gtest vuelvo a mi ejercicio:

cd /workspaces/Practicas/lab2-unit-tests-fferni01/

Y compilo y ejecuto los tests:

cmake CMakeList.txt

make

./runTests 

