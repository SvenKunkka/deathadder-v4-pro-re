/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e06fdd0. Types and names are inferred; NOT original source. */

void FUN_0e06fdd0(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = DAT_0e06fe44;
  cVar1 = *(char *)(DAT_0e06fe44 + 0x11e);
  if ('\0' < *(char *)(DAT_0e06fe44 + 0x11e)) {
    uVar2 = *(undefined1 *)(DAT_0e06fe44 + 0x120);
    iVar5 = FUN_0e06de44(uVar2);
    uVar6 = FUN_0e06de3c(uVar2);
    iVar4 = DAT_0e0726dc;
    if (iVar5 == 0) {
      if (*(char *)(iVar3 + 0x68) != '\0') {
        uVar7 = (uint)(ushort)(*(short *)(DAT_0e0726dc + 0x1e) + 1);
        uVar6 = uVar7;
        if (30000 < uVar7) {
          uVar6 = 0;
        }
        *(ushort *)(DAT_0e0726dc + 0x1c) =
             (ushort)*(byte *)(iVar3 + 0x6d) + *(short *)(DAT_0e0726dc + 0x1c);
        if (uVar7 < 0x7531) {
          *(short *)(iVar4 + 0x1e) = (short)uVar6;
        }
        else {
          *(uint *)(iVar4 + 0x1c) = uVar6;
        }
        return;
      }
    }
    else if (*(byte *)(iVar3 + iVar5 + 0xc2) != uVar6) {
      *(char *)(iVar3 + iVar5 + 0xc2) = (char)uVar6;
      FUN_0e0725a0(0,iVar5,iVar3 + 0x121,(short)(char)(cVar1 + -2),0);
      *(undefined4 *)(iVar3 + 0x98) = 0;
      *(undefined1 *)(iVar3 + 0x58) = 2;
      return;
    }
  }
  return;
}


