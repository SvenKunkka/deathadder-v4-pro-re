/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08ad28. Types and names are inferred; NOT original source. */

int FUN_0e08ad28(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *local_14;
  
  iVar1 = ram_candidate_23020cfc(param_1,0,&local_14);
  if (-1 < iVar1) {
    if ((char)local_14[1] != '\0') {
      uVar2 = 0;
      uVar3 = 0;
      do {
        while( true ) {
          uVar4 = *(uint *)(*local_14 + uVar3 * 4);
          uVar3 = (uVar4 & 0x1ff) >> 5;
          if (uVar3 < 10) {
            iVar1 = *(int *)(&DAT_0e09b06c + uVar3 * 4);
          }
          else {
            iVar1 = 0;
          }
          iVar5 = 1 << (uVar4 & 0x1f);
          if (param_2 != 0) break;
          *(int *)(iVar1 + 0x48) = iVar5;
          uVar2 = uVar2 + 1;
          uVar3 = uVar2 & 0xff;
          if (*(byte *)(local_14 + 1) <= uVar3) goto LAB_0e08ad84;
        }
        *(int *)(iVar1 + 0x44) = iVar5;
        uVar2 = uVar2 + 1;
        uVar3 = uVar2 & 0xff;
      } while (uVar3 < *(byte *)(local_14 + 1));
    }
LAB_0e08ad84:
    iVar1 = 0;
  }
  return iVar1;
}


