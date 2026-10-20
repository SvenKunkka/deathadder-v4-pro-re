/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b18be. Types and names are inferred; NOT original source. */

uint FUN_0e0b18be(int *param_1,undefined4 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  
  if (param_2[0x1a] == 2) {
    if (param_4 == 0) {
      uVar2 = 0xffffffc3;
    }
    else {
      iVar1 = FUN_0e0af598(param_2 + 2,param_2,0x20,0);
      if (iVar1 < 0) {
        uVar2 = 0xffffff97;
      }
      else {
        uVar2 = FUN_0e0b19ec(*param_2,param_3,param_4 & 0xffff);
        FUN_0e0af688(param_2 + 2);
        if (-1 < (int)uVar2) {
          if (uVar2 < param_4) {
            return 0xffffffb3;
          }
          pcVar4 = (code *)**(undefined4 **)(*param_1 + 8);
          if (pcVar4 == (code *)0x0) {
            return 0xffffffa8;
          }
          uVar3 = (*pcVar4)(*param_1,param_1[1],0);
          if (uVar3 != 0) {
            return uVar3;
          }
        }
      }
    }
  }
  else {
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}


