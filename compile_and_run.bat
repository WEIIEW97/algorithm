@echo off

if exist "build\" rmdir /s /q build

if not exist "build\" mkdir build
cd build
cmake ..
MSBuild lc.sln /p:Configuration=Release

cd Release

lc.exe
