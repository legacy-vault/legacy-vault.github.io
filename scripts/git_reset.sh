#!/bin/bash
# git_reset.sh
# version 1.2

# Resetting the Repository
git clone https://github.com/legacy-vault/legacy-vault.github.io
git checkout --orphan latest_branch
git add -A
git commit -am "Repository Reset"
git branch -D master
git branch -m master
git push -f origin master
