/* Automatically decompiled from Suit2FWData__radio_radio.bin at 2302963c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302963c(int *param_1,uint param_2,int param_3)

{
  code *pcVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = param_2 >> 5;
  param_2 = param_2 & 0x1f;
  if (-1 < *(int *)(*param_1 + 0x354) << 10) {
    *(undefined4 *)(*param_1 + 0x354) = 0x200000;
  }
  uVar2 = *(ushort *)
           (&DAT_2300130c +
           ((uint)*(byte *)(param_1 + 1) * 0x52 + ((byte)(&DAT_0e09b6b0)[uVar6] + param_2 & 0xff) +
           8) * 2);
  uVar4 = (uint)uVar2;
  if (((int)(uVar4 << 0x1a) < 0) && ((uVar2 & 2) == 0)) {
    iVar5 = (uint)(uVar2 >> 0xd) * 4;
    *(uint *)(*param_1 + iVar5 + 0x100) = uVar4 & 2;
    iVar5 = *param_1 + iVar5;
    *(uint *)(iVar5 + 0x510) = *(uint *)(iVar5 + 0x510) | 1;
    if (param_3 != 0) {
      *(int *)(*param_1 + 0x354) = 1 << (uint)(uVar2 >> 0xd);
    }
    return;
  }
  uVar4 = (uVar4 & 0x1f) >> 2;
  if (uVar4 == 4) {
    iVar5 = 3;
  }
  else {
    if (uVar4 != 5) {
      if (9 < uVar6) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0x230296fe);
        (*pcVar1)();
      }
      iVar3 = *(int *)(&DAT_0e09b688 + uVar6 * 4);
      iVar5 = (*(uint *)(iVar3 + 0xc) >> param_2 & 1) + 2;
      goto LAB_230296e0;
    }
    iVar5 = 2;
  }
  if (9 < uVar6) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0x23029708);
    (*pcVar1)();
  }
  iVar3 = *(int *)(&DAT_0e09b688 + uVar6 * 4);
LAB_230296e0:
  iVar3 = iVar3 + param_2 * 4;
  *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcffff | iVar5 << 0x10;
  return;
}


