@echo off
set BATCH_FILE_LOCATION=%~dp0
REM Change to your project directory (Optional)
cd %BATCH_FILE_LOCATION%

git add .
git status

git commit -m %1
git push
