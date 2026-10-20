/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08dc0c. Types and names are inferred; NOT original source. */

void FUN_0e08dc0c(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  uVar5 = (uint)*(byte *)(iVar3 + 0x364);
  if (uVar5 != 0) {
    uVar1 = 0;
    uVar2 = 0;
    do {
      if (((3 << (uVar2 << 1 & 0xff) & *(uint *)(iVar3 + 0x2ac)) >> (uVar2 << 1 & 0xff) & 0xfffffffd
          ) == 0) {
        iVar6 = (uVar1 & 0x7f) + 0x58;
        if ((uVar1 & 0x80) != 0) {
          iVar6 = (uVar1 & 0x7f) + 0x48;
        }
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar6 * 0x20) = 0x8000000;
        uVar5 = (uint)*(byte *)(iVar3 + 0x364);
      }
      uVar1 = uVar1 + 1;
      uVar2 = uVar1 & 0xff;
    } while (uVar2 < uVar5);
  }
  *(undefined4 *)(iVar4 + 0x814) = 9;
  *(uint *)(iVar4 + 0x810) = *(uint *)(iVar4 + 0x810) | 1;
  *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) | 0x10;
  *(uint *)(iVar4 + 0x800) = *(uint *)(iVar4 + 0x800) & 0xfffff80f;
  *(byte *)(iVar3 + 0x362) = *(byte *)(iVar3 + 0x362) & 0xdf;
  return;
}


