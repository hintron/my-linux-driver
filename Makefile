# See http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/
# NOTE: The linux kernel build system expects Makefule to be capitalized!

# Swap between different driver source files
# DRIVER_NAME = my_linux_driver
DRIVER_NAME = my_linux_driver_2

obj-m+=$(DRIVER_NAME).o

all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	# make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules_install
clean:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
