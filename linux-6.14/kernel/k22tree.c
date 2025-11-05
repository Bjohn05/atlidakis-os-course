#include <linux/k22info.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/kernel.h>

static int do_k22tree(struct k22info  __user *user_buf, int  __user *user_ne){
    int ne;
    struct k22info *kbuf;

    if (!user_buf || !user_ne){
        return -EINVAL;
    }

    if(copy_from_user(&ne, user_ne, sizeof(int))){
        return -EFAULT;
    }
    if (ne <= 0){
        return -EINVAL;
    }

    kbuf = kcalloc((size_t)ne, sizeof(*kbuf), GFP_KERNEL);
    if (!kbuf){
        return -ENOMEM;
    }

    if(copy_to_user(user_buf, kbuf, (size_t)ne * sizeof(*kbuf))){
        kfree(kbuf);
        return -EFAULT;
    }

    kfree(kbuf);

    return ne;
}
SYSCALL_DEFINE2(k22tree, struct k22info __user *,user_buf,int __user *,user_ne){
    return do_k22tree(user_buf, user_ne);}