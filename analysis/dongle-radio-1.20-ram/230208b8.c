/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230208b8. Types and names are inferred; NOT original source. */

undefined4 FUN_230208b8(int param_1,uint param_2,undefined4 param_3,char param_4,undefined1 param_5)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  byte bVar5;
  
  iVar1 = (param_2 & 0xff) + param_1 * 0xf84;
  bVar5 = *(char *)((int)&DAT_230033e8 + iVar1 + 0x154) + 1;
  if (*(byte *)((int)&DAT_230033e8 + iVar1 + 0x160) <= bVar5) {
    bVar5 = 0;
  }
  if (*(byte *)((int)&DAT_230033e8 + iVar1 + 0x15a) == bVar5) {
    return 0;
  }
  iVar1 = param_2 + param_1 * 0xf84;
  iVar4 = (int)(short)(ushort)*(byte *)((int)&DAT_230033e8 + iVar1 + 0x154) *
          (int)(short)(ushort)*(byte *)((int)&DAT_230033e8 + iVar1 + 0x166);
  iVar2 = *(int *)(&DAT_23003554 + (param_1 * 0x3e1 + param_2) * 4);
  *(char *)(iVar4 + iVar2) = param_4;
  iVar2 = iVar2 + iVar4;
  *(undefined1 *)(iVar2 + 1) = param_5;
  *(undefined1 *)(iVar2 + 2) = 0;
  *(char *)(iVar2 + 4) = param_4 + '\x02';
  *(byte *)(iVar2 + 6) =
       *(byte *)((int)&DAT_230033e8 + iVar1 + 0xa7) | (byte)((param_2 & 0xff) << 3);
  thunk_FUN_0e06f35c(iVar2 + 7,param_3);
  disableIRQinterrupts();
  cVar3 = *(char *)((int)&DAT_230033e8 + iVar1 + 0x154) + '\x01';
  if (*(char *)((int)&DAT_230033e8 + iVar1 + 0x160) == cVar3) {
    cVar3 = '\0';
  }
  *(char *)((int)&DAT_230033e8 + iVar1 + 0x154) = cVar3;
  enableIRQinterrupts();
  cVar3 = *(char *)((int)&DAT_230033e8 + iVar1 + 0xa7) + '\x01';
  if (cVar3 == '\b') {
    cVar3 = '\x01';
  }
  *(char *)((int)&DAT_230033e8 + iVar1 + 0xa7) = cVar3;
  return 1;
}


