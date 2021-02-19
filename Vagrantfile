Vagrant.configure("2") do |config|

    config.vm.define "focal", primary: true do |test|
        test.vm.box = "ubuntu/focal64"
    end

    config.vm.define "bionic", autostart: false do |test|
        test.vm.box = "ubuntu/bionic64"
    end

    config.vm.box_check_update = true
    # run ansible to install software
    config.vm.provision "software", type: 'ansible' do |ansible|
        ansible.playbook = "vagrant-software.yml"
    end

    config.vm.provider "virtualbox" do |vb|
        vb.memory = "1024"
        vb.cpus = 1
    end
    config.ssh.keys_only = true
end