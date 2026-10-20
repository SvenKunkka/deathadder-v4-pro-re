/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0f8884. Types and names are inferred; NOT original source. */

int FUN_1c0f8884(int param_1,int param_2,int param_3,uint param_4,char param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = *(int *)(param_2 + 4);
  uVar1 = FUN_1c0f6f1c();
  pcVar4 = *(code **)(*(int *)(iVar5 + 8) + 0x30);
  if ((pcVar4 == (code *)0x0) ||
     (puVar2 = (undefined4 *)(*pcVar4)(iVar5,uVar1), puVar2 == (undefined4 *)0x0)) {
    return -0x16;
  }
  pcVar6 = (char *)*puVar2;
  if (pcVar6 != (char *)0x0) {
    bVar3 = false;
    do {
      while( true ) {
        if (*pcVar6 == '\0') goto LAB_1c0f8912;
        if (pcVar6[1] == '\x04') break;
        if ((pcVar6[1] != '\x05') || (!bVar3)) goto LAB_1c0f88c0;
        if (param_3 == 1) {
          iVar5 = FUN_1c0f8a70(*(undefined4 *)(param_1 + 0x18),pcVar6,param_2 + 0xc);
        }
        else {
          if (param_3 != 2) goto LAB_1c0f8908;
          iVar5 = FUN_1c0f8ab0(*(undefined4 *)(param_1 + 0x18),pcVar6[2],param_2 + 0xc);
        }
        if (iVar5 != 0) {
          return iVar5;
        }
LAB_1c0f8908:
        puVar2 = puVar2 + 1;
        pcVar6 = (char *)*puVar2;
        bVar3 = true;
        if (pcVar6 == (char *)0x0) goto LAB_1c0f8912;
      }
      if (bVar3) {
        return 0;
      }
      if (((byte)pcVar6[2] == param_4) && (pcVar6[3] == param_5)) {
        if (pcVar6[4] == '\0') {
          return 0;
        }
        goto LAB_1c0f8908;
      }
LAB_1c0f88c0:
      puVar2 = puVar2 + 1;
      pcVar6 = (char *)*puVar2;
    } while (pcVar6 != (char *)0x0);
LAB_1c0f8912:
    if (bVar3) {
      return 0;
    }
  }
  return -0x3d;
}


