#include  <linux/kernel.h>
#include  <linux/module.h>
#include  <linux/init.h>
#include  <linux/slab.h>
#include  <linux/vmalloc.h>

MODULE_LICENSE( "GPL" );
MODULE_AUTHOR( "faye" );

unsigned long *cpPagemem;
unsigned long *cpKmallocmem;
unsigned long *cpVmallocmem;

static int __init kmem_init( void ){
	
	printk( KERN_INFO "kmem module init!\n" );
	
	cpPagemem = ( unsigned long * )__get_free_page( 0 );
	//printk( KERN_INFO "pageMem addr: %lu\n", ( unsigned long )cpPagemem );
	printk( KERN_INFO "pageMem addr: %lX\n", ( unsigned long )cpPagemem );


	cpKmallocmem = ( unsigned long * )kmalloc( 10,0 );
	//printk( KERN_INFO "kmallocMem addr: %lu\n", ( unsigned long )cpKmallocmem );
	printk( KERN_INFO "kmallocMem addr: %lX\n", ( unsigned long )cpKmallocmem );

	cpVmallocmem = ( unsigned long * )vmalloc( 500*1024 );
	//printk( KERN_INFO "vmallocMem addr: %lu\n", ( unsigned long )cpVmallocmem );
	printk( KERN_INFO "vmallocMem addr: %lX\n", ( unsigned long )cpVmallocmem );

	return 0;
}

static void __exit kmem_exit( void ){	
	free_page( ( unsigned long )cpPagemem );
	kfree( cpKmallocmem );
	vfree( cpVmallocmem );
	printk( KERN_INFO "kmem module exit!\n" );
}

module_init( kmem_init );
module_exit( kmem_exit );
