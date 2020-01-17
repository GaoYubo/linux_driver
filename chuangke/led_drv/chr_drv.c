
/*
	1. 头文件
	2. 驱动模块装载和卸载函数入口和声明
	3. 实现模块装载和卸载函数入口
	4. GPL的声明
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>

#define chr_dev_major  200
#define chr_dev_name   "chr_dev"


static struct class *chr_dev_class;
static struct device *chr_dev_dev;

static int kernel_val = 553;

ssize_t chr_drv_read (struct file *filp, char __user *buf, size_t count, loff_t *fpos)
{
	printk("-------%s-------\r\n", __FUNCTION__);
	int ret;
	ret = copy_to_user(buf, &kernel_val, count);
	if(ret > 0)
	{
		printk("copy to user error\r\n");
		return -EFAULT;
	}
	return 0;
}

ssize_t chr_drv_write (struct file *filp, const char __user *buf, size_t count, loff_t *fpos)
{
	printk("-------%s-------\r\n", __FUNCTION__);
	int ret;
	int value;
	ret = copy_from_user(&value,buf, count);

	if(ret > 0)
	{
		printk("copy from user error\r\n");
		return -EFAULT;
	}

	printk("____KERNEL____: value = %d\r\n", value);

	return 0;
}

int chr_drv_open (struct inode *inode, struct file *filp)
{
	printk("-------%s-------\r\n", __FUNCTION__);
	return 0;
}

int chr_drv_release (struct inode *inode, struct file *filp)
{
	printk("-------%s-------\r\n", __FUNCTION__);
	return 0;
}

const struct file_operations chr_drv_fop = {
	.open = chr_drv_open,
	.write = chr_drv_write,
	.read = chr_drv_read,
	.release = chr_drv_release,
};

static int __init chr_drv_init(void)
{
	/* 一般都是向系统申请资源 */
	int ret;
	printk("char drive init\r\n");

	/* 申请设备号 */
	ret = register_chrdev(chr_dev_major,"chr_dev",&chr_drv_fop);
	if (ret == 0)
	{
		printk("register ok\r\n");
	}
	else
	{
		printk("register failed\r\n");
		return -EINVAL;
	}

	chr_dev_class = class_create(THIS_MODULE,chr_dev_name);
	chr_dev_dev = device_create(chr_dev_class,NULL,MKDEV(chr_dev_major,0),NULL,chr_dev_name);
	
	return 0;
}

static void __exit chr_drv_exit(void)
{
	/* 一般都是释放系统资源 */
	device_destroy(chr_dev_class,MKDEV(chr_dev_major,0));
	class_destroy(chr_dev_class);

	unregister_chrdev(chr_dev_major,"chr_dev");

	printk("char drive exit\r\n");
}

module_init(chr_drv_init);
module_exit(chr_drv_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("george <g_yubo@163.com>");
