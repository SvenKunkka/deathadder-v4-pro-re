/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091ed0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e091ed0(uint param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_1 < 0x140) {
    iVar5 = *(int *)(&DAT_0e09b718 + (param_1 >> 5) * 4);
    iVar6 = 1 << (param_1 & 0x1f);
    uVar9 = param_2 & 0x1f;
    *(int *)(iVar5 + 4) = iVar6;
    if (param_2 < 0x140) {
      iVar7 = *(int *)(&DAT_0e09b718 + (param_2 >> 5) * 4);
      uVar8 = 1 << uVar9;
      *(uint *)(iVar7 + 4) = uVar8;
      iVar4 = iVar5 + (param_1 & 0x1f) * 4;
      iVar2 = iVar7 + uVar9 * 4;
      *(uint *)(iVar4 + 0x80) = *(uint *)(iVar4 + 0x80) & 0xfffcf0f0 | 0x80d;
      *(uint *)(iVar2 + 0x80) = *(uint *)(iVar2 + 0x80) & 0xfffcf0f0 | 0x80d;
      cVar3 = '\t';
      FUN_0e097590(4);
      do {
        if ((uVar8 & *(uint *)(iVar7 + 0xc)) != 0) break;
        *(int *)(iVar5 + 8) = iVar6;
        FUN_0e097590(4);
        *(int *)(iVar5 + 4) = iVar6;
        FUN_0e097590(4);
        cVar3 = cVar3 + -1;
      } while (cVar3 != '\0');
      *(uint *)(iVar7 + 8) = uVar8;
      FUN_0e097590(4);
      *(uint *)(iVar7 + 4) = uVar8;
      FUN_0e097590(4);
      return 0xbad0001 - (*(uint *)(iVar7 + 0xc) >> uVar9 & 1);
    }
  }
  _Reset = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe091f8c);
  (*pcVar1)();
}


