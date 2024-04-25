rm -rf ./build
cmake -S . -B ./build
#不指定--config参数，则默认为Debug模式
# makefile系统 config模式不起作用
cmake --build ./build --config Release 
cmake --install ./build --config Release 