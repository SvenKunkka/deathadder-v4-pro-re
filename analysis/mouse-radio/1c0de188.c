/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0de188. Types and names are inferred; NOT original source. */

void FUN_1c0de188(undefined4 param_1,int param_2,byte *param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  char cVar8;
  
  iVar5 = DAT_1c0de238;
  iVar4 = DAT_1c0de234;
  bVar1 = *param_3;
  iVar7 = DAT_1c0de230 + param_2 * 0x80;
  if ((bVar1 & 0x1f) == 0) {
    *(byte *)(DAT_1c0de234 + param_2) = bVar1 & 0x1f;
    *(char *)(iVar5 + param_2) = (char)param_4 + -1;
    cVar8 = '\x01';
    thunk_EXT_FUN_0e0974c4(iVar7,param_3 + 1);
  }
  else {
    if (*(byte *)(DAT_1c0de234 + param_2) != (bVar1 & 0x1f)) {
      *(undefined1 *)(DAT_1c0de234 + param_2) = 0;
      *(undefined1 *)(iVar5 + param_2) = 0;
      return;
    }
    bVar2 = *(byte *)(DAT_1c0de238 + param_2);
    cVar8 = *(byte *)(DAT_1c0de234 + param_2) + 1;
    thunk_EXT_FUN_0e0974c4(iVar7 + (uint)bVar2,param_3 + 1,param_4 + -1);
    *(byte *)(iVar5 + param_2) = bVar2 + (char)(param_4 + -1);
  }
  *(char *)(iVar4 + param_2) = cVar8;
  if ((int)((uint)bVar1 << 0x18) < 0) {
    return;
  }
  uVar3 = *(undefined1 *)(iVar5 + param_2);
  *DAT_1c0de23c = (char)param_2;
  uVar6 = DAT_1c0de244;
  *DAT_1c0de240 = uVar3;
  thunk_EXT_FUN_0e0974c4(uVar6,iVar7);
  *(undefined1 *)(iVar4 + param_2) = 0;
  *(undefined1 *)(iVar5 + param_2) = 0;
  thunk_EXT_FUN_0e095414(DAT_1c0de248);
  return;
}


