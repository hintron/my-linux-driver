# My Linux Driver

I am going through a Linux loadable kernel module (i.e. Linux driver) tutorial.


### Requirements:

Linux OS (I'm doing this on a Debian 9.3 Digital Ocean droplet)

Packages to install (`sudo apt-get install <package>`):
`git`
`build-essential`
`linux-headers-4.9.0-5-amd64`
    (run `apt-cache search linux-headers-$(uname -r)` to figure out the exact package for your linux kernel)

### How to build

`git clone https://github.com/hintron/my-linux-driver`
`cd my-linux-driver`
`make`

### How to load the loadable kernel module once built

`sudo insmod my_linux_driver.ko`

### How to see which modules are currently loaded

`lsmod`

### How to see info on my_linux_driver

`modinfo my_linux_driver.ko`

### How to remove the module

`sudo rmmod my_linux_driver` or `sudo rmmod my_linux_driver.ko`

### How to load the loadable kernel module once built

`sudo insmod my_linux_driver.ko name=Thor`

### How to see printed messages from the driver

`tail /var/log/kern.log`

Or, if you want to see it update live in another terminal, do

`tail -f /var/log/kern.log`


See http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/

See http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/