/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c100320. Types and names are inferred; NOT original source. */

byte FUN_1c100320(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  int iVar9;
  byte bVar10;
  undefined4 *puVar11;
  int iVar12;
  int local_2c [2];
  
  if (param_3 < 5) {
    bVar10 = 0xff;
  }
  else {
    bVar10 = *param_2;
    bVar1 = param_2[1];
    bVar2 = param_2[4];
    if ((char)*param_2 < '\0') {
      if (bVar2 < *DAT_1c100468) {
        puVar11 = (undefined4 *)((short)(ushort)bVar2 * 0x28 + 4 + DAT_1c10046c);
      }
      else {
        puVar11 = (undefined4 *)0x0;
      }
      if (param_1 == 0) {
        iVar5 = FUN_1c0fcc48();
        iVar9 = DAT_1c100470;
        iVar6 = DAT_1c100470 + 1;
        iVar12 = DAT_1c100470 + iVar5 * 0x24;
        *(undefined4 *)(iVar12 + 4) = 0;
        *(undefined2 *)(iVar6 + iVar5 * 0x24) = 0x1ff;
        FUN_1c101814(iVar12);
        uVar8 = *puVar11;
        *(byte *)(iVar12 + 1) = bVar10 & 0x7f;
        FUN_1c0fffe8(bVar1,param_2 + 5,param_3 - 5,uVar8,puVar11);
        FUN_1c101814(0);
        FUN_1c0fcc8c(*(undefined1 *)(iVar9 + iVar5 * 0x24));
      }
      else {
        *(byte *)(param_1 + 1) = bVar10 & 0x7f;
        FUN_1c0fffe8(bVar1,param_2 + 5,param_3 - 5,*puVar11,puVar11);
      }
      return 0x80;
    }
    if (bVar10 != 1) {
      if (bVar2 < *DAT_1c100468) {
        iVar9 = (short)(ushort)bVar2 * 0x28 + 4 + DAT_1c10046c;
      }
      else {
        iVar9 = 0;
      }
      if (bVar10 == 0) {
        FUN_1c0fffe8(bVar1,param_2 + 5,param_3 - 5,*(undefined4 *)(iVar9 + 4),iVar9);
        uVar4 = **(undefined1 **)(iVar9 + 8);
        uVar3 = (*(undefined1 **)(iVar9 + 8))[1];
        FUN_1c0ffd44(iVar9,local_2c,0);
        iVar5 = -0xc;
        if (local_2c[0] != 0) {
          *(undefined1 *)(local_2c[0] + -2) = uVar4;
          *(byte *)(local_2c[0] + -4) = bVar1;
          *(undefined1 *)(local_2c[0] + -1) = uVar3;
          *(undefined1 *)(local_2c[0] + -3) = 0xff;
          *(undefined1 *)(local_2c[0] + -5) = 2;
          iVar5 = -0x13;
          if (*(char *)(*(int *)(iVar9 + 8) + 0x14) != '\0') {
            pcVar7 = *(code **)(**(int **)(iVar9 + 0xc) + 4);
            if (pcVar7 == (code *)0x0) {
              iVar5 = -5;
            }
            else {
              iVar5 = (*pcVar7)(*(int **)(iVar9 + 0xc),local_2c[0] + -5,5);
              if (-1 < iVar5) {
                return 0;
              }
            }
          }
        }
        FUN_1c0fff3c(iVar5,1,iVar9,bVar1,0);
      }
    }
  }
  return bVar10;
}


