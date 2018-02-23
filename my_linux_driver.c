/**
 * @file    my_linux_driver.c
 * @author  Michael Hinton
 * @date    22 February 2018
 * @version 0.1
 * @brief  An introductory loadable kernel module (LKM) for educational purposes.
 * See the /var/log/kern.log file when the module is loaded and removed. The module
 * can accept an argument when it is loaded -- the name, which appears in the kernel
 * log files.
 * @see http://derekmolloy.ie/writing-a-linux-kernel-module-part-1-introduction/
*/

// Macros used to mark up functions e.g., __init __exit
#include <linux/init.h>
// Core header for loading LKMs into the kernel
#include <linux/module.h>
// Contains types, macros, functions for the kernel
#include <linux/kernel.h>


// The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");
// The author -- visible when you use modinfo
MODULE_AUTHOR("Michael Hinton");
// The description -- see modinfo
MODULE_DESCRIPTION("A simple Linux driver for educational purposes");
// The version of the module
MODULE_VERSION("0.1");


// An example LKM argument -- default value is "world"
static char *name = "world";
// Param desc. charp = char ptr, S_IRUGO can be read/not changed
module_param(name, charp, S_IRUGO);
// parameter description
MODULE_PARM_DESC(name, "The name to display in /var/log/kern.log");

/** @brief The LKM initialization function
 *  The static keyword restricts the visibility of the function to within this C file. The __init
 *  macro means that for a built-in driver (not a LKM) the function is only used at initialization
 *  time and that it can be discarded and its memory freed up after that point.
 *  @return returns 0 if successful
 */
static int __init my_linux_driver_init(void){
    printk(KERN_INFO "MGH: Hello %s from my_linux_driver!\n", name);
    return 0;
}

/** @brief The LKM cleanup function
 *  Similar to the initialization function, it is static. The __exit macro notifies that if this
 *  code is used for a built-in driver (not a LKM) that this function is not required.
 */
static void __exit my_linux_driver_exit(void){
    printk(KERN_INFO "MGH: Goodbye %s from my_linux_driver!\n", name);
}

/** @brief A module must use the module_init() module_exit() macros from linux/init.h, which
 *  identify the initialization function at insertion time and the cleanup function (as
 *  listed above)
 */
module_init(my_linux_driver_init);
module_exit(my_linux_driver_exit);