/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23028130. Types and names are inferred; NOT original source. */

void ram_candidate_23028130(void)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  undefined1 *in_r3;
  uint unaff_r4;
  uint uVar5;
  int unaff_r6;
  undefined1 unaff_r7;
  ushort *unaff_r8;
  uint unaff_r9;
  int unaff_r10;
  int iVar6;
  
code_r0x23028130:
  *in_r3 = 0;
  in_r3[2] = 1;
joined_r0x2302813c:
  do {
    unaff_r4 = unaff_r4 + 1;
    if (unaff_r4 == 6) {
      return;
    }
    while( true ) {
      pbVar4 = (byte *)(unaff_r4 * 5 + unaff_r6);
      uVar5 = (int)(uint)*unaff_r8 >> (unaff_r4 & 0xff) & 1;
      if ((int)((uint)*(byte *)(unaff_r6 + unaff_r4 * 5) << 0x1e) < 0) {
        if (pbVar4[2] != 0) {
          if (pbVar4[1] == uVar5) {
            if (unaff_r9 <= pbVar4[3]) {
              *pbVar4 = *pbVar4 & 0xfd;
            }
          }
          else {
            pbVar4[3] = 0;
          }
          goto joined_r0x2302813c;
        }
        *pbVar4 = *pbVar4 & 0xfd;
      }
      if (uVar5 != 0) {
        in_r3 = (undefined1 *)(unaff_r6 + unaff_r4 * 5);
        if (in_r3[1] == '\0') {
          in_r3[2] = 0;
        }
        else {
          bVar3 = *(byte *)(unaff_r6 + unaff_r4 * 5);
          bVar2 = bVar3 & 1;
          if ((bVar3 & 1) != 0) goto code_r0x23028130;
          iVar1 = unaff_r4 * 5;
          iVar6 = unaff_r6 + iVar1;
          if (in_r3[4] == '\x01') {
            bVar2 = *(byte *)(unaff_r10 + 5);
          }
          if (bVar2 < *(byte *)(iVar6 + 2)) {
            *(undefined1 *)(iVar6 + 1) = 0;
            FUN_23027170(0,unaff_r4);
            *(byte *)(unaff_r6 + iVar1) = *(byte *)(unaff_r6 + iVar1) | 2;
            *(undefined1 *)(iVar6 + 2) = unaff_r7;
            *(undefined1 *)(iVar6 + 4) = 0;
          }
        }
        goto joined_r0x2302813c;
      }
      pbVar4 = (byte *)(unaff_r6 + unaff_r4 * 5);
      bVar3 = pbVar4[1];
      if (bVar3 == 1) {
        pbVar4[2] = 0;
        goto joined_r0x2302813c;
      }
      if ((int)((uint)*(byte *)(unaff_r6 + unaff_r4 * 5) << 0x1f) < 0) break;
      *pbVar4 = *pbVar4 | 1;
      pbVar4[2] = 1;
      if ((pbVar4[4] != 0) || (1 < unaff_r4)) goto joined_r0x2302813c;
      FUN_23027170(1,unaff_r4);
      pbVar4[1] = 1;
      *pbVar4 = *pbVar4 | 2;
      pbVar4[2] = (byte)unaff_r9;
      pbVar4[4] = 0;
      unaff_r4 = unaff_r4 + 1;
    }
    if (pbVar4[4] != 1) {
      bVar3 = 0;
    }
    iVar1 = unaff_r4 * 5;
    iVar6 = unaff_r6 + iVar1;
    if (pbVar4[4] == 1) {
      bVar3 = *(byte *)(unaff_r10 + 3);
    }
    if (bVar3 < *(byte *)(iVar6 + 2)) {
      *(undefined1 *)(iVar6 + 1) = 1;
      FUN_23027170(1,unaff_r4);
      *(byte *)(unaff_r6 + iVar1) = *(byte *)(unaff_r6 + iVar1) | 2;
      *(byte *)(iVar6 + 2) = (byte)unaff_r9;
      *(undefined1 *)(iVar6 + 4) = 0;
    }
  } while( true );
}


