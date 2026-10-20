/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230251e4. Types and names are inferred; NOT original source. */

void FUN_230251e4(undefined4 param_1,undefined4 param_2,char *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  byte local_68;
  undefined1 auStack_67 [67];
  char *pcVar4;
  
  if (param_4 == 0) {
    cVar9 = '\0';
  }
  else {
    cVar9 = '\0';
    pcVar4 = param_3;
    do {
      pcVar3 = pcVar4 + 1;
      cVar9 = cVar9 + *pcVar4;
      pcVar4 = pcVar3;
    } while (pcVar3 != param_3 + param_4);
    cVar9 = -cVar9;
  }
  param_3[param_4] = cVar9;
  uVar5 = param_4 + 1U & 0xffff;
  uVar1 = FUN_23020768(param_1,param_2);
  uVar8 = ((int)(uVar5 + 3) >> 2) - 1U & 0xffff;
  if (uVar8 < uVar1) {
    uVar6 = 0;
    uVar1 = 0;
    do {
      if (uVar1 == uVar8) {
        local_68 = 0;
        uVar1 = uVar5 + 1 & 0xffff;
        uVar7 = uVar5;
      }
      else {
        uVar1 = 5;
        local_68 = 0x80;
        uVar7 = 4;
      }
      local_68 = local_68 | (byte)uVar6;
      thunk_FUN_0e06f35c(auStack_67,param_3);
      iVar2 = FUN_230208b8(param_1,param_2,&local_68,uVar1,0xff);
      uVar6 = uVar6 + 1;
      uVar1 = uVar6 & 0xffff;
      uVar5 = uVar5 - uVar7 & 0xffff;
    } while ((iVar2 != 0) && (param_3 = param_3 + uVar7, uVar1 <= uVar8));
  }
  return;
}


