#include <linux/module.h>
#include <linux/device.h>

#define VIRTUAL_BUS_NAME	"virtual"

static struct bus_type bus_type = {
	.name = VIRTUAL_BUS_NAME,
};

static int virtual_bus_init(void)
{
	int ret = bus_register(&bus_type);
	if (ret)
		return ret;
	return 0;
}

static void virtual_bus_exit(void)
{
	bus_unregister(&bus_type);
}

module_init(virtual_bus_init);
module_exit(virtual_bus_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Alejandro Mery <alejandro.mery@micrologic.net>");
MODULE_DESCRIPTION("Virtual Bus - devices comming out from thin air");
