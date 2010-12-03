#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h>
#include <linux/kdev_t.h>

#define TTYOU_MASTER_NAME	"ttyou"
#define TTYOU_SLAVE_MAX		7

static dev_t master;

static int ttyou_init(void)
{
	int ret = alloc_chrdev_region(&master, 0, TTYOU_SLAVE_MAX+1,
			       TTYOU_MASTER_NAME);
	if (ret < 0) {
		printk(KERN_ALERT "ttyou: failed to register (%d)\n", ret);
		return ret;
	}

	printk(KERN_ALERT "ttyou: registered with major %d\n", MAJOR(master));
	return 0;
}

static void ttyou_exit(void)
{
	unregister_chrdev_region(master, TTYOU_SLAVE_MAX+1);
	printk(KERN_ALERT "ttyou: bye\n");
}

module_init(ttyou_init);
module_exit(ttyou_exit);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Alejandro Mery <alejandro.mery@micrologic.net>");
MODULE_DESCRIPTION("TTY on Userspace");
