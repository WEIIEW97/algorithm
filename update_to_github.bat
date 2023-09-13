@echo off

REM Change to your project directory (Optional)
cd "D:\william\codes\algorithm"

REM Stage changes
git add .

REM Check git status
git status

REM Commit changes
git commit -m %1

REM Push changes
git push
