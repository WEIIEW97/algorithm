#!/bin/zsh
script_dir=$(dirname "$(readlink -f "$BASH_SOURCE")")
echo "The script is located in $script_dir"
cd $script_dir

git add .
git status

if [ -z "$1" ]; then
  echo "Please provide a commit message."
  exit 1
fi

git commit -m $1
git push
echo "pushing to remote repository done!" 