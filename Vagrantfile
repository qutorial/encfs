Vagrant.configure("2") do |config|
    config.vm.box = "ubuntu/focal64"
    config.vm.box_check_update = true
    # run ansible to install software
    config.vm.provision "software", type: 'ansible' do |ansible|
        ansible.playbook = "vagrant-software.yml"
    end

    config.vm.provider "virtualbox" do |vb|
        vb.memory = "2048"
        vb.cpus = 2
    end
    config.ssh.keys_only = true
end