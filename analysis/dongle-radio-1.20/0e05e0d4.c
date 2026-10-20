/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e0d4. Types and names are inferred; NOT original source. */

int FUN_0e05e0d4(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined1 *param_5)

{
  int iVar1;
  uint uVar2;
  byte local_20;
  undefined1 local_1f;
  short local_1e;
  int local_1c;
  
  uVar2 = param_1[6];
  iVar1 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                    (param_1[0xe],
                     (param_4 - (uint)(uVar2 < (uint)param_1[0x10])) * uVar2 +
                     (uVar2 - param_1[0x10]) + *param_1,&local_20,0x10);
  if (-1 < iVar1) {
    uVar2 = FUN_0e05d23c(0xff,&local_1f,0xf);
    if (((local_20 == uVar2) && (local_1e == -1)) && (local_1c == -1)) {
      *param_5 = local_1f;
      return 0;
    }
    iVar1 = -2;
  }
  return iVar1;
}


