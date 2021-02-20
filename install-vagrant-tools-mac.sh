#!/bin/sh

echo "Updating homebrew..."
brew update
export HOMEBREW_NO_AUTO_UPDATE=1
echo "Installing Vagrant and tools..."
brew install -fq virtualbox ansible vagrant cmake git git-vendor
brew upgrade -fq virtualbox ansible vagrant cmake git git-vendor