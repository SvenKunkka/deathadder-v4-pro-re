/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f8524. Types and names are inferred; NOT original source. */

int FUN_1c0f8524(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  
  iVar7 = param_3[1];
  FUN_1c100d84(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
  if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0) {
    iVar6 = -0x10;
    goto LAB_1c0f8618;
  }
  if (param_2 == 1) {
    iVar6 = FUN_1c0f6f28(param_1);
    if ((iVar6 != 0) &&
       ((-1 < (int)((uint)*(byte *)(iVar7 + 7) << 0x1a) ||
        (*(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80) << 0x1e < 0)))) {
      puVar3 = *(undefined4 **)(param_1 + 0x50);
      puVar8 = (undefined4 *)(param_1 + 0x58);
      if (puVar3 != (undefined4 *)0x0) {
        do {
          if (puVar3 == param_3) goto LAB_1c0f8614;
          puVar3 = (undefined4 *)*puVar3;
        } while (puVar3 != (undefined4 *)0x0);
        goto LAB_1c0f8588;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x58);
      if (puVar3 != (undefined4 *)0x0) goto LAB_1c0f858e;
      iVar6 = param_3[1];
LAB_1c0f8654:
      cVar2 = *(char *)(*(int *)(param_1 + 0x68) + 0x11) + '\x01';
      *(char *)(iVar6 + 5) = cVar2;
      iVar6 = *(int *)(param_1 + 0x68);
LAB_1c0f85b2:
      *(char *)(iVar6 + 0x11) = cVar2;
      goto LAB_1c0f85b4;
    }
  }
  else if (((-1 < (int)((uint)*(byte *)(iVar7 + 7) << 0x1a)) ||
           (*(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80) << 0x1e < 0)) &&
          (param_2 == 0)) {
    puVar3 = *(undefined4 **)(param_1 + 0x58);
    puVar8 = (undefined4 *)(param_1 + 0x50);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = *(undefined4 **)(param_1 + 0x50);
      if (puVar3 == (undefined4 *)0x0) {
LAB_1c0f85a4:
        cVar2 = *(char *)(*(int *)(param_1 + 100) + 0x11) + '\x01';
        *(char *)(param_3[1] + 5) = cVar2;
        iVar6 = *(int *)(param_1 + 100);
        goto LAB_1c0f85b2;
      }
    }
    else {
      do {
        if (param_3 == puVar3) goto LAB_1c0f8614;
        puVar3 = (undefined4 *)*puVar3;
      } while (puVar3 != (undefined4 *)0x0);
LAB_1c0f8588:
      puVar3 = (undefined4 *)*puVar8;
      if (puVar3 == (undefined4 *)0x0) {
LAB_1c0f85a0:
        if (param_2 == 0) goto LAB_1c0f85a4;
        iVar6 = param_3[1];
        if (param_2 == 1) goto LAB_1c0f8654;
        *(undefined1 *)(iVar6 + 5) = 1;
        goto LAB_1c0f85b4;
      }
    }
LAB_1c0f858e:
    if (param_3 == puVar3) {
      uVar5 = *param_3;
      *puVar8 = uVar5;
      if ((undefined4 *)puVar8[1] == param_3) {
        puVar8[1] = uVar5;
      }
    }
    else {
      do {
        puVar4 = puVar3;
        puVar3 = (undefined4 *)*puVar4;
        if (puVar3 == (undefined4 *)0x0) goto LAB_1c0f85a0;
      } while (puVar3 != param_3);
      *puVar4 = *param_3;
      if ((undefined4 *)puVar8[1] == param_3) {
        puVar8[1] = puVar4;
      }
    }
    *param_3 = 0;
LAB_1c0f85b4:
    if (param_3[2] != 0) {
      iVar6 = FUN_1c0f717c(param_1);
      if (iVar6 != 0) goto LAB_1c0f8618;
      uVar1 = FUN_1c0f7278(param_3[2]);
      *(undefined1 *)(iVar7 + 6) = uVar1;
    }
    *param_3 = 0;
    if ((undefined4 *)puVar8[1] == (undefined4 *)0x0) {
      *puVar8 = param_3;
      puVar8[1] = param_3;
    }
    else {
      *(undefined4 *)puVar8[1] = param_3;
      puVar8[1] = param_3;
    }
    iVar6 = 0;
    goto LAB_1c0f8618;
  }
  iVar6 = -0x86;
LAB_1c0f8618:
  FUN_1c100e80(param_1 + 4);
  return iVar6;
LAB_1c0f8614:
  iVar6 = -0x16;
  goto LAB_1c0f8618;
}


