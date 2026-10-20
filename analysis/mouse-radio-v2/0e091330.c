/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091330. Types and names are inferred; NOT original source. */

bool FUN_0e091330(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = *(byte *)(param_1 + 1);
  *(undefined4 *)(*param_1 + 0x200) = 0;
  *(undefined4 *)(*param_1 + 4) = 1;
  iVar2 = DAT_0e0913d4;
  if (param_2 != 0) {
    iVar5 = *param_1;
    do {
      while ((iVar4 = iVar2 + (uint)*(byte *)(param_1 + 1) * 0x14,
             *(int *)(iVar2 + (uint)*(byte *)(param_1 + 1) * 0x14) != 0 ||
             (*(int *)(iVar5 + 0x104) == 0))) {
        if (*(char *)(iVar4 + 8) != '\x02') goto LAB_0e0913a4;
      }
      *(undefined4 *)(iVar5 + 0x104) = 0;
      *(undefined1 *)(iVar4 + 8) = 1;
      iVar5 = *param_1;
    } while (*(char *)(iVar4 + 8) == '\x02');
LAB_0e0913a4:
    *(undefined4 *)(iVar5 + 0x500) = 0;
    *(undefined1 *)(iVar2 + (uint)bVar1 * 0x14 + 8) = 1;
  }
  uVar3 = (uint)*(byte *)(param_1 + 1);
  if ((*(int *)(iVar2 + uVar3 * 0x14) == 0) && (*(int *)(*param_1 + 0x104) != 0)) {
    *(undefined4 *)(*param_1 + 0x104) = 0;
    *(undefined1 *)(iVar2 + uVar3 * 0x14 + 8) = 1;
  }
  return *(char *)(iVar2 + uVar3 * 0x14 + 8) != '\x02';
}


