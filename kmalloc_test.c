#include  <linux/kernel.h>
#include  <linux/module.h>
#include  <linux/init.h>
#include  <linux/slab.h>
#include  <linux/vmalloc.h>

MODULE_LICENSE( "GPL" );
MODULE_AUTHOR( "faye" );

unsigned char *cpPagemem;
unsigned char *cpKmallocmem;
unsigned char *cpVmallocmem;

static int __init kmem_init( void ){
	
	printk( KERN_INFO "kmem module init!\n" );
	
	cpPagemem = ( unsigned char * )__get_free_page( 0 );
	printk( KERN_INFO "pageMem addr: %lu\n", (unsigned long)cpPagemem );

	cpKmallocmem = 	( unsigned char * )kmalloc( 10,0 );
	printk( KERN_INFO "kmallocMem addr: %lu\n", (unsigned long)cpKmallocmem );

	cpVmallocmem = ( unsigned char * )vmalloc( 10 );
	printk( KERN_INFO "vmallocMem addr: %lu\n", (unsigned long)cpVmallocmem );

	return 0;
}

void __exit kmem_exit( void ){	
	free_page( (unsigned long)cpPagemem );
	kfree( cpKmallocmem );
	vfree( cpVmallocmem );
	printk( KERN_INFO "kmem module exit!\n" );
}

module_init( kmem_init );
module_exit( kmem_exit );
