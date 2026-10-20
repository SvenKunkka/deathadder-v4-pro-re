/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0551d0. Types and names are inferred; NOT original source. */

void FUN_0e0551d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  thunk_FUN_0e06f446(param_1,0,0x20,param_4,param_4);
  puVar4 = DAT_0e05522c;
  iVar3 = DAT_0e055228;
  puVar2 = DAT_0e055224;
  *param_1 = *(undefined4 *)(DAT_0e055224 + 10);
  uVar1 = *puVar2;
  param_1[1] = *(undefined4 *)(puVar2 + 0xe);
  param_1[2] = *(undefined4 *)(iVar3 + 0xe30);
  uVar5 = *puVar4;
  param_1[3] = *(undefined4 *)(iVar3 + 0xe34);
  *(char *)((int)param_1 + 0x13) = (char)uVar1;
  *(char *)(param_1 + 6) = (char)uVar5;
  *(char *)((int)param_1 + 0x19) = (char)puVar4[0x20];
  *(char *)((int)param_1 + 0x1a) = (char)*(undefined2 *)(puVar4 + 0x32);
  *(char *)((int)param_1 + 0x1b) = (char)*(undefined2 *)((int)puVar4 + 0xca);
  *(char *)(param_1 + 7) = (char)*(undefined2 *)(puVar4 + 0x33);
  *(char *)((int)param_1 + 0x1d) = (char)*(undefined2 *)((int)puVar4 + 0xce);
  *(char *)((int)param_1 + 0x1e) = (char)*(undefined2 *)(puVar4 + 0x34);
  return;
}


