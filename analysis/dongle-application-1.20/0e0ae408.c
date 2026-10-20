/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0ae408. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0ae408(int *param_1,undefined4 param_2,int param_3,byte *param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined4 uStack_24;
  
  iVar6 = param_3;
  uStack_24 = param_4;
  uVar9 = FUN_0e0ae054(param_2);
  uVar8 = (uint)((ulonglong)uVar9 >> 0x20);
  if (param_3 == 0) {
LAB_0e0ae46c:
    if (param_4 != (byte *)0x0) {
      iVar6 = FUN_0e0ae0c0(uVar8);
      if (iVar6 == 0) goto LAB_0e0ae478;
      bVar3 = *param_4;
      iVar6 = *param_1 + (uint)bVar3 * 4;
      *(undefined4 *)(iVar6 + 0x510) = 0;
      *(undefined4 *)(iVar6 + 0x510) = 0;
      iVar6 = (int)uVar9 + 8;
      uVar4 = *(ushort *)(&DAT_2f01137c + iVar6 * 2);
      *(ushort *)(&DAT_2f01137c + iVar6 * 2) = uVar4 & 0x1fdf;
      bVar1 = param_4[1];
      if (bVar1 != 0) {
        iVar5 = *param_1 + (uint)bVar3 * 4;
        bVar2 = param_4[2];
        *(uint *)(iVar5 + 0x510) = *(uint *)(iVar5 + 0x510) & 0xffece00f;
        *(uint *)(iVar5 + 0x510) =
             (uVar8 & 0x1ff) << 4 | (bVar1 & 3) << 0x10 | (bVar2 & 1) << 0x14 |
             *(uint *)(iVar5 + 0x510);
        *(ushort *)(&DAT_2f01137c + iVar6 * 2) = uVar4 & 0x1fdf | (ushort)bVar3 << 0xd | 0x20;
      }
    }
    uVar7 = 0xbad0000;
  }
  else {
    uVar10 = FUN_0e0ae0c0(uVar8);
    if ((((int)uVar10 != 0) || (iVar5 = FUN_0e0ae0d8((int)((ulonglong)uVar10 >> 0x20)), iVar5 == 0))
       && ((iVar5 = (int)uVar9 + 8, (*(ushort *)(&DAT_2f01137c + iVar5 * 2) & 0x1c) == 0 ||
           (*(char *)(param_3 + 1) != '\x01')))) {
      uStack_24 = (byte *)CONCAT13(1,(undefined3)uStack_24);
      FUN_0e0b207a(uVar8,(int)&uStack_24 + 3,param_3 + 1,param_3 + 2,param_3,0,iVar6);
      *(ushort *)(&DAT_2f01137c + iVar5 * 2) = *(ushort *)(&DAT_2f01137c + iVar5 * 2) | 3;
      goto LAB_0e0ae46c;
    }
LAB_0e0ae478:
    uVar7 = 0xbad0004;
  }
  return uVar7;
}


