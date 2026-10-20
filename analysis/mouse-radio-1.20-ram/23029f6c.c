/* Automatically decompiled from Suit2FWData__radio_radio.bin at 23029f6c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_23029f6c(uint *param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar10;
  uint uVar11;
  uint *puVar9;
  
  if (param_2 == 0) {
    return 0;
  }
  puVar8 = param_1;
  do {
    puVar9 = puVar8 + 1;
    uVar5 = *puVar8;
    uVar3 = (uVar5 & 0x7fff) >> 0xb;
    uVar4 = uVar5 & 0x1ff;
    if (8 < uVar3) {
      return -0x16;
    }
    if (uVar4 == 0x1ff) {
      uVar4 = 0xffffffff;
    }
    uVar3 = (uint)(byte)(&DAT_0e09b57c)[uVar3];
    switch(uVar5 >> 0x18) {
    case 0:
      uVar7 = 1;
      *(uint *)(param_3 + 0x604) = uVar4;
      uVar10 = 1;
      uVar5 = 1;
      break;
    case 1:
      uVar7 = 0;
      uVar5 = 0xffffffff;
      uVar10 = 0;
      *(uint *)(param_3 + 0x60c) = uVar4;
      break;
    case 2:
      uVar7 = 1;
      *(uint *)(param_3 + 0x610) = uVar4;
      uVar10 = 1;
      uVar5 = 1;
      break;
    case 3:
    case 6:
      *(uint *)(param_3 + 0x608) = uVar4;
code_r0x23029fd8:
      uVar7 = 0;
      uVar5 = 0xffffffff;
      uVar10 = 0;
      break;
    case 4:
      uVar7 = 0;
      uVar10 = 1;
      uVar5 = 0;
      *(uint *)(param_3 + 0x600) = uVar4;
      break;
    case 5:
      uVar7 = 1;
      uVar5 = 0;
      uVar10 = 1;
      *(uint *)(param_3 + 0x604) = uVar4;
      break;
    default:
      return -0x86;
    case 0xb:
      *(uint *)(param_3 + 0x600) = uVar4;
      if (uVar3 != 0) goto code_r0x23029fd8;
      uVar7 = 0;
      uVar5 = 0xffffffff;
      uVar3 = 8;
      uVar10 = 0;
      break;
    case 0xc:
      *(uint *)(param_3 + 0x604) = uVar4;
      if (uVar3 != 0) goto code_r0x23029fd8;
      uVar7 = 0;
      uVar5 = 0xffffffff;
      uVar3 = 8;
      uVar10 = 0;
      break;
    case 0x16:
      uVar7 = 1;
      *(uint *)(param_3 + 0x560) = uVar4;
      uVar10 = 1;
      uVar5 = *(ushort *)((int)puVar8 + 2) & 1;
      break;
    case 0x17:
      uVar7 = 1;
      *(uint *)(param_3 + 0x564) = uVar4;
      uVar10 = 1;
      uVar5 = *(ushort *)((int)puVar8 + 2) & 1;
      break;
    case 0x18:
      uVar7 = 1;
      *(uint *)(param_3 + 0x568) = uVar4;
      uVar10 = 1;
      uVar5 = *(ushort *)((int)puVar8 + 2) & 1;
      break;
    case 0x19:
      uVar7 = 1;
      *(uint *)(param_3 + 0x56c) = uVar4;
      uVar5 = *(ushort *)((int)puVar8 + 2) & 1;
      uVar10 = uVar7;
    }
    if (uVar4 != 0xffffffff) {
      uVar11 = uVar4 & 0x1f;
      uVar4 = uVar4 >> 5;
      if ((int)(*puVar8 << 0xd) < 0) {
        if (uVar4 < 10) {
          iVar6 = *(int *)(&UNK_0e09b554 + uVar4 * 4);
        }
        else {
          iVar6 = 0;
        }
        iVar2 = thunk_FUN_0e08ac48(3);
        if (iVar2 < 0) {
          return iVar2;
        }
        *(int *)(iVar6 + 0x48) = 1 << uVar11;
      }
      if (uVar5 == 0xffffffff) {
        uVar5 = *puVar8;
        if ((uVar5 & 0x8000) != 0) {
          uVar7 = 1;
          uVar10 = 0;
        }
        if (9 < uVar4) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0x2302a1ba);
          (*pcVar1)();
        }
      }
      else {
        if (uVar5 == 0) {
          if (9 < uVar4) {
            _NMI = 0;
                    /* WARNING: Does not return */
            pcVar1 = (code *)software_udf(0xff,0x2302a1a8);
            (*pcVar1)();
          }
          *(int *)(*(int *)(&UNK_0e09b554 + uVar4 * 4) + 8) = 1 << uVar11;
        }
        else {
          if (9 < uVar4) {
            _Reset = 0;
                    /* WARNING: Does not return */
            pcVar1 = (code *)software_udf(0xff,0x2302a1ae);
            (*pcVar1)();
          }
          *(int *)(*(int *)(&UNK_0e09b554 + uVar4 * 4) + 4) = 1 << uVar11;
        }
        uVar5 = *puVar8;
        if ((uVar5 & 0x8000) != 0) {
          uVar7 = 1;
          uVar10 = 0;
        }
      }
      iVar2 = *(int *)(&UNK_0e09b554 + uVar4 * 4);
      iVar6 = iVar2 + uVar11 * 4;
      *(uint *)(iVar6 + 0x80) =
           *(uint *)(iVar6 + 0x80) & 0xfffcf0f0 | ((uVar5 & 0x7ff) >> 9) << 2 | uVar3 << 8 | uVar10
           | uVar7 << 1;
      *(uint *)(iVar6 + 0x80) = *(uint *)(iVar6 + 0x80) & 0x7fffffff | (*puVar8 >> 0x11) << 0x1f;
      if ((int)(*puVar8 << 0xd) < 0) {
        *(int *)(iVar2 + 0x44) = 1 << uVar11;
        iVar6 = thunk_FUN_0e08acf8(3);
        if (iVar6 < 0) {
          return iVar6;
        }
      }
    }
    puVar8 = puVar9;
    if (puVar9 == param_1 + param_2) {
      return 0;
    }
  } while( true );
}


