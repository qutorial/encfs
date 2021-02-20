update:
	vagrant box update

up: update
	vagrant up --provision

provision:
	vagrant provision

down: 
	vagrant halt

ssh:
	vagrant ssh

.PHONY: build-ubuntu
build-ubuntu:
	vagrant ssh -c 'bash -c "cd /vagrant; ./build.sh"'

.PHONY: build
build:
	./build.sh

.PHONY: install
install: build
	make install -C build

.PHONY: install-dev-tools-mac
install-dev-tools-mac:
	./install-vagrant-tools-mac.sh
