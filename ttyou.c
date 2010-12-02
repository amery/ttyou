#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int ttyou_init(void)
{
	printk(KERN_ALERT "Hello world\n");
	return 0;
}

static void ttyou_exit(void)
{
	printk(KERN_ALERT "Goodbye cruel world\n");
}

module_init(ttyou_init);
module_exit(ttyou_exit);
