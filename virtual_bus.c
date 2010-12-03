#include <linux/module.h>
#include <linux/device.h>

#define VIRTUAL_BUS_NAME	"virtual"

static void virtual_bus_release(struct device *dev);

static struct bus_type virtual_bus_type = {
	.name = VIRTUAL_BUS_NAME,
};

static struct device virtual_bus = {
	.bus = &virtual_bus_type,
	.init_name = VIRTUAL_BUS_NAME,
	.release = virtual_bus_release,
};

static void virtual_bus_release(struct device *dev)
{
	printk(KERN_NOTICE "virtual bus device released\n");
}

static int virtual_bus_init(void)
{
	int ret;
	if ((ret = bus_register(&virtual_bus_type)))
		return ret;
	if ((ret = device_register(&virtual_bus))) {
		printk(KERN_NOTICE "failed to register virtual bus device\n");
		return ret;
	}
	return 0;
}

static void virtual_bus_exit(void)
{
	device_unregister(&virtual_bus);
	bus_unregister(&virtual_bus_type);
}

module_init(virtual_bus_init);
module_exit(virtual_bus_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alejandro Mery <alejandro.mery@micrologic.net>");
MODULE_DESCRIPTION("Virtual Bus - devices comming out from thin air");
