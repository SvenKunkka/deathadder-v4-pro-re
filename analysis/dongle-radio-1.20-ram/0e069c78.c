/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069c78. Types and names are inferred; NOT original source. */

bool FUN_0e069c78(int *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = *(byte *)(param_1 + 1);
  *(undefined4 *)(*param_1 + 0x200) = 0;
  *(undefined4 *)(*param_1 + 4) = 1;
  if (param_2 != 0) {
    iVar4 = *param_1;
    do {
      while ((iVar1 = (uint)*(byte *)(param_1 + 1) * 0x14,
             (&DAT_23006e04)[(uint)*(byte *)(param_1 + 1) * 5] != 0 ||
             (*(int *)(iVar4 + 0x104) == 0))) {
        if ((&DAT_23006e0c)[iVar1] != '\x02') goto LAB_0e069cec;
      }
      *(undefined4 *)(iVar4 + 0x104) = 0;
      (&DAT_23006e0c)[iVar1] = 1;
      iVar4 = *param_1;
    } while ((&DAT_23006e0c)[iVar1] == '\x02');
LAB_0e069cec:
    *(undefined4 *)(iVar4 + 0x500) = 0;
    (&DAT_23006e0c)[(uint)bVar2 * 0x14] = 1;
  }
  uVar3 = (uint)*(byte *)(param_1 + 1);
  if (((&DAT_23006e04)[uVar3 * 5] == 0) && (*(int *)(*param_1 + 0x104) != 0)) {
    *(undefined4 *)(*param_1 + 0x104) = 0;
    (&DAT_23006e0c)[uVar3 * 0x14] = 1;
  }
  return (&DAT_23006e0c)[uVar3 * 0x14] != '\x02';
}


