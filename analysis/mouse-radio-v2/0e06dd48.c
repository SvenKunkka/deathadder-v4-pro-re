/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06dd48. Types and names are inferred; NOT original source. */

undefined4
FUN_0e06dd48(int param_1,uint param_2,undefined1 *param_3,char param_4,undefined1 param_5)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  
  iVar1 = DAT_0e06de18;
  if (param_2 == 1) {
    param_4 = param_4 + -1;
    param_3 = param_3 + 1;
    *(undefined1 *)(DAT_0e06de18 + 0xa1) = *param_3;
  }
  iVar3 = param_1 * 0xee0 + iVar1;
  iVar4 = iVar3 + (param_2 & 0xff);
  bVar5 = *(char *)(iVar4 + 0x15e) + 1;
  if (*(byte *)(iVar4 + 0x16a) <= bVar5) {
    bVar5 = 0;
  }
  if (*(byte *)(iVar4 + 0x164) != bVar5) {
    iVar3 = iVar3 + param_2;
    iVar4 = *(int *)(iVar1 + (param_1 * 0x3b8 + param_2 + 0x5e) * 4);
    iVar1 = (int)(short)(ushort)*(byte *)(iVar3 + 0x15e) *
            (int)(short)(ushort)*(byte *)(iVar3 + 0x170);
    *(char *)(iVar1 + iVar4) = param_4;
    iVar1 = iVar1 + iVar4;
    *(char *)(iVar1 + 4) = param_4 + '\x02';
    *(undefined1 *)(iVar1 + 2) = 0;
    *(undefined1 *)(iVar1 + 1) = param_5;
    *(byte *)(iVar1 + 6) = *(byte *)(iVar3 + 0xb2) | (byte)((param_2 & 0xff) << 3);
    thunk_FUN_0e0974c4(iVar1 + 7,param_3);
    disableIRQinterrupts();
    cVar2 = *(char *)(iVar3 + 0x15e) + '\x01';
    if (*(char *)(iVar3 + 0x16a) == cVar2) {
      cVar2 = '\0';
    }
    *(char *)(iVar3 + 0x15e) = cVar2;
    enableIRQinterrupts();
    cVar2 = *(char *)(iVar3 + 0xb2) + '\x01';
    if (cVar2 == '\b') {
      cVar2 = '\x01';
    }
    *(char *)(iVar3 + 0xb2) = cVar2;
    return 1;
  }
  return 0;
}


