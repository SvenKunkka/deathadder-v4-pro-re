/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08a3c4. Types and names are inferred; NOT original source. */

void FUN_0e08a3c4(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = DAT_0e08a46c;
  if (param_2 == 0) {
    return;
  }
  iVar6 = 0;
  puVar4 = DAT_0e08a468;
  do {
    iVar5 = param_1[1];
    if (iVar5 != 0) {
      iVar7 = *param_1;
      uVar2 = FUN_0e08a1ac(iVar7);
      uVar3 = FUN_0e08a1ac(iVar5 + iVar7 + -1);
      if (uVar2 != uVar3) {
        *(undefined4 *)(DAT_0e08a474 + iVar6 * 0x14) = 0xffffffea;
        return;
      }
      puVar4[-1] = uVar2;
      if (uVar2 == 0xffffffea) {
        return;
      }
      if ((int)(uint)*DAT_0e08a470 <= (int)uVar2) {
        return;
      }
      *(uint *)(iVar1 + 0x98) = uVar2;
      *(uint *)(iVar1 + 0x98) = uVar2;
      *(byte *)(puVar4 + 2) = (byte)puVar4[2] & 0xe0 | (byte)*(undefined4 *)(iVar1 + 0x9c) & 0x1f;
      *(byte *)(puVar4 + 2) =
           (byte)puVar4[2] & 0x1f | (byte)((*(uint *)(iVar1 + 0xa0) >> 1 & 7) << 5);
      *puVar4 = *(uint *)(iVar1 + 0x9c) & 0xffffffe0;
      puVar4[3] = *(uint *)(iVar1 + 0xa0) & 0xffffffe0;
    }
    iVar6 = iVar6 + 1;
    param_1 = param_1 + 3;
    puVar4 = puVar4 + 5;
    if (param_2 <= iVar6) {
      return;
    }
  } while( true );
}


