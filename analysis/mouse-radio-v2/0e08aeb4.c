/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08aeb4. Types and names are inferred; NOT original source. */

int FUN_0e08aeb4(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *local_14;
  
  iVar2 = FUN_0e0977c0(param_1,0,&local_14);
  iVar1 = DAT_0e08af18;
  if (-1 < iVar2) {
    if ((char)local_14[1] != '\0') {
      uVar3 = 0;
      uVar4 = 0;
      do {
        while( true ) {
          uVar5 = *(uint *)(*local_14 + uVar4 * 4);
          uVar4 = (uVar5 & 0x1ff) >> 5;
          if (uVar4 < 10) {
            iVar2 = *(int *)(iVar1 + uVar4 * 4);
          }
          else {
            iVar2 = 0;
          }
          iVar6 = 1 << (uVar5 & 0x1f);
          if (param_2 != 0) break;
          *(int *)(iVar2 + 0x48) = iVar6;
          uVar3 = uVar3 + 1;
          uVar4 = uVar3 & 0xff;
          if (*(byte *)(local_14 + 1) <= uVar4) goto LAB_0e08af10;
        }
        *(int *)(iVar2 + 0x44) = iVar6;
        uVar3 = uVar3 + 1;
        uVar4 = uVar3 & 0xff;
      } while (uVar4 < *(byte *)(local_14 + 1));
    }
LAB_0e08af10:
    iVar2 = 0;
  }
  return iVar2;
}


