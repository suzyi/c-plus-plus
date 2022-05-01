if EXIST build rm -rf build
mkdir build && cd build
cmake .. -A x64
cmake --build . --config Release
cd ..
rm -rf data\img_lmdb
build\Release\convert_imageset.exe data\ data\img_list.txt data\img_lmdb --resize_width=32 --resize_height=32
