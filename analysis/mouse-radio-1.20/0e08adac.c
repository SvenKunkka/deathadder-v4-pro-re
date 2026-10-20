/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08adac. Types and names are inferred; NOT original source. */

undefined4
FUN_0e08adac(int param_1,int param_2,undefined1 param_3,undefined4 param_4,undefined1 param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_0e094c5c(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
  iVar2 = (uint)*(byte *)(param_1 + 0x60) << 0x1e;
  if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1e) < 0) {
    uVar3 = 0xffffff88;
  }
  else {
    if (param_2 == 0) {
      iVar2 = *(int *)(param_1 + 100);
    }
    else {
      if (param_2 != 1) {
        *(byte *)(4 - (iVar2 >> 0x1f)) = (byte)((uint)iVar2 >> 0x1f);
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe08ae04);
        (*pcVar1)();
      }
      iVar2 = *(int *)(param_1 + 0x68);
    }
    uVar3 = 0;
    *(undefined1 *)(iVar2 + 4) = param_3;
    *(char *)(iVar2 + 5) = (char)param_4;
    *(undefined1 *)(iVar2 + 6) = param_5;
  }
  FUN_0e094d58(param_1 + 4);
  return uVar3;
}


