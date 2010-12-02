ifneq ($(KERNELRELEASE),)
obj-m := ttyou.o
else
PWD := $(shell pwd)
KERNELVER ?= $(shell uname -r)
KERNELDIR ?= /lib/modules/$(KERNELVER)/build

.PHONY: default

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

endif
