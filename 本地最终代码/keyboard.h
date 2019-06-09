#ifndef KEYBOARD_H_INCLUDED
#define KEYBOARD_H_INCLUDED

int fd;
char szSendCMD[128];

int nState;
char cKey;

void keyboard_init();
int keyboard_single();
char *keyboard_long();
char *keyboard_code();



#endif // KEYBOARD_H_INCLUDED
