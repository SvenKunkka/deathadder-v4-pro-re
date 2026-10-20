/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae51c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0ae51c(undefined4 param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_0e0ae0d8(param_2);
  if ((int)uVar3 == 0) {
    uVar2 = 0xbad0004;
  }
  else {
    iVar1 = FUN_0e0ae054((int)((ulonglong)uVar3 >> 0x20));
    uVar2 = 0xbad0000;
    *param_3 = (byte)((ushort)*(undefined2 *)(&DAT_2f01137c + (iVar1 + 8) * 2) >> 0xd);
  }
  return uVar2;
}


