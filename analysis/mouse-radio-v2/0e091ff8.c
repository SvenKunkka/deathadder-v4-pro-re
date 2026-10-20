/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e091ff8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e091ff8(uint param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  iVar3 = DAT_0e0920b8;
  if (param_1 < 0x140) {
    iVar6 = *(int *)(DAT_0e0920b8 + (param_1 >> 5) * 4);
    iVar7 = 1 << (param_1 & 0x1f);
    uVar10 = param_2 & 0x1f;
    *(int *)(iVar6 + 4) = iVar7;
    if (param_2 < 0x140) {
      iVar8 = *(int *)(iVar3 + (param_2 >> 5) * 4);
      uVar9 = 1 << uVar10;
      *(uint *)(iVar8 + 4) = uVar9;
      uVar2 = DAT_0e0920bc;
      iVar5 = iVar6 + (param_1 & 0x1f) * 4;
      iVar3 = iVar8 + uVar10 * 4;
      *(uint *)(iVar5 + 0x80) = *(uint *)(iVar5 + 0x80) & DAT_0e0920bc | 0x80d;
      *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & uVar2 | 0x80d;
      cVar4 = '\t';
      FUN_0e097740(4);
      do {
        if ((uVar9 & *(uint *)(iVar8 + 0xc)) != 0) break;
        *(int *)(iVar6 + 8) = iVar7;
        FUN_0e097740(4);
        *(int *)(iVar6 + 4) = iVar7;
        FUN_0e097740(4);
        cVar4 = cVar4 + -1;
      } while (cVar4 != '\0');
      *(uint *)(iVar8 + 8) = uVar9;
      FUN_0e097740(4);
      *(uint *)(iVar8 + 4) = uVar9;
      FUN_0e097740(4);
      return DAT_0e0920c0 - (*(uint *)(iVar8 + 0xc) >> uVar10 & 1);
    }
  }
  _Reset = 0;
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe0920b4);
  (*pcVar1)();
}


