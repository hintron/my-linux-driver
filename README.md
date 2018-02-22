# My Linunx Kernel

I am going through a linux loadable kernel module (i.e. linux driver) tutorial.


### Requirements:

Linux OS (I'm doing this on a Debian 9.3 Digital Ocean droplet)

Packages to install (sudo apt-get install <package>):
git
build-essential
linux-headers-4.9.0-5-amd64
    (run `apt-cache search linux-headers-$(uname -r)` to figure out the exact package for your linux distro)


git clone https://github.com/hintron/my-linux-driver

cd my-linux-driver
make





See http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/
See http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/