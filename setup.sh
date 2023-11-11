g++ -shared -fPIC -o ./bin/libMain.so ./src/Main.cpp
g++ -o ./bin/test_ex ./examples/test_ex/Main.cpp -ldl
