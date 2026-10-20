/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06dd48. Types and names are inferred; NOT original source. */

undefined4
FUN_0e06dd48(int param_1,uint param_2,undefined1 *param_3,char param_4,undefined1 param_5)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  byte bVar5;
  
  if (param_2 == 1) {
    param_4 = param_4 + -1;
    param_3 = param_3 + 1;
    DAT_23002a19 = *param_3;
  }
  iVar1 = (param_2 & 0xff) + param_1 * 0xee0;
  bVar5 = *(char *)((int)&DAT_23002978 + iVar1 + 0x15e) + 1;
  if (*(byte *)((int)&DAT_23002978 + iVar1 + 0x16a) <= bVar5) {
    bVar5 = 0;
  }
  if (*(byte *)((int)&DAT_23002978 + iVar1 + 0x164) != bVar5) {
    iVar1 = param_2 + param_1 * 0xee0;
    iVar4 = (&DAT_23002978)[param_1 * 0x3b8 + param_2 + 0x5e];
    iVar2 = (int)(short)(ushort)*(byte *)((int)&DAT_23002978 + iVar1 + 0x15e) *
            (int)(short)(ushort)*(byte *)((int)&DAT_23002978 + iVar1 + 0x170);
    *(char *)(iVar2 + iVar4) = param_4;
    iVar2 = iVar2 + iVar4;
    *(char *)(iVar2 + 4) = param_4 + '\x02';
    *(undefined1 *)(iVar2 + 2) = 0;
    *(undefined1 *)(iVar2 + 1) = param_5;
    *(byte *)(iVar2 + 6) =
         *(byte *)((int)&DAT_23002978 + iVar1 + 0xb2) | (byte)((param_2 & 0xff) << 3);
    thunk_FUN_0e09739c(iVar2 + 7,param_3);
    disableIRQinterrupts();
    cVar3 = *(char *)((int)&DAT_23002978 + iVar1 + 0x15e) + '\x01';
    if (*(char *)((int)&DAT_23002978 + iVar1 + 0x16a) == cVar3) {
      cVar3 = '\0';
    }
    *(char *)((int)&DAT_23002978 + iVar1 + 0x15e) = cVar3;
    enableIRQinterrupts();
    cVar3 = *(char *)((int)&DAT_23002978 + iVar1 + 0xb2) + '\x01';
    if (cVar3 == '\b') {
      cVar3 = '\x01';
    }
    *(char *)((int)&DAT_23002978 + iVar1 + 0xb2) = cVar3;
    return 1;
  }
  return 0;
}


