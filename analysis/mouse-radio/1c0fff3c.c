/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0fff3c. Types and names are inferred; NOT original source. */

void FUN_1c0fff3c(undefined4 *param_1,int param_2,int param_3,undefined1 param_4,undefined1 param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  code *pcVar3;
  undefined4 *local_2c;
  int local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  
  local_22 = param_5;
  local_24 = (undefined1)param_2;
  local_28 = param_3;
  local_23 = param_4;
  if (param_3 == 0) {
    if (param_2 == 0) {
      local_28 = 0;
      local_2c = param_1;
    }
    else {
      local_2c = param_1;
    }
  }
  else {
    if (param_2 == 0) {
      uVar1 = **(undefined1 **)(param_3 + 8);
      uVar2 = (*(undefined1 **)(param_3 + 8))[1];
      FUN_1c0ffd44(param_3,&local_2c);
      if (local_2c != (undefined4 *)0x0) {
        *(undefined1 *)((int)local_2c + -2) = uVar1;
        *(undefined1 *)((int)local_2c + -1) = uVar2;
        *(undefined1 *)(local_2c + -1) = param_4;
        *(undefined1 *)((int)local_2c + -3) = param_5;
        *local_2c = param_1;
        *(undefined1 *)((int)local_2c + -5) = 3;
        if (*(char *)(*(int *)(param_3 + 8) + 0x14) != '\0') {
          pcVar3 = *(code **)(**(int **)(param_3 + 0xc) + 4);
          if (pcVar3 != (code *)0x0) {
            (*pcVar3)(*(int **)(param_3 + 0xc),(int)local_2c + -5,9);
          }
        }
      }
    }
    local_2c = param_1;
    if (*(code **)(param_3 + 0x1c) != (code *)0x0) {
      (**(code **)(param_3 + 0x1c))(&local_2c);
    }
  }
  if ((code *)*DAT_1c0fffe4 != (code *)0x0) {
    (*(code *)*DAT_1c0fffe4)(&local_2c);
  }
  return;
}


