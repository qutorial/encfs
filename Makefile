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

install: build
	make install -C build
