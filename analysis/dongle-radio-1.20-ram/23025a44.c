/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025a44. Types and names are inferred; NOT original source. */

void FUN_23025a44(void)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  undefined1 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined2 uVar8;
  uint uVar9;
  char *pcVar4;
  
  puVar7 = &DAT_23002ca8;
  iVar1 = (((uint)DAT_230071b6 * 100) / 0xff) * 4;
  pcVar4 = &DAT_23002cb4;
  do {
    pcVar3 = pcVar4 + 1;
    cVar2 = *pcVar4;
    if (cVar2 == '\x01') {
      uVar8 = *(undefined2 *)(&DAT_0e06f7d4 + iVar1);
      *(undefined1 *)((int)puVar7 + 3) = 1;
      uVar5 = (&DAT_0e06f7d6)[iVar1];
      *(undefined2 *)puVar7 = uVar8;
      *(undefined1 *)((int)puVar7 + 2) = uVar5;
    }
    else if (cVar2 == '\x02') {
      uVar9 = (uint)DAT_230071b3;
      *(undefined1 *)((int)puVar7 + 3) = 1;
      *(undefined2 *)puVar7 = *(undefined2 *)(&DAT_0e06f7c0 + uVar9 * 4);
      *(undefined *)((int)puVar7 + 2) = (&DAT_0e06f7c2)[uVar9 * 4];
    }
    else if (cVar2 == '\x03') {
      if ((int)((uint)DAT_230071b4 << 0x1f) < 0) {
        uVar8 = 0xff;
        uVar5 = 0;
LAB_23025b02:
        *(undefined1 *)((int)puVar7 + 2) = uVar5;
        *(undefined2 *)puVar7 = uVar8;
        *(undefined1 *)((int)puVar7 + 3) = 1;
      }
      else {
        uVar9 = 1;
        do {
          uVar6 = uVar9 + 1;
          if (((int)(uint)DAT_230071b4 >> (uVar9 & 0xff)) << 0x1f < 0) {
            uVar8 = (&DAT_0e06f7a4)[uVar9 * 2];
            uVar5 = (&DAT_0e06f7a6)[uVar9 * 4];
            goto LAB_23025b02;
          }
          uVar9 = uVar6;
        } while (uVar6 != 7);
      }
    }
    else if (cVar2 == '\x04') {
      uVar9 = (uint)DAT_230071b5;
      *(undefined1 *)((int)puVar7 + 3) = 1;
      *(undefined2 *)puVar7 = *(undefined2 *)(&DAT_0e06f790 + uVar9 * 4);
      *(undefined *)((int)puVar7 + 2) = (&DAT_0e06f792)[uVar9 * 4];
    }
    else {
      *(undefined2 *)puVar7 = 0;
      *(undefined1 *)((int)puVar7 + 3) = 1;
      *(undefined1 *)((int)puVar7 + 2) = 0;
    }
    puVar7 = puVar7 + 1;
    pcVar4 = pcVar3;
    if (pcVar3 == (char *)0x23002cb7) {
      return;
    }
  } while( true );
}


