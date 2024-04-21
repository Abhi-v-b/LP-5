Sem 8 codes (HPC & DL)

Installation commands of g++ and openmp-
sudo apt-get install g++
sudo apt-get install libomp.dev
Steps-
        Create file using command-
          Cat > filename.cpp
          Write code in terminal and press ctrl D to save the code
        To compile file use command-
          'g++ -o filename –fopenmp filename.cpp' or 'gcc file.c -lgomp -pthread -o out'
        Run file using command-
          ./filename

CUDA Check :
            nvcc --version
             sudo apt install nvidia-cuda-toolkit
