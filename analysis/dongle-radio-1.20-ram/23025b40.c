/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025b40. Types and names are inferred; NOT original source. */

void FUN_23025b40(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar8;
  char *pcVar7;
  
  switch(param_1) {
  case 0xe0:
    if (param_2 < 5) {
      puVar4 = &DAT_23002ca8;
      pcVar7 = &DAT_23002cb4;
      do {
        pcVar6 = pcVar7 + 1;
        if (*pcVar7 == '\x02') {
          uVar3 = *(undefined2 *)(&DAT_0e06f7c0 + param_2 * 4);
          *(undefined1 *)((int)puVar4 + 3) = 1;
          *(undefined2 *)puVar4 = uVar3;
          *(undefined *)((int)puVar4 + 2) = (&DAT_0e06f7c2)[param_2 * 4];
        }
        puVar4 = puVar4 + 1;
        pcVar7 = pcVar6;
      } while (pcVar6 != (char *)0x23002cb7);
    }
    break;
  case 0xe1:
    if ((int)(param_2 << 0x1f) < 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (param_2 & 3) >> 1;
      if (-1 < (int)(param_2 << 0x1e)) {
        uVar5 = 2;
        while (uVar8 = uVar5 + 1, -1 < ((int)param_2 >> (uVar5 & 0xff)) << 0x1f) {
          uVar5 = uVar8;
          if (uVar8 == 7) {
            return;
          }
        }
      }
    }
    puVar4 = &DAT_23002ca8;
    pcVar7 = &DAT_23002cb4;
    do {
      pcVar6 = pcVar7 + 1;
      if (*pcVar7 == '\x03') {
        uVar3 = (&DAT_0e06f7a4)[uVar5 * 2];
        *(undefined1 *)((int)puVar4 + 3) = 1;
        *(undefined2 *)puVar4 = uVar3;
        *(undefined1 *)((int)puVar4 + 2) = (&DAT_0e06f7a6)[uVar5 * 4];
      }
      puVar4 = puVar4 + 1;
      pcVar7 = pcVar6;
    } while (pcVar6 != (char *)0x23002cb7);
    break;
  case 0xe2:
    if (param_2 < 5) {
      puVar4 = &DAT_23002ca8;
      pcVar7 = &DAT_23002cb4;
      do {
        pcVar6 = pcVar7 + 1;
        if (*pcVar7 == '\x04') {
          uVar3 = *(undefined2 *)(&DAT_0e06f790 + param_2 * 4);
          *(undefined1 *)((int)puVar4 + 3) = 1;
          *(undefined2 *)puVar4 = uVar3;
          *(undefined *)((int)puVar4 + 2) = (&DAT_0e06f792)[param_2 * 4];
        }
        puVar4 = puVar4 + 1;
        pcVar7 = pcVar6;
      } while (pcVar6 != (char *)0x23002cb7);
    }
    break;
  case 0xe3:
    DAT_230071b9 = param_2 < 0x10;
    if (!(bool)DAT_230071b9) {
      puVar4 = &DAT_23002ca8;
      iVar1 = ((param_2 * 100) / 0xff) * 4;
      pcVar7 = &DAT_23002cb4;
      do {
        pcVar6 = pcVar7 + 1;
        if (*pcVar7 == '\x01') {
          uVar3 = *(undefined2 *)(&DAT_0e06f7d4 + iVar1);
          *(undefined1 *)((int)puVar4 + 3) = 1;
          uVar2 = (&DAT_0e06f7d6)[iVar1];
          *(undefined2 *)puVar4 = uVar3;
          *(undefined1 *)((int)puVar4 + 2) = uVar2;
        }
        puVar4 = puVar4 + 1;
        pcVar7 = pcVar6;
      } while (pcVar6 != (char *)0x23002cb7);
    }
    break;
  case 0xff:
    DAT_23002cac = 0x1000000;
    DAT_23002cb0 = 0x1000000;
    DAT_23002ca8 = 0x1000000;
    DAT_230071b9 = 0;
  }
  return;
}


