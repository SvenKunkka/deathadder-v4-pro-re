/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07202c. Types and names are inferred; NOT original source. */

void FUN_0e07202c(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar3 = DAT_0e0720d8;
  cVar1 = *(char *)(DAT_0e0720d8 + 0x11e);
  if ('\0' < *(char *)(DAT_0e0720d8 + 0x11e)) {
    uVar2 = *(undefined1 *)(DAT_0e0720d8 + 0x120);
    iVar6 = FUN_0e06de44(uVar2);
    uVar7 = FUN_0e06de3c(uVar2);
    iVar5 = DAT_0e0720e0;
    iVar4 = DAT_0e0720dc;
    if (iVar6 == 0) {
      if (*(char *)(iVar3 + 0x121) == '(') {
        *(undefined4 *)(DAT_0e0720e0 + 0x36) = *(undefined4 *)(iVar3 + 0x122);
      }
      else if (*(char *)(iVar3 + 0x121) == ')') {
        *(ushort *)(DAT_0e0720dc + 0x1de) =
             *(ushort *)(iVar3 + 0x123) << 8 | *(ushort *)(iVar3 + 0x123) >> 8;
        uVar2 = *(undefined1 *)(iVar3 + 0x122);
        *(undefined1 *)(iVar4 + 0x31) = 1;
        *(undefined1 *)(iVar5 + 0x3a) = uVar2;
      }
      iVar4 = DAT_0e0726dc;
      if (*(char *)(iVar3 + 0x68) != '\0') {
        uVar8 = (uint)(ushort)(*(short *)(DAT_0e0726dc + 0x1e) + 1);
        uVar7 = uVar8;
        if (30000 < uVar8) {
          uVar7 = 0;
        }
        *(ushort *)(DAT_0e0726dc + 0x1c) =
             (ushort)*(byte *)(iVar3 + 0x6d) + *(short *)(DAT_0e0726dc + 0x1c);
        if (uVar8 < 0x7531) {
          *(short *)(iVar4 + 0x1e) = (short)uVar7;
        }
        else {
          *(uint *)(iVar4 + 0x1c) = uVar7;
        }
        return;
      }
    }
    else if (*(byte *)(iVar3 + iVar6 + 0xc2) != uVar7) {
      *(char *)(iVar3 + iVar6 + 0xc2) = (char)uVar7;
      FUN_0e0725a0(0,iVar6,iVar3 + 0x121,(short)(char)(cVar1 + -2),*(undefined1 *)(iVar3 + 0x6d));
      *(undefined4 *)(iVar3 + 0x98) = 0;
      *(undefined1 *)(iVar3 + 0x58) = 2;
      return;
    }
  }
  return;
}


