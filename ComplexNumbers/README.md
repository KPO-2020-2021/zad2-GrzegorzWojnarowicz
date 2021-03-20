# gtest
Stworzyć folder lib<br>
W lib sklonować: <br> git clone https://github.com/google/googletest.git <br>
potem w głównym folderze <br>
mkdir build && cd build <br>
cmake .. (tworzą się dwa makefile w folderze /build to jest program i w folderze /build/tst jest program testujący)
w celu uruchomienia programu należy użyć komendy <br> ./complex_run easy lub ./complex_run hard <br>
w celu uruchomienia testów należy użyć komendy <br> ./complex_tst <br>