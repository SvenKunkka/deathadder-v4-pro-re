/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063488. Types and names are inferred; NOT original source. */

int FUN_0e063488(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  undefined1 uVar9;
  code *pcVar10;
  undefined1 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int *piVar20;
  undefined2 local_32;
  uint local_30;
  uint local_2c [2];
  
  piVar20 = *(int **)(param_3 + 0xc);
  iVar16 = *(int *)(param_3 + 4);
  local_30 = 0;
  if (piVar20 != (int *)0x0) {
    iVar13 = 0;
    uVar17 = 0;
LAB_0e0634b0:
    local_2c[0] = 0;
    iVar7 = *(int *)(piVar20[1] + 8);
    uVar18 = uVar17;
    if (*(code **)(iVar7 + 0x30) == (code *)0x0) goto LAB_0e0635ea;
    piVar5 = (int *)(**(code **)(iVar7 + 0x30))(piVar20[1],param_2);
    if (piVar5 != (int *)0x0) {
      piVar20[3] = 0;
      piVar20[4] = 0;
      pcVar8 = (char *)*piVar5;
      if (pcVar8 == (char *)0x0) {
        return -0x16;
      }
LAB_0e0634f8:
      if (*pcVar8 != '\0') {
        cVar2 = (char)uVar18;
        if (pcVar8[1] == '\v') {
          pcVar8[2] = cVar2;
        }
        iVar7 = *piVar5;
        cVar1 = *(char *)(iVar7 + 1);
        if (cVar1 == '\x04') {
          piVar20[3] = piVar20[3] | local_2c[0];
          if (*(char *)(iVar7 + 3) == '\0') {
            *(char *)(iVar7 + 2) = cVar2;
            piVar20[4] = piVar20[4] | 1 << uVar18;
            uVar18 = uVar18 + 1 & 0xff;
          }
          else {
            *(char *)(iVar7 + 2) = cVar2 + -1;
            FUN_0e063418(&local_30,local_2c);
          }
          iVar7 = *piVar5;
          local_2c[0] = 0;
          cVar1 = *(char *)(iVar7 + 1);
        }
        if (cVar1 == '\x05') {
          iVar6 = -0x13;
          uVar14 = 1;
          uVar15 = *(undefined4 *)(param_1 + 0x18);
          do {
            uVar4 = local_2c[0];
            uVar3 = local_30;
            local_32 = *(undefined2 *)(iVar7 + 4);
            cVar2 = (char)uVar14;
            uVar19 = uVar14 & 0xff;
            if (*(char *)(iVar7 + 2) < '\0') {
              uVar19 = uVar19 | 0x80;
              uVar12 = (uVar14 & 0x7f) + 0x10;
              if (-1 < (int)((local_30 >> uVar12) << 0x1f)) {
                cVar2 = (char)uVar19;
LAB_0e063568:
                if ((-1 < (int)((local_2c[0] >> (uVar12 & 0xff)) << 0x1f)) &&
                   (iVar6 = FUN_0e0647cc(uVar15,uVar19,*(undefined1 *)(iVar7 + 3),&local_32,
                                         *(undefined1 *)(iVar7 + 6)), iVar6 == 0))
                goto LAB_0e06365c;
              }
            }
            else {
              uVar12 = uVar14;
              if (-1 < (int)((local_30 >> (uVar14 & 0xff)) << 0x1f)) goto LAB_0e063568;
            }
            uVar14 = uVar14 + 1;
            if (uVar14 == 0x10) {
              return iVar6;
            }
          } while( true );
        }
        goto LAB_0e0634f0;
      }
      goto LAB_0e0635ce;
    }
    pcVar10 = *(code **)(*(int *)(piVar20[1] + 8) + 0x28);
    goto joined_r0x0e06368e;
  }
  uVar11 = 9;
  uVar9 = 0;
  uVar17 = 0;
LAB_0e06361a:
  *(undefined1 *)(iVar16 + 2) = uVar11;
  *(undefined1 *)(iVar16 + 3) = uVar9;
  *(char *)(iVar16 + 4) = (char)uVar17;
  piVar20 = *(int **)(param_3 + 0xc);
  while( true ) {
    if (piVar20 == (int *)0x0) {
      return 0;
    }
    piVar20[2] = piVar20[3];
    iVar16 = FUN_0e063418(&local_30,piVar20 + 3);
    if (iVar16 != 0) break;
    piVar20 = (int *)*piVar20;
  }
  return iVar16;
LAB_0e06365c:
  *(char *)(iVar7 + 2) = (char)uVar19;
  *(undefined2 *)(iVar7 + 4) = local_32;
  if (cVar2 < '\0') {
    uVar19 = (uVar19 & 0xffffff7f) + 0x10;
  }
  local_2c[0] = uVar4 | 1 << uVar19;
  local_30 = uVar3 | 1 << uVar19;
LAB_0e0634f0:
  piVar5 = piVar5 + 1;
  pcVar8 = (char *)*piVar5;
  if (pcVar8 == (char *)0x0) goto LAB_0e0635ce;
  goto LAB_0e0634f8;
LAB_0e0635ce:
  if (uVar18 <= uVar17) {
    return -0x16;
  }
  piVar20[3] = piVar20[3] | local_2c[0];
  iVar7 = *(int *)(piVar20[1] + 8);
LAB_0e0635ea:
  pcVar10 = *(code **)(iVar7 + 0x28);
  uVar17 = uVar18;
joined_r0x0e06368e:
  if (pcVar10 == (code *)0x0) {
    return -0x86;
  }
  iVar7 = (*pcVar10)();
  if (iVar7 != 0) {
    return iVar7;
  }
  iVar7 = FUN_0e063a18(piVar20[1],param_2);
  piVar20 = (int *)*piVar20;
  iVar13 = iVar13 + iVar7;
  if (piVar20 == (int *)0x0) goto code_r0x0e06360c;
  goto LAB_0e0634b0;
code_r0x0e06360c:
  uVar11 = (undefined1)(iVar13 + 9);
  uVar9 = (undefined1)((uint)(iVar13 + 9) >> 8);
  goto LAB_0e06361a;
}


