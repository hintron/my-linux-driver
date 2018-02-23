# See http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/
# NOTE: The linux kernel build system expects Makefule to be capitalized!

obj-m+=my_linux_driver.o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	# make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules_install
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean