set CUDA_HOME="D:\\CUDA"


echo "��ʼ����"
start /d %CUDA_HOME%\bin nvcc.exe ./hello.cu -o helloWorld

echo "��������"