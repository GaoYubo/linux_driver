KERNELDIR := /home/george/linux/kernel/nxp_linux_kernel/linux-imx-rel_imx_4.1.15_2.1.0_ga
ROOTFS_DIR := /home/george/linux/nfs/rootfs/lib/modules/4.1.15\ /
CURRENT_PATH := $(shell pwd)

obj-m += chr_drv.o

APP_NAME = chr_test
CROSS_COMPILE = /usr/local/arm/gcc-linaro-7.4.1-2019.02-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-
CC = $(CROSS_COMPILE)gcc

build: kernel_modules

kernel_modules:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) modules
	$(CC) $(APP_NAME).c -o $(APP_NAME)

clean:
	$(MAKE) -C $(KERNELDIR) M=$(CURRENT_PATH) clean
	rm $(APP_NAME)

install:
	cp -raf *.ko $(APP_NAME) $(ROOTFS_DIR)
