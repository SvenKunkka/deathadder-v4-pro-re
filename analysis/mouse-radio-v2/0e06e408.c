/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06e408. Types and names are inferred; NOT original source. */

void FUN_0e06e408(int param_1,int param_2)

{
  char cVar1;
  undefined2 uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  undefined1 local_20;
  undefined1 local_1f;
  ushort local_1e;
  
  pcVar3 = DAT_0e06e4b8;
  if (param_2 - 1U < 0x40) {
    uVar2 = (undefined2)param_2;
    local_1f = (undefined1)param_2;
    if (*DAT_0e06e4b0 < 3) {
      *(undefined2 *)(param_1 * 0xee0 + DAT_0e06e4b4 + 0x34) = uVar2;
      pcVar3 = DAT_0e06e4b8;
      if (param_2 == 1) {
        if (*DAT_0e06e4b8 == '\0') {
          *(undefined4 *)(DAT_0e06e4bc + 0x40) = 1;
          *pcVar3 = '\x01';
        }
      }
      else if (*DAT_0e06e4b8 != '\0') {
        *(undefined4 *)(DAT_0e06e4bc + 0x44) = 1;
        *pcVar3 = '\0';
      }
    }
    else {
      iVar5 = param_1 * 0xee0 + DAT_0e06e4b4;
      if (*(short *)(iVar5 + 0x34) == 0) {
        cVar1 = *DAT_0e06e4b8;
        *(undefined2 *)(iVar5 + 0x34) = uVar2;
        if (param_2 == 1) {
          if (cVar1 == '\0') {
            *(undefined4 *)(DAT_0e06e4bc + 0x40) = 1;
            *pcVar3 = '\x01';
          }
        }
        else if (cVar1 != '\0') {
          *(undefined4 *)(DAT_0e06e4bc + 0x44) = 1;
          *pcVar3 = '\0';
        }
      }
      else {
        uVar4 = *(ushort *)(DAT_0e06e4b4 + 0x92) + 100;
        local_1e = (ushort)((uVar4 & 0xff) << 8) | (ushort)(uVar4 >> 8) & 0xff;
        local_20 = 0x2f;
        FUN_0e06dd48(param_1,0,&local_20,4,0xff);
        *(undefined2 *)(iVar5 + 0x36) = uVar2;
        *(short *)(iVar5 + 0x38) = (short)uVar4;
      }
    }
    return;
  }
  return;
}


