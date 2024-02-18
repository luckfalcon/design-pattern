if [ -d "./build/" ]
then
rm -rf build
echo "Delete build successfully!"
else
echo "Not found build!"
fi
cmake -B build
cmake --build build/