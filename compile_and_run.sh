if [ -d "build" ]; then
	rm -rf build
fi

if [ ! -d "build" ]; then
  mkdir build
fi

cd build
cmake .. -GNinja
ninja

./lc
