KERNELDIR := /home/george/linux/kernel/nxp_linux_kernel/linux-imx-rel_imx_4.1.15_2.1.0_ga
ROOTFS_DIR := /home/george/linux/nfs/rootfs/lib/modules/4.1.15\ /
CURRENT_PATH := $(shell pwd)

obj-m += hello_param.o
obj-m += math.o

build: kernel_modules

kernel_modules:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) clean

install:
	cp -raf *.ko $(ROOTFS_DIR)
