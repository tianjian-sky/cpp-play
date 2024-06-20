set CUDA_HOME="D:\\CUDA"


echo "ПЊЪМБрвы"
start /d %CUDA_HOME%\bin nvcc.exe ./hello.cu -o helloWorld

echo "НсЪјБрвы"