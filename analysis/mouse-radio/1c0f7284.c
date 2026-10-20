/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f7284. Types and names are inferred; NOT original source. */

undefined4 FUN_1c0f7284(int param_1,int param_2,char param_3,int param_4)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  code *pcVar7;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  int *piVar11;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined1 local_24;
  
  uVar2 = FUN_1c0f6f1c();
  if (param_4 == 0) {
    iVar3 = FUN_1c0f8400(param_1,uVar2,param_3 + '\x01');
    if (iVar3 != 0) {
      pbVar10 = *(byte **)(iVar3 + 4);
LAB_1c0f72cc:
      iVar9 = param_2 + 0xc;
      uVar4 = FUN_1c0f6938(iVar9);
      uVar5 = (uint)*pbVar10;
      if (uVar4 < uVar5) {
        uVar5 = FUN_1c0f6938(iVar9);
      }
      FUN_1c0f68c0(iVar9,pbVar10,uVar5);
      piVar11 = *(int **)(iVar3 + 0xc);
      do {
        if (piVar11 == (int *)0x0) {
          if ((uint)*(ushort *)(param_2 + 0x10) <= (uint)*(ushort *)(param_1 + 0x26)) {
            return 0;
          }
          FUN_1c0f6918(iVar9,(uint)*(ushort *)(param_2 + 0x10) - (uint)*(ushort *)(param_1 + 0x26));
          return 0;
        }
        pcVar7 = *(code **)(*(int *)(piVar11[1] + 8) + 0x30);
        if ((pcVar7 != (code *)0x0) &&
           (puVar6 = (undefined4 *)(*pcVar7)(piVar11[1],uVar2), puVar6 != (undefined4 *)0x0)) {
          pcVar8 = (char *)*puVar6;
          while (pcVar8 != (char *)0x0) {
            while( true ) {
              if (*pcVar8 == '\0') goto LAB_1c0f7334;
              uVar4 = FUN_1c0f6938(iVar9);
              if (*(byte *)*puVar6 <= uVar4) break;
              uVar1 = FUN_1c0f6938(iVar9);
              FUN_1c0f68c0(iVar9,*puVar6,uVar1);
              puVar6 = puVar6 + 1;
              pcVar8 = (char *)*puVar6;
              if (pcVar8 == (char *)0x0) goto LAB_1c0f7334;
            }
            FUN_1c0f68c0(iVar9);
            puVar6 = puVar6 + 1;
            pcVar8 = (char *)*puVar6;
          }
        }
LAB_1c0f7334:
        piVar11 = (int *)*piVar11;
      } while( true );
    }
  }
  else {
    iVar3 = FUN_1c0f6f28(param_1);
    if (iVar3 == 1) {
      uVar2 = (uint)(uVar2 == 0);
      iVar3 = FUN_1c0f8400(param_1,uVar2,param_3 + '\x01');
      if (iVar3 != 0) {
        puVar6 = *(undefined4 **)(iVar3 + 4);
        uStack_28 = puVar6[1];
        pbVar10 = (byte *)&local_2c;
        local_24 = *(undefined1 *)(puVar6 + 2);
        local_2c._2_2_ = (undefined2)((uint)*puVar6 >> 0x10);
        local_2c._0_2_ = CONCAT11(7,(byte)*puVar6);
        goto LAB_1c0f72cc;
      }
    }
  }
  iVar3 = FUN_1c103614();
  *(undefined4 *)(DAT_1c0f7390 + iVar3) = 0xffffff7a;
  return 0;
}


