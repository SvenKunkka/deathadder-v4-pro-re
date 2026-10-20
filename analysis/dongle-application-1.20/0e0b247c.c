/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b247c. Types and names are inferred; NOT original source. */

void FUN_0e0b247c(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  FUN_0e0afbe4();
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 2;
  if (param_2 != (int *)0x0) {
    param_1[2] = (int)param_2;
    piVar2 = (int *)*param_2;
    if (param_2 != piVar2) {
      for (; piVar2 != (undefined4 *)0x0; piVar2 = (int *)*piVar2) {
        if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)piVar2 + 0xe)) &&
           (*(char *)((int)param_1 + 0xe) < *(char *)((int)piVar2 + 0xe))) {
          piVar1 = (int *)piVar2[1];
          *param_1 = (int)piVar2;
          param_1[1] = (int)piVar1;
          *piVar1 = (int)param_1;
          piVar2[1] = (int)param_1;
          return;
        }
        if ((undefined4 *)param_2[1] == piVar2) break;
      }
    }
    piVar2 = (int *)param_2[1];
    *param_1 = (int)param_2;
    param_1[1] = (int)piVar2;
    *piVar2 = (int)param_1;
    param_2[1] = (int)param_1;
  }
  return;
}


