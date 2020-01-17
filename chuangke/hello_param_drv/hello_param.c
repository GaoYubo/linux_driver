
/*
	1. 头文件
	2. 驱动模块装载和卸载函数入口和声明
	3. 实现模块装载和卸载函数入口
	4. GPL的声明
*/
#include <linux/init.h>
#include <linux/module.h>
#include "math.h"

static int myvalue = 56;
static char *myname = "george";

static int __init hello_drv_init(void)
{
	printk("hello drv init\r\n");
	printk("name = %s, value = %d\r\n",myname,myvalue);
	printk("a+b=%d, a-b=%d\r\n",my_add(3,2),my_sub(3,2));

	return 0;
}

static void __exit hello_drv_exit(void)
{
	printk("hello drv exit\r\n");
}

module_init(hello_drv_init);
module_exit(hello_drv_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("George <g_yubo@163.com>");

module_param(myvalue,int,0644);
module_param(myname,charp,S_IRUGO|S_IWUSR);
