#ifndef PARSER_H
#define PARSER_H

#include <linux/keyboard.h>
#include <linux/input.h>
#include <stdio.h>

#define FIRST_CD    KEY_1
#define LAST_CD     KEY_SLASH
const char ch_table[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\r',
                         '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
                         'X', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', 'X',
                         'X', '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'
                        };
struct keycode {
    int code;
    const char * string;
};
typedef struct keycode keycode;
keycode codes[] =
{
    {KEY_ENTER, "\n"},
    {KEY_SPACE, " "},
    {KEY_ESC, "<Esc>"},
    {KEY_BACKSPACE, "<Backspace>"},
    {KEY_TAB, "<Tab>"},
    {KEY_LEFTCTRL, "<LCtrl>"},
    {KEY_LEFTSHIFT, "<LShift>"},
    {KEY_RIGHTSHIFT, "<RShift>"},
    {KEY_LEFTALT, "<LAlt>"},
    {KEY_CAPSLOCK, "<CapsLock>"},
    {KEY_F1, "F1"},
    {KEY_F2, "F2"},
    {KEY_F3, "F3"},
    {KEY_F4, "F4"},
    {KEY_F5, "F5"},
    {KEY_F6, "F6"},
    {KEY_F7, "F7"},
    {KEY_F8, "F8"},
    {KEY_F9, "F9"},
    {KEY_F10, "F10"},
    {KEY_F11, "F11"},
    {KEY_F12, "F12"},
    {KEY_NUMLOCK, "<NumLock>"},
    {KEY_SCROLLLOCK, "<ScroollLock>"},
    {KEY_RIGHTCTRL, "<RCtrl>"},
    {KEY_RIGHTALT, "<RAlt>"},
    {KEY_HOME, "<Home>"},
    {KEY_UP, "<ArrowUp>"},
    {KEY_PAGEUP, "<PageUp>"},
    {KEY_LEFT, "<ArrowLeft>"},
    {KEY_RIGHT, "<ArrowRight>"},
    {KEY_END, "<End>"},
    {KEY_DOWN, "<ArrowDown>"},
    {KEY_PAGEDOWN, "<PageDown>"},
    {KEY_INSERT, "<Insert>"},
    {KEY_DELETE, "<Del>"}
};
#endif
