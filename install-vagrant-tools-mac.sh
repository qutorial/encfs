#!/bin/sh

echo "Updating homebrew..."
brew update
export HOMEBREW_NO_AUTO_UPDATE=1
echo "Installing Vagrant and tools..."
brew install -q virtualbox ansible vagrant