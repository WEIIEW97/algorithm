@echo off
set BATCH_FILE_LOCATION=%~dp0
REM Change to your project directory (Optional)
cd %BATCH_FILE_LOCATION%

REM Stage changes
git add .

REM Check git status
git status

REM Commit changes
git commit -m %1

REM Push changes
git push
