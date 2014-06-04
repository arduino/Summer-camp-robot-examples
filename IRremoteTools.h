#ifndef IRREMOTETOOLS_H
#define IRREMOTETOOLS_H

#define REMOTE_UP 0xE4B308F7
#define REMOTE_DOWN 0xE4B3D827
#define REMOTE_LEFT 0xE4B350AF
#define REMOTE_RIGHT 0xE4B3F807
#define REMOTE_MIDDLE 0xE4B310EF
#define REMOTE_MINUS 0xE4B3F00F
#define REMOTE_PLUS 0xE4B3B847
#define REMOTE_CONTINUE -1

extern void beginIRremote(int recvpin);

extern bool IRreceived();

extern void resumeIRremote();

extern unsigned long getIRresult();

#endif