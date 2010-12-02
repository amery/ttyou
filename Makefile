ifneq ($(KERNELRELEASE),)
obj-m := ttyou.o
else
PWD := $(shell pwd)
KERNELVER ?= $(shell uname -r)
KERNELDIR ?= /lib/modules/$(KERNELVER)/build

.PHONY: build clean

build:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	@rm -vf *.o *.ko core
	@rm -vf *~ .*.cmd *.mod.c modules.order Module.symver
	@rm -rvf .tmp_versions
endif
