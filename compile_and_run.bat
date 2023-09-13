@echo off

if not exist "build\" mkdir build
cd build
cmake ..
MSBuild lc.sln /p:Configuration=Release

cd Release

lc.exe