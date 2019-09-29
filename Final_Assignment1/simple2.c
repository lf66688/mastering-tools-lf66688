#include <linux/init.h>
#include <linux/list.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <liunx/slab.h>

struct birthday{
		int day;
		int month;
		int year;
		struct list_head list;
	};
static LIST_HEAD(birthday_list);
int simple_init(void)
{	
	
	int day1=25,month1=7,year=1998;
	struct birthday *person;
	//插入元素到链表 
	for(int i=0;i<5;i++){
	person = kmalloc(sizeof(*person),GFP_KERNEL);
	person->day=day1++;
	person->month=month1++;
	person->year=year1++;
	INIT_LIST_HEAD(&person->list);
	list_add_tail(&person->list,&birthday_list);
	}
	
	
	struct birthday *ptr;
		//遍历链表 
	list_for_each_entry(ptr,&birthday_list,list){
	
		printk(KERN_INFO "%d.%d.%d\n",ptr->year,ptr->month,ptr->day);
	
	}
	printk(KERN_INFO "Loading Module\n");
	
	return 0;
 } 
 
 
 void simple_exit(void)
 {
 	
 	//移除元素 
 	struct birthday *ptr,*next;
    list_for_each_entry_safe(ptr,next,&birthday_list,list)
    {
    	
        list_del(&ptr->list);
        kfree(ptr);
    }

 	printk(KERN_INFO "Removing\n");		 
	
 }
 
 module_init(simple_init);
 module_exit(simple_exit);
 MODULE_LICENSE("GPL");
 MODULE_DESCRIPTION("Simple Module");
 MODULE_AUTHOR("SGG");
