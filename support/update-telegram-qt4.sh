#!/usr/bin/env bash

function say {
	echo -e "\e[1m=== $1 ===\e[0m";
}

set -e;
shopt -s extglob;

say 'Changing to repository root';
cd $(git rev-parse --show-toplevel);
pwd;

say 'Initializing submodules';
git submodule init;

say 'Updating submodules';
git submodule update --recursive;

say 'Cleaning telegram-qt4';
rm -frv telegram-qt4/src/!(telegram-qt.pro);

say 'Populating telegram-qt4';
cp -rv support/telegram-qt/telegram-qt/!(telegram-qt.pro) telegram-qt4/src/;

say 'Removing unnecessary files';
rm -rv telegram-qt4/src/generator telegram-qt4/src/generator-ng;

say 'Done';
