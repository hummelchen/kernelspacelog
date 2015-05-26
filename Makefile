ifneq ($(KERNELRELEASE),)
obj-m := keylogger.o
else
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	gcc parser.c -o parser
endif

clean:
	rm -rf parser *.o *~ *.ko *.mod.c Module.* *.order .keylogger* .tmp_versions
