/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e13c. Types and names are inferred; NOT original source. */

void FUN_0e05e13c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char local_21;
  undefined1 local_20;
  char local_1f [15];
  
  local_1f[1] = -1;
  local_1f[2] = -1;
  local_1f[3] = -1;
  local_1f[4] = -1;
  local_1f[5] = -1;
  local_1f[6] = -1;
  local_1f[0xb] = '\x01';
  local_1f[0xc] = 'B';
  local_1f[0xd] = '\0';
  local_1f[0xe] = '\0';
  local_1f[7] = '\0';
  local_1f[8] = '\0';
  local_1f[9] = '\0';
  local_1f[10] = '\0';
  iVar1 = FUN_0e05e0d4(param_1,param_2,0,param_4,&local_21);
  if (iVar1 == -2) {
    local_1f[0] = '\x01';
  }
  else {
    if (iVar1 != 0) {
      return;
    }
    local_1f[0] = local_21 + '\x01';
  }
  local_20 = FUN_0e05d23c(0xff,local_1f,0xf);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 0x18) - *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0xc) = param_4 - (uint)(*(uint *)(param_1 + 0x18) < *(uint *)(param_1 + 0x40))
  ;
  iVar1 = FUN_0e05dfe0(param_1,&local_20);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(undefined4 *)(param_1 + 0xc) = uVar3;
  }
  return;
}


