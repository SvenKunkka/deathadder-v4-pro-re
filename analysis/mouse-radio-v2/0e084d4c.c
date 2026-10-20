/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e084d4c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e084d4c(byte *param_1,ushort *param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  byte local_31;
  byte *local_30;
  uint local_2c;
  undefined1 local_28;
  int local_24;
  uint local_20;
  undefined1 local_1c;
  
  iVar2 = DAT_0e084dfc;
  local_2c = (uint)*param_1;
  if (local_2c == 2) {
    uVar3 = FUN_0e084ce8(param_1[1],param_1 + 4,param_1[10]);
    return uVar3;
  }
  if (local_2c == 4) {
    *(undefined2 *)(DAT_0e084dfc + 2) = *(undefined2 *)(param_1 + 8);
LAB_0e084dda:
    uVar3 = 1;
  }
  else {
    if (local_2c == 1) {
      local_20 = (uint)param_1[10];
      bVar1 = param_1[1];
      *(byte *)(DAT_0e084dfc + 0x14) = bVar1;
      if (local_20 < 2) {
        local_30 = (byte *)(iVar2 + 0x14);
      }
      else {
        local_30 = &local_31;
        local_31 = bVar1;
      }
      local_24 = iVar2 + 0x24;
      local_28 = 0;
      local_1c = 7;
      iVar4 = (**(code **)(*(int *)(DAT_0e084e00 + 8) + 8))(DAT_0e084e00,&local_30,2,0x6a);
      if (iVar4 == 0) {
        *(undefined1 *)(iVar2 + 6) = 0;
        if (param_2 != (ushort *)0x0) {
          if (param_1[10] == 1) {
            *param_2 = (ushort)*(byte *)(iVar2 + 0x24);
          }
          else if (param_1[10] == 2) {
            *param_2 = *(ushort *)(iVar2 + 0x24);
          }
        }
        goto LAB_0e084dda;
      }
      *(char *)(iVar2 + 6) = *(char *)(iVar2 + 6) + '\x01';
    }
    uVar3 = 0;
  }
  return uVar3;
}


