/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025004. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23025004(undefined4 param_1,int param_2,byte *param_3,char param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  char cVar7;
  byte *pbVar8;
  char local_49;
  byte local_48 [4];
  short local_44;
  undefined2 local_42;
  byte abStack_39 [21];
  
  bVar1 = *param_3;
  pbVar8 = (byte *)(param_2 * 0x80 + 0x23006278);
  local_49 = param_4;
  if ((bVar1 & 0x1f) == 0) {
    (&DAT_23006578)[param_2] = bVar1 & 0x1f;
    (&DAT_23006580)[param_2] = param_4 + -1;
    cVar7 = '\x01';
    thunk_FUN_0e06f35c(pbVar8,param_3 + 1);
  }
  else {
    if ((&DAT_23006578)[param_2] != (bVar1 & 0x1f)) {
      (&DAT_23006578)[param_2] = 0;
      (&DAT_23006580)[param_2] = 0;
      return;
    }
    bVar2 = (&DAT_23006580)[param_2];
    cVar7 = (&DAT_23006578)[param_2] + 1;
    thunk_FUN_0e06f35c(pbVar8 + bVar2,param_3 + 1);
    (&DAT_23006580)[param_2] = bVar2 + param_4 + -1;
  }
  (&DAT_23006578)[param_2] = cVar7;
  if ((int)((uint)bVar1 << 0x18) < 0) {
    return;
  }
  iVar6 = 0;
  (&DAT_23006578)[param_2] = 0;
  cVar7 = (&DAT_23006580)[param_2];
  (&DAT_23006580)[param_2] = 0;
  if (param_2 == 1) {
    local_48[0] = (DAT_230062f8 | DAT_23006588) & 0x7f;
    local_44 = (uRam230062fa << 8 | uRam230062fa >> 8) + _DAT_2300658c;
    local_42 = (uRam230062fc << 8 | uRam230062fc >> 8) + DAT_2300658e;
    cVar7 = (char)DAT_23006589;
    DAT_23006588 = 0;
    _DAT_2300658c = 0;
    DAT_23006589 = 0;
    local_48[3] = cRam230062f9 + cVar7;
    local_48[1] = 0;
    local_48[2] = 0;
  }
  else {
    local_49 = cVar7;
    if (param_2 == 3) {
      iVar6 = FUN_23024c88(param_1,0x230063f8,cVar7);
      if (iVar6 != 0) {
        return;
      }
      goto LAB_230250be;
    }
    if (param_2 != 2) {
      if (param_2 == 4) {
        pbVar8 = local_48;
        thunk_FUN_0e06f3aa(pbVar8,0,0x20);
        thunk_FUN_0e06f35c(pbVar8,0x23006478,cVar7);
        iVar3 = FUN_23020128(pbVar8,&local_49);
        if (iVar3 == 0) {
          return;
        }
        local_49 = '\x10';
        if (local_48[0] == 1) {
          pbVar5 = local_48 + 1;
          DAT_23006594 = 0;
          do {
            pbVar5 = pbVar5 + 1;
            if (*pbVar5 != 0) {
              iVar6 = iVar3;
            }
          } while (abStack_39 != pbVar5);
          if (iVar6 != 0) {
            DAT_23006594 = 1;
          }
        }
      }
      goto LAB_230250be;
    }
    thunk_FUN_0e06f3aa(local_48,0,0x20);
    thunk_FUN_0e06f35c(local_48,0x23006378,cVar7);
    iVar6 = FUN_23020128(local_48,&local_49);
    if (iVar6 == 0) {
      return;
    }
    iVar3 = 0;
    pcVar4 = &local_49;
    do {
      pcVar4 = pcVar4 + 1;
      if (*pcVar4 != '\0') {
        iVar3 = iVar6;
      }
    } while ((char *)((int)&local_42 + 1) != pcVar4);
    DAT_23006594 = iVar3 != 0;
  }
  local_49 = '\b';
  pbVar8 = local_48;
LAB_230250be:
  FUN_23020250(param_2,pbVar8,local_49);
  return;
}


