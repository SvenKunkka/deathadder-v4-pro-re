/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c358. Types and names are inferred; NOT original source. */

byte FUN_0e06c358(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined *puVar9;
  byte bVar10;
  undefined4 *puVar11;
  int local_2c [2];
  
  if (param_3 < 5) {
    bVar10 = 0xff;
  }
  else {
    bVar10 = *param_2;
    bVar1 = param_2[1];
    bVar2 = param_2[4];
    if ((char)*param_2 < '\0') {
      if (bVar2 < DAT_230071ef) {
        puVar11 = (undefined4 *)(&DAT_0e07267c + (short)(ushort)bVar2 * 0x28);
      }
      else {
        puVar11 = (undefined4 *)0x0;
      }
      if (param_1 == 0) {
        iVar6 = FUN_0e068710();
        iVar5 = iVar6 * 0x24;
        *(undefined4 *)(&DAT_2300704c + iVar5) = 0;
        *(undefined2 *)(&DAT_23007049 + iVar6 * 0x24) = 0x1ff;
        FUN_0e06d83c(&DAT_23007048 + iVar5);
        uVar8 = *puVar11;
        (&DAT_23007049)[iVar5] = bVar10 & 0x7f;
        FUN_0e06c020(bVar1,param_2 + 5,param_3 - 5,uVar8,puVar11);
        FUN_0e06d83c(0);
        FUN_0e068754((&DAT_23007048)[iVar6 * 0x24]);
      }
      else {
        *(byte *)(param_1 + 1) = bVar10 & 0x7f;
        FUN_0e06c020(bVar1,param_2 + 5,param_3 - 5,*puVar11,puVar11);
      }
      return 0x80;
    }
    if (bVar10 != 1) {
      if (bVar2 < DAT_230071ef) {
        puVar9 = &DAT_0e07267c + (short)(ushort)bVar2 * 0x28;
      }
      else {
        puVar9 = (undefined *)0x0;
      }
      if (bVar10 == 0) {
        FUN_0e06c020(bVar1,param_2 + 5,param_3 - 5,*(undefined4 *)(puVar9 + 4),puVar9);
        uVar4 = **(undefined1 **)(puVar9 + 8);
        uVar3 = (*(undefined1 **)(puVar9 + 8))[1];
        FUN_0e06bd78(puVar9,local_2c,0);
        iVar5 = -0xc;
        if (local_2c[0] != 0) {
          *(undefined1 *)(local_2c[0] + -2) = uVar4;
          *(byte *)(local_2c[0] + -4) = bVar1;
          *(undefined1 *)(local_2c[0] + -1) = uVar3;
          *(undefined1 *)(local_2c[0] + -3) = 0xff;
          *(undefined1 *)(local_2c[0] + -5) = 2;
          iVar5 = -0x13;
          if (*(char *)(*(int *)(puVar9 + 8) + 0x14) != '\0') {
            pcVar7 = *(code **)(**(int **)(puVar9 + 0xc) + 4);
            if (pcVar7 == (code *)0x0) {
              iVar5 = -5;
            }
            else {
              iVar5 = (*pcVar7)(*(int **)(puVar9 + 0xc),local_2c[0] + -5,5);
              if (-1 < iVar5) {
                return 0;
              }
            }
          }
        }
        FUN_0e06bf74(iVar5,1,puVar9,bVar1,0);
      }
    }
  }
  return bVar10;
}


