/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e075dd4. Types and names are inferred; NOT original source. */

void thunk_FUN_0e075eb4(int *param_1,uint param_2)

{
  code *pcVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_2 >> 5;
  uVar2 = *(ushort *)
           (&DAT_2300130c +
           ((uint)*(byte *)(param_1 + 1) * 0x52 +
            ((uint)(byte)(&DAT_0e09b6b0)[uVar4] + (param_2 & 0x1f) & 0xff) + 8) * 2);
  if (((int)((uint)uVar2 << 0x1a) < 0) && (-1 < (int)((uint)uVar2 << 0x1e))) {
    *(int *)(*param_1 + 0x358) = 1 << (uint)(uVar2 >> 0xd);
    iVar3 = *param_1 + (uint)(uVar2 >> 0xd) * 4;
    *(uint *)(iVar3 + 0x510) = *(uint *)(iVar3 + 0x510) & 0xfffffffc;
    return;
  }
  if (uVar4 < 10) {
    iVar3 = *(int *)(&DAT_0e09b688 + uVar4 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcffff;
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe075f2e);
  (*pcVar1)();
}


