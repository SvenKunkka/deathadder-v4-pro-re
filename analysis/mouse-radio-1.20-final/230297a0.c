/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230297a0. Types and names are inferred; NOT original source. */

undefined4 FUN_230297a0(int param_1,uint param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_2 >> 5;
  uVar4 = (uint)(byte)(&DAT_0e09b6b0)[uVar5] + (param_2 & 0x1f) & 0xff;
  if (-1 < (int)((uint)*(ushort *)
                        (&DAT_2300130c + ((uint)*(byte *)(param_1 + 4) * 0x52 + uVar4 + 8) * 2) <<
                0x1f)) {
    return 0xbad0004;
  }
  piVar2 = (int *)FUN_23029718();
  if ((int)((uint)*(ushort *)(&DAT_2300130c + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2)
           << 0x1a) < 0) {
    iVar3 = *piVar2 + (uint)(*(ushort *)
                              (&DAT_2300130c + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2)
                            >> 0xd) * 4;
    *(undefined4 *)(iVar3 + 0x510) = 0;
    *(undefined4 *)(iVar3 + 0x510) = 0;
  }
  FUN_2302985c(piVar2,param_2);
  *(undefined2 *)(&DAT_2300130c + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2) = 0;
  if (uVar5 < 10) {
    iVar3 = *(int *)(&DAT_0e09b688 + uVar5 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcf0f0 | 2;
    return 0xbad0000;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0x23029840);
  (*pcVar1)();
}


