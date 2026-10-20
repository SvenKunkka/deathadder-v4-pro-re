/* PRIVATE LOCAL ANALYSIS — official firmware v1.20.00_r1.
 * Automatically decompiled; NOT original source and NOT a buildable firmware project.
 * Includes OS/library/diagnostic functions alongside wireless functions.
 * Original LMA copied code is mapped at its verified RAM execution address.
 * Unknown types, callbacks, and decompiler warnings are retained, not silently repaired.
 */

/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ba10. Types and names are inferred; NOT original source. */

undefined8 FUN_0e05ba10(int param_1,int param_2,int param_3,int param_4)

{
  undefined8 uVar1;
  
  if ((param_4 == 0) && (param_3 == 0)) {
    if (param_2 != 0 || param_1 != 0) {
      param_2 = -1;
      param_1 = -1;
    }
    return CONCAT44(param_2,param_1);
  }
  uVar1 = FUN_0e05ba78();
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ba44. Types and names are inferred; NOT original source. */

int FUN_0e05ba44(byte *param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  
  do {
    uVar2 = (uint)*param_1;
    bVar1 = *param_2;
    bVar3 = uVar2 == 1;
    if (uVar2 != 0) {
      bVar3 = uVar2 == bVar1;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (bVar3);
  return uVar2 - bVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ba58. Types and names are inferred; NOT original source. */

void FUN_0e05ba58(char *param_1,char *param_2)

{
  char cVar1;
  
  do {
    cVar1 = *param_2;
    *param_1 = cVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ba68. Types and names are inferred; NOT original source. */

char * FUN_0e05ba68(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = param_1;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return pcVar2 + (-1 - (int)param_1);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ba78. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e05bcde) */

undefined8 FUN_0e05ba78(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  if (param_4 == 0) {
    iVar3 = LZCOUNT(param_3);
    if (param_2 < param_3) {
      uVar6 = param_1;
      if (iVar3 != 0) {
        param_3 = param_3 << iVar3;
        uVar6 = param_1 << iVar3;
        param_2 = param_1 >> (0x20U - iVar3 & 0xff) | param_2 << iVar3;
      }
      uVar11 = param_3 >> 0x10;
      uVar7 = param_2 / uVar11;
      uVar8 = uVar7 * (param_3 & 0xffff);
      uVar4 = uVar6 >> 0x10 | (param_2 - uVar11 * uVar7) * 0x10000;
      uVar5 = uVar7;
      if (uVar4 <= uVar8 && uVar8 - uVar4 != 0) {
        bVar13 = CARRY4(param_3,uVar4);
        uVar4 = param_3 + uVar4;
        uVar5 = uVar7 - 1;
        if ((!bVar13) && (uVar4 <= uVar8 && uVar8 - uVar4 != 0)) {
          uVar4 = uVar4 + param_3;
          uVar5 = uVar7 - 2;
        }
      }
      uVar9 = (uVar4 - uVar8) / uVar11;
      uVar2 = uVar9 * (param_3 & 0xffff);
      uVar7 = uVar6 & 0xffff | ((uVar4 - uVar8) - uVar11 * uVar9) * 0x10000;
      uVar4 = uVar9;
      if (uVar7 <= uVar2 && uVar2 - uVar7 != 0) {
        bVar13 = CARRY4(param_3,uVar7);
        uVar7 = param_3 + uVar7;
        uVar4 = uVar9 - 1;
        if ((!bVar13) && (uVar7 <= uVar2 && uVar2 - uVar7 != 0)) {
          uVar7 = uVar7 + param_3;
          uVar4 = uVar9 - 2;
        }
      }
      uVar7 = uVar7 - uVar2;
      uVar4 = uVar4 | uVar5 << 0x10;
      uVar6 = 0;
    }
    else {
      if (iVar3 == 0) {
        param_2 = param_2 - param_3;
        uVar6 = 1;
        uVar7 = param_1;
      }
      else {
        param_3 = param_3 << iVar3;
        uVar7 = param_1 << iVar3;
        uVar6 = param_2 >> (0x20U - iVar3 & 0xff);
        uVar2 = param_3 >> 0x10;
        uVar5 = param_1 >> (0x20U - iVar3 & 0xff) | param_2 << iVar3;
        uVar11 = uVar6 / uVar2;
        uVar8 = uVar11 * (param_3 & 0xffff);
        uVar6 = uVar5 >> 0x10 | (uVar6 - uVar2 * uVar11) * 0x10000;
        uVar4 = uVar11;
        if (uVar6 <= uVar8 && uVar8 - uVar6 != 0) {
          bVar13 = CARRY4(param_3,uVar6);
          uVar6 = param_3 + uVar6;
          uVar4 = uVar11 - 1;
          if ((!bVar13) && (uVar6 <= uVar8 && uVar8 - uVar6 != 0)) {
            uVar6 = uVar6 + param_3;
            uVar4 = uVar11 - 2;
          }
        }
        uVar9 = (uVar6 - uVar8) / uVar2;
        uVar11 = uVar9 * (param_3 & 0xffff);
        param_2 = uVar5 & 0xffff | ((uVar6 - uVar8) - uVar2 * uVar9) * 0x10000;
        uVar6 = uVar9;
        if (param_2 <= uVar11 && uVar11 - param_2 != 0) {
          bVar13 = CARRY4(param_3,param_2);
          param_2 = param_3 + param_2;
          uVar6 = uVar9 - 1;
          if ((!bVar13) && (param_2 <= uVar11 && uVar11 - param_2 != 0)) {
            param_2 = param_2 + param_3;
            uVar6 = uVar9 - 2;
          }
        }
        param_2 = param_2 - uVar11;
        uVar6 = uVar6 | uVar4 << 0x10;
      }
      uVar2 = param_3 >> 0x10;
      uVar11 = param_2 / uVar2;
      uVar8 = uVar11 * (param_3 & 0xffff);
      uVar4 = uVar7 >> 0x10 | (param_2 - uVar2 * uVar11) * 0x10000;
      uVar5 = uVar11;
      if (uVar4 <= uVar8 && uVar8 - uVar4 != 0) {
        bVar13 = CARRY4(param_3,uVar4);
        uVar4 = param_3 + uVar4;
        uVar5 = uVar11 - 1;
        if ((!bVar13) && (uVar4 <= uVar8 && uVar8 - uVar4 != 0)) {
          uVar4 = uVar4 + param_3;
          uVar5 = uVar11 - 2;
        }
      }
      uVar9 = (uVar4 - uVar8) / uVar2;
      uVar11 = uVar9 * (param_3 & 0xffff);
      uVar7 = uVar7 & 0xffff | ((uVar4 - uVar8) - uVar2 * uVar9) * 0x10000;
      uVar4 = uVar9;
      if (uVar7 <= uVar11 && uVar11 - uVar7 != 0) {
        bVar13 = CARRY4(param_3,uVar7);
        uVar7 = param_3 + uVar7;
        uVar4 = uVar9 - 1;
        if ((!bVar13) && (uVar7 <= uVar11 && uVar11 - uVar7 != 0)) {
          uVar7 = uVar7 + param_3;
          uVar4 = uVar9 - 2;
        }
      }
      uVar7 = uVar7 - uVar11;
      uVar4 = uVar4 | uVar5 << 0x10;
    }
    if (param_5 != (uint *)0x0) {
      *param_5 = uVar7 >> iVar3;
      param_5[1] = 0;
    }
  }
  else if (param_2 < param_4) {
    if (param_5 != (uint *)0x0) {
      *param_5 = param_1;
      param_5[1] = param_2;
    }
    uVar4 = 0;
    uVar6 = uVar4;
  }
  else {
    iVar3 = LZCOUNT(param_4);
    if (iVar3 == 0) {
      if ((param_4 < param_2) || (param_3 <= param_1)) {
        bVar13 = param_1 < param_3;
        param_1 = param_1 - param_3;
        param_2 = (param_2 - param_4) - (uint)bVar13;
        uVar4 = 1;
      }
      else {
        uVar4 = 0;
      }
      if (param_5 != (uint *)0x0) {
        *param_5 = param_1;
        param_5[1] = param_2;
      }
    }
    else {
      uVar10 = 0x20 - iVar3;
      uVar8 = param_1 << iVar3;
      uVar5 = param_3 >> (uVar10 & 0xff) | param_4 << iVar3;
      uVar6 = param_2 >> (uVar10 & 0xff);
      uVar2 = uVar5 >> 0x10;
      uVar4 = param_1 >> (uVar10 & 0xff) | param_2 << iVar3;
      uVar11 = uVar6 / uVar2;
      uVar9 = uVar11 * (uVar5 & 0xffff);
      uVar7 = uVar4 >> 0x10 | (uVar6 - uVar2 * uVar11) * 0x10000;
      uVar6 = uVar11;
      if (uVar7 <= uVar9 && uVar9 - uVar7 != 0) {
        bVar13 = CARRY4(uVar5,uVar7);
        uVar7 = uVar5 + uVar7;
        uVar6 = uVar11 - 1;
        if ((!bVar13) && (uVar7 <= uVar9 && uVar9 - uVar7 != 0)) {
          uVar7 = uVar7 + uVar5;
          uVar6 = uVar11 - 2;
        }
      }
      uVar11 = (uVar7 - uVar9) / uVar2;
      uVar12 = uVar11 * (uVar5 & 0xffff);
      uVar7 = uVar4 & 0xffff | ((uVar7 - uVar9) - uVar2 * uVar11) * 0x10000;
      uVar4 = uVar11;
      if (uVar7 <= uVar12 && uVar12 - uVar7 != 0) {
        bVar13 = CARRY4(uVar5,uVar7);
        uVar7 = uVar5 + uVar7;
        uVar4 = uVar11 - 1;
        if ((!bVar13) && (uVar7 <= uVar12 && uVar12 - uVar7 != 0)) {
          uVar7 = uVar7 + uVar5;
          uVar4 = uVar11 - 2;
        }
      }
      uVar4 = uVar4 | uVar6 << 0x10;
      uVar1 = (ulonglong)uVar4 * (ulonglong)(param_3 << iVar3);
      if (CONCAT44(uVar7 - uVar12,uVar8) < uVar1) {
        uVar4 = uVar4 - 1;
        uVar1 = uVar1 - CONCAT44(uVar5,param_3 << iVar3);
      }
      if (param_5 != (uint *)0x0) {
        uVar6 = ((uVar7 - uVar12) - (int)(uVar1 >> 0x20)) - (uint)(uVar8 < (uint)uVar1);
        *param_5 = uVar6 << (uVar10 & 0xff) | uVar8 - (uint)uVar1 >> iVar3;
        param_5[1] = uVar6 >> iVar3;
      }
    }
    uVar6 = 0;
  }
  return CONCAT44(uVar6,uVar4);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05bd18. Types and names are inferred; NOT original source. */

undefined * FUN_0e05bd18(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0e0624a4(&DAT_23001d0c,&DAT_2300037c);
  if ((((iVar1 == 0) && (iVar1 = FUN_0e0624a4(&DAT_23001d0c,&DAT_2300035c), iVar1 == 0)) &&
      (iVar1 = FUN_0e0624a4(&DAT_23001d0c,&DAT_23000324), iVar1 == 0)) &&
     (iVar1 = FUN_0e0624a4(&DAT_23001d0c,&DAT_23000310), iVar1 == 0)) {
    iVar1 = FUN_0e062250(&DAT_23001d0c);
    if (iVar1 == 1) {
      iVar1 = FUN_0e06384c(&DAT_23001d0c,1,&DAT_23000268);
      if (iVar1 != 0) {
        return (undefined *)0x0;
      }
      iVar1 = FUN_0e063bac(&DAT_23001d0c,1,1);
      if (iVar1 != 0) {
        return (undefined *)0x0;
      }
      FUN_0e062260(&DAT_23001d0c,1,0,0,0);
    }
    iVar1 = FUN_0e06384c(&DAT_23001d0c,0,&DAT_23000288);
    if ((((iVar1 == 0) && (iVar1 = FUN_0e063bac(&DAT_23001d0c,0,1), iVar1 == 0)) &&
        ((FUN_0e062260(&DAT_23001d0c,0,0,0,0), param_1 == 0 ||
         (iVar1 = FUN_0e064024(&DAT_23001d0c,param_1), iVar1 == 0)))) &&
       (iVar1 = FUN_0e062338(&DAT_23001d0c), iVar1 == 0)) {
      return &DAT_23001d0c;
    }
  }
  return (undefined *)0x0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05bde0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e05bde0(void)

{
  undefined8 uVar1;
  
  _DAT_53014600 = 0x6e524635;
  uVar1 = FUN_0e0684dc(100000,0);
  FUN_0e068454(DAT_23002df8,0,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0xe05bde1,0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05be20. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e05be20(void)

{
  DAT_23002df8 = FUN_0e06841c();
  _DAT_53014504 = 0x10000;
  _DAT_53014508 = 1;
  _DAT_5301450c = 0;
  _DAT_53014000 = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05be4c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e05be4c(void)

{
  undefined8 uVar1;
  
  _DAT_53014600 = 0x6e524635;
  uVar1 = FUN_0e0684dc(100000,0);
  FUN_0e068454(DAT_23002df8,0,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0xe05bde1,0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c0e8. Types and names are inferred; NOT original source. */

void FUN_0e05c0e8(void)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined4 in_r3;
  
  bVar1 = DAT_230071cb;
  uVar2 = DAT_230071cd;
  if (DAT_230071de != '\0') {
    FUN_0e05d028();
    bVar1 = DAT_230071cb;
    uVar2 = DAT_230071cd;
  }
  DAT_230065f2._2_1_ = uVar2;
  DAT_23006600 = bVar1;
  DAT_230071de = 0;
  if (DAT_230071cf == '\x01') {
    DAT_23006601 = 4;
    DAT_23006618 = 2;
  }
  else if (DAT_230071cf == '\x02') {
    DAT_23006601 = 9;
    DAT_23006618 = 4;
  }
  else if (DAT_230071cf == '\0') {
    DAT_23006601 = 3;
    DAT_23006618 = 1;
  }
  if (DAT_230071ce < 0x11) {
    DAT_23006602 = (&DAT_0e06fbe8)[DAT_230071ce];
  }
  else {
    DAT_23006602 = 4;
  }
  DAT_23006610 = (uint)DAT_230071cc;
  uVar3 = (uint)DAT_230071ca;
  if (uVar3 < 2) {
    DAT_230071ca = 1;
    DAT_2300660c = 0x32;
  }
  else if (uVar3 < 99) {
    DAT_2300660c = 100 / (uVar3 + 1);
  }
  else {
    DAT_230071ca = 99;
    DAT_2300660c = 1;
  }
  DAT_230065f2._3_1_ = 0;
  DAT_230065ee._0_2_ = 0;
  DAT_230065f6._0_2_ = 0;
  DAT_230065fa._2_2_ = 0;
  DAT_230065fe = 0;
  DAT_230065e8 = 2;
  DAT_230065f6._2_2_ = 0xc0d5;
  DAT_230065fa._0_2_ = 0xe05;
  DAT_230065ea = (uint)DAT_23006600 << 0x10;
  DAT_23006614 = (uint)DAT_230071ac;
  DAT_230065ee._2_2_ = (ushort)DAT_230071cc;
  DAT_230065f2._0_2_ = 0;
  DAT_230065e9 = DAT_23006601;
  DAT_23006603 = DAT_230065f2._2_1_;
  DAT_230071cb = DAT_23006600;
  DAT_230071cd = DAT_230065f2._2_1_;
  FUN_0e05cd78(&DAT_230065e8,DAT_23006610,DAT_23006614,in_r3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c200. Types and names are inferred; NOT original source. */

void FUN_0e05c200(void)

{
  DAT_230071c9 = 0;
  DAT_230071c8 = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c214. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e05c214(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  
  if (param_2 == 0) {
    if (param_1 != 0) goto LAB_0e05c226;
LAB_0e05c282:
    switch(DAT_230071c9) {
    case 1:
s_6N3x_0e05c3f5_1:
      if (DAT_230071de != '\0') {
        FUN_0e05d028();
        DAT_230071de = '\0';
      }
      DAT_230065e8 = 0;
      DAT_230065ee._0_1_ = 0;
      DAT_230065ee._2_2_ = 0;
      DAT_230065f2._0_2_ = 0;
      DAT_230065f2._2_1_ = 0;
      DAT_230065ea._2_1_ = (undefined1)_DAT_23006602;
      DAT_230065ea._3_1_ = (undefined1)((uint)_DAT_23006602 >> 8);
      break;
    case 2:
s_DN3x_0e05c3bb_1:
      if (DAT_230071de != '\0') {
        FUN_0e05d028();
        DAT_230071de = '\0';
      }
      DAT_230065ea._3_1_ = DAT_23006600;
      DAT_230065e8 = 1;
      DAT_230065f2._2_1_ = 0;
      DAT_230065ea._2_1_ = DAT_23006602;
      DAT_230065ee._0_1_ = DAT_23006603;
      DAT_230065ee._2_2_ = (undefined2)DAT_23006614;
      DAT_230065f2._0_2_ = (undefined2)((uint)DAT_23006614 >> 0x10);
      break;
    case 3:
LAB_0e05c388:
      DAT_230065e8 = 5;
      DAT_230065ee._1_1_ = 0;
      DAT_230065ea._2_1_ = DAT_23006602;
      DAT_230065ea._3_1_ = DAT_23006600;
      DAT_230065ee._0_1_ = DAT_23006603;
      DAT_230065f2._2_1_ = (undefined1)DAT_23006614;
      DAT_230065f2._3_1_ = (undefined1)((uint)DAT_23006614 >> 8);
      DAT_230065f6._0_2_ = (undefined2)((uint)DAT_23006614 >> 0x10);
      DAT_230065ee._2_2_ = (undefined2)DAT_2300660c;
      DAT_230065f2._0_2_ = (undefined2)(DAT_2300660c >> 0x10);
      goto LAB_0e05c370;
    case 4:
LAB_0e05c44e:
      DAT_230065e8 = 3;
      DAT_230065f2._2_1_ = 0;
      DAT_230065f2._3_1_ = 0;
      DAT_230065f6._0_2_ = 0;
      DAT_230065ee._2_2_ = (undefined2)DAT_23006608;
      DAT_230065f2._0_2_ = (undefined2)(DAT_23006608 >> 0x10);
      DAT_230065ea._2_1_ = (undefined1)_DAT_23006602;
      DAT_230065ea._3_1_ = (undefined1)((uint)_DAT_23006602 >> 8);
      DAT_230065ee._0_1_ = (undefined1)((uint)_DAT_23006602 >> 0x10);
      DAT_230065ee._1_1_ = (undefined1)((uint)_DAT_23006602 >> 0x18);
LAB_0e05c370:
      DAT_230065fa._2_2_ = 0;
      DAT_230065fa._0_2_ = 0;
      DAT_230065f6._2_2_ = 0;
      DAT_230065ea._0_2_ = 0;
      DAT_230065fe = 0;
      DAT_230065e9 = DAT_23006601;
      FUN_0e05cd78();
      DAT_230071c8 = DAT_230071c9;
      DAT_230071c9 = 0;
      DAT_230071de = 1;
      return 0;
    case 5:
      goto LAB_0e05c23c;
    case 6:
      uVar1 = _DAT_23006603;
LAB_0e05c348:
      DAT_230065ee._1_1_ = 0;
      DAT_230065f2._2_1_ = 0;
      DAT_230065f2._3_1_ = 0;
      DAT_230065ee._2_2_ = (undefined2)DAT_23006608;
      DAT_230065f2._0_2_ = (undefined2)(DAT_23006608 >> 0x10);
      DAT_230065e8 = 4;
      DAT_230065ea._2_1_ = (undefined1)uVar1;
      DAT_230065ea._3_1_ = (undefined1)((ushort)uVar1 >> 8);
      DAT_230065f6._0_2_ = 0;
      DAT_230065ee._0_1_ = DAT_23006604._1_1_;
      goto LAB_0e05c370;
    default:
      goto switchD_0e05c28c_default;
    }
  }
  else {
    DAT_230071c9 = 0;
    DAT_230071c8 = 0;
    if (param_1 == 0) {
      DAT_230071c8 = 0;
      DAT_230071c9 = 0;
      return 0;
    }
LAB_0e05c226:
    switch(DAT_230071db) {
    case 1:
    case 3:
      iVar3 = 1;
      DAT_23006600 = 0;
      if (DAT_230071d9 != '\x01') goto LAB_0e05c2b8;
      goto LAB_0e05c336;
    case 2:
    case 4:
      iVar3 = 2;
      DAT_23006600 = 0;
      break;
    default:
      iVar3 = 0;
    }
    if (DAT_230071d9 == '\x01') {
LAB_0e05c336:
      DAT_23006601 = 4;
      DAT_23006618 = 2;
    }
    else {
LAB_0e05c2b8:
      if (DAT_230071d9 == '\x02') {
        DAT_23006601 = 9;
        DAT_23006618 = 4;
      }
      else if (DAT_230071d9 == '\0') {
        DAT_23006601 = 3;
        DAT_23006618 = 1;
      }
    }
    if (DAT_230071d4 < 0x11) {
      uVar5 = (&DAT_0e06fbe8)[DAT_230071d4];
    }
    else {
      uVar5 = 4;
    }
    _DAT_23006602 = CONCAT31(_DAT_23006603,uVar5);
    if (DAT_230071db < 6) {
      _DAT_23006602 = CONCAT13(2,_DAT_23006602);
    }
    uVar2 = _DAT_23006602;
    uVar4 = (uint)DAT_230071d2;
    DAT_23006608 = (uint)DAT_230071d7;
    DAT_23006610 = (uint)DAT_230071d3;
    if (DAT_23006608 < 10) {
      DAT_23006608 = 10;
    }
    DAT_2300660c = uVar4;
    if (99 < uVar4) {
      DAT_2300660c = 100;
    }
    DAT_23006604._1_1_ = SUB41(uVar2,3);
    _DAT_23006602 = CONCAT12(DAT_230071d5,CONCAT11(DAT_230071d6,DAT_23006602));
    if (iVar3 == 1) {
      if (DAT_230071d8 != '\0') {
        DAT_230071c9 = 4;
        DAT_23006614 = 0;
        goto LAB_0e05c44e;
      }
      if (DAT_230071da != '\0') {
        if (uVar4 != 0) {
          DAT_230071c9 = 3;
          DAT_23006614 = 0;
          goto LAB_0e05c388;
        }
        DAT_230071c9 = 2;
        DAT_23006614 = 0;
        goto s_DN3x_0e05c3bb_1;
      }
      DAT_230071c9 = 1;
      DAT_23006614 = 0;
      goto s_6N3x_0e05c3f5_1;
    }
    if (iVar3 != 2) goto LAB_0e05c282;
    if (DAT_230071d8 != '\0') {
      DAT_230071c9 = 6;
      uVar1 = CONCAT11(DAT_230071d5,DAT_230071d6);
      goto LAB_0e05c348;
    }
    DAT_230071c9 = 5;
LAB_0e05c23c:
    if (DAT_230071de != '\0') {
      FUN_0e05d028();
      DAT_230071de = '\0';
    }
    DAT_230065e8 = 2;
    DAT_230065ea._3_1_ = 0;
    DAT_230065f2._0_2_ = 0;
    DAT_230065ee._0_1_ = 0;
    DAT_230065ee._2_2_ = 0;
    DAT_230065f2._2_1_ = DAT_23006603;
    DAT_230065ea._2_1_ = DAT_23006600;
  }
  DAT_230065fe = 0;
  DAT_230065fa._2_2_ = 0;
  DAT_230065fa._0_2_ = 0;
  DAT_230065f6._2_2_ = 0;
  DAT_230065f6._0_2_ = 0;
  DAT_230065f2._3_1_ = 0;
  DAT_230065ee._1_1_ = 0;
  DAT_230065ea._0_2_ = 0;
  DAT_230065e9 = DAT_23006601;
  FUN_0e05cd78();
  DAT_230071c8 = DAT_230071c9;
  DAT_230071c9 = 0;
switchD_0e05c28c_default:
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c504. Types and names are inferred; NOT original source. */

void FUN_0e05c504(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  DAT_230071da = param_1[1];
  DAT_230071d9 = param_1[2];
  DAT_230071d8 = param_1[3];
  DAT_230071d7 = param_1[4];
  DAT_230071d6 = param_1[5];
  DAT_230071d5 = param_1[6];
  DAT_230071d4 = param_1[7];
  DAT_230071d3 = param_1[8];
  DAT_230071d2 = param_1[9];
  DAT_230071db = cVar1;
  if (cVar1 == '\0') {
    DAT_230071dd = 0;
    if (DAT_230071c7 != '\0') {
      DAT_230071dd = cVar1;
      ram_candidate_23021db0();
      FUN_0e05d230();
      DAT_230071c7 = cVar1;
      return;
    }
  }
  else {
    if ((DAT_230071dd == '\0') && (DAT_230071c7 == '\0')) {
      ram_candidate_23021d9c();
      FUN_0e05d1ac(&DAT_230065e8);
      DAT_230071c7 = '\x01';
    }
    DAT_230071dd = 1;
    DAT_230071dc = 1;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c5ec. Types and names are inferred; NOT original source. */

void FUN_0e05c5ec(undefined1 *param_1)

{
  char cVar1;
  
  cVar1 = DAT_230071d1;
  if (DAT_230071d1 == '\0') {
    if (DAT_230071dd == '\x01') {
      if (DAT_230071c7 == '\0') {
        DAT_230071dd = DAT_230071c7;
      }
      else {
        ram_candidate_23021db0();
        FUN_0e05d230();
        DAT_230071c7 = cVar1;
        DAT_230071dd = cVar1;
      }
    }
    else if (DAT_230071c7 != '\0') goto LAB_0e05c61a;
  }
  else if (DAT_230071c7 != '\0') {
    ram_candidate_23021db0();
    FUN_0e05d230();
    DAT_230071c7 = '\0';
  }
  ram_candidate_23021d9c();
  FUN_0e05d1ac(&DAT_230065e8);
  DAT_230071c7 = '\x01';
LAB_0e05c61a:
  DAT_230071d1 = 1;
  DAT_230071cf = *param_1;
  DAT_230071ce = param_1[1];
  DAT_230071cd = param_1[2];
  DAT_230071cc = param_1[3];
  DAT_230071cb = param_1[4];
  DAT_230071ca = param_1[5];
  DAT_230071ac = *(ushort *)(param_1 + 6) << 8 | *(ushort *)(param_1 + 6) >> 8;
  DAT_230071aa = *(ushort *)(param_1 + 8) << 8 | *(ushort *)(param_1 + 8) >> 8;
  DAT_230071a8 = *(ushort *)(param_1 + 10) << 8 | *(ushort *)(param_1 + 10) >> 8;
  DAT_230071a6 = *(ushort *)(param_1 + 0xc) << 8 | *(ushort *)(param_1 + 0xc) >> 8;
  DAT_230071d0 = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c6d4. Types and names are inferred; NOT original source. */

void FUN_0e05c6d4(undefined1 *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined1 uVar5;
  
  *param_1 = DAT_230071cf;
  param_1[1] = DAT_230071ce;
  param_1[2] = DAT_230071cd;
  uVar4 = DAT_230071ac;
  uVar3 = DAT_230071aa;
  param_1[3] = DAT_230071cc;
  uVar2 = DAT_230071a8;
  uVar1 = DAT_230071a6;
  param_1[4] = DAT_230071cb;
  param_1[7] = (char)uVar4;
  uVar5 = DAT_230071ca;
  param_1[9] = (char)uVar3;
  param_1[6] = (char)((ushort)uVar4 >> 8);
  param_1[8] = (char)((ushort)uVar3 >> 8);
  param_1[5] = uVar5;
  param_1[10] = (char)((ushort)uVar2 >> 8);
  param_1[0xb] = (char)uVar2;
  param_1[0xc] = (char)((ushort)uVar1 >> 8);
  param_1[0xd] = (char)uVar1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c7f4. Types and names are inferred; NOT original source. */

void FUN_0e05c7f4(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = DAT_23006620 & 0xfffeffff;
  iVar1 = DAT_23006620 << 0xf;
  DAT_23006620 = uVar2;
  if (iVar1 < 0) {
    FUN_0e06a708(DAT_230071df,&TIMER021_S_TASKS_START);
  }
  uVar2 = DAT_23006620 & 0xfffffffb;
  iVar1 = DAT_23006620 << 0x1d;
  DAT_23006620 = uVar2;
  if (iVar1 < 0) {
    FUN_0e06a8e0(DAT_230071df,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_TXEN);
  }
  uVar2 = DAT_23006620 & 0xffffffef;
  iVar1 = DAT_23006620 << 0x1b;
  DAT_23006620 = uVar2;
  if (iVar1 < 0) {
    FUN_0e06a8e0(DAT_230071df,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_RXEN);
  }
  uVar2 = DAT_23006620;
  DAT_23006620 = DAT_23006620 & 0xfffffeff;
  if ((int)(uVar2 << 0x17) < 0) {
    FUN_0e06a8e0(DAT_230071df,&TIMER021_S_EVENTS_COMPARE_0,&RADIO_S_TASKS_TXEN);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c8fc. Types and names are inferred; NOT original source. */

void FUN_0e05c8fc(undefined4 param_1)

{
  dword dVar1;
  
  switch(param_1) {
  case 1:
    dVar1 = 0xf;
    break;
  case 2:
    dVar1 = 0x16;
    break;
  case 3:
    dVar1 = 0x17;
    break;
  case 4:
    dVar1 = 0x18;
    break;
  case 5:
    dVar1 = 0x19;
    break;
  case 6:
    dVar1 = 0x1a;
    break;
  case 7:
    dVar1 = 0x1b;
    break;
  case 8:
    dVar1 = 0x1c;
    break;
  case 9:
    dVar1 = 0x1d;
    break;
  case 10:
    dVar1 = 0x1f;
    break;
  case 0xffffffba:
    dVar1 = 0;
    break;
  default:
    FUN_0e05d634("TX power to enumerator conversion failed, defaulting to 0 dBm\n");
  case 0:
    dVar1 = 0xe;
    break;
  case 0xffffffd8:
    dVar1 = 1;
    break;
  case 0xffffffe2:
    dVar1 = 2;
    break;
  case 0xffffffec:
    dVar1 = 3;
    break;
  case 0xfffffff0:
    dVar1 = 8;
    break;
  case 0xfffffff4:
    dVar1 = 9;
    break;
  case 0xfffffff8:
    dVar1 = 10;
    break;
  case 0xfffffffc:
    dVar1 = 0xb;
    break;
  case 0xfffffffe:
    dVar1 = 0xc;
    break;
  case 0xffffffff:
    dVar1 = 0xd;
  }
  RADIO_S_TXPOWER = dVar1;
  if (DAT_230071e0 != '\0') {
    return;
  }
  FUN_0e05d634("Requested tx output power: %hhi dBm\n",param_1);
  FUN_0e05d634("Tx output power set to: %hhi dBm\n",param_1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05c9ec. Types and names are inferred; NOT original source. */

void FUN_0e05c9ec(uint param_1,int param_2,uint param_3)

{
  short sVar1;
  dword dVar2;
  dword dVar3;
  
  RADIO_S_TIMING = 1;
  RADIO_S_CRCCNF = 0;
  RADIO_S_CRCPOLY = 0;
  RADIO_S_TXADDRESS = 0;
  RADIO_S_RXADDRESSES = 1;
  if (param_2 == 1) {
LAB_0e05ca16:
    RADIO_S_PREFIX0 = 0x6a;
    RADIO_S_BASE0 = 0x58fe811b;
  }
  else if (param_2 == 2) {
    RADIO_S_PREFIX0 = 0xcc;
    RADIO_S_BASE0 = 0xcccccccc;
  }
  else {
    if (param_2 != 0) goto LAB_0e05ca16;
    RADIO_S_PREFIX0 = 0xab;
    RADIO_S_BASE0 = 0xabababab;
  }
  if (param_3 == 0) {
    param_3 = 0xff;
  }
  param_3 = param_3 & 0xff;
  sVar1 = (short)param_3;
  if (param_1 < 7) {
    if (4 < param_1) {
      RADIO_S_CRCCNF = 0x103;
      dVar2 = 0x63800008;
      DAT_230071ae = sVar1 + 0x17;
      dVar3 = param_3 | 0x2030000;
      RADIO_S_CRCPOLY = 0;
      goto LAB_0e05ca42;
    }
    if (param_1 == 4) {
      dVar2 = 0x1000008;
      DAT_230071ae = sVar1 + 8;
      dVar3 = param_3 | 0x3040000;
      goto LAB_0e05ca42;
    }
  }
  else if (param_1 == 0xf) {
    DAT_230071ae = 0x85;
    dVar3 = 0x7f;
    dVar2 = 0x2000008;
    goto LAB_0e05ca42;
  }
  dVar2 = 8;
  DAT_230071ae = sVar1 + 7;
  dVar3 = param_3 | 0x3040000;
LAB_0e05ca42:
  RADIO_S_PCNF0 = dVar2;
  RADIO_S_PCNF1 = dVar3;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cac4. Types and names are inferred; NOT original source. */

void FUN_0e05cac4(int param_1,int param_2,int param_3)

{
  FUN_0e05c9ec();
  if (param_1 == 0xf) {
    DAT_23006730 = 0x7e;
  }
  else if (param_3 == 0) {
    DAT_23006730 = 0xff;
  }
  else {
    DAT_23006730 = (undefined1)param_3;
  }
  if (param_2 == 1) {
    FUN_0e06f3aa(&DAT_23006731,0xf0,0xff);
    RADIO_S_PACKETPTR = 0x23006730;
    return;
  }
  if (param_2 == 2) {
    FUN_0e06f3aa(&DAT_23006731,0xcc,0xff);
    RADIO_S_PACKETPTR = 0x23006730;
    return;
  }
  if (param_2 != 0) {
    FUN_0e06f3aa(&DAT_23006731,param_2,0xff);
    RADIO_S_PACKETPTR = 0x23006730;
    return;
  }
  FUN_0e0621b8(&DAT_23006731,0xff);
  RADIO_S_PACKETPTR = 0x23006730;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cb44. Types and names are inferred; NOT original source. */

void FUN_0e05cb44(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  uint uVar1;
  
  FUN_0e05c7f4();
  if (param_1 == 0) {
    FUN_0e06a760(DAT_230071df,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_TXEN);
    uVar1 = 4;
  }
  else {
    FUN_0e06a760(DAT_230071df,&EGU020_S_EVENTS_TRIGGERED_0,&RADIO_S_TASKS_RXEN);
    uVar1 = 0x10;
  }
  DAT_23006620 = DAT_23006620 | uVar1;
  FUN_0e06a6a0(DAT_230071df,&TIMER021_S_TASKS_START);
  DAT_23006620 = DAT_23006620 | 0x10000;
  FUN_0e06ab28(1 << DAT_230071df,extraout_r1,0,param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cbb8. Types and names are inferred; NOT original source. */

void FUN_0e05cbb8(dword param_1,undefined4 param_2,dword param_3)

{
  dword dVar1;
  
  RADIO_S_SHORTS = 0;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_EVENTS_DISABLED = 0;
  dVar1 = RADIO_S_EVENTS_DISABLED;
  RADIO_S_TASKS_DISABLE = 1;
  do {
    dVar1 = RADIO_S_EVENTS_DISABLED;
  } while (dVar1 == 0);
  RADIO_S_EVENTS_DISABLED = 0;
  dVar1 = RADIO_S_EVENTS_DISABLED;
  RADIO_S_MODE = param_1;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 1;
  FUN_0e05c8fc(param_2);
  if (param_1 == 0xf) {
    if (param_3 - 0xb < 0x10) {
      param_3 = param_3 * 5 - 0x32;
    }
    else {
      param_3 = 5;
    }
  }
  RADIO_S_FREQUENCY = param_3;
  if ((DAT_230071e0 != '\0') && (FUN_0e05cb44(0), DAT_230071e0 != '\0')) {
    EGU020_S_TASKS_TRIGGER_0 = 1;
    return;
  }
  RADIO_S_TASKS_TXEN = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cc4c. Types and names are inferred; NOT original source. */

void FUN_0e05cc4c(dword param_1,dword param_2,undefined4 param_3,undefined4 param_4)

{
  dword dVar1;
  
  RADIO_S_SHORTS = 0;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_EVENTS_DISABLED = 0;
  dVar1 = RADIO_S_EVENTS_DISABLED;
  RADIO_S_TASKS_DISABLE = 1;
  do {
    dVar1 = RADIO_S_EVENTS_DISABLED;
  } while (dVar1 == 0);
  RADIO_S_EVENTS_DISABLED = 0;
  dVar1 = RADIO_S_EVENTS_DISABLED;
  RADIO_S_MODE = param_1;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x21;
  RADIO_S_PACKETPTR = 0x23006630;
  FUN_0e05c9ec(param_1,param_3,0,&RADIO_S_TASKS_TXEN,param_4);
  if (param_1 == 0xf) {
    if (param_2 - 0xb < 0x10) {
      param_2 = param_2 * 5 - 0x32;
    }
    else {
      param_2 = 5;
    }
  }
  RADIO_S_FREQUENCY = param_2;
  DAT_23006628 = 0;
  DAT_23006624 = 0;
  RADIO_S_INTENSET00 = 0x800;
  if ((DAT_230071e0 != '\0') && (FUN_0e05cb44(1), DAT_230071e0 != '\0')) {
    EGU020_S_TASKS_TRIGGER_0 = 1;
    return;
  }
  RADIO_S_TASKS_RXEN = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cd0c. Types and names are inferred; NOT original source. */

void FUN_0e05cd0c(undefined4 param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  
  if (*param_2 == '\x03') {
    DAT_230071e0 = 1;
    FUN_0e05cbb8(param_2[1],(int)param_2[4],DAT_230071e1);
    bVar3 = param_2[5];
    bVar1 = param_2[6];
    cVar2 = param_2[7];
  }
  else {
    if (*param_2 != '\x04') {
      FUN_0e05d634("Unexpected test type: %d\n");
      return;
    }
    DAT_230071e0 = 1;
    FUN_0e05cc4c(param_2[1],DAT_230071e1,param_2[4]);
    bVar3 = param_2[4];
    bVar1 = param_2[5];
    cVar2 = param_2[6];
  }
  if ((byte)(cVar2 + DAT_230071e1) <= bVar1) {
    bVar3 = cVar2 + DAT_230071e1;
  }
  DAT_230071e1 = bVar3;
  DAT_230071e0 = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05cd78. Types and names are inferred; NOT original source. */

void FUN_0e05cd78(undefined1 *param_1)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  dword dVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  dword dVar9;
  uint uVar10;
  int iVar11;
  
  switch(*param_1) {
  case 0:
    FUN_0e05cbb8(param_1[1],(int)(char)param_1[4],param_1[5]);
    return;
  case 1:
    iVar7 = *(int *)(param_1 + 8);
    uVar8 = (uint)(byte)param_1[1];
    iVar11 = (int)(char)param_1[4];
    dVar9 = (dword)(byte)param_1[6];
    RADIO_S_SHORTS = 0;
    RADIO_S_INTENCLR00 = 0xffffffff;
    RADIO_S_EVENTS_DISABLED = 0;
    dVar4 = RADIO_S_EVENTS_DISABLED;
    RADIO_S_TASKS_DISABLE = 1;
    do {
      dVar4 = RADIO_S_EVENTS_DISABLED;
    } while (dVar4 == 0);
    RADIO_S_EVENTS_DISABLED = 0;
    dVar4 = RADIO_S_EVENTS_DISABLED;
    FUN_0e05cac4(uVar8,param_1[5],*(undefined4 *)(param_1 + 0xc),dVar4);
    if (uVar8 < 7) {
      if (4 < uVar8) {
        dVar4 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar4 | 0x100001;
        RADIO_S_MODE = uVar8;
        FUN_0e05c8fc(iVar11);
        goto LAB_0e05cf4c;
      }
    }
    else if (uVar8 == 0xf) {
      dVar4 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar4 | 0x100001;
      RADIO_S_MODE = 0xf;
      FUN_0e05c8fc(iVar11);
      if (dVar9 - 0xb < 0x10) {
        dVar9 = dVar9 * 5 - 0x32;
      }
      else {
        dVar9 = 5;
      }
      goto LAB_0e05cf4c;
    }
    dVar4 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar4 | 0x21;
    RADIO_S_MODE = uVar8;
    FUN_0e05c8fc(iVar11);
LAB_0e05cf4c:
    RADIO_S_FREQUENCY = dVar9;
    DAT_2300662c = 0;
    RADIO_S_EVENTS_END = 0;
    dVar4 = RADIO_S_EVENTS_END;
    if (iVar7 != 0) {
      RADIO_S_INTENSET00 = 0x40;
    }
    RADIO_S_TASKS_TXEN = 1;
    return;
  case 2:
    FUN_0e05cc4c(param_1[1],param_1[0xc],param_1[4]);
    return;
  case 3:
    uVar5 = *(undefined4 *)(param_1 + 8);
    DAT_230071e1 = param_1[5];
    break;
  case 4:
    uVar5 = *(undefined4 *)(param_1 + 8);
    DAT_230071e1 = param_1[4];
    break;
  case 5:
    uVar8 = *(uint *)(param_1 + 8);
    iVar7 = *(int *)(param_1 + 0xc);
    uVar10 = (uint)(byte)param_1[1];
    cVar2 = param_1[4];
    dVar9 = (dword)(byte)param_1[6];
    RADIO_S_SHORTS = 0;
    RADIO_S_INTENCLR00 = 0xffffffff;
    RADIO_S_EVENTS_DISABLED = 0;
    dVar4 = RADIO_S_EVENTS_DISABLED;
    RADIO_S_TASKS_DISABLE = 1;
    do {
      dVar4 = RADIO_S_EVENTS_DISABLED;
    } while (dVar4 == 0);
    RADIO_S_EVENTS_DISABLED = 0;
    dVar4 = RADIO_S_EVENTS_DISABLED;
    FUN_0e05cac4(uVar10,param_1[5],*(undefined4 *)(param_1 + 0x10),dVar4);
    RADIO_S_MODE = uVar10;
    dVar4 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar4 | 0x80001;
    FUN_0e05c8fc((int)cVar2);
    if (uVar10 == 0xf) {
      if (dVar9 - 0xb < 0x10) {
        dVar9 = dVar9 * 5 - 0x32;
      }
      else {
        dVar9 = 5;
      }
    }
    RADIO_S_FREQUENCY = dVar9;
    uVar6 = (uint)DAT_230071ae;
    bVar1 = (&DAT_0e06fd04)[uVar10];
    DAT_2300662c = 0;
    FUN_0e069f5c(&DAT_0e06fd14);
    FUN_0e05cb44(0);
    dVar4 = TIMER021_S_SHORTS;
    TIMER021_S_SHORTS = 0;
    TIMER021_S_INTENCLR = 0xffffffff;
    uVar5 = FUN_0e069f84(&DAT_0e06fd14,(uVar6 * bVar1 * (100 - uVar8)) / uVar8 + uVar6 * bVar1);
    FUN_0e06a064(&DAT_0e06fd14,1,uVar5,2,0);
    if (iVar7 != 0) {
      RADIO_S_INTENSET00 = 0x40;
    }
    uVar5 = 0;
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      uVar5 = getBasePriority();
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if ((bVar3) && (uVar8 = getBasePriority(), uVar8 == 0 || 0x40 < uVar8)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    EGU020_S_TASKS_TRIGGER_0 = 1;
    iVar7 = FUN_0e06aacc(DAT_230071df);
    if (iVar7 != 0) {
      FUN_0e06ab4c(1 << DAT_230071df);
    }
    FUN_0e05c7f4();
    FUN_0e06a760(DAT_230071df,&TIMER021_S_EVENTS_COMPARE_1,&RADIO_S_TASKS_TXEN);
    DAT_23006620 = DAT_23006620 | 0x100;
    FUN_0e06ab28(1 << (uint)DAT_230071df);
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
  default:
    return;
  }
  FUN_0e069f5c(&DAT_0e06fd14);
  dVar4 = TIMER021_S_SHORTS;
  TIMER021_S_SHORTS = 0;
  TIMER021_S_INTENCLR = 0xffffffff;
  uVar5 = FUN_0e069ff0(&DAT_0e06fd14,uVar5);
  FUN_0e06a064(&DAT_0e06fd14,0,uVar5,0x10001,1);
  TIMER021_S_TASKS_START = 1;
  DAT_23006e54 = 2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d028. Types and names are inferred; NOT original source. */

void FUN_0e05d028(void)

{
  dword dVar1;
  int iVar2;
  
  FUN_0e069f5c(&DAT_0e06fd14);
  FUN_0e069f7c(&DAT_0e06fd14);
  DAT_230071e0 = 0;
  iVar2 = FUN_0e06aacc(DAT_230071df);
  if (iVar2 != 0) {
    FUN_0e06ab4c(1 << (uint)DAT_230071df);
  }
  FUN_0e05c7f4();
  RADIO_S_SHORTS = 0;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_EVENTS_DISABLED = 0;
  dVar1 = RADIO_S_EVENTS_DISABLED;
  RADIO_S_TASKS_DISABLE = 1;
  do {
    dVar1 = RADIO_S_EVENTS_DISABLED;
  } while (dVar1 == 0);
  RADIO_S_EVENTS_DISABLED = 0;
  dVar1 = RADIO_S_EVENTS_DISABLED;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d1ac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d1ac(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  local_1c = 1000000;
  local_18 = 0x200;
  uStack_14 = param_1;
  iVar1 = FUN_0e069ee8(&DAT_0e06fd14,&local_1c,&LAB_0e05cd04_1);
  if (iVar1 != 0xbad0000) {
    FUN_0e05d634("nrfx_timer_init failed with: %d\n",iVar1);
  }
  FUN_0e0612f0(0x29,5,0);
  DAT_2300661c = param_1;
  iVar1 = FUN_0e06a658(&DAT_230071df);
  if (iVar1 == 0xbad0000) {
    FUN_0e05d634("ppi_radio_start = %d\n",DAT_230071df);
    uVar2 = 0;
  }
  else {
    FUN_0e05d634("Failed to allocate gppi channel.\n");
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d230. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d230(void)

{
  FUN_0e05d028();
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d23c. Types and names are inferred; NOT original source. */

void FUN_0e05d23c(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = param_2 + -1;
    do {
      iVar1 = iVar1 + 1;
    } while (iVar1 != param_2 + param_3 + -1);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d278. Types and names are inferred; NOT original source. */

void FUN_0e05d278(int param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_2 * 8 + 2;
  sVar1 = (short)param_3 - (short)param_2;
  iVar2 = (param_2 - param_3) + (uint)(*(ushort *)(param_1 + iVar3) >> 1);
  uVar4 = iVar2 * 2;
  *(short *)(param_1 + iVar3) = sVar1 * 2;
  *(short *)(param_1 + param_3 * 8 + 2) = (short)uVar4;
  *(short *)(param_1 + param_3 * 8) = sVar1;
  *(short *)(param_1 + (((uVar4 & 0xffff) >> 1) + param_3) * 8) = (short)iVar2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d2a8. Types and names are inferred; NOT original source. */

void FUN_0e05d2a8(int param_1,int param_2,int param_3)

{
  int iVar1;
  short sVar2;
  int iVar3;
  
  iVar1 = param_2 * 8 + 2;
  iVar3 = param_3 * 8 + 2;
  sVar2 = (*(ushort *)(param_1 + iVar1) >> 1) + (*(ushort *)(param_1 + iVar3) >> 1);
  *(short *)(param_1 + iVar1) = sVar2 * 2;
  *(short *)(param_1 + (param_3 + (uint)(*(ushort *)(param_1 + iVar3) >> 1)) * 8) = sVar2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d2dc. Types and names are inferred; NOT original source. */

void FUN_0e05d2dc(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1 + param_2 * 8;
  uVar3 = 0x1f - LZCOUNT((uint)(*(ushort *)(iVar4 + 2) >> 1));
  iVar5 = param_1 + uVar3 * 4;
  iVar2 = *(int *)(iVar5 + 0x10);
  iVar6 = param_2 * 8 + 4;
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 1 << (uVar3 & 0xff);
    *(uint *)(iVar5 + 0x10) = param_2;
    *(uint *)(param_1 + iVar6) = param_2 & 0xffff | param_2 << 0x10;
    return;
  }
  iVar5 = iVar2 * 8 + 4;
  uVar1 = *(ushort *)(param_1 + iVar5);
  *(ushort *)(param_1 + iVar6) = uVar1;
  *(short *)(iVar4 + 6) = (short)iVar2;
  *(short *)(param_1 + (uint)uVar1 * 8 + 6) = (short)param_2;
  *(short *)(param_1 + iVar5) = (short)param_2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d338. Types and names are inferred; NOT original source. */

void FUN_0e05d338(int param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_1 + param_2 * 8;
  uVar1 = *(ushort *)(iVar4 + 6);
  uVar3 = (uint)uVar1;
  if (param_2 != uVar3) {
    uVar2 = *(ushort *)(iVar4 + 4);
    *(uint *)(param_1 + (param_3 + 4) * 4) = uVar3;
    *(ushort *)(param_1 + (uint)uVar2 * 8 + 6) = uVar1;
    *(ushort *)(param_1 + uVar3 * 8 + 4) = uVar2;
    return;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & ~(1 << (param_3 & 0xff));
  *(undefined4 *)(param_1 + (param_3 + 4) * 4) = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d37c. Types and names are inferred; NOT original source. */

uint FUN_0e05d37c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar6 = LZCOUNT(param_2);
  iVar5 = 0x1f - iVar6;
  iVar9 = param_1 + iVar5 * 4;
  uVar8 = *(uint *)(iVar9 + 0x10);
  if (uVar8 != 0) {
    iVar10 = 3;
    uVar7 = uVar8;
    do {
      iVar11 = param_1 + uVar7 * 8;
      if (param_2 <= *(ushort *)(iVar11 + 2) >> 1) goto LAB_0e05d3d4;
      uVar7 = (uint)*(ushort *)(iVar11 + 6);
      iVar10 = iVar10 + -1;
      *(uint *)(iVar9 + 0x10) = uVar7;
    } while ((iVar10 != 0) && (uVar8 != uVar7));
  }
  uVar8 = -1 << (0x20U - iVar6 & 0xff) & *(uint *)(param_1 + 0xc);
  if (uVar8 == 0) {
    return 0;
  }
  bVar2 = (byte)uVar8;
  bVar3 = (byte)(uVar8 >> 8);
  bVar4 = (byte)(uVar8 >> 0x10);
  bVar1 = (byte)(uVar8 >> 0x18);
  iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1
                                  | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) <<
                                1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18 |
                  (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1
                                  | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) <<
                                1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                  (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1
                                  | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) <<
                                1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                  (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) << 1
                                  | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) <<
                                1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
  iVar6 = iVar5 + 4;
  uVar7 = *(uint *)(param_1 + iVar6 * 4);
LAB_0e05d3d4:
  FUN_0e05d338(param_1,uVar7,iVar5,iVar6,param_4);
  return uVar7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d3e0. Types and names are inferred; NOT original source. */

void FUN_0e05d3e0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_2 * 8;
  iVar2 = param_2 + (uint)(*(ushort *)(param_1 + iVar3 + 2) >> 1);
  uVar1 = *(ushort *)(param_1 + iVar2 * 8 + 2);
  if (-1 < (int)((uint)uVar1 << 0x1f)) {
    FUN_0e05d338(param_1,iVar2,0x1f - LZCOUNT((uint)(uVar1 >> 1)));
    FUN_0e05d2a8(param_1,param_2,param_2 + (uint)(*(ushort *)(param_1 + iVar3 + 2) >> 1));
  }
  iVar2 = param_2 - (uint)*(ushort *)(param_1 + iVar3);
  uVar1 = *(ushort *)(param_1 + iVar2 * 8 + 2);
  if ((int)((uint)uVar1 << 0x1f) < 0) {
    FUN_0e05d2dc(param_1,param_2,(uint)uVar1,param_4);
    return;
  }
  FUN_0e05d338(param_1,iVar2,0x1f - LZCOUNT((uint)(uVar1 >> 1)));
  FUN_0e05d2a8(param_1,param_2 - (uint)*(ushort *)(param_1 + iVar3),param_2);
  FUN_0e05d2dc(param_1,param_2 - (uint)*(ushort *)(param_1 + iVar3));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d460. Types and names are inferred; NOT original source. */

void FUN_0e05d460(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar1 = *param_1;
    uVar2 = (param_2 + -4) - iVar1;
    iVar3 = (uVar2 & 0xfffffff8) + iVar1;
    *(ushort *)(iVar3 + 2) = *(ushort *)(iVar3 + 2) & 0xfffe;
    FUN_0e05d3e0(iVar1,uVar2 >> 3);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d480. Types and names are inferred; NOT original source. */

int FUN_0e05d480(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *param_1;
  if ((param_2 != 0) && (param_2 >> 3 < *(uint *)(iVar4 + 8))) {
    uVar3 = param_2 + 0xb >> 3;
    iVar1 = FUN_0e05d37c(iVar4,uVar3,param_3,*(uint *)(iVar4 + 8),param_4);
    if (iVar1 != 0) {
      iVar5 = iVar4 + iVar1 * 8;
      if (uVar3 < *(ushort *)(iVar5 + 2) >> 1) {
        uVar2 = FUN_0e05d278(iVar4,iVar1,iVar1 + uVar3);
        FUN_0e05d2dc(uVar2,extraout_r2);
      }
      *(ushort *)(iVar5 + 2) = *(ushort *)(iVar5 + 2) | 1;
      return iVar4 + iVar1 * 8 + 4;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d4d0. Types and names are inferred; NOT original source. */

int FUN_0e05d4d0(int *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = param_2 - 1 & param_2;
  iVar6 = *param_1;
  if (uVar8 == 0) {
    if (param_2 < 5) {
      iVar6 = FUN_0e05d480(param_1,param_3);
      return iVar6;
    }
    uVar4 = 0;
    uVar3 = 4;
    uVar8 = param_2;
  }
  else {
    uVar4 = -param_2 & param_2;
    uVar3 = uVar4;
    if (3 < uVar4) {
      uVar3 = 4;
    }
  }
  if (((param_3 != 0) && (param_3 >> 3 < *(uint *)(iVar6 + 8))) &&
     (uVar3 = FUN_0e05d37c(iVar6,(param_3 + 0xb + uVar8) - uVar3 >> 3), uVar3 != 0)) {
    iVar5 = ((uVar4 + uVar3 * 8 + iVar6 + uVar8 + 3) / uVar8) * uVar8 - uVar4;
    uVar4 = (iVar5 + -4) - iVar6;
    uVar8 = (int)((param_3 + iVar5 + 7 & 0xfffffff8) - iVar6) >> 3;
    uVar9 = uVar4 >> 3;
    if (uVar3 < uVar4 >> 3) {
      uVar2 = FUN_0e05d278(iVar6,uVar3,uVar9);
      iVar7 = iVar6 + uVar9 * 8;
      FUN_0e05d2dc(uVar2,uVar3);
      uVar1 = *(ushort *)(iVar7 + 2);
    }
    else {
      iVar7 = iVar6 + uVar9 * 8;
      uVar1 = *(ushort *)(iVar7 + 2);
    }
    if (uVar8 < uVar9 + (uVar1 >> 1)) {
      uVar2 = FUN_0e05d278(iVar6,uVar9,uVar8);
      FUN_0e05d2dc(uVar2,uVar8);
    }
    *(ushort *)(iVar7 + 2) = *(ushort *)(iVar7 + 2) | 1;
    return iVar5;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d5b0. Types and names are inferred; NOT original source. */

void FUN_0e05d5b0(undefined4 *param_1,int param_2,int param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  
  puVar4 = (undefined2 *)(param_2 + 7U & 0xfffffff8);
  uVar2 = (param_2 + param_3 + -4 & 0xfffffff8U) - (int)puVar4;
  uVar5 = uVar2 >> 3;
  uVar3 = (0x24 - LZCOUNT(uVar5)) * 4 + 7U >> 3;
  *param_1 = puVar4;
  *(undefined4 *)(puVar4 + 6) = 0;
  *(uint *)(puVar4 + 4) = uVar5;
  FUN_0e06f3aa(puVar4 + 8,0,(0x20 - LZCOUNT(uVar5)) * 4);
  puVar4[1] = (ushort)(uVar3 << 1) | 1;
  sVar1 = (short)uVar5 - (short)uVar3;
  *puVar4 = 0;
  puVar4[uVar3 * 4 + 1] = sVar1 * 2;
  puVar4[uVar3 * 4] = (short)uVar3;
  *(short *)((int)puVar4 + uVar2) = sVar1;
  *(undefined2 *)((int)puVar4 + uVar2 + 2) = 1;
  FUN_0e05d2dc(puVar4,uVar3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d634. Types and names are inferred; NOT original source. */

void FUN_0e05d634(undefined4 param_1)

{
  undefined4 local_28;
  undefined1 *local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  local_24 = &LAB_0e05d628_1;
  local_20 = 0;
  uStack_1c = 0;
  local_28 = 0x20000;
  FUN_0e06eea8(&local_28,param_1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d698. Types and names are inferred; NOT original source. */

void FUN_0e05d698(void)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06110c();
  FUN_0e05d634("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e061410();
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d6bc. Types and names are inferred; NOT original source. */

void FUN_0e05d6bc(int param_1,uint param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  puVar3 = &local_28;
  if (param_5 == (uint *)0x0) {
    local_24 = param_3 + -1 + param_2;
    local_28 = param_2 >> 5;
    local_1c = local_24 & 0x1f;
    local_1c = 1 << local_1c;
    local_24 = local_24 >> 5;
    local_20 = param_2 & 0x1f;
    local_18 = -(1 << (param_2 & 0x1f));
    local_14 = local_1c - 1 | local_1c;
    uVar2 = local_28;
    if (local_28 == local_24) {
      local_18 = local_18 & local_14;
      goto LAB_0e05d74e;
    }
  }
  else {
    local_28 = param_5[1];
    local_18 = param_5[4];
    puVar3 = param_5;
    uVar2 = *param_5;
    if (*param_5 == local_28) {
LAB_0e05d74e:
      iVar1 = *(int *)(param_1 + 8);
      uVar2 = *(uint *)(iVar1 + local_28 * 4);
      if (param_4 == 0) {
        *(uint *)(iVar1 + local_28 * 4) = uVar2 & ~local_18;
        return;
      }
      *(uint *)(iVar1 + local_28 * 4) = local_18 | uVar2;
      return;
    }
  }
  iVar1 = *(int *)(param_1 + 8);
  uVar4 = *(uint *)(iVar1 + uVar2 * 4);
  if (param_4 == 0) {
    *(uint *)(iVar1 + uVar2 * 4) = uVar4 & ~local_18;
    *(uint *)(*(int *)(param_1 + 8) + puVar3[1] * 4) =
         *(uint *)(*(int *)(param_1 + 8) + puVar3[1] * 4) & ~puVar3[5];
    uVar2 = *puVar3 + 1;
    if (uVar2 < puVar3[1]) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 8) + uVar2 * 4) = 0;
        uVar2 = uVar2 + 1;
      } while (uVar2 < puVar3[1]);
      return;
    }
  }
  else {
    *(uint *)(iVar1 + uVar2 * 4) = local_18 | uVar4;
    *(uint *)(*(int *)(param_1 + 8) + puVar3[1] * 4) =
         *(uint *)(*(int *)(param_1 + 8) + puVar3[1] * 4) | puVar3[5];
    uVar2 = *puVar3 + 1;
    if (uVar2 < puVar3[1]) {
      do {
        *(undefined4 *)(*(int *)(param_1 + 8) + uVar2 * 4) = 0xffffffff;
        uVar2 = uVar2 + 1;
      } while (uVar2 < puVar3[1]);
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d7a4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d7a4(int param_1,uint param_2,int param_3,int param_4,uint *param_5,int *param_6)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar7 = param_3 + -1 + param_2;
  uVar10 = uVar7 & 0x1f;
  uVar11 = 1 << uVar10;
  param_5[3] = uVar10;
  uVar7 = uVar7 >> 5;
  uVar6 = param_2 >> 5;
  param_5[2] = param_2 & 0x1f;
  uVar10 = -(1 << (param_2 & 0x1f));
  uVar11 = uVar11 - 1 | uVar11;
  param_5[1] = uVar7;
  *param_5 = uVar6;
  param_5[4] = uVar10;
  param_5[5] = uVar11;
  if (uVar6 == uVar7) {
    uVar10 = uVar10 & uVar11;
    param_5[4] = uVar10;
    uVar7 = *(uint *)(*(int *)(param_1 + 8) + uVar6 * 4);
    if (param_4 == 0) {
      uVar7 = ~uVar7;
    }
    if ((uVar10 & ~uVar7) != 0) {
      uVar5 = uVar10 & ~uVar7;
      goto LAB_0e05d7ea;
    }
  }
  else {
    iVar9 = *(int *)(param_1 + 8);
    uVar12 = *(uint *)(iVar9 + uVar6 * 4);
    uVar5 = uVar12 & uVar10;
    if (param_4 == 0) {
      if (uVar5 != 0) goto LAB_0e05d7ea;
      uVar10 = ~*(uint *)(iVar9 + uVar7 * 4);
    }
    else {
      if (uVar5 != uVar10) {
        uVar5 = uVar10 & ~uVar12;
        goto LAB_0e05d7ea;
      }
      uVar10 = *(uint *)(iVar9 + uVar7 * 4);
    }
    if ((uVar11 & ~uVar10) != 0) {
      uVar5 = uVar11 & ~uVar10;
      uVar6 = uVar7;
LAB_0e05d7ea:
      if (param_6 != (int *)0x0) {
        bVar2 = (byte)uVar5;
        bVar3 = (byte)(uVar5 >> 8);
        bVar4 = (byte)(uVar5 >> 0x10);
        bVar1 = (byte)(uVar5 >> 0x18);
        iVar9 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1)
                                         << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                      bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                        0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                                bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                              bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                            bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                        (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                         << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                      bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8
                        | (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 |
                                           bVar1 >> 2 & 1) << 1 | bVar1 >> 3 & 1) << 1 |
                                         bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                                       bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
        if (uVar5 == 0) {
          iVar9 = -1;
        }
        *param_6 = iVar9 + uVar6 * 0x20;
      }
      return 0;
    }
    uVar10 = uVar6 + 1;
    if (uVar10 < uVar7) {
      puVar8 = (uint *)(iVar9 + uVar6 * 4);
      do {
        puVar8 = puVar8 + 1;
        uVar5 = *puVar8;
        if (param_4 != 0) {
          uVar5 = ~uVar5;
        }
        uVar6 = uVar10;
        if (uVar5 != 0) goto LAB_0e05d7ea;
        uVar10 = uVar10 + 1;
      } while (puVar8 != (uint *)(iVar9 + uVar7 * 4 + -4));
    }
  }
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d8b4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d8b4(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_2 < *param_1) {
    uVar3 = 0;
    *(uint *)(param_1[2] + (param_2 >> 5) * 4) =
         *(uint *)(param_1[2] + (param_2 >> 5) * 4) & ~(1 << (param_2 & 0x1f));
  }
  else {
    uVar3 = 0xffffffea;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d8f8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d8f8(uint *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((param_3 == (uint *)0x0) || (*param_1 <= param_2)) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *param_3 = *(uint *)(param_1[2] + (param_2 >> 5) * 4) >> (param_2 & 0x1f) & 1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d934. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d934(uint *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((param_3 == (uint *)0x0) || (*param_1 <= param_2)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar3 = param_2 >> 5;
    *param_3 = *(uint *)(param_1[2] + uVar3 * 4) >> (param_2 & 0x1f) & 1;
    uVar2 = 0;
    *(uint *)(param_1[2] + uVar3 * 4) = *(uint *)(param_1[2] + uVar3 * 4) | 1 << (param_2 & 0x1f);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05d988. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05d988(uint *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  int local_44;
  undefined1 auStack_40 [28];
  
  uVar13 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar13 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar11 = getBasePriority(), uVar11 == 0 || 0x40 < uVar11)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (((param_3 == (uint *)0x0) || (param_2 == 0)) || (*param_1 < param_2)) {
    uVar7 = 0xffffffea;
    goto LAB_0e05da1e;
  }
  uVar12 = *param_1 - param_2;
  uVar11 = 0;
  if (param_1[1] == 0) {
LAB_0e05d9d0:
    do {
      iVar6 = FUN_0e05d7a4(param_1,uVar11,param_2,0,auStack_40,&local_44);
      if (iVar6 != 0) {
        FUN_0e05d6bc(param_1,uVar11,param_2,1,auStack_40);
        *param_3 = uVar11;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar13);
        }
        InstructionSynchronizationBarrier(0xf);
        return 0;
      }
      uVar11 = local_44 + 1;
    } while (uVar11 <= uVar12);
  }
  else {
    uVar8 = 0;
    uVar11 = 0;
    puVar9 = (uint *)(param_1[2] - 4);
    do {
      puVar9 = puVar9 + 1;
      uVar10 = *puVar9;
      if (uVar10 != 0xffffffff) {
        if (uVar10 != 0) {
          uVar10 = ~uVar10;
          bVar3 = (byte)uVar10;
          bVar4 = (byte)(uVar10 >> 8);
          bVar5 = (byte)(uVar10 >> 0x10);
          bVar2 = (byte)(uVar10 >> 0x18);
          uVar11 = uVar11 + LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                                     bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                                   bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                                 bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18 |
                                    (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                                     bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                                   bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                                 bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                                    (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 |
                                                     bVar5 >> 2 & 1) << 1 | bVar5 >> 3 & 1) << 1 |
                                                   bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1 |
                                                 bVar5 >> 6 & 1) << 1 | bVar5 >> 7) << 8 |
                                    (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                                     bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                                   bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                                 bVar2 >> 6 & 1) << 1 | bVar2 >> 7));
        }
        break;
      }
      uVar8 = uVar8 + 1;
      uVar11 = uVar11 + 0x20;
    } while (uVar8 != param_1[1]);
    if (uVar11 <= uVar12) goto LAB_0e05d9d0;
  }
  uVar7 = 0xffffffe4;
LAB_0e05da1e:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar13);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05da4c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05da4c(uint *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 auStack_38 [28];
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((((param_2 == 0) || (uVar4 = *param_1, uVar4 < param_2)) || (uVar4 <= param_3)) ||
     (uVar4 <= (param_2 - 1) + param_3)) {
    uVar3 = 0xffffffea;
  }
  else {
    iVar2 = FUN_0e05d7a4(param_1,param_3,param_2,1,auStack_38,0);
    if (iVar2 == 0) {
      uVar3 = 0xfffffff2;
    }
    else {
      FUN_0e05d6bc(param_1,param_3,param_2,0,auStack_38);
      uVar3 = 0;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05dab8. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e05dafa) */

void FUN_0e05dab8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  code *pcVar2;
  code *pcVar3;
  short sVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  int *piVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  
  uVar11 = *(ushort *)(param_1 + 6);
  uVar12 = (uint)uVar11;
  if ((uVar11 & 8) != 0) {
    if (param_2 == 1) {
      uVar11 = uVar11 | 0x10;
    }
    else {
      uVar11 = uVar11 | 0x20;
    }
    *(ushort *)(param_1 + 6) = uVar11;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(param_3);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  do {
    pcVar2 = (code *)(uVar12 & 7);
    if (param_2 == 2) {
      if (pcVar2 == (code *)0x0) {
        if (*param_1 == 0) goto LAB_0e05dc06;
        uVar12 = uVar12 & 0xfffffff8 | 6;
        pcVar2 = *(code **)param_1[4];
        *(short *)(param_1 + 6) = (short)uVar12;
        pcVar9 = (code *)0x6;
        iVar8 = 0;
      }
      else if (pcVar2 == (code *)0x2) {
        if (*(short *)((int)param_1 + 0x1a) != 0) goto LAB_0e05dc06;
        uVar12 = uVar12 & 0xfffffff8 | 4;
        pcVar2 = *(code **)(param_1[4] + 4);
        *(short *)(param_1 + 6) = (short)uVar12;
        pcVar9 = (code *)&Reset;
        iVar8 = 0;
      }
      else {
        if ((pcVar2 != (code *)0x1) || (*param_1 == 0)) {
LAB_0e05dc06:
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(param_3);
          }
          InstructionSynchronizationBarrier(0xf);
          return;
        }
        uVar12 = uVar12 & 0xfffffff8 | 5;
        pcVar2 = *(code **)(param_1[4] + 8);
        *(short *)(param_1 + 6) = (short)uVar12;
        pcVar9 = (code *)0x5;
        iVar8 = 0;
      }
LAB_0e05db2c:
      uVar11 = (ushort)uVar12;
      piVar10 = (int *)0x0;
      if (param_1[2] != 0) {
LAB_0e05db38:
        *(ushort *)(param_1 + 6) = uVar11 | 8;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(param_3);
        }
        InstructionSynchronizationBarrier(0xf);
        piVar5 = (int *)param_1[2];
        if (piVar5 != (int *)0x0) {
          piVar6 = (int *)*piVar5;
          (*(code *)piVar5[1])(param_1,piVar5,pcVar9,iVar8,param_4);
          while (piVar6 != (int *)0x0) {
            iVar7 = *piVar6;
            (*(code *)piVar6[1])(param_1,piVar6,pcVar9,iVar8);
            piVar6 = (int *)iVar7;
          }
        }
        goto joined_r0x0e05dcb8;
      }
      if (pcVar2 == (code *)0x0) goto LAB_0e05db9e;
      *(ushort *)(param_1 + 6) = uVar11 | 8;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(param_3);
      }
      InstructionSynchronizationBarrier(0xf);
LAB_0e05db7a:
      (*pcVar2)(param_1,&LAB_0e05dd7c_1);
LAB_0e05db80:
      param_3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        param_3 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar12 = getBasePriority(), uVar12 == 0 || 0x40 < uVar12)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar12 = (uint)(*(ushort *)(param_1 + 6) & 0xfff7);
      *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) & 0xfff7;
    }
    else {
      iVar8 = param_1[5];
      if (iVar8 < 0) {
        pcVar9 = (code *)0x1;
        uVar12 = uVar12 & 0xfffffff8 | 1;
        piVar10 = (int *)*param_1;
        *(short *)(param_1 + 6) = (short)uVar12;
        *param_1 = 0;
        param_1[1] = 0;
LAB_0e05dcd8:
        if (pcVar2 != pcVar9) {
LAB_0e05dcde:
          uVar11 = (ushort)uVar12;
          if (param_1[2] != 0) {
            pcVar2 = (code *)0x0;
            goto LAB_0e05db38;
          }
        }
      }
      else {
        if ((code *)0x1 < pcVar2 + -5) {
          if (pcVar2 == (code *)&Reset) {
            uVar12 = uVar12 & 0xfffffff8;
            *(short *)(param_1 + 6) = (short)uVar12;
            if (*param_1 == 0) {
              pcVar9 = (code *)0x0;
              pcVar2 = (code *)0x0;
            }
            else {
              uVar12 = uVar12 | 0x20;
              *(short *)(param_1 + 6) = (short)uVar12;
              pcVar9 = (code *)0x0;
              pcVar2 = pcVar9;
            }
            goto LAB_0e05db2c;
          }
          goto LAB_0e05db9e;
        }
        pcVar9 = (code *)0x0;
        uVar13 = uVar12 & 0xfffffff8;
        piVar10 = (int *)*param_1;
        param_1[1] = 0;
        *param_1 = 0;
        if (pcVar2 == (code *)0x6) {
          if (piVar10 != (int *)0x0) {
            sVar4 = *(short *)((int)param_1 + 0x1a);
            piVar5 = piVar10;
            do {
              sVar4 = sVar4 + 1;
              *(short *)((int)param_1 + 0x1a) = sVar4;
              piVar5 = (int *)*piVar5;
            } while (piVar5 != (int *)0x0);
          }
          uVar12 = uVar13 | 2;
          *(short *)(param_1 + 6) = (short)uVar12;
          if (*(short *)((int)param_1 + 0x1a) == 0) {
            uVar12 = uVar13 | 0x22;
            pcVar9 = (code *)0x2;
            *(short *)(param_1 + 6) = (short)uVar12;
          }
          else {
            pcVar9 = (code *)0x2;
          }
          goto LAB_0e05dcd8;
        }
        *(short *)(param_1 + 6) = (short)uVar13;
        uVar12 = uVar13;
        if (pcVar2 != (code *)0x0) goto LAB_0e05dcde;
      }
      if (piVar10 != (int *)0x0) {
        *(ushort *)(param_1 + 6) = (ushort)uVar12 | 8;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(param_3);
        }
        InstructionSynchronizationBarrier(0xf);
        pcVar2 = (code *)0x0;
joined_r0x0e05dcb8:
        while (piVar5 = piVar10, piVar10 != (int *)0x0) {
          while( true ) {
            piVar10 = (int *)*piVar5;
            pcVar3 = (code *)FUN_0e05df10(piVar5 + 1,iVar8);
            if (pcVar3 == (code *)0x0) break;
            (*pcVar3)(param_1,piVar5,pcVar9,iVar8);
            piVar5 = piVar10;
            if (piVar10 == (int *)0x0) goto LAB_0e05db78;
          }
        }
LAB_0e05db78:
        if (pcVar2 != (code *)0x0) goto LAB_0e05db7a;
        goto LAB_0e05db80;
      }
    }
LAB_0e05db9e:
    if ((uVar12 & 0x10) == 0) {
      if ((uVar12 & 0x20) == 0) goto LAB_0e05dc06;
      uVar12 = uVar12 & 0xffffffdf;
      param_2 = 2;
    }
    else {
      param_2 = 1;
      uVar12 = uVar12 & 0xffffffef;
    }
    *(short *)(param_1 + 6) = (short)uVar12;
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ddc0. Types and names are inferred; NOT original source. */

uint FUN_0e05ddc0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  bool bVar2;
  uint uVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffffffea;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffffea;
  }
  uVar3 = FUN_0e05dee8(param_2 + 1);
  if (uVar3 == 0) {
    if (3 < (uint)param_2[2]) {
      return 0xffffffea;
    }
  }
  else if ((int)uVar3 < 0) {
    return uVar3;
  }
  uVar5 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar5 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar1 = *(ushort *)(param_1 + 6);
  uVar3 = uVar1 & 7;
  if (*(ushort *)((int)param_1 + 0x1a) == 0xffff) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff5;
  }
  if (uVar3 == 2) {
    iVar6 = *(ushort *)((int)param_1 + 0x1a) + 1;
    *(short *)((int)param_1 + 0x1a) = (short)iVar6;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    pcVar4 = (code *)FUN_0e05df10(param_2 + 1,0,uVar5,iVar6,param_4);
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(param_1,param_2,2,0);
    }
    return 2;
  }
  switch(uVar3) {
  case 0:
  case 4:
  case 6:
    *param_2 = 0;
    if ((undefined4 *)param_1[1] == (undefined4 *)0x0) {
      *param_1 = param_2;
      param_1[1] = param_2;
    }
    else {
      *(undefined4 *)param_1[1] = param_2;
      param_1[1] = param_2;
    }
    break;
  default:
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffffb;
  case 5:
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xffffff7a;
  }
  if ((uVar1 & 7) == 0) {
    FUN_0e05dab8(param_1,2);
    return uVar3;
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05dee8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05dee8(int *param_1)

{
  if ((param_1 != (int *)0x0) &&
     (((param_1[1] & 3U) == 1 || (((param_1[1] & 3U) == 3 && (*param_1 != 0)))))) {
    param_1[2] = 0;
    return 0;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05df10. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05df10(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  param_1[2] = param_2;
  if ((param_1[1] & 3) == 3) {
    uVar1 = *param_1;
  }
  else {
    uVar1 = 0;
  }
  param_1[1] = 0;
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05df2c. Types and names are inferred; NOT original source. */

int FUN_0e05df2c(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined1 auStack_38 [32];
  
  if (param_6 == 0) {
    return 0;
  }
  param_3 = param_4 * param_1[6] + *param_1 + param_3;
  uVar2 = -*(int *)param_1[0xf] & param_6;
  if (uVar2 != 0) {
    iVar1 = (**(code **)(*(int *)(param_1[0xe] + 8) + 4))(param_1[0xe],param_3,param_5,uVar2);
    if (iVar1 != 0) {
      return iVar1;
    }
    param_6 = param_6 - uVar2;
    if (param_6 == 0) {
      return 0;
    }
    param_3 = param_3 + uVar2;
    param_5 = param_5 + uVar2;
  }
  FUN_0e06f35c(auStack_38,param_5,param_6);
  piVar3 = (int *)param_1[0xf];
  FUN_0e06f3aa(auStack_38 + param_6,*(undefined1 *)((int)piVar3 + 5),*piVar3 - param_6);
  iVar1 = (**(code **)(*(int *)(param_1[0xe] + 8) + 4))(param_1[0xe],param_3,auStack_38,*piVar3);
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05dfa4. Types and names are inferred; NOT original source. */

int FUN_0e05dfa4(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0e05df2c(param_1,param_2,*(undefined4 *)(param_1 + 0x10),
                       *(undefined4 *)(param_1 + 0x14),param_2,param_3);
  if (-1 < iVar1) {
    uVar2 = **(uint **)(param_1 + 0x3c);
    if (1 < uVar2) {
      param_3 = (param_3 - 1) + uVar2 & -uVar2;
    }
    iVar1 = 0;
    uVar2 = *(uint *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x10) = uVar2 + param_3;
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (uint)CARRY4(uVar2,param_3);
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05dfe0. Types and names are inferred; NOT original source. */

void FUN_0e05dfe0(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0x10;
  iVar1 = FUN_0e05df2c(param_1,param_2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                       param_2,0x10);
  if (iVar1 == 0) {
    uVar2 = **(uint **)(param_1 + 0x3c);
    if (1 < uVar2) {
      uVar3 = uVar2 + 0xf & -uVar2;
    }
    uVar2 = *(uint *)(param_1 + 8);
    *(uint *)(param_1 + 8) = uVar2 - uVar3;
    *(uint *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) - (uint)(uVar2 < uVar3);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e018. Types and names are inferred; NOT original source. */

int FUN_0e05e018(int *param_1,uint *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  byte local_38;
  char local_37;
  ushort local_36;
  int local_30;
  
  uVar6 = 0;
  uVar3 = *param_2 + param_1[0x10] * -2;
  uVar4 = param_2[1] - (uint)(*param_2 < (uint)(param_1[0x10] * 2));
  *param_2 = uVar3;
  param_2[1] = uVar4;
  *param_3 = 0;
  param_3[1] = uVar4;
  uVar5 = uVar4;
  if (uVar3 != 0) {
    do {
      iVar1 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                        (param_1[0xe],uVar5 * param_1[6] + *param_1 + uVar3,&local_38,0x10);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (((char)param_1[8] == local_37) &&
         (uVar2 = FUN_0e05d23c(0xff,&local_37,0xf), local_38 == uVar2)) {
        uVar2 = (uint)local_36;
        uVar6 = 0;
        if (8 < uVar2) {
          uVar6 = *(uint *)param_1[0xf];
          if (1 < uVar6) {
            uVar2 = (uVar2 - 1) + uVar6 & -uVar6;
          }
          uVar6 = local_30 + uVar2;
          *param_3 = uVar6;
          param_3[1] = uVar4;
        }
        *param_2 = uVar3;
        param_2[1] = uVar5;
      }
      bVar7 = uVar3 < (uint)param_1[0x10];
      uVar3 = uVar3 - param_1[0x10];
      uVar5 = uVar5 - bVar7;
    } while (uVar4 <= uVar5 && (uint)(uVar3 <= uVar6) <= uVar4 - uVar5);
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e0d4. Types and names are inferred; NOT original source. */

int FUN_0e05e0d4(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined1 *param_5)

{
  int iVar1;
  uint uVar2;
  byte local_20;
  undefined1 local_1f;
  short local_1e;
  int local_1c;
  
  uVar2 = param_1[6];
  iVar1 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                    (param_1[0xe],
                     (param_4 - (uint)(uVar2 < (uint)param_1[0x10])) * uVar2 +
                     (uVar2 - param_1[0x10]) + *param_1,&local_20,0x10);
  if (-1 < iVar1) {
    uVar2 = FUN_0e05d23c(0xff,&local_1f,0xf);
    if (((local_20 == uVar2) && (local_1e == -1)) && (local_1c == -1)) {
      *param_5 = local_1f;
      return 0;
    }
    iVar1 = -2;
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e13c. Types and names are inferred; NOT original source. */

void FUN_0e05e13c(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char local_21;
  undefined1 local_20;
  char local_1f [15];
  
  local_1f[1] = -1;
  local_1f[2] = -1;
  local_1f[3] = -1;
  local_1f[4] = -1;
  local_1f[5] = -1;
  local_1f[6] = -1;
  local_1f[0xb] = '\x01';
  local_1f[0xc] = 'B';
  local_1f[0xd] = '\0';
  local_1f[0xe] = '\0';
  local_1f[7] = '\0';
  local_1f[8] = '\0';
  local_1f[9] = '\0';
  local_1f[10] = '\0';
  iVar1 = FUN_0e05e0d4(param_1,param_2,0,param_4,&local_21);
  if (iVar1 == -2) {
    local_1f[0] = '\x01';
  }
  else {
    if (iVar1 != 0) {
      return;
    }
    local_1f[0] = local_21 + '\x01';
  }
  local_20 = FUN_0e05d23c(0xff,local_1f,0xf);
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 0x18) - *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0xc) = param_4 - (uint)(*(uint *)(param_1 + 0x18) < *(uint *)(param_1 + 0x40))
  ;
  iVar1 = FUN_0e05dfe0(param_1,&local_20);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = uVar2;
    *(undefined4 *)(param_1 + 0xc) = uVar3;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e1bc. Types and names are inferred; NOT original source. */

int FUN_0e05e1bc(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_30;
  undefined1 local_2f;
  undefined2 local_2e;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined1 auStack_20 [16];
  
  uVar4 = *(uint *)(param_1 + 8);
  local_2c = 0xffffffff;
  local_24 = 0xffffffff;
  local_2e = 0;
  local_28 = *(int *)(param_1 + 0x40) + uVar4;
  local_2f = *(undefined1 *)(param_1 + 0x20);
  uVar5 = *(uint *)(param_1 + 0xc);
  FUN_0e06f3aa(auStack_20,*(undefined1 *)(*(int *)(param_1 + 0x3c) + 5),0x10);
  while (uVar4 != 0) {
    uVar2 = *(uint *)(param_1 + 0x10);
    uVar3 = *(uint *)(param_1 + 0x14);
    if (uVar5 <= uVar3 && (uint)(uVar2 <= uVar4) <= uVar5 - uVar3) break;
    iVar1 = FUN_0e05dfe0(param_1,auStack_20,uVar2,(uVar5 - uVar3) - (uint)(uVar2 > uVar4));
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar5 = *(uint *)(param_1 + 0xc);
    uVar4 = *(uint *)(param_1 + 8);
  }
  uVar2 = *(uint *)(param_1 + 0x18);
  uVar4 = *(int *)(param_1 + 0x40) * 2;
  if (uVar2 <= uVar4 && uVar4 - uVar2 != 0) {
    uVar5 = uVar5 - 1;
  }
  *(uint *)(param_1 + 8) = uVar2 + *(int *)(param_1 + 0x40) * -2;
  *(uint *)(param_1 + 0xc) = uVar5;
  local_30 = FUN_0e05d23c(0xff,&local_2f,0xf);
  FUN_0e05dfe0(param_1,&local_30);
  iVar1 = *(int *)(param_1 + 0xc) + 1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 == *(int *)(param_1 + 0x1c)) {
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  iVar1 = FUN_0e05e0d4(param_1,param_1 + 0x20,*(undefined4 *)(param_1 + 8),iVar1,param_1 + 0x20);
  if (iVar1 == -2) {
    *(undefined1 *)(param_1 + 0x20) = 0;
  }
  else if (iVar1 != 0) {
    return iVar1;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0xc);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e280. Types and names are inferred; NOT original source. */

void FUN_0e05e280(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = param_1[6];
  uVar3 = uVar1 + param_1[0x10] * -2;
  param_4 = param_4 - (uint)(uVar1 < (uint)(param_1[0x10] * 2));
  iVar2 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                    (param_1[0xe],param_4 * uVar1 + *param_1 + uVar3,param_6,0x10);
  if (iVar2 != 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0e05e2d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)**(undefined4 **)(param_1[0xe] + 8))
            (param_1[0xe],
             (param_4 + (uint)CARRY4(param_1[0x10],uVar3)) * param_1[6] +
             *param_1 + param_1[0x10] + uVar3,param_5,0x10);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e2d4. Types and names are inferred; NOT original source. */

uint FUN_0e05e2d4(int param_1)

{
  uint uVar1;
  uint uVar2;
  byte *in_stack_00000000;
  byte *in_stack_00000004;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = in_stack_00000000;
  pbVar4 = in_stack_00000004;
  uVar1 = FUN_0e05e280();
  if (((((uVar1 == 0) &&
        (uVar2 = FUN_0e05d23c(0xff,in_stack_00000000 + 1,0xf), *in_stack_00000000 == uVar2)) &&
       (*(short *)(in_stack_00000000 + 2) == -1)) &&
      ((*(int *)(in_stack_00000000 + 4) == -1 &&
       (uVar2 = FUN_0e05d23c(0xff,in_stack_00000004 + 1,0xf,0,pbVar3,pbVar4),
       *in_stack_00000004 == uVar2)))) &&
     ((*(short *)(in_stack_00000004 + 2) == 0 &&
      ((*(int *)(in_stack_00000004 + 4) == -1 &&
       (uVar2 = *(int *)(param_1 + 0x18) - *(int *)(in_stack_00000004 + 8),
       uVar2 == *(uint *)(param_1 + 0x40) * (uVar2 / *(uint *)(param_1 + 0x40)))))))) {
    uVar1 = (uint)(in_stack_00000000[1] == in_stack_00000004[1]);
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e350. Types and names are inferred; NOT original source. */

int FUN_0e05e350(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint local_18;
  
  uVar2 = *(uint *)(param_1 + 0x40) + *param_2;
  uVar3 = param_2[1] + (uint)CARRY4(*(uint *)(param_1 + 0x40),*param_2);
  *param_2 = uVar2;
  param_2[1] = uVar3;
  if (uVar2 == *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x40) * -2) {
    if (uVar3 == 0) {
      uVar3 = *(uint *)(param_1 + 0x1c);
    }
    *param_2 = uVar2;
    param_2[1] = uVar3 - 1;
    iVar1 = FUN_0e05e2d4(param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (iVar1 == 0) {
      uVar3 = *(uint *)(param_1 + 0xc);
      *param_2 = *(uint *)(param_1 + 8);
      param_2[1] = uVar3;
    }
    else {
      *param_2 = local_18;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e3b0. Types and names are inferred; NOT original source. */

int FUN_0e05e3b0(int *param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                uint *param_7,int *param_8)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  byte local_41;
  int local_40;
  int iStack_3c;
  undefined4 local_38;
  uint local_34;
  uint uStack_30;
  uint uStack_2c;
  
  iVar4 = -1;
  local_40 = param_3;
  iStack_3c = param_4;
  do {
    while( true ) {
      iVar2 = iStack_3c;
      iVar1 = local_40;
      iVar3 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                        (param_1[0xe],iStack_3c * param_1[6] + *param_1 + local_40,&local_38,0x10);
      if (iVar3 != 0) {
        return iVar3;
      }
      uVar6 = FUN_0e05e350(param_1,&local_40);
      if ((int)uVar6 != 0) {
        return (int)uVar6;
      }
      if (local_34 == param_2) break;
      if (iStack_3c == param_6 && local_40 == param_5) goto LAB_0e05e452;
    }
    if (iVar4 < 0 || iVar2 != iVar4) {
      iVar4 = FUN_0e05e0d4(param_1,(int)((ulonglong)uVar6 >> 0x20),iVar1,iVar2,&local_41);
      if (iVar4 != -2) {
        if (iVar4 != 0) {
          return iVar4;
        }
        goto LAB_0e05e438;
      }
      local_41 = 0;
      uVar5 = 0;
    }
    else {
LAB_0e05e438:
      uVar5 = (uint)local_41;
    }
    if (((local_38 >> 8 & 0xff) == uVar5) &&
       (uVar5 = FUN_0e05d23c(0xff,(int)&local_38 + 1,0xf), (local_38 & 0xff) == uVar5)) {
      iVar4 = 1;
      goto LAB_0e05e456;
    }
    iVar4 = iVar2;
  } while (iStack_3c != param_6 || local_40 != param_5);
LAB_0e05e452:
  iVar4 = 0;
LAB_0e05e456:
  *param_7 = local_38;
  param_7[3] = uStack_2c;
  param_7[1] = local_34;
  param_7[2] = uStack_30;
  *param_8 = iVar1;
  param_8[1] = iVar2;
  return iVar4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e4a8. Types and names are inferred; NOT original source. */

void FUN_0e05e4a8(int *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  bool bVar13;
  undefined8 uVar14;
  uint local_98;
  int iStack_94;
  uint local_90;
  int iStack_8c;
  undefined1 auStack_88 [8];
  uint local_80;
  byte local_78;
  char local_77;
  ushort local_76;
  undefined4 local_74;
  uint local_70;
  undefined1 auStack_68 [16];
  undefined1 uStack_58;
  undefined1 local_57;
  undefined1 local_48;
  char local_47 [7];
  int local_40;
  undefined4 local_3c;
  
  uVar14 = FUN_0e05e0d4(param_1,param_2,param_1[2],param_1[3],param_1 + 8);
  iVar11 = (int)uVar14;
  if (iVar11 == -2) {
    uVar14 = FUN_0e05e13c(param_1,(int)((ulonglong)uVar14 >> 0x20),param_1[2],param_1[3]);
    if ((int)uVar14 != 0) {
      return;
    }
    iVar11 = FUN_0e05e0d4(param_1,(int)((ulonglong)uVar14 >> 0x20),param_1[2],param_1[3],param_1 + 8
                         );
  }
  if (iVar11 == 0) {
    iVar11 = param_1[3] + 1;
    cVar1 = (char)param_1[8];
    if (iVar11 == param_1[7]) {
      iVar11 = 0;
    }
    uVar6 = param_1[0x10];
    uVar7 = param_1[6] - uVar6;
    iVar10 = iVar11 - (uint)((uint)param_1[6] < uVar6);
    local_98 = uVar7;
    iStack_94 = iVar10;
    iVar2 = FUN_0e05e2d4(param_1,uVar6,uVar7,iVar10,&uStack_58,auStack_88);
    if (-1 < iVar2) {
      if (iVar2 != 0) {
        uVar6 = uVar7 + param_1[0x10] * -2;
        local_98 = local_80;
        iVar2 = iVar10 - (uint)(uVar7 < (uint)(param_1[0x10] * 2));
        *(undefined1 *)(param_1 + 8) = local_57;
        iStack_94 = iVar10;
        do {
          while( true ) {
            iVar10 = iStack_94;
            uVar7 = local_98;
            iVar3 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                              (param_1[0xe],iStack_94 * param_1[6] + *param_1 + local_98,&local_78,
                               0x10);
            if (iVar3 != 0) {
              return;
            }
            iVar3 = FUN_0e05e350(param_1,&local_98);
            if (iVar3 != 0) {
              return;
            }
            if ((((char)param_1[8] == local_77) &&
                (uVar4 = FUN_0e05d23c(0xff,&local_77,0xf), local_78 == uVar4)) && (local_76 != 0))
            break;
LAB_0e05e552:
            if (iVar2 == iVar10 && uVar6 == uVar7) goto LAB_0e05e688;
          }
          local_90 = uVar7;
          iStack_8c = iVar10;
          iVar3 = FUN_0e05e3b0(param_1,local_74,param_1[2],param_1[3],param_1[2],param_1[3],
                               auStack_68,&local_90);
          if (iVar3 < 0) {
            return;
          }
          if (iStack_8c != iVar10 || local_90 != uVar7) goto LAB_0e05e552;
          uVar4 = (uint)local_76;
          if (8 < uVar4) {
            iVar8 = *(int *)param_1[0xf];
            uVar12 = local_70;
            iVar3 = iVar10;
            local_70 = param_1[4];
            do {
              uVar9 = -iVar8 & 0x20U;
              if (uVar4 <= (-iVar8 & 0x20U)) {
                uVar9 = uVar4;
              }
              iVar5 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                                (param_1[0xe],iVar3 * param_1[6] + *param_1 + uVar12,&local_48,uVar9
                                );
              if (iVar5 != 0) {
                return;
              }
              iVar5 = FUN_0e05dfa4(param_1,&local_48,uVar9);
              if (iVar5 != 0) {
                return;
              }
              bVar13 = CARRY4(uVar9,uVar12);
              uVar12 = uVar9 + uVar12;
              iVar3 = iVar3 + (uint)bVar13;
              uVar4 = uVar4 - uVar9;
            } while (uVar4 != 0);
          }
          local_77 = cVar1;
          local_78 = FUN_0e05d23c(0xff,&local_77,0xf);
          iVar3 = FUN_0e05dfe0(param_1,&local_78);
          if (iVar3 != 0) {
            return;
          }
        } while (iVar2 != iVar10 || uVar6 != uVar7);
      }
LAB_0e05e688:
      *(char *)(param_1 + 8) = cVar1;
      local_40 = param_1[4];
      local_47[3] = -1;
      local_47[4] = -1;
      local_47[5] = -1;
      local_47[6] = -1;
      local_3c = 0xffffffff;
      local_47[1] = '\0';
      local_47[2] = '\0';
      local_47[0] = cVar1;
      local_48 = FUN_0e05d23c(0xff,local_47,0xf);
      uVar14 = FUN_0e05dfe0(param_1,&local_48);
      if ((int)uVar14 == 0) {
        FUN_0e05e13c(param_1,(int)((ulonglong)uVar14 >> 0x20),0,iVar11);
        return;
      }
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05e6d4. Types and names are inferred; NOT original source. */

int FUN_0e05e6d4(int *param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  bool bVar11;
  undefined8 uVar12;
  byte *pbVar13;
  undefined1 *puVar14;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  byte local_78;
  char local_77;
  short local_76;
  byte local_68;
  char local_67 [15];
  undefined1 auStack_58 [16];
  byte local_48;
  undefined1 local_47;
  short local_46;
  int local_44;
  uint local_3c;
  byte local_38;
  undefined1 local_37;
  short local_36;
  int local_34;
  int local_30;
  undefined4 local_2c;
  
  piVar8 = param_1 + 9;
  FUN_0e06cd9c(piVar8);
  uVar12 = (**(code **)(*(int *)(param_1[0xe] + 8) + 0xc))();
  puVar1 = (uint *)uVar12;
  param_1[0xf] = (int)puVar1;
  if (puVar1 == (uint *)0x0) {
    return -0x16;
  }
  uVar5 = *puVar1;
  if (uVar5 < 2) {
    uVar5 = 0x10;
  }
  else {
    uVar5 = -uVar5 & uVar5 + 0xf;
  }
  param_1[0x10] = uVar5;
  if (0x1f < *puVar1 - 1) {
    return -0x16;
  }
  if ((uint)param_1[7] < 2) {
    return -0x16;
  }
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  FUN_0e06cdac(piVar8,(int)((ulonglong)uVar12 >> 0x20),0xffffffff,0xffffffff);
  if (param_1[7] == 0) {
LAB_0e05e7e0:
    FUN_0e06cea8(piVar8);
    return -0x86;
  }
  puVar14 = auStack_58;
  uVar5 = 0;
  uVar9 = 0;
  pbVar13 = &local_48;
  bVar11 = false;
  do {
    uVar7 = param_1[6];
    uVar3 = param_1[0x10] * 2;
    uVar6 = uVar9;
    if (uVar7 <= uVar3 && uVar3 - uVar7 != 0) {
      uVar6 = uVar9 - 1;
    }
    uVar7 = uVar7 + param_1[0x10] * -2;
    local_88 = uVar7;
    local_84 = uVar6;
    iVar2 = FUN_0e05e2d4(param_1,uVar3,uVar7,uVar6,pbVar13,puVar14);
    if (iVar2 < 0) goto LAB_0e05e7ee;
    *(undefined1 *)(param_1 + 8) = local_47;
    if (iVar2 == 1) {
      uVar5 = uVar5 + 1;
      if ((local_3c & 0xff00) == 0x4200) {
        if ((local_3c & 0xff) != 1) {
          iVar2 = -0x7b;
          goto LAB_0e05e9f0;
        }
        bVar11 = true;
      }
      local_84 = uVar6 + 1;
      if (uVar6 + 1 == param_1[7]) {
        local_84 = 0;
      }
      local_88 = uVar7;
      iVar2 = FUN_0e05e2d4(param_1,param_1[7],uVar7,local_84,pbVar13,puVar14);
      if (iVar2 < 0) goto LAB_0e05e7ee;
      *(undefined1 *)(param_1 + 8) = local_47;
      if (iVar2 == 0) {
        uVar6 = param_1[7];
        if (uVar5 == uVar6) goto LAB_0e05e7de;
        goto LAB_0e05e802;
      }
    }
    uVar6 = param_1[7];
    uVar9 = uVar9 + 1;
  } while (uVar9 < uVar6);
  if (uVar5 == uVar6) {
LAB_0e05e7de:
    if (!bVar11) goto LAB_0e05e7e0;
  }
LAB_0e05e802:
  if (uVar9 == uVar6) {
    uVar12 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                       (param_1[0xe],
                        (local_84 - (local_88 < (uint)param_1[0x10])) * param_1[6] +
                        *param_1 + (local_88 - param_1[0x10]),&local_68,0x10);
    uVar9 = local_84;
    uVar5 = local_88;
    uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
    iVar2 = (int)uVar12;
    if (iVar2 != 0) goto LAB_0e05e7ee;
    if ((char)param_1[8] == local_67[0]) {
      uVar12 = FUN_0e05d23c(0xff,local_67,0xf);
      uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
      if ((uint)local_68 != (uint)uVar12) goto LAB_0e05e94c;
    }
    else {
LAB_0e05e94c:
      local_84 = uVar9 + 1;
      uVar9 = local_84;
      local_88 = uVar5;
      if (local_84 == param_1[7]) {
        local_84 = 0;
        uVar9 = 0;
      }
    }
    iVar2 = FUN_0e05e280(param_1,uVar4,uVar5,uVar9,pbVar13,puVar14);
    if (iVar2 != 0) goto LAB_0e05e7ee;
    uVar12 = FUN_0e05d23c(0xff,&local_47,0xf);
    if ((((uint)local_48 == (uint)uVar12) && (local_46 == -1)) && (local_44 == -1)) {
      if (((local_3c & 0xff00) == 0x4200) && ((local_3c & 0xff) != 1)) {
        FUN_0e06cea8(piVar8);
        return -0x7b;
      }
    }
    else {
      iVar2 = FUN_0e05e13c(param_1,(int)((ulonglong)uVar12 >> 0x20),uVar5,uVar9);
      if (iVar2 != 0) goto LAB_0e05e7ee;
    }
    iVar2 = FUN_0e05e0d4(param_1,param_1 + 8,uVar5,uVar9,param_1 + 8);
    if (iVar2 == -2) {
      *(undefined1 *)(param_1 + 8) = 0;
    }
    else if (iVar2 != 0) goto LAB_0e05e7ee;
  }
  iVar2 = FUN_0e05e018(param_1,&local_88,&local_80);
  if (iVar2 == 0) {
    param_1[5] = local_7c;
    param_1[2] = local_88;
    param_1[3] = local_84;
    param_1[4] = local_80;
    uVar5 = local_84;
    uVar9 = local_88;
    if (local_7c < local_84 || local_84 - local_7c < (uint)(local_80 <= local_88)) {
      do {
        iVar2 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                          (param_1[0xe],uVar5 * param_1[6] + *param_1 + uVar9,&local_78,0x10);
        if (iVar2 != 0) goto LAB_0e05e7ee;
        if (((char)param_1[8] != local_77) ||
           (uVar5 = FUN_0e05d23c(0xff,&local_77,0xf), local_78 != uVar5)) {
          uVar6 = param_1[0x10];
          uVar5 = param_1[3];
          break;
        }
        uVar5 = param_1[2];
        uVar3 = param_1[5];
        if ((param_1[3] == uVar3 && uVar5 == param_1[4]) && (local_76 != 0)) {
          iVar2 = -0x1d;
          goto LAB_0e05e9f0;
        }
        uVar6 = param_1[0x10];
        uVar9 = uVar5 - uVar6;
        uVar5 = param_1[3] - (uint)(uVar5 < uVar6);
        param_1[2] = uVar9;
        param_1[3] = uVar5;
      } while (uVar3 < uVar5 || uVar5 - uVar3 < (uint)((uint)param_1[4] <= uVar9));
    }
    else {
      uVar6 = param_1[0x10];
    }
    local_88 = param_1[6] + uVar6 * -2;
    local_84 = uVar5 + (uVar6 * 2 <= (uint)param_1[6]);
    if (local_84 == param_1[7]) {
      local_84 = 0;
    }
    iVar2 = FUN_0e05e2d4(param_1);
    if (-1 < iVar2) {
      uVar6 = param_1[2];
      uVar5 = param_1[6];
      iVar10 = param_1[3];
      uVar9 = param_1[0x10];
      if (iVar2 != 1) {
LAB_0e05e89e:
        if (uVar6 == uVar5 + uVar9 * -3) {
          local_30 = param_1[4];
          local_36 = 0;
          local_37 = (undefined1)param_1[8];
          local_34 = -1;
          local_2c = 0xffffffff;
          local_38 = FUN_0e05d23c(0xff,&local_37,0xf);
          iVar2 = FUN_0e05dfe0(param_1,&local_38);
LAB_0e05e9f0:
          FUN_0e06cea8(piVar8);
          if (iVar2 != 0) {
            return iVar2;
          }
        }
        else {
          FUN_0e06cea8(piVar8);
        }
        *(undefined1 *)((int)param_1 + 0x21) = 1;
        return 0;
      }
      uVar7 = uVar9 + uVar6;
      uVar3 = uVar5 + uVar9 * -2;
      uVar9 = iVar10 + (uint)CARRY4(uVar9,uVar6);
      *(undefined1 *)(param_1 + 8) = local_47;
      local_88 = uVar7;
      local_84 = uVar9;
      if (uVar7 < uVar3) {
        do {
          local_88 = uVar7;
          local_84 = uVar9;
          iVar2 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                            (param_1[0xe],uVar9 * uVar5 + *param_1 + uVar7,&local_38,0x10,pbVar13,
                             puVar14);
          if (iVar2 != 0) goto LAB_0e05e7ee;
          uVar12 = FUN_0e05d23c(0xff,&local_37,0xf);
          uVar5 = (uint)((ulonglong)uVar12 >> 0x20);
          if ((((uint)local_38 == (uint)uVar12) && (local_36 == 0)) && (local_34 == -1)) break;
          uVar6 = param_1[0x10];
          uVar5 = param_1[6];
          bVar11 = CARRY4(uVar6,uVar7);
          uVar7 = uVar6 + uVar7;
          uVar9 = uVar9 + bVar11;
          local_88 = uVar7;
          local_84 = uVar9;
        } while (uVar7 < uVar5 + uVar6 * -2);
        uVar6 = param_1[2];
        iVar10 = param_1[3];
        uVar3 = uVar5;
      }
      iVar2 = FUN_0e05e13c(param_1,uVar3,uVar6,iVar10);
      if (iVar2 == 0) {
        param_1[4] = 0;
        param_1[2] = param_1[6] + param_1[0x10] * -3;
        param_1[5] = param_1[3];
        iVar2 = FUN_0e05e4a8(param_1);
        if (iVar2 == 0) {
          uVar5 = param_1[6];
          uVar9 = param_1[0x10];
          uVar6 = param_1[2];
          goto LAB_0e05e89e;
        }
      }
    }
  }
LAB_0e05e7ee:
  FUN_0e06cea8(piVar8);
  return iVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05eb1c. Types and names are inferred; NOT original source. */

uint FUN_0e05eb1c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 uStack_2c;
  
  if (*(char *)(param_1 + 0x21) == '\0') {
    return 0xfffffff3;
  }
  uVar7 = **(uint **)(param_1 + 0x3c);
  uVar5 = param_4;
  if (1 < uVar7) {
    uVar5 = (param_4 + uVar7) - 1 & -uVar7;
  }
  uVar7 = *(uint *)(param_1 + 0x40);
  if ((*(int *)(param_1 + 0x18) + uVar7 * -5 < param_4) || (0xffff < param_4)) {
LAB_0e05ec6a:
    uVar5 = 0xffffffea;
  }
  else {
    uVar9 = uVar5;
    if (param_4 == 0) {
      if (uVar5 != 0) {
        uVar9 = uVar7;
      }
    }
    else {
      if (param_3 == 0) goto LAB_0e05ec6a;
      if ((uVar5 != 0) && (uVar9 = uVar7, 8 < param_4)) {
        uVar9 = uVar5 + uVar7;
      }
    }
    FUN_0e06cdac(param_1 + 0x24,uVar7 * 5,0xffffffff,0xffffffff);
    if (*(int *)(param_1 + 0x1c) != 0) {
      iVar8 = 0;
      do {
        uVar7 = *(uint *)(param_1 + 8);
        uVar5 = *(uint *)(param_1 + 0xc);
        iVar8 = iVar8 + 1;
        if (uVar7 != 0) {
          uVar4 = *(uint *)(param_1 + 0x10);
          uVar6 = *(int *)(param_1 + 0x14) + (uint)CARRY4(uVar9,uVar4);
          bVar10 = uVar9 + uVar4 <= uVar7;
          uVar1 = uVar5 - uVar6;
          bVar2 = uVar6 < uVar5;
          uVar5 = (uVar5 - uVar6) - (uint)!bVar10;
          if (bVar2 || uVar1 < bVar10) {
            if (uVar7 == *(uint *)(param_1 + 0x40)) {
              if (param_4 != 0) goto LAB_0e05ebb8;
              local_38 = (uint)*(byte *)(param_1 + 0x20) << 8;
              local_30 = 0;
              uStack_2c = 0;
              local_34 = param_2;
LAB_0e05ec58:
              uVar3 = FUN_0e05d23c(0xff,(int)&local_38 + 1,0xf);
              local_38 = CONCAT31(local_38._1_3_,uVar3);
            }
            else {
              local_30 = 0;
              uStack_2c = 0;
              local_38 = (uint)CONCAT21((short)param_4,*(undefined1 *)(param_1 + 0x20)) << 8;
              if (param_4 < 9) {
                local_34 = param_2;
                if (param_4 - 1 < 8) {
                  FUN_0e06f35c(&local_30,param_3,param_4);
                }
                goto LAB_0e05ec58;
              }
              local_34 = param_2;
              local_30 = uVar4;
              uVar3 = FUN_0e05d23c(0xff,(int)&local_38 + 1,0xf);
              local_38 = CONCAT31(local_38._1_3_,uVar3);
              uVar5 = FUN_0e05dfa4(param_1,param_3,param_4);
              if (uVar5 != 0) goto LAB_0e05ebc4;
            }
            uVar5 = FUN_0e05dfe0(param_1,&local_38);
            if (uVar5 == 0) {
              uVar5 = param_4;
            }
            goto LAB_0e05ebc4;
          }
        }
LAB_0e05ebb8:
        uVar5 = FUN_0e05e1bc(param_1,uVar5);
        if ((uVar5 != 0) || (uVar5 = FUN_0e05e4a8(param_1), uVar5 != 0)) goto LAB_0e05ebc4;
      } while (*(int *)(param_1 + 0x1c) != iVar8);
    }
    uVar5 = 0xffffffe4;
LAB_0e05ebc4:
    FUN_0e06cea8(param_1 + 0x24);
  }
  return uVar5;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ec88. Types and names are inferred; NOT original source. */

uint FUN_0e05ec88(int *param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_40;
  int local_3c;
  undefined1 auStack_38 [2];
  ushort local_36;
  int local_34;
  int local_30 [3];
  
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    uVar1 = 0xfffffff3;
  }
  else {
    iVar2 = param_1[2];
    local_3c = param_1[3];
    uVar3 = 0;
    local_40 = iVar2;
    iVar4 = local_3c;
    while( true ) {
      uVar1 = FUN_0e05e3b0(param_1,param_2,local_40,local_3c,iVar2,iVar4,auStack_38,&local_40);
      iVar4 = local_3c;
      uVar3 = uVar3 + 1;
      if ((int)uVar1 < 0) break;
      if (uVar1 == 0) {
        return 0xfffffffe;
      }
      uVar1 = FUN_0e05e350(param_1,&local_40);
      if (uVar1 != 0) {
        return uVar1;
      }
      if (param_5 < uVar3) {
        if (local_34 != param_2) {
          return 0xfffffffe;
        }
        uVar1 = (uint)local_36;
        if (uVar1 == 0) {
          return 0xfffffffe;
        }
        if (uVar1 < 9) {
          if (param_3 != 0) {
            if (uVar1 <= param_4) {
              param_4 = uVar1;
            }
            FUN_0e06f35c(param_3,local_30,param_4);
          }
        }
        else if (param_3 != 0) {
          if (uVar1 <= param_4) {
            param_4 = uVar1;
          }
          uVar3 = (*(code *)**(undefined4 **)(param_1[0xe] + 8))
                            (param_1[0xe],iVar4 * param_1[6] + *param_1 + local_30[0],param_3,
                             param_4);
          if (uVar3 != 0) {
            return uVar3;
          }
        }
        return uVar1;
      }
      iVar2 = param_1[2];
      iVar4 = param_1[3];
    }
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ed64. Types and names are inferred; NOT original source. */

uint FUN_0e05ed64(void)

{
  uint uVar1;
  uint in_r3;
  
  uVar1 = FUN_0e05ec88();
  if ((-1 < (int)uVar1) && (in_r3 <= uVar1)) {
    uVar1 = in_r3;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ed80. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05ed80(int param_1)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)(param_1 + 8);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e05ed8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE)();
      return uVar1;
    }
    return 0;
  }
  return 0xfffffffb;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ed9c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05ed9c(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    return 0xffffffea;
  }
  if (param_3 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) {
      *param_2 = param_1;
                    /* WARNING: Could not recover jumptable at 0x0e05edb4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(iVar2 + 0xc))(param_1,param_2 + 1);
      return uVar1;
    }
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05edcc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05edcc(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffea;
  }
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return 0xfffffffe;
  }
  if (*(int *)(iVar1 + 8) == 0) {
    return 0xfffffffb;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(iVar1 + 8) + 8);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e05edea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(iVar1,param_1[1],param_2,param_3);
    return uVar2;
  }
  return 0xfffffffb;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05ee68. Types and names are inferred; NOT original source. */

uint * FUN_0e05ee68(int *param_1,uint param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = param_1[2];
  if (param_2 < uVar4) {
    iVar3 = *param_1;
    iVar2 = param_1[1];
    puVar5 = (uint *)(iVar2 * param_2 + iVar3);
    if (param_3 == (uint *)0x0) {
      return puVar5 + 1;
    }
    if (param_4 != 0) {
      FUN_0e067378(puVar5,4);
      DataMemoryBarrier(0x1b);
      iVar3 = *param_1;
      iVar2 = param_1[1];
      uVar4 = param_1[2];
    }
    uVar1 = *puVar5;
    if ((uVar1 <= iVar2 * uVar4 - 4) && (uVar1 + 4 + (int)puVar5 <= iVar3 + iVar2 * uVar4)) {
      *param_3 = uVar1;
      puVar5 = puVar5 + 1;
      if (param_4 == 0) {
        return puVar5;
      }
      FUN_0e067378(puVar5);
      DataMemoryBarrier(0x1b);
      return puVar5;
    }
  }
  return (uint *)0x0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05eee4. Types and names are inferred; NOT original source. */

int FUN_0e05eee4(int *param_1,int *param_2,int *param_3,undefined4 param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  int local_30;
  int local_2c [2];
  
  iVar5 = *param_1;
  bVar1 = false;
  uVar3 = (*param_2 + 3 + *(uint *)(iVar5 + 0x20)) / *(uint *)(iVar5 + 0x20);
  while (uVar6 = FUN_0e05d988(*(undefined4 *)(iVar5 + 0x28),uVar3,&local_30), iVar2 = (int)uVar6,
        iVar2 == -0x1c) {
    if (param_5 == 0 && param_6 == 0) {
      if (bVar1) {
        FUN_0e06d0d0(param_1 + 0x27);
      }
      goto LAB_0e05efa6;
    }
    iVar2 = FUN_0e06d118(param_1 + 0x27,(int)((ulonglong)uVar6 >> 0x20),param_5,param_6);
    if (iVar2 < 0) {
      if (bVar1) {
        FUN_0e06d0d0(param_1 + 0x27);
      }
      if (iVar2 != -0x1c) goto LAB_0e05efb8;
      goto LAB_0e05efa6;
    }
    bVar1 = true;
  }
  if (bVar1) {
    FUN_0e06d0d0(param_1 + 0x27);
  }
  if (iVar2 < 0) {
LAB_0e05efb8:
    if (iVar2 != -0x16) {
      return iVar2;
    }
LAB_0e05efa6:
    local_30 = -0xc;
  }
  else {
    if (*param_2 == 0) {
      uVar3 = local_30 + 1;
      local_2c[0] = 0;
      if (uVar3 < *(uint *)(iVar5 + 0x24)) {
        do {
          FUN_0e05d934(*(undefined4 *)(iVar5 + 0x28),uVar3,local_2c);
          if (local_2c[0] != 0) break;
          uVar3 = uVar3 + 1;
        } while (uVar3 < *(uint *)(iVar5 + 0x24));
        uVar3 = uVar3 - local_30;
      }
      else {
        uVar3 = 1;
      }
    }
    iVar4 = *(int *)(iVar5 + 0x20) * uVar3 + -4;
    *param_2 = iVar4;
    iVar2 = *(int *)(iVar5 + 0x1c);
    iVar5 = *(int *)(iVar5 + 0x20) * local_30;
    *(int *)(iVar2 + iVar5) = iVar4;
    *param_3 = iVar2 + iVar5 + 4;
  }
  return local_30;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05efe4. Types and names are inferred; NOT original source. */

uint FUN_0e05efe4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  
  uVar1 = FUN_0e05eee4(*(undefined4 *)(param_1 + 0x10),param_4,param_3,param_5,param_5,param_6);
  return uVar1 & (int)uVar1 >> 0x1f;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f0d0. Types and names are inferred; NOT original source. */

int FUN_0e05f0d0(int param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  
  if (3 < param_2) {
    return 0;
  }
  uVar4 = (uint)*(byte *)(param_2 + param_1 + 0xec);
  if (uVar4 < 4) {
    iVar6 = uVar4 * 0x10;
    puVar2 = (uint *)(iVar6 + 0xb0 + param_1);
    uVar1 = *puVar2 & 0xff;
    if (uVar1 == 3) {
      if (*(int *)(param_1 + iVar6 + 0xb4) == 0) goto LAB_0e05f118;
    }
    else if (uVar1 == 2) {
      *puVar2 = 3;
      iVar3 = *(int *)(param_1 + uVar4 * 0x10 + 0xac);
      pcVar5 = *(code **)(iVar3 + 8);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(*(undefined4 *)(iVar3 + 0x14));
      }
LAB_0e05f118:
      return param_1 + iVar6 + 0xac;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f158. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05f158(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  piVar1 = *(int **)(param_1 + 0x10);
  if (DAT_230071e7 == '\0') {
    FUN_0e06d524(&DAT_23002250);
    FUN_0e06d530(&DAT_23002250,&DAT_23010800,0x200,0xffffffff,0);
    DAT_230071e7 = '\x01';
  }
  *piVar1 = iVar2;
  *(bool *)(piVar1 + 0x3f) = *(uint *)(iVar2 + 0x10) < *(uint *)(iVar2 + 0x1c);
  FUN_0e06cd9c(piVar1 + 0x1e);
  FUN_0e06d3f0(piVar1 + 0x23,&LAB_0e05f618_1);
  FUN_0e06d0b4(piVar1 + 0x27,0,1);
  piVar1[0x3c] = -1;
  piVar1[0x3d] = -1;
  piVar1[0x3b] = -1;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f214. Types and names are inferred; NOT original source. */

uint FUN_0e05f214(int *param_1,int param_2,undefined1 param_3,undefined1 param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  iVar1 = *param_1;
  uVar2 = (uint)(param_2 - *(int *)(iVar1 + 0x10)) / *(uint *)(iVar1 + 0x14);
  if ((uVar2 < *(uint *)(iVar1 + 0x18)) &&
     (param_2 == uVar2 * *(uint *)(iVar1 + 0x14) + *(int *)(iVar1 + 0x10) + 4)) {
    if (-1 < (int)uVar2) {
      local_1a = (undefined1)uVar2;
      local_1c = param_3;
      local_1b = param_4;
      FUN_0e06cdac(param_1 + 0x1e,param_2,0xffffffff,0xffffffff);
      uVar2 = FUN_0e05fa4c(iVar1,param_1 + 2,&local_1c,3);
      FUN_0e06cea8(param_1 + 0x1e);
    }
    return uVar2;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f284. Types and names are inferred; NOT original source. */

uint FUN_0e05f284(int param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined2 local_1c;
  undefined1 local_1a;
  
  piVar4 = *(int **)(param_1 + 0x10);
  iVar3 = *piVar4;
  uVar2 = *(uint *)(iVar3 + 0x14);
  uVar1 = (uint)(param_3 - *(int *)(iVar3 + 0x10)) / uVar2;
  if ((uVar1 < *(uint *)(iVar3 + 0x18)) && (param_3 == uVar1 * uVar2 + *(int *)(iVar3 + 0x10) + 4))
  {
    if (-1 < (int)uVar1) {
      local_1a = (undefined1)uVar1;
      local_1c = 1;
      FUN_0e06cdac(piVar4 + 0x1e,uVar2,0xffffffff,0xffffffff);
      uVar1 = FUN_0e05fa4c(iVar3,piVar4 + 2,&local_1c,3);
      FUN_0e06cea8(piVar4 + 0x1e);
    }
    return uVar1;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f2ec. Types and names are inferred; NOT original source. */

uint FUN_0e05f2ec(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  iVar1 = *param_1;
  iVar8 = *(int *)(iVar1 + 0x1c);
  uVar7 = *(uint *)(iVar1 + 0x20);
  uVar4 = (uint)(param_2 - iVar8) / uVar7;
  if (uVar4 < *(uint *)(iVar1 + 0x24)) {
    iVar10 = uVar4 * uVar7;
    iVar5 = uVar7 * *(uint *)(iVar1 + 0x24);
    uVar9 = *(uint *)(iVar8 + iVar10);
    uVar6 = iVar5 + iVar8;
    if (((uVar9 <= iVar5 - 4U) && (uVar9 + 4 + iVar8 + iVar10 <= uVar6)) &&
       (param_2 == iVar8 + iVar10 + 4)) {
      uVar2 = uVar4;
      if (-1 < (int)uVar4) {
        uVar3 = (uVar7 + 3 + uVar9) / uVar7;
        uVar9 = uVar4;
        if (-1 < param_3) {
          uVar6 = (param_3 + 3 + uVar7) / uVar7;
          if (uVar3 < uVar6) {
            return 0xffffffea;
          }
          *(int *)(iVar8 + iVar10) = param_3;
          uVar9 = uVar4 + uVar6;
          uVar3 = uVar3 - uVar6;
        }
        if ((uVar3 != 0) &&
           (uVar2 = FUN_0e05da4c(*(undefined4 *)(iVar1 + 0x28),uVar3,uVar9,uVar6,param_4),
           -1 < (int)uVar2)) {
          FUN_0e06d0d0(param_1 + 0x27);
          return uVar4;
        }
      }
      return uVar2;
    }
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f388. Types and names are inferred; NOT original source. */

uint FUN_0e05f388(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = FUN_0e05f2ec(*(undefined4 *)(param_1 + 0x10),param_3,0xffffffff,param_4,param_4);
  return uVar1 & (int)uVar1 >> 0x1f;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f39c. Types and names are inferred; NOT original source. */

uint FUN_0e05f39c(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar1 = *param_1;
  if (param_2 < *(uint *)(iVar1 + 0x24)) {
    iVar6 = *(int *)(iVar1 + 0x1c);
    uVar3 = *(uint *)(iVar1 + 0x20);
    iVar4 = uVar3 * *(uint *)(iVar1 + 0x24);
    uVar7 = *(uint *)(iVar6 + uVar3 * param_2);
    uVar5 = iVar4 + iVar6;
    if ((uVar7 <= iVar4 - 4U) && (iVar6 + uVar3 * param_2 + uVar7 + 4 <= uVar5)) {
      uVar7 = uVar3 + 3 + uVar7;
      uVar2 = param_2;
      if ((uVar3 <= uVar7) &&
         (uVar2 = FUN_0e05da4c(*(undefined4 *)(iVar1 + 0x28),uVar7 / uVar3,param_2,uVar5,param_4),
         -1 < (int)uVar2)) {
        FUN_0e06d0d0(param_1 + 0x27);
        uVar2 = param_2;
      }
      return uVar2;
    }
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f3fc. Types and names are inferred; NOT original source. */

void FUN_0e05f3fc(undefined1 *param_1,uint param_2,int param_3)

{
  byte bVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 local_20;
  int local_1c;
  
  piVar5 = *(int **)(param_3 + 0x10);
  if ((2 < param_2) && (uVar6 = (uint)(byte)param_1[1], uVar6 < 4)) {
    switch(*param_1) {
    case 0:
      uVar2 = param_1[2];
      iVar7 = *piVar5;
      iVar4 = FUN_0e05ee68(iVar7 + 0x10,uVar2,&local_20,1);
      piVar3 = (int *)FUN_0e05f0d0(piVar5,uVar6);
      if ((iVar4 != 0) && (piVar3 != (int *)0x0)) {
        FUN_0e05d8b4(*(undefined4 *)(iVar7 + 0x2c),uVar2);
        (**(code **)(*piVar3 + 0xc))(iVar4,local_20,*(undefined4 *)(*piVar3 + 0x14));
        FUN_0e05d8f8(*(undefined4 *)(iVar7 + 0x2c),uVar2,&local_1c);
        if (local_1c == 0) {
          FUN_0e05f214(piVar5,iVar4,1);
        }
      }
      break;
    case 1:
      FUN_0e05f39c(piVar5,param_1[2]);
      return;
    case 2:
      bVar1 = param_1[2];
      uVar8 = FUN_0e05ee68(*piVar5 + 0x10,bVar1,&local_1c,1);
      if ((int)uVar8 != 0) {
        FUN_0e06cdac(piVar5 + 0x1e,(int)((ulonglong)uVar8 >> 0x20),0xffffffff,0xffffffff);
        *(ushort *)((int)piVar5 + (uVar6 + 0x78) * 2) = (ushort)bVar1;
        FUN_0e06cea8(piVar5 + 0x1e);
        FUN_0e06d3fc(&DAT_23002250,piVar5 + 0x23);
        return;
      }
      break;
    case 3:
      iVar4 = FUN_0e05f39c(piVar5,param_1[2]);
      if (-1 < iVar4) {
        FUN_0e05f0d0(piVar5,uVar6);
        return;
      }
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f4e8. Types and names are inferred; NOT original source. */

int FUN_0e05f4e8(int *param_1,undefined1 param_2,undefined1 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 extraout_r1;
  uint uVar2;
  int iVar3;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  
  iVar1 = *(int *)(*param_1 + 0x1c);
  iVar3 = param_4 * *(int *)(*param_1 + 0x20);
  *(int *)(iVar1 + iVar3) = param_5;
  DataMemoryBarrier(0x1b);
  FUN_0e067318(iVar1 + iVar3,param_5 + 4);
  iVar1 = *param_1;
  local_22 = (undefined1)param_4;
  local_24 = param_2;
  local_23 = param_3;
  FUN_0e06cdac(param_1 + 0x1e,extraout_r1,0xffffffff,0xffffffff);
  iVar1 = FUN_0e05fa4c(iVar1,param_1 + 2,&local_24,3);
  FUN_0e06cea8(param_1 + 0x1e);
  if (iVar1 < 0) {
    uVar2 = *(uint *)(*param_1 + 0x20);
    if ((!CARRY4(uVar2,param_5 + 3U)) &&
       (iVar3 = FUN_0e05da4c(*(undefined4 *)(*param_1 + 0x28),(uVar2 + param_5 + 3U) / uVar2,param_4
                            ), -1 < iVar3)) {
      FUN_0e06d0d0(param_1 + 0x27);
    }
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f578. Types and names are inferred; NOT original source. */

int FUN_0e05f578(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  iVar1 = FUN_0e05f2ec(uVar2,param_3,param_4);
  if (-1 < iVar1) {
    iVar1 = FUN_0e05f4e8(uVar2,0,*(undefined1 *)(param_2 + 0xc),iVar1,param_4);
    return iVar1;
  }
  FUN_0e05f2ec(uVar2,param_3,0xffffffff);
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f5c4. Types and names are inferred; NOT original source. */

uint FUN_0e05f5c4(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  uint local_20;
  undefined4 local_1c;
  
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  local_20 = param_4;
  uVar1 = FUN_0e05eee4(uVar2,&local_20,&local_1c,param_4,0,0);
  cVar3 = '\x01';
  if (-1 < (int)uVar1) {
    FUN_0e06f35c(local_1c,param_3,param_4);
    uVar1 = FUN_0e05f4e8(uVar2,0,*(undefined1 *)(param_2 + 0xc),uVar1,param_4);
    uVar1 = uVar1 & (int)uVar1 >> 0x20;
    if (cVar3 == '\0') {
      uVar1 = param_4;
    }
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05f808. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e05f8b2) */

void FUN_0e05f808(int param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int local_90;
  int local_8c;
  int local_88;
  char local_84;
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar1 = FUN_0e05fc80(*(undefined4 *)(param_1 + -0x54),0);
  if (iVar1 - 1U < 0x80) {
    uVar2 = FUN_0e05fc80(*(undefined4 *)(param_1 + -0x54),&local_90,0x80);
    if (iVar4 == 2) {
      pcVar3 = *(code **)(*(int *)(param_1 + -0x3c) + 4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(&local_90,uVar2,*(undefined4 *)(param_1 + -0x38));
      }
    }
    else {
      if (uVar2 < 0xd) {
        return;
      }
      if (local_90 != 0x6c316d45) {
        return;
      }
      if (local_8c != 0x72304b31) {
        return;
      }
      if (local_88 != 0x696c336e) {
        return;
      }
      if (local_84 != '4') {
        return;
      }
      if ((code *)**(undefined4 **)(param_1 + -0x3c) != (code *)0x0) {
        (*(code *)**(undefined4 **)(param_1 + -0x3c))(*(undefined4 *)(param_1 + -0x38));
      }
      *(int *)(param_1 + 0x10) = 2;
    }
    iVar1 = FUN_0e05fc80(*(undefined4 *)(param_1 + -0x54),0);
    if (iVar1 != 0) {
      FUN_0e06d3fc(&DAT_23002300,param_1);
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fa4c. Types and names are inferred; NOT original source. */

uint FUN_0e05fa4c(int *param_1,undefined4 *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  
  if (param_2[0x1a] == 2) {
    if (param_4 == 0) {
      uVar2 = 0xffffffc3;
    }
    else {
      iVar1 = FUN_0e06cdac(param_2 + 2,param_2,1000,0);
      if (iVar1 < 0) {
        uVar2 = 0xffffff97;
      }
      else {
        uVar2 = FUN_0e05fb88(*param_2,param_3,param_4 & 0xffff);
        FUN_0e06cea8(param_2 + 2);
        if (-1 < (int)uVar2) {
          if (uVar2 < param_4) {
            return 0xffffffb3;
          }
          pcVar4 = (code *)**(undefined4 **)(*param_1 + 8);
          if (pcVar4 == (code *)0x0) {
            return 0xffffffa8;
          }
          uVar3 = (*pcVar4)(*param_1,param_1[1],0);
          if (uVar3 != 0) {
            return uVar3;
          }
        }
      }
    }
  }
  else {
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fac8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fac8(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_1 == (uint *)0x0) || (uVar1 = *param_1, uVar1 == 0)) {
    return 0xffffffea;
  }
  uVar3 = param_1[1];
  if ((uVar3 != 0) && (uVar4 = param_1[4], uVar4 != 0)) {
    uVar2 = param_1[2];
    if (uVar2 < 4) {
      uVar2 = 4;
    }
    if ((((uVar1 == uVar2 * (uVar1 / uVar2)) &&
         (uVar3 == uVar2 * (uVar3 / uVar2) && (uVar4 & 3) == 0)) && (0xb < param_1[3])) &&
       ((((param_1[3] & 3) == 0 && (uVar1 < uVar3)) && (uVar3 < uVar4)))) {
      if (uVar3 != uVar1 + uVar2) {
        return 0xffffffea;
      }
      return 0;
    }
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fb2c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fb2c(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *param_1;
  iVar1 = FUN_0e05fac8(iVar2);
  if (iVar1 == 0) {
    param_1[1] = 0;
    param_1[2] = 0;
    **(int **)(iVar2 + 4) = param_1[1];
    **(int **)*param_1 = param_1[2];
    DataMemoryBarrier(0x1b);
    FUN_0e067318(*(undefined4 *)(*param_1 + 4),4);
    FUN_0e067318(*(undefined4 *)*param_1,4);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fb70. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fb70(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_0e05fac8(*param_1);
  if (iVar1 == 0) {
    param_1[1] = 0;
    param_1[2] = 0;
    return 0;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fb88. Types and names are inferred; NOT original source. */

uint FUN_0e05fb88(int *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffea;
  }
  if ((param_3 != 0) && (param_2 != 0)) {
    FUN_0e067378(*(undefined4 *)*param_1,4);
    DataMemoryBarrier(0x1b);
    puVar2 = (undefined4 *)*param_1;
    iVar7 = puVar2[4];
    uVar6 = puVar2[3];
    uVar3 = *(uint *)*puVar2;
    uVar5 = param_1[1];
    if ((uVar3 & 3) == 0) {
      if (uVar5 < uVar3) {
        iVar4 = (uVar6 + uVar5) - uVar3;
      }
      else {
        iVar4 = uVar5 - uVar3;
      }
      if (param_3 + 4 <= (uVar6 - 4) - iVar4) {
        *(undefined4 *)(iVar7 + uVar5) = 0;
        *(char *)(iVar7 + uVar5) = (char)(param_3 >> 8);
        *(char *)(iVar7 + uVar5 + 1) = (char)param_3;
        DataMemoryBarrier(0x1b);
        uVar3 = uVar5 + 4;
        FUN_0e067318(iVar7 + uVar5,4);
        if (uVar6 <= uVar3) {
          uVar3 = uVar3 - uVar6 * (uVar3 / uVar6);
        }
        uVar5 = uVar6 - uVar3;
        if (param_3 <= uVar6 - uVar3) {
          uVar5 = param_3;
        }
        uVar1 = FUN_0e06f35c(iVar7 + uVar3,param_2,uVar5);
        FUN_0e067318(uVar1,uVar5);
        if (uVar5 < param_3) {
          FUN_0e06f35c(iVar7,param_2 + uVar5,param_3 - uVar5);
          FUN_0e067318(iVar7,param_3 - uVar5);
        }
        uVar3 = param_3 + 3 + uVar3 & 0xfffffffc;
        if (uVar6 <= uVar3) {
          uVar3 = uVar3 - uVar6 * (uVar3 / uVar6);
        }
        param_1[1] = uVar3;
        **(uint **)(*param_1 + 4) = uVar3;
        DataMemoryBarrier(0x1b);
        FUN_0e067318(*(undefined4 *)(*param_1 + 4),4);
        return param_3;
      }
      return 0xfffffff4;
    }
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fc80. Types and names are inferred; NOT original source. */

uint FUN_0e05fc80(int *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffea;
  }
  FUN_0e067378(*(undefined4 *)(*param_1 + 4),4,param_3,*param_1,param_4);
  DataMemoryBarrier(0x1b);
  iVar1 = *param_1;
  iVar5 = *(int *)(iVar1 + 0x10);
  uVar3 = **(uint **)(iVar1 + 4);
  uVar4 = *(uint *)(iVar1 + 0xc);
  uVar6 = param_1[2];
  if ((uVar3 & 3) != 0) {
    return 0xffffffea;
  }
  uVar2 = 0;
  if (uVar3 != uVar6) {
    FUN_0e067378(iVar5 + uVar6,4,*(uint **)(iVar1 + 4),iVar1,param_4);
    uVar2 = (*(ushort *)(iVar5 + uVar6) & 0xff) << 8 | (uint)(*(ushort *)(iVar5 + uVar6) >> 8);
    if (param_2 != 0) {
      if (param_3 < uVar2) {
        return 0xfffffff4;
      }
      if (uVar3 < uVar6) {
        iVar1 = uVar4 - uVar6;
      }
      else {
        iVar1 = -uVar6;
      }
      if (uVar2 + 4 <= uVar3 + iVar1) {
        uVar6 = uVar6 + 4;
        if (uVar4 <= uVar6) {
          uVar6 = uVar6 - uVar4 * (uVar6 / uVar4);
        }
        uVar3 = uVar4 - uVar6;
        if (uVar2 <= uVar4 - uVar6) {
          uVar3 = uVar2;
        }
        FUN_0e067378(iVar5 + uVar6,uVar3);
        FUN_0e06f35c(param_2,iVar5 + uVar6,uVar3);
        if (uVar3 < uVar2) {
          FUN_0e067378(iVar5,uVar2 - uVar3);
          FUN_0e06f35c(param_2 + uVar3,*(undefined4 *)(*param_1 + 0x10),uVar2 - uVar3);
        }
        uVar3 = uVar2 + 3 + uVar6 & 0xfffffffc;
        if (uVar4 <= uVar3) {
          uVar3 = uVar3 - uVar4 * (uVar3 / uVar4);
        }
        param_1[2] = uVar3;
        **(uint **)*param_1 = uVar3;
        DataMemoryBarrier(0x1b);
        FUN_0e067318(*(undefined4 *)*param_1,4);
        return uVar2;
      }
      return 0xfffffff5;
    }
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fd84. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fd84(undefined4 *param_1)

{
  *param_1 = &DAT_0e0700a0;
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fd94. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fd94(uint param_1,undefined4 *param_2)

{
  int iVar1;
  byte *pbVar2;
  
  if (DAT_230004f8 == (byte *)0x0) {
    return 0xfffffff3;
  }
  iVar1 = 0;
  pbVar2 = DAT_230004f8;
  while (iVar1 = iVar1 + 1, *pbVar2 != param_1) {
    pbVar2 = pbVar2 + 0x10;
    if (iVar1 == 4) {
      return 0xfffffffe;
    }
  }
  if ((*(int *)(pbVar2 + 0xc) != 0) && (iVar1 = FUN_0e06c6c0(), iVar1 != 0)) {
    *param_2 = pbVar2;
    return 0;
  }
  return 0xffffffed;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fde8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fde8(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    return 0xffffffea;
  }
  if ((uint)(param_4 + param_2) <= *(uint *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0e05fe0e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)**(undefined4 **)(*(int *)(param_1 + 0xc) + 8))
                      (*(int *)(param_1 + 0xc),param_2 + *(int *)(param_1 + 4));
    return uVar1;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fe20. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fe20(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    return 0xffffffea;
  }
  if ((uint)(param_4 + param_2) <= *(uint *)(param_1 + 8)) {
                    /* WARNING: Could not recover jumptable at 0x0e05fe46. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0xc) + 8) + 4))
                      (*(int *)(param_1 + 0xc),param_2 + *(int *)(param_1 + 4));
    return uVar1;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fe58. Types and names are inferred; NOT original source. */

undefined4 FUN_0e05fe58(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(*(int *)(param_1 + 0xc) + 8) + 0xc))();
  return *puVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fe68. Types and names are inferred; NOT original source. */

undefined1 FUN_0e05fe68(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0xc) + 8) + 0xc))();
  return *(undefined1 *)(iVar1 + 5);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fe78. Types and names are inferred; NOT original source. */

void FUN_0e05fe78(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  FUN_0e05d634("*** Booting nRF Connect SDK v2.9.0-nRF54H20-1-f7069dc707f3 ***\n");
  FUN_0e05d634("*** Using Zephyr OS v3.7.99-d141a610109b ***\n",extraout_r1,extraout_r2,in_r3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e05fe94. Types and names are inferred; NOT original source. */

int FUN_0e05fe94(undefined2 *param_1,int *param_2,int *param_3,int *param_4,char param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84 [18];
  undefined1 auStack_3c [36];
  
  iVar1 = FUN_0e060c1c(&local_98,*(undefined4 *)(param_1 + 6));
  if (iVar1 != 0) {
    return iVar1;
  }
  FUN_0e06bd40(local_84,3,local_98,*(undefined4 *)(param_1 + 6),1);
  iVar1 = FUN_0e06bc34(local_84,3);
  if (iVar1 != 0) {
    iVar1 = FUN_0e06bc08(local_84,3);
    if (((iVar1 == 0) || (iVar1 = FUN_0e06bc08(local_84,*param_1), iVar1 == 0)) ||
       (iVar1 = FUN_0e06bc08(local_84,param_1[1]), iVar1 == 0)) {
      FUN_0e06bc7c(local_84);
    }
    else {
      iVar1 = FUN_0e06bc74(local_84,3);
      if (iVar1 != 0) {
        iVar1 = local_84[0] - local_98;
        if (param_5 == '\0') {
          iVar2 = (**(code **)(param_1 + 2))
                            (local_84[0],*(int *)(param_1 + 6) - iVar1,param_2,&local_9c);
          if (iVar2 != 0) {
LAB_0e060026:
            FUN_0e060c54(local_98);
            return -0x47;
          }
        }
        else {
          uVar3 = param_2[1];
          if ((((uint)(*(int *)(param_1 + 6) - iVar1) < uVar3) || (local_84[0] == 0)) ||
             (*param_2 == 0)) goto LAB_0e060026;
          FUN_0e06f35c(local_84[0],*param_2,uVar3);
          local_9c = uVar3;
        }
        local_94 = local_9c + iVar1;
        iVar1 = FUN_0e060c84(local_98,local_94,&local_90,&local_8c);
        if (iVar1 != 0) {
          if (iVar1 != -0x7a) {
            iVar1 = -5;
          }
          return iVar1;
        }
        thunk_FUN_0e06b300(local_84,3,local_90,local_8c,1,auStack_3c,0);
        iVar1 = FUN_0e06b844(local_84);
        if (iVar1 != 0) {
          iVar1 = FUN_0e06b6a8(local_84,&local_88);
          if (iVar1 == 0) {
            FUN_0e06b940(local_84);
          }
          else {
            iVar1 = FUN_0e06b8dc(local_84);
            if (iVar1 != 0) {
              if (local_88 != 0) {
                FUN_0e060c6c(local_90);
                return local_88;
              }
              uVar3 = local_8c - (local_84[0] - local_90);
              if (param_5 == '\0') {
                iVar1 = (**(code **)(param_1 + 4))(local_84[0],uVar3,param_3,0);
                if (iVar1 == 0) {
LAB_0e05ffe2:
                  if (param_4 != (int *)0x0) {
                    *param_4 = local_90;
                    return 0;
                  }
                  FUN_0e060c6c();
                  return 0;
                }
              }
              else if (((uVar3 <= (uint)param_3[1]) && (*param_3 != 0)) && (local_84[0] != 0)) {
                FUN_0e06f35c(*param_3,local_84[0],uVar3);
                param_3[1] = uVar3;
                goto LAB_0e05ffe2;
              }
              FUN_0e060c6c(local_90);
              return -0x47;
            }
          }
        }
        FUN_0e060c6c(local_90);
        return -0x47;
      }
    }
  }
  FUN_0e060c54(local_98);
  return -0x47;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0601a0. Types and names are inferred; NOT original source. */

void FUN_0e0601a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  
  iVar1 = FUN_0e06b7a4(param_1,0x33);
  if (iVar1 == 0) {
    return;
  }
  FUN_0e06b6a8(param_1,param_2,extraout_r2,param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0601bc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0601bc(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0e06b844();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_0e06b2e8(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_0e06b7a4(param_1,1);
    if ((iVar1 == 0) || (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
      iVar1 = FUN_0e06b2f0(param_1);
      if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,2), iVar1 == 0)) ||
         (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
        iVar1 = FUN_0e06b2f0(param_1);
        if (((iVar1 != 0) && (iVar1 = FUN_0e06b7a4(param_1,3), iVar1 != 0)) &&
           ((iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 != 0 &&
            ((iVar1 = FUN_0e06b6b0(param_1,param_2 + 4), iVar1 != 0 &&
             (iVar1 = FUN_0e06b844(param_1), iVar1 != 0)))))) {
          iVar1 = FUN_0e06b94c(0,5,param_2 + 0x1c,(undefined *)0xe06b6a9,param_1,param_2 + 8,4);
          if (iVar1 == 0) {
            FUN_0e06b940(param_1);
          }
          else {
            iVar1 = FUN_0e06b8dc(param_1);
            if ((((iVar1 != 0) && (iVar1 = FUN_0e06b6a8(param_1,param_2 + 0x20), iVar1 != 0)) &&
                (iVar1 = FUN_0e06b6a8(param_1,param_2 + 0x24), iVar1 != 0)) &&
               (iVar1 = FUN_0e06b7ac(param_1,param_2 + 0x28), iVar1 != 0)) {
              *(undefined1 *)(param_2 + 0x58) = 2;
              FUN_0e06b2f8(param_1);
              goto LAB_0e0603b8;
            }
          }
        }
        iVar1 = FUN_0e06b2f0(param_1);
        if (((iVar1 != 0) && (iVar1 = FUN_0e06b7a4(param_1,4), iVar1 != 0)) &&
           (((iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 != 0 &&
             ((iVar1 = FUN_0e06b7ac(param_1,param_2 + 4), iVar1 != 0 &&
              (iVar1 = FUN_0e06b6b0(param_1,param_2 + 0xc), iVar1 != 0)))) &&
            (iVar1 = FUN_0e06b844(param_1), iVar1 != 0)))) {
          iVar1 = FUN_0e06b94c(0,5,param_2 + 0x24,(undefined *)0xe06b6a9,param_1,param_2 + 0x10,4);
          if (iVar1 == 0) {
            FUN_0e06b940(param_1);
          }
          else {
            iVar1 = FUN_0e06b8dc(param_1);
            if (((iVar1 != 0) && (iVar1 = FUN_0e06b6a8(param_1,param_2 + 0x28), iVar1 != 0)) &&
               (iVar1 = FUN_0e06b7ac(param_1,param_2 + 0x2c), iVar1 != 0)) {
              *(undefined1 *)(param_2 + 0x58) = 3;
              FUN_0e06b2f8(param_1);
              goto LAB_0e0603b8;
            }
          }
        }
        iVar1 = FUN_0e06b2f0(param_1);
        if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,10), iVar1 == 0)) ||
           (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
          iVar1 = FUN_0e06b2f0(param_1);
          if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0xb), iVar1 == 0)) ||
             (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
            iVar1 = FUN_0e06b2f0(param_1);
            if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0xc), iVar1 == 0)) ||
               (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
              iVar1 = FUN_0e06b2f0(param_1);
              if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0xd), iVar1 == 0)) ||
                 (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
                iVar1 = FUN_0e06b2f0(param_1);
                if (((iVar1 != 0) && (iVar1 = FUN_0e06b7a4(param_1,0x12), iVar1 != 0)) &&
                   ((iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 != 0 &&
                    (iVar1 = FUN_0e06b844(param_1), iVar1 != 0)))) {
                  iVar1 = FUN_0e06b94c(0,0x14,param_2 + 0x54,(undefined *)0xe06b6a9,param_1,
                                       param_2 + 4,4);
                  if (iVar1 == 0) {
                    FUN_0e06b940(param_1);
                  }
                  else {
                    iVar1 = FUN_0e06b8dc(param_1);
                    if (iVar1 != 0) {
                      *(undefined1 *)(param_2 + 0x58) = 8;
                      FUN_0e06b2f8(param_1);
                      goto LAB_0e0603b8;
                    }
                  }
                }
                iVar1 = FUN_0e06b2f0(param_1);
                if ((((((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0x13), iVar1 == 0)) ||
                      (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) ||
                     ((iVar1 = FUN_0e06b6a8(param_1,param_2 + 4), iVar1 == 0 ||
                      (iVar1 = FUN_0e06b7ac(param_1,param_2 + 8), iVar1 == 0)))) ||
                    ((iVar1 = FUN_0e06b7ac(param_1,param_2 + 0x10), iVar1 == 0 ||
                     ((iVar1 = FUN_0e06b6a8(param_1,param_2 + 0x18), iVar1 == 0 ||
                      (iVar1 = FUN_0e06b6a8(param_1,param_2 + 0x1c), iVar1 == 0)))))) ||
                   (iVar1 = FUN_0e06b6a8(param_1,param_2 + 0x20), iVar1 == 0)) {
                  iVar1 = FUN_0e06b2f0(param_1);
                  if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0x15), iVar1 == 0)) ||
                     (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
                    iVar1 = FUN_0e06b2f0(param_1);
                    if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0xe), iVar1 == 0)) ||
                       ((iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0 ||
                        (iVar1 = FUN_0e06b6b0(param_1,param_2 + 4), iVar1 == 0)))) {
                      iVar1 = FUN_0e06b2f0(param_1);
                      if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0xf), iVar1 == 0)) ||
                         (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
                        iVar1 = FUN_0e06b2f0(param_1);
                        if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0x28), iVar1 == 0)) ||
                           (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
                          iVar1 = FUN_0e06b2f0(param_1);
                          if (((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0x2b), iVar1 == 0)) ||
                             (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
                            iVar1 = FUN_0e06b2f0(param_1);
                            if (((iVar1 != 0) && (iVar1 = FUN_0e06b7a4(param_1,0x2c), iVar1 != 0))
                               && ((iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 != 0 &&
                                   (iVar1 = FUN_0e06b844(param_1), iVar1 != 0)))) {
                              iVar1 = FUN_0e06b94c(0,3,param_2 + 0x1c,0xe0607c5,param_1,param_2 + 4,
                                                   8);
                              if (iVar1 == 0) {
                                FUN_0e06b940(param_1);
                              }
                              else {
                                iVar1 = FUN_0e06b8dc(param_1);
                                if (iVar1 != 0) {
                                  *(undefined1 *)(param_2 + 0x58) = 0xf;
                                  FUN_0e06b2f8(param_1);
                                  goto LAB_0e0603b8;
                                }
                              }
                            }
                            iVar1 = FUN_0e06b2f0(param_1);
                            if ((((iVar1 == 0) || (iVar1 = FUN_0e06b7a4(param_1,0x32), iVar1 == 0))
                                || (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) ||
                               (iVar1 = FUN_0e06b6b0(param_1,param_2 + 4), iVar1 == 0)) {
                              iVar1 = FUN_0e06b2f0(param_1);
                              if ((iVar1 == 0) ||
                                 (iVar1 = FUN_0e0601a0(param_1,param_2), iVar1 == 0)) {
                                iVar1 = FUN_0e06b2f0(param_1);
                                if ((iVar1 == 0) ||
                                   ((iVar1 = FUN_0e06b7a4(param_1,0x34), iVar1 == 0 ||
                                    (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)))) {
                                  iVar1 = FUN_0e06b2f0(param_1);
                                  if (((iVar1 == 0) ||
                                      (iVar1 = FUN_0e06b7a4(param_1,0x35), iVar1 == 0)) ||
                                     (iVar1 = FUN_0e06b6a8(param_1,param_2), iVar1 == 0)) {
                                    FUN_0e06b2f8(param_1);
                                    goto LAB_0e060392;
                                  }
                                  *(undefined1 *)(param_2 + 0x58) = 0x13;
                                  FUN_0e06b2f8(param_1);
                                }
                                else {
                                  *(undefined1 *)(param_2 + 0x58) = 0x12;
                                  FUN_0e06b2f8(param_1);
                                }
                              }
                              else {
                                *(undefined1 *)(param_2 + 0x58) = 0x11;
                                FUN_0e06b2f8(param_1);
                              }
                            }
                            else {
                              *(undefined1 *)(param_2 + 0x58) = 0x10;
                              FUN_0e06b2f8(param_1);
                            }
                          }
                          else {
                            *(undefined1 *)(param_2 + 0x58) = 0xe;
                            FUN_0e06b2f8(param_1);
                          }
                        }
                        else {
                          *(undefined1 *)(param_2 + 0x58) = 0xd;
                          FUN_0e06b2f8(param_1);
                        }
                      }
                      else {
                        *(undefined1 *)(param_2 + 0x58) = 0xc;
                        FUN_0e06b2f8(param_1);
                      }
                    }
                    else {
                      *(undefined1 *)(param_2 + 0x58) = 0xb;
                      FUN_0e06b2f8(param_1);
                    }
                  }
                  else {
                    *(undefined1 *)(param_2 + 0x58) = 10;
                    FUN_0e06b2f8(param_1);
                  }
                }
                else {
                  *(undefined1 *)(param_2 + 0x58) = 9;
                  FUN_0e06b2f8(param_1);
                }
              }
              else {
                *(undefined1 *)(param_2 + 0x58) = 7;
                FUN_0e06b2f8(param_1);
              }
            }
            else {
              *(undefined1 *)(param_2 + 0x58) = 6;
              FUN_0e06b2f8(param_1);
            }
          }
          else {
            *(undefined1 *)(param_2 + 0x58) = 5;
            FUN_0e06b2f8(param_1);
          }
        }
        else {
          *(undefined1 *)(param_2 + 0x58) = 4;
          FUN_0e06b2f8(param_1);
        }
      }
      else {
        *(undefined1 *)(param_2 + 0x58) = 1;
        FUN_0e06b2f8(param_1);
      }
    }
    else {
      *(undefined1 *)(param_2 + 0x58) = 0;
      FUN_0e06b2f8(param_1);
    }
LAB_0e0603b8:
    uVar2 = FUN_0e06b8dc(param_1);
    return uVar2;
  }
LAB_0e060392:
  FUN_0e06b940(param_1);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0607c4. Types and names are inferred; NOT original source. */

void FUN_0e0607c4(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_r2;
  
  iVar1 = FUN_0e06b6b0();
  if (iVar1 == 0) {
    return;
  }
  FUN_0e06b6b0(param_1,param_2 + 4,extraout_r2,param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06081c. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0e06081c(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0e06bc34(param_1,7);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(char *)(param_2 + 0x3c) == '\0') {
    iVar1 = FUN_0e06bc08(param_1,1);
    if ((((iVar1 == 0) || (iVar1 = FUN_0e06bbe8(param_1,param_2), iVar1 == 0)) ||
        (iVar1 = FUN_0e06bbe8(param_1,param_2 + 4), iVar1 == 0)) ||
       (iVar1 = FUN_0e06bc34(param_1,0xc), iVar1 == 0)) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bcfc(0,6,param_2 + 0x38,&LAB_0e060800_1,param_1,param_2 + 8,8);
    if (iVar1 == 0) {
      FUN_0e06bc7c(param_1);
      goto switchD_0e060838_default;
    }
    iVar1 = FUN_0e06bc74(param_1,0xc);
    goto joined_r0x0e060b40;
  }
  switch(*(char *)(param_2 + 0x3c)) {
  case '\x01':
    iVar1 = FUN_0e06bc08(param_1,2);
    if (((iVar1 == 0) || (iVar1 = FUN_0e06bc2c(param_1,param_2), iVar1 == 0)) ||
       (iVar1 = FUN_0e06bbb0(param_1,param_2 + 8), iVar1 == 0)) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bc2c(param_1,param_2 + 0xc);
    break;
  case '\x02':
    iVar1 = FUN_0e06bc08(param_1,3);
    goto joined_r0x0e060996;
  case '\x03':
    iVar1 = FUN_0e06bc08(param_1,4);
    break;
  case '\x04':
    iVar1 = FUN_0e06bc08(param_1,10);
    if (((((iVar1 == 0) || (iVar1 = FUN_0e06bc2c(param_1,param_2), iVar1 == 0)) ||
         (iVar1 = FUN_0e06bbe8(param_1,param_2 + 8), iVar1 == 0)) ||
        ((iVar1 = FUN_0e06bc2c(param_1,param_2 + 0xc), iVar1 == 0 ||
         (iVar1 = FUN_0e06bc2c(param_1,param_2 + 0x14), iVar1 == 0)))) ||
       (iVar1 = FUN_0e06bbe8(param_1,param_2 + 0x1c), iVar1 == 0)) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bbe8(param_1,param_2 + 0x20);
    break;
  case '\x05':
    iVar1 = FUN_0e06bc08(param_1,0xb);
joined_r0x0e060996:
    if (iVar1 == 0) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bc2c(param_1,param_2);
    break;
  case '\x06':
    iVar1 = FUN_0e06bc08(param_1,0xc);
    if (((iVar1 == 0) || (iVar1 = FUN_0e06bc2c(param_1,param_2), iVar1 == 0)) ||
       (iVar1 = FUN_0e06bbe8(param_1,param_2 + 8), iVar1 == 0)) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bbe8(param_1,param_2 + 0xc);
    break;
  case '\a':
    iVar1 = FUN_0e06bc08(param_1,0xd);
    if ((iVar1 == 0) || (iVar1 = FUN_0e06bc2c(param_1,param_2), iVar1 == 0))
    goto switchD_0e060838_default;
    iVar1 = FUN_0e06bc2c(param_1,param_2 + 8);
    break;
  case '\b':
    iVar1 = FUN_0e06bc08(param_1,0x12);
    break;
  case '\t':
    iVar1 = FUN_0e06bc08(param_1,0x13);
    goto joined_r0x0e060b70;
  case '\n':
    iVar1 = FUN_0e06bc08(param_1,0x15);
    if (((iVar1 == 0) || (iVar1 = FUN_0e06bc2c(param_1,param_2), iVar1 == 0)) ||
       (iVar1 = FUN_0e06bc2c(param_1,param_2 + 8), iVar1 == 0)) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bbb0(param_1,param_2 + 0x10);
    break;
  case '\v':
    iVar1 = FUN_0e06bc08(param_1,0xe);
    goto joined_r0x0e060b50;
  case '\f':
    iVar1 = FUN_0e06bc08(param_1,0xf);
    if ((iVar1 == 0) || (iVar1 = FUN_0e06bbe8(param_1,param_2), iVar1 == 0))
    goto switchD_0e060838_default;
    iVar1 = FUN_0e06bbe8(param_1,param_2 + 4);
    break;
  case '\r':
    iVar1 = FUN_0e06bc08(param_1,0x28);
    if (iVar1 == 0) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bc88(param_1,param_2);
    break;
  case '\x0e':
    iVar1 = FUN_0e06bc08(param_1,0x2b);
    if ((((iVar1 == 0) || (iVar1 = FUN_0e06bbe8(param_1,param_2), iVar1 == 0)) ||
        ((iVar1 = FUN_0e06bbe8(param_1,param_2 + 4), iVar1 == 0 ||
         ((iVar1 = FUN_0e06bbe8(param_1,param_2 + 8), iVar1 == 0 ||
          (iVar1 = FUN_0e06bc88(param_1,param_2 + 0xc), iVar1 == 0)))))) ||
       (iVar1 = FUN_0e06bbe8(param_1,param_2 + 0x10), iVar1 == 0)) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bbe8(param_1,param_2 + 0x14);
    break;
  case '\x0f':
    iVar1 = FUN_0e06bc08(param_1,0x2c);
joined_r0x0e060b50:
    if (iVar1 == 0) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bbe8(param_1,param_2);
    break;
  case '\x10':
    iVar1 = FUN_0e06bc08(param_1,0x32);
    break;
  case '\x11':
    iVar1 = FUN_0e06bc08(param_1,0x33);
joined_r0x0e060b70:
    if (iVar1 == 0) goto switchD_0e060838_default;
    iVar1 = FUN_0e06bbb0(param_1,param_2);
    break;
  case '\x12':
    iVar1 = FUN_0e06bc08(param_1,0x34);
    break;
  case '\x13':
    iVar1 = FUN_0e06bc08(param_1,0x35);
    break;
  default:
    goto switchD_0e060838_default;
  }
joined_r0x0e060b40:
  if (iVar1 != 0) {
    uVar2 = FUN_0e06bc74(param_1,7);
    return uVar2;
  }
switchD_0e060838_default:
  FUN_0e06bc7c(param_1);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060c1c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e060c1c(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 0xffffffea;
  }
  if (DAT_230071e9 == '\0') {
    return 0xfffffff0;
  }
  FUN_0e06bd78(&DAT_0e07267c,param_1,param_2);
  if (*param_1 == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060c54. Types and names are inferred; NOT original source. */

void FUN_0e060c54(undefined4 param_1)

{
  if (DAT_230071e9 == '\0') {
    return;
  }
  FUN_0e06c69c(&DAT_0e07267c,param_1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060c6c. Types and names are inferred; NOT original source. */

void FUN_0e060c6c(undefined4 param_1)

{
  if (DAT_230071e9 == '\0') {
    return;
  }
  FUN_0e06bd58(&DAT_0e07267c,param_1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060c84. Types and names are inferred; NOT original source. */

int FUN_0e060c84(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_1 == 0) {
LAB_0e060cfc:
    iVar1 = -0x16;
  }
  else {
    if ((param_3 == 0) || (param_4 == 0)) {
      iVar1 = -0x16;
    }
    else if (DAT_230071e9 == '\0') {
      iVar1 = -0x10;
    }
    else {
      iVar1 = FUN_0e06c4ac(&DAT_0e07267c,0x10042,param_1,param_2,param_3,param_4);
      if (iVar1 == -0x16) goto LAB_0e060cfc;
      if (iVar1 < -0x15) {
        if (iVar1 == -0x72) {
          return -0x78;
        }
        if (iVar1 == -0x4d) {
          return -0x4d;
        }
        return -5;
      }
      if (iVar1 != -0xe) {
        if (iVar1 == -5) {
          return -5;
        }
        if (iVar1 == 0) {
          return 0;
        }
        return -5;
      }
    }
    FUN_0e06c69c(&DAT_0e07267c,param_1);
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060d10. Types and names are inferred; NOT original source. */

void FUN_0e060d10(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 uVar4;
  
  uVar3 = DAT_23007170;
  if (param_1 == 1) {
    param_4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      param_4 = getCurrentExceptionNumber();
      param_4 = param_4 & 0x1ff;
    }
  }
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06c6e8();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e061198(uVar3,extraout_r1,extraout_r2,param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060d1c. Types and names are inferred; NOT original source. */

void FUN_0e060d1c(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 uVar4;
  
  uVar3 = DAT_23007170;
  if (*param_1 == 1) {
    param_4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      param_4 = getCurrentExceptionNumber();
      param_4 = param_4 & 0x1ff;
    }
  }
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06c6e8(*param_1,param_1);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e061198(uVar3,extraout_r1,extraout_r2,param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060d2c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void vector_2(void)

{
  FUN_0e060d3c();
  if ((-1 < *(char *)(DAT_23007170 + 0xe)) && (DAT_23007170 != DAT_2300717c)) {
    _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060d3c. Types and names are inferred; NOT original source. */

void FUN_0e060d3c(void)

{
  do {
    WaitForInterrupt();
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060d44. Types and names are inferred; NOT original source. */

undefined4 FUN_0e060d44(int param_1,int param_2)

{
  FUN_0e06f35c(param_2 + -8,&DAT_0e06f750,0);
  FUN_0e06f3aa(param_2 + -8,0,8);
  *(int *)(param_1 + 0x84) = param_2 + -0x10;
  return 0x10;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060db0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e060db0(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = _DAT_e000ed28;
  if ((_DAT_e000ed28 & 0x2000000) == 0) {
    uVar2 = 0x1d;
  }
  else {
    uVar2 = 0x1e;
  }
  if ((_DAT_e000ed28 & 0x1000000) != 0) {
    uVar2 = 0x1f;
  }
  if ((_DAT_e000ed28 & 0x100000) != 0) {
    uVar2 = 2;
  }
  if ((_DAT_e000ed28 & 0x80000) != 0) {
    uVar2 = 0x21;
  }
  if ((_DAT_e000ed28 & 0x40000) != 0) {
    uVar2 = 0x22;
  }
  if ((_DAT_e000ed28 & 0x20000) != 0) {
    uVar2 = 0x23;
  }
  _DAT_e000ed28 = ~(~(_DAT_e000ed28 << 0x10) >> 0x10);
  if ((uVar1 & 0x10000) != 0) {
    uVar2 = 0x24;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060e14. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e060e14(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if ((_DAT_e000ed28 & 0x1000) == 0) {
    uVar1 = 0x16;
  }
  else {
    uVar1 = 0x17;
  }
  if ((_DAT_e000ed28 & 0x800) != 0) {
    uVar1 = 0x18;
  }
  if ((int)(_DAT_e000ed28 << 0x16) < 0) {
    if (((int)(_DAT_e000ed28 << 0x10) < 0) && (param_1 != 0)) {
      _DAT_e000ed28 = _DAT_e000ed28 & 0xffff7fff;
    }
    uVar1 = 0x19;
  }
  if ((_DAT_e000ed28 & 0x400) != 0) {
    uVar1 = 0x1a;
  }
  if ((int)(_DAT_e000ed28 << 0x17) < 0) {
    uVar1 = 0x1b;
  }
  else if ((_DAT_e000ed28 & 0x2000) != 0) {
    uVar1 = 0x1c;
  }
  _DAT_e000ed28 = _DAT_e000ed28 | 0xff00;
  *param_2 = 0;
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060e84. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e060e84(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  
  if ((_DAT_e000ed28 & 0x10) == 0) {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0x11;
  }
  if ((_DAT_e000ed28 & 8) != 0) {
    uVar1 = 0x12;
  }
  if ((int)(_DAT_e000ed28 << 0x1e) < 0) {
    if (((int)(_DAT_e000ed28 << 0x18) < 0) && (param_1 != 0)) {
      _DAT_e000ed28 = _DAT_e000ed28 & 0xffffff7f;
    }
    uVar1 = 0x13;
  }
  if ((_DAT_e000ed28 & 1) != 0) {
    uVar1 = 0x14;
  }
  if ((_DAT_e000ed28 & 0x20) != 0) {
    uVar1 = 0x15;
  }
  if ((int)(_DAT_e000ed28 << 0x1a) < 0) {
    _DAT_e000ed24 = _DAT_e000ed24 & 0xffffdfff;
  }
  _DAT_e000ed28 = _DAT_e000ed28 | 0xff;
  *param_2 = 0;
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e060f04. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e060f04(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  char local_31;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint local_14;
  
  puVar4 = (undefined4 *)0x0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar2 = puVar4;
  if (((param_3 & 0xff000000) == 0xff000000) && ((param_3 & 0xc) != 8)) {
    if ((int)(param_3 << 0x1c) < 0) {
      puVar4 = param_2;
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar4 = param_1;
      puVar2 = (undefined4 *)0x1;
    }
  }
  local_31 = '\0';
  switch(_DAT_e000ed04 & 0x1ff) {
  case 3:
    if ((_DAT_e000ed2c & 2) != 0) goto switchD_0e060f46_default;
    uVar3 = 0;
    if (((int)_DAT_e000ed2c < 0) || (uVar3 = 0, (_DAT_e000ed2c & 0x40000000) == 0))
    goto LAB_0e060f54;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    _DAT_e000ed14 = _DAT_e000ed14 & 0xfffffeff;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    if (*(short *)(puVar4[6] + -2) == -0x20fe) {
      uVar3 = *puVar4;
    }
    else if ((_DAT_e000ed28 & 0xff) == 0) {
      if ((_DAT_e000ed28 & 0xff00) == 0) {
        if (_DAT_e000ed28 < 0x10000) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_0e060db0();
        }
      }
      else {
        uVar3 = FUN_0e060e14(1,&local_31);
      }
    }
    else {
      uVar3 = FUN_0e060e84(1,&local_31);
    }
    break;
  case 4:
    uVar3 = FUN_0e060e84(0,&local_31);
    break;
  case 5:
    uVar3 = FUN_0e060e14(0,&local_31);
    break;
  case 6:
    uVar3 = FUN_0e060db0();
    goto LAB_0e060f54;
  default:
switchD_0e060f46_default:
    uVar3 = 0;
    goto LAB_0e060f54;
  }
  if (local_31 != '\0') {
    return;
  }
LAB_0e060f54:
  local_30 = *puVar4;
  uStack_2c = puVar4[1];
  uStack_28 = puVar4[2];
  uStack_24 = puVar4[3];
  local_20 = puVar4[4];
  uStack_1c = puVar4[5];
  uStack_18 = puVar4[6];
  local_14 = puVar4[7];
  if (puVar2 == (undefined4 *)0x0) {
    local_14 = local_14 & 0xfffffe00;
    FUN_0e060d10(uVar3,&local_30);
  }
  else {
    if ((local_14 & 0x1ff) == 0) {
      local_14 = local_14 | 0x1ff;
    }
    FUN_0e060d10(uVar3,&local_30);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061078. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e061078(void)

{
  _DAT_e000ed14 = _DAT_e000ed14 & 0xfffffff7 | 0x410;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061098. Types and names are inferred; NOT original source. */

undefined4 vector_3(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = getMainStackPointer();
  uVar2 = getProcessStackPointer();
  FUN_0e060f04(uVar1,uVar2);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0610ac. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Reset_Handler(void)

{
  char cVar1;
  bool bVar2;
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 extraout_s1;
  undefined8 extraout_d4;
  undefined8 unaff_d14;
  
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setThreadModePrivileged(1);
    bVar2 = (bool)isThreadMode();
    if (bVar2) {
      cVar3 = isUsingMainStack();
      setStackMode(cVar3 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  setMainStackPointerLimit(0);
  setProcStackPointerLimit(0);
  FUN_0e068a44(0);
  _DAT_e000ed94 = 0;
  DataSynchronizationBarrier(0xf);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setMainStackPointer(0x23013640);
  }
  FUN_0e061130(&DAT_23013640);
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(0x40);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setProcessStackPointer(0x23013100);
  }
  cVar3 = isThreadModePrivileged();
  cVar1 = isUsingMainStack();
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setThreadModePrivileged(cVar3 == '\x01');
    bVar2 = (bool)isThreadMode();
    if (bVar2) {
      cVar4 = isUsingMainStack();
      setStackMode(cVar4 == '\x01');
    }
  }
  InstructionSynchronizationBarrier(0xf);
  uVar5 = FUN_0e06132c((cVar1 != '\x01') << 1 | cVar3 != '\x01' | 2);
  vcx3(5,2,unaff_d14,extraout_d4,CONCAT44(extraout_s1,uVar5),0,0x40,0);
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06110c. Types and names are inferred; NOT original source. */

void FUN_0e06110c(void)

{
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061130. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e061130(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableFIQinterrupts(0);
  }
  uVar2 = 0;
  if ((_DAT_e000ed90 & 0xff00) != 0) {
    do {
      _DAT_e000ed98 = uVar2;
      _DAT_e000eda0 = 0;
      uVar2 = _DAT_e000ed98 + 1;
    } while ((_DAT_e000ed90 & 0xffff) >> 8 != _DAT_e000ed98 + 1);
  }
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 0x20;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar3 * 4 + -0x1fff1f00) = 0xffffffff;
  } while (iVar4 != 0x10);
  iVar4 = 0;
  do {
    iVar3 = iVar4 + 0x60;
    iVar4 = iVar4 + 1;
    *(undefined4 *)(iVar3 * 4 + -0x1fff1f00) = 0xffffffff;
  } while (iVar4 != 0x10);
  enableIRQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061198. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e061198(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (DAT_23007170 == param_1) {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getCurrentExceptionNumber();
      uVar4 = uVar4 & 0x1ff;
    }
    if (uVar4 != 0) {
      _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
      _DAT_e000ed24 = _DAT_e000ed24 & 0xffff7fff;
    }
  }
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (-1 < (int)((uint)*(byte *)(param_1 + 0xc) << 0x1f)) {
    if ((int)((uint)*(byte *)(param_1 + 0xd) << 0x1c) < 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      return param_1;
    }
    iVar2 = FUN_0e06db60(param_1,uVar3,1);
    return iVar2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  software_interrupt(2);
  return 4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0611cc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0611cc(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = DAT_23007170;
  *(undefined4 *)(DAT_23007170 + 0x88) = param_1;
  *(undefined4 *)(iVar2 + 0x8c) = 0xfffffff5;
  _DAT_e000ed04 = _DAT_e000ed04 | 0x10000000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  return *(undefined4 *)(DAT_23007170 + 0x8c);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061204. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e061204(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_23007170 = DAT_2300717c;
  _DAT_e000ed04 = 0x8000000;
  DAT_23006930 = *(undefined4 *)(DAT_2300717c + 0x84);
  uVar3 = *(undefined4 *)(DAT_2300717c + 0x88);
  *(undefined4 *)(DAT_2300717c + 0x88) = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06124c. Types and names are inferred; NOT original source. */

void vector_14(void)

{
  bool bVar1;
  int iVar2;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 uVar3;
  
  iVar2 = DAT_23007170;
  uVar3 = getProcessStackPointer();
  *(undefined4 *)(DAT_23007170 + 0x30) = unaff_r4;
  *(undefined4 *)(iVar2 + 0x34) = unaff_r5;
  *(undefined4 *)(iVar2 + 0x38) = unaff_r6;
  *(undefined4 *)(iVar2 + 0x3c) = unaff_r7;
  *(undefined4 *)(iVar2 + 0x40) = unaff_r8;
  *(undefined4 *)(iVar2 + 0x44) = unaff_r9;
  *(undefined4 *)(iVar2 + 0x48) = unaff_r10;
  *(undefined4 *)(iVar2 + 0x4c) = unaff_r11;
  *(undefined4 *)(iVar2 + 0x50) = uVar3;
  FUN_0e061204();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(*(undefined4 *)(DAT_23007170 + 0x50));
  }
  FUN_0e0613a4(DAT_23007170);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06128c. Types and names are inferred; NOT original source. */

undefined4 vector_11(void)

{
  undefined4 uVar1;
  uint unaff_lr;
  
  if ((unaff_lr & 4) == 0) {
    uVar1 = getMainStackPointer();
  }
  else {
    uVar1 = getProcessStackPointer();
  }
  FUN_0e060d1c();
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0612ac. Types and names are inferred; NOT original source. */

void FUN_0e0612ac(short param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)((uVar1 >> 5) * 4 + -0x1fff1f00) = 1 << (uVar1 & 0x1f);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0612c8. Types and names are inferred; NOT original source. */

void FUN_0e0612c8(short param_1)

{
  uint uVar1;
  
  uVar1 = (uint)param_1;
  if (-1 < (int)uVar1) {
    *(int *)(((uVar1 >> 5) + 0x20) * 4 + -0x1fff1f00) = 1 << (uVar1 & 0x1f);
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0612f0. Types and names are inferred; NOT original source. */

void FUN_0e0612f0(short param_1,char param_2,int param_3)

{
  uint uVar1;
  bool bVar2;
  
  bVar2 = -1 < param_3 << 0x1f;
  if (bVar2) {
    param_2 = (param_2 + '\x02') * ' ';
  }
  uVar1 = (uint)param_1;
  if (!bVar2) {
    param_2 = '\0';
  }
  if (-1 < (int)uVar1) {
    *(char *)(uVar1 + 0xe000e400) = param_2;
    return;
  }
  (&DAT_e000ed14)[uVar1 & 0xf] = param_2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06132c. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e06132c(void)

{
  _DAT_e000ed08 = &DWORD_0e054000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  _DAT_e000ed88 = _DAT_e000ed88 & 0xff0fffff;
  FUN_0e06c858();
  FUN_0e06e5d8();
  FUN_0e06142c();
  FUN_0e06c878();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061364. Types and names are inferred; NOT original source. */

void FUN_0e061364(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_3 + -0x20) = param_4;
  *(undefined4 *)(param_3 + -0x1c) = param_5;
  *(undefined4 *)(param_3 + -0x18) = param_6;
  *(undefined4 *)(param_3 + -4) = 0x1000000;
  *(undefined4 *)(param_3 + -0x14) = param_7;
  *(undefined1 **)(param_3 + -8) = &LAB_0e05d66c;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(int *)(param_1 + 0x50) = param_3 + -0x20;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0613a4. Types and names are inferred; NOT original source. */

void FUN_0e0613a4(int param_1)

{
  setProcStackPointerLimit(*(undefined4 *)(param_1 + 0x74));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0613ac. Types and names are inferred; NOT original source. */

void FUN_0e0613ac(int param_1,undefined4 param_2,code *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r3;
  
  DAT_23006930 = *(undefined4 *)(param_1 + 0x84);
  setProcStackPointerLimit(*(undefined4 *)(param_1 + 0x74));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(param_2);
  }
  DAT_23007170 = param_1;
  FUN_0e0613f4(0);
  FUN_0e06e3a4();
  iVar3 = FUN_0e06f4ac();
  *(undefined4 *)(iVar3 + 8) = extraout_r3;
  (*param_3)(0,0,0);
  FUN_0e061198(*(undefined4 *)(iVar3 + 8));
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06110c(extraout_r1);
  FUN_0e05d634("Failed to reboot: spinning endlessly...\n");
  do {
    FUN_0e061410();
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0613f4. Types and names are inferred; NOT original source. */

void FUN_0e0613f4(undefined4 param_1)

{
  bool bVar1;
  
  enableFIQinterrupts();
  enableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_1);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061404. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e061404(void)

{
  _DAT_e000ed10 = 0x10;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061410. Types and names are inferred; NOT original source. */

void FUN_0e061410(void)

{
  bool bVar1;
  
  disableIRQinterrupts();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  WaitForInterrupt();
  enableIRQinterrupts();
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06142c. Types and names are inferred; NOT original source. */

void FUN_0e06142c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    *(undefined1 *)(iVar1 + -0x1fff1c00) = 0x40;
    iVar1 = iVar2;
  } while (iVar2 != 0x1d7);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061470. Types and names are inferred; NOT original source. */

uint FUN_0e061470(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = TT(param_1);
  uVar1 = uVar2 & 0xff;
  if ((uVar2 & 0x10000) == 0) {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061484. Types and names are inferred; NOT original source. */

void FUN_0e061484(void)

{
  undefined4 *local_14;
  undefined4 uStack_10;
  undefined4 local_c;
  
  FUN_0e061674(&DAT_0e07017c,1,&DAT_23000000,ram_candidate_23020000);
  local_14 = &DAT_23001e20;
  uStack_10 = 0x1e1e0;
  local_c = 0;
  FUN_0e061688(&local_14,1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0614c0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e0614c0(uint param_1,uint *param_2)

{
  if (param_1 <= ((_DAT_e000ed90 & 0xffff) >> 8) - 1) {
    _DAT_e000ed98 = param_1;
    _DAT_e000ed9c = (ushort)param_2[2] & 0x1f | *param_2 & 0xffffffe0;
    _DAT_e000eda0 =
         (param_2[1] - 1) + (*param_2 & 0xffffffe0) & 0xffffffe0 |
         (*(ushort *)((int)param_2 + 10) & 7) << 1 | 1;
    return param_1;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061514. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e061514(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_2 != 0) {
    iVar5 = 0;
    iVar4 = param_1;
    do {
      uVar3 = *(uint *)(iVar4 + 4);
      if (uVar3 != 0) {
        if (uVar3 < 0x20) {
          return 0xffffffea;
        }
        if ((uVar3 & 0x1f) != 0) {
          return 0xffffffea;
        }
        uVar6 = *(uint *)(param_1 + iVar5 * 4);
        if ((uVar6 & 0x1f) != 0) {
          return 0xffffffea;
        }
        uVar1 = FUN_0e061470(uVar6);
        uVar3 = FUN_0e061470((uVar6 - 1) + uVar3);
        if (uVar1 != uVar3) {
          return 0xffffffea;
        }
        if (uVar1 == 0xffffffea) {
          return 0xffffffea;
        }
        if ((int)param_3 <= (int)uVar1) {
          return 0xffffffea;
        }
        uVar3 = *(uint *)(param_1 + iVar5 * 4);
        uVar6 = *(int *)(iVar4 + 4) + uVar3;
        uVar7 = _DAT_e000eda0 | 0x1f;
        uVar8 = uVar6 - 1;
        _DAT_e000ed98 = uVar1;
        if ((_DAT_e000ed9c & 0xffffffe0) == uVar3) {
          if (uVar7 == uVar8) {
            FUN_0e0614c0(uVar1 & 0xff,iVar4,uVar6,0xe000ed00,param_4);
          }
          else {
            _DAT_e000ed9c = uVar6 & 0xffffffe0 | _DAT_e000ed9c & 0x1f;
            iVar2 = FUN_0e0614c0(param_3 & 0xff,iVar4,_DAT_e000ed9c,0xe000ed00,param_4);
joined_r0x0e061634:
            if (iVar2 == -0x16) {
              return 0xffffffea;
            }
            param_3 = iVar2 + 1;
          }
        }
        else {
          _DAT_e000eda0 = _DAT_e000eda0 & 0x1f | uVar3 - 1 & 0xffffffe0;
          if (uVar7 == uVar8) {
            iVar2 = FUN_0e0614c0(param_3 & 0xff,iVar4,_DAT_e000eda0,0xe000ed00,param_4);
            goto joined_r0x0e061634;
          }
          iVar2 = FUN_0e0614c0(param_3 & 0xff,iVar4,_DAT_e000eda0,0xe000ed00,param_4);
          if (iVar2 == -0x16) {
            return 0xffffffea;
          }
          uVar3 = *(int *)(param_1 + iVar5 * 4) + *(int *)(iVar4 + 4) & 0xffffffe0;
          _DAT_e000ed98 = iVar2 + 1U & 0xff;
          if (((_DAT_e000ed90 & 0xffff) >> 8) - 1 < _DAT_e000ed98) {
            _DAT_e000ed98 = uVar1;
            return 0xffffffea;
          }
          _DAT_e000ed9c = _DAT_e000ed9c & 0x1f | uVar3;
          _DAT_e000eda0 = _DAT_e000eda0 & 0xe | ((uVar7 - 1) + uVar3) - uVar8 & 0xffffffe0 | 1;
          param_3 = _DAT_e000ed98 + 1;
        }
      }
      iVar5 = iVar5 + 3;
      iVar4 = iVar4 + 0xc;
    } while (iVar5 != param_2 * 3);
  }
  return param_3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061674. Types and names are inferred; NOT original source. */

void FUN_0e061674(undefined4 param_1,undefined4 param_2)

{
  DAT_230071ea = FUN_0e061514(param_1,param_2,DAT_230071ea);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061688. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e061688(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0) {
    return;
  }
  iVar5 = 0;
  puVar3 = &DAT_23006938;
  do {
    iVar4 = param_1[1];
    if (iVar4 != 0) {
      iVar6 = *param_1;
      uVar1 = FUN_0e061470(iVar6);
      uVar2 = FUN_0e061470(iVar4 + iVar6 + -1);
      if (uVar1 != uVar2) {
        (&DAT_23006934)[iVar5 * 5] = 0xffffffea;
        return;
      }
      puVar3[-1] = uVar1;
      if (uVar1 == 0xffffffea) {
        return;
      }
      if ((int)(uint)DAT_230071ea <= (int)uVar1) {
        return;
      }
      _DAT_e000ed98 = uVar1;
      *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0xe0 | (byte)_DAT_e000ed9c & 0x1f;
      *(byte *)(puVar3 + 2) = (byte)puVar3[2] & 0x1f | (byte)((_DAT_e000eda0 >> 1 & 7) << 5);
      *puVar3 = _DAT_e000ed9c & 0xffffffe0;
      puVar3[3] = _DAT_e000eda0 & 0xffffffe0;
    }
    iVar5 = iVar5 + 1;
    param_1 = param_1 + 3;
    puVar3 = puVar3 + 5;
    if (param_2 <= iVar5) {
      return;
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06173c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e06173c(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int local_2c [2];
  
  if ((_DAT_e000ed90 & 0xffff) >> 8 < 3) {
    uVar3 = 0xffffffff;
  }
  else {
    DataMemoryBarrier(0x1f);
    _DAT_e000ed94 = 0;
    _DAT_e000edc0 = 0x44ffaa;
    puVar4 = &DAT_23000690;
    uVar11 = 0;
    do {
      _DAT_e000ed98 = uVar11;
      _DAT_e000ed9c = *puVar4 & 0xffffffe0 | (byte)puVar4[2] & 0x1f;
      _DAT_e000eda0 = puVar4[3] & 0xffffffe0 | (uint)(byte)((byte)puVar4[2] >> 5) << 1 | 1;
      puVar4 = puVar4 + 4;
      uVar11 = _DAT_e000ed98 + 1;
    } while (_DAT_e000ed98 + 1 != 3);
    DAT_230071ea = 3;
    iVar2 = FUN_0e05fd84(local_2c);
    if (iVar2 == 0) {
      uVar11 = (uint)DAT_230071ea;
    }
    else {
      bVar1 = false;
      uVar11 = (uint)DAT_230071ea;
      iVar10 = 0;
      uVar6 = uVar11;
      do {
        while (uVar5 = uVar6, uVar6 = *(uint *)(local_2c[0] + 0xc) & 0xfff00000, uVar6 == 0x200000)
        {
          iVar8 = 2;
          uVar7 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar9 = 1;
          uVar6 = *(int *)(local_2c[0] + 8) + -1 + uVar7 & 0xffffffe0;
LAB_0e0617fc:
          if (((_DAT_e000ed90 & 0xffff) >> 8) - 1 < uVar5) {
            if (bVar1) {
              DAT_230071ea = (byte)uVar5;
            }
            return 0xffffffea;
          }
          bVar1 = true;
          iVar10 = iVar10 + 1;
          _DAT_e000eda0 = uVar6 | iVar8 << 1 | 1;
          _DAT_e000ed9c = uVar7 | uVar9;
          local_2c[0] = local_2c[0] + 0x10;
          uVar6 = uVar5 + 1 & 0xff;
          _DAT_e000ed98 = uVar5;
          if (iVar2 == iVar10) goto LAB_0e06183a;
        }
        if (uVar6 == 0x400000) {
          iVar8 = 0;
          uVar9 = 2;
          uVar7 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar6 = *(int *)(local_2c[0] + 8) + -1 + uVar7 & 0xffffffe0;
          goto LAB_0e0617fc;
        }
        if (uVar6 == 0x100000) {
          iVar8 = 1;
          uVar9 = 1;
          uVar7 = *(uint *)(local_2c[0] + 4) & 0xffffffe0;
          uVar6 = *(int *)(local_2c[0] + 8) + -1 + uVar7 & 0xffffffe0;
          goto LAB_0e0617fc;
        }
        iVar10 = iVar10 + 1;
        local_2c[0] = local_2c[0] + 0x10;
        uVar6 = uVar5;
      } while (iVar2 != iVar10);
LAB_0e06183a:
      if (bVar1) {
        DAT_230071ea = (byte)uVar6;
        uVar11 = uVar6;
      }
    }
    if (uVar11 < (_DAT_e000ed90 & 0xffff) >> 8) {
      do {
        _DAT_e000ed98 = uVar11;
        _DAT_e000eda0 = 0;
        uVar11 = _DAT_e000ed98 + 1;
      } while ((int)(_DAT_e000ed98 + 1) < (int)((_DAT_e000ed90 & 0xffff) >> 8));
    }
    _DAT_e000ed94 = 5;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
    uVar3 = 0;
  }
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06194c. Types and names are inferred; NOT original source. */

undefined * FUN_0e06194c(int param_1)

{
  return &DAT_23001c7c + param_1 * 0x24;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06195c. Types and names are inferred; NOT original source. */

int FUN_0e06195c(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_24 [2];
  
  local_24[0] = param_2;
  uVar4 = FUN_0e06e9e0(&local_30);
  uVar3 = uStack_2c;
  uVar2 = local_30;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar6 = (uint)*(ushort *)(param_1 + 0x12);
  if (uVar6 == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_4 != 0 || param_3 != 0) {
      FUN_0e06f4ac(uVar4,0,param_3,param_4);
    }
    uVar9 = FUN_0e06d038(param_1);
    if ((int)uVar9 != 0) goto joined_r0x0e0619a8;
LAB_0e061a02:
    iVar7 = 0;
  }
  else {
    if (uVar6 < *(ushort *)(param_1 + 0x10)) {
      uVar9 = FUN_0e06d038(param_1,uVar6,0,0);
      if ((int)uVar9 != 0) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar8);
        }
        InstructionSynchronizationBarrier(0xf);
        goto joined_r0x0e0619a8;
      }
      uVar6 = (uint)*(ushort *)(param_1 + 0x12);
    }
    *(short *)(param_1 + 0x12) = (short)uVar6 + -1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar7 = *(ushort *)(param_1 + 0x10) - uVar6;
    iVar5 = iVar7 * (*(byte *)(param_1 + 0x14) + 0x1b & 0xfffffffc) + *(int *)(param_1 + 0x20);
    uVar9 = CONCAT44(iVar7,iVar5);
    *(char *)(iVar5 + 10) = (char)(param_1 + -0x23001c7c >> 2) * '9';
    *(undefined1 *)(iVar5 + 0xb) = *(undefined1 *)(param_1 + 0x14);
joined_r0x0e0619a8:
    iVar7 = (int)uVar9;
    if (local_24[0] == 0) {
      *(undefined4 *)(iVar7 + 0x14) = 0;
    }
    else {
      FUN_0e06ea70(&local_30,(int)((ulonglong)uVar9 >> 0x20),uVar2,uVar3);
      iVar5 = (**(code **)**(undefined4 **)(&DAT_23001c98 + (uint)*(byte *)(iVar7 + 10) * 0x24))
                        (iVar7,local_24,local_30,uStack_2c);
      *(int *)(iVar7 + 0x14) = iVar5;
      if (iVar5 == 0) {
        FUN_0e06d020(&DAT_23001c7c + (uint)*(byte *)(iVar7 + 10) * 0x24,iVar7);
        goto LAB_0e061a02;
      }
    }
    *(short *)(iVar7 + 0x12) = (short)local_24[0];
    *(undefined2 *)(iVar7 + 8) = 1;
    *(undefined4 *)(iVar7 + 4) = 0;
    FUN_0e06f3aa(iVar7 + 0x18,0,*(undefined1 *)(iVar7 + 0xb));
    *(undefined2 *)(iVar7 + 0x10) = 0;
    *(undefined4 *)(iVar7 + 0xc) = *(undefined4 *)(iVar7 + 0x14);
  }
  return iVar7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061a90. Types and names are inferred; NOT original source. */

void FUN_0e061a90(int param_1)

{
  FUN_0e06195c(param_1,*(undefined4 *)(*(int *)(param_1 + 0x1c) + 8));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061a98. Types and names are inferred; NOT original source. */

int FUN_0e061a98(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = FUN_0e06195c(param_1,0,param_5,param_6);
  if (iVar1 != 0) {
    FUN_0e061b64(iVar1 + 0xc,param_2,param_3);
    *(undefined1 *)(iVar1 + 9) = 1;
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061ac0. Types and names are inferred; NOT original source. */

void FUN_0e061ac0(int param_1)

{
  int iVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return;
  }
  do {
    while( true ) {
      iVar4 = *(int *)(param_1 + 4);
      cVar3 = *(char *)(param_1 + 8) + -1;
      *(char *)(param_1 + 8) = cVar3;
      if (cVar3 != '\0') {
        return;
      }
      bVar2 = *(byte *)(param_1 + 10);
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 4) = 0;
      iVar1 = (uint)bVar2 * 0x24;
      if (*(code **)(&DAT_23001c94 + iVar1) == (code *)0x0) break;
      (**(code **)(&DAT_23001c94 + iVar1))();
      param_1 = iVar4;
      if (iVar4 == 0) {
        return;
      }
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      if (-1 < (int)((uint)*(byte *)(param_1 + 9) << 0x1f)) {
        (**(code **)(**(int **)(&DAT_23001c98 + iVar1) + 8))();
      }
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    FUN_0e06d020(&DAT_23001c7c + (uint)bVar2 * 0x24,param_1);
    param_1 = iVar4;
  } while (iVar4 != 0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061b2c. Types and names are inferred; NOT original source. */

int FUN_0e061b2c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  if (param_1 == 0) {
    *(char *)(param_2 + 8) = *(char *)(param_2 + 8) + '\x01';
    return param_2;
  }
  do {
    iVar1 = iVar2;
    iVar2 = *(int *)(iVar1 + 4);
  } while (iVar2 != 0);
  *(int *)(iVar1 + 4) = param_2;
  return param_1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061b48. Types and names are inferred; NOT original source. */

undefined4 FUN_0e061b48(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_2 + 4);
  }
  uVar1 = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = 0;
  FUN_0e061ac0();
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061b64. Types and names are inferred; NOT original source. */

void FUN_0e061b64(undefined4 *param_1,undefined4 param_2,undefined2 param_3)

{
  param_1[1] = CONCAT22(param_3,param_3);
  param_1[2] = param_2;
  *param_1 = param_2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061b78. Types and names are inferred; NOT original source. */

int FUN_0e061b78(int *param_1,short param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 1);
  *(ushort *)(param_1 + 1) = param_2 + uVar1;
  return *param_1 + (uint)uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061b84. Types and names are inferred; NOT original source. */

void FUN_0e061b84(int *param_1,undefined4 param_2,short param_3)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 1);
  *(ushort *)(param_1 + 1) = uVar1 + param_3;
  FUN_0e06f35c(*param_1 + (uint)uVar1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061b98. Types and names are inferred; NOT original source. */

int FUN_0e061b98(int *param_1,undefined1 param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(param_1 + 1);
  iVar2 = *param_1;
  *(ushort *)(param_1 + 1) = uVar1 + 1;
  *(undefined1 *)(iVar2 + (uint)uVar1) = param_2;
  return iVar2 + (uint)uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061bac. Types and names are inferred; NOT original source. */

void FUN_0e061bac(int *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = *(ushort *)(param_1 + 1);
  iVar2 = *param_1;
  *(ushort *)(param_1 + 1) = uVar1 + 2;
  *(char *)(iVar2 + (uint)uVar1) = (char)param_2;
  *(char *)(iVar2 + (uint)uVar1 + 1) = (char)((uint)param_2 >> 8);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061bcc. Types and names are inferred; NOT original source. */

void FUN_0e061bcc(int *param_1,undefined4 param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 1);
  *(ushort *)(param_1 + 1) = uVar1 + 4;
  *(undefined4 *)(*param_1 + (uint)uVar1) = param_2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061bdc. Types and names are inferred; NOT original source. */

int FUN_0e061bdc(int *param_1,short param_2)

{
  ushort uVar1;
  
  uVar1 = (short)param_1[1] - param_2;
  *(ushort *)(param_1 + 1) = uVar1;
  return *param_1 + (uint)uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061bec. Types and names are inferred; NOT original source. */

void FUN_0e061bec(int *param_1,int param_2)

{
  *(short *)(param_1 + 1) = (short)param_1[1] - (short)param_2;
  *param_1 = *param_1 + param_2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061bfc. Types and names are inferred; NOT original source. */

int FUN_0e061bfc(int *param_1)

{
  return ((uint)*(ushort *)((int)param_1 + 6) - (uint)*(ushort *)(param_1 + 1)) -
         (*param_1 - param_1[2]);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061c10. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e061c10(void)

{
  uint uVar1;
  
  FUN_0e0673d8();
  FUN_0e067308();
  FUN_0e0620e4(&DAT_23006954,0x10);
  _DAT_5301e490 = _DAT_5301e490 & 0xfffffffe;
  _DAT_53012508 = _DAT_53012508 & 0xffffff3f | 0x13f;
  _DAT_53012518 = _DAT_53012518 & 0xffffff3f | 0x13f;
  _DAT_5301250c = 0x13f;
  _DAT_5301251c = 0x13f;
  _DAT_5300d448 = _DAT_0fffe430 & 0xffff;
  _DAT_5300d440 = _DAT_0fffe410 & 0xff;
  _DAT_5300d444 = _DAT_0fffe418 & 0xffff;
  _DAT_5300d468 = 0x10;
  _DAT_5300d450 = 0;
  _DAT_5300d480 = 0;
  _DAT_5300d014 = 1;
  uVar1 = FUN_0e062190();
  return uVar1 & (int)uVar1 >> 0x1f;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061d3c. Types and names are inferred; NOT original source. */

uint FUN_0e061d3c(int param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  longlong lVar7;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_23006958 = DAT_23006958 & 0xfffffeef;
  iVar2 = FUN_0e06ad08(*(undefined1 *)(param_1 + 0x20),*(short *)(param_1 + 0x1a) != 0);
  if (iVar2 == 0) {
    uVar5 = FUN_0e06e9a0();
    lVar6 = FUN_0e05ba10((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
    uVar3 = (uint)lVar6;
    while( true ) {
      uVar5 = FUN_0e06e9a0(uVar3);
      lVar7 = FUN_0e05ba10((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
      if ((int)(uint)((uint)(lVar7 - lVar6) < 1000) <= (int)((ulonglong)(lVar7 - lVar6) >> 0x20)) {
        return 0xffffff8c;
      }
      uVar3 = (DAT_23006958 & 0x1ff) >> 8;
      if ((int)(DAT_23006958 << 0x17) < 0) break;
      if ((int)(DAT_23006958 << 0x1b) < 0) {
        return uVar3;
      }
    }
    return 0xfffffffb;
  }
  return 0xfffffffb;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061ed4. Types and names are inferred; NOT original source. */

void FUN_0e061ed4(int param_1,code *UNRECOVERED_JUMPTABLE_00)

{
  int iVar1;
  
  *(code **)(param_1 + 0x1c) = UNRECOVERED_JUMPTABLE_00;
  if (-1 < (int)(DAT_23006958 << 0x1e)) {
                    /* WARNING: Could not recover jumptable at 0x0e061ef0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,(DAT_23006958 & 3) >> 1);
    return;
  }
  iVar1 = FUN_0e06ad08(*(undefined1 *)(param_1 + 0x20),0,param_1);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0e061f0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,0xfffffffb);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061f14. Types and names are inferred; NOT original source. */

void FUN_0e061f14(int param_1,code *UNRECOVERED_JUMPTABLE_00)

{
  int iVar1;
  
  *(code **)(param_1 + 0x1c) = UNRECOVERED_JUMPTABLE_00;
  if (-1 < (int)(DAT_23006958 << 0x1e)) {
                    /* WARNING: Could not recover jumptable at 0x0e061f30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,(DAT_23006958 & 3) >> 1);
    return;
  }
  iVar1 = FUN_0e06ad08(*(undefined1 *)(param_1 + 0x20),1,param_1);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0e061f4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE_00)(param_1,0xfffffffb);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e061f9c. Types and names are inferred; NOT original source. */

uint FUN_0e061f9c(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined8 uVar4;
  undefined1 auStack_20 [4];
  undefined1 *local_1c;
  uint local_18;
  uint local_14;
  
  if ((param_1 < 5) && (puVar2 = (&PTR_DAT_0e070194)[param_1], puVar2 != (undefined *)0x0)) {
    local_14 = (DAT_23006958 & 7) >> 2;
    if ((int)(DAT_23006958 << 0x1d) < 0) {
      uVar1 = 0xfffffffb;
    }
    else {
      local_1c = (undefined1 *)(uint)DAT_230071f0;
      if (local_1c == (undefined1 *)0x0) {
        local_18 = 1;
        local_14 = (uint)local_1c;
        uVar1 = FUN_0e05ddc0(puVar2,auStack_20);
        if (-1 < (int)uVar1) {
          do {
          } while ((local_18 & 3) != 0);
          return local_14;
        }
      }
      else {
        local_1c = &LAB_0e061d34_1;
        puVar3 = puVar2 + 0x24;
        local_18 = 3;
        FUN_0e06cdac(puVar3,&LAB_0e061d34_1,0xffffffff,0xffffffff);
        uVar4 = FUN_0e05ddc0(puVar2,auStack_20);
        uVar1 = (uint)uVar4;
        if ((int)uVar1 < 0) {
          FUN_0e06cea8(puVar3);
        }
        else {
          FUN_0e06d118(puVar2 + 0x38,(int)((ulonglong)uVar4 >> 0x20),0xffffffff,0xffffffff);
          uVar1 = *(uint *)(puVar2 + 0x48);
          FUN_0e06cea8(puVar3);
        }
      }
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06204c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06204c(uint param_1)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  if ((param_1 < 5) && (puVar5 = (&PTR_DAT_0e070194)[param_1], puVar5 != (undefined *)0x0)) {
    if (DAT_23006958 << 0x1d < 0) {
      return 0xfffffffb;
    }
    uVar6 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar6 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if ((*(ushort *)(puVar5 + 0x18) & 7) == 2) {
      sVar1 = *(short *)(puVar5 + 0x1a);
      *(short *)(puVar5 + 0x1a) = sVar1 + -1;
      if ((short)(sVar1 + -1) == 0) {
        FUN_0e05dab8(puVar5,2,uVar6);
        return 2;
      }
      uVar4 = 2;
    }
    else if ((*(ushort *)(puVar5 + 0x18) & 7) == 1) {
      uVar4 = 0xfffffffb;
    }
    else {
      uVar4 = 0xffffff7a;
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar4;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06207c. Types and names are inferred; NOT original source. */

int FUN_0e06207c(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *local_14;
  
  iVar1 = FUN_0e067d30(param_1,0,&local_14);
  if (-1 < iVar1) {
    if ((char)local_14[1] != '\0') {
      uVar2 = 0;
      uVar3 = 0;
      do {
        while( true ) {
          uVar4 = *(uint *)(*local_14 + uVar3 * 4);
          uVar3 = (uVar4 & 0x1ff) >> 5;
          if (uVar3 < 10) {
            iVar1 = *(int *)(&DAT_0e0701a8 + uVar3 * 4);
          }
          else {
            iVar1 = 0;
          }
          iVar5 = 1 << (uVar4 & 0x1f);
          if (param_2 != 0) break;
          *(int *)(iVar1 + 0x48) = iVar5;
          uVar2 = uVar2 + 1;
          uVar3 = uVar2 & 0xff;
          if (*(byte *)(local_14 + 1) <= uVar3) goto LAB_0e0620d8;
        }
        *(int *)(iVar1 + 0x44) = iVar5;
        uVar2 = uVar2 + 1;
        uVar3 = uVar2 & 0xff;
      } while (uVar3 < *(byte *)(local_14 + 1));
    }
LAB_0e0620d8:
    iVar1 = 0;
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0620e4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0620e4(undefined4 *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  if (param_2 == 1) {
    puVar7 = &DAT_23006968;
  }
  else {
    if (param_2 != 0x10) {
      return;
    }
    puVar7 = &DAT_23006960;
  }
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar4 = (undefined4 *)*puVar7;
  DAT_2300695c = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
LAB_0e062144:
    _DAT_5301e490 = _DAT_5301e490 & ~param_2 | param_2;
    puVar4 = (undefined4 *)*puVar7;
    if (puVar4 == (undefined4 *)0x0) goto LAB_0e062128;
  }
  else {
    iVar6 = 0;
    puVar3 = puVar4;
    do {
      puVar3 = (undefined4 *)*puVar3;
      iVar6 = iVar6 + 1;
    } while (puVar3 != (undefined4 *)0x0);
    DAT_2300695c = (undefined4 *)0x0;
    if (iVar6 == 0) goto LAB_0e062144;
  }
  if (param_1 == puVar4) {
    uVar5 = *param_1;
    *puVar7 = uVar5;
    if (param_1 == (undefined4 *)puVar7[1]) {
      puVar7[1] = uVar5;
    }
  }
  else {
    do {
      puVar3 = puVar4;
      puVar4 = (undefined4 *)*puVar3;
      if (puVar4 == (undefined4 *)0x0) goto LAB_0e062128;
    } while (param_1 != puVar4);
    *puVar3 = *param_1;
    if (param_1 == (undefined4 *)puVar7[1]) {
      puVar7[1] = puVar3;
    }
  }
LAB_0e062128:
  *param_1 = 0;
  if ((undefined4 *)puVar7[1] == (undefined4 *)0x0) {
    *puVar7 = param_1;
    puVar7[1] = param_1;
  }
  else {
    *(undefined4 *)puVar7[1] = param_1;
    puVar7[1] = param_1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar8);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e062190. Types and names are inferred; NOT original source. */

undefined4 FUN_0e062190(void)

{
  undefined4 in_r3;
  
  DAT_2300697c = &DAT_0e070200;
  FUN_0e05d5b0(&DAT_23006970,0x2fc13018,1000,&DAT_0e070200,in_r3);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0621b8. Types and names are inferred; NOT original source. */

void FUN_0e0621b8(int param_1,uint param_2)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  bool bVar5;
  int local_24;
  
  if (param_2 != 0) {
    do {
      uVar4 = 0;
      bVar5 = (bool)isCurrentModePrivileged();
      if (bVar5) {
        uVar4 = getBasePriority();
      }
      bVar5 = (bool)isCurrentModePrivileged();
      if ((bVar5) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar2 = FUN_0e068540();
      bVar5 = CARRY4(uVar2,DAT_23000230);
      uVar2 = uVar2 + DAT_23000230;
      lVar1 = (ulonglong)uVar2 * 0x87b0b0fd;
      uVar3 = (uint)lVar1;
      DAT_23000230 = uVar3 + 0xb504f32d;
      DAT_23000234 = (DAT_23000234 + (uint)bVar5) * -0x784f4f03 + uVar2 * 0x27bb2ee6 +
                     (int)((ulonglong)lVar1 >> 0x20) + (uint)(0x4afb0cd2 < uVar3);
      bVar5 = (bool)isCurrentModePrivileged();
      if (bVar5) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar2 = param_2;
      if (3 < param_2) {
        uVar2 = 4;
      }
      local_24 = DAT_23000234;
      FUN_0e06f35c(param_1,&local_24,uVar2);
      param_2 = param_2 - uVar2;
      param_1 = param_1 + uVar2;
    } while (param_2 != 0);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e062244. Types and names are inferred; NOT original source. */

uint FUN_0e062244(int param_1)

{
  return (*(byte *)(param_1 + 0x60) & 0x3f) >> 4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e062250. Types and names are inferred; NOT original source. */

uint FUN_0e062250(int param_1)

{
  return *(uint *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80) & 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e062260. Types and names are inferred; NOT original source. */

undefined4
FUN_0e062260(int param_1,int param_2,undefined1 param_3,undefined4 param_4,undefined1 param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  FUN_0e06cdac(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
  iVar2 = (uint)*(byte *)(param_1 + 0x60) << 0x1e;
  if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1e) < 0) {
    uVar3 = 0xffffff88;
  }
  else {
    if (param_2 == 0) {
      iVar2 = *(int *)(param_1 + 100);
    }
    else {
      if (param_2 != 1) {
        *(byte *)(4 - (iVar2 >> 0x1f)) = (byte)((uint)iVar2 >> 0x1f);
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe0622b8);
        (*pcVar1)();
      }
      iVar2 = *(int *)(param_1 + 0x68);
    }
    uVar3 = 0;
    *(undefined1 *)(iVar2 + 4) = param_3;
    *(char *)(iVar2 + 5) = (char)param_4;
    *(undefined1 *)(iVar2 + 6) = param_5;
  }
  FUN_0e06cea8(param_1 + 4);
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0622bc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0622bc(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80);
  FUN_0e06cdac(param_1 + 4,param_2,0xffffffff,0xffffffff);
  if (iVar2 << 0x1e < 0) {
    if (((int)((uint)*(byte *)(param_1 + 0x60) << 0x1c) < 0) &&
       ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1d) < 0)) {
      iVar2 = *(int *)(param_1 + 0x18);
      iVar3 = *(int *)(iVar2 + 8);
      if (*(int *)(*(int *)(iVar2 + 0x10) + 0xa0) << 0x1e < 0) {
        (**(code **)(iVar3 + 0x3c))(iVar2);
        uVar1 = (**(code **)(iVar3 + 0x20))(iVar2);
        (**(code **)(iVar3 + 0x40))(iVar2);
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
    else {
      uVar1 = 0xfffffff3;
    }
  }
  else {
    uVar1 = 0xffffff7a;
  }
  FUN_0e06cea8(param_1 + 4);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06232c. Types and names are inferred; NOT original source. */

uint FUN_0e06232c(int param_1)

{
  return (*(byte *)(param_1 + 0x60) & 7) >> 2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e062338. Types and names are inferred; NOT original source. */

int FUN_0e062338(int param_1)

{
  int iVar1;
  undefined4 extraout_r1;
  int iVar2;
  
  FUN_0e06e0c4();
  iVar2 = param_1 + 4;
  FUN_0e06cdac(iVar2,extraout_r1,0xffffffff,0xffffffff);
  if (*(int *)(param_1 + 0x18) != 0) {
    if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0) {
      iVar1 = -0x78;
      goto LAB_0e06236c;
    }
    iVar1 = FUN_0e06c6c0();
    if (iVar1 != 0) {
      iVar1 = FUN_0e0633e4(param_1);
      if (iVar1 == 0) {
        FUN_0e06f3aa(param_1 + 0x20,0,0x28);
        *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 1;
        FUN_0e06cea8(iVar2);
        FUN_0e06e0ec();
        return 0;
      }
      goto LAB_0e06236c;
    }
  }
  iVar1 = -0x13;
LAB_0e06236c:
  FUN_0e06cea8(iVar2);
  FUN_0e06e0ec();
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0623ac. Types and names are inferred; NOT original source. */

int FUN_0e0623ac(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 + 4;
  FUN_0e06cdac(iVar2,param_2,0xffffffff,0xffffffff);
  if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0) {
    if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1e) < 0) {
      iVar1 = -0x78;
    }
    else {
      iVar1 = FUN_0e064bf8(*(undefined4 *)(param_1 + 0x18));
      if (iVar1 == 0) {
        iVar1 = FUN_0e063134(param_1);
        if (iVar1 == 0) {
          *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 2;
          FUN_0e06cea8(iVar2);
          return 0;
        }
        FUN_0e064c60(*(undefined4 *)(param_1 + 0x18));
      }
    }
  }
  else {
    iVar1 = -1;
  }
  FUN_0e06cea8(iVar2);
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e062414. Types and names are inferred; NOT original source. */

undefined4 FUN_0e062414(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1e) < 0) {
    FUN_0e06cdac(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
    FUN_0e063788(param_1,0);
    uVar1 = FUN_0e064c60(*(undefined4 *)(param_1 + 0x18));
    *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) & 0xfd;
    FUN_0e06cea8(param_1 + 4);
  }
  else {
    uVar1 = 0xffffff88;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06245c. Types and names are inferred; NOT original source. */

uint FUN_0e06245c(int param_1)

{
  return (*(byte *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80) & 0x1f) >> 4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06246c. Types and names are inferred; NOT original source. */

int FUN_0e06246c(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)(param_1 + 0x48)) {
    while( true ) {
      if (piVar1 == (int *)0x0) {
        return 0;
      }
      if (*(byte *)((int)piVar1 + 0x11) == param_2) {
        if (param_2 == 3) {
          if (*(byte *)(piVar1 + 2) == param_3) {
            return (int)piVar1;
          }
        }
        else if (param_2 == 0xf) {
          return (int)piVar1;
        }
      }
      if (piVar1 == (int *)*(int *)(param_1 + 0x4c)) break;
      piVar1 = (int *)*piVar1;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0624a4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0624a4(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  char cVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  
  FUN_0e06cdac(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
  iVar3 = *(int *)(param_1 + 100);
  iVar8 = *(int *)(param_1 + 0x68);
  if (((iVar3 == 0) || (iVar8 == 0)) || ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0)) {
    uVar7 = 0xffffffff;
  }
  else {
    if (*(int *)(param_1 + 0x48) == 0) {
      *(int *)(param_1 + 0x48) = param_1 + 0x48;
      *(int *)(param_1 + 0x4c) = param_1 + 0x48;
    }
    if (*param_2 == 0) {
      cVar5 = *(char *)((int)param_2 + 0x11);
      if (cVar5 == '\x0f') {
        piVar6 = *(int **)(param_1 + 0x4c);
        param_2[1] = (int)piVar6;
        *param_2 = param_1 + 0x48;
        *piVar6 = (int)param_2;
        *(int **)(param_1 + 0x4c) = param_2;
        cVar5 = *(char *)((int)param_2 + 0x11);
      }
      if (cVar5 == '\x03') {
        piVar6 = *(int **)(param_1 + 0x48);
        if ((int *)(param_1 + 0x48) != piVar6) {
          for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
            while (*(char *)((int)piVar6 + 0x11) == '\x03') {
              bVar1 = *(byte *)(piVar6 + 2);
              if ((piVar6 == *(int **)(param_1 + 0x4c)) ||
                 (piVar6 = (int *)*piVar6, piVar6 == (int *)0x0)) {
                *(byte *)(param_2 + 2) = bVar1 + 1;
                goto LAB_0e06255c;
              }
              if ((*(char *)((int)piVar6 + 0x11) != '\x03') ||
                 ((uint)bVar1 != *(byte *)(piVar6 + 2) - 1)) {
                *(byte *)(param_2 + 2) = bVar1 + 1;
                piVar4 = (int *)piVar6[1];
                *param_2 = (int)piVar6;
                param_2[1] = (int)piVar4;
                *piVar4 = (int)param_2;
                piVar6[1] = (int)param_2;
                goto LAB_0e062566;
              }
            }
            if (piVar6 == *(int **)(param_1 + 0x4c)) break;
          }
        }
        *(undefined1 *)(param_2 + 2) = 0;
LAB_0e06255c:
        piVar6 = *(int **)(param_1 + 0x4c);
        *param_2 = param_1 + 0x48;
        param_2[1] = (int)piVar6;
        *piVar6 = (int)param_2;
        *(int **)(param_1 + 0x4c) = param_2;
LAB_0e062566:
        cVar5 = *(char *)((int)param_2 + 9);
        if (cVar5 == '\x02') {
          iVar2 = param_2[2];
          *(char *)(iVar8 + 0xf) = (char)iVar2;
          *(char *)(iVar3 + 0xf) = (char)iVar2;
        }
        else if (cVar5 == '\x03') {
          iVar2 = param_2[2];
          *(char *)(iVar8 + 0x10) = (char)iVar2;
          *(char *)(iVar3 + 0x10) = (char)iVar2;
        }
        else if (cVar5 == '\x01') {
          iVar2 = param_2[2];
          *(char *)(iVar8 + 0xe) = (char)iVar2;
          *(char *)(iVar3 + 0xe) = (char)iVar2;
        }
      }
      uVar7 = 0;
    }
    else {
      uVar7 = 0xffffff88;
    }
  }
  FUN_0e06cea8(param_1 + 4);
  return uVar7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0625a0. Types and names are inferred; NOT original source. */

undefined1 FUN_0e0625a0(int *param_1)

{
  if (*param_1 != 0) {
    return (char)param_1[2];
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0625ac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0625ac(int param_1,int param_2,char param_3,int param_4)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  code *pcVar7;
  char *pcVar8;
  int iVar9;
  byte *pbVar10;
  int *piVar11;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined1 local_24;
  
  uVar2 = FUN_0e062244();
  if (param_4 == 0) {
    iVar3 = FUN_0e063728(param_1,uVar2,param_3 + '\x01');
    if (iVar3 != 0) {
      pbVar10 = *(byte **)(iVar3 + 4);
LAB_0e0625f4:
      iVar9 = param_2 + 0xc;
      uVar4 = FUN_0e061bfc(iVar9);
      uVar5 = (uint)*pbVar10;
      if (uVar4 < uVar5) {
        uVar5 = FUN_0e061bfc(iVar9);
      }
      FUN_0e061b84(iVar9,pbVar10,uVar5);
      piVar11 = *(int **)(iVar3 + 0xc);
      do {
        if (piVar11 == (int *)0x0) {
          if ((uint)*(ushort *)(param_2 + 0x10) <= (uint)*(ushort *)(param_1 + 0x26)) {
            return 0;
          }
          FUN_0e061bdc(iVar9,(uint)*(ushort *)(param_2 + 0x10) - (uint)*(ushort *)(param_1 + 0x26));
          return 0;
        }
        pcVar7 = *(code **)(*(int *)(piVar11[1] + 8) + 0x30);
        if ((pcVar7 != (code *)0x0) &&
           (puVar6 = (undefined4 *)(*pcVar7)(piVar11[1],uVar2), puVar6 != (undefined4 *)0x0)) {
          pcVar8 = (char *)*puVar6;
          while (pcVar8 != (char *)0x0) {
            while( true ) {
              if (*pcVar8 == '\0') goto LAB_0e06265c;
              uVar4 = FUN_0e061bfc(iVar9);
              if (*(byte *)*puVar6 <= uVar4) break;
              uVar1 = FUN_0e061bfc(iVar9);
              FUN_0e061b84(iVar9,*puVar6,uVar1);
              puVar6 = puVar6 + 1;
              pcVar8 = (char *)*puVar6;
              if (pcVar8 == (char *)0x0) goto LAB_0e06265c;
            }
            FUN_0e061b84(iVar9);
            puVar6 = puVar6 + 1;
            pcVar8 = (char *)*puVar6;
          }
        }
LAB_0e06265c:
        piVar11 = (int *)*piVar11;
      } while( true );
    }
  }
  else {
    iVar3 = FUN_0e062250(param_1);
    if (iVar3 == 1) {
      uVar2 = (uint)(uVar2 == 0);
      iVar3 = FUN_0e063728(param_1,uVar2,param_3 + '\x01');
      if (iVar3 != 0) {
        puVar6 = *(undefined4 **)(iVar3 + 4);
        uStack_28 = puVar6[1];
        pbVar10 = (byte *)&local_2c;
        local_24 = *(undefined1 *)(puVar6 + 2);
        local_2c._2_2_ = (undefined2)((uint)*puVar6 >> 0x10);
        local_2c._0_2_ = CONCAT11(7,(byte)*puVar6);
        goto LAB_0e0625f4;
      }
    }
  }
  iVar3 = FUN_0e06f4ac();
  *(undefined4 *)(iVar3 + 0xc) = 0xffffff7a;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0626bc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0626bc(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  code *UNRECOVERED_JUMPTABLE_00;
  
  bVar3 = *(byte *)(param_1 + 0x20) & 0x1f;
  if (bVar3 == 1) {
    iVar1 = FUN_0e063a60(param_1,*(undefined1 *)(param_1 + 0x24));
  }
  else if (bVar3 == 2) {
    iVar1 = FUN_0e063a94(param_1,*(undefined1 *)(param_1 + 0x24));
  }
  else {
    if ((*(byte *)(param_1 + 0x20) & 0x1f) != 0) goto LAB_0e0626d4;
    iVar1 = FUN_0e063ad8(param_1,*(undefined1 *)(param_1 + 0x21));
  }
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
    if ((*(short *)(param_1 + 0x26) == 0) || (-1 < *(char *)(param_1 + 0x20))) {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)(iVar1 + 8) + 8);
      if (UNRECOVERED_JUMPTABLE_00 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e062712. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE_00)(iVar1,param_1 + 0x20,param_2);
        return uVar2;
      }
    }
    else {
      UNRECOVERED_JUMPTABLE_00 = *(code **)(*(int *)(iVar1 + 8) + 0xc);
      if (UNRECOVERED_JUMPTABLE_00 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e062720. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar2 = (*UNRECOVERED_JUMPTABLE_00)(iVar1,param_1 + 0x20,param_2);
        return uVar2;
      }
    }
  }
LAB_0e0626d4:
  iVar1 = FUN_0e06f4ac();
  *(undefined4 *)(iVar1 + 0xc) = 0xffffff7a;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06273c. Types and names are inferred; NOT original source. */

uint FUN_0e06273c(int param_1,int param_2,uint param_3)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  byte bVar4;
  int iVar5;
  char *pcVar6;
  byte *pbVar7;
  uint uVar8;
  char cVar9;
  undefined1 uVar10;
  short sVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 extraout_r3;
  int *piVar14;
  int extraout_r3_00;
  code *pcVar15;
  int extraout_r3_01;
  uint uVar16;
  int iVar17;
  undefined4 *puVar18;
  int iVar19;
  int iVar20;
  undefined4 *puVar21;
  byte local_5c;
  undefined1 local_5b;
  byte abStack_58 [16];
  undefined4 local_48;
  uint local_44;
  undefined1 local_40;
  undefined1 local_3f;
  
  uVar12 = (uint)*(byte *)(param_2 + 0x18);
  if ((*(byte *)(param_2 + 0x18) & 0x7f) != 0) {
    return 0xfffffffb;
  }
  bVar4 = *(byte *)(param_2 + 0x19);
  if ((param_3 == 0) || (param_3 == 0xfffffff4)) {
    if ((bVar4 & 1) != 0) goto LAB_0e062790;
    if ((bVar4 & 4) == 0) goto LAB_0e062798;
    if (uVar12 == 0) goto LAB_0e062782;
LAB_0e0627cc:
    if (uVar12 == 0x80) {
      FUN_0e061ac0(param_2);
      uVar12 = 0;
      if (*(int *)(param_1 + 0x28) != 1) {
        return 0;
      }
      if (*(char *)(param_1 + 0x35) == '\0') {
        return 0;
      }
      cVar9 = *(char *)(param_1 + 0x21);
      if (cVar9 == '\x05') {
        iVar19 = *(int *)(param_1 + 0x18);
        uVar10 = *(undefined1 *)(param_1 + 0x22);
        iVar17 = *(int *)(iVar19 + 8);
        if (*(int *)(*(int *)(iVar19 + 0x10) + 0xa0) << 0x1e < 0) {
          (**(code **)(iVar17 + 0x3c))(iVar19);
          uVar12 = (**(code **)(iVar17 + 0x24))(iVar19,uVar10);
          (**(code **)(iVar17 + 0x40))(iVar19);
          cVar9 = *(char *)(param_1 + 0x21);
        }
        else {
          uVar12 = 0xffffffff;
          cVar9 = *(char *)(param_1 + 0x21);
        }
      }
      if ((cVar9 == '\x03') && (*(short *)(param_1 + 0x22) == 2)) {
        iVar19 = *(int *)(param_1 + 0x18);
        uVar2 = *(ushort *)(param_1 + 0x24);
        iVar17 = *(int *)(iVar19 + 8);
        if (*(int *)(*(int *)(iVar19 + 0x10) + 0xa0) << 0x1e < 0) {
          if (*(int *)(iVar17 + 0x28) == 0) {
            uVar12 = 0xffffff7a;
          }
          else {
            (**(code **)(iVar17 + 0x3c))(iVar19);
            uVar12 = (**(code **)(iVar17 + 0x28))(iVar19,uVar2 >> 8,0);
            (**(code **)(iVar17 + 0x40))(iVar19);
          }
        }
        else {
          uVar12 = 0xffffffff;
        }
      }
      *(undefined1 *)(param_1 + 0x35) = 0;
      return uVar12;
    }
    goto LAB_0e062798;
  }
  if ((bVar4 & 1) == 0) {
    if (param_3 != 0xffffff8f) {
      FUN_0e061ac0(param_2);
      return param_3;
    }
LAB_0e062782:
    FUN_0e061ac0(param_2);
    return uVar12 & 0xffffff7f;
  }
LAB_0e062790:
  if (uVar12 != 0) {
    if ((bVar4 & 4) == 0) goto LAB_0e062798;
    goto LAB_0e0627cc;
  }
  iVar17 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
  if (*(ushort *)(param_2 + 0x10) < 8) {
LAB_0e06286c:
    FUN_0e061ac0(param_2);
    goto LAB_0e062798;
  }
  uVar13 = (*(undefined4 **)(param_2 + 0xc))[1];
  *(undefined4 *)(param_1 + 0x20) = **(undefined4 **)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x24) = uVar13;
  if (*(int *)(param_2 + 4) == 0) goto LAB_0e06286c;
  uVar12 = (uint)*(byte *)(*(int *)(param_2 + 4) + 0x19);
  if (*(short *)(param_1 + 0x26) == 0) {
    iVar19 = uVar12 << 0x1d;
  }
  else {
    iVar19 = uVar12 << 0x1e;
  }
  if (-1 < iVar19) goto LAB_0e06286c;
  iVar19 = FUN_0e061b48(0);
  *(undefined4 *)(iVar17 + 0xa8) = 0;
  if (iVar19 == 0) goto LAB_0e062798;
  iVar17 = FUN_0e06f4ac();
  bVar4 = *(byte *)(param_1 + 0x20);
  uVar12 = (uint)bVar4;
  *(undefined4 *)(iVar17 + 0xc) = extraout_r3;
  if ((bVar4 & 0x60) != 0) {
    if ((uVar12 & 0x7f) >> 5 != 3) {
LAB_0e062852:
      uVar12 = FUN_0e0626bc(param_1,iVar19);
      goto LAB_0e06285c;
    }
    goto switchD_0e0628a4_caseD_3;
  }
  uVar8 = (uint)*(ushort *)(param_1 + 0x26);
  uVar10 = *(undefined1 *)(param_1 + 0x21);
  if (uVar8 != 0) {
    if (-1 < (char)bVar4) {
      switch(uVar10) {
      case 5:
        goto switchD_0e0628a4_caseD_5;
      case 9:
        goto switchD_0e0628a4_caseD_9;
      }
      goto switchD_0e0628a4_caseD_3;
    }
    switch(uVar10) {
    case 0:
      sVar11 = *(short *)(param_1 + 0x24);
      if (uVar8 == 2) {
        if (*(char *)(param_1 + 0x2c) == '\0') goto LAB_0e0629ec;
        if (*(char *)(param_1 + 0x2c) == '\x01') {
          if (sVar11 != 0) goto LAB_0e0629ec;
          if ((bVar4 & 0x1f) == 0) goto LAB_0e062e6c;
          if ((uVar12 & 0x1f) == 2) goto LAB_0e062a7a;
          uVar12 = 0;
        }
        else if ((bVar4 & 0x1f) == 0) {
          if (sVar11 != 0) goto LAB_0e0629ec;
LAB_0e062e6c:
          uVar12 = *(byte *)(param_1 + 0x60) >> 2 & 2;
        }
        else if ((uVar12 & 0x1f) == 2) {
LAB_0e062a7a:
          uVar12 = FUN_0e063f78(param_1,(char)sVar11);
        }
        else {
          uVar12 = 0;
        }
        uVar8 = FUN_0e061bfc(iVar19 + 0xc);
        if (uVar8 < *(ushort *)(param_1 + 0x26)) goto LAB_0e062db4;
        FUN_0e061bac(iVar19 + 0xc,uVar12);
        goto LAB_0e06290c;
      }
      break;
    case 6:
      uVar10 = (undefined1)*(ushort *)(param_1 + 0x22);
      if ((bVar4 & 0x1f) != 0) goto LAB_0e062852;
      iVar17 = (*(ushort *)(param_1 + 0x22) >> 8) - 1;
      switch(iVar17) {
      case 0:
        iVar17 = iVar19 + 0xc;
        uVar12 = FUN_0e061bfc(iVar17);
        if (uVar8 < uVar12) {
          uVar12 = (uint)*(ushort *)(param_1 + 0x26);
        }
        else {
          uVar12 = FUN_0e061bfc(iVar17);
        }
        iVar20 = FUN_0e062244(param_1);
        if (iVar20 == 0) {
          pbVar7 = *(byte **)(param_1 + 100);
        }
        else {
          if (iVar20 != 1) break;
          pbVar7 = *(byte **)(param_1 + 0x68);
        }
        uVar8 = (uint)*pbVar7;
        if (uVar12 <= *pbVar7) {
          uVar8 = uVar12;
        }
        FUN_0e061b84(iVar17,pbVar7,uVar8);
        goto LAB_0e06290c;
      case 1:
        uVar12 = FUN_0e0625ac(param_1,iVar19,uVar10,0);
        goto LAB_0e06285c;
      case 2:
        iVar17 = FUN_0e06246c(param_1,3);
        if (iVar17 != 0) {
          iVar20 = FUN_0e0625a0();
          if (iVar20 != 0) {
            local_5c = 0;
            uVar2 = *(ushort *)(param_1 + 0x26);
            local_5b = *(undefined1 *)(iVar17 + 0x11);
            if ((*(uint *)(iVar17 + 8) & 0x2ff00) == 0x20300) {
              iVar17 = FUN_0e067a94(abStack_58);
              if (iVar17 < 0) break;
              pcVar6 = (char *)&local_48;
              pbVar7 = abStack_58;
              for (iVar20 = 0; iVar17 != iVar20; iVar20 = iVar20 + 1) {
                cVar9 = "/0123456789ABCDEF"[(*pbVar7 & 0xf) + 1];
                *pcVar6 = "/0123456789ABCDEF"[(*pbVar7 >> 4) + 1];
                pcVar6[1] = cVar9;
                pcVar6 = pcVar6 + 2;
                pbVar7 = pbVar7 + 1;
              }
              local_5c = (char)iVar17 * '\x04' + 2;
              puVar18 = &local_48;
            }
            else {
              local_5c = *(byte *)(iVar17 + 0x10);
              puVar18 = *(undefined4 **)(iVar17 + 0xc);
            }
            iVar17 = iVar19 + 0xc;
            uVar8 = FUN_0e061bfc(iVar17);
            uVar12 = (uint)local_5c;
            if ((uint)uVar2 <= (uint)local_5c) {
              uVar12 = (uint)uVar2;
            }
            if (uVar8 < uVar12) {
              uVar12 = FUN_0e061bfc(iVar17);
            }
            uVar8 = uVar12;
            if (1 < uVar12) {
              uVar8 = 2;
            }
            uVar12 = uVar12 - uVar8;
            FUN_0e061b84(iVar17,&local_5c);
            for (puVar21 = puVar18; (undefined4 *)((int)puVar18 + (uVar12 >> 1)) != puVar21;
                puVar21 = (undefined4 *)((int)puVar21 + 1)) {
              FUN_0e061bac(iVar17,*(undefined1 *)puVar21);
            }
            if ((uVar12 & 1) != 0) {
              FUN_0e061b98(iVar17,*(undefined1 *)((int)puVar18 + (uVar12 >> 1)));
            }
            goto LAB_0e06290c;
          }
          local_48 = CONCAT22(**(undefined2 **)(iVar17 + 0xc),*(undefined2 *)(iVar17 + 0x10));
LAB_0e062ba6:
          iVar17 = iVar19 + 0xc;
          uVar2 = *(ushort *)(param_1 + 0x26);
          uVar12 = FUN_0e061bfc(iVar17);
          if (uVar2 < uVar12) {
            uVar12 = (uint)*(ushort *)(param_1 + 0x26);
          }
          else {
            uVar12 = FUN_0e061bfc(iVar17);
          }
          uVar8 = local_48 & 0xff;
          if (uVar12 <= (local_48 & 0xff)) {
            uVar8 = uVar12;
          }
          FUN_0e061b84(iVar17,&local_48,uVar8);
          goto LAB_0e06290c;
        }
        break;
      case 5:
        iVar17 = FUN_0e062244(param_1,iVar17,uVar10);
        piVar14 = (int *)(param_1 + 100);
        if (iVar17 == 0) {
          piVar14 = (int *)(param_1 + 0x68);
        }
        iVar17 = *piVar14;
        local_48 = CONCAT22(*(undefined2 *)(iVar17 + 2),0x60a);
        local_44 = *(uint *)(iVar17 + 4);
        local_40 = *(undefined1 *)(iVar17 + 0x11);
        local_3f = 0;
        iVar17 = FUN_0e062250(param_1);
        if (iVar17 == 1) goto LAB_0e062ba6;
        goto LAB_0e062b6c;
      case 6:
        uVar12 = FUN_0e0625ac(param_1,iVar19,uVar10,1);
LAB_0e06285c:
        if (uVar12 != 0) {
LAB_0e062860:
          FUN_0e061ac0(iVar19);
          return uVar12;
        }
LAB_0e06290c:
        iVar17 = FUN_0e06f4ac();
        if (*(int *)(iVar17 + 0xc) == 0) {
          sVar11 = *(short *)(param_1 + 0x26);
LAB_0e06291a:
          *(undefined4 *)(param_1 + 0x28) = 1;
          uVar12 = 0;
          if ((sVar11 != 0) && (uVar12 = (uint)(*(byte *)(param_1 + 0x20) >> 7), uVar12 == 0)) {
            do {
              iVar19 = FUN_0e061b48(0,iVar19);
              if (iVar19 == 0) goto LAB_0e062798;
              uVar12 = (uint)*(byte *)(iVar19 + 0x19);
            } while (-1 < (int)(uVar12 << 0x1d));
          }
          if ((*(byte *)(iVar19 + 0x18) & 0x7f) != 0) {
            return 0xffffffea;
          }
          uVar8 = (uint)*(byte *)(iVar19 + 0x18) << 0x18;
          if ((int)uVar8 < 0) {
            iVar17 = FUN_0e06232c();
            if (iVar17 != 0) {
              return 0xffffffff;
            }
            uVar16 = (uint)*(ushort *)(iVar19 + 0x10);
            uVar8 = (uint)*(ushort *)(param_1 + 0x26);
            if (uVar16 != 0) {
              if (uVar8 <= uVar16) {
                uVar16 = uVar8;
              }
              if (((uVar16 < uVar8) && ((uVar16 & 0x3f) == 0)) && (*(char *)(iVar19 + 0x18) < '\0'))
              {
                *(byte *)(iVar19 + 0x19) = *(byte *)(iVar19 + 0x19) | 8;
              }
            }
          }
          uVar12 = FUN_0e064ab4(*(undefined4 *)(param_1 + 0x18),iVar19,uVar8,uVar12);
          return uVar12;
        }
        goto LAB_0e062880;
      case 0xe:
        iVar17 = FUN_0e062244(param_1,iVar17,uVar10);
        if (iVar17 == 0) {
          iVar17 = *(int *)(param_1 + 100);
        }
        else {
          if (iVar17 != 1) goto LAB_0e062b6c;
          iVar17 = *(int *)(param_1 + 0x68);
        }
        if (0x200 < *(ushort *)(iVar17 + 2)) {
          local_48 = 0x50f05;
          piVar14 = *(int **)(param_1 + 0x48);
          local_44 = local_44 & 0xffffff00;
          if ((int *)(param_1 + 0x48) != piVar14) {
            for (; piVar14 != (int *)0x0; piVar14 = (int *)*piVar14) {
              if (*(char *)((int)piVar14 + 0x11) == '\x0f') {
                local_48 = CONCAT22((ushort)*(byte *)(piVar14 + 4) + local_48._2_2_,
                                    (undefined2)local_48);
                local_44 = CONCAT31(local_44._1_3_,(char)local_44 + '\x01');
              }
              if (piVar14 == (int *)*(int *)(param_1 + 0x4c)) break;
            }
          }
          iVar17 = iVar19 + 0xc;
          uVar8 = FUN_0e061bfc(iVar17);
          uVar12 = local_48 >> 0x10;
          if ((uint)*(ushort *)(param_1 + 0x26) <= local_48 >> 0x10) {
            uVar12 = (uint)*(ushort *)(param_1 + 0x26);
          }
          if (uVar8 < uVar12) {
            uVar12 = FUN_0e061bfc(iVar17);
          }
          if (uVar12 < 6) {
            uVar8 = 0;
          }
          else {
            uVar8 = uVar12 - 5;
          }
          uVar16 = local_48 & 0xff;
          if (uVar12 <= (local_48 & 0xff)) {
            uVar16 = uVar12;
          }
          FUN_0e061b84(iVar17,&local_48,uVar16);
          if ((uVar8 != 0) &&
             (piVar14 = *(int **)(param_1 + 0x48), piVar14 != (int *)(param_1 + 0x48))) {
            for (; piVar14 != (int *)0x0; piVar14 = (int *)*piVar14) {
              if (*(char *)((int)piVar14 + 0x11) == '\x0f') {
                uVar12 = (uint)*(byte *)(piVar14 + 4);
                if (uVar8 <= *(byte *)(piVar14 + 4)) {
                  uVar12 = uVar8;
                }
                FUN_0e061b84(iVar17,piVar14[3],uVar12);
                if (uVar8 < *(byte *)(piVar14 + 4)) {
                  uVar8 = 0;
                }
                else {
                  uVar8 = uVar8 - *(byte *)(piVar14 + 4);
                }
                if (uVar8 == 0) break;
              }
              if (piVar14 == (int *)*(int *)(param_1 + 0x4c)) break;
            }
          }
          goto LAB_0e06290c;
        }
LAB_0e062b6c:
        iVar17 = FUN_0e06f4ac();
        *(undefined4 *)(iVar17 + 0xc) = 0xffffff7a;
        goto LAB_0e06290c;
      }
      break;
    case 8:
      uVar10 = *(undefined1 *)(param_1 + 0x34);
      if (*(char *)(param_1 + 0x2c) == '\0') goto LAB_0e0629ec;
LAB_0e062aac:
      if (uVar8 == 1) {
        uVar12 = FUN_0e061bfc(iVar19 + 0xc);
        if (*(ushort *)(param_1 + 0x26) <= uVar12) {
          FUN_0e061b98(iVar19 + 0xc,uVar10);
          goto LAB_0e06290c;
        }
LAB_0e062db4:
        iVar17 = FUN_0e06f4ac();
        *(undefined4 *)(iVar17 + 0xc) = 0xfffffff4;
        goto LAB_0e062880;
      }
      break;
    case 10:
      if (((uVar12 & 0x1f) != 1) || (iVar17 = FUN_0e063754(param_1), iVar17 == 0))
      goto LAB_0e0629ec;
      uVar12 = (uint)*(ushort *)(param_1 + 0x24);
      if ((uVar12 < 0x100) && ((uVar12 <= *(byte *)(*(int *)(iVar17 + 4) + 4) && (uVar12 < 0x10))))
      {
        uVar10 = *(undefined1 *)(uVar12 + param_1 + 0x36);
        uVar8 = (uint)*(ushort *)(param_1 + 0x26);
        goto LAB_0e062aac;
      }
    }
    goto switchD_0e0628a4_caseD_3;
  }
  sVar11 = 0;
  switch(uVar10) {
  case 1:
    sVar1 = *(short *)(param_1 + 0x24);
    if (*(char *)(param_1 + 0x2c) != '\0') {
      if (*(char *)(param_1 + 0x2c) == '\x01') {
        if (sVar1 == 0) {
          if ((bVar4 & 0x1f) == 0) goto LAB_0e062e12;
          goto LAB_0e062cf2;
        }
      }
      else {
        if ((bVar4 & 0x1f) != 0) {
LAB_0e062cf2:
          if (((uVar12 & 0x1f) != 2) || (*(short *)(param_1 + 0x22) != 0)) goto LAB_0e06291a;
          uVar10 = (undefined1)sVar1;
          FUN_0e063f4c(param_1,uVar10);
          iVar17 = FUN_0e06f4ac();
          *(int *)(iVar17 + 0xc) = extraout_r3_01;
          if (extraout_r3_01 == -1) goto LAB_0e063104;
          iVar17 = FUN_0e063a94(param_1,uVar10);
          if (iVar17 != 0) {
            pcVar15 = (code *)**(undefined4 **)(*(int *)(iVar17 + 4) + 8);
            if (pcVar15 != (code *)0x0) {
              (*pcVar15)(*(int *)(iVar17 + 4),uVar10,0);
            }
          }
          goto LAB_0e06290c;
        }
        if (sVar1 == 0) {
LAB_0e062e12:
          if (*(short *)(param_1 + 0x22) == 1) {
            *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) & 0xf7;
          }
          goto LAB_0e06291a;
        }
      }
    }
LAB_0e0629ec:
    iVar17 = FUN_0e06f4ac();
    *(undefined4 *)(iVar17 + 0xc) = 0xffffffff;
    goto LAB_0e062880;
  case 3:
    sVar1 = *(short *)(param_1 + 0x22);
    uVar2 = *(ushort *)(param_1 + 0x24);
    cVar9 = (char)uVar2;
    if (sVar1 != 2) {
      if (*(char *)(param_1 + 0x2c) != '\0') {
        if (*(char *)(param_1 + 0x2c) == '\x01') {
          if (uVar2 == 0) {
            if ((bVar4 & 0x1f) == 0) goto LAB_0e062e9e;
            goto LAB_0e062c90;
          }
        }
        else {
          if ((bVar4 & 0x1f) != 0) {
LAB_0e062c90:
            if (((uVar12 & 0x1f) != 2) || (sVar1 != 0)) goto LAB_0e06291a;
            FUN_0e063f20(param_1,cVar9);
            iVar17 = FUN_0e06f4ac();
            *(int *)(iVar17 + 0xc) = extraout_r3_00;
            if (extraout_r3_00 == -1) goto LAB_0e063104;
            iVar17 = FUN_0e063a94(param_1,cVar9);
            if (iVar17 != 0) {
              pcVar15 = (code *)**(undefined4 **)(*(int *)(iVar17 + 4) + 8);
              if (pcVar15 != (code *)0x0) {
                (*pcVar15)(*(int *)(iVar17 + 4),cVar9,1);
              }
            }
            goto LAB_0e06290c;
          }
          if (uVar2 == 0) {
LAB_0e062e9e:
            if (sVar1 == 1) {
              *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 8;
            }
            goto LAB_0e06291a;
          }
        }
      }
      goto LAB_0e0629ec;
    }
    if ((*(byte *)(param_1 + 0x20) & 0x1f) == 0 && cVar9 == '\0') {
      iVar17 = *(int *)(param_1 + 0x18);
      iVar20 = *(int *)(iVar17 + 8);
      if ((*(int *)(*(int *)(iVar17 + 0x10) + 0xa0) << 0x1e < 0) && (*(int *)(iVar20 + 0x28) != 0))
      {
        (**(code **)(iVar20 + 0x3c))(iVar17);
        iVar5 = (**(code **)(iVar20 + 0x28))(iVar17,uVar2 >> 8,1);
        (**(code **)(iVar20 + 0x40))(iVar17);
        if (iVar5 == 0) {
          *(undefined1 *)(param_1 + 0x35) = 1;
          goto LAB_0e06290c;
        }
      }
    }
    break;
  case 5:
switchD_0e0628a4_caseD_5:
    iVar17 = *(int *)(param_1 + 0x18);
    uVar2 = *(ushort *)(param_1 + 0x22);
    if (((0x7f < uVar2) || (*(short *)(param_1 + 0x24) != 0 || *(ushort *)(param_1 + 0x26) != 0)) ||
       ((*(byte *)(param_1 + 0x20) & 0x1f) != 0)) break;
    cVar9 = *(char *)(param_1 + 0x2c);
    if (cVar9 == '\x02') goto LAB_0e0629ec;
    if (*(int *)(*(int *)(iVar17 + 0x10) + 0x80) << 0x1c < 0) {
      iVar20 = *(int *)(iVar17 + 8);
      if (-1 < *(int *)(*(int *)(iVar17 + 0x10) + 0xa0) << 0x1e) {
LAB_0e063104:
        uVar12 = 0xffffffff;
        goto LAB_0e062860;
      }
      (**(code **)(iVar20 + 0x3c))(iVar17);
      uVar12 = (**(code **)(iVar20 + 0x24))(iVar17,(char)uVar2);
      (**(code **)(iVar20 + 0x40))(iVar17);
      if (uVar12 != 0) goto LAB_0e062860;
      cVar9 = *(char *)(param_1 + 0x2c);
    }
    else {
      *(undefined1 *)(param_1 + 0x35) = 1;
    }
    if ((cVar9 == '\x01') && (*(short *)(param_1 + 0x22) == 0)) {
      uVar10 = 0;
    }
    else {
      uVar10 = 1;
    }
    *(undefined1 *)(param_1 + 0x2c) = uVar10;
    goto LAB_0e06290c;
  case 9:
switchD_0e0628a4_caseD_9:
    uVar13 = FUN_0e062244(param_1);
    uVar2 = *(ushort *)(param_1 + 0x22);
    if (((uVar2 < 0x100) && (*(short *)(param_1 + 0x26) == 0)) &&
       ((*(byte *)(param_1 + 0x20) & 0x1f) == 0)) {
      if (*(char *)(param_1 + 0x2c) != '\0') {
        uVar3 = 0;
        if (uVar2 != 0) {
          iVar17 = FUN_0e063778(param_1,uVar13,(char)uVar2);
          if (iVar17 == 0) goto LAB_0e0629ec;
          uVar3 = *(ushort *)(param_1 + 0x22);
        }
        if (*(byte *)(param_1 + 0x34) != uVar3) {
          uVar12 = FUN_0e063788(param_1,uVar3 & 0xff);
          if (uVar12 != 0) goto LAB_0e062860;
          if (*(short *)(param_1 + 0x22) == 0) {
            uVar10 = 1;
          }
          else {
            uVar10 = 2;
          }
          *(undefined1 *)(param_1 + 0x2c) = uVar10;
          FUN_0e064050(param_1,5);
        }
        goto LAB_0e06290c;
      }
      goto LAB_0e0629ec;
    }
    break;
  case 0xb:
    if ((((*(byte *)(param_1 + 0x20) & 0x1f) != 1) || (0xff < *(ushort *)(param_1 + 0x22))) ||
       (0xff < *(ushort *)(param_1 + 0x24))) break;
    if (*(char *)(param_1 + 0x2c) != '\x02') goto LAB_0e0629ec;
    uVar12 = FUN_0e063d7c(param_1,(char)*(ushort *)(param_1 + 0x24),
                          (char)*(ushort *)(param_1 + 0x22));
    if (uVar12 != 0xfffffffe) goto LAB_0e06285c;
    iVar17 = FUN_0e06f4ac();
    *(undefined4 *)(iVar17 + 0xc) = 0xfffffffe;
    goto LAB_0e062880;
  }
switchD_0e0628a4_caseD_3:
  iVar17 = FUN_0e06f4ac();
  *(undefined4 *)(iVar17 + 0xc) = 0xffffff7a;
LAB_0e062880:
  FUN_0e061ac0(iVar19);
LAB_0e062798:
  if ((*(short *)(param_1 + 0x26) == 0) || (*(char *)(param_1 + 0x20) < '\0')) {
    uVar12 = FUN_0e0649e8(*(undefined4 *)(param_1 + 0x18),0x80);
  }
  else {
    uVar12 = FUN_0e0649e8(*(undefined4 *)(param_1 + 0x18),(uint)(param_3 != 0xfffffff4) << 7);
  }
  *(undefined4 *)(param_1 + 0x28) = 0;
  return uVar12;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063134. Types and names are inferred; NOT original source. */

undefined4 FUN_0e063134(int param_1)

{
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0631f0. Types and names are inferred; NOT original source. */

void FUN_0e0631f0(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  int *piVar4;
  
  iVar2 = FUN_0e063754();
  if (iVar2 == 0) {
    return;
  }
  piVar4 = *(int **)(iVar2 + 0xc);
joined_r0x0e0631fc:
  if (piVar4 == (int *)0x0) {
    return;
  }
  do {
    cVar1 = *param_2;
    if (cVar1 == '\x03') {
      pcVar3 = *(code **)(*(int *)(piVar4[1] + 8) + 0x14);
    }
    else if (cVar1 == '\x05') {
      pcVar3 = *(code **)(*(int *)(piVar4[1] + 8) + 0x1c);
    }
    else {
      if (cVar1 != '\x02') break;
      pcVar3 = *(code **)(*(int *)(piVar4[1] + 8) + 0x18);
    }
    if (pcVar3 == (code *)0x0) break;
    (*pcVar3)();
    piVar4 = (int *)*piVar4;
    if (piVar4 == (int *)0x0) {
      return;
    }
  } while( true );
  piVar4 = (int *)*piVar4;
  goto joined_r0x0e0631fc;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063240. Types and names are inferred; NOT original source. */

void FUN_0e063240(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined1 local_24 [4];
  int local_20;
  int local_1c;
  
switchD_0e063268_default:
  FUN_0e06cc94(&DAT_23001c2c,local_24,0xffffffff,0xffffffff);
  iVar4 = *(int *)(*(int *)(local_1c + 0x10) + 0x9c);
  switch(local_24[0]) {
  case 0:
    FUN_0e064050(iVar4,0);
    goto switchD_0e063268_default;
  case 1:
    FUN_0e064050(iVar4,1,0);
    goto switchD_0e063268_default;
  case 2:
    *(byte *)(iVar4 + 0x60) = *(byte *)(iVar4 + 0x60) & 0xfb;
    if (*(char *)(iVar4 + 0x2c) == '\x02') {
      FUN_0e0631f0(iVar4,local_24);
    }
    FUN_0e064050(iVar4,2,0);
    goto switchD_0e063268_default;
  case 3:
    *(byte *)(iVar4 + 0x60) = *(byte *)(iVar4 + 0x60) | 4;
    if (*(char *)(iVar4 + 0x2c) == '\x02') {
      FUN_0e0631f0(iVar4,local_24);
    }
    FUN_0e064050(iVar4,3,0);
    goto switchD_0e063268_default;
  case 4:
    iVar1 = *(int *)(iVar4 + 0x18);
    *(byte *)(iVar4 + 0x60) = *(byte *)(iVar4 + 0x60) & 0xfb;
    iVar5 = *(int *)(iVar1 + 8);
    uVar3 = *(uint *)(*(int *)(iVar1 + 0x10) + 0xa0);
    if ((int)(uVar3 << 0x1e) < 0) {
      (**(code **)(iVar5 + 0x3c))(iVar1);
      iVar2 = (**(code **)(iVar5 + 0x24))(iVar1,0);
      (**(code **)(iVar5 + 0x40))(iVar1);
      if ((iVar2 == 0) && (iVar2 = FUN_0e063788(iVar4,0), iVar2 == 0)) {
        FUN_0e063f18(iVar4,0x80);
        iVar1 = FUN_0e064bbc(*(undefined4 *)(iVar4 + 0x18));
        *(undefined1 *)(iVar4 + 0x2c) = 0;
        *(byte *)(iVar4 + 0x60) = *(byte *)(iVar4 + 0x60) & 199 | (iVar1 == 2) << 4;
        FUN_0e064050(iVar4,4,0);
      }
      else {
        FUN_0e064050(iVar4,4,0);
        FUN_0e064050(iVar4,7,iVar2);
      }
      goto switchD_0e063268_default;
    }
    FUN_0e064050(iVar4,4,(uVar3 & 3) >> 1);
    iVar1 = -1;
    break;
  case 5:
    if (*(char *)(iVar4 + 0x2c) == '\x02') {
      FUN_0e0631f0(iVar4,local_24);
    }
    goto switchD_0e063268_default;
  case 6:
    if ((*(byte *)(local_20 + 0x18) & 0x7f) == 0) {
      iVar1 = FUN_0e06273c();
    }
    else {
      iVar1 = FUN_0e063a80(iVar4,local_20,*(undefined4 *)(local_20 + 0x1e));
    }
    if (iVar1 == 0) goto switchD_0e063268_default;
    break;
  case 7:
    goto switchD_0e063268_caseD_7;
  default:
    goto switchD_0e063268_default;
  }
  FUN_0e064050(iVar4,7,iVar1);
  goto switchD_0e063268_default;
switchD_0e063268_caseD_7:
  FUN_0e064050(iVar4,6,local_20);
  goto switchD_0e063268_default;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0633e4. Types and names are inferred; NOT original source. */

int FUN_0e0633e4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0e064ca4(*(undefined4 *)(param_1 + 0x18),&LAB_0e063144_1,param_1,param_4,param_4);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x34) = 0;
    iVar1 = FUN_0e0636c4(param_1);
    if (iVar1 != 0) {
      FUN_0e064d08(*(undefined4 *)(param_1 + 0x18));
    }
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063418. Types and names are inferred; NOT original source. */

undefined4 FUN_0e063418(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar1 = 1;
  uVar2 = *param_2;
  do {
    iVar4 = (uVar1 & 0x7f) + 0x10;
    if (uVar2 == 0) {
      return 0;
    }
    if ((int)((uVar2 >> iVar4) << 0x1f) < 0) {
      if (-1 < (int)((*param_1 >> iVar4) << 0x1f)) {
        return 0xffffffea;
      }
      *param_1 = *param_1 & ~(1 << iVar4);
      uVar2 = *param_2 & ~(1 << iVar4);
      *param_2 = uVar2;
    }
    uVar3 = 1 << (uVar1 & 0xff);
    if ((uVar2 >> (uVar1 & 0xff) & 1) != 0) {
      if (-1 < (int)((*param_1 >> (uVar1 & 0xff)) << 0x1f)) {
        return 0xffffffea;
      }
      *param_1 = *param_1 & ~uVar3;
      uVar2 = *param_2 & ~uVar3;
      *param_2 = uVar2;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 != 0x10);
  return 0;
}



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



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0636c4. Types and names are inferred; NOT original source. */

int FUN_0e0636c4(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  int *piVar4;
  
  uVar3 = (*(byte *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80) & 0x7f) >> 5;
  if (uVar3 == 2) {
    uVar2 = 0x20;
  }
  else if (uVar3 == 3) {
    uVar2 = 0x40;
  }
  else if (uVar3 == 1) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 8;
  }
  *(undefined1 *)(*(int *)(param_1 + 100) + 7) = uVar2;
  for (piVar4 = *(int **)(param_1 + 0x58); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    iVar1 = FUN_0e063488(param_1,1,piVar4);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  piVar4 = *(int **)(param_1 + 0x50);
  while( true ) {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    iVar1 = FUN_0e063488(param_1,0,piVar4);
    if (iVar1 != 0) break;
    piVar4 = (int *)*piVar4;
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063728. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e063728(int param_1,int param_2,uint param_3)

{
  code *pcVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    piVar2 = *(int **)(param_1 + 0x50);
    if (piVar2 == (int *)0x0) {
      return;
    }
  }
  else {
    if (param_2 != 1) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe063732);
      (*pcVar1)();
    }
    piVar2 = *(int **)(param_1 + 0x58);
    if (piVar2 == (int *)0x0) {
      return;
    }
  }
  do {
    if (*(byte *)(piVar2[1] + 5) == param_3) {
      return;
    }
    piVar2 = (int *)*piVar2;
  } while (piVar2 != (int *)0x0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063754. Types and names are inferred; NOT original source. */

undefined4 FUN_0e063754(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x2c) == '\x02') {
    uVar1 = FUN_0e062244();
    uVar1 = FUN_0e063728(param_1,uVar1,*(undefined1 *)(param_1 + 0x34));
    return uVar1;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063778. Types and names are inferred; NOT original source. */

bool FUN_0e063778(void)

{
  int iVar1;
  
  iVar1 = FUN_0e063728();
  return iVar1 != 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063788. Types and names are inferred; NOT original source. */

int FUN_0e063788(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  undefined8 uVar7;
  
  uVar1 = FUN_0e062244();
  if (*(char *)(param_1 + 0x34) != '\0') {
    if (*(char *)(param_1 + 0x2c) != '\x02') {
      return -0x3d;
    }
    uVar3 = FUN_0e062244(param_1);
    iVar4 = FUN_0e063728(param_1,uVar3,*(undefined1 *)(param_1 + 0x34));
    if (iVar4 == 0) {
      return -0x3d;
    }
    iVar2 = FUN_0e063cc0(param_1,iVar4);
    *(undefined4 *)(param_1 + 0x36) = 0;
    *(undefined4 *)(param_1 + 0x3a) = 0;
    *(undefined4 *)(param_1 + 0x3e) = 0;
    *(undefined4 *)(param_1 + 0x42) = 0;
    *(undefined1 *)(param_1 + 0x34) = 0;
    for (piVar6 = *(int **)(iVar4 + 0xc); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      pcVar5 = *(code **)(*(int *)(piVar6[1] + 8) + 0x24);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)();
      }
    }
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x34) = 0;
  }
  else {
    uVar7 = FUN_0e063728(param_1,uVar1,param_2);
    iVar4 = (int)uVar7;
    if (iVar4 == 0) {
      return -0x3d;
    }
    iVar2 = FUN_0e063d20(param_1,(int)((ulonglong)uVar7 >> 0x20),iVar4);
    if (iVar2 != 0) {
      return iVar2;
    }
    *(char *)(param_1 + 0x34) = (char)param_2;
    for (piVar6 = *(int **)(iVar4 + 0xc); piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      pcVar5 = *(code **)(*(int *)(piVar6[1] + 8) + 0x20);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)();
      }
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06384c. Types and names are inferred; NOT original source. */

int FUN_0e06384c(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  
  iVar7 = param_3[1];
  FUN_0e06cdac(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
  if ((int)((uint)*(byte *)(param_1 + 0x60) << 0x1f) < 0) {
    iVar6 = -0x10;
    goto LAB_0e063940;
  }
  if (param_2 == 1) {
    iVar6 = FUN_0e062250(param_1);
    if ((iVar6 != 0) &&
       ((-1 < (int)((uint)*(byte *)(iVar7 + 7) << 0x1a) ||
        (*(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80) << 0x1e < 0)))) {
      puVar3 = *(undefined4 **)(param_1 + 0x50);
      puVar8 = (undefined4 *)(param_1 + 0x58);
      if (puVar3 != (undefined4 *)0x0) {
        do {
          if (puVar3 == param_3) goto LAB_0e06393c;
          puVar3 = (undefined4 *)*puVar3;
        } while (puVar3 != (undefined4 *)0x0);
        goto LAB_0e0638b0;
      }
      puVar3 = *(undefined4 **)(param_1 + 0x58);
      if (puVar3 != (undefined4 *)0x0) goto LAB_0e0638b6;
      iVar6 = param_3[1];
LAB_0e06397c:
      cVar2 = *(char *)(*(int *)(param_1 + 0x68) + 0x11) + '\x01';
      *(char *)(iVar6 + 5) = cVar2;
      iVar6 = *(int *)(param_1 + 0x68);
LAB_0e0638da:
      *(char *)(iVar6 + 0x11) = cVar2;
      goto LAB_0e0638dc;
    }
  }
  else if (((-1 < (int)((uint)*(byte *)(iVar7 + 7) << 0x1a)) ||
           (*(int *)(*(int *)(*(int *)(param_1 + 0x18) + 0x10) + 0x80) << 0x1e < 0)) &&
          (param_2 == 0)) {
    puVar3 = *(undefined4 **)(param_1 + 0x58);
    puVar8 = (undefined4 *)(param_1 + 0x50);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = *(undefined4 **)(param_1 + 0x50);
      if (puVar3 == (undefined4 *)0x0) {
LAB_0e0638cc:
        cVar2 = *(char *)(*(int *)(param_1 + 100) + 0x11) + '\x01';
        *(char *)(param_3[1] + 5) = cVar2;
        iVar6 = *(int *)(param_1 + 100);
        goto LAB_0e0638da;
      }
    }
    else {
      do {
        if (param_3 == puVar3) goto LAB_0e06393c;
        puVar3 = (undefined4 *)*puVar3;
      } while (puVar3 != (undefined4 *)0x0);
LAB_0e0638b0:
      puVar3 = (undefined4 *)*puVar8;
      if (puVar3 == (undefined4 *)0x0) {
LAB_0e0638c8:
        if (param_2 == 0) goto LAB_0e0638cc;
        iVar6 = param_3[1];
        if (param_2 == 1) goto LAB_0e06397c;
        *(undefined1 *)(iVar6 + 5) = 1;
        goto LAB_0e0638dc;
      }
    }
LAB_0e0638b6:
    if (param_3 == puVar3) {
      uVar5 = *param_3;
      *puVar8 = uVar5;
      if ((undefined4 *)puVar8[1] == param_3) {
        puVar8[1] = uVar5;
      }
    }
    else {
      do {
        puVar4 = puVar3;
        puVar3 = (undefined4 *)*puVar4;
        if (puVar3 == (undefined4 *)0x0) goto LAB_0e0638c8;
      } while (puVar3 != param_3);
      *puVar4 = *param_3;
      if ((undefined4 *)puVar8[1] == param_3) {
        puVar8[1] = puVar4;
      }
    }
    *param_3 = 0;
LAB_0e0638dc:
    if (param_3[2] != 0) {
      iVar6 = FUN_0e0624a4(param_1);
      if (iVar6 != 0) goto LAB_0e063940;
      uVar1 = FUN_0e0625a0(param_3[2]);
      *(undefined1 *)(iVar7 + 6) = uVar1;
    }
    *param_3 = 0;
    if ((undefined4 *)puVar8[1] == (undefined4 *)0x0) {
      *puVar8 = param_3;
      puVar8[1] = param_3;
    }
    else {
      *(undefined4 *)puVar8[1] = param_3;
      puVar8[1] = param_3;
    }
    iVar6 = 0;
    goto LAB_0e063940;
  }
  iVar6 = -0x86;
LAB_0e063940:
  FUN_0e06cea8(param_1 + 4);
  return iVar6;
LAB_0e06393c:
  iVar6 = -0x16;
  goto LAB_0e063940;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0639b4. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e0639ec) */

undefined * FUN_0e0639b4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == 0) {
    puVar2 = &DAT_23001d78;
    do {
      iVar1 = FUN_0e05ba44(param_1,**(undefined4 **)(puVar2 + 4));
      if (iVar1 == 0) {
        return puVar2;
      }
      puVar2 = puVar2 + 0x18;
    } while (puVar2 < &DAT_23001dc0);
  }
  else if (param_2 == 1) {
    puVar2 = &DAT_23001dc0;
    do {
      iVar1 = FUN_0e05ba44(param_1,**(undefined4 **)(puVar2 + 4));
      if (iVar1 == 0) {
        return puVar2;
      }
      puVar2 = puVar2 + 0x18;
    } while (puVar2 < &DAT_23001e08);
  }
  return (undefined *)0x0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063a18. Types and names are inferred; NOT original source. */

int FUN_0e063a18(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  uint uVar5;
  
  pcVar4 = *(code **)(*(int *)(param_1 + 8) + 0x30);
  if ((pcVar4 != (code *)0x0) && (iVar1 = (*pcVar4)(), iVar1 != 0)) {
    iVar2 = 0;
    puVar3 = (undefined4 *)(iVar1 + -4);
    while( true ) {
      puVar3 = puVar3 + 1;
      if (((byte *)*puVar3 == (byte *)0x0) || (uVar5 = (uint)*(byte *)*puVar3, uVar5 == 0)) break;
      iVar2 = iVar2 + uVar5;
    }
    return iVar2;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063a40. Types and names are inferred; NOT original source. */

void FUN_0e063a40(void)

{
  int iVar1;
  int *piVar2;
  uint in_r3;
  
  iVar1 = FUN_0e063728();
  if (iVar1 != 0) {
    for (piVar2 = *(int **)(iVar1 + 0xc);
        (piVar2 != (int *)0x0 && ((1 << (in_r3 & 0xff) & piVar2[4]) == 0)); piVar2 = (int *)*piVar2)
    {
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063a60. Types and names are inferred; NOT original source. */

void FUN_0e063a60(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_0e063754();
  if (iVar1 != 0) {
    for (piVar2 = *(int **)(iVar1 + 0xc);
        (piVar2 != (int *)0x0 && ((1 << (param_2 & 0xff) & piVar2[4]) == 0));
        piVar2 = (int *)*piVar2) {
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063a80. Types and names are inferred; NOT original source. */

undefined4 FUN_0e063a80(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(*(int *)(param_2 + 0x1a) + 8) + 0x10);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e063a8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*UNRECOVERED_JUMPTABLE)();
    return uVar1;
  }
  return 0xffffff7a;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063a94. Types and names are inferred; NOT original source. */

int FUN_0e063a94(int param_1,uint param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar5 = param_2 & 0x7f;
  if ((int)(param_2 << 0x18) < 0) {
    uVar5 = uVar5 + 0x10;
  }
  if (*(char *)(param_1 + 0x2c) == '\x02') {
    uVar1 = *(undefined1 *)(param_1 + 0x34);
    uVar2 = FUN_0e062244();
    iVar3 = FUN_0e063728(param_1,uVar2,uVar1);
    if (iVar3 != 0) {
      for (piVar4 = *(int **)(iVar3 + 0xc); piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
        if ((1 << uVar5 & piVar4[2]) != 0) {
          return (int)piVar4;
        }
      }
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063ad8. Types and names are inferred; NOT original source. */

void FUN_0e063ad8(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  iVar1 = FUN_0e063754();
  if ((iVar1 != 0) && (piVar2 = *(int **)(iVar1 + 0xc), piVar2 != (int *)0x0)) {
    do {
      puVar3 = *(undefined4 **)(piVar2[1] + 0xc);
      if ((puVar3 != (undefined4 *)0x0) && (*(byte *)(puVar3 + 1) != 0)) {
        pbVar5 = (byte *)*puVar3;
        do {
          pbVar4 = pbVar5 + 1;
          if (*pbVar5 == param_2) {
            return;
          }
          pbVar5 = pbVar4;
        } while (pbVar4 != (byte *)*puVar3 + *(byte *)(puVar3 + 1));
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063b10. Types and names are inferred; NOT original source. */

undefined4 FUN_0e063b10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  undefined8 uVar6;
  
  uVar6 = FUN_0e0639b4(param_2,param_3);
  puVar1 = (undefined4 *)uVar6;
  if (puVar1 == (undefined4 *)0x0) {
    return 0xffffffed;
  }
  FUN_0e06cdac(param_1 + 4,(int)((ulonglong)uVar6 >> 0x20),0xffffffff,0xffffffff);
  if (-1 < (int)((uint)*(byte *)(param_1 + 0x60) << 0x1f)) {
    iVar4 = puVar1[1];
    puVar5 = puVar1 + 5;
    if ((-1 < (int)(*puVar5 << 0x1f)) &&
       ((iVar2 = *(int *)(iVar4 + 4), iVar2 == 0 || (param_1 == iVar2)))) {
      iVar2 = FUN_0e063728(param_1,param_3,param_4);
      if (iVar2 == 0) {
        uVar3 = 0xffffffc3;
      }
      else {
        *puVar1 = 0;
        if (*(undefined4 **)(iVar2 + 0x10) == (undefined4 *)0x0) {
          *(undefined4 **)(iVar2 + 0xc) = puVar1;
          *(undefined4 **)(iVar2 + 0x10) = puVar1;
        }
        else {
          **(undefined4 **)(iVar2 + 0x10) = puVar1;
          *(undefined4 **)(iVar2 + 0x10) = puVar1;
        }
        *puVar5 = *puVar5 | 1;
        uVar3 = 0;
        *(int *)(iVar4 + 4) = param_1;
      }
      goto LAB_0e063b44;
    }
  }
  uVar3 = 0xfffffff0;
LAB_0e063b44:
  FUN_0e06cea8(param_1 + 4);
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063bac. Types and names are inferred; NOT original source. */

int FUN_0e063bac(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == 1) {
    puVar2 = &DAT_23001dc0;
    do {
      if ((undefined *)0x23001e07 < puVar2) {
        return 0;
      }
      iVar1 = FUN_0e063b10(param_1,**(undefined4 **)(puVar2 + 4),1,param_3,param_4);
      puVar2 = puVar2 + 0x18;
    } while (iVar1 == 0);
  }
  else {
    if (param_2 != 0) {
      return -0x86;
    }
    puVar2 = &DAT_23001d78;
    do {
      if ((undefined *)0x23001dbf < puVar2) {
        return 0;
      }
      iVar1 = FUN_0e063b10(param_1,**(undefined4 **)(puVar2 + 4),0,param_3,param_4);
      puVar2 = puVar2 + 0x18;
    } while (iVar1 == 0);
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063c10. Types and names are inferred; NOT original source. */

int FUN_0e063c10(int param_1,int param_2,int param_3,uint param_4,char param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = *(int *)(param_2 + 4);
  uVar1 = FUN_0e062244();
  pcVar4 = *(code **)(*(int *)(iVar5 + 8) + 0x30);
  if ((pcVar4 == (code *)0x0) ||
     (puVar2 = (undefined4 *)(*pcVar4)(iVar5,uVar1), puVar2 == (undefined4 *)0x0)) {
    return -0x16;
  }
  pcVar6 = (char *)*puVar2;
  if (pcVar6 != (char *)0x0) {
    bVar3 = false;
    do {
      while( true ) {
        if (*pcVar6 == '\0') goto LAB_0e063c9e;
        if (pcVar6[1] == '\x04') break;
        if ((pcVar6[1] != '\x05') || (!bVar3)) goto LAB_0e063c4c;
        if (param_3 == 1) {
          iVar5 = FUN_0e063dfc(*(undefined4 *)(param_1 + 0x18),pcVar6,param_2 + 0xc);
        }
        else {
          if (param_3 != 2) goto LAB_0e063c94;
          iVar5 = FUN_0e063e3c(*(undefined4 *)(param_1 + 0x18),pcVar6[2],param_2 + 0xc);
        }
        if (iVar5 != 0) {
          return iVar5;
        }
LAB_0e063c94:
        puVar2 = puVar2 + 1;
        pcVar6 = (char *)*puVar2;
        bVar3 = true;
        if (pcVar6 == (char *)0x0) goto LAB_0e063c9e;
      }
      if (bVar3) {
        return 0;
      }
      if (((byte)pcVar6[2] == param_4) && (pcVar6[3] == param_5)) {
        if (pcVar6[4] == '\0') {
          return 0;
        }
        goto LAB_0e063c94;
      }
LAB_0e063c4c:
      puVar2 = puVar2 + 1;
      pcVar6 = (char *)*puVar2;
    } while (pcVar6 != (char *)0x0);
LAB_0e063c9e:
    if (bVar3) {
      return 0;
    }
  }
  return -0x3d;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063cc0. Types and names are inferred; NOT original source. */

int FUN_0e063cc0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_2 + 0xc);
  do {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    uVar3 = 1;
    do {
      uVar2 = piVar4[3];
      if (uVar2 == 0) break;
      if ((int)((uVar2 >> (uVar3 & 0x7f) + 0x10) << 0x1f) < 0) {
        iVar1 = FUN_0e063e3c(*(undefined4 *)(param_1 + 0x18),(uVar3 | 0xffffff80) & 0xff,piVar4 + 3,
                             uVar2,param_4);
        if (iVar1 != 0) {
          return iVar1;
        }
        uVar2 = (uint)piVar4[3] >> (uVar3 & 0xff);
      }
      else {
        uVar2 = uVar2 >> (uVar3 & 0xff);
      }
      if (((int)(uVar2 << 0x1f) < 0) &&
         (iVar1 = FUN_0e063e3c(*(undefined4 *)(param_1 + 0x18),uVar3 & 0xff,piVar4 + 3,uVar2 << 0x1f
                               ,param_4), iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x10);
    piVar4 = (int *)*piVar4;
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063d20. Types and names are inferred; NOT original source. */

int FUN_0e063d20(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *(int *)(param_3 + 4);
  uVar1 = *(undefined1 *)(iVar4 + 5);
  if (*(char *)(iVar4 + 4) != '\0') {
    uVar3 = 0;
    do {
      uVar5 = uVar3 & 0xff;
      iVar2 = FUN_0e063a40(param_1,param_2,uVar1,uVar5);
      uVar3 = uVar3 + 1;
      if (iVar2 == 0) {
        return -0x3d;
      }
      iVar2 = FUN_0e063c10(param_1,iVar2,1,uVar5,0);
      if (iVar2 != 0) {
        return iVar2;
      }
    } while ((int)uVar3 < (int)(uint)*(byte *)(iVar4 + 4));
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063d7c. Types and names are inferred; NOT original source. */

int FUN_0e063d7c(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  
  iVar1 = FUN_0e063a60();
  if ((iVar1 != 0) && (param_2 < 0x10)) {
    uVar4 = (uint)*(byte *)(param_1 + param_2 + 0x36);
    if (param_3 == uVar4) {
      return 0;
    }
    iVar2 = FUN_0e063c10(param_1,iVar1,0,param_2,param_3);
    if (iVar2 == 0) {
      iVar2 = FUN_0e063c10(param_1,iVar1,2,param_2,uVar4);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_0e063c10(param_1,iVar1,1,param_2,param_3);
      if (iVar2 != 0) {
        return iVar2;
      }
      pcVar3 = *(code **)(*(int *)(*(int *)(iVar1 + 4) + 8) + 4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(*(int *)(iVar1 + 4),param_2,param_3);
      }
      *(char *)(param_1 + param_2 + 0x36) = (char)param_3;
      return 0;
    }
  }
  return -2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063dfc. Types and names are inferred; NOT original source. */

void FUN_0e063dfc(undefined4 param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = FUN_0e064914(param_1,*(undefined1 *)(param_2 + 2),*(undefined1 *)(param_2 + 3),
                       *(undefined2 *)(param_2 + 4),*(undefined1 *)(param_2 + 6));
  if (iVar1 != 0) {
    return;
  }
  uVar2 = (uint)*(byte *)(param_2 + 2);
  bVar3 = *(char *)(param_2 + 2) < '\0';
  if (bVar3) {
    uVar2 = uVar2 & 0xffffff7f;
  }
  if (bVar3) {
    uVar2 = uVar2 + 0x10;
  }
  *param_3 = 1 << (uVar2 & 0xff) | *param_3;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063e3c. Types and names are inferred; NOT original source. */

int FUN_0e063e3c(undefined4 param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0e0649ac();
  if (iVar1 == 0) {
    uVar2 = param_2;
    if ((int)(param_2 << 0x18) < 0) {
      uVar2 = (param_2 & 0xffffff7f) + 0x10;
    }
    *param_3 = *param_3 & ~(1 << (uVar2 & 0xff));
    iVar1 = FUN_0e064b18(param_1,param_2);
    if (iVar1 == 0) {
      FUN_0e06e1dc();
      return 0;
    }
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063ee0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e063ee0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((*(char *)(param_2 + 0x18) < '\0') && (iVar2 = FUN_0e06232c(iVar3), iVar2 != 0)) {
    return 0xffffffff;
  }
  *(int *)(param_2 + 0x1a) = param_1;
  uVar1 = FUN_0e064ab4(*(undefined4 *)(iVar3 + 0x18),param_2);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063f18. Types and names are inferred; NOT original source. */

void FUN_0e063f18(int param_1)

{
  FUN_0e064b18(*(undefined4 *)(param_1 + 0x18));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063f20. Types and names are inferred; NOT original source. */

void FUN_0e063f20(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = FUN_0e0649e8(*(undefined4 *)(param_1 + 0x18));
  if (iVar1 != 0) {
    return;
  }
  uVar2 = param_2 << 0x18;
  bVar3 = (int)uVar2 < 0;
  if (bVar3) {
    uVar2 = param_2 & 0xffffff7f;
  }
  if (bVar3) {
    param_2 = uVar2 + 0x10;
  }
  *(uint *)(param_1 + 0x30) = 1 << (param_2 & 0xff) | *(uint *)(param_1 + 0x30);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063f4c. Types and names are inferred; NOT original source. */

void FUN_0e063f4c(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = FUN_0e064a48(*(undefined4 *)(param_1 + 0x18));
  if (iVar1 != 0) {
    return;
  }
  uVar2 = param_2 << 0x18;
  bVar3 = (int)uVar2 < 0;
  if (bVar3) {
    uVar2 = param_2 & 0xffffff7f;
  }
  if (bVar3) {
    param_2 = uVar2 + 0x10;
  }
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & ~(1 << (param_2 & 0xff));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e063f78. Types and names are inferred; NOT original source. */

uint FUN_0e063f78(int param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = (int)(param_2 << 0x18) < 0;
  if (bVar1) {
    param_2 = param_2 & 0xffffff7f;
  }
  if (bVar1) {
    param_2 = param_2 + 0x10;
  }
  return *(uint *)(param_1 + 0x30) >> (param_2 & 0xff) & 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064024. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064024(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_0e06cdac(param_1 + 4,param_2,0xffffffff,0xffffffff,param_4);
  if (*(int *)(param_1 + 0x1c) == 0) {
    *(undefined4 *)(param_1 + 0x1c) = param_2;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffff88;
  }
  FUN_0e06cea8(param_1 + 4);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064050. Types and names are inferred; NOT original source. */

void FUN_0e064050(int param_1,undefined1 param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *local_14;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar5 = FUN_0e06cae4(&DAT_23001b48,&local_14,0,0);
    if (iVar5 == 0) {
      local_14[1] = param_1;
      *(undefined1 *)(local_14 + 2) = param_2;
      local_14[3] = param_3;
      puVar3 = DAT_23006984;
      uVar6 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar6 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      *local_14 = 0;
      puVar4 = local_14;
      if (DAT_23006984 != (undefined4 *)0x0) {
        *DAT_23006984 = local_14;
        puVar4 = DAT_23006980;
      }
      DAT_23006980 = puVar4;
      DAT_23006984 = local_14;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_0e06d630(&DAT_23000238,puVar3,0,0);
    }
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064144. Types and names are inferred; NOT original source. */

void FUN_0e064144(int param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar2 + 0x10);
  iVar5 = *(int *)(iVar3 + 4);
  if ((*(char *)(**(int **)(iVar2 + 4) + 0x22) == *(char *)(param_2 + 0x18)) &&
     (pcVar1 = *(code **)(iVar5 + 0x1c), pcVar1 != (code *)0x0)) {
    if (param_3 == 0) {
      (*pcVar1)(iVar2,*(undefined2 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0xc));
    }
    FUN_0e06d43c(iVar3 + 0x24);
    if (*(char *)(**(int **)(*(int *)(param_1 + 0x10) + 4) + 0x14) != *(char *)(param_2 + 0x18))
    goto LAB_0e063f10;
  }
  else if (*(char *)(**(int **)(iVar2 + 4) + 0x14) != *(char *)(param_2 + 0x18)) goto LAB_0e063f10;
  pcVar1 = *(code **)(iVar5 + 0x18);
  if (pcVar1 == (code *)0x0) {
    FUN_0e06d0d0(iVar3 + 0x14);
  }
  else {
    (*pcVar1)(iVar2);
  }
LAB_0e063f10:
  FUN_0e064ba0(*(undefined4 *)(iVar4 + 0x18),param_2);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064210. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064210(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  *piVar1 = param_1;
  FUN_0e06d0b4(piVar1 + 5,0,1);
  FUN_0e06d3f0(piVar1 + 9,&LAB_0e064238_1);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064288. Types and names are inferred; NOT original source. */

int FUN_0e064288(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(iVar3 + 4);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);
  if (*(int *)(iVar3 + 0x10) << 0x1f < 0) {
    iVar2 = **(int **)(*(int *)(iVar5 + 0x10) + 4);
    uVar1 = *(undefined1 *)(iVar2 + 0x14);
    iVar2 = FUN_0e061a98(*(undefined4 *)(*(int *)(param_1 + 4) + 0xc),param_3,param_2,iVar2,0,0);
    if (iVar2 == 0) {
      return -0xc;
    }
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *(undefined1 *)(iVar2 + 0x18) = uVar1;
    *(undefined4 *)(iVar2 + 0x1c) = 0;
    *(undefined2 *)(iVar2 + 0x20) = 0;
    uVar6 = FUN_0e063ee0(iVar5,iVar2);
    if ((int)uVar6 != 0) {
      FUN_0e061ac0(iVar2);
      return (int)uVar6;
    }
    iVar5 = 0;
    if (*(int *)(iVar4 + 0x18) == 0) {
      FUN_0e06d118(iVar3 + 0x14,(int)((ulonglong)uVar6 >> 0x20),0xffffffff,0xffffffff);
      return 0;
    }
  }
  else {
    iVar5 = -0xd;
  }
  return iVar5;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064504. Types and names are inferred; NOT original source. */

void FUN_0e064504(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0e064508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 8) + 4))();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06450c. Types and names are inferred; NOT original source. */

void FUN_0e06450c(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0e064516. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(param_1 + 8) + 8))();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064518. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e06453a) */
/* WARNING: Removing unreachable block (ram,0x0e06454a) */
/* WARNING: Removing unreachable block (ram,0x0e06453e) */
/* WARNING: Removing unreachable block (ram,0x0e064550) */
/* WARNING: Removing unreachable block (ram,0x0e064544) */

void FUN_0e064518(void)

{
  undefined1 local_24 [16];
  
  do {
    FUN_0e06cc94(&DAT_23001bdc,local_24,0xffffffff,0xffffffff);
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0645e8. Types and names are inferred; NOT original source. */

uint FUN_0e0645e8(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  param_2 = param_2 & 3;
  uVar1 = (param_1 & 0xffffff) >> 0x10;
  if (param_2 == 2) {
    return (uVar1 & 7) >> 2;
  }
  if (param_2 == 3) {
    uVar2 = uVar1 & 2;
  }
  else {
    if (param_2 != 1) {
      return uVar1 & 1;
    }
    uVar2 = uVar1 & 8;
  }
  if (uVar2 != 0) {
    if ((param_3 & 0x1800) == 0) {
      return 1;
    }
    return (uVar1 & 0x1f) >> 4;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06462c. Types and names are inferred; NOT original source. */

void FUN_0e06462c(int param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(param_1 + 0x10) + 0xa0);
  if (param_2 != 0) {
    *puVar1 = *puVar1 | 4;
    return;
  }
  *puVar1 = *puVar1 & 0xfffffffb;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06465c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06465c(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar1 = uVar1 + 0x10;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x10) + uVar1 * 4);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064670. Types and names are inferred; NOT original source. */

uint FUN_0e064670(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar1 = uVar1 + 0x10;
  }
  return (*(byte *)(*(int *)(*(int *)(param_1 + 0x10) + uVar1 * 4) + 0x14) & 0x1f) >> 4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064688. Types and names are inferred; NOT original source. */

void FUN_0e064688(int param_1,uint param_2,byte param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar1 = uVar1 + 0x10;
  }
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + uVar1 * 4);
  *(byte *)(iVar2 + 0x14) = *(byte *)(iVar2 + 0x14) & 0xef | (param_3 & 1) << 4;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0646a4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0646a4(int param_1,int param_2)

{
  uint uVar1;
  
  if (-1 < *(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f) {
    uVar1 = *(byte *)(param_2 + 0x18) & 0xf;
    if ((int)((uint)*(byte *)(param_2 + 0x18) << 0x18) < 0) {
      uVar1 = uVar1 + 0x10;
    }
    *(int *)(*(int *)(param_1 + 0x10) + uVar1 * 4) = param_2;
    FUN_0e06cff8();
    return 0;
  }
  return 0xfffffff3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0646d4. Types and names are inferred; NOT original source. */

void FUN_0e0646d4(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar2 = uVar2 + 0x10;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + uVar2 * 4);
  if (iVar1 != 0) {
    FUN_0e06d038(iVar1,param_2 << 0x18,0,0);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0646f0. Types and names are inferred; NOT original source. */

int FUN_0e0646f0(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar2 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar2 = uVar2 + 0x10;
  }
  piVar3 = *(int **)(*(int *)(param_1 + 0x10) + uVar2 * 4);
  if (piVar3 != (int *)0x0) {
    uVar5 = FUN_0e06d038(piVar3,param_2 << 0x18,0,0);
    iVar1 = (int)uVar5;
    if (iVar1 != 0) {
      do {
        iVar4 = (int)uVar5;
        if (*piVar3 == 0) {
          return iVar1;
        }
        uVar5 = FUN_0e06d038(piVar3,(int)((ulonglong)uVar5 >> 0x20),0,0);
        *(int *)(iVar4 + 4) = (int)uVar5;
      } while ((int)uVar5 != 0);
      return iVar1;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064738. Types and names are inferred; NOT original source. */

uint * FUN_0e064738(int param_1,uint param_2)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar3 = uVar3 + 0x10;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x10) + uVar3 * 4);
  if (piVar1 != (int *)0x0) {
    puVar2 = (uint *)*piVar1;
    if ((puVar2 != (uint *)0x0) && ((*puVar2 & 3) != 0)) {
      puVar2 = (uint *)puVar2[1];
    }
    return puVar2;
  }
  return (uint *)0x0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064750. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06d008(undefined4 param_1,undefined4 param_2)

{
  FUN_0e06cf2c(param_1,0,param_2,0,1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064754. Types and names are inferred; NOT original source. */

void FUN_0e064754(int param_1)

{
  *(byte *)(param_1 + 0x19) = *(byte *)(param_1 + 0x19) & 0xf8 | 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064764. Types and names are inferred; NOT original source. */

uint FUN_0e064764(int param_1)

{
  return (*(byte *)(param_1 + 0x19) & 0xf) >> 3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06476c. Types and names are inferred; NOT original source. */

void FUN_0e06476c(int param_1)

{
  *(byte *)(param_1 + 0x19) = *(byte *)(param_1 + 0x19) & 0xf7;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064778. Types and names are inferred; NOT original source. */

void FUN_0e064778(int param_1,undefined1 param_2,undefined4 param_3)

{
  undefined1 local_14 [4];
  undefined4 local_10;
  int local_c;
  
  local_14[0] = param_2;
  local_10 = param_3;
  local_c = param_1;
  (**(code **)(*(int *)(param_1 + 0x10) + 0x98))(param_1,local_14);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064798. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064798(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_14 [4];
  int local_10;
  int iStack_c;
  
  local_14[0] = 6;
  iVar2 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar2 + 0xa0) << 0x1f < 0) {
    *(undefined4 *)(param_2 + 0x1e) = param_3;
    local_10 = param_2;
    iStack_c = param_1;
    uVar1 = (**(code **)(iVar2 + 0x98))(param_1,local_14);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0647cc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0647cc(int param_1,uint param_2,uint param_3,ushort *param_4)

{
  int iVar1;
  ushort uVar2;
  int extraout_r2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  ushort *puVar7;
  
  iVar5 = *(int *)(param_1 + 8);
  puVar7 = param_4;
  if ((int)(param_2 << 0x18) < 0) {
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + ((param_2 & 0xf) + 0x10) * 4);
    if (iVar4 == 0) {
      return 0xffffffed;
    }
    (**(code **)(iVar5 + 0x3c))();
    uVar3 = *param_4;
    iVar1 = (uint)*(byte *)(iVar4 + 0x12) << 0x1a;
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x10) + (param_2 & 0xf) * 4);
    if (iVar4 == 0) {
      return 0xffffffed;
    }
    (**(code **)(iVar5 + 0x3c))();
    uVar3 = *param_4;
    iVar1 = (uint)*(byte *)(iVar4 + 0x12) << 0x19;
  }
  if (iVar1 < 0) {
    uVar6 = *(ushort *)(iVar4 + 0x10);
    if (((uVar3 & 0x7ff) <= (uVar6 & 0x7ff)) &&
       (iVar4 = FUN_0e0645e8(*(undefined4 *)(iVar4 + 0x10),param_3,uVar3,uVar3 & 0x7ff,puVar7),
       iVar4 != 0)) {
      if (extraout_r2 == 0) {
        if (*(int *)(*(int *)(param_1 + 0x10) + 0x80) << 0x1f < 0) {
          uVar3 = 0x400;
          uVar2 = 0x200;
        }
        else {
          uVar3 = 0x40;
          uVar2 = uVar3;
        }
        if ((param_3 & 3) == 2) {
          if (uVar2 <= uVar6) {
            uVar6 = uVar2;
          }
        }
        else {
          if ((param_3 & 3) != 3) goto LAB_0e064816;
          if (uVar3 <= uVar6) {
            uVar6 = uVar3;
          }
        }
        *param_4 = uVar6;
      }
LAB_0e064816:
      (**(code **)(iVar5 + 0x40))(param_1);
      return 0;
    }
  }
  (**(code **)(iVar5 + 0x40))(param_1);
  return 0xffffff7a;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064888. Types and names are inferred; NOT original source. */

int FUN_0e064888(int param_1,uint param_2,undefined4 param_3,ushort param_4,undefined1 param_5)

{
  int iVar1;
  undefined2 extraout_r2;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = param_2 & 0xf;
  if ((char)param_2 < '\0') {
    uVar2 = uVar2 + 0x10;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + uVar2 * 4);
  iVar4 = *(int *)(param_1 + 8);
  if (iVar3 != 0) {
    if ((int)((uint)*(byte *)(iVar3 + 0x14) << 0x1f) < 0) {
      return -0x78;
    }
    if ((char)param_2 < '\0') {
      iVar1 = (uint)*(byte *)(iVar3 + 0x12) << 0x1a;
    }
    else {
      iVar1 = (uint)*(byte *)(iVar3 + 0x12) << 0x19;
    }
    if (((iVar1 < 0) && ((param_4 & 0x7ff) <= (*(ushort *)(iVar3 + 0x10) & 0x7ff))) &&
       (iVar1 = FUN_0e0645e8(*(undefined4 *)(iVar3 + 0x10),param_3), iVar1 != 0)) {
      *(undefined2 *)(iVar3 + 0x1a) = extraout_r2;
      *(char *)(iVar3 + 0x19) = (char)param_3;
      *(undefined1 *)(iVar3 + 0x1c) = param_5;
      *(byte *)(iVar3 + 0x14) = *(byte *)(iVar3 + 0x14) & 0xf1;
      iVar4 = (**(code **)(iVar4 + 0x18))(param_1,iVar3);
      *(byte *)(iVar3 + 0x14) = *(byte *)(iVar3 + 0x14) & 0xfe | iVar4 == 0;
      return iVar4;
    }
  }
  return -0x13;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064914. Types and names are inferred; NOT original source. */

undefined4
FUN_0e064914(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined1 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if ((param_2 & 0x7f) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    (**(code **)(iVar2 + 0x3c))();
    if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
      uVar1 = FUN_0e064888(param_1,param_2,param_3,param_4,param_5);
    }
    else {
      uVar1 = 0xffffffff;
    }
    (**(code **)(iVar2 + 0x40))(param_1);
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064968. Types and names are inferred; NOT original source. */

int FUN_0e064968(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  
  uVar3 = param_2 & 0xf;
  if ((int)(param_2 << 0x18) < 0) {
    uVar3 = uVar3 + 0x10;
  }
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + uVar3 * 4);
  if (iVar5 != 0) {
    if ((int)((uint)*(byte *)(iVar5 + 0x14) << 0x1f) < 0) {
      pcVar4 = *(code **)(*(int *)(param_1 + 8) + 0x1c);
      iVar1 = (*pcVar4)(param_1,iVar5,*(int *)(param_1 + 0x10),pcVar4,param_4);
      if (iVar1 == 0) {
        bVar2 = 0;
      }
      else {
        bVar2 = *(byte *)(iVar5 + 0x14) & 1;
      }
      *(byte *)(iVar5 + 0x14) = *(byte *)(iVar5 + 0x14) & 0xfe | bVar2;
      return iVar1;
    }
    return -0x78;
  }
  return -0x13;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0649ac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0649ac(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  if ((param_2 & 0x7f) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    (**(code **)(iVar2 + 0x3c))();
    if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
      uVar1 = FUN_0e064968(param_1,param_2);
    }
    else {
      uVar1 = 0xffffffff;
    }
    (**(code **)(iVar2 + 0x40))(param_1);
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0649e8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0649e8(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  (**(code **)(iVar4 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
    uVar3 = param_2 & 0xf;
    if ((int)(param_2 << 0x18) < 0) {
      uVar3 = uVar3 + 0x10;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + uVar3 * 4);
    if ((iVar2 == 0) || (-1 < (int)((uint)*(byte *)(iVar2 + 0x14) << 0x1f))) {
      uVar1 = 0xffffffed;
    }
    else if ((*(byte *)(iVar2 + 0x19) & 3) == 1) {
      uVar1 = 0xffffff7a;
    }
    else {
      uVar1 = (**(code **)(iVar4 + 0xc))(param_1);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  (**(code **)(iVar4 + 0x40))(param_1);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064a48. Types and names are inferred; NOT original source. */

int FUN_0e064a48(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  (**(code **)(iVar4 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
    uVar2 = param_2 & 0xf;
    if ((int)(param_2 << 0x18) < 0) {
      uVar2 = uVar2 + 0x10;
    }
    iVar3 = *(int *)(*(int *)(param_1 + 0x10) + uVar2 * 4);
    if ((iVar3 == 0) || (-1 < (int)((uint)*(byte *)(iVar3 + 0x14) << 0x1f))) {
      iVar1 = -0x13;
    }
    else if ((*(byte *)(iVar3 + 0x19) & 3) == 1) {
      iVar1 = -0x86;
    }
    else {
      iVar1 = (**(code **)(iVar4 + 0x10))
                        (param_1,iVar3,*(int *)(param_1 + 0x10),*(code **)(iVar4 + 0x10),param_4);
      if (iVar1 == 0) {
        *(byte *)(iVar3 + 0x14) = *(byte *)(iVar3 + 0x14) & 0xfd;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  (**(code **)(iVar4 + 0x40))(param_1);
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064ab4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064ab4(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = *(int *)(param_1 + 8);
  (**(code **)(iVar5 + 0x3c))();
  if ((*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) &&
     (uVar3 = (uint)*(byte *)(param_2 + 0x18), uVar3 != 0)) {
    bVar6 = -1 < (int)(uVar3 << 0x18);
    uVar4 = uVar3;
    if (bVar6) {
      uVar4 = uVar3 & 0xf;
    }
    if (!bVar6) {
      uVar4 = (uVar3 & 0xf) + 0x10;
    }
    iVar2 = *(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4);
    if ((iVar2 == 0) || (-1 < (int)((uint)*(byte *)(iVar2 + 0x14) << 0x1f))) {
      uVar1 = 0xffffffed;
    }
    else {
      *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) & 0xfe;
      uVar1 = (**(code **)(iVar5 + 4))(param_1,iVar2,param_2);
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  (**(code **)(iVar5 + 0x40))(param_1);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064b18. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064b18(int param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  (**(code **)(iVar4 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
    uVar3 = param_2 & 0xf;
    if ((int)(param_2 << 0x18) < 0) {
      uVar3 = uVar3 + 0x10;
    }
    piVar2 = *(int **)(*(int *)(param_1 + 0x10) + uVar3 * 4);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0xffffffed;
    }
    else {
      uVar1 = 0;
      if (*piVar2 != 0) {
        uVar1 = (**(code **)(iVar4 + 8))(param_1);
      }
    }
  }
  else {
    uVar1 = 0xffffffff;
  }
  (**(code **)(iVar4 + 0x40))(param_1);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064b64. Types and names are inferred; NOT original source. */

int FUN_0e064b64(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  (**(code **)(iVar2 + 0x3c))();
  iVar1 = FUN_0e06195c(&DAT_23001ce8,param_3,0,0,param_4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined2 *)(iVar1 + 0x20) = 0;
    *(undefined1 *)(iVar1 + 0x18) = param_2;
  }
  (**(code **)(iVar2 + 0x40))(param_1);
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064b9c. Types and names are inferred; NOT original source. */

int thunk_FUN_0e064b64(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  (**(code **)(iVar2 + 0x3c))();
  iVar1 = FUN_0e06195c(&DAT_23001ce8,param_3,0,0,param_4);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x18) = 0;
    *(undefined4 *)(iVar1 + 0x1c) = 0;
    *(undefined2 *)(iVar1 + 0x20) = 0;
    *(undefined1 *)(iVar1 + 0x18) = param_2;
  }
  (**(code **)(iVar2 + 0x40))(param_1);
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064ba0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064ba0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  (**(code **)(iVar1 + 0x3c))();
  FUN_0e061ac0(param_2);
  (**(code **)(iVar1 + 0x40))(param_1);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064bbc. Types and names are inferred; NOT original source. */

uint FUN_0e064bbc(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 8);
  (*(code *)puVar3[0xf])();
  uVar1 = *(uint *)(*(int *)(param_1 + 0x10) + 0xa0);
  uVar2 = (uVar1 & 3) >> 1;
  if ((int)(uVar1 << 0x1e) < 0) {
    if ((code *)*puVar3 == (code *)0x0) {
      (*(code *)puVar3[0x10])(param_1);
      return 1;
    }
    uVar2 = (*(code *)*puVar3)(param_1);
  }
  (*(code *)puVar3[0x10])(param_1);
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064bf8. Types and names are inferred; NOT original source. */

int FUN_0e064bf8(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0x10);
  (**(code **)(iVar5 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0x10) + 0xa0);
    uVar2 = (uVar3 & 3) >> 1;
    if ((int)(uVar3 << 0x1e) < 0) {
      iVar1 = -0x78;
    }
    else {
      *(uint *)(iVar4 + 0xa4) = uVar2;
      *(uint *)(iVar4 + 0xa8) = uVar2;
      iVar1 = (**(code **)(iVar5 + 0x2c))(param_1);
      if (iVar1 == 0) {
        *(uint *)(iVar4 + 0xa0) = *(uint *)(iVar4 + 0xa0) | 2;
        (**(code **)(iVar5 + 0x40))(param_1);
        return 0;
      }
    }
  }
  else {
    iVar1 = -1;
  }
  (**(code **)(iVar5 + 0x40))(param_1);
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064c60. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064c60(int param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0x10);
  (**(code **)(iVar3 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
    uVar1 = (**(code **)(iVar3 + 0x30))(param_1);
    puVar2 = (uint *)(iVar4 + 0xa0);
    *puVar2 = *puVar2 & 0xfffffffd;
  }
  else {
    uVar1 = 0xffffff88;
  }
  (**(code **)(iVar3 + 0x40))(param_1);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064ca4. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e064cfa) */

int FUN_0e064ca4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0x10);
  if ((param_2 == 0) || (param_3 == 0)) {
    iVar1 = -0x16;
  }
  else {
    (**(code **)(iVar3 + 0x3c))();
    if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
      iVar1 = -0x78;
    }
    else {
      *(int *)(iVar2 + 0x98) = param_2;
      *(int *)(iVar2 + 0x9c) = param_3;
      iVar1 = (**(code **)(iVar3 + 0x34))(param_1);
      if (iVar1 == 0) {
        *(uint *)(iVar2 + 0xa0) = *(uint *)(iVar2 + 0xa0) | 1;
      }
    }
    (**(code **)(iVar3 + 0x40))(param_1);
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064d08. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064d08(int param_1)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 0x10);
  (**(code **)(iVar4 + 0x3c))();
  if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1e < 0) {
    uVar1 = 0xfffffff0;
  }
  else if (*(int *)(*(int *)(param_1 + 0x10) + 0xa0) << 0x1f < 0) {
    uVar1 = (**(code **)(iVar4 + 0x38))(param_1);
    puVar2 = (uint *)(iVar3 + 0xa0);
    *puVar2 = *puVar2 & 0xfffffffe;
  }
  else {
    uVar1 = 0xffffff88;
  }
  (**(code **)(iVar4 + 0x40))(param_1);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064d60. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064d60(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_24 [4];
  int local_20;
  int iStack_1c;
  
  iVar3 = *(int *)(param_1 + 0x10);
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) | 2;
  FUN_0e061b2c(*(undefined4 *)(iVar3 + 0xa8));
  iVar1 = FUN_0e064b64(param_1,0x80,0);
  if (iVar1 == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    FUN_0e061b2c(param_2,iVar1);
    uVar2 = 0;
    *(byte *)(iVar1 + 0x19) = *(byte *)(iVar1 + 0x19) | 4;
  }
  local_20 = *(int *)(iVar3 + 0xa8);
  iVar1 = *(int *)(param_1 + 0x10);
  local_24[0] = 6;
  if (*(int *)(iVar1 + 0xa0) << 0x1f < 0) {
    *(undefined4 *)(local_20 + 0x1e) = uVar2;
    iStack_1c = param_1;
    uVar2 = (**(code **)(iVar1 + 0x98))(param_1,local_24);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064dd4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064dd4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_24 [4];
  int local_20;
  int iStack_1c;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar3 + 0xa4) == 2) {
    iVar4 = *(int *)(iVar3 + 0xa8);
    iVar1 = FUN_0e064b64(param_1,0x80,*(undefined2 *)(*(int *)(iVar4 + 0xc) + 6));
    if (iVar1 == 0) {
      uVar2 = 0xfffffff4;
    }
    else {
      FUN_0e061b2c(iVar4,iVar1);
      uVar2 = 0;
      *(byte *)(iVar1 + 0x19) = *(byte *)(iVar1 + 0x19) | 2;
    }
    local_20 = *(int *)(iVar3 + 0xa8);
    iVar3 = *(int *)(param_1 + 0x10);
    local_24[0] = 6;
    if (*(int *)(iVar3 + 0xa0) << 0x1f < 0) {
      *(undefined4 *)(local_20 + 0x1e) = uVar2;
      iStack_1c = param_1;
      uVar2 = (**(code **)(iVar3 + 0x98))(param_1,local_24);
    }
    else {
      uVar2 = 0xffffffff;
    }
  }
  else {
    uVar2 = 0xffffff7a;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064e48. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064e48(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_24 [4];
  int local_20;
  int iStack_1c;
  
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(iVar3 + 0xa8);
  iVar1 = FUN_0e064b64(param_1,0x80,0);
  if (iVar1 == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    if (iVar4 != 0) {
      FUN_0e061b2c(iVar4,iVar1);
    }
    uVar2 = 0;
    *(byte *)(iVar1 + 0x19) = *(byte *)(iVar1 + 0x19) | 4;
  }
  local_20 = *(int *)(iVar3 + 0xa8);
  iVar1 = *(int *)(param_1 + 0x10);
  local_24[0] = 6;
  if (*(int *)(iVar1 + 0xa0) << 0x1f < 0) {
    *(undefined4 *)(local_20 + 0x1e) = uVar2;
    iStack_1c = param_1;
    uVar2 = (**(code **)(iVar1 + 0x98))(param_1,local_24);
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064eb0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e064eb0(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  
  *(byte *)(param_2 + 0x19) = *(byte *)(param_2 + 0x19) | 4;
  local_14[0] = 6;
  iVar2 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar2 + 0xa0) << 0x1f < 0) {
    *(undefined1 *)(param_2 + 0x1e) = 0;
    *(undefined1 *)(param_2 + 0x1f) = 0;
    *(undefined1 *)(param_2 + 0x20) = 0;
    *(undefined1 *)(param_2 + 0x21) = 0;
    local_10 = param_2;
    local_c = param_1;
    uVar1 = (**(code **)(iVar2 + 0x98))(param_1,local_14);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064ef8. Types and names are inferred; NOT original source. */

bool FUN_0e064ef8(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x10) + 0xa4) == 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064f0c. Types and names are inferred; NOT original source. */

bool FUN_0e064f0c(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x10) + 0xa4) == 2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064f20. Types and names are inferred; NOT original source. */

bool FUN_0e064f20(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x10) + 0xa4) == 4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064f34. Types and names are inferred; NOT original source. */

bool FUN_0e064f34(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x10) + 0xa4) == 5;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064f48. Types and names are inferred; NOT original source. */

bool FUN_0e064f48(int param_1)

{
  return *(int *)(*(int *)(param_1 + 0x10) + 0xa4) == 3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e064f5c. Types and names are inferred; NOT original source. */

void FUN_0e064f5c(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x10);
  if ((int)((uint)*(byte *)(param_2 + 0x19) << 0x1f) < 0) {
    if (*(char *)(param_2 + 0x18) == '\0') {
      sVar1 = *(short *)(*(int *)(param_2 + 0xc) + 6);
      if (*(int *)(iVar4 + 0xa8) != 0) {
        FUN_0e061ac0();
      }
      *(int *)(iVar4 + 0xa8) = param_2;
      if (*(int *)(iVar4 + 0xa4) != 0) {
        *(undefined4 *)(iVar4 + 0xa4) = 0;
      }
      if (sVar1 == 0) {
        *(undefined4 *)(iVar4 + 0xa4) = 3;
        return;
      }
      *(uint *)(iVar4 + 0xa4) = (**(byte **)(param_2 + 0xc) >> 7) + 1;
      return;
    }
  }
  else if (*(char *)(param_2 + 0x18) == '\0') {
    if (*(int *)(iVar4 + 0xa4) == 1) {
      *(undefined4 *)(iVar4 + 0xa4) = 5;
      return;
    }
    if (*(int *)(iVar4 + 0xa4) != 4) {
      *(undefined4 *)(iVar4 + 0xa4) = 6;
      return;
    }
    if (*(short *)(param_2 + 0x10) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = 6;
    }
    goto LAB_0e064f84;
  }
  iVar2 = *(int *)(iVar4 + 0xa4);
  if (iVar2 == 5) {
    *(undefined4 *)(iVar4 + 0xa4) = 0;
    return;
  }
  if (iVar2 == 2) {
    uVar3 = (*(uint *)(iVar4 + 0x80) ^ 4) & 4;
  }
  else if (iVar2 == 3) {
    uVar3 = 0;
  }
  else {
    uVar3 = 6;
  }
LAB_0e064f84:
  *(uint *)(iVar4 + 0xa4) = uVar3;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065114. Types and names are inferred; NOT original source. */

void FUN_0e065114(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  uVar5 = (uint)*(byte *)(iVar3 + 0x364);
  if (uVar5 != 0) {
    uVar1 = 0;
    uVar2 = 0;
    do {
      if (((3 << (uVar2 << 1 & 0xff) & *(uint *)(iVar3 + 0x2ac)) >> (uVar2 << 1 & 0xff) & 0xfffffffd
          ) == 0) {
        iVar6 = (uVar1 & 0x7f) + 0x58;
        if ((uVar1 & 0x80) != 0) {
          iVar6 = (uVar1 & 0x7f) + 0x48;
        }
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar6 * 0x20) = 0x8000000;
        uVar5 = (uint)*(byte *)(iVar3 + 0x364);
      }
      uVar1 = uVar1 + 1;
      uVar2 = uVar1 & 0xff;
    } while (uVar2 < uVar5);
  }
  *(undefined4 *)(iVar4 + 0x814) = 9;
  *(uint *)(iVar4 + 0x810) = *(uint *)(iVar4 + 0x810) | 1;
  *(uint *)(iVar4 + 0x18) = *(uint *)(iVar4 + 0x18) | 0x10;
  *(uint *)(iVar4 + 0x800) = *(uint *)(iVar4 + 0x800) & 0xfffff80f;
  *(byte *)(iVar3 + 0x362) = *(byte *)(iVar3 + 0x362) & 0xdf;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0651a8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0651a8(void)

{
  int iVar1;
  
  iVar1 = FUN_0e06ae70();
  if (iVar1 == 0) {
    FUN_0e06ae34();
    return 0;
  }
  return 0xfffffffb;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0651c0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0651c0(void)

{
  int iVar1;
  undefined4 in_r3;
  
  iVar1 = FUN_0e06eddc(&DAT_23001c70,1,0,in_r3,0,0);
  if ((iVar1 == 0) && (iVar1 = FUN_0e06eddc(&DAT_23001c70,1,0), iVar1 == 0)) {
    return 0xffffff8c;
  }
  _DAT_5f086400 = 3;
  _DAT_5f086000 = 1;
  FUN_0e06c6b4(1);
  _DAT_5f086304 = 1;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065238. Types and names are inferred; NOT original source. */

void FUN_0e065238(int param_1,uint *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  int iVar4;
  code *pcVar5;
  undefined8 uVar6;
  int local_20;
  int iStack_1c;
  
  FUN_0e06e9e0(&local_20,param_2,100000,0);
  iVar2 = iStack_1c;
  iVar1 = local_20;
  uVar3 = extraout_r1;
  do {
    if ((param_3 & *param_2) != 0) {
      return;
    }
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x18);
    if ((iVar4 != 0) && (pcVar5 = *(code **)(iVar4 + 0x1c), pcVar5 != (code *)0x0)) {
      uVar6 = (*pcVar5)(param_1);
      uVar3 = (undefined4)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 != 0) {
        return;
      }
    }
    FUN_0e06ea70(&local_20,uVar3,iVar1,iVar2);
    uVar3 = extraout_r1_00;
  } while (iStack_1c != 0 || local_20 != 0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0652f8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0652f8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  uVar1 = FUN_0e06465c(param_1,0);
  iVar2 = thunk_FUN_0e064b64(param_1,0,param_2);
  if (iVar2 != 0) {
    thunk_FUN_0e06d008(uVar1,iVar2);
    FUN_0e06edc0(iVar3 + 0x9c,0x10000);
    FUN_0e06edc0(iVar3 + 0x90,2);
    return 0;
  }
  return 0xfffffff4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065344. Types and names are inferred; NOT original source. */

undefined4 FUN_0e065344(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  thunk_FUN_0e06d008(param_2,param_3,param_3,*(int *)(param_1 + 0x10),param_4);
  if (-1 < (int)((uint)*(byte *)(param_2 + 0x14) << 0x1e)) {
    if (*(char *)(param_2 + 0x18) < '\0') {
      bVar1 = *(byte *)(param_2 + 0x18) & 0x7f;
    }
    else {
      bVar1 = *(byte *)(param_2 + 0x18) + 0x10;
    }
    FUN_0e06edc0(iVar2 + 0x9c,1 << bVar1);
    FUN_0e06edc0(iVar2 + 0x90,2);
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0653a8. Types and names are inferred; NOT original source. */

void FUN_0e0653a8(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1[4] + 0xac);
  FUN_0e06d8f8(uVar1,&DAT_23011b00,0x200,0xe066d3d,param_1,0,0,0xfffffff8,1);
  FUN_0e06d854(uVar1,*param_1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065480. Types and names are inferred; NOT original source. */

void FUN_0e065480(int param_1,uint param_2,int param_3,int param_4)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint unaff_r10;
  uint uVar10;
  bool bVar11;
  
  iVar8 = *(int *)(param_1 + 0x10);
  uVar6 = *(byte *)(param_4 + 0x18) & 0x7f;
  bVar11 = (*(byte *)(param_4 + 0x18) & 0x7f) != 0;
  iVar7 = *(int *)(param_2 + 0xac);
  iVar9 = iVar8 + uVar6 * 0x20;
  uVar1 = *(ushort *)(param_4 + 0x1a);
  if (bVar11) {
    param_2 = *(uint *)(iVar7 + 0x2b4);
    unaff_r10 = *(uint *)(iVar7 + 0x2b8);
  }
  uVar5 = *(uint *)(iVar9 + 0xb00);
  if (!bVar11) {
    param_2 = 0x7f;
    unaff_r10 = 1;
  }
  uVar10 = (uVar1 & 0x1fff) >> 0xb;
  if ((*(byte *)(param_4 + 0x19) & 3) == 1) {
    uVar4 = FUN_0e061bfc(param_3 + 0xc);
    uVar2 = uVar1 & 0x7ff;
    uVar2 = uVar10 * uVar2 + uVar2;
    uVar3 = uVar10 + 1;
    if (uVar4 < uVar2) {
      return;
    }
    if ((int)((uint)*(ushort *)(iVar7 + 0x360) << 0x1f) < 0) {
      uVar5 = uVar5 | 0x94000000;
    }
    else {
      uVar5 = uVar5 | 0xa4000000;
    }
  }
  else {
    uVar2 = FUN_0e061bfc(param_3 + 0xc);
    if (param_2 < uVar2) {
      uVar3 = *(ushort *)(param_4 + 0x1a) & 0x7ff;
      uVar2 = ((*(ushort *)(param_4 + 0x1a) & 0x1fff) >> 0xb) * uVar3 + uVar3;
      uVar2 = (param_2 / uVar2) * uVar2;
    }
    else {
      uVar3 = *(ushort *)(param_4 + 0x1a) & 0x7ff;
    }
    uVar3 = ((uVar2 + uVar3) - 1) / uVar3;
    uVar5 = uVar5 | 0x84000000;
  }
  if (unaff_r10 < uVar3) {
    uVar3 = (uVar10 + 1) * (unaff_r10 / (uVar10 + 1));
    uVar2 = uVar3 * (*(ushort *)(param_4 + 0x1a) & 0x7ff);
  }
  uVar10 = uVar2 & 0x7ffff | (uVar3 & 0x3ff) << 0x13;
  if (*(char *)(param_4 + 0x18) == '\0') {
    uVar10 = uVar10 | 0x60000000;
  }
  *(uint *)(iVar7 + uVar6 * 4 + 0x2fc) = uVar10;
  *(uint *)(iVar8 + uVar6 * 0x20 + 0xb10) = uVar10;
  *(uint *)(iVar9 + 0xb00) = uVar5;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065570. Types and names are inferred; NOT original source. */

undefined4 FUN_0e065570(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  int iVar16;
  
  iVar9 = *(int *)(param_1 + 0x10);
  iVar16 = *(int *)(param_2 + 0xac);
  bVar1 = *(byte *)(param_3 + 0x19);
  uVar15 = (*(ushort *)(param_3 + 0x1a) & 0x1fff) >> 0xb;
  bVar7 = bVar1 & 1;
  uVar11 = (uint)*(ushort *)(param_4 + 0x10);
  uVar5 = *(byte *)(param_3 + 0x18) & 0x7f;
  uVar3 = *(ushort *)(param_3 + 0x1a) & 0x7ff;
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 3) == 1) {
      uVar6 = uVar15 * uVar3 + uVar3;
      if (uVar6 <= uVar11) {
        uVar11 = uVar6;
      }
      bVar7 = 1;
    }
    else {
      bVar7 = 1;
    }
  }
  uVar6 = (*(uint *)(iVar9 + uVar5 * 0x20 + 0x918) & 0xffff) * 4;
  uVar10 = uVar3 + 3 & 0xfffffffc;
  uVar13 = uVar6 / uVar10;
  uVar6 = uVar3 * uVar13 + (uVar6 - uVar10 * uVar13);
  if ((uVar6 < uVar11) && (uVar13 < uVar15 + 1)) {
    uVar14 = 0xfffffff5;
  }
  else {
    if (uVar11 <= uVar6) {
      uVar6 = uVar11;
    }
    if (uVar6 == 0) {
      uVar11 = 0x80000;
      uVar10 = 1;
    }
    else {
      if ((*(byte *)(param_3 + 0x18) & 0x7f) == 0) {
        uVar11 = 3;
        uVar10 = 0x7f;
      }
      else {
        uVar10 = *(uint *)(iVar16 + 0x2b4);
        uVar11 = *(uint *)(iVar16 + 0x2b8);
      }
      if (uVar10 < uVar6) {
        uVar6 = uVar15 * uVar3 + uVar3;
        uVar6 = (uVar10 / uVar6) * uVar6;
      }
      uVar10 = ((uVar3 - 1) + uVar6) / uVar3;
      if (uVar11 < uVar10) {
        uVar10 = (uVar15 + 1) * (uVar11 / (uVar15 + 1));
        uVar6 = uVar3 * uVar10;
      }
      uVar11 = (uVar10 & 0x3ff) << 0x13 | uVar6 & 0x7ffff;
    }
    *(uint *)(iVar16 + uVar5 * 4 + 700) = uVar6;
    uVar14 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar14 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (bVar7 != 0) {
      uVar11 = uVar11 | (uVar15 + 1) * 0x20000000 & 0x60000000;
    }
    *(uint *)(iVar9 + uVar5 * 0x20 + 0x910) = uVar11;
    iVar8 = iVar9 + uVar5 * 0x20;
    uVar11 = *(uint *)(iVar8 + 0x900);
    if ((uVar11 & 0x8000) == 0) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar14);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar14 = 0xfffffffe;
    }
    else {
      if ((bVar1 & 3) == 1) {
        if ((*(ushort *)(iVar16 + 0x360) & 1) == 0) {
          uVar11 = uVar11 | 0x20000000;
        }
        else {
          uVar11 = uVar11 | 0x10000000;
        }
      }
      *(uint *)(iVar8 + 0x900) = uVar11 | 0x84000000;
      *(undefined4 *)(uVar5 * 0x20 + iVar9 + 0x908) = 0x40;
      pbVar12 = *(byte **)(param_4 + 0xc);
      if (uVar10 != 0) {
        do {
          uVar11 = *(ushort *)(param_3 + 0x1a) & 0x7ff;
          if (uVar6 <= uVar11) {
            uVar11 = uVar6;
          }
          if (uVar11 != 0) {
            uVar3 = 0;
            pbVar4 = pbVar12;
            do {
              uVar15 = (uint)*pbVar4;
              if (uVar3 + 1 < uVar11) {
                uVar15 = (uint)CONCAT11(pbVar4[1],*pbVar4);
              }
              if (uVar3 + 2 < uVar11) {
                uVar15 = uVar15 | (uint)pbVar4[2] << 0x10;
              }
              if (uVar3 + 3 < uVar11) {
                uVar15 = uVar15 | (uint)pbVar4[3] << 0x18;
              }
              uVar3 = uVar3 + 4;
              *(uint *)(iVar9 + (uVar5 + 1) * 0x1000) = uVar15;
              pbVar4 = pbVar4 + 4;
            } while (uVar3 < uVar11);
          }
          uVar10 = uVar10 - 1;
          pbVar12 = pbVar12 + uVar11;
          uVar6 = uVar6 - uVar11;
        } while (uVar10 != 0);
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar14);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar14 = 0;
    }
  }
  return uVar14;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065734. Types and names are inferred; NOT original source. */

void FUN_0e065734(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  
  iVar1 = FUN_0e064738(param_1,*(undefined1 *)(param_2 + 0x18));
  if (iVar1 == 0) {
    return;
  }
  if (*(char *)(param_2 + 0x18) < '\0') {
    iVar1 = FUN_0e065570(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),param_2,iVar1)
    ;
    uVar3 = *(undefined1 *)(param_2 + 0x18);
    if (iVar1 != 0) {
      uVar2 = FUN_0e0646d4(param_1,uVar3);
      FUN_0e064798(param_1,uVar2,0xffffff91,param_4);
      return;
    }
  }
  else {
    FUN_0e065480();
    uVar3 = *(undefined1 *)(param_2 + 0x18);
  }
  FUN_0e064688(param_1,uVar3,1,param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06578c. Types and names are inferred; NOT original source. */

void FUN_0e06578c(int param_1,int param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  
  bVar1 = *(byte *)(param_2 + 0x18);
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  uVar3 = bVar1 & 0x7f;
  bVar8 = *(byte *)(param_2 + 0x19) & 3;
  iVar7 = iVar4 + uVar3 * 0x20;
  if ((int)((uint)bVar1 << 0x18) < 0) {
    uVar2 = *(uint *)(iVar7 + 0x900);
    if (((bVar8 != 1) && ((int)(uVar2 << 0xe) < 0)) && (-1 < (int)uVar2)) {
      iVar7 = uVar3 + 0x48;
      goto LAB_0e06586c;
    }
    iVar6 = uVar3 * 0x20 + 0x908 + iVar4;
    uVar5 = uVar2 | 0x88000000;
    if (param_3 != 0) {
      uVar5 = uVar2 | 0x88200000;
    }
    *(uint *)(iVar7 + 0x900) = uVar5;
    FUN_0e065238(param_1,iVar6,0x40);
    *(uint *)(iVar7 + 0x900) = uVar5 | 0xc0000000;
    FUN_0e065238(param_1,iVar6,2);
    *(undefined4 *)(iVar4 + uVar3 * 0x20 + 0x908) = 3;
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    *(uint *)(iVar4 + 0x10) = (uVar5 & 0x3c00000) >> 0x10 | 0x20;
    do {
    } while (*(int *)(iVar4 + 0x10) << 0x1a < 0);
    goto LAB_0e065816;
  }
  uVar2 = *(uint *)(iVar7 + 0xb00);
  if (((bVar8 != 1) && ((int)(uVar2 << 0xe) < 0)) && (-1 < (int)uVar2)) {
    iVar7 = uVar3 + 0x58;
LAB_0e06586c:
    if (param_3 != 0) {
      *(uint *)(iVar4 + iVar7 * 0x20) = uVar2 | 0x200000;
    }
    return;
  }
  uVar5 = *(uint *)(iVar4 + 0x804);
  if (*(int *)(iVar4 + 0x14) << 0x18 < 0) {
    FUN_0e065238(param_1,iVar4 + 0x14,0x80);
    if ((bVar1 & 0x7f) == 0) goto LAB_0e065826;
LAB_0e0657e6:
    if (param_3 == 0) {
      *(uint *)(iVar7 + 0xb00) = uVar2 | 0xc8000000;
    }
    else {
      *(uint *)(iVar7 + 0xb00) = uVar2 | 0xc0200000;
    }
    FUN_0e065238(param_1,uVar3 * 0x20 + 0xb08 + iVar4,2);
  }
  else {
    *(uint *)(iVar4 + 0x804) = uVar5 | 0x200;
    uVar5 = uVar5 & 0xfffffdff;
    FUN_0e065238(param_1,iVar4 + 0x14,0x80);
    if ((bVar1 & 0x7f) != 0) goto LAB_0e0657e6;
LAB_0e065826:
    if (param_3 == 0) {
      *(uint *)(iVar7 + 0xb00) = uVar2 | 0x8000000;
    }
    else {
      *(uint *)(iVar7 + 0xb00) = uVar2 | 0x200000;
    }
  }
  *(undefined4 *)(iVar4 + uVar3 * 0x20 + 0xb08) = 3;
  *(uint *)(iVar4 + 0x804) = uVar5 | 0x400;
LAB_0e065816:
  FUN_0e064688(param_1,*(undefined1 *)(param_2 + 0x18),0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065918. Types and names are inferred; NOT original source. */

undefined4 FUN_0e065918(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_0e06578c(param_1,param_2,0,param_4,param_4);
  iVar1 = FUN_0e0646f0(param_1,*(undefined1 *)(param_2 + 0x18));
  if (iVar1 != 0) {
    FUN_0e064798(param_1,iVar1,0xffffff8f);
  }
  FUN_0e064688(param_1,*(undefined1 *)(param_2 + 0x18),0);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065948. Types and names are inferred; NOT original source. */

int FUN_0e065948(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 *local_c;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((*(undefined4 **)(iVar1 + 0x18) != (undefined4 *)0x0) &&
     (pcVar2 = (code *)**(undefined4 **)(iVar1 + 0x18), pcVar2 != (code *)0x0)) {
    iVar1 = (*pcVar2)();
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(param_1 + 4);
  }
  puVar3 = *(undefined4 **)(iVar1 + 0x14);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = FUN_0e067d30(puVar3,0,&local_c);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0e067d84(*local_c,*(undefined1 *)(local_c + 1),*puVar3);
    return iVar1;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06598c. Types and names are inferred; NOT original source. */

int FUN_0e06598c(int param_1)

{
  short sVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  bool bVar12;
  
  iVar8 = *(int *)(param_1 + 0x10);
  puVar5 = *(uint **)(param_1 + 4);
  iVar6 = *(int *)(iVar8 + 0xac);
  FUN_0e06cd9c(iVar8 + 0x84);
  FUN_0e06edb4(iVar6 + 0x90);
  FUN_0e06edb4(iVar6 + 0x9c);
  FUN_0e06edb4(iVar6 + 0xa8);
  *(byte *)(iVar8 + 0x80) = *(byte *)(iVar8 + 0x80) & 0x95 | 0x6a;
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  if ((iVar6 != 0) && (pcVar3 = *(code **)(iVar6 + 0x18), pcVar3 != (code *)0x0)) {
    (*pcVar3)(param_1);
  }
  uVar10 = 0;
  uVar4 = puVar5[0xc];
  uVar9 = 0;
  uVar2 = puVar5[10];
  sVar1 = (*(byte *)(iVar8 + 0x80) & 1) + 0x3ff;
  uVar7 = (puVar5[0xb] & 0x3fff) >> 10;
  do {
    if (((3 << (uVar10 << 1 & 0xff) & uVar2) >> (uVar10 << 1 & 0xff) & 0xfffffffd) == 0) {
      iVar11 = uVar9 * 0x20;
      iVar6 = puVar5[3] + iVar11;
      if (uVar10 == 0) {
        *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) | 1;
        *(undefined2 *)(puVar5[3] + iVar11 + 0x10) = 0x40;
      }
      else {
        *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) | 4;
        *(byte *)(puVar5[3] + iVar11 + 0x12) = *(byte *)(puVar5[3] + iVar11 + 0x12) | 2;
        *(byte *)(puVar5[3] + iVar11 + 0x12) = *(byte *)(puVar5[3] + iVar11 + 0x12) | 8;
        *(byte *)(puVar5[3] + iVar11 + 0x12) =
             *(byte *)(puVar5[3] + iVar11 + 0x12) & 0xef | (*(byte *)(iVar8 + 0x80) & 1) << 4;
        *(short *)(puVar5[3] + iVar11 + 0x10) = sVar1;
      }
      uVar9 = uVar9 + 1;
      *(byte *)(puVar5[3] + iVar11 + 0x12) = *(byte *)(puVar5[3] + iVar11 + 0x12) | 0x40;
      *(char *)(puVar5[3] + iVar11 + 0x18) = (char)uVar10;
      iVar6 = FUN_0e0646a4(param_1,puVar5[3] + iVar11);
      if (iVar6 != 0) {
        return iVar6;
      }
      uVar2 = puVar5[10];
      if (puVar5[1] <= uVar9) break;
    }
    bVar12 = uVar7 != uVar10;
    uVar10 = uVar10 + 1;
  } while (bVar12);
  uVar4 = ((uVar4 & 0x3fffffff) >> 0x1a) + 1;
  uVar10 = 0;
  uVar9 = 0;
  do {
    if ((3 << (uVar10 << 1 & 0xff) & uVar2) >> (uVar10 << 1 & 0xff) < 2) {
      iVar11 = uVar9 * 0x20;
      iVar6 = puVar5[2] + iVar11;
      if (uVar10 == 0) {
        *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) | 1;
        *(undefined2 *)(puVar5[2] + iVar11 + 0x10) = 0x40;
      }
      else {
        *(byte *)(iVar6 + 0x12) = *(byte *)(iVar6 + 0x12) | 4;
        *(byte *)(puVar5[2] + iVar11 + 0x12) = *(byte *)(puVar5[2] + iVar11 + 0x12) | 2;
        *(byte *)(puVar5[2] + iVar11 + 0x12) = *(byte *)(puVar5[2] + iVar11 + 0x12) | 8;
        *(byte *)(puVar5[2] + iVar11 + 0x12) =
             *(byte *)(puVar5[2] + iVar11 + 0x12) & 0xef | (*(byte *)(iVar8 + 0x80) & 1) << 4;
        *(short *)(puVar5[2] + iVar11 + 0x10) = sVar1;
      }
      uVar9 = uVar9 + 1;
      *(byte *)(puVar5[2] + iVar11 + 0x12) = *(byte *)(puVar5[2] + iVar11 + 0x12) | 0x20;
      *(byte *)(puVar5[2] + iVar11 + 0x18) = (byte)uVar10 | 0x80;
      iVar6 = FUN_0e0646a4(param_1,puVar5[2] + iVar11);
      if (iVar6 != 0) {
        return iVar6;
      }
      uVar2 = *puVar5;
      if (uVar4 <= *puVar5) {
        uVar2 = uVar4;
      }
      if (uVar2 <= uVar9) {
LAB_0e065b74:
        (*(code *)puVar5[7])(param_1);
        return 0;
      }
    }
    bVar12 = uVar7 == uVar10;
    uVar10 = uVar10 + 1;
    if (bVar12) goto LAB_0e065b74;
    uVar2 = puVar5[10];
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065b84. Types and names are inferred; NOT original source. */

int FUN_0e065b84(int param_1)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  undefined2 *puVar5;
  ushort uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  
  iVar13 = *(int *)(param_1 + 4);
  iVar14 = *(int *)(iVar13 + 0x10);
  iVar4 = iVar14;
  if ((*(int *)(iVar13 + 0x18) != 0) &&
     (pcVar7 = *(code **)(*(int *)(iVar13 + 0x18) + 4), pcVar7 != (code *)0x0)) {
    iVar4 = (*pcVar7)();
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  }
  iVar10 = 0x2711;
  iVar12 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar8 = *(int *)(iVar4 + 0x10);
  while (-1 < iVar8) {
    FUN_0e06c6b4(1);
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) {
      return -5;
    }
    iVar8 = *(int *)(iVar4 + 0x10);
  }
  iVar10 = 0x2711;
  *(undefined4 *)(iVar4 + 0x10) = 1;
  do {
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) {
      return -5;
    }
    FUN_0e06c6b4(1);
  } while ((*(int *)(iVar4 + 0x10) << 0x1f < 0) && (-1 < *(int *)(iVar4 + 0x10) << 2));
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xdffffffe;
  *(byte *)(iVar12 + 0x362) =
       *(byte *)(iVar12 + 0x362) & 0xf7 | (*(uint *)(iVar4 + 0x40) < 0x4f54500a) << 3;
  *(undefined4 *)(iVar12 + 0x2ac) = *(undefined4 *)(iVar4 + 0x44);
  uVar11 = *(uint *)(iVar4 + 0x48);
  uVar16 = *(uint *)(iVar4 + 0x4c);
  uVar15 = *(uint *)(iVar4 + 0x50);
  if ((uVar15 & 0x2000000) == 0) {
    iVar4 = -0x86;
  }
  else {
    *(undefined4 *)(iVar4 + 0xc) = 0x40000000;
    FUN_0e06e334(25000,0);
    bVar2 = *(byte *)(iVar12 + 0x362) & 0xfd;
    *(byte *)(iVar12 + 0x362) = bVar2;
    if ((int)(uVar11 << 0xc) < 0) {
      *(byte *)(iVar12 + 0x362) = bVar2 | 1;
    }
    *(byte *)(iVar12 + 0x364) = (byte)((uVar11 << 0x12) >> 0x1c) + 1;
    *(byte *)(iVar12 + 0x365) = (byte)((uVar15 << 2) >> 0x1c) + 1;
    *(int *)(iVar12 + 0x2b4) = (1 << (uVar16 & 0xf) + 0xb) + -1;
    *(byte *)(iVar12 + 0x363) = (byte)((uVar15 << 0x19) >> 0x1f);
    *(int *)(iVar12 + 0x2b8) = (1 << ((uVar16 & 0x7f) >> 4) + 4) + -1;
    *(short *)(iVar12 + 0x33c) = (short)(uVar16 >> 0x10);
    if ((uVar16 & 0x800) != 0) {
      *(byte *)(iVar12 + 0x362) = *(byte *)(iVar12 + 0x362) | 4;
    }
    if ((int)((uint)*(byte *)(iVar12 + 0x362) << 0x1e) < 0) {
      uVar16 = *(uint *)(iVar4 + 8) | 0x20;
    }
    else {
      uVar16 = *(uint *)(iVar4 + 8) & 0xffffffdf;
    }
    *(uint *)(iVar4 + 8) = uVar16;
    uVar16 = (uVar11 & 0xff) >> 6;
    uVar9 = *(uint *)(iVar4 + 0x800) & 0xff7ffffc;
    if (uVar16 == 1) {
      uVar16 = 0x40000000;
      bVar3 = true;
    }
    else if (uVar16 - 2 < 2) {
      bVar3 = true;
      uVar16 = 0x40000010;
    }
    else {
      uVar16 = 0x40000040;
      bVar3 = false;
      if ((uVar11 & 0x300) == 0) {
        uVar16 = 0x40000000;
      }
      uVar9 = uVar9 | 3;
    }
    if ((uVar15 & 0xc000) != 0) {
      uVar16 = uVar16 | 8;
    }
    *(uint *)(iVar4 + 0xc) = uVar16;
    uVar11 = 0;
    *(uint *)(iVar4 + 0x800) = uVar9;
    uVar15 = (uint)*(byte *)(iVar12 + 0x364);
    *(undefined1 *)(iVar12 + 0x366) = 0;
    if (uVar15 != 0) {
      uVar16 = 0;
      do {
        if (((3 << (uVar16 << 1 & 0xff) & *(uint *)(iVar12 + 0x2ac)) >> (uVar16 << 1 & 0xff) &
            0xfffffffd) == 0) {
          iVar10 = (uVar11 & 0x7f) + 0x58;
          if ((uVar11 & 0x80) != 0) {
            iVar10 = (uVar11 & 0x7f) + 0x48;
          }
          *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar10 * 0x20) = 0x8000000;
          uVar15 = (uint)*(byte *)(iVar12 + 0x364);
          *(char *)(iVar12 + 0x366) = *(char *)(iVar12 + 0x366) + '\x01';
        }
        uVar11 = uVar11 + 1;
        uVar16 = uVar11 & 0xff;
      } while (uVar16 < uVar15);
    }
    bVar2 = *(byte *)(iVar12 + 0x365);
    bVar1 = *(byte *)(iVar12 + 0x362);
    *(short *)(iVar12 + 0x340) = (short)((uint)*(undefined4 *)(iVar4 + 0x28) >> 0x10);
    if (1 < bVar2) {
      uVar11 = 0;
      puVar5 = (undefined2 *)(iVar12 + 0x340);
      do {
        iVar10 = uVar11 + 0x40;
        uVar11 = uVar11 + 1;
        puVar5 = puVar5 + 1;
        *puVar5 = (short)((uint)*(undefined4 *)
                                 (*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar10 * 4 + 4) >> 0x10);
      } while (uVar11 != (byte)(bVar2 - 1));
    }
    uVar11 = *(uint *)(iVar4 + 0x24);
    *(short *)(iVar12 + 0x33e) = (short)uVar11;
    if ((bVar1 & 1) != 0) {
      if (bVar3) {
        iVar10 = 0x314;
      }
      else {
        iVar10 = 0x8f;
      }
      uVar11 = uVar11 & 0xffff;
      uVar15 = iVar10 + (uint)*(byte *)(iVar12 + 0x366) * 2;
      if (uVar15 <= uVar11) {
        uVar11 = uVar15;
      }
      *(short *)(iVar12 + 0x33e) = (short)uVar11;
      *(uint *)(iVar4 + 0x24) = uVar11;
      uVar6 = *(ushort *)(iVar12 + 0x340);
      if (0x1f < uVar6) {
        uVar6 = 0x20;
      }
      *(uint *)(iVar4 + 0x28) = CONCAT22(uVar6,*(undefined2 *)(iVar12 + 0x33e));
    }
    iVar10 = FUN_0e064888(param_1,0,0,0x40,0);
    if ((iVar10 != 0) || (iVar10 = FUN_0e064888(param_1,0x80,0,0x40,0), iVar10 != 0)) {
      return -5;
    }
    *(undefined4 *)(iVar4 + 0x18) = 0x803c3808;
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x18);
    if (((iVar4 == 0) || (pcVar7 = *(code **)(iVar4 + 8), pcVar7 == (code *)0x0)) ||
       (iVar4 = (*pcVar7)(param_1), iVar4 == 0)) {
      *(uint *)(iVar14 + 8) = *(uint *)(iVar14 + 8) | 1;
      (**(code **)(iVar13 + 0x20))(param_1);
      *(uint *)(iVar14 + 0x804) = *(uint *)(iVar14 + 0x804) & 0xfffffffd;
      return 0;
    }
  }
  return iVar4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e065f78. Types and names are inferred; NOT original source. */

undefined4 FUN_0e065f78(int param_1,int param_2)

{
  ushort uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  
  uVar5 = (uint)*(byte *)(param_2 + 0x18);
  uVar8 = uVar5 & 0x7f;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar12 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  cVar2 = *(char *)(param_2 + 0x18);
  if ((*(byte *)(param_2 + 0x18) & 0x7f) != 0) {
    if (cVar2 < '\0') {
      if ((*(byte *)(iVar12 + 0x365) != 0) && (*(byte *)(iVar12 + 0x365) - 1 < uVar8)) {
        return 0xffffffea;
      }
      iVar9 = uVar8 + 0x48;
    }
    else {
      iVar9 = uVar8 + 0x58;
    }
    puVar10 = (uint *)(iVar4 + iVar9 * 0x20);
    uVar1 = *(ushort *)(param_2 + 0x1a);
    uVar11 = uVar1 & 0x7ff;
    bVar3 = *(byte *)(param_2 + 0x19) & 3;
    uVar6 = *puVar10 & 0xfff3f800 | uVar11;
    if (bVar3 == 2) {
      uVar6 = uVar6 | 0x10080000;
    }
    else if (bVar3 == 3) {
      uVar6 = uVar6 | 0x100c0000;
    }
    else {
      if (bVar3 != 1) {
        return 0xffffffea;
      }
      uVar6 = uVar6 | 0x40000;
    }
    if (cVar2 < '\0') {
      if ((uVar1 & 0x7ff) == 0) {
        uVar6 = uVar6 | 0x8000;
        goto LAB_0e06609a;
      }
      uVar11 = uVar11 + 3 >> 2;
      uVar11 = ((uVar1 & 0x1fff) >> 0xb) * uVar11 + uVar11;
      if ((int)((uint)*(byte *)(iVar12 + 0x362) << 0x1f) < 0) {
        if ((-(1 << uVar8) & *(uint *)(iVar12 + 0x2b0)) != 0) {
          bVar3 = *(char *)(iVar12 + 0x365) - 1;
          if (bVar3 == 0) {
            return 0xfffffffb;
          }
          do {
            iVar4 = FUN_0e06465c(param_1,bVar3 | 0x80);
            uVar7 = *(uint *)(iVar12 + 0x2b0);
            if ((*(byte *)(iVar4 + 0x14) & 1) == 0) {
              if ((int)((uVar7 >> (uint)bVar3) << 0x1f) < 0) {
                *(uint *)(iVar12 + 0x2b0) = uVar7 & ~(1 << (uint)bVar3);
              }
            }
            else if ((int)((uVar7 >> (uint)bVar3) << 0x1f) < 0) goto LAB_0e066232;
            bVar3 = bVar3 - 1;
          } while (bVar3 != 0);
          uVar7 = *(uint *)(iVar12 + 0x2b0);
LAB_0e066232:
          if ((-(1 << uVar8) & uVar7) != 0) {
            return 0xfffffffb;
          }
        }
        if (uVar8 == 1) {
          if (*(ushort *)(iVar12 + 0x340) < 0x21) {
            uVar7 = (uint)*(ushort *)(iVar12 + 0x33e) + (uint)*(ushort *)(iVar12 + 0x340);
          }
          else {
            uVar7 = *(ushort *)(iVar12 + 0x33e) + 0x20;
          }
        }
        else {
          iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10) + uVar8 * 4;
          uVar7 = (*(uint *)(iVar4 + 0xfc) & 0xffff) + (*(uint *)(iVar4 + 0xfc) >> 0x10);
        }
        if ((*(ushort *)(iVar12 + (uVar8 + 0x1a0) * 2) < uVar11) ||
           ((uint)*(ushort *)(iVar12 + 0x33c) < uVar11 + uVar7)) {
          return 0xfffffff4;
        }
        *(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + (uVar8 + 0x3f) * 4 + 4) =
             uVar7 | uVar11 * 0x10000;
      }
      else if (*(uint *)(iVar4 + uVar8 * 4 + 0x100) >> 0x10 < uVar11) {
        return 0xfffffff4;
      }
      *(uint *)(iVar12 + 0x2b0) = *(uint *)(iVar12 + 0x2b0) | 1 << uVar8;
      iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      *(uint *)(iVar4 + 0x10) = (uVar5 & 0x1f) << 6 | 0x20;
      do {
      } while (*(int *)(iVar4 + 0x10) << 0x1a < 0);
      uVar8 = *(byte *)(param_2 + 0x18) & 0x7f;
      iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
      uVar6 = (uVar5 & 0xf) << 0x16 | uVar6 & 0xfc3fffff | 0x8000;
      if ((int)((uint)*(byte *)(param_2 + 0x18) << 0x18) < 0) goto LAB_0e06609a;
    }
    else {
      uVar6 = uVar6 | 0x8000;
    }
    uVar8 = uVar8 + 0x10;
LAB_0e06609a:
    *(uint *)(iVar4 + 0x81c) = *(uint *)(iVar4 + 0x81c) | 1 << uVar8;
    *puVar10 = uVar6;
    return 0;
  }
  uVar1 = *(ushort *)(param_2 + 0x1a);
  if (cVar2 < '\0') {
    puVar10 = (uint *)(iVar4 + 0x900);
    uVar8 = *(uint *)(iVar4 + 0x900) & 0xfffffffc;
    if (uVar1 == 0x20) {
      uVar8 = uVar8 | 0x8001;
    }
    else if (uVar1 < 0x21) {
      if (uVar1 == 8) {
        uVar8 = uVar8 | 0x8003;
      }
      else {
        if (uVar1 != 0x10) {
          return 0xffffffea;
        }
        uVar8 = uVar8 | 0x8002;
      }
    }
    else {
      if (uVar1 != 0x40) {
        return 0xffffffea;
      }
      uVar8 = uVar8 | 0x8000;
    }
  }
  else {
    uVar8 = *(uint *)(iVar4 + 0xb00) & 0xfffffffc;
    if (uVar1 == 0x20) {
      uVar8 = uVar8 | 1;
    }
    else if (uVar1 < 0x21) {
      if (uVar1 == 8) {
        uVar8 = uVar8 | 3;
      }
      else {
        if (uVar1 != 0x10) {
          return 0xffffffea;
        }
        uVar8 = uVar8 | 2;
      }
    }
    else if (uVar1 != 0x40) {
      return 0xffffffea;
    }
    uVar8 = uVar8 | 0x8000;
    puVar10 = (uint *)(iVar4 + 0xb00);
    if (uVar5 == 0) {
      *(undefined4 *)(iVar4 + 0x10) = 0x10;
      do {
      } while (*(int *)(iVar4 + 0x10) << 0x1b < 0);
      goto LAB_0e066024;
    }
  }
  *(undefined4 *)(iVar4 + 0x10) = 0x20;
  do {
  } while (*(int *)(iVar4 + 0x10) << 0x1a < 0);
LAB_0e066024:
  *puVar10 = uVar8;
  uVar8 = *(byte *)(param_2 + 0x18) & 0x7f;
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(byte *)(param_2 + 0x18) & 0x80) == 0) {
    uVar8 = uVar8 + 0x10;
  }
  *(uint *)(iVar4 + 0x81c) = *(uint *)(iVar4 + 0x81c) | 1 << uVar8;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e066280. Types and names are inferred; NOT original source. */

void FUN_0e066280(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((iVar2 != 0) && (pcVar3 = *(code **)(iVar2 + 0x24), pcVar3 != (code *)0x0)) {
    (*pcVar3)();
  }
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xffffffdf;
  FUN_0e06c6b4(1);
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xffffffef;
  FUN_0e06c6b4(1);
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) | 4;
  FUN_0e06c6b4(1);
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffff7;
  if (param_2 != 0) {
    if ((int)((uint)*(byte *)(iVar8 + 0x362) << 0x1d) < 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0x32;
    }
    FUN_0e06c6b4(uVar1);
  }
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) | 0x10;
  FUN_0e06c6b4(1);
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffe;
  iVar7 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  uVar4 = *(uint *)(iVar7 + 0x2a8);
  uVar6 = uVar4 & 0xffffc000;
  *(undefined4 *)(iVar2 + 0x54) = *(undefined4 *)(iVar7 + 0xd0);
  if ((uVar4 & 0x18000000) == 0) {
    uVar6 = uVar6 | 0x20000;
  }
  *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar7 + 0xcc);
  *(uint *)(iVar2 + 0xe00) = uVar6;
  *(uint *)(iVar2 + 8) = *(uint *)(iVar7 + 0xb8) | 1;
  *(undefined4 *)(iVar2 + 0x14) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0x18) = 0x10000;
  *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar7 + 0xbc);
  uVar1 = *(undefined4 *)(iVar7 + 0x114);
  *(undefined4 *)(iVar2 + 0x800) = uVar1;
  if (param_3 != 0) {
    *(undefined4 *)(iVar2 + 0x800) = uVar1;
  }
  if (param_2 == 0) {
    uVar6 = uVar6 | 0x208;
  }
  *(uint *)(iVar2 + 0xe00) = uVar6;
  FUN_0e06c6b4(1);
  *(uint *)(iVar2 + 0xe00) = uVar6 | 0x2000;
  FUN_0e065238(param_1,iVar2 + 0x14,0x10000);
  if ((int)((uint)*(byte *)(iVar7 + 0x362) << 0x1c) < 0) {
    *(uint *)(iVar2 + 0xe00) = uVar6;
    FUN_0e06c6b4(1);
  }
  if (param_3 == 0) {
    *(undefined4 *)(iVar2 + 0x14) = 0xffffffff;
  }
  *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffb;
  FUN_0e06c6b4(1);
  if (param_2 == 0) {
    *(uint *)(iVar5 + 0xe00) = *(uint *)(iVar5 + 0xe00) & 0xfffffff7;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar8 + 0xbc);
    *(undefined4 *)(iVar5 + 0x800) = *(undefined4 *)(iVar8 + 0x114);
    *(undefined4 *)(iVar5 + 0x804) = *(undefined4 *)(iVar8 + 0x118);
    *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffd;
    FUN_0e06c6b4(5);
    *(uint *)(iVar5 + 0x804) = *(uint *)(iVar5 + 0x804) | 0x800;
  }
  else {
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar8 + 0xbc);
    *(undefined4 *)(iVar5 + 0x800) = *(undefined4 *)(iVar8 + 0x114);
    *(undefined4 *)(iVar5 + 0x804) = *(undefined4 *)(iVar8 + 0x118);
    *(uint *)(iVar5 + 0x58) = *(uint *)(iVar5 + 0x58) & 0xfffffffd;
    FUN_0e06c6b4(1);
    *(uint *)(iVar5 + 0x804) = *(uint *)(iVar8 + 0x118) | 1;
  }
  FUN_0e06e334(1000,0);
  *(undefined4 *)(iVar5 + 0x14) = 0xffffffff;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e066448. Types and names are inferred; NOT original source. */

undefined4 FUN_0e066448(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar4 + 0x10);
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  *(uint *)(iVar3 + 0x804) = *(uint *)(iVar3 + 0x804) | 2;
  iVar1 = FUN_0e064968(param_1,0);
  if ((iVar1 == 0) && (iVar1 = FUN_0e064968(param_1,0x80), iVar1 == 0)) {
    (**(code **)(iVar4 + 0x24))(param_1);
    if ((int)((uint)*(byte *)(iVar5 + 0x362) << 0x1b) < 0) {
      FUN_0e066280(param_1,0,1);
      *(byte *)(iVar5 + 0x362) = *(byte *)(iVar5 + 0x362) & 0xef;
    }
    *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffffe;
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x18);
    uVar2 = 0;
    if ((iVar1 != 0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0xc), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0e06649e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*UNRECOVERED_JUMPTABLE)(param_1);
      return uVar2;
    }
  }
  else {
    uVar2 = 0xfffffffb;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0664c4. Types and names are inferred; NOT original source. */

void FUN_0e0664c4(int param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  code *UNRECOVERED_JUMPTABLE;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  undefined4 local_2c [2];
  undefined4 *puVar21;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  iVar12 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((int)((uint)*(byte *)(iVar8 + 0x362) << 0x1b) < 0) {
    uVar11 = *(uint *)(iVar12 + 0x58);
    *(uint *)(iVar12 + 0x58) = uVar11;
    if (((int)(uVar11 << 0x18) < 0) && ((uVar11 & 0x1fffff) >> 0x13 == 2)) {
      FUN_0e06edc0(iVar8 + 0x90,0x80);
    }
    if ((uVar11 & 0x200) != 0) {
      FUN_0e06edc0(iVar8 + 0x90,0x40);
    }
  }
  else {
    uVar11 = *(uint *)(iVar12 + 0x18);
LAB_0e0664f0:
    uVar14 = *(uint *)(iVar12 + 0x14) & uVar11;
    if (uVar14 != 0) {
      do {
        if ((int)(uVar14 << 0x1c) < 0) {
          *(undefined4 *)(iVar12 + 0x14) = 8;
          *(ushort *)(iVar8 + 0x360) = (ushort)((uint)(*(int *)(iVar12 + 0x808) << 10) >> 0x12);
          FUN_0e064778(param_1,5,0);
        }
        if ((int)(uVar14 << 0x13) < 0) {
          *(undefined4 *)(iVar12 + 0x14) = 0x1000;
          FUN_0e065114(param_1);
          FUN_0e06edd4(iVar8 + 0x90,0x20);
        }
        if ((int)(uVar14 << 0x12) < 0) {
          *(undefined4 *)(iVar12 + 0x14) = 0x2000;
          iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
          *(byte *)(iVar16 + 0x362) =
               (byte)((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + 0x808) >> 1) << 6) | 0x20
               | *(byte *)(iVar16 + 0x362) & 0x1f;
          FUN_0e06edc0(iVar16 + 0x90,1);
          FUN_0e064778(param_1,4,0);
        }
        if ((int)uVar14 < 0) {
          *(undefined4 *)(iVar12 + 0x14) = 0x80000000;
          FUN_0e06462c(param_1,0);
          FUN_0e064778(param_1,2,0);
          FUN_0e06edd4(iVar8 + 0x90,0x20);
        }
        if ((int)(uVar14 << 0xd) < 0) {
          uVar3 = 0;
          iVar16 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar17 = *(uint *)(iVar16 + 0x810);
          uVar13 = *(uint *)(iVar16 + 0x818);
          do {
            while ((iVar18 = iVar16 + uVar3 * 0x20, -1 < (int)((uVar13 >> (uVar3 & 0xff)) << 0x1f)
                   || (uVar15 = uVar17 & *(uint *)(iVar18 + 0x908),
                      *(uint *)(iVar18 + 0x908) = uVar15, -1 < (int)(uVar15 << 0x1f)))) {
LAB_0e0668ac:
              uVar3 = uVar3 + 1;
              if (uVar3 == 0x10) goto LAB_0e06693a;
            }
            iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
            iVar18 = FUN_0e06465c(param_1,(uVar3 | 0xffffff80) & 0xff);
            iVar9 = FUN_0e064738(param_1,*(undefined1 *)(iVar18 + 0x18));
            if (iVar9 == 0) {
              FUN_0e064778(param_1,7,0xffffff97);
              goto LAB_0e0668ac;
            }
            FUN_0e061bec(iVar9 + 0xc,*(undefined4 *)(iVar4 + uVar3 * 4 + 700));
            if ((*(short *)(iVar9 + 0x10) != 0) &&
               (iVar18 = FUN_0e065570(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),
                                      iVar18,iVar9), iVar18 == 0)) goto LAB_0e0668ac;
            FUN_0e06edc0(iVar4 + 0xa8,1 << (uVar3 & 0xff));
            uVar3 = uVar3 + 1;
            FUN_0e06edc0(iVar4 + 0x90,8);
          } while (uVar3 != 0x10);
LAB_0e06693a:
          *(undefined4 *)(iVar16 + 0x14) = 0x40000;
        }
        if ((int)(uVar14 << 0x1b) < 0) {
          iVar16 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar17 = *(uint *)(iVar16 + 0x20);
          uVar13 = (uVar17 & 0x1fffff) >> 0x11;
          uVar3 = uVar17 & 0xf;
          uVar17 = (uVar17 & 0x7fff) >> 4;
          if (uVar13 == 2) {
            iVar16 = FUN_0e06465c(param_1,uVar3);
            iVar16 = FUN_0e064738(param_1,*(undefined1 *)(iVar16 + 0x18));
            iVar18 = *(int *)(*(int *)(param_1 + 4) + 0x10);
            if (iVar16 == 0) {
              if (uVar17 != 0) {
                uVar3 = uVar17 + 3 >> 2;
                goto LAB_0e066b08;
              }
            }
            else {
              iVar16 = iVar16 + 0xc;
              uVar15 = FUN_0e061bfc(iVar16);
              uVar13 = uVar17;
              if (uVar15 <= uVar17) {
                uVar13 = FUN_0e061bfc(iVar16);
              }
              if (uVar13 >> 2 != 0) {
                uVar15 = 0;
                do {
                  uVar15 = uVar15 + 1;
                  FUN_0e061bcc(iVar16,*(undefined4 *)(iVar18 + (uVar3 + 1) * 0x1000));
                } while (uVar15 != uVar13 >> 2);
              }
              if ((uVar13 & 3) != 0) {
                local_2c[0] = *(undefined4 *)(iVar18 + (uVar3 + 1) * 0x1000);
                puVar21 = local_2c;
                do {
                  puVar20 = (undefined4 *)((int)puVar21 + 1);
                  FUN_0e061b98(iVar16,*(undefined1 *)puVar21);
                  puVar21 = puVar20;
                } while ((undefined4 *)((uVar13 & 3) + (int)local_2c) != puVar20);
              }
              if ((uVar13 < uVar17) && (uVar3 = (uVar17 + 3) - uVar13 >> 2, uVar3 != 0)) {
LAB_0e066b08:
                uVar13 = 0;
                do {
                  uVar13 = uVar13 + 1;
                } while (uVar13 != uVar3);
              }
            }
          }
          else if ((uVar13 == 6) && (uVar17 != 0)) {
            iVar18 = 0;
            uVar13 = uVar17;
            if (7 < uVar17) {
              uVar13 = 8;
            }
            iVar9 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
            do {
              uVar15 = iVar18 + 4;
              uVar6 = *(undefined4 *)(iVar16 + (uVar3 + 1) * 0x1000);
              *(char *)(iVar9 + 0x367) = (char)uVar6;
              *(char *)(iVar9 + 0x369) = (char)((uint)uVar6 >> 0x10);
              *(char *)(iVar9 + 0x368) = (char)((uint)uVar6 >> 8);
              *(char *)(iVar9 + 0x36a) = (char)((uint)uVar6 >> 0x18);
              iVar18 = 4;
              iVar9 = iVar9 + 4;
            } while (uVar15 < uVar13);
            for (; uVar15 < uVar17; uVar15 = uVar15 + 4) {
            }
          }
        }
        if ((int)(uVar14 << 0xc) < 0) {
          iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
          iVar18 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar3 = *(uint *)(iVar18 + 0x814);
          uVar13 = 0;
          uVar17 = *(uint *)(iVar18 + 0x818);
          do {
            while (-1 < (int)((uVar17 >> (uVar13 + 0x10 & 0xff)) << 0x1f)) {
LAB_0e06671e:
              uVar13 = uVar13 + 1;
              if (uVar13 == 0x10) goto LAB_0e0667ce;
            }
            iVar9 = iVar18 + uVar13 * 0x20;
            uVar15 = *(uint *)(iVar9 + 0xb08) & uVar3;
            *(uint *)(iVar9 + 0xb08) = uVar15;
            if ((int)(uVar15 << 0x1c) < 0) {
              FUN_0e06edc0(iVar16 + 0x90,4);
            }
            if (-1 < (int)(uVar15 << 0x1f)) goto LAB_0e06671e;
            iVar9 = FUN_0e06465c(param_1,uVar13 & 0xff);
            uVar15 = *(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + uVar13 * 0x20 + 0xb10);
            bVar1 = *(byte *)(iVar9 + 0x19);
            iVar19 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
            iVar4 = FUN_0e064738(param_1,*(undefined1 *)(iVar9 + 0x18));
            if (iVar4 == 0) {
              FUN_0e064778(param_1,7,0xffffff97);
              goto LAB_0e06671e;
            }
            uVar5 = *(uint *)(iVar19 + uVar13 * 4 + 0x2fc);
            uVar10 = (uVar5 & 0x7ffff) - (uVar15 & 0x7ffff);
            if ((bVar1 & 3) == 1) {
              uVar10 = (uVar15 & 0x7fffffff) >> 0x1d;
              iVar9 = ((uVar5 & 0x1fffffff) >> 0x13) - ((uVar15 & 0x1fffffff) >> 0x13);
              if (uVar10 == 1) {
                if (iVar9 != 3) goto LAB_0e06680c;
              }
              else if (uVar10 == 2) {
                if (iVar9 != 2) goto LAB_0e06680c;
              }
              else if ((uVar10 != 0) || (iVar9 != 1)) {
LAB_0e06680c:
                FUN_0e061bdc(iVar4 + 0xc);
              }
            }
            else if (((uVar10 != 0) &&
                     (uVar15 = *(ushort *)(iVar9 + 0x1a) & 0x7ff,
                     uVar10 == uVar15 * (uVar10 / uVar15))) &&
                    (iVar7 = FUN_0e061bfc(iVar4 + 0xc), iVar7 != 0)) {
              FUN_0e065480(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),iVar4,iVar9)
              ;
              goto LAB_0e06671e;
            }
            FUN_0e06edc0(iVar19 + 0xa8,1 << (uVar13 + 0x10 & 0xff));
            uVar13 = uVar13 + 1;
            FUN_0e06edc0(iVar19 + 0x90,8);
          } while (uVar13 != 0x10);
LAB_0e0667ce:
          *(undefined4 *)(iVar18 + 0x14) = 0x80000;
        }
        if ((int)(uVar14 << 0xb) < 0) {
          iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
          iVar18 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar3 = (uint)*(byte *)(iVar16 + 0x364);
          if (1 < uVar3) {
            uVar13 = 1;
            do {
              while ((1 < (3 << (uVar13 << 1 & 0xff) & *(uint *)(iVar16 + 0x2ac)) >>
                          (uVar13 << 1 & 0xff) ||
                     ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) +
                                ((uVar13 & 0x7f) + 0x48) * 0x20) & 0x800c8000) != 0x80048000))) {
                uVar13 = uVar13 + 1 & 0xff;
                if (uVar3 <= uVar13) goto LAB_0e0666ec;
              }
              iVar9 = FUN_0e06465c(param_1,uVar13 | 0x80);
              FUN_0e06578c(param_1,iVar9,0);
              iVar4 = FUN_0e0646d4(param_1,*(undefined1 *)(iVar9 + 0x18));
              if (iVar4 != 0) {
                FUN_0e064798(param_1,iVar4,0);
                FUN_0e065734(param_1,iVar9);
              }
              uVar3 = (uint)*(byte *)(iVar16 + 0x364);
              uVar13 = uVar13 + 1 & 0xff;
            } while (uVar13 < uVar3);
          }
LAB_0e0666ec:
          *(undefined4 *)(iVar18 + 0x14) = 0x100000;
        }
        if ((int)(uVar14 << 10) < 0) {
          iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
          iVar18 = *(int *)(*(int *)(param_1 + 4) + 0x10);
          uVar2 = *(ushort *)(iVar16 + 0x360);
          uVar3 = (uint)*(byte *)(iVar16 + 0x364);
          if (1 < uVar3) {
            uVar13 = 1;
            do {
              while (((3 << (uVar13 << 1 & 0xff) & *(uint *)(iVar16 + 0x2ac)) >>
                      (uVar13 << 1 & 0xff) & 0xfffffffd) != 0) {
LAB_0e066562:
                uVar13 = uVar13 + 1 & 0xff;
                if (uVar3 <= uVar13) goto LAB_0e0665e4;
              }
              iVar9 = (uVar13 & 0x7f) + 0x58;
              if ((uVar13 & 0x80) != 0) {
                iVar9 = (uVar13 & 0x7f) + 0x48;
              }
              if (((uVar2 & 1) << 0x10 | 0x80048000) !=
                  (*(uint *)(*(int *)(*(int *)(param_1 + 4) + 0x10) + iVar9 * 0x20) & 0x800d8000))
              goto LAB_0e066562;
              iVar9 = FUN_0e06465c(param_1,uVar13);
              FUN_0e06578c(param_1,iVar9,0);
              iVar9 = FUN_0e0646d4(param_1,*(undefined1 *)(iVar9 + 0x18));
              if (iVar9 != 0) {
                FUN_0e064798(param_1,iVar9,0);
              }
              uVar3 = (uint)*(byte *)(iVar16 + 0x364);
              uVar13 = uVar13 + 1 & 0xff;
            } while (uVar13 < uVar3);
          }
LAB_0e0665e4:
          *(undefined4 *)(iVar18 + 0x14) = 0x200000;
        }
        if (-1 < (int)(uVar14 << 0x14)) goto LAB_0e0664f0;
        *(undefined4 *)(iVar12 + 0x14) = 0x800;
        FUN_0e06462c(param_1,1);
        FUN_0e064778(param_1,3,0);
        if (*(char *)(iVar8 + 0x363) != '\x01') goto LAB_0e0664f0;
        FUN_0e06edc0(iVar8 + 0x90,0x20);
        uVar14 = *(uint *)(iVar12 + 0x14) & uVar11;
        if (uVar14 == 0) break;
      } while( true );
    }
  }
  iVar8 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  if ((iVar8 != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(iVar8 + 0x14), UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0e06664c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(param_1);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e066b60. Types and names are inferred; NOT original source. */

void FUN_0e066b60(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  FUN_0e066280();
  iVar8 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x10);
  *puVar2 = *(undefined4 *)(iVar8 + 0xb4);
  puVar2[2] = *(undefined4 *)(iVar8 + 0xb8);
  puVar2[3] = *(undefined4 *)(iVar8 + 0xbc);
  puVar2[6] = *(undefined4 *)(iVar8 + 0xc0);
  puVar2[9] = *(undefined4 *)(iVar8 + 0xc4);
  puVar2[10] = *(undefined4 *)(iVar8 + 200);
  puVar2[0x17] = *(undefined4 *)(iVar8 + 0xd4);
  if (1 < *(byte *)(iVar8 + 0x365)) {
    uVar3 = 1;
    do {
      puVar2[uVar3 + 0x40] = *(undefined4 *)(iVar8 + uVar3 * 4 + 0xd4);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < *(byte *)(iVar8 + 0x365));
  }
  if (param_2 == 0) {
    puVar2[0x201] = *(undefined4 *)(iVar8 + 0x118);
  }
  iVar4 = 0;
  puVar2[0x204] = *(undefined4 *)(iVar8 + 0x11c);
  puVar2[0x205] = *(undefined4 *)(iVar8 + 0x120);
  puVar7 = (undefined4 *)(iVar8 + 0x128);
  puVar2[0x207] = *(undefined4 *)(iVar8 + 0x124);
  do {
    while( true ) {
      uVar3 = (3 << (iVar4 << 1 & 0xffU) & *(uint *)(iVar8 + 0x2ac)) >> (iVar4 << 1 & 0xffU);
      if (uVar3 < 2) break;
      if (uVar3 == 2) {
LAB_0e066c14:
        iVar1 = iVar8 + iVar4 * 4;
        puVar2[iVar4 * 8 + 0x2c4] = *(undefined4 *)(iVar1 + 0x228);
        puVar2[iVar4 * 8 + 0x2c5] = *(undefined4 *)(iVar1 + 0x268);
        puVar2[(iVar4 + 0x58) * 8] = *(undefined4 *)(iVar1 + 0x1e8);
      }
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
      if (iVar4 == 0x10) goto LAB_0e066c8c;
    }
    puVar2[iVar4 * 8 + 0x244] = puVar7[0x10];
    puVar2[iVar4 * 8 + 0x245] = puVar7[0x20];
    puVar2[(iVar4 + 0x48) * 8] = *puVar7;
    if (uVar3 == 0) goto LAB_0e066c14;
    iVar4 = iVar4 + 1;
    puVar7 = puVar7 + 1;
  } while (iVar4 != 0x10);
LAB_0e066c8c:
  *(byte *)(iVar5 + 0x362) = *(byte *)(iVar5 + 0x362) & 0xef;
  FUN_0e06462c(param_1,0);
  FUN_0e064778(param_1,2,0);
  if (param_2 != 0) {
    FUN_0e06e334(1000,0);
    *(uint *)(iVar6 + 0x804) = *(uint *)(iVar6 + 0x804) & 0xfffffffe;
  }
  if (param_3 != 0) {
    FUN_0e06edd4(iVar5 + 0x9c,0xffffffff);
    FUN_0e06edd4(iVar5 + 0xa8,0xffffffff);
    FUN_0e065114(param_1);
    return;
  }
  iVar6 = FUN_0e06eddc(iVar5 + 0x9c,0xffffffff,0,0,0,0);
  if (iVar6 != 0) {
    FUN_0e06edc0(iVar5 + 0x90,2);
  }
  iVar6 = FUN_0e06eddc(iVar5 + 0xa8,0xffffffff,0);
  if (iVar6 == 0) {
    return;
  }
  FUN_0e06edc0(iVar5 + 0x90,8);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e066d3c. Types and names are inferred; NOT original source. */

void FUN_0e066d3c(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  undefined4 *puVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  code *pcVar15;
  int iVar16;
  byte bVar17;
  undefined4 *puVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  bool bVar22;
  ulonglong uVar23;
  
  do {
    iVar21 = *(int *)(param_1 + 4);
    iVar20 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
    iVar12 = *(int *)(iVar21 + 0x10);
    iVar19 = iVar20 + 0x90;
    uVar23 = FUN_0e06eddc(iVar19,0xffffffff,0,iVar12,0xffffffff,0xffffffff);
    iVar4 = (int)uVar23;
    FUN_0e06cdac(*(int *)(param_1 + 0x10) + 0x84,(int)(uVar23 >> 0x20),0xffffffff,0xffffffff);
    if (iVar4 << 0x1e < 0) {
      FUN_0e06edd4(iVar19,2);
      if ((*(byte *)(iVar20 + 0x362) & 0x10) == 0) {
        uVar5 = FUN_0e06eddc(iVar20 + 0x9c,0xffffffff,*(byte *)(iVar20 + 0x362) & 0x10,0,0,0);
        FUN_0e06edd4(iVar20 + 0x9c,uVar5);
      }
      else {
        uVar5 = 0;
      }
      while (uVar5 != 0) {
        bVar1 = (byte)uVar5;
        bVar2 = (byte)(uVar5 >> 8);
        bVar3 = (byte)(uVar5 >> 0x10);
        bVar17 = (byte)(uVar5 >> 0x18);
        uVar13 = LZCOUNT((uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1
                                          ) << 1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                       bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                         0x18 | (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                                 bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                               bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                             bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x10 |
                         (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1
                                          ) << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                       bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                         8 | (uint)(byte)((((((((bVar17 & 1) << 1 | bVar17 >> 1 & 1) << 1 |
                                              bVar17 >> 2 & 1) << 1 | bVar17 >> 3 & 1) << 1 |
                                            bVar17 >> 4 & 1) << 1 | bVar17 >> 5 & 1) << 1 |
                                          bVar17 >> 6 & 1) << 1 | bVar17 >> 7));
        if (uVar13 < 0x10) {
          uVar7 = uVar13 | 0x80;
        }
        else {
          uVar7 = uVar13 - 0x10 & 0xff;
        }
        uVar5 = uVar5 & ~(1 << uVar13);
        iVar14 = FUN_0e06465c(param_1,uVar7);
        iVar16 = FUN_0e064670(param_1,*(undefined1 *)(iVar14 + 0x18));
        if (iVar16 == 0) {
          FUN_0e065734(param_1,iVar14);
        }
      }
    }
    if (iVar4 << 0x1c < 0) {
      FUN_0e06edd4(iVar19,8);
      if ((*(byte *)(iVar20 + 0x362) & 0x10) == 0) {
        uVar5 = FUN_0e06eddc(iVar20 + 0xa8,0xffffffff,*(byte *)(iVar20 + 0x362) & 0x10,0,0,0);
        FUN_0e06edd4(iVar20 + 0xa8,uVar5);
      }
      else {
        uVar5 = 0;
      }
LAB_0e066f70:
      if (uVar5 != 0) {
        do {
          bVar1 = (byte)uVar5;
          bVar2 = (byte)(uVar5 >> 8);
          bVar3 = (byte)(uVar5 >> 0x10);
          bVar17 = (byte)(uVar5 >> 0x18);
          uVar13 = LZCOUNT((uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 |
                                            bVar1 >> 2 & 1) << 1 | bVar1 >> 3 & 1) << 1 |
                                          bVar1 >> 4 & 1) << 1 | bVar1 >> 5 & 1) << 1 |
                                        bVar1 >> 6 & 1) << 1 | bVar1 >> 7) << 0x18 |
                           (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                            bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                          bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                        bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x10 |
                           (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                            bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                          bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                        bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 8 |
                           (uint)(byte)((((((((bVar17 & 1) << 1 | bVar17 >> 1 & 1) << 1 |
                                            bVar17 >> 2 & 1) << 1 | bVar17 >> 3 & 1) << 1 |
                                          bVar17 >> 4 & 1) << 1 | bVar17 >> 5 & 1) << 1 |
                                        bVar17 >> 6 & 1) << 1 | bVar17 >> 7));
          uVar5 = uVar5 & ~(1 << uVar13);
          if (uVar13 < 0x10) {
            iVar14 = FUN_0e06465c(param_1,uVar13 | 0x80);
            iVar16 = FUN_0e064738(param_1,*(undefined1 *)(iVar14 + 0x18));
            if (iVar16 == 0) {
              FUN_0e064778(param_1,7,0xffffff97);
            }
            else if (*(short *)(iVar16 + 0x10) == 0) {
              cVar8 = *(char *)(iVar14 + 0x18);
              if (cVar8 == -0x80) {
                iVar11 = FUN_0e064764();
                if (iVar11 != 0) {
                  FUN_0e06476c(iVar16);
                  goto LAB_0e067052;
                }
                cVar8 = *(char *)(iVar14 + 0x18);
              }
              iVar16 = FUN_0e0646d4(param_1,cVar8);
              FUN_0e064688(param_1,*(undefined1 *)(iVar14 + 0x18),0);
              if (*(char *)(iVar14 + 0x18) != -0x80) goto LAB_0e066fcc;
              iVar11 = FUN_0e064f34(param_1);
              if ((iVar11 != 0) || (iVar11 = FUN_0e064f48(param_1), iVar11 != 0)) {
                FUN_0e064eb0(param_1,iVar16);
              }
              FUN_0e064f5c(param_1,iVar16);
              iVar11 = FUN_0e064f20(param_1);
              if (iVar11 != 0) {
                FUN_0e0652f8(param_1,8);
                FUN_0e061ac0(iVar16);
              }
            }
            else {
LAB_0e067052:
              FUN_0e065570(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x10),iVar14,
                           iVar16);
            }
          }
          else {
            iVar14 = FUN_0e06465c(param_1,uVar13 - 0x10 & 0xff);
            iVar16 = FUN_0e0646d4(param_1,*(undefined1 *)(iVar14 + 0x18));
            if (iVar16 != 0) {
              FUN_0e064688(param_1,*(undefined1 *)(iVar14 + 0x18),0);
              if (*(char *)(iVar14 + 0x18) == '\0') {
                iVar11 = FUN_0e064f20(param_1);
                if (iVar11 != 0) {
                  FUN_0e064eb0(param_1,iVar16);
                }
                FUN_0e064f5c(param_1,iVar16);
                iVar11 = FUN_0e064f34(param_1);
                if (iVar11 != 0) {
                  FUN_0e064d60(param_1,iVar16);
                }
              }
              else {
LAB_0e066fcc:
                FUN_0e064798(param_1,iVar16,0);
              }
            }
          }
          iVar16 = FUN_0e064670(param_1,*(undefined1 *)(iVar14 + 0x18));
          if (iVar16 != 0) goto LAB_0e066f70;
          FUN_0e065734(param_1,iVar14);
          if (uVar5 == 0) break;
        } while( true );
      }
    }
    if (iVar4 << 0x1d < 0) {
      FUN_0e06edd4(iVar19,4);
      iVar16 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
      FUN_0e06edd4(iVar16 + 0xa8,0x10001);
      iVar14 = FUN_0e0646f0(param_1,0);
      if (iVar14 != 0) {
        FUN_0e061ac0();
      }
      iVar14 = FUN_0e0646f0(param_1,0x80);
      if (iVar14 != 0) {
        uVar6 = FUN_0e06465c(param_1,0x80);
        FUN_0e06578c(param_1,uVar6,0);
        FUN_0e061ac0(iVar14);
      }
      FUN_0e064688(param_1,0);
      FUN_0e064688(param_1,0x80,0);
      iVar14 = thunk_FUN_0e064b64(param_1,0,8);
      if (iVar14 != 0) {
        FUN_0e061b84(iVar14 + 0xc,iVar16 + 0x367,8);
        FUN_0e064754(iVar14);
        FUN_0e064f5c(param_1,iVar14);
        iVar16 = FUN_0e064ef8(param_1);
        if (iVar16 == 0) {
          iVar14 = FUN_0e064f0c(param_1);
          if (iVar14 == 0) {
            FUN_0e064e48(param_1);
          }
          else {
            FUN_0e064dd4(param_1);
          }
        }
        else {
          iVar16 = FUN_0e0652f8(param_1,*(undefined2 *)(*(int *)(iVar14 + 0xc) + 6));
          if (iVar16 == -0xc) {
            FUN_0e064798(param_1,iVar14,0xfffffff4);
          }
        }
      }
    }
    if (iVar4 << 0x1b < 0) {
      FUN_0e06edd4(iVar19,0x30);
      bVar17 = *(byte *)(iVar20 + 0x362) & 0x10;
      if ((*(byte *)(iVar20 + 0x362) & 0x10) == 0) {
        *(uint *)(iVar12 + 0x804) = *(uint *)(iVar12 + 0x804) | 1;
        FUN_0e06462c(param_1,bVar17);
        FUN_0e064778(param_1,2,bVar17);
        FUN_0e06e334(2000,0);
        *(uint *)(iVar12 + 0x804) = *(uint *)(iVar12 + 0x804) & 0xfffffffe;
      }
      else {
        (**(code **)(iVar21 + 0x24))(param_1);
        FUN_0e066b60(param_1,1,0);
        (**(code **)(iVar21 + 0x20))(param_1);
      }
    }
    if (iVar4 << 0x1a < 0) {
      (**(code **)(iVar21 + 0x24))(param_1);
      iVar12 = FUN_0e06edd4(iVar19,0x20);
      if (iVar12 << 0x1a < 0) {
        puVar18 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x10);
        iVar12 = *(int *)(*(int *)(param_1 + 0x10) + 0xac);
        bVar17 = *(byte *)(iVar12 + 0x365);
        *(undefined4 *)(iVar12 + 0xb4) = *puVar18;
        *(undefined4 *)(iVar12 + 0xb8) = puVar18[2];
        *(undefined4 *)(iVar12 + 0xbc) = puVar18[3];
        *(undefined4 *)(iVar12 + 0xc0) = puVar18[6];
        *(undefined4 *)(iVar12 + 0xc4) = puVar18[9];
        *(undefined4 *)(iVar12 + 200) = puVar18[10];
        *(undefined4 *)(iVar12 + 0xcc) = puVar18[0xc];
        *(undefined4 *)(iVar12 + 0xd0) = puVar18[0x15];
        *(undefined4 *)(iVar12 + 0xd4) = puVar18[0x17];
        if (1 < bVar17) {
          uVar5 = 0;
          puVar9 = (undefined4 *)(iVar12 + 0xd4);
          do {
            iVar14 = uVar5 + 0x41;
            uVar5 = uVar5 + 1;
            puVar9 = puVar9 + 1;
            *puVar9 = puVar18[iVar14];
          } while (uVar5 != (byte)(bVar17 - 1));
        }
        *(undefined4 *)(iVar12 + 0x114) = puVar18[0x200];
        *(undefined4 *)(iVar12 + 0x118) = puVar18[0x201];
        uVar5 = *(uint *)(iVar12 + 0x2ac);
        *(undefined4 *)(iVar12 + 0x11c) = puVar18[0x204];
        puVar10 = (uint *)(iVar12 + 0x128);
        *(undefined4 *)(iVar12 + 0x120) = puVar18[0x205];
        *(undefined4 *)(iVar12 + 0x124) = puVar18[0x207];
        iVar14 = 0;
        do {
          while (uVar13 = (3 << (iVar14 << 1 & 0xffU) & uVar5) >> (iVar14 << 1 & 0xffU), 1 < uVar13)
          {
            if (uVar13 != 2) goto LAB_0e067148;
LAB_0e067190:
            uVar13 = puVar18[(iVar14 + 0x58) * 8];
            bVar22 = (int)(uVar13 << 0xf) < 0;
            if (bVar22) {
              uVar13 = uVar13 | 0x20000000;
            }
            iVar16 = iVar12 + iVar14 * 4;
            if (!bVar22) {
              uVar13 = uVar13 | 0x10000000;
            }
            *(uint *)(iVar16 + 0x1e8) = uVar13;
            iVar11 = iVar14 + 1;
            *(undefined4 *)(iVar16 + 0x228) = puVar18[iVar14 * 8 + 0x2c4];
            *(undefined4 *)(iVar16 + 0x268) = puVar18[iVar14 * 8 + 0x2c5];
            puVar10 = puVar10 + 1;
            iVar14 = iVar11;
            if (iVar11 == 0x10) goto LAB_0e0671ca;
          }
          uVar7 = puVar18[(iVar14 + 0x48) * 8];
          if ((int)(uVar7 << 0xf) < 0) {
            uVar7 = uVar7 | 0x20000000;
          }
          else {
            uVar7 = uVar7 | 0x10000000;
          }
          *puVar10 = uVar7;
          puVar10[0x10] = puVar18[iVar14 * 8 + 0x244];
          puVar10[0x20] = puVar18[iVar14 * 8 + 0x245];
          if (uVar13 == 0) goto LAB_0e067190;
LAB_0e067148:
          iVar14 = iVar14 + 1;
          puVar10 = puVar10 + 1;
        } while (iVar14 != 0x10);
LAB_0e0671ca:
        *(undefined4 *)(iVar12 + 0x2a8) = puVar18[0x380];
        puVar18[0x16] = puVar18[0x16] | 2;
        FUN_0e06c6b4(1);
        puVar18[0x380] = puVar18[0x380] | 1;
        FUN_0e06c6b4(1);
        puVar18[0x16] = puVar18[0x16] | 1;
        FUN_0e06c6b4(1);
        puVar18[0x16] = puVar18[0x16] | 0x41500;
        FUN_0e06c6b4(1);
        puVar18[0x16] = puVar18[0x16] | 8;
        FUN_0e06c6b4(1);
        puVar18[0x16] = puVar18[0x16] | 0x20;
        iVar14 = *(int *)(*(int *)(param_1 + 4) + 0x18);
        if ((iVar14 != 0) && (pcVar15 = *(code **)(iVar14 + 0x20), pcVar15 != (code *)0x0)) {
          (*pcVar15)();
        }
        *(byte *)(iVar12 + 0x362) = *(byte *)(iVar12 + 0x362) | 0x10;
      }
      (**(code **)(iVar21 + 0x20))(param_1);
    }
    if ((uVar23 & 0xc0) != 0) {
      (**(code **)(iVar21 + 0x24))(param_1);
      uVar5 = FUN_0e06edd4(iVar19,0xc0);
      if ((int)((uint)*(byte *)(iVar20 + 0x362) << 0x1b) < 0) {
        FUN_0e066b60(param_1,0,(uVar5 & 0x7f) >> 6);
      }
      (**(code **)(iVar21 + 0x20))(param_1);
    }
    if (iVar4 << 0x1f < 0) {
      FUN_0e06edd4(iVar19,1);
    }
    FUN_0e06cea8(*(int *)(param_1 + 0x10) + 0x84);
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067308. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e067308(void)

{
  _DAT_e0083404 = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067318. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e067318(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (_DAT_e0083404 << 0x1f < 0) {
    if ((param_1 == 0) || (param_2 == 0)) {
      uVar2 = 0xffffffea;
    }
    else {
      uVar1 = param_1 & 0xffffffe0 | 0x10000000;
      do {
        do {
          _DAT_e0083410 = uVar1;
          uVar1 = _DAT_e0083410;
        } while ((int)(_DAT_e0083400 << 0x1f) < 0);
        _DAT_e0083018 = 1;
        uVar1 = _DAT_e0083410 + 0x20;
      } while (_DAT_e0083410 + 0x20 < (param_1 | 0x10000000) + param_2);
      do {
      } while ((_DAT_e0083400 & 1) != 0);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xfffffff5;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067378. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e067378(uint param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (_DAT_e0083404 << 0x1f < 0) {
    if ((param_1 == 0) || (param_2 == 0)) {
      uVar2 = 0xffffffea;
    }
    else {
      uVar1 = param_1 & 0xffffffe0 | 0x10000000;
      do {
        do {
          _DAT_e0083410 = uVar1;
          uVar1 = _DAT_e0083410;
        } while ((int)(_DAT_e0083400 << 0x1f) < 0);
        _DAT_e0083014 = 1;
        uVar1 = _DAT_e0083410 + 0x20;
      } while (_DAT_e0083410 + 0x20 < (param_1 | 0x10000000) + param_2);
      do {
      } while ((_DAT_e0083400 & 1) != 0);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xfffffff5;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0673d8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0673d8(void)

{
  _DAT_e0082404 = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0673e8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0673e8(int param_1,int param_2,int param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *local_20;
  int local_1c;
  
  iVar3 = *(int *)(param_1 + 8);
  *param_4 = 0;
  param_4[2] = 0;
  (**(code **)(iVar3 + 0x10))(param_1,&local_20,&local_1c);
  if (local_1c != 0) {
    iVar3 = param_4[2];
    iVar4 = *param_4;
    do {
      local_1c = local_1c + -1;
      uVar2 = local_20[1];
      param_4[1] = uVar2;
      if (param_2 == 0) {
        uVar1 = param_3 - iVar3;
      }
      else {
        uVar1 = (uint)(param_2 - iVar4) / uVar2;
      }
      if (*local_20 <= uVar1) {
        uVar1 = *local_20;
      }
      iVar4 = uVar1 * uVar2 + iVar4;
      iVar3 = iVar3 + uVar1;
      param_4[2] = iVar3;
      *param_4 = iVar4;
      if (uVar1 < *local_20) {
        return 0;
      }
      local_20 = local_20 + 2;
    } while (local_1c != 0);
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067468. Types and names are inferred; NOT original source. */

void FUN_0e067468(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0e0673e8(param_1,param_2,0,param_3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067598. Types and names are inferred; NOT original source. */

undefined4 FUN_0e067598(int param_1,uint param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte bVar5;
  uint uVar6;
  undefined1 uStack_25;
  uint local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  uint *local_18;
  undefined4 local_14;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar6 = param_2 & 0x1f | (uint)*(byte *)(iVar2 + 0xc) << 5;
  if (*(int *)(iVar2 + 0x10) == 0) {
    uVar4 = 0xffffff7a;
  }
  else {
    if (param_3 == 0x200000) {
      thunk_FUN_0e068ec4(iVar2 + 0x10,uVar6);
    }
    else {
      local_20 = (undefined1 *)0x0;
      if (param_3 == 0x400000) {
        if (param_4 == 0x2000000) {
          bVar5 = 4;
        }
        else {
          bVar5 = 5;
        }
        local_18 = &local_24;
        local_1c = 0;
        local_14 = 0;
        local_24 = (uint)bVar5;
      }
      else {
        if (param_4 == 0x6000000) {
          bVar5 = 3;
        }
        else if (param_4 == 0x2000000) {
          bVar5 = 2;
        }
        else {
          bVar5 = 1;
        }
        local_24 = (uint)bVar5;
        local_18 = &local_24;
        local_1c = 0;
        local_14 = 0;
        if (((*(uint *)(iVar2 + 8) >> (param_2 & 0xff) & 1) == 0) && (param_3 == 0x1400000)) {
          if (0x13f < uVar6) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)software_udf(0xff,0xe0676a4);
            (*pcVar1)();
          }
          if (-1 < *(int *)(*(int *)(&DAT_0e0703c8 + (uint)*(byte *)(iVar2 + 0xc) * 4) +
                           ((param_2 & 0x1f) + 0x20) * 4) << 0x1f) {
            iVar3 = FUN_0e0693c0(iVar2 + 0x10,uVar6,&uStack_25);
            if ((iVar3 == 0xbad0004) &&
               (iVar3 = FUN_0e0694c0(iVar2 + 0x10,&uStack_25), iVar3 != 0xbad0000)) {
              return 0xfffffff4;
            }
            local_20 = &uStack_25;
          }
        }
      }
      iVar3 = FUN_0e069008(iVar2 + 0x10,uVar6,&local_1c);
      if (iVar3 != 0xbad0000) {
        return 0xffffffea;
      }
      FUN_0e0694d8(iVar2 + 0x10,uVar6,1);
    }
    uVar4 = 0;
  }
  return uVar4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067700. Types and names are inferred; NOT original source. */

int FUN_0e067700(int param_1,uint param_2,uint param_3)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined1 local_3e;
  byte local_3d;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  
  if ((int)(param_3 << 0x1b) < 0) {
    local_3d = 3;
  }
  else {
    local_3d = (byte)((param_3 << 0x1a) >> 0x1f);
  }
  iVar4 = 0x306;
  iVar8 = *(int *)(param_1 + 4);
  uVar6 = param_3 & 0x306;
  bVar2 = *(byte *)(iVar8 + 0xc);
  if (uVar6 == 0x106) {
    uVar6 = 9;
LAB_0e067748:
    iVar9 = 1 << (param_2 & 0xff);
    if (*(char *)(iVar8 + 0x18) != '\x01') goto LAB_0e067758;
LAB_0e0677f4:
    iVar4 = FUN_0e061f9c();
    if (iVar4 < 0) {
      return iVar4;
    }
    iVar4 = *(int *)(iVar8 + 4);
    *(int *)(iVar4 + 0x48) = iVar9;
    if ((int)(param_3 << 0xc) < 0) goto LAB_0e06780a;
LAB_0e06775c:
    bVar10 = (int)(param_3 << 0xd) < 0;
    if (bVar10) {
      iVar4 = *(int *)(iVar8 + 4);
    }
    if (bVar10) {
      *(int *)(iVar4 + 8) = iVar9;
    }
    uVar7 = param_2 & 0x1f | (uint)bVar2 << 5;
    if (*(int *)(iVar8 + 0x10) != 0) goto LAB_0e06777a;
LAB_0e067822:
    if (0x13f < uVar7) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe067912);
      (*pcVar1)();
    }
    iVar4 = *(int *)(&DAT_0e0703c8 + (uVar7 >> 5) * 4) + (uVar7 & 0x1f) * 4;
    *(uint *)(iVar4 + 0x80) =
         (param_3 & 0x3ffff) >> 0x11 | (((param_3 ^ 0x10000) & 0x1ffff) >> 0x10) << 1 |
         (uint)local_3d << 2 | *(uint *)(iVar4 + 0x80) & 0xfffff0f0 | uVar6 << 8;
  }
  else {
    if (uVar6 < 0x107) {
      if (uVar6 == 6) {
        uVar6 = 8;
      }
      else if (uVar6 < 7) {
        if ((uVar6 != 0) && (uVar6 != 2)) {
          return -0x16;
        }
      }
      else {
        if (uVar6 != 0x100) {
          return -0x16;
        }
        uVar6 = 1;
      }
      goto LAB_0e067748;
    }
    if (uVar6 == 0x202) {
      uVar6 = 6;
      goto LAB_0e067748;
    }
    if (uVar6 == 0x300) {
      uVar6 = 5;
      goto LAB_0e067748;
    }
    if (uVar6 != 0x200) {
      return -0x16;
    }
    uVar6 = 4;
    iVar9 = 1 << (param_2 & 0xff);
    if (*(char *)(iVar8 + 0x18) == '\x01') goto LAB_0e0677f4;
LAB_0e067758:
    if (-1 < (int)(param_3 << 0xc)) goto LAB_0e06775c;
LAB_0e06780a:
    *(int *)(*(int *)(iVar8 + 4) + 4) = iVar9;
    uVar7 = param_2 & 0x1f | (uint)bVar2 << 5;
    if (*(int *)(iVar8 + 0x10) == 0) goto LAB_0e067822;
LAB_0e06777a:
    iVar8 = iVar8 + 0x10;
    iVar4 = FUN_0e0693c0(iVar8,uVar7,&local_3e);
    if ((param_3 & 0x30000) != 0) {
      local_30 = &local_3c;
      local_3c = 0;
      uStack_38 = 0;
      local_34 = (byte *)0x0;
      local_2c = (undefined4 *)0x0;
      iVar3 = FUN_0e069008(iVar8,uVar7,&local_34);
      if (iVar3 == 0xbad0000) {
        puVar5 = (undefined4 *)(param_3 & 0x20000);
        if (puVar5 == (undefined4 *)0x0) {
          local_34 = &local_3d;
          local_30 = puVar5;
          local_2c = puVar5;
          iVar3 = FUN_0e069008(iVar8,uVar7,&local_34);
        }
        else {
          local_34 = (byte *)CONCAT31(CONCAT21(CONCAT11(local_34._3_1_,local_3d),
                                               (byte)(((param_3 ^ 0x10000) << 0xf) >> 0x1f)),
                                      (char)uVar6);
          iVar3 = FUN_0e06923c(iVar8,uVar7,&local_34,0);
        }
        if (iVar3 == 0xbad0000) goto LAB_0e06779a;
      }
      iVar4 = -0x16;
      goto LAB_0e0677a6;
    }
    thunk_FUN_0e068f4c(iVar8,uVar7);
LAB_0e06779a:
    if (iVar4 == 0xbad0000) {
      FUN_0e0694a8(iVar8,local_3e);
    }
  }
  iVar4 = 0;
LAB_0e0677a6:
  if (*(char *)(*(int *)(param_1 + 4) + 0x18) == '\x01') {
    if ((int)(param_3 << 0xe) < 0) {
      *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x44) = iVar9;
    }
    FUN_0e06204c(1);
  }
  return iVar4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06796c. Types and names are inferred; NOT original source. */

uint FUN_0e06796c(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar3 + 4);
  if (*(char *)(iVar3 + 0x18) == '\x01') {
    uVar2 = FUN_0e061f9c();
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    *(undefined4 *)(*(int *)(iVar3 + 4) + 0x48) = param_2;
    *(undefined4 *)(iVar4 + 4) = param_2;
    iVar3 = *(int *)(param_1 + 4);
    cVar1 = *(char *)(iVar3 + 0x18);
  }
  else {
    *(undefined4 *)(iVar4 + 4) = param_2;
    iVar3 = *(int *)(param_1 + 4);
    cVar1 = *(char *)(iVar3 + 0x18);
  }
  if (cVar1 != '\x01') {
    return 0;
  }
  *(undefined4 *)(*(int *)(iVar3 + 4) + 0x44) = param_2;
  uVar2 = FUN_0e06204c();
  return uVar2 & (int)uVar2 >> 0x1f;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0679b0. Types and names are inferred; NOT original source. */

uint FUN_0e0679b0(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar3 + 4);
  if (*(char *)(iVar3 + 0x18) == '\x01') {
    uVar2 = FUN_0e061f9c();
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    *(undefined4 *)(*(int *)(iVar3 + 4) + 0x48) = param_2;
    *(undefined4 *)(iVar4 + 8) = param_2;
    iVar3 = *(int *)(param_1 + 4);
    cVar1 = *(char *)(iVar3 + 0x18);
  }
  else {
    *(undefined4 *)(iVar4 + 8) = param_2;
    iVar3 = *(int *)(param_1 + 4);
    cVar1 = *(char *)(iVar3 + 0x18);
  }
  if (cVar1 != '\x01') {
    return 0;
  }
  *(undefined4 *)(*(int *)(iVar3 + 4) + 0x44) = param_2;
  uVar2 = FUN_0e06204c();
  return uVar2 & (int)uVar2 >> 0x1f;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0679f4. Types and names are inferred; NOT original source. */

uint FUN_0e0679f4(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(iVar2 + 4);
  if (*(char *)(iVar2 + 0x18) == '\x01') {
    uVar1 = FUN_0e061f9c();
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    *(uint *)(*(int *)(iVar2 + 4) + 0x48) = param_2;
  }
  *(uint *)(iVar3 + 4) = param_3 & param_2;
  *(uint *)(iVar3 + 8) = param_2 & ~(param_3 & param_2);
  if (*(char *)(*(int *)(param_1 + 4) + 0x18) != '\x01') {
    return 0;
  }
  *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x44) = param_2;
  uVar1 = FUN_0e06204c();
  return uVar1 & (int)uVar1 >> 0x1f;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067a44. Types and names are inferred; NOT original source. */

uint FUN_0e067a44(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  puVar3 = *(uint **)(iVar4 + 4);
  uVar2 = *puVar3;
  if (*(char *)(iVar4 + 0x18) == '\x01') {
    uVar1 = FUN_0e061f9c();
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    *(uint *)(*(int *)(iVar4 + 4) + 0x48) = param_2;
  }
  puVar3[1] = param_2 & ~uVar2;
  puVar3[2] = uVar2 & param_2;
  if (*(char *)(*(int *)(param_1 + 4) + 0x18) != '\x01') {
    return 0;
  }
  *(uint *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x44) = param_2;
  uVar2 = FUN_0e06204c();
  return uVar2 & (int)uVar2 >> 0x1f;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067a94. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0e067a94(undefined4 param_1,uint param_2)

{
  uint local_18;
  uint local_14;
  
  if (7 < param_2) {
    param_2 = 8;
  }
  local_18 = _DAT_0fffe014 << 0x18 | ((_DAT_0fffe014 & 0xff00) >> 8) << 0x10 |
             (((_DAT_0fffe018 & 0xff) << 0x10 | _DAT_0fffe014 & 0xff0000) >> 0x10) << 8 |
             (_DAT_0fffe014 | _DAT_0fffe028 << 0x18) >> 0x18;
  local_14 = _DAT_0fffe010 << 0x18 | (_DAT_0fffe010 >> 8 & 0xff) << 0x10 |
             (_DAT_0fffe010 >> 0x10 & 0xff) << 8 | _DAT_0fffe010 >> 0x18;
  FUN_0e06f35c(param_1,&local_18,param_2);
  return param_2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067d30. Types and names are inferred; NOT original source. */

undefined4 FUN_0e067d30(int param_1,uint param_2,uint *param_3)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + 4);
  *param_3 = uVar2;
  if (uVar2 + (uint)*(byte *)(param_1 + 8) * 8 <= uVar2) {
    return 0xfffffffe;
  }
  if (*(byte *)(uVar2 + 5) == param_2) {
    return 0;
  }
  do {
    uVar3 = uVar2 + 8;
    *param_3 = uVar3;
    if (*(int *)(param_1 + 4) + (uint)*(byte *)(param_1 + 8) * 8 <= uVar3) {
      return 0xfffffffe;
    }
    pbVar1 = (byte *)(uVar2 + 0xd);
    uVar2 = uVar3;
  } while (*pbVar1 != param_2);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e067d84. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0e067d84(uint *param_1,int param_2,int param_3,uint param_4)

{
  code *pcVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint extraout_r3;
  uint uVar8;
  uint *puVar9;
  undefined *unaff_lr;
  uint *puVar10;
  
  if (param_2 == 0) {
    return 0;
  }
  puVar9 = param_1;
  do {
    puVar10 = puVar9 + 1;
    uVar8 = *puVar9;
    uVar5 = (uVar8 & 0x7fff) >> 0xb;
    uVar6 = uVar8 & 0x1ff;
    if (8 < uVar5) {
      return -0x16;
    }
    bVar2 = (&DAT_0e07052c)[uVar5];
    if (uVar6 == 0x1ff) {
      switch(uVar8 >> 0x18) {
      case 0:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x604) = 0xffffffff;
        break;
      case 1:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x60c) = 0xffffffff;
        break;
      case 2:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x610) = 0xffffffff;
        break;
      case 3:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x608) = 0xffffffff;
        break;
      default:
        goto LAB_0e067e00;
      case 0x16:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x560) = 0xffffffff;
        break;
      case 0x17:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x564) = 0xffffffff;
        break;
      case 0x18:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x568) = 0xffffffff;
        break;
      case 0x19:
        param_4 = 0xffffffff;
        *(undefined4 *)(param_3 + 0x56c) = 0xffffffff;
      }
      goto LAB_0e067ec8;
    }
    switch(uVar8 >> 0x18) {
    case 0:
      *(uint *)(param_3 + 0x604) = uVar6;
      param_4 = *puVar9 << 0xd;
      uVar5 = param_4;
      break;
    case 1:
      *(uint *)(param_3 + 0x60c) = uVar6;
      param_4 = *puVar9;
      if ((param_4 & 0x40000) != 0) goto LAB_0e067f6a;
LAB_0e067f80:
      uVar6 = 0;
      goto LAB_0e067e52;
    case 2:
      *(uint *)(param_3 + 0x610) = uVar6;
      uVar5 = *puVar9 << 0xd;
      break;
    case 3:
      *(uint *)(param_3 + 0x608) = uVar6;
      param_4 = *puVar9;
      if ((param_4 & 0x40000) == 0) goto LAB_0e067f80;
LAB_0e067f6a:
      uVar5 = 0;
      uVar3 = 0xffffffff;
      goto LAB_0e067e18;
    default:
LAB_0e067e00:
      return -0x86;
    case 0x16:
      *(uint *)(param_3 + 0x560) = uVar6;
      uVar3 = *puVar9;
      param_4 = uVar3 << 0xd;
      uVar5 = param_4;
      goto joined_r0x0e067e14;
    case 0x17:
      *(uint *)(param_3 + 0x564) = uVar6;
      uVar3 = (*puVar9 & 0x1ffff) >> 0x10;
      if (-1 < (int)(*puVar9 << 0xd)) {
        uVar5 = 1;
        goto LAB_0e067ef0;
      }
      goto LAB_0e067e16;
    case 0x18:
      *(uint *)(param_3 + 0x568) = uVar6;
      param_4 = *puVar9 << 0xd;
      uVar3 = (*puVar9 & 0x1ffff) >> 0x10;
      if ((int)param_4 < 0) goto LAB_0e067e16;
      uVar5 = 1;
      goto LAB_0e067ef0;
    case 0x19:
      *(uint *)(param_3 + 0x56c) = uVar6;
      uVar3 = *puVar9;
      uVar5 = uVar3 << 0xd;
joined_r0x0e067e14:
      uVar3 = (uVar3 & 0x1ffff) >> 0x10;
      if ((int)uVar5 < 0) {
LAB_0e067e16:
        uVar5 = 1;
        goto LAB_0e067e18;
      }
      uVar5 = 1;
      goto LAB_0e067ef0;
    }
    if ((int)uVar5 < 0) {
      uVar5 = 1;
      uVar3 = 1;
LAB_0e067e18:
      if (0x13f < uVar6) {
        param_4 = 0;
      }
      else {
        unaff_lr = &DAT_0e070504;
      }
      if (0x13f >= uVar6) {
        param_4 = *(uint *)(unaff_lr + ((uVar8 & 0x1ff) >> 5) * 4);
      }
      iVar4 = FUN_0e061f9c(3);
      if (iVar4 < 0) {
        return iVar4;
      }
      *(int *)(param_4 + 0x48) = 1 << (uVar8 & 0x1f);
      if (uVar3 != 0xffffffff) {
LAB_0e067ef0:
        uVar6 = (uVar8 & 0x1ff) >> 5;
        if (uVar3 != 0) goto LAB_0e068016;
        if (9 < uVar6) {
          _NMI = 0;
                    /* WARNING: Does not return */
          pcVar1 = (code *)software_udf(0xff,0xe0680a4);
          (*pcVar1)();
        }
        *(int *)(*(int *)(&DAT_0e070504 + uVar6 * 4) + 8) = 1 << (uVar8 & 0x1f);
        goto LAB_0e067f0c;
      }
      param_4 = *puVar9;
      uVar6 = uVar5;
LAB_0e067e52:
      uVar5 = uVar6;
      if ((param_4 & 0x8000) != 0) {
        uVar6 = 0;
        uVar5 = 1;
      }
      if (9 < (uVar8 & 0x1ff) >> 5) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe0680b8);
        (*pcVar1)();
      }
    }
    else {
      uVar5 = 1;
LAB_0e068016:
      uVar6 = (uVar8 & 0x1ff) >> 5;
      if (9 < uVar6) {
        _Reset = 0;
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe0680a0);
        (*pcVar1)();
      }
      *(int *)(*(int *)(&DAT_0e070504 + uVar6 * 4) + 4) = 1 << (uVar8 & 0x1f);
LAB_0e067f0c:
      param_4 = *puVar9;
      uVar6 = uVar5;
      if ((param_4 & 0x8000) != 0) {
        uVar5 = 1;
        uVar6 = 0;
      }
    }
    unaff_lr = &DAT_0e070504;
    iVar4 = *(int *)(&DAT_0e070504 + ((uVar8 & 0x1ff) >> 5) * 4);
    iVar7 = iVar4 + (uVar8 & 0x1f) * 4;
    *(uint *)(iVar7 + 0x80) =
         *(uint *)(iVar7 + 0x80) & 0xfffcf0f0 | (uint)bVar2 << 8 | ((param_4 & 0x7ff) >> 9) << 2 |
         uVar6 | uVar5 << 1;
    *(uint *)(iVar7 + 0x80) = *(uint *)(iVar7 + 0x80) & 0x7fffffff | (*puVar9 >> 0x11) << 0x1f;
    param_4 = *puVar9;
    if ((int)(param_4 << 0xd) < 0) {
      *(int *)(iVar4 + 0x44) = 1 << (uVar8 & 0x1f);
      unaff_lr = (undefined *)0xe067ec5;
      iVar4 = FUN_0e06204c(3);
      param_4 = extraout_r3;
      if (iVar4 < 0) {
        return iVar4;
      }
    }
LAB_0e067ec8:
    puVar9 = puVar10;
    if (puVar10 == param_1 + param_2) {
      return 0;
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0680c0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0680c0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x3c);
  param_3[1] = 0;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0680d0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e0680d0(int param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *local_1c [2];
  
  piVar6 = *(int **)(param_1 + 4);
  puVar7 = (undefined4 *)piVar6[0xe];
  iVar2 = FUN_0e067d30(puVar7,0,local_1c);
  if (-1 < iVar2) {
    FUN_0e067d84(*local_1c[0],*(undefined1 *)(local_1c[0] + 1),*puVar7);
  }
  FUN_0e06207c(piVar6[0xe],0);
  uVar5 = 0;
  uVar3 = 0;
  do {
    uVar4 = *(uint *)(*piVar6 + (uVar5 + 0x158) * 4);
    if (-1 < (int)uVar4) {
      if (0x13f < uVar4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe068168);
        (*pcVar1)();
      }
      if ((int)((**(uint **)(&DAT_0e070538 + (uVar4 >> 5) * 4) >> (uVar4 & 0x1f)) << 0x1f) < 0) {
        uVar3 = 1 << (uVar5 & 0xff) & 0xffU | uVar3;
      }
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 != 4);
  uVar5 = 0;
  do {
    *(ushort *)(*(int *)(*(int *)(param_1 + 4) + 0x28) + uVar5 * 2) =
         (ushort)((1 << (uVar5 & 0xff) & uVar3) == 0) << 0xf;
    uVar5 = uVar5 + 1;
  } while (uVar5 != 4);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068170. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e068170(int param_1,uint param_2,uint param_3,uint param_4,ushort param_5)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  ushort uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint *puVar10;
  bool bVar11;
  
  piVar9 = *(int **)(param_1 + 4);
  puVar10 = *(uint **)(param_1 + 0x10);
  if (3 < param_2) {
    return 0xffffffea;
  }
  bVar11 = *(char *)((int)piVar9 + 0x1e) == '\x01';
  uVar8 = param_4;
  if (bVar11) {
    uVar8 = param_4 >> 1;
  }
  if (bVar11) {
    param_3 = param_3 >> 1;
  }
  piVar4 = piVar9;
  if (uVar8 == 0) {
    uVar6 = 0;
    bVar11 = false;
  }
  else if (uVar8 < param_3) {
    if (param_3 != *puVar10) {
      if (((uint)(byte)puVar10[1] & ~(1 << (param_2 & 0xff))) != 0) {
        return 0xffffffea;
      }
      iVar3 = 0;
      uVar7 = param_3;
      while (0x7fff < uVar7) {
        iVar3 = iVar3 + 1;
        uVar7 = uVar7 >> 1;
        if (iVar3 == 8) {
          return 0xffffffea;
        }
      }
      *puVar10 = param_3;
      *(char *)((int)puVar10 + 5) = (char)iVar3;
      iVar5 = *piVar9;
      bVar2 = *(byte *)((int)piVar9 + 0x1e);
      *(int *)(iVar5 + 0x50c) = iVar3;
      *(uint *)(iVar5 + 0x504) = (uint)bVar2;
      *(uint *)(iVar5 + 0x508) = uVar7;
      piVar4 = *(int **)(param_1 + 4);
    }
    bVar11 = true;
    uVar6 = (ushort)(uVar8 >> *(sbyte *)((int)puVar10 + 5));
  }
  else {
    bVar11 = false;
    uVar6 = 0x7fff;
  }
  iVar3 = piVar4[10];
  *(ushort *)(iVar3 + param_2 * 2) = uVar6 | (param_5 & 1 ^ 1) << 0xf;
  if (piVar9[0x10] << 0x1f < 0) {
    FUN_0e067318(*(undefined4 *)(*(int *)(param_1 + 4) + 0x28),(short)piVar9[0xb],iVar3,
                 *(int *)(param_1 + 4),param_4);
  }
  if (bVar11) {
    *(byte *)(puVar10 + 1) = (byte)puVar10[1] | (byte)(1 << (param_2 & 0xff));
    goto LAB_0e068236;
  }
  uVar7 = *(uint *)(*piVar9 + (param_2 + 0x158) * 4);
  if (-1 < (int)uVar7) {
    if ((param_5 & 1) == 0) {
      if (uVar8 == 0) goto LAB_0e06825c;
    }
    else if (uVar8 != 0) {
LAB_0e06825c:
      if (0x13f < uVar7) {
        _NMI = 0;
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe0682d8);
        (*pcVar1)();
      }
      *(int *)(*(int *)(&DAT_0e070538 + (uVar7 >> 5) * 4) + 8) = 1 << (uVar7 & 0x1f);
      goto LAB_0e0681f6;
    }
    if (0x13f < uVar7) {
      _Reset = 0;
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe0682d2);
      (*pcVar1)();
    }
    *(int *)(*(int *)(&DAT_0e070538 + (uVar7 >> 5) * 4) + 4) = 1 << (uVar7 & 0x1f);
  }
LAB_0e0681f6:
  uVar8 = (uint)(byte)puVar10[1] & ~(1 << (param_2 & 0xff));
  *(char *)(puVar10 + 1) = (char)uVar8;
  if (uVar8 == 0) {
    FUN_0e069c78(piVar9);
    *(undefined1 *)((int)puVar10 + 6) = 1;
    return 0;
  }
LAB_0e068236:
  if (*(char *)((int)puVar10 + 6) != '\0') {
    *(undefined1 *)((int)puVar10 + 6) = 0;
    do {
      iVar3 = FUN_0e069d20(piVar9);
    } while (iVar3 == 0);
  }
  FUN_0e069ba8(piVar9,piVar9 + 10,1,0x10);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0682e0. Types and names are inferred; NOT original source. */

uint FUN_0e0682e0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_0e0612f0(0x1b4,1,0);
  iVar1 = FUN_0e069b50(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + 8,&DAT_0e0680bd,
                       *(undefined4 *)(param_1 + 0x10));
  if (iVar1 == 0xbad0000) {
    uVar2 = FUN_0e0680d0(param_1);
    return uVar2 & (int)uVar2 >> 0x1f;
  }
  return 0xfffffff0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068320. Types and names are inferred; NOT original source. */

uint FUN_0e068320(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_0e0612f0(0x1c4,1,0);
  iVar1 = FUN_0e069b50(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + 8,&DAT_0e0680bd,
                       *(undefined4 *)(param_1 + 0x10));
  if (iVar1 == 0xbad0000) {
    uVar2 = FUN_0e0680d0(param_1);
    return uVar2 & (int)uVar2 >> 0x1f;
  }
  return 0xfffffff0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068360. Types and names are inferred; NOT original source. */

uint FUN_0e068360(int param_1)

{
  int iVar1;
  uint uVar2;
  
  FUN_0e0612f0(0x1a4,1,0);
  iVar1 = FUN_0e069b50(*(int *)(param_1 + 4),*(int *)(param_1 + 4) + 8,&DAT_0e0680bd,
                       *(undefined4 *)(param_1 + 0x10));
  if (iVar1 == 0xbad0000) {
    uVar2 = FUN_0e0680d0(param_1);
    return uVar2 & (int)uVar2 >> 0x1f;
  }
  return 0xfffffff0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0683a0. Types and names are inferred; NOT original source. */

void FUN_0e0683a0(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint local_18;
  uint uStack_14;
  
  FUN_0e069644(&local_18);
  if (param_4 < uStack_14 || uStack_14 - param_4 < (uint)(param_3 <= local_18)) {
    iVar1 = param_3 - DAT_23002840;
    DAT_23002840 = param_3;
    DAT_23002844 = param_4;
    FUN_0e06e7fc(iVar1);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06841c. Types and names are inferred; NOT original source. */

uint FUN_0e06841c(void)

{
  int iVar1;
  uint uVar2;
  byte local_9;
  
  if ((DAT_230071eb < 3) && (iVar1 = FUN_0e069690(&local_9), iVar1 == 0xbad0000)) {
    uVar2 = (uint)local_9;
    DAT_230071eb = DAT_230071eb + 1;
  }
  else {
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068454. Types and names are inferred; NOT original source. */

undefined4
FUN_0e068454(byte param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_2c;
  undefined4 local_28;
  byte local_24;
  
  uVar1 = DAT_23006db0;
  uVar4 = 1 << (uint)param_1;
  DAT_23006db0 = DAT_23006db0 & ~uVar4;
  FUN_0e069808(param_1);
  local_2c = param_5;
  local_28 = param_6;
  local_24 = param_1;
  iVar2 = FUN_0e069760(&local_2c,extraout_r1,param_3,param_4,1);
  uVar3 = 0;
  if (iVar2 != 0xbad0000) {
    uVar3 = 0xffffffff;
  }
  if ((uVar4 & uVar1) != 0) {
    DAT_23006db0 = DAT_23006db0 | uVar4;
    FUN_0e069850(param_1);
    return uVar3;
  }
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0684dc. Types and names are inferred; NOT original source. */

undefined8 FUN_0e0684dc(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  uint local_20;
  int iStack_1c;
  
  FUN_0e069644(&local_20);
  uVar3 = FUN_0e06e928();
  iVar1 = (-1 - param_2) - (uint)(0xfffffffe < param_1);
  if (iVar1 < 0) {
    if (param_2 < 0x100000) {
      return CONCAT44(iStack_1c + param_2 + (uint)CARRY4(param_1,local_20),param_1 + local_20);
    }
  }
  else {
    uVar2 = (-param_1 - 2) - (uint)uVar3;
    iVar1 = (iVar1 - (int)((ulonglong)uVar3 >> 0x20)) - (uint)(-param_1 - 2 < (uint)uVar3);
    if (iVar1 < 0x100000) {
      return CONCAT44(iVar1 + iStack_1c + (uint)CARRY4(uVar2,local_20),uVar2 + local_20);
    }
  }
  return 0xffffffffffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068540. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068540(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_10 [2];
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e069644(local_10);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return local_10[0];
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068568. Types and names are inferred; NOT original source. */

int FUN_0e068568(void)

{
  int local_10 [3];
  
  FUN_0e069644(local_10);
  return local_10[0] - DAT_23002840;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068584. Types and names are inferred; NOT original source. */

void FUN_0e068584(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint local_18;
  int local_14;
  
  if (param_1 == 0xffffffff) {
    param_1 = 0x7fffffff;
  }
  else {
    param_1 = param_1 & ~((int)param_1 >> 0x1f);
  }
  FUN_0e069644(&local_18);
  uVar1 = (local_18 - DAT_23002840) + param_1;
  iVar2 = ((local_14 - DAT_23002844) - (uint)(local_18 < DAT_23002840)) +
          ((int)param_1 >> 0x1f) + (uint)CARRY4(local_18 - DAT_23002840,param_1);
  if (uVar1 == 0 && iVar2 == 0) {
    uVar1 = 1;
    iVar2 = 0;
  }
  FUN_0e069760(&DAT_23000958,1,uVar1 + DAT_23002840,
               DAT_23002844 + iVar2 + (uint)CARRY4(uVar1,DAT_23002840),1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0685dc. Types and names are inferred; NOT original source. */

void FUN_0e0685dc(void)

{
  undefined4 local_18;
  undefined4 uStack_14;
  
  do {
    FUN_0e06cc94(&DAT_23006dc8,&local_18,0xffffffff,0xffffffff);
    (*DAT_23006e00)(local_18,uStack_14);
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068608. Types and names are inferred; NOT original source. */

int FUN_0e068608(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  
  DAT_23006e00 = param_1;
  iVar1 = FUN_0e06d0b4(&DAT_23006db8,8);
  if (-1 < iVar1) {
    DAT_23006db4 = 0xff000000;
    FUN_0e06cbb8(&DAT_23006dc8,&DAT_23006df0,8,2);
    puVar4 = &DAT_23011d00;
    puVar2 = &DAT_23002848;
    do {
      puVar3 = puVar2 + 0x90;
      FUN_0e06d8f8(puVar2,puVar4,0x400,0xe0685dd,0,0,0,2,0);
      puVar4 = puVar4 + 0x400;
      puVar2 = puVar3;
    } while (puVar3 != &DAT_230029f8);
    iVar1 = 0;
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0686a4. Types and names are inferred; NOT original source. */

void FUN_0e0686a4(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_10 = param_1;
  uStack_c = param_2;
  FUN_0e06cbdc(&DAT_23006dc8,&local_10,0xffffffff,0xffffffff);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0686c8. Types and names are inferred; NOT original source. */

void FUN_0e0686c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0e06e0c4();
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  FUN_0e06d0d0(param_1);
  FUN_0e06e0ec();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0686e8. Types and names are inferred; NOT original source. */

void FUN_0e0686e8(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_0e06d118(param_1,param_2,0xffffffff,0xffffffff);
  FUN_0e06e0c4();
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  *param_3 = *(undefined4 *)(param_1 + 0x14);
  FUN_0e06e0ec();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068710. Types and names are inferred; NOT original source. */

void FUN_0e068710(undefined4 param_1,undefined4 param_2)

{
  FUN_0e06d118(&DAT_23006db8,param_2,0xffffffff,0xffffffff);
  DAT_23006db4 = DAT_23006db4 & ~(0x80000000U >> LZCOUNT(DAT_23006db4));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068754. Types and names are inferred; NOT original source. */

void FUN_0e068754(uint param_1)

{
  DAT_23006db4 = DAT_23006db4 | 0x80000000U >> (param_1 & 0xff);
  FUN_0e06d0d0(&DAT_23006db8);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0687b0. Types and names are inferred; NOT original source. */

int FUN_0e0687b0(int param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  
  if ((*(char *)(*(int *)(param_1 + 4) + 0x48) != '\0') &&
     (iVar2 = FUN_0e06edf4(*param_2), iVar2 != 0)) {
    return iVar2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  InstructionSynchronizationBarrier(0xf);
  software_interrupt(2);
  *param_2 = 0;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0687dc. Types and names are inferred; NOT original source. */

int FUN_0e0687dc(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  cVar1 = *(char *)(iVar3 + 0x48);
  if (cVar1 == '\x01') {
    iVar2 = FUN_0e06eddc(iVar3 + 0x28,1,0,*(undefined4 *)(iVar3 + 0x3c),
                         *(undefined4 *)(iVar3 + 0x38),*(undefined4 *)(iVar3 + 0x3c));
    if (iVar2 == 0) {
      return -0x20;
    }
    *(undefined1 *)(iVar3 + 0x48) = 2;
  }
  else {
    if (cVar1 == '\x03') {
      return -0x20;
    }
    if (cVar1 == '\0') {
      return -0xe;
    }
  }
  iVar3 = FUN_0e05edcc(iVar3 + 0x20,param_2,param_3);
  FUN_0e06ede4(param_2);
  if (iVar3 != -0x16) {
    if (iVar3 < -0x15) {
      if (iVar3 == -0x78) {
        return -0x72;
      }
      if (iVar3 == -0x4d) {
        return -0x4d;
      }
    }
    else if (iVar3 == -5) {
      return -5;
    }
    if (iVar3 < 0) {
      iVar3 = -5;
    }
    else {
      iVar3 = 0;
    }
  }
  return iVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068874. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068874(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  if (*(char *)(puVar3 + 0x12) == '\0') {
    if (param_2 == 0) {
      return 0xffffffea;
    }
    iVar1 = FUN_0e05ed80(*puVar3);
    if ((iVar1 == 0) || (iVar1 == -0x78)) {
      puVar3[4] = &DAT_0e0687a5;
      puVar3[0x10] = param_2;
      puVar3[5] = &LAB_0e068778_1;
      puVar3[6] = &DAT_0e068791;
      puVar3[0x11] = param_3;
      puVar3[7] = param_1;
      FUN_0e06edb4(puVar3 + 10);
      iVar1 = FUN_0e05ed9c(*puVar3,puVar3 + 8,puVar3 + 2);
      if (iVar1 == 0) {
        uVar5 = FUN_0e06e9a0();
        lVar6 = FUN_0e05ba10((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0,param_4);
        uVar2 = (uint)(lVar6 + 500);
        iVar1 = (int)((ulonglong)(lVar6 + 500) >> 0x20);
        if ((iVar1 + ((((iVar1 * 0x20 | uVar2 >> 0x1b) - iVar1) - (uint)(uVar2 * 0x20 < uVar2)) * 4
                     | uVar2 * 0x1f >> 0x1e) + (uint)CARRY4(uVar2 * 0x7c,uVar2) & 0x1fffffff) == 0
            && (uVar2 * 0x7d >> 0x1d == 0 && uVar2 * 1000 == 0)) {
          iVar4 = -2;
          iVar1 = -1;
        }
        else {
          uVar5 = FUN_0e06e9a0();
          lVar6 = FUN_0e05ba10((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),1000,0);
          uVar2 = (uint)(lVar6 + 500);
          iVar1 = (int)((ulonglong)(lVar6 + 500) >> 0x20);
          iVar4 = uVar2 * -1000 + -2;
          iVar1 = (-1 - ((iVar1 + ((((iVar1 * 0x20 | uVar2 >> 0x1b) - iVar1) -
                                   (uint)(uVar2 * 0x20 < uVar2)) * 4 | uVar2 * 0x1f >> 0x1e) +
                                  (uint)CARRY4(uVar2 * 0x7c,uVar2)) * 8 | uVar2 * 0x7d >> 0x1d)) -
                  (uint)(0xfffffffe < uVar2 * 1000);
        }
        puVar3[0xe] = iVar4;
        puVar3[0xf] = iVar1;
        *(undefined1 *)(puVar3 + 0x12) = 1;
        return 0;
      }
      *(undefined1 *)(puVar3 + 0x12) = 3;
      if (iVar1 == -0x16) {
        return 0xffffffea;
      }
      if (iVar1 < -0x15) {
        if (iVar1 == -0x78) {
          return 0xffffff8e;
        }
        if (iVar1 != -0x4d) {
          return 0xfffffffb;
        }
        return 0xffffffb3;
      }
      if (iVar1 == -5) {
        return 0xfffffffb;
      }
    }
    else {
      *(undefined1 *)(puVar3 + 0x12) = 3;
      if (iVar1 == -0x16) {
        return 0xffffffea;
      }
      if (iVar1 == -5) {
        return 0xfffffffb;
      }
      if (iVar1 == -0x4d) {
        return 0xffffffb3;
      }
    }
    if (iVar1 < 0) {
      return 0xfffffffb;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068a44. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e068a44(void)

{
  _DAT_e000ed8c = _DAT_e000ed8c | 0xc00;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068a5c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068a5c(uint *param_1,undefined1 *param_2)

{
  uint uVar1;
  
  do {
    uVar1 = *param_1;
    if (uVar1 == 0) {
      return 0xbad0002;
    }
  } while (*param_1 != uVar1);
  *param_1 = uVar1 & ~(1 << (0x1fU - LZCOUNT(uVar1) & 0xff));
  *param_2 = (char)(0x1fU - LZCOUNT(uVar1));
  return 0xbad0000;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068a9c. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e068ae6) */

undefined4 FUN_0e068a9c(uint *param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = *param_1;
  if (-1 < (int)((uVar3 >> (param_2 & 0xff)) << 0x1f)) {
    uVar2 = 1 << (param_2 & 0xff);
    bVar1 = false;
    if (*param_1 == uVar3) {
      *param_1 = uVar3 | uVar2;
      bVar1 = true;
    }
    while (!bVar1) {
      bVar1 = false;
      if (*param_1 == *param_1) {
        *param_1 = uVar2 | *param_1;
        bVar1 = true;
      }
    }
    return 0xbad0000;
  }
  return 0xbad0004;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068af0. Types and names are inferred; NOT original source. */

void FUN_0e068af0(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  
  uVar1 = (uint)*(ushort *)
                 (param_1 +
                 (((uint)(byte)(&DAT_0e070704)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8) * 2);
  if ((int)(uVar1 << 0x17) < 0) {
    uVar1 = (uVar1 & 0x1fff) >> 9;
    (**(code **)(param_1 + uVar1 * 8))(param_2,param_3,*(undefined4 *)(param_1 + uVar1 * 8 + 4));
  }
  if (*(code **)(param_1 + 8) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e068b34. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_1 + 8))(param_2,param_3,*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068b40. Types and names are inferred; NOT original source. */

void FUN_0e068b40(int param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  
  iVar3 = (uint)*(byte *)(param_1 + 4) * 0x52 +
          ((uint)(byte)(&DAT_0e070704)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8;
  uVar1 = *(ushort *)(&DAT_23000968 + iVar3 * 2);
  if ((int)((uint)uVar1 << 0x17) < 0) {
    uVar2 = (uVar1 & 0x1fff) >> 9;
    *(ushort *)(&DAT_23000968 + iVar3 * 2) = uVar1 & 0xe0ff;
    iVar3 = (uint)*(byte *)(param_1 + 4) * 0xa4;
    puVar4 = (ushort *)(iVar3 + 0x23000976);
    while( true ) {
      puVar4 = puVar4 + 1;
      if (((int)((uint)*puVar4 << 0x17) < 0) && (uVar2 == (*puVar4 & 0x1fff) >> 9)) break;
      if (puVar4 == (ushort *)(iVar3 + 0x230009f6)) {
        *(undefined4 *)(&DAT_23000968 + (uint)*(byte *)(param_1 + 4) * 0xa4 + uVar2 * 8) = 0;
        FUN_0e068a9c(&DAT_23000a00 + (uint)*(byte *)(param_1 + 4) * 0xa4);
        return;
      }
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068bc8. Types and names are inferred; NOT original source. */

byte FUN_0e068bc8(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int *piVar6;
  undefined4 local_34;
  int local_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 *local_20;
  undefined4 uStack_1c;
  byte *pbVar5;
  
  piVar6 = &local_30;
  local_34 = param_2;
  pbVar5 = &DAT_0e070714;
  do {
    pbVar4 = pbVar5 + 1;
    bVar1 = *(byte *)((int)&local_34 + (uint)(*pbVar5 >> 3)) >> (*pbVar5 & 7);
    if ((bVar1 & 1) != 0) {
      local_30 = 0x5f938000;
      puStack_2c = &SUB_5f938200;
      uStack_28 = 0x5f938400;
      uStack_24 = 0x5f938c00;
      local_20 = &SUB_5f938e00;
      uStack_1c = 0x5f939200;
      iVar2 = *piVar6;
      iVar3 = *(int *)(iVar2 + 0x20);
      *param_1 = iVar3;
      *(int *)(iVar2 + 0x20) = iVar3;
      if (iVar3 != 0) {
        return bVar1 & 1;
      }
    }
    piVar6 = piVar6 + 1;
    param_1 = param_1 + 1;
    pbVar5 = pbVar4;
  } while (pbVar4 != &DAT_0e07071a);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068ec4. Types and names are inferred; NOT original source. */

void FUN_0e068ec4(int *param_1,uint param_2)

{
  code *pcVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_2 >> 5;
  uVar2 = *(ushort *)
           (&DAT_23000968 +
           ((uint)*(byte *)(param_1 + 1) * 0x52 +
            ((uint)(byte)(&DAT_0e070704)[uVar4] + (param_2 & 0x1f) & 0xff) + 8) * 2);
  if (((int)((uint)uVar2 << 0x1a) < 0) && (-1 < (int)((uint)uVar2 << 0x1e))) {
    *(int *)(*param_1 + 0x358) = 1 << (uint)(uVar2 >> 0xd);
    iVar3 = *param_1 + (uint)(uVar2 >> 0xd) * 4;
    *(uint *)(iVar3 + 0x510) = *(uint *)(iVar3 + 0x510) & 0xfffffffc;
    return;
  }
  if (uVar4 < 10) {
    iVar3 = *(int *)(&DAT_0e0706dc + uVar4 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcffff;
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe068f3e);
  (*pcVar1)();
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e068f4c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e068f4c(int param_1,uint param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_2 >> 5;
  uVar4 = (uint)(byte)(&DAT_0e070704)[uVar5] + (param_2 & 0x1f) & 0xff;
  if (-1 < (int)((uint)*(ushort *)
                        (&DAT_23000968 + ((uint)*(byte *)(param_1 + 4) * 0x52 + uVar4 + 8) * 2) <<
                0x1f)) {
    return 0xbad0004;
  }
  piVar2 = (int *)FUN_0e068ec4();
  if ((int)((uint)*(ushort *)(&DAT_23000968 + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2)
           << 0x1a) < 0) {
    iVar3 = *piVar2 + (uint)(*(ushort *)
                              (&DAT_23000968 + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2)
                            >> 0xd) * 4;
    *(undefined4 *)(iVar3 + 0x510) = 0;
    *(undefined4 *)(iVar3 + 0x510) = 0;
  }
  FUN_0e068b40(piVar2,param_2);
  *(undefined2 *)(&DAT_23000968 + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2) = 0;
  if (uVar5 < 10) {
    iVar3 = *(int *)(&DAT_0e0706dc + uVar5 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcf0f0 | 2;
    return 0xbad0000;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe068fec);
  (*pcVar1)();
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069008. Types and names are inferred; NOT original source. */

int FUN_0e069008(int *param_1,uint param_2,undefined4 *param_3)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  byte *pbVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  byte local_19;
  
  uVar4 = param_2 >> 5;
  uVar11 = (uint)(byte)(&DAT_0e070704)[uVar4] + (param_2 & 0x1f) & 0xff;
  if ((byte *)*param_3 != (byte *)0x0) {
    if ((*(ushort *)(&DAT_23000968 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8) * 2) & 0x22)
        == 0x22) {
      return 0xbad0004;
    }
    if (9 < uVar4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe069224);
      (*pcVar1)();
    }
    iVar5 = *(int *)(&DAT_0e0706dc + uVar4 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar5 + 0x80) = *(uint *)(iVar5 + 0x80) & 0xfffffff0 | (uint)*(byte *)*param_3 << 2;
    iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
    *(ushort *)(&DAT_23000968 + iVar5 * 2) = *(ushort *)(&DAT_23000968 + iVar5 * 2) & 0xfffd;
    iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
    *(ushort *)(&DAT_23000968 + iVar5 * 2) = *(ushort *)(&DAT_23000968 + iVar5 * 2) | 1;
  }
  pbVar9 = (byte *)param_3[1];
  if (pbVar9 == (byte *)0x0) goto LAB_0e0690e0;
  uVar4 = (uint)*(byte *)(param_1 + 1);
  iVar13 = uVar4 * 0x52 + uVar11 + 8;
  bVar2 = *pbVar9;
  uVar12 = (uint)bVar2;
  iVar5 = *(int *)(pbVar9 + 4);
  uVar8 = *(ushort *)(&DAT_23000968 + iVar13 * 2);
  if ((uVar8 & 2) == 0) {
    *(ushort *)(&DAT_23000968 + iVar13 * 2) = uVar8 & 0x1fdf;
    if (iVar5 != 0) {
      if (3 < uVar12) {
        return 0xbad0004;
      }
      bVar3 = **(byte **)(param_3[1] + 4);
      iVar5 = *param_1 + (uint)bVar3 * 4;
      if (uVar12 == 0) {
        *(undefined4 *)(iVar5 + 0x510) = 0;
        *(undefined4 *)(iVar5 + 0x510) = 0;
        uVar4 = (uint)*(byte *)(param_1 + 1);
        uVar8 = *(ushort *)(&DAT_23000968 + (uVar4 * 0x52 + uVar11 + 8) * 2);
        goto LAB_0e0690ba;
      }
      *(uint *)(iVar5 + 0x510) = *(uint *)(iVar5 + 0x510) & 0xfffffffc;
      iVar5 = *param_1 + (uint)bVar3 * 4;
      *(uint *)(iVar5 + 0x510) = *(uint *)(iVar5 + 0x510) & 0xfffce00f;
      *(uint *)(iVar5 + 0x510) = (param_2 & 0x1ff) << 4 | uVar12 << 0x10 | *(uint *)(iVar5 + 0x510);
      iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
      *(ushort *)(&DAT_23000968 + iVar5 * 2) =
           *(ushort *)(&DAT_23000968 + iVar5 * 2) | (ushort)bVar3 << 0xd | 0x20;
    }
    uVar4 = (uint)*(byte *)(param_1 + 1);
    uVar8 = *(ushort *)(&DAT_23000968 + (uVar4 * 0x52 + uVar11 + 8) * 2);
  }
  else if (iVar5 != 0) {
    return 0xbad0004;
  }
LAB_0e0690ba:
  *(ushort *)(&DAT_23000968 + (uVar4 * 0x52 + uVar11 + 8) * 2) = uVar8 & 0xffe3;
  iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
  *(ushort *)(&DAT_23000968 + iVar5 * 2) =
       *(ushort *)(&DAT_23000968 + iVar5 * 2) | (ushort)bVar2 << 2;
LAB_0e0690e0:
  piVar10 = (int *)param_3[2];
  if (piVar10 != (int *)0x0) {
    iVar13 = *piVar10;
    iVar5 = piVar10[1];
    FUN_0e068b40(param_1);
    if (iVar13 != 0) {
      uVar4 = (uint)*(byte *)(param_1 + 1);
      if ((iVar13 == *(int *)(&DAT_23000968 + uVar4 * 0xa4)) &&
         (iVar5 == *(int *)(&DAT_2300096c + uVar4 * 0xa4))) {
        uVar7 = 0;
        uVar12 = uVar7;
      }
      else {
        iVar6 = FUN_0e068a5c(&DAT_23000a00 + uVar4 * 0xa4,&local_19);
        if (iVar6 != 0xbad0000) {
          return iVar6;
        }
        uVar4 = (uint)*(byte *)(param_1 + 1);
        uVar7 = (local_19 & 0x7f) << 9;
        uVar12 = (uint)local_19;
      }
      *(int *)(&DAT_23000968 + uVar4 * 0xa4 + uVar12 * 8) = iVar13;
      *(int *)(&DAT_2300096c + (uint)*(byte *)(param_1 + 1) * 0xa4 + uVar12 * 8) = iVar5;
      iVar5 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar11 + 8;
      *(ushort *)(&DAT_23000968 + iVar5 * 2) =
           (ushort)uVar7 | *(ushort *)(&DAT_23000968 + iVar5 * 2) | 0x100;
    }
  }
  return 0xbad0000;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06923c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06923c(int *param_1,uint param_2,byte *param_3,byte *param_4)

{
  code *pcVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  
  uVar6 = param_2 >> 5;
  uVar8 = (uint)(byte)(&DAT_0e070704)[uVar6] + (param_2 & 0x1f) & 0xff;
  if (param_3 != (byte *)0x0) {
    uVar5 = *(ushort *)(&DAT_23000968 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8) * 2);
    if (((uVar5 & 2) == 0) && ((uVar5 & 0x20) != 0)) {
      return 0xbad0004;
    }
    if (((uVar5 & 0x1c) != 0) && (param_3[1] == 1)) {
      return 0xbad0004;
    }
    if (9 < uVar6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)software_udf(0xff,0xe069382);
      (*pcVar1)();
    }
    iVar7 = *(int *)(&DAT_0e0706dc + uVar6 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar7 + 0x80) =
         (uint)param_3[2] << 2 | (uint)param_3[1] << 1 | *(uint *)(iVar7 + 0x80) & 0xfffff0f0 |
         (uint)*param_3 << 8 | 1;
    iVar7 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8;
    *(ushort *)(&DAT_23000968 + iVar7 * 2) = *(ushort *)(&DAT_23000968 + iVar7 * 2) | 3;
  }
  if (param_4 != (byte *)0x0) {
    if (-1 < (int)((uint)*(ushort *)
                          (&DAT_23000968 + ((uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8) * 2) <<
                  0x1e)) {
      return 0xbad0004;
    }
    bVar2 = *param_4;
    iVar7 = *param_1 + (uint)bVar2 * 4;
    *(undefined4 *)(iVar7 + 0x510) = 0;
    *(undefined4 *)(iVar7 + 0x510) = 0;
    iVar7 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8;
    *(ushort *)(&DAT_23000968 + iVar7 * 2) = *(ushort *)(&DAT_23000968 + iVar7 * 2) & 0x1fdf;
    bVar3 = param_4[1];
    if (bVar3 != 0) {
      bVar4 = param_4[2];
      iVar7 = *param_1 + (uint)bVar2 * 4;
      *(uint *)(iVar7 + 0x510) = *(uint *)(iVar7 + 0x510) & 0xffece00f;
      *(uint *)(iVar7 + 0x510) =
           (param_2 & 0x1ff) << 4 | (bVar3 & 3) << 0x10 | (bVar4 & 1) << 0x14 |
           *(uint *)(iVar7 + 0x510);
      iVar7 = (uint)*(byte *)(param_1 + 1) * 0x52 + uVar8 + 8;
      *(ushort *)(&DAT_23000968 + iVar7 * 2) =
           *(ushort *)(&DAT_23000968 + iVar7 * 2) | (ushort)bVar2 << 0xd | 0x20;
    }
  }
  return 0xbad0000;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06939c. Types and names are inferred; NOT original source. */

void FUN_0e06939c(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(&DAT_23000970 + (uint)*(byte *)(param_1 + 4) * 0xa4) = param_2;
  *(undefined4 *)(&DAT_23000974 + (uint)*(byte *)(param_1 + 4) * 0xa4) = param_3;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0693c0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e0693c0(int param_1,uint param_2,byte *param_3)

{
  undefined4 uVar1;
  
  if ((int)((uint)*(ushort *)
                   (&DAT_23000968 +
                   ((uint)*(byte *)(param_1 + 4) * 0x52 +
                    ((uint)(byte)(&DAT_0e070704)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8) * 2)
           << 0x1a) < 0) {
    uVar1 = 0xbad0000;
    *param_3 = (byte)(*(ushort *)
                       (&DAT_23000968 +
                       ((uint)*(byte *)(param_1 + 4) * 0x52 +
                        ((uint)(byte)(&DAT_0e070704)[param_2 >> 5] + (param_2 & 0x1f) & 0xff) + 8) *
                       2) >> 0xd);
  }
  else {
    uVar1 = 0xbad0004;
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069404. Types and names are inferred; NOT original source. */

undefined4 FUN_0e069404(int *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  bVar1 = *(byte *)(param_1 + 1);
  iVar3 = (uint)bVar1 * 0xa4;
  if ((&DAT_23000a08)[iVar3] == '\0') {
    FUN_0e06f3aa(&DAT_23000978 + iVar3,0,0x80);
    uVar4 = *(uint *)(&DAT_230009f8 + iVar3);
    iVar3 = *param_1;
    if (uVar4 != 0) {
      uVar2 = 0;
      do {
        if ((uVar2 & 0xff) == 0x15) {
          *(undefined4 *)(iVar3 + (uVar2 & 0xff) * 4 + 0x100) = 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar4 != uVar2);
    }
    *(undefined4 *)(iVar3 + 0x154) = 0;
    FUN_0e0612ac(0x69);
    iVar3 = (uint)bVar1 * 0xa4;
    (&DAT_23000a08)[iVar3] = 1;
    *(undefined4 *)(&DAT_23000a00 + iVar3) = 1;
    return 0xbad0000;
  }
  return 0xbad000c;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069488. Types and names are inferred; NOT original source. */

bool FUN_0e069488(int param_1)

{
  return (&DAT_23000a08)[(uint)*(byte *)(param_1 + 4) * 0xa4] != '\0';
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0694a4. Types and names are inferred; NOT original source. */

undefined4 thunk_FUN_0e068f4c(int param_1,uint param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_2 >> 5;
  uVar4 = (uint)(byte)(&DAT_0e070704)[uVar5] + (param_2 & 0x1f) & 0xff;
  if (-1 < (int)((uint)*(ushort *)
                        (&DAT_23000968 + ((uint)*(byte *)(param_1 + 4) * 0x52 + uVar4 + 8) * 2) <<
                0x1f)) {
    return 0xbad0004;
  }
  piVar2 = (int *)FUN_0e068ec4();
  if ((int)((uint)*(ushort *)(&DAT_23000968 + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2)
           << 0x1a) < 0) {
    iVar3 = *piVar2 + (uint)(*(ushort *)
                              (&DAT_23000968 + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2)
                            >> 0xd) * 4;
    *(undefined4 *)(iVar3 + 0x510) = 0;
    *(undefined4 *)(iVar3 + 0x510) = 0;
  }
  FUN_0e068b40(piVar2,param_2);
  *(undefined2 *)(&DAT_23000968 + ((uint)*(byte *)(piVar2 + 1) * 0x52 + uVar4 + 8) * 2) = 0;
  if (uVar5 < 10) {
    iVar3 = *(int *)(&DAT_0e0706dc + uVar5 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcf0f0 | 2;
    return 0xbad0000;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe068fec);
  (*pcVar1)();
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0694a8. Types and names are inferred; NOT original source. */

void FUN_0e0694a8(int param_1)

{
  FUN_0e068a9c((short)(ushort)*(byte *)(param_1 + 4) * 0xa4 + 0x230009fc);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0694c0. Types and names are inferred; NOT original source. */

void FUN_0e0694c0(int param_1)

{
  FUN_0e068a5c((short)(ushort)*(byte *)(param_1 + 4) * 0xa4 + 0x230009fc);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0694d8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e0694d8(int *param_1,uint param_2,int param_3)

{
  code *pcVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = param_2 >> 5;
  param_2 = param_2 & 0x1f;
  if (-1 < *(int *)(*param_1 + 0x354) << 10) {
    *(undefined4 *)(*param_1 + 0x354) = 0x200000;
  }
  uVar2 = *(ushort *)
           (&DAT_23000968 +
           ((uint)*(byte *)(param_1 + 1) * 0x52 + ((byte)(&DAT_0e070704)[uVar6] + param_2 & 0xff) +
           8) * 2);
  uVar4 = (uint)uVar2;
  if (((int)(uVar4 << 0x1a) < 0) && ((uVar2 & 2) == 0)) {
    iVar5 = (uint)(uVar2 >> 0xd) * 4;
    *(uint *)(*param_1 + iVar5 + 0x100) = uVar4 & 2;
    iVar5 = *param_1 + iVar5;
    *(uint *)(iVar5 + 0x510) = *(uint *)(iVar5 + 0x510) | 1;
    if (param_3 != 0) {
      *(int *)(*param_1 + 0x354) = 1 << (uint)(uVar2 >> 0xd);
    }
    return;
  }
  uVar4 = (uVar4 & 0x1f) >> 2;
  if (uVar4 == 4) {
    iVar5 = 3;
  }
  else {
    if (uVar4 != 5) {
      if (9 < uVar6) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)software_udf(0xff,0xe06959a);
        (*pcVar1)();
      }
      iVar3 = *(int *)(&DAT_0e0706dc + uVar6 * 4);
      iVar5 = (*(uint *)(iVar3 + 0xc) >> param_2 & 1) + 2;
      goto LAB_0e06957c;
    }
    iVar5 = 2;
  }
  if (9 < uVar6) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)software_udf(0xff,0xe0695a4);
    (*pcVar1)();
  }
  iVar3 = *(int *)(&DAT_0e0706dc + uVar6 * 4);
LAB_0e06957c:
  iVar3 = iVar3 + param_2 * 4;
  *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcffff | iVar5 << 0x10;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0695b4. Types and names are inferred; NOT original source. */

void thunk_FUN_0e068ec4(int *param_1,uint param_2)

{
  code *pcVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = param_2 >> 5;
  uVar2 = *(ushort *)
           (&DAT_23000968 +
           ((uint)*(byte *)(param_1 + 1) * 0x52 +
            ((uint)(byte)(&DAT_0e070704)[uVar4] + (param_2 & 0x1f) & 0xff) + 8) * 2);
  if (((int)((uint)uVar2 << 0x1a) < 0) && (-1 < (int)((uint)uVar2 << 0x1e))) {
    *(int *)(*param_1 + 0x358) = 1 << (uint)(uVar2 >> 0xd);
    iVar3 = *param_1 + (uint)(uVar2 >> 0xd) * 4;
    *(uint *)(iVar3 + 0x510) = *(uint *)(iVar3 + 0x510) & 0xfffffffc;
    return;
  }
  if (uVar4 < 10) {
    iVar3 = *(int *)(&DAT_0e0706dc + uVar4 * 4) + (param_2 & 0x1f) * 4;
    *(uint *)(iVar3 + 0x80) = *(uint *)(iVar3 + 0x80) & 0xfffcffff;
    return;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)software_udf(0xff,0xe068f3e);
  (*pcVar1)();
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e0695c8. Types and names are inferred; NOT original source. */

void FUN_0e0695c8(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (uint)*(byte *)(param_1 + 2);
  if (uVar5 == 7) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    if (uVar5 != 0xd) {
      uVar3 = 0xd;
      uVar2 = 0xe000;
      do {
        uVar2 = uVar2 & ~(1 << uVar3);
        bVar1 = (byte)(uVar2 >> 8);
        uVar3 = LZCOUNT((uint)(byte)(((bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7) <<
                        0x10);
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar5 != uVar3);
    }
  }
  *(undefined4 *)(uVar5 * 0x10 + 0x5f99c52c) = 0;
  (&DAT_23000abc)[uVar4 * 3] = *param_1;
  (&DAT_23000ac0)[uVar4 * 3] = param_1[1];
  bVar1 = *(byte *)(param_1 + 2);
  (&DAT_23000ac4)[uVar4 * 0xc] = bVar1;
  DAT_23000ab8 = DAT_23000ab8 | 1 << (uint)bVar1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069644. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e069644(undefined4 *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  *param_1 = 0;
  param_1[1] = 0;
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  do {
  } while (0x3fffffff < _DAT_5f99c774);
  uVar2 = _DAT_5f99c774 & 0xfffff;
  *param_1 = _DAT_5f99c770;
  param_1[1] = uVar2;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0xbad0000;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069690. Types and names are inferred; NOT original source. */

void FUN_0e069690(undefined4 param_1)

{
  FUN_0e068a5c(&DAT_23000ab4,param_1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06969c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06969c(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  undefined1 *puVar6;
  byte bVar7;
  
  if (DAT_23000ab0 != '\0') {
    return 0xbad000c;
  }
  iVar3 = 0x10;
  uVar2 = 0xe080;
  uVar5 = 0;
  do {
    iVar3 = iVar3 + -1;
    uVar5 = uVar5 + (uVar2 & 1) & 0xff;
    uVar2 = uVar2 >> 1;
  } while (iVar3 != 0);
  if (uVar5 == 4) {
    bVar7 = 0;
    puVar6 = &DAT_23000ab0;
    do {
      while (bVar7 == 0) {
        puVar6[0x14] = 7;
        puVar6 = puVar6 + 0xc;
        bVar7 = 1;
      }
      while (1 < bVar7) {
        iVar3 = 0xd;
        bVar4 = 1;
        uVar5 = 0xe000;
        do {
          uVar5 = uVar5 & ~(1 << iVar3);
          bVar1 = (byte)(uVar5 >> 8);
          bVar4 = bVar4 + 1;
          iVar3 = LZCOUNT((uint)(byte)(((bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7)
                          << 0x10);
        } while (bVar7 != bVar4);
        puVar6[0x14] = (char)iVar3;
        if (bVar7 == 3) {
          uVar5 = 0;
          do {
            uVar2 = 1 << (uVar5 >> 2 & 0xff);
            if ((uVar2 & 0xe080) != 0) {
              *(undefined4 *)(uVar5 + 0x5f99c100) = 0;
              uVar2 = *(uint *)(uVar5 + 0x5f99c100);
            }
            uVar5 = uVar5 + 4;
          } while (uVar5 != 0x40);
          FUN_0e0612ac(0x6d,0x5f99c100,0x40,uVar2);
          DAT_23000ab0 = 1;
          return 0xbad0000;
        }
        puVar6 = puVar6 + 0xc;
        bVar7 = 3;
      }
      bVar7 = 2;
      puVar6[0x14] = 0xd;
      puVar6 = puVar6 + 0xc;
    } while( true );
  }
  return 0xbad0001;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069760. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e069760(int param_1,undefined4 param_2,undefined4 param_3,uint param_4,char param_5)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = 1 << *(sbyte *)(param_1 + 8);
  if ((uVar3 & 0xe080) == 0) {
    return 0xbad0008;
  }
  if ((~DAT_23000ab4 & 0xe080 & uVar3) == 0) {
    return 0xbad0004;
  }
  FUN_0e0695c8();
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  *(undefined4 *)((uint)*(byte *)(param_1 + 8) * 4 + 0x5f99c100) = 0;
  iVar4 = (uint)*(byte *)(param_1 + 8) * 0x10;
  *(undefined4 *)(iVar4 + 0x5f99c520) = param_3;
  *(uint *)(iVar4 + 0x5f99c524) = param_4 & 0xfffff;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar2);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_5 != '\0') {
    _DAT_5f99c354 = 1 << *(sbyte *)(param_1 + 8);
  }
  return 0xbad0000;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069808. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e069808(uint param_1)

{
  uint uVar1;
  
  uVar1 = 1 << (param_1 & 0xff);
  if ((uVar1 & 0xe080) == 0) {
    return 0xbad0008;
  }
  if (((~DAT_23000ab4 & 0xe080 & uVar1) != 0) && ((DAT_23000ab8 & uVar1 & 0xe080) != 0)) {
    _DAT_5f99c358 = uVar1;
    return 0xbad0000;
  }
  return 0xbad0004;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069850. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e069850(uint param_1)

{
  uint uVar1;
  
  uVar1 = 1 << (param_1 & 0xff);
  if ((uVar1 & 0xe080) == 0) {
    return 0xbad0008;
  }
  if ((~DAT_23000ab4 & 0xe080 & uVar1) != 0) {
    DAT_23000ab8 = DAT_23000ab8 | uVar1;
    _DAT_5f99c354 = uVar1;
    return 0xbad0000;
  }
  return 0xbad0004;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069a24. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e069a24(uint *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  char *pcVar5;
  byte *pbVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  byte bVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  
  if (*(char *)(param_2 + 7) == '\0') {
    puVar8 = param_2 + -1;
    pcVar5 = (char *)(param_2 + 4);
    do {
      puVar8 = puVar8 + 1;
      uVar9 = *puVar8;
      if (uVar9 != 0xffffffff) {
        uVar7 = uVar9 & 0x1f;
        uVar9 = uVar9 >> 5;
        if (*pcVar5 == '\0') {
          if (9 < uVar9) {
            _NMI = 0;
                    /* WARNING: Does not return */
            pcVar1 = (code *)software_udf(0xff,0xe069b46);
            (*pcVar1)();
          }
          iVar11 = *(int *)(&DAT_0e07071c + uVar9 * 4);
          *(int *)(iVar11 + 8) = 1 << uVar7;
        }
        else {
          if (9 < uVar9) {
            _Reset = 0;
                    /* WARNING: Does not return */
            pcVar1 = (code *)software_udf(0xff,0xe069b42);
            (*pcVar1)();
          }
          iVar11 = *(int *)(&DAT_0e07071c + uVar9 * 4);
          *(int *)(iVar11 + 4) = 1 << uVar7;
        }
        iVar11 = iVar11 + uVar7 * 4;
        *(uint *)(iVar11 + 0x80) = *(uint *)(iVar11 + 0x80) & 0xfffcf0f0 | 3;
      }
      pcVar5 = pcVar5 + 1;
    } while (param_2 + 3 != puVar8);
  }
  uVar3 = *(ushort *)(param_2 + 6);
  bVar12 = *(byte *)((int)param_2 + 0x15);
  bVar2 = *(byte *)((int)param_2 + 0x16);
  uVar4 = *(ushort *)((int)param_2 + 0x1a);
  uVar9 = *param_1;
  if (*(char *)((int)param_2 + 0x1d) == '\0') {
    uVar15 = param_2[1];
    uVar14 = param_2[2];
    uVar13 = param_2[3];
    *(undefined4 *)(uVar9 + 0x560) = *param_2;
    *(undefined4 *)(uVar9 + 0x564) = uVar15;
    *(undefined4 *)(uVar9 + 0x568) = uVar14;
    *(undefined4 *)(uVar9 + 0x56c) = uVar13;
  }
  *(uint *)(uVar9 + 0x50c) = (uint)bVar12;
  *(uint *)(uVar9 + 0x504) = (uint)bVar2;
  *(uint *)(uVar9 + 0x508) = (uint)uVar3;
  *(uint *)(uVar9 + 0x510) = (uint)uVar4;
  uVar9 = *param_1;
  *(undefined4 *)(uVar9 + 0x110) = 0;
  *(undefined4 *)(uVar9 + 0x108) = 0;
  *(undefined4 *)(uVar9 + 0x10c) = 0;
  FUN_0e0612ac((uVar9 & 0x1fffff) >> 0xc,*(undefined4 *)(uVar9 + 0x108),0,
               *(undefined4 *)(uVar9 + 0x10c),param_4);
  pbVar10 = (byte *)((int)param_2 + 0xf);
  do {
    pbVar6 = pbVar10 + (-0xf - (int)param_2);
    uVar9 = *param_1;
    pbVar10 = pbVar10 + 1;
    bVar12 = *pbVar10;
    if (*(char *)((int)param_2 + 0x16) == '\0') {
      bVar12 = bVar12 ^ 1;
    }
    uVar7 = 1 << ((uint)pbVar6 & 0xff);
    if (bVar12 == 0) {
      *(uint *)(uVar9 + 0x518) = *(uint *)(uVar9 + 0x518) & ~uVar7;
    }
    else {
      *(uint *)(uVar9 + 0x518) = uVar7 | *(uint *)(uVar9 + 0x518);
    }
  } while (pbVar10 != (byte *)((int)param_2 + 0x13));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069b50. Types and names are inferred; NOT original source. */

undefined4 FUN_0e069b50(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 4);
  if ((&DAT_23006e0c)[uVar1 * 0x14] == '\0') {
    (&DAT_23006e04)[uVar1 * 5] = param_3;
    (&DAT_23006e08)[uVar1 * 5] = param_4;
    if (param_2 != 0) {
      (&DAT_23006e14)[uVar1 * 0x14] = *(undefined1 *)(param_2 + 0x1c);
      FUN_0e069a24();
    }
    (&DAT_23006e0c)[uVar1 * 0x14] = 1;
    return 0xbad0000;
  }
  return 0xbad000c;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069ba8. Types and names are inferred; NOT original source. */

int FUN_0e069ba8(int *param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  
  iVar2 = *param_1;
  uVar4 = (uint)*(byte *)(param_1 + 1);
  *(undefined4 *)(iVar2 + 0x704) = *param_2;
  *(uint *)(iVar2 + 0x708) = (uint)*(ushort *)(param_2 + 1) << 1;
  *(undefined4 *)(iVar2 + 0x528) = param_2[2];
  *(undefined4 *)(iVar2 + 0x52c) = param_2[3];
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x728) = *param_2;
  *(uint *)(iVar2 + 0x72c) = (uint)*(ushort *)(param_2 + 1) << 1;
  *(undefined4 *)(iVar2 + 0x548) = param_2[2];
  *(undefined4 *)(iVar2 + 0x54c) = param_2[3];
  uVar1 = param_3 & 1;
  *(uint *)(*param_1 + 0x514) = uVar1 + (param_3 >> 1);
  if ((int)(param_4 << 0x1f) < 0) {
    uVar3 = 0x10;
  }
  else {
    uVar3 = 0;
    if ((param_4 & 2) != 0) {
      if (uVar1 == 0) {
        uVar3 = 4;
      }
      else {
        uVar3 = 8;
      }
    }
  }
  *(undefined4 *)(*param_1 + 0x200) = uVar3;
  (&DAT_23006e0c)[uVar4 * 0x14] = 2;
  (&DAT_23006e10)[uVar4 * 5] = param_4;
  iVar2 = (&DAT_23006e04)[uVar4 * 5];
  *(undefined4 *)(*param_1 + 0x500) = 1;
  if (iVar2 != 0) {
    if ((param_4 & 4) == 0) {
      uVar4 = 0x82;
    }
    else {
      uVar4 = 0x92;
    }
    if ((int)(param_4 << 0x1c) < 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((int)(param_4 << 0x1b) < 0) {
      uVar4 = uVar4 & 0xffffff7f;
    }
    *(uint *)(*param_1 + 0x300) = uVar4;
  }
  bVar5 = (param_4 & 0x80) == 0;
  if (bVar5) {
    param_4 = 1;
  }
  iVar2 = uVar1 * 8 + 0x10;
  if (bVar5) {
    *(uint *)(*param_1 + iVar2) = param_4;
    iVar2 = 0;
  }
  else {
    iVar2 = *param_1 + iVar2;
  }
  return iVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069c78. Types and names are inferred; NOT original source. */

bool FUN_0e069c78(int *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  
  bVar2 = *(byte *)(param_1 + 1);
  *(undefined4 *)(*param_1 + 0x200) = 0;
  *(undefined4 *)(*param_1 + 4) = 1;
  if (param_2 != 0) {
    iVar4 = *param_1;
    do {
      while ((iVar1 = (uint)*(byte *)(param_1 + 1) * 0x14,
             (&DAT_23006e04)[(uint)*(byte *)(param_1 + 1) * 5] != 0 ||
             (*(int *)(iVar4 + 0x104) == 0))) {
        if ((&DAT_23006e0c)[iVar1] != '\x02') goto LAB_0e069cec;
      }
      *(undefined4 *)(iVar4 + 0x104) = 0;
      (&DAT_23006e0c)[iVar1] = 1;
      iVar4 = *param_1;
    } while ((&DAT_23006e0c)[iVar1] == '\x02');
LAB_0e069cec:
    *(undefined4 *)(iVar4 + 0x500) = 0;
    (&DAT_23006e0c)[(uint)bVar2 * 0x14] = 1;
  }
  uVar3 = (uint)*(byte *)(param_1 + 1);
  if (((&DAT_23006e04)[uVar3 * 5] == 0) && (*(int *)(*param_1 + 0x104) != 0)) {
    *(undefined4 *)(*param_1 + 0x104) = 0;
    (&DAT_23006e0c)[uVar3 * 0x14] = 1;
  }
  return (&DAT_23006e0c)[uVar3 * 0x14] != '\x02';
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069d20. Types and names are inferred; NOT original source. */

bool FUN_0e069d20(int *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 1);
  if (((&DAT_23006e04)[uVar1 * 5] == 0) && (*(int *)(*param_1 + 0x104) != 0)) {
    *(undefined4 *)(*param_1 + 0x104) = 0;
    (&DAT_23006e0c)[uVar1 * 0x14] = 1;
  }
  return (&DAT_23006e0c)[uVar1 * 0x14] != '\x02';
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069e04. Types and names are inferred; NOT original source. */

undefined4 FUN_0e069e04(uint *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  dword *pdVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  
  pdVar6 = (dword *)*param_1;
  uVar10 = *param_2;
  if ((pdVar6 == (dword *)0x5f8e2000) || (pdVar6 == (dword *)0x5f8e3000)) {
    uVar7 = 320000000;
    uVar9 = 320000000 / uVar10;
    if (uVar10 * uVar9 != 320000000) {
      return 0xbad0004;
    }
  }
  else if (((pdVar6 == &TIMER020_S_TASKS_START) || (pdVar6 == &TIMER021_S_TASKS_START)) ||
          (pdVar6 == &TIMER022_S_TASKS_START)) {
    uVar7 = 32000000;
    uVar9 = 32000000 / uVar10;
    if (uVar10 * uVar9 != 32000000) {
      return 0xbad0004;
    }
  }
  else {
    uVar7 = 16000000;
    uVar9 = 16000000 / uVar10;
    if (uVar10 * uVar9 != 16000000) {
      return 0xbad0004;
    }
  }
  if (((uVar10 <= uVar7) && ((uVar9 - 1 & uVar9) == 0)) && (uVar9 < 0x201)) {
    uVar7 = uVar7 / uVar10;
    bVar3 = (byte)uVar7;
    bVar4 = (byte)(uVar7 >> 8);
    bVar5 = (byte)(uVar7 >> 0x10);
    bVar2 = (byte)(uVar7 >> 0x18);
    bVar1 = *(byte *)((int)param_2 + 5);
    pdVar6[0x141] = (byte)param_2[1] & 3 | pdVar6[0x141] & 0xfffffffc;
    pdVar6[0x142] = pdVar6[0x142] & 0xfffffffc | bVar1 & 3;
    pdVar6[0x144] =
         LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                                 bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1
                              | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18 |
                 (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                                 bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1
                              | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                 (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1) << 1 |
                                 bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1
                              | bVar5 >> 6 & 1) << 1 | bVar5 >> 7) << 8 |
                 (uint)(byte)((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                               bVar2 >> 3 & 1) << 1 | bVar2 >> 4) << 3));
    uVar10 = *param_1;
    puVar8 = (undefined4 *)(uVar10 + 0x140);
    do {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    } while ((undefined4 *)(uVar10 + 0x160) != puVar8);
    FUN_0e0612ac((uVar10 & 0x1fffff) >> 0xc);
    return 0xbad0000;
  }
  return 0xbad0004;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069ee8. Types and names are inferred; NOT original source. */

int FUN_0e069ee8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_1 + 4);
  if ((&DAT_23006e48)[uVar3 * 0xc] == '\0') {
    *(undefined4 *)(&DAT_23006e40 + uVar3 * 0xc) = param_3;
    if (param_2 == 0) {
      bVar2 = true;
      iVar1 = 0xbad0000;
    }
    else {
      *(undefined4 *)(&DAT_23006e44 + uVar3 * 0xc) = *(undefined4 *)(param_2 + 8);
      iVar1 = FUN_0e069e04();
      bVar2 = iVar1 == 0xbad0000;
    }
    (&DAT_23006e48)[uVar3 * 0xc] = bVar2;
    return iVar1;
  }
  return 0xbad000c;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069f5c. Types and names are inferred; NOT original source. */

void FUN_0e069f5c(int *param_1)

{
  *(undefined4 *)(*param_1 + 4) = 1;
  *(undefined4 *)(*param_1 + 0xc) = 1;
  (&DAT_23006e48)[(uint)*(byte *)(param_1 + 1) * 0xc] = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069f7c. Types and names are inferred; NOT original source. */

void FUN_0e069f7c(int *param_1)

{
  *(undefined4 *)(*param_1 + 0xc) = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069f84. Types and names are inferred; NOT original source. */

uint FUN_0e069f84(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  dword *pdVar2;
  uint uVar3;
  uint uVar4;
  
  pdVar2 = (dword *)*param_1;
  uVar4 = pdVar2[0x144];
  if ((pdVar2 == (dword *)0x5f8e2000) || (pdVar2 == (dword *)0x5f8e3000)) {
    uVar3 = 0x140;
  }
  else if ((pdVar2 == &TIMER020_S_TASKS_START) || (pdVar2 == &TIMER021_S_TASKS_START)) {
    uVar3 = 0x20;
  }
  else if (pdVar2 == &TIMER022_S_TASKS_START) {
    uVar3 = 0x20;
  }
  else {
    uVar3 = 0x10;
  }
  uVar1 = (uint)((ulonglong)param_2 * (ulonglong)uVar3 >> 0x20);
  return uVar1 >> (uVar4 - 0x20 & 0xff) |
         (uint)((ulonglong)param_2 * (ulonglong)uVar3) >> (uVar4 & 0xff) |
         uVar1 << (0x20 - uVar4 & 0xff);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e069ff0. Types and names are inferred; NOT original source. */

uint FUN_0e069ff0(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  dword *pdVar2;
  uint uVar3;
  uint uVar4;
  
  pdVar2 = (dword *)*param_1;
  uVar4 = pdVar2[0x144];
  if ((pdVar2 == (dword *)0x5f8e2000) || (pdVar2 == (dword *)0x5f8e3000)) {
    uVar3 = 320000;
  }
  else if ((pdVar2 == &TIMER020_S_TASKS_START) || (pdVar2 == &TIMER021_S_TASKS_START)) {
    uVar3 = 32000;
  }
  else if (pdVar2 == &TIMER022_S_TASKS_START) {
    uVar3 = 32000;
  }
  else {
    uVar3 = 16000;
  }
  uVar1 = (uint)((ulonglong)param_2 * (ulonglong)uVar3 >> 0x20);
  return uVar1 >> (uVar4 - 0x20 & 0xff) |
         (uint)((ulonglong)param_2 * (ulonglong)uVar3) >> (uVar4 & 0xff) |
         uVar1 << (0x20 - uVar4 & 0xff);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a064. Types and names are inferred; NOT original source. */

void FUN_0e06a064(int *param_1,uint param_2,undefined4 param_3,uint param_4,char param_5)

{
  uint uVar1;
  
  uVar1 = 0x10000 << (param_2 & 0xff);
  *(uint *)(*param_1 + 0x200) = *(uint *)(*param_1 + 0x200) & ~(uVar1 | 1 << (param_2 & 0xff));
  *(uint *)(*param_1 + 0x200) = *(uint *)(*param_1 + 0x200) | param_4;
  if (param_5 == '\0') {
    *(uint *)(*param_1 + 0x308) = uVar1;
  }
  else {
    *(undefined4 *)(*param_1 + param_2 * 4 + 0x140) = 0;
    *(uint *)(*param_1 + 0x304) = uVar1;
  }
  *(undefined4 *)(*param_1 + (param_2 + 0x150) * 4) = param_3;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a0d4. Types and names are inferred; NOT original source. */

bool FUN_0e06a0d4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0e06ab70();
  if ((((iVar1 == 0xf) || (iVar1 = FUN_0e06ab70(param_2), iVar1 == 0xf)) &&
      (iVar1 = FUN_0e06ab78(), param_1 != iVar1)) && (iVar1 = FUN_0e06ab78(), param_2 != iVar1)) {
    return param_1 != param_2;
  }
  return false;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a108. Types and names are inferred; NOT original source. */

void FUN_0e06a108(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  
  piVar11 = *(int **)(&DAT_23006e58 + param_1 * 0xc);
  iVar4 = param_1 * 0xc;
  piVar10 = *(int **)(&DAT_23006e5c + iVar4);
  iVar3 = FUN_0e06ab70(piVar11);
  if (iVar3 == 0xf) {
    bVar1 = (&DAT_23006e60)[iVar4];
  }
  else {
    bVar1 = (&DAT_23006e61)[iVar4];
  }
  iVar4 = FUN_0e06ab70(piVar10);
  if (iVar4 == 0xf) {
    bVar2 = (&DAT_23006e60)[param_1 * 0xc];
  }
  else {
    bVar2 = (&DAT_23006e61)[param_1 * 0xc];
  }
  iVar4 = 1 << (uint)bVar1;
  iVar3 = 1 << (uint)bVar2;
  if (param_2 == 0) {
    *(int *)(*piVar11 + 0x508) = iVar4;
    *(int *)(*piVar10 + 0x508) = iVar3;
    iVar5 = FUN_0e06a0d4(piVar11,piVar10);
    if (iVar5 != 0) {
      piVar9 = (int *)FUN_0e06ab78();
      *(int *)(*piVar9 + 0x508) = 1 << (&DAT_23006e60)[param_1 * 0xc];
    }
    iVar5 = FUN_0e06ab70(piVar11);
    iVar6 = FUN_0e06ab70(piVar10);
    if (iVar5 != iVar6) {
      puVar7 = (undefined4 *)FUN_0e06abf4(piVar11);
      puVar8 = (undefined4 *)FUN_0e06abf4(piVar10);
      piVar10 = (int *)FUN_0e06ab80(*puVar7);
      piVar11 = (int *)FUN_0e06ab80(*puVar8);
      *(int *)(*piVar10 + 0x508) = iVar4;
      *(int *)(*piVar11 + 0x508) = iVar3;
    }
  }
  else {
    *(int *)(*piVar11 + 0x504) = iVar4;
    *(int *)(*piVar10 + 0x504) = iVar3;
    iVar5 = FUN_0e06a0d4(piVar11,piVar10);
    if (iVar5 == 0) {
      iVar5 = FUN_0e06ab70(piVar11);
      iVar6 = FUN_0e06ab70(piVar10);
      if (iVar6 != iVar5) {
LAB_0e06a18e:
        puVar7 = (undefined4 *)FUN_0e06abf4(piVar11);
        puVar8 = (undefined4 *)FUN_0e06abf4(piVar10);
        piVar10 = (int *)FUN_0e06ab80(*puVar7);
        piVar11 = (int *)FUN_0e06ab80(*puVar8);
        *(int *)(*piVar10 + 0x504) = iVar4;
        *(int *)(*piVar11 + 0x504) = iVar3;
        return;
      }
    }
    else {
      piVar9 = (int *)FUN_0e06ab78();
      *(int *)(*piVar9 + 0x504) = 1 << (uint)(byte)(&DAT_23006e60)[param_1 * 0xc];
      iVar5 = FUN_0e06ab70(piVar11);
      iVar6 = FUN_0e06ab70(piVar10);
      if (iVar5 != iVar6) goto LAB_0e06a18e;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a264. Types and names are inferred; NOT original source. */

int FUN_0e06a264(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 == param_2) {
    if (param_3 == 0xff) {
      return 0xbad0004;
    }
    iVar3 = FUN_0e068a9c(*(undefined4 *)(param_1 + 4),param_3);
    if (iVar3 != 0xbad0000) {
      return iVar3;
    }
    FUN_0e06ab70(param_1);
  }
  else {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_3 == 0xff) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0xbad0004;
    }
    iVar3 = FUN_0e068a9c(*(undefined4 *)(param_1 + 4),param_3);
    if ((iVar3 != 0xbad0000) ||
       (iVar3 = FUN_0e068a9c(*(undefined4 *)(param_2 + 4),param_3), iVar3 != 0xbad0000)) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return iVar3;
    }
    iVar3 = FUN_0e06a0d4(param_1,param_2);
    if (iVar3 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    else {
      iVar3 = FUN_0e06ab78();
      iVar3 = FUN_0e068a9c(*(undefined4 *)(iVar3 + 4),param_3);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      if (iVar3 != 0xbad0000) {
        return iVar3;
      }
    }
    iVar3 = FUN_0e06ab70(param_1);
    if (iVar3 == 3) {
      *(undefined4 *)(*(int *)(param_1 + 0x10) + (param_3 & 0x3f) * 4 + 0x80) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x10) + param_3 * 4 + 0x180) = 0;
    }
  }
  return 0xbad0000;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a32c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06a32c(int *param_1,int *param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  sbyte *psVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  byte *local_2c;
  
  uVar3 = FUN_0e06ab80(*param_1);
  uVar4 = FUN_0e06ab80(*param_2);
  iVar5 = FUN_0e06ab70(uVar3);
  if (iVar5 == 0xf) {
    local_2c = (byte *)(param_3 + 0xb);
    bVar1 = *(byte *)(param_3 + 8);
    bVar2 = *(byte *)(param_3 + 9);
    psVar7 = (sbyte *)(param_3 + 10);
  }
  else {
    iVar5 = FUN_0e06ab70(uVar4);
    if (iVar5 != 0xf) {
      return 0xbad0004;
    }
    local_2c = (byte *)(param_3 + 10);
    bVar1 = *(byte *)(param_3 + 9);
    bVar2 = *(byte *)(param_3 + 8);
    psVar7 = (sbyte *)(param_3 + 0xb);
  }
  puVar8 = (uint *)param_1[1];
  uVar6 = *(uint *)param_2[1];
  uVar10 = *puVar8;
  uVar9 = param_2[3];
  uVar13 = uVar10 & param_1[2];
  do {
    uVar10 = uVar10 & uVar13;
    if (uVar10 == 0) {
      return 0xbad0002;
    }
    uVar11 = 0x1f - LZCOUNT(uVar10);
    uVar12 = *puVar8;
    *puVar8 = uVar12 & ~(1 << (uVar11 & 0xff));
    uVar10 = *puVar8;
  } while (uVar12 == uVar10);
  *psVar7 = (sbyte)uVar11;
  puVar8 = (uint *)param_2[1];
  uVar10 = *puVar8;
  do {
    uVar10 = uVar10 & uVar6 & uVar9;
    if (uVar10 == 0) {
      if (*psVar7 != -1) {
        FUN_0e068a9c(param_1[1]);
      }
      return 0xbad0002;
    }
    uVar13 = 0x1f - LZCOUNT(uVar10);
    uVar11 = *puVar8;
    *puVar8 = uVar11 & ~(1 << (uVar13 & 0xff));
    uVar10 = *puVar8;
  } while (uVar11 == uVar10);
  *local_2c = (byte)uVar13;
  *(uint *)(*param_1 + 0x200) = 1 << *psVar7 | *(uint *)(*param_1 + 0x200);
  *(uint *)(*param_2 + 0x200) = 1 << *local_2c | *(uint *)(*param_2 + 0x200);
  *(uint *)(*param_1 + (byte)(*psVar7 << 2) + 0x80) = bVar1 | 0x80000000;
  *(uint *)(*param_2 + (uint)*local_2c * 4 + 0x180) = bVar2 | 0x80000000;
  return 0xbad0000;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a484. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06a484(int param_1,int param_2,byte *param_3)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  
  if (param_1 == param_2) {
    puVar6 = *(uint **)(param_1 + 4);
    uVar7 = *puVar6;
    uVar9 = (*(uint *)(param_1 + 8) | *(uint *)(param_1 + 0xc)) & uVar7;
    do {
      uVar7 = uVar7 & uVar9;
      if (uVar7 == 0) {
        return 0xbad0002;
      }
      uVar8 = 0x1f - LZCOUNT(uVar7);
      uVar5 = *puVar6;
      *puVar6 = uVar5 & ~(1 << (uVar8 & 0xff));
      uVar7 = *puVar6;
    } while (uVar5 == uVar7);
    *param_3 = (byte)uVar8;
    return 0xbad0000;
  }
  uVar10 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar10 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar9 = getBasePriority(), uVar9 == 0 || 0x40 < uVar9)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar9 = *(uint *)(param_1 + 8) & *(uint *)(param_2 + 0xc) & **(uint **)(param_2 + 4) &
          **(uint **)(param_1 + 4);
  iVar2 = FUN_0e06a0d4();
  if (iVar2 != 0) {
    iVar4 = FUN_0e06ab78();
    uVar5 = *(uint *)(iVar4 + 8);
    iVar4 = FUN_0e06ab78();
    uVar7 = *(uint *)(iVar4 + 0xc);
    iVar4 = FUN_0e06ab78();
    uVar9 = uVar5 & uVar7 & uVar9 & **(uint **)(iVar4 + 4);
  }
  puVar6 = *(uint **)(param_1 + 4);
  uVar7 = *puVar6;
  do {
    if ((uVar7 & uVar9) == 0) goto LAB_0e06a55c;
    uVar8 = 0x1f - LZCOUNT(uVar7 & uVar9);
    uVar5 = uVar8 & 0xff;
    uVar11 = *puVar6;
    *puVar6 = uVar11 & ~(1 << uVar5);
    uVar7 = *puVar6;
  } while (uVar11 == uVar7);
  *param_3 = (byte)uVar8;
  puVar6 = *(uint **)(param_2 + 4);
  uVar7 = *puVar6;
  do {
    if ((uVar7 & uVar9) == 0) {
      uVar8 = 0xff;
      goto LAB_0e06a546;
    }
    uVar8 = 0x1fU - LZCOUNT(uVar7 & uVar9) & 0xff;
    uVar11 = *puVar6;
    *puVar6 = uVar11 & ~(1 << uVar8);
    uVar7 = *puVar6;
  } while (uVar11 == uVar7);
  uVar7 = uVar8;
  if (iVar2 != 0) {
    *param_3 = 0xff;
    iVar2 = FUN_0e06ab78();
    puVar6 = *(uint **)(iVar2 + 4);
    uVar11 = *puVar6;
    do {
      if ((uVar11 & uVar9) == 0) goto LAB_0e06a546;
      uVar7 = 0x1fU - LZCOUNT(uVar11 & uVar9) & 0xff;
      uVar12 = *puVar6;
      *puVar6 = uVar12 & ~(1 << uVar7);
      uVar11 = *puVar6;
    } while (uVar12 == uVar11);
  }
  *param_3 = (byte)uVar7;
  iVar2 = FUN_0e06ab70(param_1);
  if (iVar2 == 3) {
    uVar9 = (uint)*param_3;
    *(uint *)(*(int *)(param_1 + 0x10) + (uVar9 & 0x3f) * 4 + 0x80) = uVar9 | 0x80000000;
    *(uint *)(*(int *)(param_2 + 0x10) + uVar9 * 4 + 0x180) = uVar9 | 0x80000000;
  }
  uVar3 = 0xbad0000;
LAB_0e06a56e:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar10);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
LAB_0e06a546:
  FUN_0e068a9c(*(undefined4 *)(param_1 + 4),uVar5);
  if (uVar8 != 0xff) {
    FUN_0e068a9c(*(undefined4 *)(param_2 + 4),uVar8);
  }
LAB_0e06a55c:
  iVar2 = FUN_0e06ab78();
  if (*param_3 != 0xff) {
    FUN_0e068a9c(*(undefined4 *)(iVar2 + 4));
  }
  uVar3 = 0xbad0002;
  goto LAB_0e06a56e;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a658. Types and names are inferred; NOT original source. */

void FUN_0e06a658(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0e068a5c(&DAT_23000af8,param_1);
  if (iVar1 != 0xbad0000) {
    return;
  }
  iVar1 = (uint)*param_1 * 0xc;
  iVar2 = (uint)*param_1 * 0xc;
  *(undefined4 *)(&DAT_23006e58 + iVar2) = 0;
  *(undefined4 *)(&DAT_23006e5c + iVar1) = 0;
  *(undefined4 *)(&DAT_23006e60 + iVar1) = 0;
  *(undefined2 *)(&DAT_23006e60 + iVar2) = 0xffff;
  (&DAT_23006e62)[iVar1] = 0xff;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a6a0. Types and names are inferred; NOT original source. */

void FUN_0e06a6a0(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_0e06ab80(param_2);
  iVar3 = FUN_0e06ab70();
  if (iVar3 == 0xf) {
    bVar1 = (&DAT_23006e60)[param_1 * 0xc];
  }
  else {
    bVar1 = (&DAT_23006e61)[param_1 * 0xc];
  }
  if (((*(int *)(&DAT_23006e5c + param_1 * 0xc) != iVar2) &&
      (*(int *)(&DAT_23006e58 + param_1 * 0xc) != iVar2)) && (iVar2 = FUN_0e06a0d4(), iVar2 != 0)) {
    FUN_0e06ab78();
  }
  if (param_2 + 0xacfd4000U < 0x1065) {
    iVar2 = 0x100;
  }
  else {
    iVar2 = 0x80;
  }
  *(uint *)(iVar2 + param_2) = bVar1 | 0x80000000;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a708. Types and names are inferred; NOT original source. */

void FUN_0e06a708(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0e06ab80(param_2);
  if (((*(int *)(&DAT_23006e5c + param_1 * 0xc) != iVar1) &&
      (*(int *)(&DAT_23006e58 + param_1 * 0xc) != iVar1)) && (iVar1 = FUN_0e06a0d4(), iVar1 != 0)) {
    FUN_0e06ab78();
  }
  if (param_2 + 0xacfd4000U < 0x1065) {
    iVar1 = 0x100;
  }
  else {
    iVar1 = 0x80;
  }
  *(undefined4 *)(iVar1 + param_2) = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a760. Types and names are inferred; NOT original source. */

void FUN_0e06a760(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  byte *pbVar12;
  int iVar13;
  
  uVar1 = FUN_0e06ab80(param_2);
  uVar2 = FUN_0e06ab80(param_3);
  iVar3 = FUN_0e06ab70(uVar1);
  iVar13 = param_1 * 0xc;
  if (iVar3 == 0xf) {
    iVar3 = iVar13 + 8;
  }
  else {
    iVar3 = iVar13 + 9;
  }
  iVar4 = FUN_0e06ab70(uVar2);
  if (iVar4 == 0xf) {
    iVar4 = iVar13 + 8;
  }
  else {
    iVar4 = iVar13 + 9;
  }
  pbVar11 = &DAT_23006e58 + iVar4;
  iVar5 = FUN_0e06ab70(uVar1);
  iVar6 = FUN_0e06ab70(uVar2);
  iVar4 = param_1 * 0xc;
  pbVar12 = &DAT_23006e58 + iVar3;
  if (iVar5 == iVar6) {
    iVar3 = FUN_0e06a484(uVar1,uVar2,pbVar12);
    if (iVar3 == 0xbad0000) goto LAB_0e06a868;
    FUN_0e06a264(uVar1,uVar2,*pbVar12);
  }
  else {
    puVar7 = (undefined4 *)FUN_0e06abf4(uVar1);
    puVar8 = (undefined4 *)FUN_0e06abf4(uVar2);
    uVar9 = FUN_0e06ab80(*puVar7);
    uVar10 = FUN_0e06ab80(*puVar8);
    iVar3 = FUN_0e06a484(uVar1,uVar9,pbVar12);
    if (((iVar3 == 0xbad0000) && (iVar3 = FUN_0e06a484(uVar10,uVar2,pbVar11), iVar3 == 0xbad0000))
       && (iVar3 = FUN_0e06a32c(puVar7,puVar8,&DAT_23006e58 + iVar4), iVar3 == 0xbad0000)) {
LAB_0e06a868:
      *(undefined4 *)(&DAT_23006e58 + param_1 * 0xc) = uVar1;
      if (param_2 + 0xacfd4000U < 0x1065) {
        iVar3 = 0x100;
      }
      else {
        iVar3 = 0x80;
      }
      if (param_3 + 0xacfd4000U < 0x1065) {
        iVar13 = 0x100;
      }
      else {
        iVar13 = 0x80;
      }
      *(undefined4 *)(&DAT_23006e5c + param_1 * 0xc) = uVar2;
      *(uint *)(iVar3 + param_2) = *pbVar12 | 0x80000000;
      *(uint *)(iVar13 + param_3) = *pbVar11 | 0x80000000;
      return;
    }
    FUN_0e06a264(uVar1,uVar9,*pbVar12);
    FUN_0e06a264(uVar10,uVar2,*pbVar11);
    FUN_0e06a32c(puVar7,puVar8,&DAT_23006e58 + iVar4);
  }
  *(undefined4 *)(&DAT_23006e58 + iVar13) = 0;
  *(undefined4 *)(&DAT_23006e5c + iVar4) = 0;
  *(undefined4 *)(&DAT_23006e60 + iVar4) = 0;
  *(undefined2 *)(&DAT_23006e60 + param_1 * 0xc) = 0xffff;
  (&DAT_23006e62)[param_1 * 0xc] = 0xff;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06a8e0. Types and names are inferred; NOT original source. */

void FUN_0e06a8e0(int param_1,int param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  
  uVar2 = FUN_0e06ab80(param_2);
  uVar3 = FUN_0e06ab80(param_3);
  iVar4 = FUN_0e06ab70(uVar2);
  iVar13 = param_1 * 0xc;
  if (iVar4 == 0xf) {
    iVar4 = iVar13 + 8;
  }
  else {
    iVar4 = iVar13 + 9;
  }
  iVar5 = FUN_0e06ab70(uVar3);
  if (iVar5 == 0xf) {
    iVar5 = iVar13 + 8;
  }
  else {
    iVar5 = iVar13 + 9;
  }
  iVar6 = FUN_0e06ab70(uVar2);
  iVar7 = FUN_0e06ab70(uVar3);
  if (iVar6 == iVar7) {
    iVar4 = FUN_0e06a264(uVar2,uVar3,(&DAT_23006e58)[iVar4]);
  }
  else {
    piVar8 = (int *)FUN_0e06abf4(uVar2);
    piVar9 = (int *)FUN_0e06abf4(uVar3);
    uVar10 = FUN_0e06ab80(*piVar8);
    uVar11 = FUN_0e06ab80(*piVar9);
    iVar6 = FUN_0e06abec(piVar8);
    if (iVar6 == 0xf) {
      bVar1 = (&DAT_23006e62)[param_1 * 0xc];
    }
    else {
      bVar1 = (&DAT_23006e63)[param_1 * 0xc];
    }
    uVar12 = (uint)bVar1;
    iVar6 = FUN_0e06abec(piVar9);
    if (iVar6 == 0xf) {
      bVar1 = (&DAT_23006e62)[param_1 * 0xc];
    }
    else {
      bVar1 = (&DAT_23006e63)[param_1 * 0xc];
    }
    uVar14 = (uint)bVar1;
    if (uVar12 == 0xff) {
      return;
    }
    iVar6 = FUN_0e068a9c(piVar8[1],uVar12);
    if (iVar6 != 0xbad0000) {
      return;
    }
    if (uVar14 == 0xff) {
      return;
    }
    iVar6 = FUN_0e068a9c(piVar9[1],uVar14);
    if (iVar6 != 0xbad0000) {
      return;
    }
    *(uint *)(*piVar8 + 0x200) = *(uint *)(*piVar8 + 0x200) & ~(1 << uVar12);
    *(uint *)(*piVar9 + 0x200) = *(uint *)(*piVar9 + 0x200) & ~(1 << uVar14);
    *(undefined4 *)(*piVar8 + (uVar12 & 0x3f) * 4 + 0x80) = 0;
    *(undefined4 *)(*piVar9 + uVar14 * 4 + 0x180) = 0;
    iVar4 = FUN_0e06a264(uVar2,uVar10,(&DAT_23006e58)[iVar4]);
    if (iVar4 != 0xbad0000) {
      return;
    }
    iVar4 = FUN_0e06a264(uVar11,uVar3,(&DAT_23006e58)[iVar5]);
  }
  if (iVar4 == 0xbad0000) {
    if (param_2 + 0xacfd4000U < 0x1065) {
      iVar4 = 0x100;
    }
    else {
      iVar4 = 0x80;
    }
    if (param_3 + 0xacfd4000U < 0x1065) {
      iVar5 = 0x100;
    }
    else {
      iVar5 = 0x80;
    }
    *(undefined4 *)(&DAT_23006e58 + iVar13) = 0;
    *(undefined4 *)(&DAT_23006e5c + iVar13) = 0;
    *(undefined4 *)(&DAT_23006e60 + iVar13) = 0;
    *(undefined2 *)(&DAT_23006e60 + param_1 * 0xc) = 0xffff;
    (&DAT_23006e62)[param_1 * 0xc] = 0xff;
    *(undefined4 *)(iVar4 + param_2) = 0;
    *(undefined4 *)(iVar5 + param_3) = 0;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06aacc. Types and names are inferred; NOT original source. */

uint FUN_0e06aacc(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = (uint)(byte)(&DAT_23006e60)[param_1 * 0xc];
  if (uVar4 == 0xff) {
    return 0;
  }
  uVar3 = 0;
  if ((*(uint *)(**(int **)(&DAT_23006e58 + param_1 * 0xc) + 0x500) >> uVar4 & 1) != 0) {
    uVar3 = *(uint *)(**(int **)(&DAT_23006e5c + param_1 * 0xc) + 0x500) >> uVar4 & 1;
    if ((uVar3 != 0) && (iVar1 = FUN_0e06a0d4(), iVar1 != 0)) {
      piVar2 = (int *)FUN_0e06ab78();
      return *(uint *)(*piVar2 + 0x500) >> uVar4 & 1;
    }
  }
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ab28. Types and names are inferred; NOT original source. */

void FUN_0e06ab28(uint param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return;
  }
  do {
    bVar2 = (byte)param_1;
    bVar3 = (byte)(param_1 >> 8);
    bVar4 = (byte)(param_1 >> 0x10);
    bVar1 = (byte)(param_1 >> 0x18);
    iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                     1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                  bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18
                    | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                       << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                    bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                      0x10 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                              bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                            bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                          bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                    (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) <<
                                     1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                  bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    FUN_0e06a108(iVar5,1);
    param_1 = param_1 & ~(1 << iVar5);
  } while (param_1 != 0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ab4c. Types and names are inferred; NOT original source. */

void FUN_0e06ab4c(uint param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  
  if (param_1 == 0) {
    return;
  }
  do {
    bVar2 = (byte)param_1;
    bVar3 = (byte)(param_1 >> 8);
    bVar4 = (byte)(param_1 >> 0x10);
    bVar1 = (byte)(param_1 >> 0x18);
    iVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                     1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                  bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18
                    | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                       << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                    bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                      0x10 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                              bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                            bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                          bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                    (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) <<
                                     1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                  bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    FUN_0e06a108(iVar5,0);
    param_1 = param_1 & ~(1 << iVar5);
  } while (param_1 != 0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ab70. Types and names are inferred; NOT original source. */

byte FUN_0e06ab70(int param_1)

{
  return *(byte *)(param_1 + 3) & 0xf;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ab78. Types and names are inferred; NOT original source. */

undefined * FUN_0e06ab78(void)

{
  return &DAT_0e070744;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ab80. Types and names are inferred; NOT original source. */

uint * FUN_0e06ab80(uint param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  if ((param_1 & 0xfffffff) >> 0x18 == 0xf) {
    iVar2 = 4;
    puVar1 = (uint *)&DAT_0e070744;
  }
  else {
    iVar2 = 1;
    puVar1 = &DAT_0e0707a4;
  }
  puVar3 = puVar1 + iVar2 * 6;
  do {
    if ((*puVar1 & -puVar1[5] & 0xffffff) >> 0x10 == (param_1 & -puVar1[5] & 0xffffff) >> 0x10) {
      return puVar1;
    }
    puVar1 = puVar1 + 6;
  } while (puVar3 != puVar1);
  return (uint *)0x0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06abd0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06abd0(void)

{
  return 4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06abd4. Types and names are inferred; NOT original source. */

undefined * FUN_0e06abd4(uint param_1)

{
  undefined *puVar1;
  
  if (param_1 < 4) {
    puVar1 = &DAT_0e070744 + param_1 * 0x18;
  }
  else {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06abec. Types and names are inferred; NOT original source. */

byte FUN_0e06abec(int param_1)

{
  return *(byte *)(param_1 + 3) & 0xf;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06abf4. Types and names are inferred; NOT original source. */

undefined4 * FUN_0e06abf4(uint *param_1)

{
  int iVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *param_1;
  uVar5 = param_1[5];
  iVar1 = FUN_0e06ab70();
  if (iVar1 != 0xf) {
    return (undefined4 *)&DAT_0e0707cc;
  }
  if ((uVar4 & -uVar5 & 0xffffff) >> 0x10 != (-param_1[5] >> 0x10 & 0x92)) {
    bVar3 = 0;
    do {
      uVar4 = FUN_0e06abd0();
      uVar5 = (uint)bVar3;
      bVar3 = bVar3 + 1;
      if (uVar4 <= uVar5) {
        return (undefined4 *)0x0;
      }
      puVar2 = (uint *)FUN_0e06abd4(uVar5);
    } while (*puVar2 != *param_1);
  }
  return &DAT_0e0707bc;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ad08. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06ad08(undefined1 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined2 local_10;
  undefined4 local_e;
  undefined1 local_a;
  undefined1 local_9;
  
  if (DAT_23006fe4 == '\0') {
    return 1;
  }
  local_10 = 0x301;
  local_e = param_3;
  local_a = param_1;
  local_9 = param_2;
  uVar1 = FUN_0e06b014(&local_10,8);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ae34. Types and names are inferred; NOT original source. */

void FUN_0e06ae34(void)

{
  DAT_23006ff4 = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ae70. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06ae70(undefined4 param_1)

{
  undefined4 uVar1;
  undefined2 local_10;
  undefined4 local_e;
  
  if (DAT_23006ff4 == '\0') {
    return 1;
  }
  local_10 = 0x802;
  local_e = param_1;
  uVar1 = FUN_0e06b014(&local_10,6);
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06aeec. Types and names are inferred; NOT original source. */

void FUN_0e06aeec(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06aef0. Types and names are inferred; NOT original source. */

/* WARNING: Switch with 1 destination removed at 0x0e06af14 */
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_0e06aef0(ushort *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  undefined1 uStack_c;
  ushort uStack_b;
  
  if ((*param_1 & 0x8000) == 0) {
    uVar2 = (*param_1 & 0x3fff) >> 8;
    if ((uVar2 < 10) && (*(int *)(&DAT_0e0707dc + uVar2 * 4) != 0)) {
      if ((pcRam23006fd8 == (code *)0x0) || (cRam23006fdc == '\0')) {
        return;
      }
      uVar1 = *param_1;
      if ((uVar1 & 0x4000) != 0) {
        uStack_c = 1;
        (*pcRam23006fd8)(&uStack_c,*(undefined4 *)(param_1 + 1));
        return;
      }
      uStack_b = param_1[3];
      if (uVar1 == 1) {
        uStack_c = 2;
        (*pcRam23006fd8)(&uStack_c,*(undefined4 *)(param_1 + 1));
        return;
      }
      if (uVar1 - 3 < 2) {
        uStack_c = 0;
        (*pcRam23006fd8)(&uStack_c,*(undefined4 *)(param_1 + 1));
      }
      return;
    }
  }
  else {
    FUN_0e06aeec(param_1 + 3,param_2 + -6);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06af24. Types and names are inferred; NOT original source. */

void FUN_0e06af24(void)

{
  int iVar1;
  undefined1 auStack_34 [2];
  undefined2 local_32;
  undefined1 auStack_30 [36];
  
  while( true ) {
    iVar1 = FUN_0e06cc94(&DAT_23001c04,auStack_34,0,0);
    if (iVar1 != 0) break;
    FUN_0e05edcc(&DAT_23000b20,auStack_30,local_32);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06af94. Types and names are inferred; NOT original source. */

int FUN_0e06af94(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 auStack_38 [36];
  
  iVar1 = FUN_0e06d830();
  if ((iVar1 == 0) && (DAT_23000b28 == 1)) {
    iVar1 = FUN_0e05edcc(&DAT_23000b20,param_1,param_2);
    iVar1 = (uint)(iVar1 == 0) << 1;
  }
  else {
    if (param_2 < 0x21) {
      local_3a = (undefined2)param_2;
      local_3c = 0x5c;
      FUN_0e06f35c(auStack_38,param_1,param_2);
      iVar1 = FUN_0e06cbdc(&DAT_23001c04,&local_3c,param_3,param_4);
      if (iVar1 == 0) {
        if (DAT_23000b28 != 1) {
          return 0;
        }
        uVar2 = FUN_0e06d43c(&DAT_23007000);
        return (uVar2 >> 0x1f) << 1;
      }
    }
    iVar1 = 2;
  }
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b014. Types and names are inferred; NOT original source. */

void FUN_0e06b014(undefined4 param_1,undefined4 param_2)

{
  FUN_0e06af94(param_1,param_2,0,0,0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b064. Types and names are inferred; NOT original source. */

void FUN_0e06b064(void)

{
  int extraout_r2;
  
  FUN_0e05d698(0);
  if (extraout_r2 == 0) {
    return;
  }
  FUN_0e06b064();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b06c. Types and names are inferred; NOT original source. */

void FUN_0e06b06c(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    return;
  }
  FUN_0e06b064();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b078. Types and names are inferred; NOT original source. */

void FUN_0e06b078(int param_1,uint param_2)

{
  undefined1 auStack_28 [32];
  
  if (0x20 < param_2) {
    FUN_0e06b06c(1,0);
    return;
  }
  if (param_1 != 0) {
    FUN_0e06f35c(auStack_28,param_1,param_2);
    FUN_0e06aef0(auStack_28,param_2);
    return;
  }
  FUN_0e06b06c(4,0,0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b0c0. Types and names are inferred; NOT original source. */

int FUN_0e06b0c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_0e06d3f0(&DAT_23007000,0xe06af25,param_3,param_4,param_4);
  iVar1 = FUN_0e05ed80(DAT_23000b18);
  if ((iVar1 < 0) && (iVar1 != -0x78)) {
    FUN_0e06b06c(5,iVar1,0);
    return iVar1;
  }
  iVar1 = FUN_0e05ed9c(DAT_23000b18,&DAT_23000b20,DAT_23000b1c);
  if (-1 < iVar1) {
    return iVar1;
  }
  FUN_0e06b06c(6,iVar1,0);
  return iVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b11c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e06b11c(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  iVar2 = param_1[8];
  if (iVar2 == 0) {
    if (_NMI <= _Reset) {
      if ((MemManage != '\0') && (_HardFault != 0)) {
        return 0;
      }
      goto LAB_0e06b19a;
    }
  }
  else {
    if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
      return 0;
    }
    if (*(uint *)(iVar2 + 8) <= *(uint *)(iVar2 + 4)) {
LAB_0e06b19a:
      *(undefined4 *)(iVar2 + 0xc) = 1;
      return 0;
    }
  }
  *(undefined1 *)(param_1 + 4) = 0;
  *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + 1;
  puVar3 = (undefined4 *)(*(int *)param_1[8] + (((int *)param_1[8])[1] + -1) * 0x24);
  puVar4 = param_1;
  do {
    uVar6 = *puVar4;
    uVar5 = puVar4[1];
    uVar7 = puVar4[2];
    uVar1 = puVar4[3];
    puVar4 = puVar4 + 4;
    *puVar3 = uVar6;
    puVar3[1] = uVar5;
    puVar3[2] = uVar7;
    puVar3[3] = uVar1;
    puVar3 = puVar3 + 4;
  } while (puVar4 != param_1 + 8);
  *puVar3 = *puVar4;
  param_1[2] = param_2;
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b1a4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0e06b1a4(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  piVar9 = (int *)param_1[8];
  if (piVar9 == (int *)0x0) {
    uVar8 = *param_1;
    uVar7 = param_1[2];
    local_30 = param_1[5];
    uStack_2c = param_1[6];
    uStack_28 = param_1[7];
    iVar5 = _Reset;
    if (_Reset != 0) goto LAB_0e06b1ee;
    if ((MemManage != '\0') && (_HardFault != 0)) {
      return 0;
    }
  }
  else {
    if (((char)piVar9[4] != '\0') && (piVar9[3] != 0)) {
      return 0;
    }
    local_30 = param_1[5];
    uStack_2c = param_1[6];
    uStack_28 = param_1[7];
    uVar8 = *param_1;
    uVar7 = param_1[2];
    iVar5 = piVar9[1];
    if (piVar9[1] != 0) {
LAB_0e06b1ee:
      if ((param_2 & 1) != 0) {
        puVar4 = (undefined4 *)(*piVar9 + (iVar5 + -1) * 0x24);
        if (((param_2 & 4) == 0) && (*(char *)(puVar4 + 4) != '\0')) {
          if (((char)piVar9[4] != '\0') && (piVar9[3] != 0)) {
            return 0;
          }
          piVar9[3] = 0xf;
          return 0;
        }
        puVar11 = puVar4 + 8;
        puVar3 = param_1;
        do {
          uVar10 = *puVar4;
          uVar6 = puVar4[1];
          uVar1 = puVar4[2];
          uVar2 = puVar4[3];
          puVar4 = puVar4 + 4;
          *puVar3 = uVar10;
          puVar3[1] = uVar6;
          puVar3[2] = uVar1;
          puVar3[3] = uVar2;
          puVar3 = puVar3 + 4;
        } while (puVar4 != puVar11);
        *puVar3 = *puVar4;
      }
      if ((param_2 & 2) != 0) {
        *(int *)(param_1[8] + 4) = *(int *)(param_1[8] + 4) + -1;
      }
      if (param_3 < uVar7) {
        iVar5 = param_1[8];
        if (iVar5 == 0) {
          return 0;
        }
        if ((*(char *)(iVar5 + 0x10) != '\0') && (*(int *)(iVar5 + 0xc) != 0)) {
          return 0;
        }
        *(undefined4 *)(iVar5 + 0xc) = 4;
        return 0;
      }
      if ((param_2 & 4) != 0) {
        *param_1 = uVar8;
      }
      if ((param_2 & 8) != 0) {
        param_1[5] = local_30;
        param_1[6] = uStack_2c;
        param_1[7] = uStack_28;
      }
      return 1;
    }
  }
  piVar9[3] = 2;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b2e8. Types and names are inferred; NOT original source. */

void FUN_0e06b2e8(int param_1)

{
  FUN_0e06b11c(param_1,*(undefined4 *)(param_1 + 8));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b2f0. Types and names are inferred; NOT original source. */

void FUN_0e06b2f0(int param_1)

{
  FUN_0e06b1a4(param_1,1,*(undefined4 *)(param_1 + 8));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b2f8. Types and names are inferred; NOT original source. */

void FUN_0e06b2f8(int param_1)

{
  FUN_0e06b1a4(param_1,2,*(undefined4 *)(param_1 + 8));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b300. Types and names are inferred; NOT original source. */

void FUN_0e06b300(int *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  param_1[3] = param_4 + param_3;
  *param_1 = param_3;
  param_1[2] = param_5;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[6] = 0;
  if (1 < param_2) {
    param_1[8] = (int)(param_1 + param_2 * 9 + -9);
    param_1[param_2 * 9 + -9] = 0;
    *(uint *)(param_1[8] + 8) = param_2 - 2;
    *(undefined4 *)(param_1[8] + 4) = 0;
    *(undefined4 *)(param_1[8] + 0xc) = 0;
    *(undefined1 *)(param_1[8] + 0x10) = 0;
    *(undefined1 *)(param_1[8] + 0x11) = 1;
    *(undefined1 *)(param_1[8] + 0x12) = 0;
    if (param_2 != 2) {
      *(int **)param_1[8] = param_1 + 9;
    }
    return;
  }
  param_1[8] = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b358. Types and names are inferred; NOT original source. */

undefined8 FUN_0e06b358(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  uint local_18;
  uint uStack_14;
  
  local_18 = 0;
  uStack_14 = 0;
  if (param_2 < 9) {
    FUN_0e06f35c(&local_18,param_1,param_2);
    if (uStack_14 == 0 && (0x17 < local_18) <= uStack_14) {
      return CONCAT44(uStack_14 - (0x17 >= local_18),1);
    }
    param_2 = uStack_14 - (0xff >= local_18);
    if (uStack_14 == 0 && (0xff < local_18) <= uStack_14) {
      uVar1 = 2;
    }
    else {
      if (uStack_14 != 0 || uStack_14 < (0xffff < local_18)) {
        if (uStack_14 == 0) {
          uVar1 = 5;
        }
        else {
          uVar1 = 9;
        }
        return CONCAT44(param_2,uVar1);
      }
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 0;
  }
  return CONCAT44(param_2,uVar1);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b3b4. Types and names are inferred; NOT original source. */

int FUN_0e06b3b4(int param_1,uint param_2,int *param_3,uint *param_4,int *param_5,code *param_6,
                uint param_7,int param_8)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  param_5[2] = param_8;
  *(undefined1 *)(param_5 + 4) = 0;
  *(undefined1 *)(param_5 + 5) = 0;
  param_5[6] = 0;
  *param_5 = param_1;
  param_5[3] = param_1 + param_2;
  if (param_7 < 2) {
    param_5[8] = 0;
    piVar3 = param_3;
  }
  else {
    param_5[8] = (int)(param_5 + param_7 * 9 + -9);
    param_5[param_7 * 9 + -9] = 0;
    *(uint *)(param_5[8] + 8) = param_7 - 2;
    *(undefined4 *)(param_5[8] + 4) = 0;
    *(undefined4 *)(param_5[8] + 0xc) = 0;
    *(undefined1 *)(param_5[8] + 0x10) = 0;
    *(undefined1 *)(param_5[8] + 0x11) = 1;
    *(undefined1 *)(param_5[8] + 0x12) = 0;
    piVar3 = (int *)0x1;
    if (param_7 != 2) {
      *(int **)param_5[8] = param_5 + 9;
      piVar3 = param_5 + 9;
    }
  }
  iVar1 = (*param_6)(param_5,param_3,piVar3,param_6,param_4);
  if (iVar1 == 0) {
    iVar1 = param_5[8];
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0xc);
      *(undefined4 *)(iVar1 + 0xc) = 0;
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    return 0x1f;
  }
  if (param_4 != (uint *)0x0) {
    uVar4 = *param_5 - param_1;
    if (param_2 <= (uint)(*param_5 - param_1)) {
      uVar4 = param_2;
    }
    *param_4 = uVar4;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b44c. Types and names are inferred; NOT original source. */

int FUN_0e06b44c(int param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar2 = 0;
  pcVar1 = (char *)(param_1 + -1);
  do {
    pcVar1 = pcVar1 + 1;
    if (*pcVar1 == '\0') {
      return iVar2;
    }
    iVar2 = iVar2 + 1;
  } while (param_2 != iVar2);
  return param_2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b470. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06b470(int *param_1,byte *param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  char cVar10;
  
  iVar1 = param_1[8];
  if (iVar1 != 0) {
    cVar10 = *(char *)(iVar1 + 0x10);
    if (cVar10 != '\0') {
      if (*(int *)(iVar1 + 0xc) != 0) {
        return 0;
      }
      pbVar2 = (byte *)*param_1;
      pbVar8 = (byte *)param_1[3];
      if (pbVar8 <= pbVar2) goto LAB_0e06b5b2;
      if (param_1[2] == 0) goto LAB_0e06b5ca;
      bVar4 = *pbVar2;
      bVar5 = bVar4 & 0x1f;
      if (bVar5 != 0x1f) goto LAB_0e06b4a8;
      if (param_4 != (undefined1 *)0x0) goto LAB_0e06b58a;
LAB_0e06b4f2:
      if ((cVar10 != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
LAB_0e06b4fc:
      *(undefined4 *)(iVar1 + 0xc) = 7;
      return 0;
    }
    pbVar8 = (byte *)param_1[3];
    pbVar2 = (byte *)*param_1;
    if (pbVar8 <= pbVar2) goto LAB_0e06b5b2;
    if (param_1[2] == 0) {
LAB_0e06b5ca:
      *(undefined4 *)(iVar1 + 0xc) = 3;
      return 0;
    }
    bVar4 = *pbVar2;
    bVar5 = bVar4 & 0x1f;
    if (bVar5 != 0x1f) goto LAB_0e06b4a8;
    if (param_4 == (undefined1 *)0x0) goto LAB_0e06b4fc;
LAB_0e06b58a:
    if (*(char *)(iVar1 + 0x11) != '\0') {
      if ((cVar10 != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar1 + 0xc) = 0x15;
      return 0;
    }
    *param_4 = 1;
LAB_0e06b592:
    iVar6 = 1;
LAB_0e06b594:
    iVar1 = *param_1;
    *param_1 = iVar6 + iVar1;
    param_1[1] = iVar1;
    param_1[2] = param_1[2] + -1;
    return 1;
  }
  pbVar2 = (byte *)*param_1;
  pbVar8 = (byte *)param_1[3];
  if (pbVar8 <= pbVar2) {
    return 0;
  }
  if (param_1[2] == 0) {
    return 0;
  }
  bVar4 = *pbVar2;
  bVar5 = bVar4 & 0x1f;
  if (bVar5 == 0x1f) {
    return 0;
  }
LAB_0e06b4a8:
  if (bVar5 < 0x18) {
    if (pbVar2 + 1 <= pbVar8) {
      FUN_0e06f3aa(param_2,0);
      *param_2 = bVar5;
      goto LAB_0e06b592;
    }
  }
  else {
    if (3 < (byte)(bVar5 - 0x18)) {
      if (iVar1 == 0) {
        return 0;
      }
      cVar10 = *(char *)(iVar1 + 0x10);
      goto LAB_0e06b4f2;
    }
    uVar7 = 1 << (uint)(byte)(bVar5 - 0x18);
    if (param_3 < uVar7) {
      if (iVar1 == 0) {
        return 0;
      }
      if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar1 + 0xc) = 5;
      return 0;
    }
    iVar6 = uVar7 + 1;
    if (pbVar2 + iVar6 <= pbVar8) {
      FUN_0e06f3aa(param_2,0);
      pbVar9 = (byte *)*param_1;
      pbVar2 = param_2 + -1;
      pbVar8 = pbVar9 + uVar7;
      do {
        pbVar3 = pbVar8 + -1;
        pbVar2 = pbVar2 + 1;
        *pbVar2 = *pbVar8;
        pbVar8 = pbVar3;
      } while (pbVar9 != pbVar3);
      if ((((param_1[8] == 0) || (*(char *)(param_1[8] + 0x11) != '\0')) && (2 < (byte)(bVar4 + 7)))
         && (iVar1 = FUN_0e06b358(param_2,param_3), iVar6 != iVar1)) {
        iVar1 = param_1[8];
        if (iVar1 == 0) {
          return 0;
        }
        if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
          return 0;
        }
        *(undefined4 *)(iVar1 + 0xc) = 0x15;
        return 0;
      }
      goto LAB_0e06b594;
    }
  }
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
    return 0;
  }
LAB_0e06b5b2:
  *(undefined4 *)(iVar1 + 0xc) = 8;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b6a8. Types and names are inferred; NOT original source. */

int FUN_0e06b6a8(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = param_1[8];
  if (iVar3 == 0) {
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      return 0;
    }
    bVar1 = *(byte *)*param_1;
    if (0x3f < bVar1) {
      return 0;
    }
    iVar3 = FUN_0e06b470(param_1,param_2,4,0,param_4);
  }
  else {
    if (*(char *)(iVar3 + 0x10) == '\0') {
      pbVar2 = (byte *)*param_1;
      if ((byte *)param_1[3] <= pbVar2) {
LAB_0e06b672:
        *(undefined4 *)(iVar3 + 0xc) = 8;
        return 0;
      }
    }
    else {
      if (*(int *)(iVar3 + 0xc) != 0) {
        return 0;
      }
      pbVar2 = (byte *)*param_1;
      if ((byte *)param_1[3] <= pbVar2) goto LAB_0e06b672;
    }
    bVar1 = *pbVar2;
    if (0x3f < bVar1) {
      if ((*(char *)(iVar3 + 0x10) != '\0') && (*(int *)(iVar3 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar3 + 0xc) = 10;
      return 0;
    }
    iVar3 = FUN_0e06b470(param_1,param_2,4,0,param_4);
  }
  if (iVar3 != 0) {
    if (-1 < *(char *)(param_2 + 3)) {
      if (bVar1 >> 5 != 1) {
        return iVar3;
      }
      pbVar2 = (byte *)(param_2 + -1);
      do {
        pbVar2 = pbVar2 + 1;
        *pbVar2 = ~*pbVar2;
      } while (pbVar2 != (byte *)(param_2 + 3));
      return iVar3;
    }
    iVar3 = param_1[8];
    *param_1 = param_1[1];
    param_1[2] = param_1[2] + 1;
    if ((iVar3 != 0) && ((*(char *)(iVar3 + 0x10) == '\0' || (*(int *)(iVar3 + 0xc) == 0)))) {
      *(undefined4 *)(iVar3 + 0xc) = 5;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b6b0. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06b6b0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1[8];
  if (iVar2 == 0) {
    if (((byte *)*param_1 < (byte *)param_1[3]) && (*(byte *)*param_1 >> 5 == 0)) {
      uVar1 = FUN_0e06b470(param_1,param_2,4,0);
      return uVar1;
    }
    return 0;
  }
  if ((*(char *)(iVar2 + 0x10) == '\0') || (*(int *)(iVar2 + 0xc) == 0)) {
    if ((byte *)*param_1 < (byte *)param_1[3]) {
      if (*(byte *)*param_1 >> 5 == 0) {
        uVar1 = FUN_0e06b470(param_1,param_2,4,0);
        return uVar1;
      }
      if ((*(char *)(iVar2 + 0x10) == '\0') || (*(int *)(iVar2 + 0xc) == 0)) {
        *(undefined4 *)(iVar2 + 0xc) = 10;
        return 0;
      }
    }
    else {
      *(undefined4 *)(iVar2 + 0xc) = 8;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b7a4. Types and names are inferred; NOT original source. */

int FUN_0e06b7a4(undefined4 *param_1,int param_2)

{
  int iVar1;
  int local_18;
  int iStack_14;
  
  iVar1 = param_1[8];
  if (iVar1 == 0) {
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 0) {
      return 0;
    }
  }
  else {
    if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
      return 0;
    }
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      *(undefined4 *)(iVar1 + 0xc) = 8;
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 0) {
      if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar1 + 0xc) = 10;
      return 0;
    }
  }
  iVar1 = FUN_0e06b470(param_1,&local_18,8,0);
  if (iVar1 != 0) {
    if (iStack_14 == 0 && local_18 == param_2) {
      return iVar1;
    }
    iVar1 = param_1[8];
    *param_1 = param_1[1];
    param_1[2] = param_1[2] + 1;
    if ((iVar1 != 0) && ((*(char *)(iVar1 + 0x10) == '\0' || (*(int *)(iVar1 + 0xc) == 0)))) {
      *(undefined4 *)(iVar1 + 0xc) = 0xb;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b7ac. Types and names are inferred; NOT original source. */

int FUN_0e06b7ac(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[8];
  if (iVar2 == 0) {
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 2) {
      return 0;
    }
  }
  else {
    if (*(char *)(iVar2 + 0x10) == '\0') {
      pbVar1 = (byte *)*param_1;
      if ((byte *)param_1[3] <= pbVar1) {
LAB_0e06b7f8:
        *(undefined4 *)(iVar2 + 0xc) = 8;
        return 0;
      }
    }
    else {
      if (*(int *)(iVar2 + 0xc) != 0) {
        return 0;
      }
      pbVar1 = (byte *)*param_1;
      if ((byte *)param_1[3] <= pbVar1) goto LAB_0e06b7f8;
    }
    if (*pbVar1 >> 5 != 2) {
      if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar2 + 0xc) = 10;
      return 0;
    }
  }
  iVar2 = FUN_0e06b470(param_1,param_2 + 1,4,0,param_4);
  if (iVar2 != 0) {
    iVar3 = *param_1;
    *param_2 = iVar3;
    if ((uint)param_2[1] <= (uint)(param_1[3] - iVar3)) {
      *param_1 = iVar3 + param_2[1];
      return iVar2;
    }
    iVar2 = param_1[8];
    *param_1 = param_1[1];
    param_1[2] = param_1[2] + 1;
    if ((iVar2 != 0) && ((*(char *)(iVar2 + 0x10) == '\0' || (*(int *)(iVar2 + 0xc) == 0)))) {
      *(undefined4 *)(iVar2 + 0xc) = 8;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b844. Types and names are inferred; NOT original source. */

int FUN_0e06b844(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  char local_15;
  undefined4 local_14 [2];
  
  local_15 = '\0';
  iVar2 = param_1[8];
  if (iVar2 == 0) {
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 4) {
      return 0;
    }
  }
  else {
    if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
      return 0;
    }
    if ((byte *)param_1[3] <= (byte *)*param_1) {
      *(undefined4 *)(iVar2 + 0xc) = 8;
      return 0;
    }
    if (*(byte *)*param_1 >> 5 != 4) {
      if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
        return 0;
      }
      *(undefined4 *)(iVar2 + 0xc) = 10;
      return 0;
    }
  }
  iVar2 = FUN_0e06b470(param_1,local_14,4,&local_15);
  cVar1 = local_15;
  if (iVar2 != 0) {
    if (local_15 == '\0') {
      iVar2 = FUN_0e06b11c(param_1,local_14[0]);
    }
    else {
      iVar2 = FUN_0e06b11c(param_1,0xfffffff0);
    }
    if (iVar2 != 0) {
      *(char *)(param_1 + 5) = cVar1;
      return iVar2;
    }
    *param_1 = param_1[1];
    param_1[2] = param_1[2] + 1;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b8dc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06b8dc(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  uVar2 = 0;
  if (*(char *)(param_1 + 5) != '\0') {
    iVar1 = param_1[8];
    if (iVar1 == 0) {
      pcVar3 = (char *)*param_1;
      if ((char *)param_1[3] <= pcVar3) {
        return 0;
      }
      if (*pcVar3 != -1) {
        return 0;
      }
    }
    else {
      if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
        return 0;
      }
      pcVar3 = (char *)*param_1;
      if ((char *)param_1[3] <= pcVar3) {
        *(undefined4 *)(iVar1 + 0xc) = 8;
        return 0;
      }
      if (*pcVar3 != -1) {
        if ((*(char *)(iVar1 + 0x10) != '\0') && (*(int *)(iVar1 + 0xc) != 0)) {
          return 0;
        }
        *(undefined4 *)(iVar1 + 0xc) = 10;
        return 0;
      }
    }
    uVar2 = 0xffffffff;
    *param_1 = pcVar3 + 1;
    *(undefined1 *)(param_1 + 5) = 0;
  }
  uVar2 = FUN_0e06b1a4(param_1,7,uVar2);
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b940. Types and names are inferred; NOT original source. */

void FUN_0e06b940(undefined4 param_1)

{
  FUN_0e06b1a4(param_1,7,0xffffffff);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b94c. Types and names are inferred; NOT original source. */

undefined4
FUN_0e06b94c(uint param_1,uint param_2,uint *param_3,code *param_4,undefined4 *param_5,int param_6,
            int param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = param_5[8];
  if (((iVar1 == 0) || (*(char *)(iVar1 + 0x10) == '\0')) || (*(int *)(iVar1 + 0xc) == 0)) {
    if (param_2 != 0) {
      uVar4 = 0;
      do {
        uVar3 = *param_5;
        uVar2 = param_5[2];
        iVar1 = (*param_4)(param_5,param_6);
        param_6 = param_6 + param_7;
        if (iVar1 == 0) {
          *param_3 = uVar4;
          *param_5 = uVar3;
          param_5[2] = uVar2;
          if (param_1 <= uVar4) goto LAB_0e06b9a2;
          iVar1 = param_5[8];
          if ((iVar1 != 0) && ((*(char *)(iVar1 + 0x10) == '\0' || (*(int *)(iVar1 + 0xc) == 0)))) {
            *(undefined4 *)(iVar1 + 0xc) = 0xd;
          }
          goto LAB_0e06b9b0;
        }
        uVar4 = uVar4 + 1;
      } while (param_2 != uVar4);
    }
    *param_3 = param_2;
LAB_0e06b9a2:
    uVar2 = 1;
  }
  else {
LAB_0e06b9b0:
    uVar2 = 0;
  }
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b9d4. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06b300(int *param_1,uint param_2,int param_3,int param_4,int param_5)

{
  param_1[3] = param_4 + param_3;
  *param_1 = param_3;
  param_1[2] = param_5;
  *(undefined1 *)(param_1 + 4) = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[6] = 0;
  if (1 < param_2) {
    param_1[8] = (int)(param_1 + param_2 * 9 + -9);
    param_1[param_2 * 9 + -9] = 0;
    *(uint *)(param_1[8] + 8) = param_2 - 2;
    *(undefined4 *)(param_1[8] + 4) = 0;
    *(undefined4 *)(param_1[8] + 0xc) = 0;
    *(undefined1 *)(param_1[8] + 0x10) = 0;
    *(undefined1 *)(param_1[8] + 0x11) = 1;
    *(undefined1 *)(param_1[8] + 0x12) = 0;
    if (param_2 != 2) {
      *(int **)param_1[8] = param_1 + 9;
    }
    return;
  }
  param_1[8] = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06b9d8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06b9d8(int *param_1,char param_2,byte *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = (byte *)*param_1;
  pbVar4 = (byte *)param_1[3];
  iVar2 = param_1[8];
  if (pbVar3 + param_4 + 1 <= pbVar4) {
    bVar1 = *param_3;
    if (param_4 != 0) {
      if (param_4 - 2U < 7) {
        bVar1 = "ipc_to_sysctrl"[param_4 + 0xe] + 0x18;
      }
      else {
        bVar1 = 0x18;
      }
    }
    if (iVar2 == 0) {
      if (pbVar4 <= pbVar3) {
        return 0;
      }
    }
    else {
      if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
        return 0;
      }
      if (pbVar4 <= pbVar3) goto LAB_0e06ba70;
    }
    *pbVar3 = bVar1 & 0x1f | param_2 << 5;
    iVar2 = *param_1;
    if (param_4 == 0) {
      *param_1 = iVar2 + 1;
    }
    else {
      param_4 = param_4 + -1;
      *param_1 = iVar2 + 2;
      pbVar3 = param_3 + param_4;
      *(byte *)(iVar2 + 1) = param_3[param_4];
      if (param_4 != 0) {
        do {
          pbVar4 = (byte *)*param_1;
          *param_1 = (int)(pbVar4 + 1);
          pbVar3 = pbVar3 + -1;
          *pbVar4 = *pbVar3;
        } while (pbVar3 != param_3);
      }
    }
    param_1[2] = param_1[2] + 1;
    return 1;
  }
  if (iVar2 == 0) {
    return 0;
  }
  if ((*(char *)(iVar2 + 0x10) != '\0') && (*(int *)(iVar2 + 0xc) != 0)) {
    return 0;
  }
LAB_0e06ba70:
  *(undefined4 *)(iVar2 + 0xc) = 8;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bbb0. Types and names are inferred; NOT original source. */

void FUN_0e06bbb0(undefined4 param_1,uint *param_2)

{
  int iVar1;
  bool bVar2;
  uint local_18 [2];
  
  bVar2 = *(char *)((int)param_2 + 3) < '\0';
  if (bVar2) {
    local_18[0] = ~*param_2;
    param_2 = local_18;
  }
  iVar1 = FUN_0e06b358(param_2,4);
  FUN_0e06b9d8(param_1,bVar2,param_2,iVar1 + -1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bbe8. Types and names are inferred; NOT original source. */

void FUN_0e06bbe8(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0e06b358(param_2,4);
  FUN_0e06b9d8(param_1,0,param_2,iVar1 + -1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bc08. Types and names are inferred; NOT original source. */

void FUN_0e06bc08(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = param_2;
  iVar1 = FUN_0e06b358(&local_c,4);
  FUN_0e06b9d8(param_1,0,&local_c,iVar1 + -1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bc2c. Types and names are inferred; NOT original source. */

int FUN_0e06bc2c(uint *param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  if ((*param_1 < param_1[3]) && (uVar2 = param_2[1], uVar2 <= param_1[3] - *param_1)) {
    puVar4 = param_2 + 1;
    uVar3 = 0;
    if (*param_2 != 0) {
      iVar1 = FUN_0e06b358(puVar4,4,uVar2,*param_2,param_4);
      uVar2 = param_1[3];
      uVar3 = *param_1 + param_2[1] + iVar1;
      if (uVar2 < uVar3) goto LAB_0e06baf6;
    }
    iVar1 = FUN_0e06b358(puVar4,4,uVar2,uVar3,param_4);
    iVar1 = FUN_0e06b9d8(param_1,2,puVar4,iVar1 + -1);
    if (iVar1 != 0) {
      uVar2 = *param_2;
      if (*param_1 != uVar2) {
        FUN_0e06f376(*param_1,uVar2,param_2[1]);
        uVar2 = *param_1;
      }
      *param_1 = uVar2 + param_2[1];
      return iVar1;
    }
  }
  else {
LAB_0e06baf6:
    uVar2 = param_1[8];
    if ((uVar2 != 0) && ((*(char *)(uVar2 + 0x10) == '\0' || (*(int *)(uVar2 + 0xc) == 0)))) {
      *(undefined4 *)(uVar2 + 0xc) = 8;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bc34. Types and names are inferred; NOT original source. */

int FUN_0e06bc34(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_c;
  
  local_c = param_2;
  iVar1 = FUN_0e06b11c(param_1,0);
  if (iVar1 != 0) {
    iVar1 = FUN_0e06b358(&local_c);
    iVar1 = FUN_0e06b9d8(param_1,4,&local_c,iVar1 + -1);
    if (iVar1 != 0) {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
      return iVar1;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bc74. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e06bb22) */

int FUN_0e06bc74(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_24 [2];
  int local_1c;
  
  local_1c = param_1[2];
  iVar4 = *param_1;
  local_24[0] = param_2;
  iVar1 = FUN_0e06b358(local_24);
  iVar2 = FUN_0e06b358(&local_1c,4);
  iVar3 = FUN_0e06b1a4(param_1,3,0xffffffff);
  if (iVar3 != 0) {
    if (iVar1 - 1U < iVar2 - 1U) {
      iVar1 = param_1[8];
      if ((iVar1 != 0) && ((*(char *)(iVar1 + 0x10) == '\0' || (*(int *)(iVar1 + 0xc) == 0)))) {
        *(undefined4 *)(iVar1 + 0xc) = 4;
      }
    }
    else {
      iVar3 = FUN_0e06b358(&local_1c,4);
      iVar3 = FUN_0e06b9d8(param_1,4,&local_1c,iVar3 + -1);
      if (iVar3 != 0) {
        if (iVar1 != iVar2) {
          iVar1 = (iVar1 - iVar2) + *param_1;
          iVar4 = iVar4 - iVar1;
          FUN_0e06f376(*param_1,iVar1,iVar4);
          iVar4 = iVar4 + *param_1;
        }
        *param_1 = iVar4;
        return iVar3;
      }
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bc7c. Types and names are inferred; NOT original source. */

void FUN_0e06bc7c(undefined4 param_1)

{
  FUN_0e06b1a4(param_1,3,0xffffffff);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bc88. Types and names are inferred; NOT original source. */

void FUN_0e06bc88(undefined4 param_1,char *param_2)

{
  int iVar1;
  char local_9;
  
  local_9 = *param_2 + '\x14';
  iVar1 = FUN_0e06b358(&local_9,1);
  FUN_0e06b9d8(param_1,7,&local_9,iVar1 + -1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bcb8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06bcb8(int param_1,code *param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_3 + 0x20);
  if (((iVar2 != 0) && (*(char *)(iVar2 + 0x10) != '\0')) && (*(int *)(iVar2 + 0xc) != 0)) {
    return 0;
  }
  if (param_1 != 0) {
    iVar2 = 0;
    do {
      iVar1 = (*param_2)(param_3,param_4);
      iVar2 = iVar2 + 1;
      param_4 = param_4 + param_5;
      if (iVar1 == 0) {
        return 0;
      }
    } while (param_1 != iVar2);
  }
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bcfc. Types and names are inferred; NOT original source. */

undefined4
FUN_0e06bcfc(uint param_1,uint param_2,uint *param_3,undefined4 param_4,int param_5,
            undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *param_3;
  if ((param_1 <= uVar3) && (uVar3 <= param_2)) {
    uVar1 = FUN_0e06bcb8(uVar3,param_4,param_5,param_6);
    return uVar1;
  }
  iVar2 = *(int *)(param_5 + 0x20);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x10) == '\0') {
      *(undefined4 *)(iVar2 + 0xc) = 0xd;
    }
    else if (*(int *)(iVar2 + 0xc) == 0) {
      *(undefined4 *)(iVar2 + 0xc) = 0xd;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bd40. Types and names are inferred; NOT original source. */

void FUN_0e06bd40(void)

{
  FUN_0e06b300();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bd58. Types and names are inferred; NOT original source. */

void FUN_0e06bd58(int param_1,int param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_2 != 0) {
    UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(param_1 + 0xc) + 0x10);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      FUN_0e06d0d0(*(int *)(param_1 + 8) + 4);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0e06bd6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*UNRECOVERED_JUMPTABLE)(*(int **)(param_1 + 0xc),param_2 + -5);
      return;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bd78. Types and names are inferred; NOT original source. */

void FUN_0e06bd78(int param_1,int *param_2,int param_3)

{
  int iVar1;
  code *pcVar2;
  uint local_14 [2];
  
  *param_2 = 0;
  if (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0') {
    pcVar2 = *(code **)(**(int **)(param_1 + 0xc) + 8);
    if (((pcVar2 != (code *)0x0) &&
        (local_14[0] = param_3 + 5U, iVar1 = (*pcVar2)(*(int **)(param_1 + 0xc),local_14),
        iVar1 != 0)) && (param_3 + 5U <= local_14[0])) {
      *param_2 = iVar1 + 5;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bda8. Types and names are inferred; NOT original source. */

void FUN_0e06bda8(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar4;
  undefined1 *local_1c;
  
  uVar1 = **(undefined2 **)(param_1 + 8);
  iVar2 = FUN_0e05ba68(*(undefined4 *)(param_1 + 0x18));
  FUN_0e06bd78(param_1,&local_1c,iVar2 + 1);
  if (local_1c != (undefined1 *)0x0) {
    *(undefined2 *)(local_1c + -2) = uVar1;
    *(undefined2 *)(local_1c + -5) = 4;
    local_1c[-3] = 0xff;
    *local_1c = 0;
    uVar4 = *(undefined4 *)(param_1 + 0x18);
    uVar3 = FUN_0e05ba68(uVar4);
    FUN_0e06f35c(local_1c + 1,uVar4,uVar3);
    if (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0') {
      UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(param_1 + 0xc) + 4);
      if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0e06be10. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(*(int **)(param_1 + 0xc),local_1c + -5,iVar2 + 6);
        return;
      }
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06be18. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e06bf24) */

int FUN_0e06be18(undefined4 param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 extraout_r1;
  char cVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  int *piVar9;
  undefined8 uVar10;
  
  if (DAT_230071ec == '\0') {
    pcVar1 = &DAT_230004fc;
    cVar6 = '\0';
    cVar4 = '\0';
    puVar8 = &DAT_0e07267c;
    DAT_23007034 = param_1;
    while( true ) {
      *pcVar1 = cVar6;
      if (*(int *)(puVar8 + 0x24) << 0x1f < 0) {
        cVar4 = cVar4 + '\x01';
      }
      cVar6 = cVar6 + '\x01';
      if ((undefined *)0xe0726a3 < puVar8 + 0x28) break;
      pcVar1 = *(char **)(puVar8 + 0x30);
      puVar8 = puVar8 + 0x28;
      if (cVar6 == -1) {
        return -0xc;
      }
    }
    DAT_230071ee = cVar4;
    DAT_230071ef = cVar6;
    FUN_0e06f3aa(&DAT_23007048,0,0x120);
    iVar2 = FUN_0e068608(&LAB_0e06c604_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0e06d0b4(&DAT_23007038,0,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_0e06d0b4(&DAT_23007010,0,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = 0;
    puVar8 = &DAT_23007054;
    do {
      puVar8[-0xc] = (char)iVar2;
      iVar3 = FUN_0e06d0b4(puVar8,0,1);
      iVar2 = iVar2 + 1;
      puVar8 = puVar8 + 0x24;
      if (iVar3 < 0) {
        return iVar3;
      }
    } while (iVar2 != 8);
    puVar8 = &DAT_0e07267c;
    do {
      piVar9 = *(int **)(puVar8 + 0xc);
      puVar7 = (undefined4 *)*piVar9;
      if (puVar7[4] == 0) {
        uVar10 = FUN_0e06d0b4(*(int *)(puVar8 + 8) + 4,0,1);
        uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
        if (-1 < (int)uVar10) {
          puVar7 = (undefined4 *)*piVar9;
          goto LAB_0e06bedc;
        }
      }
      else {
LAB_0e06bedc:
        uVar10 = (*(code *)*puVar7)(piVar9,0xe06c079,0);
        uVar5 = (undefined4)((ulonglong)uVar10 >> 0x20);
        if (((int)uVar10 == 0) &&
           (*(undefined1 *)(*(int *)(puVar8 + 8) + 0x14) = 1, *(int *)(puVar8 + 0x24) << 0x1e < 0))
        {
          FUN_0e06bda8(puVar8);
          uVar5 = extraout_r1;
        }
      }
      puVar8 = puVar8 + 0x28;
    } while (puVar8 < &UNK_0e0726a4);
    if ((DAT_230071ee != '\0') &&
       (iVar2 = FUN_0e06d118(&DAT_23007038,uVar5,1000000,0), iVar2 == -0xb)) {
      return -0x23;
    }
    DAT_230071ec = '\x01';
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06bf74. Types and names are inferred; NOT original source. */

void FUN_0e06bf74(undefined4 *param_1,int param_2,int param_3,undefined1 param_4,undefined1 param_5)

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
      FUN_0e06bd78(param_3,&local_2c);
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
  if (DAT_23007034 != (code *)0x0) {
    (*DAT_23007034)(&local_2c);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c020. Types and names are inferred; NOT original source. */

void FUN_0e06c020(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 param_5)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)(param_4 + 1);
  while( true ) {
    if ((byte *)*param_4 <= pbVar1) {
      FUN_0e06bd58(param_5);
      FUN_0e06bf74(0xfffffffe,0,param_5,param_1);
      return;
    }
    if (*pbVar1 == param_1) break;
    pbVar1 = pbVar1 + 0xc;
  }
                    /* WARNING: Could not recover jumptable at 0x0e06c052. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(pbVar1 + 4))(param_5,param_2,param_3,*(undefined4 *)(pbVar1 + 8));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c078. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */

void FUN_0e06c078(int *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  bool bVar7;
  code *UNRECOVERED_JUMPTABLE;
  int iVar8;
  undefined *puVar9;
  byte bVar10;
  byte bVar11;
  bool bVar12;
  undefined4 uVar13;
  
  if (param_3 < 5) {
    bVar10 = 0xff;
    bVar11 = 0xff;
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      puVar9 = (undefined *)0x0;
      uVar13 = 0xffffffb3;
      bVar10 = 0xff;
      goto LAB_0e06c108;
    }
    uVar13 = 0xffffffb3;
    puVar9 = (undefined *)0x0;
    bVar11 = 0xff;
    goto LAB_0e06c10e;
  }
  bVar11 = *param_2;
  bVar3 = param_2[4];
  bVar1 = param_2[3];
  uVar5 = (uint)param_2[2];
  bVar10 = param_2[1];
  uVar4 = (ushort)bVar3;
  if ((char)*param_2 < '\0') {
    if (bVar3 < DAT_230071ef) {
      puVar9 = &DAT_0e07267c + (short)uVar4 * 0x28;
      *(undefined1 *)((&DAT_0e072684)[(short)uVar4 * 10] + 0x14) = 1;
      if (uVar5 == 0xff) {
switchD_0e06c0c4_default:
        FUN_0e0686a4(param_2,param_3);
        iVar8 = *(int *)(*param_1 + 0x10);
        uVar13 = extraout_r1_01;
      }
      else {
        bVar11 = 0x80;
switchD_0e06c0c4_caseD_1:
        if (7 < uVar5) {
          uVar13 = 0xffffffb3;
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          if (UNRECOVERED_JUMPTABLE != (code *)0x0) goto LAB_0e06c108;
          goto LAB_0e06c10e;
        }
        if (((*(code **)(&DAT_2300704c + uVar5 * 0x24) != (code *)0x0) && (bVar11 == 1)) &&
           (*(int *)(*param_1 + 0x10) == 0)) {
          (**(code **)(&DAT_2300704c + uVar5 * 0x24))
                    (puVar9,param_2 + 5,param_3 - 5,*(undefined4 *)(&DAT_23007050 + uVar5 * 0x24));
          FUN_0e0686c8(&DAT_23007054 + uVar5 * 0x24,1,0);
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          goto joined_r0x0e06c1e2;
        }
        FUN_0e0686c8(&DAT_23007054 + uVar5 * 0x24,param_2);
        iVar8 = *(int *)(*param_1 + 0x10);
        uVar13 = extraout_r1_00;
      }
      if (iVar8 != 0) {
        return;
      }
      puVar9 = (undefined *)(*(int *)(puVar9 + 8) + 4);
      goto LAB_0e06c130;
    }
    bVar11 = 0x80;
LAB_0e06c0fa:
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      uVar13 = 0xffffffb3;
      puVar9 = (undefined *)0x0;
    }
    else {
      puVar9 = (undefined *)0x0;
      uVar13 = 0xffffffb3;
LAB_0e06c108:
      (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
    }
  }
  else {
    if (bVar11 < 4) {
      if (bVar3 < DAT_230071ef) {
        iVar8 = (short)uVar4 * 0x28;
        puVar9 = &DAT_0e07267c + iVar8;
        *(undefined1 *)((&DAT_0e072684)[(short)uVar4 * 10] + 0x14) = 1;
        switch(bVar11) {
        case 1:
          goto switchD_0e06c0c4_caseD_1;
        case 2:
          if (*(code **)(&DAT_0e07268c + iVar8) == (code *)0x0) {
LAB_0e06c282:
            UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          }
          else {
            (**(code **)(&DAT_0e07268c + iVar8))(bVar10,*(undefined4 *)(&DAT_0e072690 + iVar8));
            UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          }
          break;
        case 3:
          if (param_3 < 9) {
            uVar13 = 0xffffffb3;
          }
          else {
            uVar13 = *(undefined4 *)(param_2 + 5);
          }
          FUN_0e06bf74(uVar13,2,puVar9,bVar10,0xff);
          UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
          break;
        default:
          goto switchD_0e06c0c4_default;
        }
joined_r0x0e06c1e2:
        if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
          return;
        }
                    /* WARNING: Could not recover jumptable at 0x0e06c1ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
        return;
      }
      goto LAB_0e06c0fa;
    }
    if ((bVar11 != 4) || (param_3 == 5)) goto LAB_0e06c0fa;
    iVar8 = param_3 - 6;
    if (iVar8 == 0) goto LAB_0e06c0fa;
    if ((param_2[5] & 0xf) != 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
      if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
        uVar13 = 0xffffffd5;
        puVar9 = (undefined *)0x0;
        goto LAB_0e06c10e;
      }
      puVar9 = (undefined *)0x0;
      uVar13 = 0xffffffd5;
      goto LAB_0e06c108;
    }
    puVar9 = &DAT_0e07267c;
    do {
      uVar13 = *(undefined4 *)(puVar9 + 0x18);
      iVar6 = FUN_0e05ba68(uVar13);
      if ((iVar8 == iVar6) && (iVar6 = FUN_0e06f3ba(param_2 + 6,uVar13,iVar8), iVar6 == 0)) {
        cVar2 = *(char *)(*(int *)(puVar9 + 8) + 1);
        *(byte *)(*(int *)(puVar9 + 8) + 1) = bVar1;
        if (cVar2 == -1) {
          bVar12 = bVar3 == 0xff;
          bVar7 = false;
          if ((*(uint *)(puVar9 + 0x24) & 1) != 0) {
            DAT_230071ed = DAT_230071ed + '\x01';
            bVar7 = DAT_230071ee == DAT_230071ed;
          }
        }
        else {
          if (bVar3 != 0xff) goto LAB_0e06c282;
          bVar12 = true;
          bVar7 = false;
        }
        DAT_23007020 = 0;
        DAT_23007028 = CONCAT31(CONCAT12(DAT_23007028._3_1_,CONCAT11(bVar7,bVar12)),cVar2 == -1);
        DAT_23007024 = puVar9;
        FUN_0e0686a4(&DAT_23007020,0x10);
        FUN_0e06d118(&DAT_23007010,extraout_r1_02,0xffffffff,0xffffffff);
        goto LAB_0e06c282;
      }
      puVar9 = puVar9 + 0x28;
    } while (puVar9 < &UNK_0e0726a4);
    UNRECOVERED_JUMPTABLE = *(code **)(*param_1 + 0x10);
    if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
      puVar9 = (undefined *)0x0;
      uVar13 = 0xfffffff2;
      goto LAB_0e06c108;
    }
    uVar13 = 0xfffffff2;
    puVar9 = (undefined *)0x0;
  }
LAB_0e06c10e:
  DAT_2300702d = bVar11;
  DAT_23007020 = 1;
  DAT_23007024 = puVar9;
  DAT_23007028 = uVar13;
  DAT_2300702c = bVar10;
  FUN_0e0686a4(&DAT_23007020,0x10);
  puVar9 = &DAT_23007010;
  uVar13 = extraout_r1;
LAB_0e06c130:
  FUN_0e06d118(puVar9,uVar13,0xffffffff,0xffffffff);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c358. Types and names are inferred; NOT original source. */

byte FUN_0e06c358(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined *puVar9;
  byte bVar10;
  undefined4 *puVar11;
  int local_2c [2];
  
  if (param_3 < 5) {
    bVar10 = 0xff;
  }
  else {
    bVar10 = *param_2;
    bVar1 = param_2[1];
    bVar2 = param_2[4];
    if ((char)*param_2 < '\0') {
      if (bVar2 < DAT_230071ef) {
        puVar11 = (undefined4 *)(&DAT_0e07267c + (short)(ushort)bVar2 * 0x28);
      }
      else {
        puVar11 = (undefined4 *)0x0;
      }
      if (param_1 == 0) {
        iVar6 = FUN_0e068710();
        iVar5 = iVar6 * 0x24;
        *(undefined4 *)(&DAT_2300704c + iVar5) = 0;
        *(undefined2 *)(&DAT_23007049 + iVar6 * 0x24) = 0x1ff;
        FUN_0e06d83c(&DAT_23007048 + iVar5);
        uVar8 = *puVar11;
        (&DAT_23007049)[iVar5] = bVar10 & 0x7f;
        FUN_0e06c020(bVar1,param_2 + 5,param_3 - 5,uVar8,puVar11);
        FUN_0e06d83c(0);
        FUN_0e068754((&DAT_23007048)[iVar6 * 0x24]);
      }
      else {
        *(byte *)(param_1 + 1) = bVar10 & 0x7f;
        FUN_0e06c020(bVar1,param_2 + 5,param_3 - 5,*puVar11,puVar11);
      }
      return 0x80;
    }
    if (bVar10 != 1) {
      if (bVar2 < DAT_230071ef) {
        puVar9 = &DAT_0e07267c + (short)(ushort)bVar2 * 0x28;
      }
      else {
        puVar9 = (undefined *)0x0;
      }
      if (bVar10 == 0) {
        FUN_0e06c020(bVar1,param_2 + 5,param_3 - 5,*(undefined4 *)(puVar9 + 4),puVar9);
        uVar4 = **(undefined1 **)(puVar9 + 8);
        uVar3 = (*(undefined1 **)(puVar9 + 8))[1];
        FUN_0e06bd78(puVar9,local_2c,0);
        iVar5 = -0xc;
        if (local_2c[0] != 0) {
          *(undefined1 *)(local_2c[0] + -2) = uVar4;
          *(byte *)(local_2c[0] + -4) = bVar1;
          *(undefined1 *)(local_2c[0] + -1) = uVar3;
          *(undefined1 *)(local_2c[0] + -3) = 0xff;
          *(undefined1 *)(local_2c[0] + -5) = 2;
          iVar5 = -0x13;
          if (*(char *)(*(int *)(puVar9 + 8) + 0x14) != '\0') {
            pcVar7 = *(code **)(**(int **)(puVar9 + 0xc) + 4);
            if (pcVar7 == (code *)0x0) {
              iVar5 = -5;
            }
            else {
              iVar5 = (*pcVar7)(*(int **)(puVar9 + 0xc),local_2c[0] + -5,5);
              if (-1 < iVar5) {
                return 0;
              }
            }
          }
        }
        FUN_0e06bf74(iVar5,1,puVar9,bVar1,0);
      }
    }
  }
  return bVar10;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c4ac. Types and names are inferred; NOT original source. */

int FUN_0e06c4ac(int param_1,uint param_2,int param_3,int param_4,int *param_5,int *param_6)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *local_34;
  int local_30;
  int local_2c [2];
  
  if ((param_2 & 0x10000) == 0) {
    local_34 = (int *)0x0;
    piVar6 = param_5;
    param_5 = (int *)0x0;
  }
  else {
    local_34 = param_6;
    *param_5 = 0;
    *param_6 = 0;
    param_6 = (int *)0x0;
    piVar6 = (int *)0x0;
  }
  pbVar2 = (byte *)FUN_0e06d848();
  if (pbVar2 == (byte *)0x0) {
    iVar3 = FUN_0e068710();
    pbVar2 = &DAT_23007048 + iVar3 * 0x24;
    *(undefined4 *)(&DAT_2300704c + iVar3 * 0x24) = 0;
    *(undefined2 *)(&DAT_23007049 + iVar3 * 0x24) = 0x1ff;
    FUN_0e06d83c(pbVar2);
  }
  else {
    pbVar2[2] = pbVar2[2] + 1;
  }
  bVar1 = (*(byte **)(param_1 + 8))[1];
  *(uint *)(param_3 + -5) =
       *pbVar2 | 0x80 | (param_2 & 0xff) << 8 | (uint)pbVar2[1] << 0x10 |
       (uint)**(byte **)(param_1 + 8) << 0x18;
  *(byte *)(param_3 + -1) = bVar1;
  uVar8 = *(undefined4 *)(pbVar2 + 4);
  *(int **)(pbVar2 + 4) = piVar6;
  uVar7 = *(undefined4 *)(pbVar2 + 8);
  *(int **)(pbVar2 + 8) = param_6;
  if (*(char *)(*(int *)(param_1 + 8) + 0x14) == '\0') {
    iVar3 = -0x13;
  }
  else {
    pcVar5 = *(code **)(**(int **)(param_1 + 0xc) + 4);
    if (pcVar5 == (code *)0x0) {
      iVar3 = -5;
    }
    else {
      iVar3 = (*pcVar5)(*(int **)(param_1 + 0xc),param_3 + -5,param_4 + 5);
      if (-1 < iVar3) {
        do {
          FUN_0e0686e8(pbVar2 + 0xc,local_2c,&local_30);
          if (local_2c[0] == 1) goto LAB_0e06c538;
          iVar4 = FUN_0e06c358(pbVar2,local_2c[0],local_30);
        } while (iVar4 != 1);
        if (param_5 == (int *)0x0) {
          if ((*(int *)(**(int **)(param_1 + 0xc) + 0x10) != 0) &&
             (*(code **)(pbVar2 + 4) != (code *)0x0)) {
            (**(code **)(pbVar2 + 4))
                      (param_1,local_2c[0] + 5,local_30 + -5,*(undefined4 *)(pbVar2 + 8));
            FUN_0e06bd58(param_1,local_2c[0] + 5);
          }
        }
        else {
          *param_5 = local_2c[0] + 5;
          *local_34 = local_30 + -5;
        }
      }
    }
  }
LAB_0e06c538:
  bVar1 = pbVar2[2];
  *(undefined4 *)(pbVar2 + 4) = uVar8;
  *(undefined4 *)(pbVar2 + 8) = uVar7;
  pbVar2[2] = bVar1 - 1;
  if ((byte)(bVar1 - 1) != 0) {
    return iVar3;
  }
  FUN_0e06d83c();
  FUN_0e068754(*pbVar2);
  return iVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c69c. Types and names are inferred; NOT original source. */

void FUN_0e06c69c(int param_1,int param_2)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(param_1 + 0xc) + 0xc);
  if ((UNRECOVERED_JUMPTABLE != (code *)0x0) && (*(char *)(*(int *)(param_1 + 8) + 0x14) != '\0')) {
                    /* WARNING: Could not recover jumptable at 0x0e06c6ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(*(int **)(param_1 + 0xc),param_2 + -5);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c6b4. Types and names are inferred; NOT original source. */

void FUN_0e06c6b4(int param_1)

{
  uint uVar1;
  bool bVar2;
  
  if (param_1 == 0) {
    return;
  }
  if (param_1 == 0) {
    return;
  }
  uVar1 = (DAT_23000964 / 1000000) * param_1;
  do {
    bVar2 = 2 < uVar1;
    uVar1 = uVar1 - 3;
  } while (bVar2 && uVar1 != 0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c6bc. Types and names are inferred; NOT original source. */

void FUN_0e06c6bc(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c6c0. Types and names are inferred; NOT original source. */

bool FUN_0e06c6c0(int param_1)

{
  byte bVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1 != 0) {
    bVar1 = (*(char **)(param_1 + 0xc))[1];
    bVar2 = (bool)(bVar1 & 1);
    if ((bVar1 & 1) != 0) {
      bVar2 = **(char **)(param_1 + 0xc) == '\0';
    }
  }
  return bVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c6d8. Types and names are inferred; NOT original source. */

void FUN_0e06c6d8(void)

{
  bool bVar1;
  uint uVar2;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c6e8. Types and names are inferred; NOT original source. */

void FUN_0e06c6e8(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  undefined4 extraout_r3;
  undefined4 uVar4;
  
  FUN_0e06c6d8();
  uVar3 = DAT_23007170;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06c6e8();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e061198(uVar3,extraout_r1,extraout_r2,extraout_r3,in_r3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c720. Types and names are inferred; NOT original source. */

void FUN_0e06c720(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar3 = (undefined4 *)(&PTR_DAT_0e070824)[param_1];
  puVar5 = (undefined4 *)(&PTR_DAT_0e070824)[param_1 + 1];
  do {
    if (puVar5 <= puVar3) {
      return;
    }
    while( true ) {
      pcVar2 = (code *)*puVar3;
      iVar4 = puVar3[1];
      if (iVar4 != 0) break;
      puVar3 = puVar3 + 2;
      (*pcVar2)();
      if (puVar5 <= puVar3) {
        return;
      }
    }
    if ((pcVar2 != (code *)0x0) && (iVar1 = (*pcVar2)(iVar4), iVar1 != 0)) {
      if (iVar1 < 0) {
        iVar1 = -iVar1;
      }
      if (0xfe < iVar1) {
        iVar1 = 0xff;
      }
      **(undefined1 **)(iVar4 + 0xc) = (char)iVar1;
    }
    puVar3 = puVar3 + 2;
    *(byte *)(*(int *)(iVar4 + 0xc) + 1) = *(byte *)(*(int *)(iVar4 + 0xc) + 1) | 1;
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c850. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06f3aa(undefined1 *param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_3;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    *param_1 = param_2;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c854. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06f35c(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar2 = param_2 + param_3;
  puVar3 = (undefined1 *)(param_1 + -1);
  if (param_2 != puVar2) {
    do {
      puVar1 = param_2 + 1;
      puVar3 = puVar3 + 1;
      *puVar3 = *param_2;
      param_2 = puVar1;
    } while (puVar1 != puVar2);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c858. Types and names are inferred; NOT original source. */

void FUN_0e06c858(void)

{
  undefined4 in_r3;
  
  thunk_FUN_0e06f3aa(&DAT_23001e20,0,0x53d4,in_r3,in_r3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c878. Types and names are inferred; NOT original source. */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0e06c878(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  FUN_0e06c720(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(0x23013100);
  }
  setMainStackPointerLimit(0x23012900);
  DAT_e000ed22 = 0xe0;
  DAT_e000ed1f = 0x20;
  DAT_e000ed18 = 0;
  DAT_e000ed19 = 0;
  DAT_e000ed1a = 0;
  _DAT_e000ed24 = _DAT_e000ed24 | 0x70000;
  DAT_e000ed23 = 0;
  FUN_0e061078();
  FUN_0e061404();
  _DAT_e000ed28 = 0xffffffff;
  _DAT_e000ed2c = 0xffffffff;
  FUN_0e06173c();
  FUN_0e061484();
  DAT_23002bdc = 0x101;
  DAT_23002c44 = 0;
  DAT_23002c48 = 0;
  FUN_0e06ee28(&DAT_23002bd0);
  DAT_23007170 = &DAT_23002bd0;
  FUN_0e06c6bc();
  FUN_0e06c720(1);
  FUN_0e06c720(2);
  FUN_0e06e1cc();
  DAT_2300717c = &DAT_23002a88;
  uVar2 = FUN_0e06d860(&DAT_23002a88,&DAT_23013240,0x400,&LAB_0e06c774_1,0,0,0,0,1,&DAT_0e07081c);
  DAT_23002a95 = DAT_23002a95 & 0xfb;
  FUN_0e06dd24(&DAT_23002a88);
  FUN_0e06d860(&DAT_230029f8,&DAT_23013100,0x140,&LAB_0e06cba0_1,&DAT_23007168,0,0,0xf,1,0);
  DAT_23002a05 = DAT_23002a05 & 0xfb;
  DAT_23007178 = 0;
  DAT_2300716c = &DAT_23013100;
  DAT_23007174 = &DAT_230029f8;
  FUN_0e0613ac(&DAT_23002a88,uVar2,&LAB_0e06c774_1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c99c. Types and names are inferred; NOT original source. */

void FUN_0e06c99c(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06c9d0. Types and names are inferred; NOT original source. */

void FUN_0e06c9d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_30;
  int iStack_2c;
  
  FUN_0e06e9e0(&local_30,param_2,param_5,param_6);
  iVar4 = iStack_2c;
  iVar3 = local_30;
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  while ((uVar6 = FUN_0e05d4d0(param_1,param_2,param_3), (int)uVar6 == 0 &&
         (param_5 != 0 || param_6 != 0))) {
    FUN_0e06ea70(&local_30,(int)((ulonglong)uVar6 >> 0x20),iVar3,iVar4);
    param_6 = iStack_2c;
    param_5 = local_30;
    FUN_0e06dec8(param_1 + 0x14,uVar5,param_1 + 0xc);
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ca58. Types and names are inferred; NOT original source. */

void FUN_0e06ca58(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e05d460();
  iVar3 = FUN_0e06e148(param_1 + 0xc);
  if (iVar3 != 0) {
    FUN_0e06e078(param_1 + 0x14,uVar4,extraout_r2,param_4);
    return;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ca90. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06ca90(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar2 = &DAT_23001b48;
  do {
    puVar4 = *(undefined4 **)(puVar2 + 8);
    if ((((uint)puVar4 | *(uint *)(puVar2 + 0x14)) & 3) != 0) {
      return 0xffffffea;
    }
    *(undefined4 *)(puVar2 + 0xc) = 0;
    puVar3 = (undefined4 *)(*(uint *)(puVar2 + 0x14) * (*(int *)(puVar2 + 0x10) + -1) + (int)puVar4)
    ;
    puVar1 = (undefined4 *)0x0;
    if (puVar4 <= puVar3) {
      do {
        puVar4 = puVar3;
        *puVar4 = puVar1;
        puVar1 = puVar4;
        puVar3 = (undefined4 *)((int)puVar4 - *(int *)(puVar2 + 0x14));
      } while (*(undefined4 **)(puVar2 + 8) <= (undefined4 *)((int)puVar4 - *(int *)(puVar2 + 0x14))
              );
      *(undefined4 **)(puVar2 + 0xc) = puVar4;
    }
    puVar2 = puVar2 + 0x1c;
  } while (puVar2 < &DAT_23001b64);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cae4. Types and names are inferred; NOT original source. */

int FUN_0e06cae4(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar5 = *(undefined4 **)(param_1 + 0xc);
  if (puVar5 == (undefined4 *)0x0) {
    if (param_3 != 0 || param_4 != 0) {
      iVar3 = FUN_0e06dec8(param_1 + 8,uVar4,param_1,param_4,param_3,param_4);
      if (iVar3 != 0) {
        return iVar3;
      }
      *param_2 = *(undefined4 *)(DAT_23007170 + 0x14);
      return 0;
    }
    iVar3 = -0xc;
    *param_2 = 0;
  }
  else {
    iVar3 = 0;
    *param_2 = puVar5;
    *(undefined4 *)(param_1 + 0xc) = *puVar5;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return iVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cbb8. Types and names are inferred; NOT original source. */

void FUN_0e06cbb8(int param_1,int param_2,int param_3,int param_4)

{
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(int *)(param_1 + 0x14) = param_4 * param_3 + param_2;
  *(undefined1 *)(param_1 + 0x24) = 0;
  *(int *)(param_1 + 8) = param_3;
  *(int *)(param_1 + 0xc) = param_4;
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x1c) = param_2;
  *(int *)(param_1 + 0x10) = param_2;
  *(int *)param_1 = param_1;
  *(int *)(param_1 + 4) = param_1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cbdc. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06cbdc(int param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  
  uVar4 = 0;
  bVar5 = (bool)isCurrentModePrivileged();
  if (bVar5) {
    uVar4 = getBasePriority();
  }
  bVar5 = (bool)isCurrentModePrivileged();
  if ((bVar5) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(uint *)(param_1 + 0x20) < *(uint *)(param_1 + 0xc)) {
    iVar3 = FUN_0e06df70();
    if (iVar3 != 0) {
      FUN_0e06f35c(*(undefined4 *)(iVar3 + 0x14),param_2,*(undefined4 *)(param_1 + 8));
      *(undefined4 *)(iVar3 + 0x8c) = 0;
      FUN_0e06dd24(iVar3);
      FUN_0e06e078(param_1 + 8,uVar4);
      return 0;
    }
    FUN_0e06f35c(*(undefined4 *)(param_1 + 0x1c),param_2,*(undefined4 *)(param_1 + 8));
    iVar3 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 8);
    bVar5 = iVar3 == *(int *)(param_1 + 0x14);
    *(int *)(param_1 + 0x1c) = iVar3;
    if (bVar5) {
      iVar3 = *(int *)(param_1 + 0x10);
    }
    uVar2 = 0;
    if (bVar5) {
      *(int *)(param_1 + 0x1c) = iVar3;
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  else {
    if (param_3 != 0 || param_4 != 0) {
      *(undefined4 *)(DAT_23007170 + 0x14) = param_2;
      uVar4 = FUN_0e06dec8(param_1 + 8,uVar4,param_1,param_4,param_3,param_4);
      return uVar4;
    }
    uVar2 = 0xffffffdd;
  }
  bVar5 = (bool)isCurrentModePrivileged();
  if (bVar5) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cc94. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06cc94(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(int *)(param_1 + 0x20) == 0) {
    if (param_3 != 0 || param_4 != 0) {
      *(undefined4 *)(DAT_23007170 + 0x14) = param_2;
      uVar6 = FUN_0e06dec8(param_1 + 8,uVar6,param_1,param_4,param_3,param_4);
      return uVar6;
    }
    uVar3 = 0xffffffdd;
  }
  else {
    FUN_0e06f35c(param_2,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 8));
    iVar4 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 8);
    *(int *)(param_1 + 0x18) = iVar4;
    if (iVar4 == *(int *)(param_1 + 0x14)) {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x10);
    }
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
    iVar4 = FUN_0e06df70(param_1);
    uVar3 = 0;
    if (iVar4 != 0) {
      FUN_0e06f35c(*(undefined4 *)(param_1 + 0x1c),*(undefined4 *)(iVar4 + 0x14),
                   *(undefined4 *)(param_1 + 8));
      iVar5 = *(int *)(param_1 + 0x1c) + *(int *)(param_1 + 8);
      *(int *)(param_1 + 0x1c) = iVar5;
      if (iVar5 == *(int *)(param_1 + 0x14)) {
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x10);
      }
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      *(undefined4 *)(iVar4 + 0x8c) = 0;
      FUN_0e06dd24(iVar4);
      FUN_0e06e078(param_1 + 8,uVar6);
      return 0;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cd54. Types and names are inferred; NOT original source. */

void FUN_0e06cd54(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = FUN_0e06df70();
  while (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x8c) = 0xffffffdd;
    FUN_0e06dd24();
    iVar3 = FUN_0e06df70(param_1);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
  FUN_0e06e078(param_1 + 8,uVar4,*(undefined4 *)(param_1 + 0x1c),param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cd9c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06cd9c(int param_1)

{
  *(int *)param_1 = param_1;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(int *)(param_1 + 4) = param_1;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cdac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06cdac(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  
  iVar8 = DAT_23007170;
  uVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar7 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[3] == 0) {
    iVar5 = (int)*(char *)(DAT_23007170 + 0xe);
LAB_0e06cdcc:
    param_1[3] = param_1[3] + 1;
    param_1[4] = iVar5;
    param_1[2] = iVar8;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  iVar5 = param_1[2];
  if (iVar5 == DAT_23007170) {
    iVar5 = param_1[4];
    goto LAB_0e06cdcc;
  }
  if (param_3 == 0 && param_4 == 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff0;
  }
  cVar1 = *(char *)(iVar5 + 0xe);
  cVar4 = *(char *)(DAT_23007170 + 0xe);
  if (cVar1 <= *(char *)(DAT_23007170 + 0xe)) {
    cVar4 = cVar1;
  }
  if (cVar4 < -0x7f) {
    cVar4 = -0x7f;
  }
  if (cVar4 < cVar1) {
    iVar8 = FUN_0e06dfc8(iVar5);
  }
  else {
    iVar8 = 0;
  }
  iVar5 = FUN_0e06dec8(&DAT_23007188,uVar7,param_1,param_4,param_3,param_4);
  if (iVar5 == 0) {
    return 0;
  }
  uVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar7 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[2] != 0) {
    piVar6 = (int *)*param_1;
    iVar5 = param_1[4];
    if ((param_1 != piVar6) && (piVar6 != (int *)0x0)) {
      if (*(char *)((int)piVar6 + 0xe) <= iVar5) {
        iVar5 = (int)*(char *)((int)piVar6 + 0xe);
      }
      if (iVar5 < -0x7f) {
        iVar5 = -0x7f;
      }
    }
    if ((iVar5 != *(char *)(param_1[2] + 0xe)) && (iVar5 = FUN_0e06dfc8(), iVar5 != 0))
    goto LAB_0e06ce76;
  }
  if (iVar8 == 0) {
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xfffffff5;
  }
LAB_0e06ce76:
  FUN_0e06e078(&DAT_23007188,uVar7);
  return 0xfffffff5;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cea8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06cea8(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 8) == 0) {
    return 0xffffffea;
  }
  if (*(int *)(param_1 + 8) != DAT_23007170) {
    return 0xffffffff;
  }
  if (*(uint *)(param_1 + 0xc) < 2) {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (*(int *)(param_1 + 0x10) != (int)*(char *)(*(int *)(param_1 + 8) + 0xe)) {
      FUN_0e06dfc8();
    }
    iVar3 = FUN_0e06df70(param_1);
    *(int *)(param_1 + 8) = iVar3;
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    else {
      *(int *)(param_1 + 0x10) = (int)*(char *)(iVar3 + 0xe);
      *(undefined4 *)(iVar3 + 0x8c) = 0;
      FUN_0e06dd24();
      FUN_0e06e078(&DAT_23007188,uVar4);
    }
  }
  else {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) - 1;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cf2c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06cf2c(uint *param_1,uint *param_2,uint *param_3,int param_4,char param_5)

{
  bool bVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 uVar8;
  
  puVar7 = param_1 + 2;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_5 == '\0') {
    iVar2 = FUN_0e06df70(puVar7);
  }
  else {
    param_2 = (uint *)param_1[1];
    iVar2 = FUN_0e06df70(puVar7);
  }
  if (iVar2 != 0) {
    *(uint **)(iVar2 + 0x14) = param_3;
    *(undefined4 *)(iVar2 + 0x8c) = 0;
    FUN_0e06dd24();
    FUN_0e06e078(puVar7,uVar8);
    return 0;
  }
  if (param_4 == 0) {
    *param_3 = 0;
    uVar6 = 0;
    uVar5 = 0;
    puVar3 = param_3;
    if (param_2 != (uint *)0x0) goto LAB_0e06cf62;
LAB_0e06cfbe:
    *puVar3 = *param_1 | uVar6;
    *param_1 = (uint)puVar3;
    if (param_1[1] != 0) goto LAB_0e06cf7a;
  }
  else {
    puVar3 = (uint *)FUN_0e06ee34(0,8);
    if (puVar3 == (uint *)0x0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar8);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0xfffffff4;
    }
    uVar6 = 1;
    puVar3[1] = (uint)param_3;
    *puVar3 = 1;
    uVar5 = uVar6;
    if (param_2 == (uint *)0x0) goto LAB_0e06cfbe;
LAB_0e06cf62:
    if (3 < *param_2) {
      *puVar3 = *param_2 & 0xfffffffc | uVar5;
      *param_2 = (uint)puVar3 | *param_2 & 3;
      goto LAB_0e06cf7a;
    }
    *puVar3 = uVar5;
    puVar4 = (uint *)param_1[1];
    if (puVar4 == (uint *)0x0) {
      *param_1 = (uint)puVar3;
      param_1[1] = (uint)puVar3;
      goto LAB_0e06cf7a;
    }
    *puVar4 = *puVar4 & 3 | (uint)puVar3;
  }
  param_1[1] = (uint)puVar3;
LAB_0e06cf7a:
  FUN_0e06e078(puVar7,uVar8);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06cff8. Types and names are inferred; NOT original source. */

void FUN_0e06cff8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = param_1 + 2;
  param_1[3] = param_1 + 2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d008. Types and names are inferred; NOT original source. */

void FUN_0e06d008(undefined4 param_1,undefined4 param_2)

{
  FUN_0e06cf2c(param_1,0,param_2,0,1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d020. Types and names are inferred; NOT original source. */

void FUN_0e06d020(undefined4 param_1,undefined4 param_2)

{
  FUN_0e06cf2c(param_1,0,param_2,0,0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d038. Types and names are inferred; NOT original source. */

uint * FUN_0e06d038(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint *puVar6;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar4 = (uint *)*param_1;
  if (puVar4 == (uint *)0x0) {
    if (param_3 != 0 || param_4 != 0) {
      iVar2 = FUN_0e06dec8(param_1 + 2,uVar5,param_1 + 2,param_4,param_3,param_4);
      if (iVar2 != 0) {
        return (uint *)0x0;
      }
      return *(uint **)(DAT_23007170 + 0x14);
    }
  }
  else {
    uVar3 = *puVar4;
    if (puVar4 == (uint *)param_1[1]) {
      param_1[1] = uVar3 & 0xfffffffc;
    }
    *param_1 = uVar3 & 0xfffffffc;
    if ((*puVar4 & 3) != 0) {
      puVar6 = (uint *)puVar4[1];
      FUN_0e06ede4(puVar4);
      puVar4 = puVar6;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return puVar4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d0b4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d0b4(int param_1,uint param_2,uint param_3)

{
  if ((param_3 != 0) && (param_2 <= param_3)) {
    *(uint *)(param_1 + 8) = param_2;
    *(uint *)(param_1 + 0xc) = param_3;
    *(int *)param_1 = param_1;
    *(int *)(param_1 + 4) = param_1;
    return 0;
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d0d0. Types and names are inferred; NOT original source. */

void FUN_0e06d0d0(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = FUN_0e06df70();
  if (iVar3 == 0) {
    iVar3 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 0xc) != iVar3) {
      iVar3 = iVar3 + 1;
    }
    *(int *)(param_1 + 8) = iVar3;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  *(undefined4 *)(iVar3 + 0x8c) = 0;
  FUN_0e06dd24();
  FUN_0e06e078(&DAT_23007188,uVar4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d118. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d118(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(int *)(param_1 + 8) == 0) {
    if (param_3 == 0 && param_4 == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar3 = 0xfffffff0;
    }
    else {
      uVar3 = FUN_0e06dec8(&DAT_23007188,uVar3,param_1,param_4,param_3,param_4);
    }
  }
  else {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar3 = 0;
  }
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d168. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d168(void)

{
  char *local_10;
  undefined4 uStack_c;
  
  local_10 = "sysworkq";
  uStack_c = 0x100;
  FUN_0e06d530(&DAT_23002b18,&DAT_23013640,0x400,0xffffffff,&local_10);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d19c. Types and names are inferred; NOT original source. */

void FUN_0e06d19c(int param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  
  do {
    while( true ) {
      uVar12 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar12 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      puVar11 = *(undefined4 **)(param_1 + 0x90);
      if (puVar11 != (undefined4 *)0x0) break;
      uVar6 = *(uint *)(param_1 + 0xa8);
      *(uint *)(param_1 + 0xa8) = uVar6 & 0xfffffffb;
      if ((int)(uVar6 << 0x1d) < 0) {
        do {
          iVar7 = FUN_0e06e3f4(param_1 + 0xa0,1,0);
        } while (iVar7 != 0);
      }
      FUN_0e06e460(&DAT_23007188,uVar12,param_1 + 0x98,0,0xffffffff,0xffffffff,0);
    }
    uVar8 = *puVar11;
    *(undefined4 *)(param_1 + 0x90) = uVar8;
    if (puVar11 == *(undefined4 **)(param_1 + 0x94)) {
      *(undefined4 *)(param_1 + 0x94) = uVar8;
    }
    *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) | 2;
    puVar11[3] = puVar11[3] & 0xfffffffb | 1;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar12);
    }
    InstructionSynchronizationBarrier(0xf);
    (*(code *)puVar11[1])(puVar11);
    uVar12 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar12 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    uVar6 = puVar11[3];
    uVar10 = uVar6 & 0xfffffffe;
    if ((int)(uVar6 << 0x1b) < 0) {
      puVar11[3] = uVar6 & 0xffffffee;
      FUN_0e06d0d0(puVar11 + 4);
      uVar10 = puVar11[3];
    }
    else {
      puVar11[3] = uVar10;
    }
    puVar4 = DAT_23002bc8;
    if (((int)(uVar10 << 0x1e) < 0) &&
       (puVar11[3] = uVar10 & 0xfffffffd, puVar4 != (undefined4 *)0x0)) {
      puVar9 = (undefined4 *)puVar4[1];
      puVar2 = (undefined4 *)0x0;
      puVar5 = (undefined4 *)*puVar4;
      while (puVar3 = puVar5, puVar11 != puVar9) {
        if (puVar3 == (undefined4 *)0x0) goto LAB_0e06d222;
        puVar2 = puVar4;
        puVar5 = (undefined4 *)*puVar3;
        puVar4 = puVar3;
        puVar9 = (undefined4 *)puVar3[1];
      }
      puVar11 = (undefined4 *)*puVar4;
      if (puVar2 == (undefined4 *)0x0) {
        DAT_23002bc8 = puVar11;
        if (DAT_23002bcc == puVar4) {
          DAT_23002bcc = puVar11;
        }
      }
      else {
        *puVar2 = puVar11;
        if (DAT_23002bcc == puVar4) {
          DAT_23002bcc = puVar2;
        }
      }
      *puVar4 = 0;
      FUN_0e06d0d0(puVar4 + 2);
    }
LAB_0e06d222:
    uVar6 = *(uint *)(param_1 + 0xa8) & 0xfffffffd;
    *(uint *)(param_1 + 0xa8) = uVar6;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar12);
    }
    InstructionSynchronizationBarrier(0xf);
    if (-1 < (int)(uVar6 << 0x17)) {
      FUN_0e06e1dc();
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d2dc. Types and names are inferred; NOT original source. */

uint FUN_0e06d2dc(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = param_1[3];
  uVar5 = (uVar2 & 3) >> 1;
  if ((int)(uVar2 << 0x1e) < 0) {
LAB_0e06d30e:
    uVar5 = 0xfffffff0;
  }
  else {
    if ((int)(uVar2 << 0x1d) < 0) goto LAB_0e06d2ee;
    iVar6 = *param_2;
    if (iVar6 == 0) {
      iVar6 = param_1[2];
      *param_2 = iVar6;
      if ((int)(param_1[3] << 0x1f) < 0) goto LAB_0e06d376;
      uVar2 = 1;
      if (iVar6 != 0) goto LAB_0e06d320;
LAB_0e06d380:
      uVar5 = 0xffffffea;
      goto LAB_0e06d2ee;
    }
    if ((int)(uVar2 << 0x1f) < 0) {
LAB_0e06d376:
      iVar6 = param_1[2];
      uVar2 = 2;
      *param_2 = iVar6;
      if (iVar6 == 0) goto LAB_0e06d380;
    }
    else {
      uVar2 = 1;
    }
LAB_0e06d320:
    if (DAT_23007170 == iVar6) {
      iVar1 = FUN_0e06d830();
      iVar3 = *(int *)(iVar6 + 0xa8);
      if (iVar1 != 0) goto LAB_0e06d32c;
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1c) || (iVar3 << 0x1d < 0)) goto LAB_0e06d340;
        goto LAB_0e06d30e;
      }
    }
    else {
      iVar3 = *(int *)(iVar6 + 0xa8);
LAB_0e06d32c:
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1d) && (-1 < iVar3 << 0x1c)) {
LAB_0e06d340:
          *param_1 = 0;
          puVar4 = *(undefined4 **)(iVar6 + 0x94);
          if (puVar4 == (undefined4 *)0x0) {
            *(undefined4 **)(iVar6 + 0x90) = param_1;
            *(undefined4 **)(iVar6 + 0x94) = param_1;
          }
          else {
            *puVar4 = param_1;
            *(undefined4 **)(iVar6 + 0x94) = param_1;
          }
          FUN_0e06e3f4(iVar6 + 0x98,0,0,puVar4,param_4);
          param_1[3] = param_1[3] | 4;
          param_1[2] = *param_2;
          return uVar2;
        }
        goto LAB_0e06d30e;
      }
    }
    uVar5 = 0xffffffed;
  }
LAB_0e06d2ee:
  *param_2 = 0;
  return uVar5;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d3a4. Types and names are inferred; NOT original source. */

void FUN_0e06d3a4(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_c;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar2 = *(uint *)(param_1 + -4);
  *(uint *)(param_1 + -4) = uVar2 & 0xfffffff7;
  if ((int)(uVar2 << 0x1c) < 0) {
    local_c = *(undefined4 *)(param_1 + 0x18);
    FUN_0e06d2dc(param_1 + -0x10,&local_c);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d3f0. Types and names are inferred; NOT original source. */

void FUN_0e06d3f0(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  *param_1 = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d3fc. Types and names are inferred; NOT original source. */

int FUN_0e06d3fc(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_14;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  local_14 = param_1;
  iVar3 = FUN_0e06d2dc(param_2,&local_14);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  if (0 < iVar3) {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    FUN_0e06e09c(uVar4);
  }
  return iVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d43c. Types and names are inferred; NOT original source. */

int FUN_0e06d43c(undefined4 param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *local_14;
  
  local_14 = &DAT_23002b18;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = FUN_0e06d2dc(param_1,&local_14);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  if (0 < iVar3) {
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    FUN_0e06e09c(uVar4);
  }
  return iVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d480. Types and names are inferred; NOT original source. */

uint FUN_0e06d480(undefined4 *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar5 = param_1[3];
  if ((int)(uVar5 << 0x1e) < 0) {
    uVar2 = 0;
    if ((uVar5 & 0x1f) != 0) {
      param_1[3] = uVar5 | 2;
      uVar2 = uVar5 & 0x1f | 2;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar2;
  }
  uVar2 = uVar5 & 0xfffffffb;
  iVar7 = param_1[2];
  param_1[3] = uVar2;
  if (((int)(uVar5 << 0x1d) < 0) &&
     (puVar3 = *(undefined4 **)(iVar7 + 0x90), puVar3 != (undefined4 *)0x0)) {
    if (param_1 == puVar3) {
      uVar6 = *param_1;
      *(undefined4 *)(iVar7 + 0x90) = uVar6;
      if (param_1 == *(undefined4 **)(iVar7 + 0x94)) {
        *(undefined4 *)(iVar7 + 0x94) = uVar6;
      }
    }
    else {
      do {
        puVar4 = puVar3;
        puVar3 = (undefined4 *)*puVar4;
        if (puVar3 == (undefined4 *)0x0) goto LAB_0e06d4c0;
      } while (param_1 != puVar3);
      *puVar4 = *param_1;
      if (param_1 == *(undefined4 **)(iVar7 + 0x94)) {
        *(undefined4 **)(iVar7 + 0x94) = puVar4;
      }
    }
    uVar2 = param_1[3];
    *param_1 = 0;
  }
LAB_0e06d4c0:
  uVar5 = 0;
  if ((uVar2 & 0x1f) != 0) {
    param_1[3] = uVar2 | 2;
    uVar5 = uVar2 & 0x1f | 2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar8);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar5;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d524. Types and names are inferred; NOT original source. */

void FUN_0e06d524(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0e06f3aa(param_1,0,0xb0,param_4,param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d530. Types and names are inferred; NOT original source. */

void FUN_0e06d530(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(int *)(param_1 + 0x98) = param_1 + 0x98;
  *(int *)(param_1 + 0x9c) = param_1 + 0x98;
  *(int *)(param_1 + 0xa0) = param_1 + 0xa0;
  *(int *)(param_1 + 0xa4) = param_1 + 0xa0;
  if (param_5 == (int *)0x0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0x101;
    if ((char)param_5[1] == '\0') {
      uVar1 = 1;
    }
  }
  *(undefined4 *)(param_1 + 0xa8) = uVar1;
  FUN_0e06d8f8(param_1,param_2,param_3,0xe06d19d,param_1,0,0,param_4,0);
  if (param_5 != (int *)0x0) {
    if (*param_5 != 0) {
      FUN_0e06d854(param_1);
    }
    if (*(char *)((int)param_5 + 5) != '\0') {
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
    }
  }
  thunk_FUN_0e06dd44(param_1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d5b0. Types and names are inferred; NOT original source. */

void FUN_0e06d5b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0e06f3aa(param_1,0,0x30,param_4,param_4);
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0xc) = 0x100;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d5c8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d5c8(undefined4 param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_c;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((*(uint *)(param_2 + 0xc) & 0x1e) == 0) {
    local_c = param_1;
    if (param_4 == 0 && param_3 == 0) {
      uVar3 = FUN_0e06d2dc(param_2,&local_c);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return uVar3;
    }
    *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
    *(undefined4 *)(param_2 + 0x28) = param_1;
    FUN_0e06e648(param_2 + 0x10,0xe06d3a5);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return 1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d630. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d630(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *local_c;
  
  local_c = &DAT_23002b18;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((*(uint *)(param_1 + 0xc) & 0x1e) == 0) {
    if (param_4 == 0 && param_3 == 0) {
      uVar3 = FUN_0e06d2dc(param_1,&local_c);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      return uVar3;
    }
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
    *(undefined **)(param_1 + 0x28) = &DAT_23002b18;
    FUN_0e06e648(param_1 + 0x10,0xe06d3a5);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return 1;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d69c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d69c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_1c [2];
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = *(uint *)(param_2 + 0xc);
  *(uint *)(param_2 + 0xc) = uVar3 & 0xfffffff7;
  local_1c[0] = param_1;
  if ((int)(uVar3 << 0x1c) < 0) {
    FUN_0e06e768(param_2 + 0x10);
  }
  if (param_4 == 0 && param_3 == 0) {
    uVar2 = FUN_0e06d2dc(param_2,local_1c);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar2;
  }
  *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) | 8;
  *(undefined4 *)(param_2 + 0x28) = local_1c[0];
  FUN_0e06e648(param_2 + 0x10,0xe06d3a5,param_3,param_4);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d714. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d714(int param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined *local_1c [2];
  
  local_1c[0] = &DAT_23002b18;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar3 & 0xfffffff7;
  if ((int)(uVar3 << 0x1c) < 0) {
    FUN_0e06e768(param_1 + 0x10);
  }
  if (param_4 == 0 && param_3 == 0) {
    uVar2 = FUN_0e06d2dc(param_1,local_1c);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
    return uVar2;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 8;
  *(undefined **)(param_1 + 0x28) = local_1c[0];
  FUN_0e06e648(param_1 + 0x10,0xe06d3a5,param_3,param_4);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d790. Types and names are inferred; NOT original source. */

uint FUN_0e06d790(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar9 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar9 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x40 < uVar7)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = param_1[3];
  uVar7 = uVar3 & 0xfffffff7;
  param_1[3] = uVar7;
  if ((int)(uVar3 << 0x1c) < 0) {
    FUN_0e06e768(param_1 + 4);
    uVar7 = param_1[3];
    uVar3 = uVar7;
  }
  if (-1 < (int)(uVar3 << 0x1e)) {
    iVar4 = uVar7 << 0x1d;
    uVar7 = uVar7 & 0xfffffffb;
    iVar2 = param_1[2];
    param_1[3] = uVar7;
    if ((iVar4 < 0) && (puVar5 = *(undefined4 **)(iVar2 + 0x90), puVar5 != (undefined4 *)0x0)) {
      if (param_1 == puVar5) {
        uVar8 = *param_1;
        *(undefined4 *)(iVar2 + 0x90) = uVar8;
        if (param_1 == *(undefined4 **)(iVar2 + 0x94)) {
          *(undefined4 *)(iVar2 + 0x94) = uVar8;
        }
      }
      else {
        do {
          puVar6 = puVar5;
          puVar5 = (undefined4 *)*puVar6;
          if (puVar5 == (undefined4 *)0x0) goto LAB_0e06d7b2;
        } while (param_1 != puVar5);
        *puVar6 = *param_1;
        if (param_1 == *(undefined4 **)(iVar2 + 0x94)) {
          *(undefined4 **)(iVar2 + 0x94) = puVar6;
        }
      }
      uVar7 = param_1[3];
      *param_1 = 0;
    }
  }
LAB_0e06d7b2:
  uVar3 = 0;
  if ((uVar7 & 0x1f) != 0) {
    param_1[3] = uVar7 | 2;
    uVar3 = uVar7 & 0x1f | 2;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  return uVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d830. Types and names are inferred; NOT original source. */

bool FUN_0e06d830(void)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1ff;
  }
  return uVar2 != 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d83c. Types and names are inferred; NOT original source. */

void FUN_0e06d83c(undefined4 param_1)

{
  *(undefined4 *)(DAT_23007170 + 0x70) = param_1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d848. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d848(void)

{
  return *(undefined4 *)(DAT_23007170 + 0x70);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d854. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06d854(void)

{
  return 0xffffffa8;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d85c. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06dd44(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)((uint)*(byte *)(param_1 + 0xd) << 0x1d) < 0) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xfb;
    FUN_0e06da0c();
    if (iVar3 == 0) {
      uVar2 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar2 = getCurrentExceptionNumber();
        uVar2 = uVar2 & 0x1ff;
      }
      if ((uVar2 == 0) && (DAT_2300717c != DAT_23007170)) {
        FUN_0e0611cc();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d860. Types and names are inferred; NOT original source. */

int FUN_0e06d860(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined1 param_8,undefined1 param_9)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined1 *)(param_1 + 0xc) = param_9;
  uVar3 = param_3 + 7U & 0xfffffff8;
  *(undefined1 *)(param_1 + 0xe) = param_8;
  iVar4 = param_2 + uVar3;
  *(int *)(param_1 + 0x58) = param_1 + 0x58;
  *(int *)(param_1 + 0x5c) = param_1 + 0x58;
  *(undefined1 *)(param_1 + 0xd) = 4;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  iVar1 = FUN_0e060d44(param_1,iVar4);
  *(uint *)(param_1 + 0x78) = uVar3;
  *(int *)(param_1 + 0x74) = param_2;
  uVar3 = iVar1 + 7U & 0xfffffff8;
  iVar4 = iVar4 - uVar3;
  *(uint *)(param_1 + 0x7c) = uVar3;
  FUN_0e061364(param_1,param_2,iVar4,param_4,param_5,param_6,param_7);
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar1 = DAT_23007170;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x80);
  }
  *(undefined4 *)(param_1 + 0x80) = uVar2;
  return iVar4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d8f8. Types and names are inferred; NOT original source. */

int FUN_0e06d8f8(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined1 param_8,undefined1 param_9,
                undefined4 param_10,int param_11,int param_12)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = param_3 + 7U & 0xfffffff8;
  *(undefined1 *)(param_1 + 0xc) = param_9;
  *(undefined1 *)(param_1 + 0xe) = param_8;
  *(int *)(param_1 + 0x58) = param_1 + 0x58;
  *(int *)(param_1 + 0x5c) = param_1 + 0x58;
  iVar2 = param_2 + uVar3;
  *(undefined1 *)(param_1 + 0xd) = 4;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined1 *)(param_1 + 0xf) = 0;
  iVar1 = FUN_0e060d44(param_1,iVar2);
  *(uint *)(param_1 + 0x78) = uVar3;
  *(int *)(param_1 + 0x74) = param_2;
  uVar3 = iVar1 + 7U & 0xfffffff8;
  *(uint *)(param_1 + 0x7c) = uVar3;
  FUN_0e061364(param_1,param_2,iVar2 - uVar3,param_4,param_5,param_6,param_7);
  *(undefined4 *)(param_1 + 0x54) = 0;
  iVar1 = DAT_23007170;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  uVar4 = 0;
  if (iVar1 != 0) {
    uVar4 = *(undefined4 *)(iVar1 + 0x80);
  }
  *(undefined4 *)(param_1 + 0x80) = uVar4;
  if (param_12 == -1 && param_11 == -1) {
    return param_1;
  }
  if (param_12 == 0 && param_11 == 0) {
    FUN_0e06dd44(param_1);
    return param_1;
  }
  FUN_0e06e648(param_1 + 0x18,&LAB_0e06daf4_1,param_11,param_12);
  return param_1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06d9cc. Types and names are inferred; NOT original source. */

void FUN_0e06d9cc(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((undefined4 **)DAT_23007180 == &DAT_23007180) ||
     (puVar1 = DAT_23007180, DAT_23007180 == (undefined4 *)0x0)) {
    puVar1 = DAT_23007174;
  }
  if (((((param_1 != 0) || ((*(byte *)((int)DAT_23007170 + 0xd) & 0x1f) != 0)) || (puVar1[6] != 0))
      || (puVar2 = DAT_23007170, *(ushort *)((int)DAT_23007170 + 0xe) < 0x80)) &&
     (puVar2 = puVar1, puVar1 != DAT_23007170)) {
    FUN_0e06e4ec(puVar1);
    DAT_2300717c = puVar1;
    return;
  }
  DAT_2300717c = puVar2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06da0c. Types and names are inferred; NOT original source. */

void FUN_0e06da0c(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((*(char *)((int)param_1 + 0xd) < '\0') || ((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0)) ||
     (param_1[6] != 0)) {
    return;
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  puVar2 = DAT_23007180;
  if ((undefined4 **)DAT_23007180 == &DAT_23007180) {
    puVar2 = (undefined4 *)0x0;
  }
  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)puVar2 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)puVar2 + 0xe))) {
      puVar1 = (undefined4 *)puVar2[1];
      *param_1 = puVar2;
      param_1[1] = puVar1;
      *puVar1 = param_1;
      puVar2[1] = param_1;
      goto LAB_0e06da5a;
    }
    if (puVar2 == DAT_23007184) break;
  }
  *param_1 = &DAT_23007180;
  param_1[1] = DAT_23007184;
  *DAT_23007184 = param_1;
  DAT_23007184 = param_1;
LAB_0e06da5a:
  FUN_0e06d9cc(0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06da74. Types and names are inferred; NOT original source. */

void FUN_0e06da74(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (*(char *)((int)param_1 + 0xd) < '\0') {
    piVar1 = (int *)param_1[1];
    *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x7f;
    iVar3 = *param_1;
    *piVar1 = iVar3;
    *(int **)(iVar3 + 4) = piVar1;
    *param_1 = 0;
    param_1[1] = 0;
  }
  FUN_0e06d9cc(DAT_23007170 == param_1);
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 2;
  if (param_2 != (undefined4 *)0x0) {
    param_1[2] = (int)param_2;
    puVar4 = (undefined4 *)*param_2;
    if (param_2 != puVar4) {
      for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
        if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)puVar4 + 0xe)) &&
           (*(char *)((int)param_1 + 0xe) < *(char *)((int)puVar4 + 0xe))) {
          puVar2 = (undefined4 *)puVar4[1];
          *param_1 = (int)puVar4;
          param_1[1] = (int)puVar2;
          *puVar2 = param_1;
          puVar4[1] = param_1;
          return;
        }
        puVar2 = (undefined4 *)param_2[1];
        if (puVar4 == puVar2) goto LAB_0e06dad8;
      }
    }
    puVar2 = (undefined4 *)param_2[1];
LAB_0e06dad8:
    *param_1 = (int)param_2;
    param_1[1] = (int)puVar2;
    *puVar2 = param_1;
    param_2[1] = param_1;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06db60. Types and names are inferred; NOT original source. */

void FUN_0e06db60(int *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  bool bVar7;
  
  if (param_3 == 0) {
    bVar6 = 0x10;
  }
  else {
    bVar6 = 8;
  }
  bVar1 = *(byte *)((int)param_1 + 0xd);
  if ((bVar6 & bVar1) != 0) goto joined_r0x0e06dbd4;
  if ((char)bVar1 < '\0') {
    *(byte *)((int)param_1 + 0xd) = bVar6 | bVar1 & 0x7f;
    iVar5 = *param_1;
    piVar2 = (int *)param_1[1];
    *piVar2 = iVar5;
    *(int **)(iVar5 + 4) = piVar2;
    *param_1 = 0;
    param_1[1] = 0;
    if (bVar6 == 8) goto LAB_0e06dbfe;
LAB_0e06db9a:
    bVar7 = false;
  }
  else {
    *(byte *)((int)param_1 + 0xd) = bVar6 | bVar1;
    if (bVar6 != 8) goto LAB_0e06db9a;
LAB_0e06dbfe:
    if (param_1[2] != 0) {
      iVar5 = *param_1;
      piVar2 = (int *)param_1[1];
      *piVar2 = iVar5;
      *(int **)(iVar5 + 4) = piVar2;
      *param_1 = 0;
      param_1[1] = 0;
      *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfd;
      param_1[2] = 0;
    }
    FUN_0e06e768(param_1 + 6);
    piVar2 = (int *)param_1[0x16];
    while ((param_1 + 0x16 != piVar2 && (piVar2 != (int *)0x0))) {
      iVar5 = *piVar2;
      piVar3 = (int *)piVar2[1];
      *piVar3 = iVar5;
      *(int **)(iVar5 + 4) = piVar3;
      *(byte *)((int)piVar2 + 0xd) = *(byte *)((int)piVar2 + 0xd) & 0xfd;
      *piVar2 = 0;
      piVar2[1] = 0;
      piVar2[2] = 0;
      FUN_0e06e768(piVar2 + 6);
      piVar2[0x23] = 0;
      FUN_0e06da0c(piVar2);
      piVar2 = (int *)param_1[0x16];
    }
    if (param_1 == DAT_23007170) {
      uVar4 = 0;
      bVar7 = (bool)isCurrentModePrivileged();
      if (bVar7) {
        uVar4 = getCurrentExceptionNumber();
        uVar4 = uVar4 & 0x1ff;
      }
      bVar7 = uVar4 != 0;
    }
    else {
      bVar7 = false;
    }
  }
  if (((int **)DAT_23007180 == &DAT_23007180) || (piVar2 = DAT_23007180, DAT_23007180 == (int *)0x0)
     ) {
    piVar2 = DAT_23007174;
  }
  if (piVar2 != DAT_23007170) {
    FUN_0e06e4ec(piVar2);
  }
  DAT_2300717c = piVar2;
  if ((bVar6 != 0x10) && (bVar7)) {
    DAT_23002c44 = 0;
    DAT_23002c48 = 0;
    DAT_23002bdc = 0x101;
    FUN_0e06ee28(&DAT_23002bd0);
    DAT_23007170 = (int *)&DAT_23002bd0;
  }
  DataMemoryBarrier(0x1f);
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x9f;
joined_r0x0e06dbd4:
  if (DAT_23007170 == param_1) {
    uVar4 = 0;
    bVar7 = (bool)isCurrentModePrivileged();
    if (bVar7) {
      uVar4 = getCurrentExceptionNumber();
      uVar4 = uVar4 & 0x1ff;
    }
    if (uVar4 == 0) {
      FUN_0e0611cc(param_2);
      return;
    }
  }
  bVar7 = (bool)isCurrentModePrivileged();
  if (bVar7) {
    setBasePriority(param_2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06dca8. Types and names are inferred; NOT original source. */

void FUN_0e06dca8(int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  bVar1 = *(byte *)((int)param_1 + 0xd);
  if (*(char *)((int)param_1 + 0xd) < '\0') {
    iVar2 = *param_1;
    piVar4 = (int *)param_1[1];
    *(byte *)((int)param_1 + 0xd) = bVar1 & 0x7f;
    *piVar4 = iVar2;
    *(int **)(iVar2 + 4) = piVar4;
    bVar1 = *(byte *)((int)param_1 + 0xd);
    *param_1 = 0;
    param_1[1] = 0;
  }
  *(byte *)((int)param_1 + 0xd) = bVar1 | 0x80;
  piVar4 = DAT_23007180;
  if ((int **)DAT_23007180 == &DAT_23007180) {
    piVar4 = (int *)0x0;
  }
  for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
    if ((*(char *)((int)param_1 + 0xe) != *(char *)((int)piVar4 + 0xe)) &&
       (*(char *)((int)param_1 + 0xe) < *(char *)((int)piVar4 + 0xe))) {
      puVar3 = (undefined4 *)piVar4[1];
      *param_1 = (int)piVar4;
      param_1[1] = (int)puVar3;
      *puVar3 = param_1;
      piVar4[1] = (int)param_1;
      goto LAB_0e06dd04;
    }
    if (piVar4 == DAT_23007184) break;
  }
  *param_1 = (int)&DAT_23007180;
  param_1[1] = (int)DAT_23007184;
  *DAT_23007184 = (int)param_1;
  DAT_23007184 = param_1;
LAB_0e06dd04:
  FUN_0e06d9cc(DAT_23007170 == param_1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06dd24. Types and names are inferred; NOT original source. */

void FUN_0e06dd24(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06da0c();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06dd44. Types and names are inferred; NOT original source. */

void FUN_0e06dd44(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)((uint)*(byte *)(param_1 + 0xd) << 0x1d) < 0) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xfb;
    FUN_0e06da0c();
    if (iVar3 == 0) {
      uVar2 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar2 = getCurrentExceptionNumber();
        uVar2 = uVar2 & 0x1ff;
      }
      if ((uVar2 == 0) && (DAT_2300717c != DAT_23007170)) {
        FUN_0e0611cc();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06dd90. Types and names are inferred; NOT original source. */

void FUN_0e06dd90(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  FUN_0e06e768(param_1 + 0x18);
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((*(byte *)(param_1 + 0xd) & 0x10) == 0) {
    FUN_0e06db60(param_1,uVar3);
    return;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ddc4. Types and names are inferred; NOT original source. */

void FUN_0e06ddc4(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)((uint)*(byte *)(param_1 + 0xd) << 0x1b) < 0) {
    *(byte *)(param_1 + 0xd) = *(byte *)(param_1 + 0xd) & 0xef;
    FUN_0e06da0c();
    if (iVar3 == 0) {
      uVar2 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar2 = getCurrentExceptionNumber();
        uVar2 = uVar2 & 0x1ff;
      }
      if ((uVar2 == 0) && (DAT_2300717c != DAT_23007170)) {
        FUN_0e0611cc();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06de10. Types and names are inferred; NOT original source. */

void FUN_0e06de10(int *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_1[2] == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  iVar5 = *param_1;
  piVar4 = (int *)param_1[1];
  *piVar4 = iVar5;
  *(int **)(iVar5 + 4) = piVar4;
  *param_1 = 0;
  param_1[1] = 0;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfd;
  param_1[2] = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06de58. Types and names are inferred; NOT original source. */

void FUN_0e06de58(int *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar4 = *(byte *)((int)param_1 + 0xd);
  if (((char)param_1[0x1b] == '\0') || (param_2 == 0)) {
    *(undefined1 *)(param_1 + 0x1b) = 0;
    if ((bVar4 & 0x28) == 0) {
      if (param_1[2] != 0) {
        iVar5 = *param_1;
        piVar7 = (int *)param_1[1];
        *piVar7 = iVar5;
        *(int **)(iVar5 + 4) = piVar7;
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = bVar4 & 0x28;
        bVar4 = *(byte *)((int)param_1 + 0xd) & 0xfd;
      }
      if (param_2 == 0) {
        bVar3 = 0xfb;
      }
      else {
        bVar3 = 0xeb;
      }
      *(byte *)((int)param_1 + 0xd) = bVar4 & bVar3;
      FUN_0e06da0c();
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x1b) = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06dec8. Types and names are inferred; NOT original source. */

void FUN_0e06dec8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = DAT_23007170;
  DAT_23007188 = DAT_23007170;
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_0e06da74(DAT_23007170,param_3,param_3,uVar4);
  if (param_6 != -1 || param_5 != -1) {
    FUN_0e06e648(iVar3 + 0x18,&LAB_0e06daf4_1,param_5,param_6);
  }
  FUN_0e0611cc(param_2);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06df20. Types and names are inferred; NOT original source. */

int * FUN_0e06df20(int *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  piVar3 = (int *)*param_1;
  if ((param_1 != piVar3) && (piVar3 != (int *)0x0)) {
    iVar6 = *piVar3;
    piVar4 = (int *)piVar3[1];
    *piVar4 = iVar6;
    *(int **)(iVar6 + 4) = piVar4;
    *piVar3 = 0;
    piVar3[1] = 0;
    *(byte *)((int)piVar3 + 0xd) = *(byte *)((int)piVar3 + 0xd) & 0xfd;
    piVar3[2] = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    return piVar3;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return (int *)0x0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06df70. Types and names are inferred; NOT original source. */

int * FUN_0e06df70(int *param_1)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  piVar5 = (int *)*param_1;
  if (param_1 == piVar5) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return (int *)0x0;
  }
  if (piVar5 != (int *)0x0) {
    iVar4 = *piVar5;
    piVar3 = (int *)piVar5[1];
    *piVar3 = iVar4;
    *(int **)(iVar4 + 4) = piVar3;
    *piVar5 = 0;
    piVar5[1] = 0;
    *(byte *)((int)piVar5 + 0xd) = *(byte *)((int)piVar5 + 0xd) & 0xfd;
    piVar5[2] = 0;
    FUN_0e06e768(piVar5 + 6);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return piVar5;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06dfc8. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06dfc8(int *param_1,char param_2)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0) || (param_1[6] != 0)) {
    *(char *)((int)param_1 + 0xe) = param_2;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0x7f;
  piVar3 = (int *)param_1[1];
  iVar5 = *param_1;
  *piVar3 = iVar5;
  *(int **)(iVar5 + 4) = piVar3;
  *param_1 = 0;
  param_1[1] = 0;
  *(char *)((int)param_1 + 0xe) = param_2;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  piVar3 = DAT_23007180;
  if ((int **)DAT_23007180 == &DAT_23007180) {
    piVar3 = (int *)0x0;
  }
  for (; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    if ((param_2 != *(char *)((int)piVar3 + 0xe)) && (param_2 < *(char *)((int)piVar3 + 0xe))) {
      puVar4 = (undefined4 *)piVar3[1];
      *param_1 = (int)piVar3;
      param_1[1] = (int)puVar4;
      *puVar4 = param_1;
      piVar3[1] = (int)param_1;
      goto LAB_0e06e042;
    }
    if (piVar3 == DAT_23007184) break;
  }
  *param_1 = (int)&DAT_23007180;
  param_1[1] = (int)DAT_23007184;
  *DAT_23007184 = (int)param_1;
  DAT_23007184 = param_1;
LAB_0e06e042:
  if (((int **)DAT_23007180 == &DAT_23007180) || (piVar3 = DAT_23007180, DAT_23007180 == (int *)0x0)
     ) {
    piVar3 = DAT_23007174;
  }
  if (piVar3 != DAT_23007170) {
    FUN_0e06e4ec(piVar3);
  }
  DAT_2300717c = piVar3;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e078. Types and names are inferred; NOT original source. */

void FUN_0e06e078(undefined4 param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1ff;
    }
    if (uVar2 == 0) {
      if (DAT_2300717c != DAT_23007170) {
        FUN_0e0611cc();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e09c. Types and names are inferred; NOT original source. */

void FUN_0e06e09c(int param_1)

{
  bool bVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1ff;
    }
    if (uVar2 == 0) {
      if (DAT_2300717c != DAT_23007170) {
        FUN_0e0611cc();
        return;
      }
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(param_1);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e0c4. Types and names are inferred; NOT original source. */

void FUN_0e06e0c4(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  *(char *)(DAT_23007170 + 0xf) = *(char *)(DAT_23007170 + 0xf) + -1;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e0ec. Types and names are inferred; NOT original source. */

void FUN_0e06e0ec(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  *(char *)(DAT_23007170 + 0xf) = *(char *)(DAT_23007170 + 0xf) + '\x01';
  FUN_0e06d9cc(0);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar3 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (iVar3 == 0) {
    uVar2 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar2 = getCurrentExceptionNumber();
      uVar2 = uVar2 & 0x1ff;
    }
    if ((uVar2 == 0) && (DAT_2300717c != DAT_23007170)) {
      FUN_0e0611cc();
      return;
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(iVar3);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e148. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06e148(int *param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = (int *)*param_1;
  if ((piVar6 != param_1) && (piVar6 != (int *)0x0)) {
    do {
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      if (piVar6[2] != 0) {
        iVar5 = *piVar6;
        piVar4 = (int *)piVar6[1];
        *piVar4 = iVar5;
        *(int **)(iVar5 + 4) = piVar4;
        *piVar6 = 0;
        piVar6[1] = 0;
        *(byte *)((int)piVar6 + 0xd) = *(byte *)((int)piVar6 + 0xd) & 0xfd;
        piVar6[2] = 0;
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_0e06e768(piVar6 + 6,uVar3);
      uVar3 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar3 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_0e06da0c(piVar6);
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      piVar6 = (int *)*param_1;
    } while ((param_1 != piVar6) && (piVar6 != (int *)0x0));
    return 1;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e1cc. Types and names are inferred; NOT original source. */

void FUN_0e06e1cc(void)

{
  DAT_23007180 = &DAT_23007180;
  DAT_23007184 = &DAT_23007180;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e1dc. Types and names are inferred; NOT original source. */

void FUN_0e06e1dc(void)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  
  piVar6 = DAT_23007170;
  uVar7 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar7 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  piVar3 = (int *)DAT_23007170[1];
  *(byte *)((int)DAT_23007170 + 0xd) = *(byte *)((int)DAT_23007170 + 0xd) & 0x7f;
  iVar4 = *piVar6;
  *piVar3 = iVar4;
  *(int **)(iVar4 + 4) = piVar3;
  *piVar6 = 0;
  piVar6[1] = 0;
  piVar3 = DAT_23007170;
  *(byte *)((int)DAT_23007170 + 0xd) = *(byte *)((int)DAT_23007170 + 0xd) | 0x80;
  piVar6 = DAT_23007180;
  if ((int **)DAT_23007180 == &DAT_23007180) {
    piVar6 = (int *)0x0;
  }
  for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
    if ((*(char *)((int)piVar3 + 0xe) != *(char *)((int)piVar6 + 0xe)) &&
       (*(char *)((int)piVar3 + 0xe) < *(char *)((int)piVar6 + 0xe))) {
      puVar5 = (undefined4 *)piVar6[1];
      *piVar3 = (int)piVar6;
      piVar3[1] = (int)puVar5;
      *puVar5 = piVar3;
      piVar6[1] = (int)piVar3;
      goto LAB_0e06e242;
    }
    if (piVar6 == DAT_23007184) break;
  }
  *piVar3 = (int)&DAT_23007180;
  piVar3[1] = (int)DAT_23007184;
  *DAT_23007184 = (int)piVar3;
  DAT_23007184 = piVar3;
LAB_0e06e242:
  if (((int **)DAT_23007180 == &DAT_23007180) || (piVar6 = DAT_23007180, DAT_23007180 == (int *)0x0)
     ) {
    piVar6 = DAT_23007174;
  }
  if (piVar6 != DAT_23007170) {
    FUN_0e06e4ec(piVar6);
  }
  DAT_2300717c = piVar6;
  FUN_0e0611cc(uVar7);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e278. Types and names are inferred; NOT original source. */

int FUN_0e06e278(uint param_1,int param_2)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (param_1 == 0 && param_2 == 0) {
    FUN_0e06e1dc();
  }
  else {
    if ((int)((param_2 + 1) - (uint)(param_1 < 0xfffffffe)) < 0 ==
        (SBORROW4(param_2,-1) != SBORROW4(param_2 + 1,(uint)(param_1 < 0xfffffffe)))) {
      iVar5 = FUN_0e06e968();
      uVar6 = iVar5 + param_1;
    }
    else {
      uVar6 = -param_1 - 2;
    }
    piVar1 = DAT_23007170;
    uVar7 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar7 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    DAT_23007188 = DAT_23007170;
    if (*(char *)((int)DAT_23007170 + 0xd) < '\0') {
      *(byte *)((int)DAT_23007170 + 0xd) = *(byte *)((int)DAT_23007170 + 0xd) & 0x7f;
      iVar5 = *piVar1;
      piVar4 = (int *)piVar1[1];
      *piVar4 = iVar5;
      *(int **)(iVar5 + 4) = piVar4;
      *piVar1 = 0;
      piVar1[1] = 0;
      bVar2 = DAT_23007170 == piVar1;
    }
    else {
      bVar2 = true;
    }
    FUN_0e06d9cc(bVar2);
    FUN_0e06e648(DAT_23007170 + 6,&LAB_0e06daf4_1,param_1,param_2);
    *(byte *)((int)DAT_23007170 + 0xd) = *(byte *)((int)DAT_23007170 + 0xd) | 0x10;
    FUN_0e0611cc(uVar7);
    uVar3 = FUN_0e06e968();
    if ((int)(uint)(uVar6 - uVar3 == 0) <= (int)-(uint)(uVar6 < uVar3)) {
      return uVar6 - uVar3;
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e334. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06e334(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_23007170;
  if (param_2 == -1 && param_1 == -1) {
    FUN_0e06e768(DAT_23007170 + 0x18);
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if ((*(byte *)(iVar2 + 0xd) & 0x10) == 0) {
      FUN_0e06db60(iVar2,uVar4);
    }
    else {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    return 0xffffffff;
  }
  uVar3 = FUN_0e06e278();
  uVar4 = FUN_0e05ba10(uVar3 + 999,((int)uVar3 >> 0x1f) + (uint)(0xfffffc18 < uVar3),1000,0);
  return uVar4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e3a4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06e3a4(void)

{
  return DAT_23007170;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e3f4. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06e3f4(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  piVar5 = (int *)*param_1;
  if (param_1 == piVar5) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  if (piVar5 == (int *)0x0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0;
  }
  piVar5[5] = param_3;
  piVar3 = (int *)piVar5[1];
  iVar4 = *piVar5;
  piVar5[0x23] = param_2;
  *piVar3 = iVar4;
  *(int **)(iVar4 + 4) = piVar3;
  piVar5[2] = 0;
  *(byte *)((int)piVar5 + 0xd) = *(byte *)((int)piVar5 + 0xd) & 0xfd;
  *piVar5 = 0;
  piVar5[1] = 0;
  FUN_0e06e768(piVar5 + 6);
  FUN_0e06da0c(piVar5);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e460. Types and names are inferred; NOT original source. */

void FUN_0e06e460(void)

{
  undefined4 *in_stack_00000008;
  
  FUN_0e06dec8();
  if (in_stack_00000008 != (undefined4 *)0x0) {
    *in_stack_00000008 = *(undefined4 *)(DAT_23007170 + 0x14);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e484. Types and names are inferred; NOT original source. */

int FUN_0e06e484(int *param_1,code *param_2,undefined4 param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  piVar4 = (int *)*param_1;
  if (param_1 != piVar4) {
    for (; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      iVar3 = (*param_2)(piVar4,param_3);
      if (iVar3 != 0) goto LAB_0e06e4ba;
      if (piVar4 == (int *)param_1[1]) break;
    }
  }
  iVar3 = 0;
LAB_0e06e4ba:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar5);
  }
  InstructionSynchronizationBarrier(0xf);
  return iVar3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e4ec. Types and names are inferred; NOT original source. */

void FUN_0e06e4ec(undefined *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_23007178;
  iVar2 = uVar1 * 0x18 + 0x23002c60;
  FUN_0e06e768(iVar2);
  (&DAT_2300718c)[uVar1] = 0;
  if ((((*(ushort *)(param_1 + 0xe) < 0x80) && (DAT_23007194 != 0)) &&
      (DAT_23007190 <= (char)param_1[0xe])) &&
     (((param_1[0xd] & 0x1f) == 0 && (param_1 != &DAT_230029f8)))) {
    FUN_0e06e648(iVar2,&LAB_0e06e4c8_1,DAT_23007194 + -1,DAT_23007194 + -1 >> 0x1f);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e5d8. Types and names are inferred; NOT original source. */

void FUN_0e06e5d8(void)

{
  undefined4 in_r3;
  
  thunk_FUN_0e06f35c(&DAT_23000000,&PTR_DAT_0e070854,0x1e08);
  thunk_FUN_0e06f35c(&DAT_23000000,&PTR_DAT_0e070854,0);
  thunk_FUN_0e06f35c(ram_candidate_23020000,&DAT_0e05479c,0x7270,in_r3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e610. Types and names are inferred; NOT original source. */

void FUN_0e06e610(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = *param_1;
  if ((DAT_23000b4c != param_1) && (iVar3 != 0)) {
    uVar2 = *(uint *)(iVar3 + 0x10);
    uVar4 = param_1[4];
    iVar5 = param_1[5];
    *(uint *)(iVar3 + 0x10) = uVar2 + uVar4;
    *(uint *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar5 + (uint)CARRY4(uVar2,uVar4);
    iVar3 = *param_1;
  }
  piVar1 = (int *)param_1[1];
  *piVar1 = iVar3;
  *(int **)(iVar3 + 4) = piVar1;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e648. Types and names are inferred; NOT original source. */

void FUN_0e06e648(undefined4 *param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  
  if (param_4 == -1 && param_3 == 0xffffffff) {
    return;
  }
  param_1[2] = param_2;
  uVar7 = 0;
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    uVar7 = getBasePriority();
  }
  bVar8 = (bool)isCurrentModePrivileged();
  if ((bVar8) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if ((int)((param_4 + 1) - (uint)(param_3 != 0xffffffff)) < 0 ==
      (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != 0xffffffff)))) {
    uVar5 = param_3 + 1;
    iVar6 = param_4 + (uint)(0xfffffffe < param_3);
    if (DAT_23007198 == 0) {
      uVar3 = FUN_0e068568();
      bVar8 = CARRY4(uVar3,uVar5);
      uVar5 = uVar3 + uVar5;
      iVar6 = iVar6 + ((int)uVar3 >> 0x1f) + (uint)bVar8;
    }
  }
  else {
    uVar5 = (-DAT_23002c78 - 2) - param_3;
    iVar6 = (((-1 - DAT_23002c7c) - (uint)(0xfffffffe < DAT_23002c78)) - param_4) -
            (uint)(-DAT_23002c78 - 2 < param_3);
    if (iVar6 < (int)(uint)(uVar5 == 0)) {
      uVar5 = 1;
      iVar6 = 0;
    }
  }
  param_1[4] = uVar5;
  param_1[5] = iVar6;
  puVar4 = DAT_23000b4c;
  puVar1 = DAT_23000b48;
  if ((undefined4 **)DAT_23000b48 != &DAT_23000b48) {
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      uVar3 = puVar1[4];
      iVar2 = puVar1[5];
      if ((int)((iVar6 - iVar2) - (uint)(uVar5 < uVar3)) < 0 !=
          (SBORROW4(iVar6,iVar2) != SBORROW4(iVar6 - iVar2,(uint)(uVar5 < uVar3)))) {
        puVar1[4] = uVar3 - uVar5;
        puVar1[5] = (iVar2 - iVar6) - (uint)(uVar3 < uVar5);
        puVar4 = (undefined4 *)puVar1[1];
        *param_1 = puVar1;
        param_1[1] = puVar4;
        *puVar4 = param_1;
        puVar1[1] = param_1;
        goto LAB_0e06e6d8;
      }
      bVar8 = uVar5 < uVar3;
      uVar5 = uVar5 - uVar3;
      iVar6 = (iVar6 - iVar2) - (uint)bVar8;
      param_1[4] = uVar5;
      param_1[5] = iVar6;
      if (puVar4 == puVar1) break;
    }
  }
  *param_1 = &DAT_23000b48;
  param_1[1] = puVar4;
  *puVar4 = param_1;
  DAT_23000b4c = param_1;
LAB_0e06e6d8:
  if ((((undefined4 **)DAT_23000b48 != &DAT_23000b48) && (param_1 == DAT_23000b48)) &&
     (DAT_23007198 == 0)) {
    uVar3 = FUN_0e068568();
    uVar5 = param_1[4] - uVar3;
    iVar6 = (param_1[5] - ((int)uVar3 >> 0x1f)) - (uint)((uint)param_1[4] < uVar3);
    if (iVar6 < 0) {
      uVar5 = 0;
      iVar6 = 0;
    }
    bVar8 = uVar5 < 0x80000000;
    if ((int)(uint)bVar8 <= iVar6) {
      uVar5 = 0x7fffffff;
    }
    FUN_0e068584(uVar5,0,param_1[5],iVar6 - (uint)bVar8,param_4);
    bVar8 = (bool)isCurrentModePrivileged();
    if (bVar8) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    return;
  }
  bVar8 = (bool)isCurrentModePrivileged();
  if (bVar8) {
    setBasePriority(uVar7);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e768. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06e768(int *param_1)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  
  puVar2 = DAT_23000b48;
  uVar8 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar8 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*param_1 == 0) {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar8);
    }
    InstructionSynchronizationBarrier(0xf);
    return 0xffffffea;
  }
  if ((undefined4 **)DAT_23000b48 == &DAT_23000b48) {
    FUN_0e06e610();
    goto LAB_0e06e78e;
  }
  puVar4 = (undefined4 *)FUN_0e06e610();
  puVar3 = DAT_23000b48;
  if (puVar4 != puVar2) goto LAB_0e06e78e;
  if ((undefined4 **)DAT_23000b48 == &DAT_23000b48) {
    if (DAT_23007198 == 0) {
      FUN_0e068568();
    }
LAB_0e06e7e8:
    uVar7 = 0x7fffffff;
  }
  else {
    if (DAT_23007198 == 0) {
      uVar5 = FUN_0e068568();
    }
    else {
      uVar5 = 0;
    }
    if (puVar3 == (undefined4 *)0x0) goto LAB_0e06e7e8;
    uVar7 = puVar3[4] - uVar5;
    iVar6 = (puVar3[5] - ((int)uVar5 >> 0x1f)) - (uint)((uint)puVar3[4] < uVar5);
    if ((int)(uint)(uVar7 < 0x80000000) <= iVar6) goto LAB_0e06e7e8;
    if (iVar6 < 0) {
      uVar7 = 0;
    }
  }
  FUN_0e068584(uVar7,0);
LAB_0e06e78e:
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar8);
  }
  InstructionSynchronizationBarrier(0xf);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e7fc. Types and names are inferred; NOT original source. */

void FUN_0e06e7fc(uint param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  bool bVar10;
  
  uVar9 = 0;
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    uVar9 = getBasePriority();
  }
  bVar10 = (bool)isCurrentModePrivileged();
  if ((bVar10) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x40 < uVar7)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  DAT_23007198 = DAT_23000b48;
  if ((undefined4 **)DAT_23000b48 == &DAT_23000b48) {
LAB_0e06e8e8:
    DAT_23007198 = (undefined4 *)0x0;
    bVar10 = CARRY4(DAT_23002c78,param_1);
    DAT_23002c78 = DAT_23002c78 + param_1;
    DAT_23002c7c = DAT_23002c7c + ((int)param_1 >> 0x1f) + (uint)bVar10;
LAB_0e06e8fc:
    FUN_0e068568();
LAB_0e06e900:
    uVar6 = 0x7fffffff;
  }
  else {
    if (DAT_23000b48 == (undefined4 *)0x0) {
      bVar10 = CARRY4(DAT_23002c78,param_1);
      DAT_23002c78 = DAT_23002c78 + param_1;
      DAT_23002c7c = DAT_23002c7c + ((int)param_1 >> 0x1f) + (uint)bVar10;
      goto LAB_0e06e8fc;
    }
    do {
      puVar1 = DAT_23000b48;
      uVar7 = DAT_23000b48[4];
      iVar5 = DAT_23000b48[5];
      iVar4 = (int)param_1 >> 0x1f;
      if ((int)((iVar4 - iVar5) - (uint)(param_1 < uVar7)) < 0 !=
          (SBORROW4(iVar4,iVar5) != SBORROW4(iVar4 - iVar5,(uint)(param_1 < uVar7)))) {
        DAT_23000b48[4] = uVar7 - param_1;
        puVar8 = DAT_23000b48;
        puVar1[5] = (iVar5 - iVar4) - (uint)(uVar7 < param_1);
        goto LAB_0e06e896;
      }
      bVar10 = CARRY4(DAT_23002c78,uVar7);
      DAT_23002c78 = DAT_23002c78 + uVar7;
      DAT_23002c7c = DAT_23002c7c + ((int)uVar7 >> 0x1f) + (uint)bVar10;
      DAT_23007198 = (undefined4 *)param_1;
      DAT_23000b48[4] = 0;
      puVar1[5] = 0;
      iVar4 = FUN_0e06e610();
      bVar10 = (bool)isCurrentModePrivileged();
      if (bVar10) {
        setBasePriority(uVar9);
      }
      InstructionSynchronizationBarrier(0xf);
      (**(code **)(iVar4 + 8))();
      uVar9 = 0;
      bVar10 = (bool)isCurrentModePrivileged();
      if (bVar10) {
        uVar9 = getBasePriority();
      }
      bVar10 = (bool)isCurrentModePrivileged();
      if ((bVar10) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      param_1 = (int)DAT_23007198 - uVar7;
      if ((undefined4 **)DAT_23000b48 == &DAT_23000b48) goto LAB_0e06e8e8;
    } while (DAT_23000b48 != (undefined4 *)0x0);
    iVar4 = (int)param_1 >> 0x1f;
    puVar8 = DAT_23000b48;
LAB_0e06e896:
    DAT_23007198 = (undefined4 *)0x0;
    bVar10 = CARRY4(DAT_23002c78,param_1);
    DAT_23002c78 = DAT_23002c78 + param_1;
    DAT_23002c7c = DAT_23002c7c + iVar4 + (uint)bVar10;
    if ((undefined4 **)puVar8 == &DAT_23000b48) goto LAB_0e06e8fc;
    uVar7 = FUN_0e068568();
    if (puVar8 == (undefined4 *)0x0) goto LAB_0e06e900;
    uVar6 = puVar8[4] - uVar7;
    iVar4 = (puVar8[5] - ((int)uVar7 >> 0x1f)) - (uint)((uint)puVar8[4] < uVar7);
    if ((int)(uint)(uVar6 < 0x80000000) <= iVar4) goto LAB_0e06e900;
    if (iVar4 < 0) {
      uVar6 = 0;
    }
  }
  FUN_0e068584(uVar6,0);
  puVar2 = DAT_23007170;
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar9 = 0;
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    uVar9 = getBasePriority();
  }
  bVar10 = (bool)isCurrentModePrivileged();
  if ((bVar10) && (uVar7 = getBasePriority(), uVar7 == 0 || 0x40 < uVar7)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  puVar3 = DAT_23007188;
  if (DAT_23007188 != DAT_23007170) {
    DAT_23007188 = (undefined *)0x0;
    if (((((&DAT_2300718c)[DAT_23007178] == '\0') || (0x7f < *(ushort *)(DAT_23007170 + 0xe))) ||
        (DAT_23007194 == 0)) ||
       ((((char)DAT_23007170[0xe] < DAT_23007190 || ((DAT_23007170[0xd] & 0x1f) != 0)) ||
        (DAT_23007170 == &DAT_230029f8)))) goto LAB_0e06e5b4;
    FUN_0e06dca8(DAT_23007170);
    puVar3 = puVar2;
  }
  FUN_0e06e4ec(puVar3);
LAB_0e06e5b4:
  bVar10 = (bool)isCurrentModePrivileged();
  if (bVar10) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e928. Types and names are inferred; NOT original source. */

undefined8 FUN_0e06e928(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (DAT_23007198 == 0) {
    uVar2 = FUN_0e068568();
    iVar3 = (int)uVar2 >> 0x1f;
  }
  else {
    uVar2 = 0;
    iVar3 = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return CONCAT44(iVar3 + DAT_23002c7c + (uint)CARRY4(uVar2,DAT_23002c78),uVar2 + DAT_23002c78);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e968. Types and names are inferred; NOT original source. */

int FUN_0e06e968(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (DAT_23007198 == 0) {
    iVar3 = FUN_0e068568();
  }
  else {
    iVar3 = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return iVar3 + DAT_23002c78;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e9a0. Types and names are inferred; NOT original source. */

undefined8 FUN_0e06e9a0(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (DAT_23007198 == 0) {
    uVar2 = FUN_0e068568();
    iVar3 = (int)uVar2 >> 0x1f;
  }
  else {
    uVar2 = 0;
    iVar3 = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  return CONCAT44(iVar3 + DAT_23002c7c + (uint)CARRY4(uVar2,DAT_23002c78),uVar2 + DAT_23002c78);
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06e9e0. Types and names are inferred; NOT original source. */

int * FUN_0e06e9e0(int *param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_4 == -1 && param_3 == 0xffffffff) {
    *param_1 = -1;
    param_1[1] = -1;
    return param_1;
  }
  if (param_3 == 0 && param_4 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    return param_1;
  }
  iVar4 = -2 - param_3;
  iVar3 = (-1 - param_4) - (uint)(0xfffffffe < param_3);
  if (iVar3 < 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (DAT_23007198 == 0) {
      uVar2 = FUN_0e068568();
      iVar3 = (int)uVar2 >> 0x1f;
    }
    else {
      uVar2 = 0;
      iVar3 = 0;
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar4 = uVar2 + DAT_23002c78 + param_3;
    iVar3 = iVar3 + DAT_23002c7c + (uint)CARRY4(uVar2,DAT_23002c78) +
            param_4 + (uint)CARRY4(uVar2 + DAT_23002c78,param_3);
  }
  *param_1 = iVar4;
  param_1[1] = iVar3;
  return param_1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ea70. Types and names are inferred; NOT original source. */

int * FUN_0e06ea70(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_4 == 0xffffffff && param_3 == 0xffffffff) {
    *param_1 = -1;
    param_1[1] = -1;
    return param_1;
  }
  if (param_4 != 0 || param_3 != 0) {
    uVar5 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar5 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (DAT_23007198 == 0) {
      uVar2 = FUN_0e068568();
      iVar4 = (int)uVar2 >> 0x1f;
    }
    else {
      uVar2 = 0;
      iVar4 = 0;
    }
    uVar3 = uVar2 + DAT_23002c78;
    uVar2 = iVar4 + DAT_23002c7c + (uint)CARRY4(uVar2,DAT_23002c78);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    if (uVar2 <= param_4 && (uint)(param_3 <= uVar3) <= uVar2 - param_4) {
      *param_1 = param_3 - uVar3;
      param_1[1] = (param_4 - uVar2) - (uint)(param_3 < uVar3);
      return param_1;
    }
  }
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ebe0. Types and names are inferred; NOT original source. */

void FUN_0e06ebe0(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  uVar2 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    uVar2 = getBasePriority();
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if ((bVar4) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  if (param_4 != -1 || param_3 != -1) {
    iVar3 = param_4;
    if ((int)((param_4 + 1) - (uint)(param_3 != -1)) < 0 ==
        (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != -1)))) {
      if (param_4 < (int)(uint)(param_3 == 0)) {
        param_3 = 1;
        iVar3 = 0;
      }
      bVar4 = param_3 != 0;
      param_3 = param_3 + -1;
      iVar3 = iVar3 + -1 + (uint)bVar4;
    }
    FUN_0e06e768(param_1);
    *(undefined4 *)(param_1 + 0x28) = param_5;
    *(undefined4 *)(param_1 + 0x2c) = param_6;
    *(undefined4 *)(param_1 + 0x30) = 0;
    FUN_0e06e648(param_1,&LAB_0e06eb00_1,param_3,iVar3,param_4);
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    setBasePriority(uVar2);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ec54. Types and names are inferred; NOT original source. */

void FUN_0e06ec54(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_0e06e768();
  if (iVar3 == 0) {
    if (*(code **)(param_1 + 0x24) != (code *)0x0) {
      (**(code **)(param_1 + 0x24))(param_1);
    }
    iVar3 = FUN_0e06df20(param_1 + 0x18);
    if (iVar3 != 0) {
      FUN_0e06dd24();
      uVar4 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar4 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      FUN_0e06e09c(uVar4);
      return;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ed7c. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06ed7c(int param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = param_2[1] & *(uint *)(param_1 + 100);
  if ((*(uint *)(param_1 + 0x68) & 1) == 0) {
    if (uVar1 != 0) {
LAB_0e06ed9c:
      *(undefined1 *)(param_1 + 0x6c) = 1;
      *(int *)(param_1 + 0x60) = *param_2;
      *param_2 = param_1;
      FUN_0e06e768(param_1 + 0x18);
      return 0;
    }
  }
  else if (*(uint *)(param_1 + 100) == uVar1) goto LAB_0e06ed9c;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06edb4. Types and names are inferred; NOT original source. */

void FUN_0e06edb4(int param_1)

{
  *(int *)param_1 = param_1;
  *(undefined4 *)(param_1 + 8) = 0;
  *(int *)(param_1 + 4) = param_1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06edc0. Types and names are inferred; NOT original source. */

uint FUN_0e06edc0(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iStack_28;
  uint uStack_24;
  
  iStack_28 = 0;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = *(uint *)(param_1 + 8);
  uVar5 = (param_2 ^ uVar3) & param_2 ^ uVar3;
  *(uint *)(param_1 + 8) = uVar5;
  uStack_24 = uVar5;
  FUN_0e06e484(param_1,0xe06ed7d,&iStack_28);
  iVar2 = iStack_28;
  while (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x8c) = 0;
    *(uint *)(iVar2 + 100) = uVar5;
    iVar4 = *(int *)(iVar2 + 0x60);
    FUN_0e06de58(iVar2,0);
    iVar2 = iVar4;
  }
  FUN_0e06e078(param_1 + 0xc,uVar6);
  return uVar3 & param_2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06edd4. Types and names are inferred; NOT original source. */

uint FUN_0e06edd4(int param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iStack_28;
  uint uStack_24;
  
  iStack_28 = 0;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  uVar3 = *(uint *)(param_1 + 8);
  uVar5 = uVar3 & param_2 ^ uVar3;
  *(uint *)(param_1 + 8) = uVar5;
  uStack_24 = uVar5;
  FUN_0e06e484(param_1,0xe06ed7d,&iStack_28);
  iVar2 = iStack_28;
  while (iVar2 != 0) {
    *(undefined4 *)(iVar2 + 0x8c) = 0;
    *(uint *)(iVar2 + 100) = uVar5;
    iVar4 = *(int *)(iVar2 + 0x60);
    FUN_0e06de58(iVar2,0);
    iVar2 = iVar4;
  }
  FUN_0e06e078(param_1 + 0xc,uVar6);
  return uVar3 & param_2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06eddc. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x0e06ed74) */
/* WARNING: Removing unreachable block (ram,0x0e06ed78) */

uint FUN_0e06eddc(int param_1,uint param_2,int param_3,undefined4 param_4,uint param_5,uint param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (param_2 != 0) {
    iVar2 = FUN_0e06e3a4();
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    if (param_3 << 0x1f < 0) {
      *(undefined4 *)(param_1 + 8) = 0;
    }
    else {
      uVar5 = *(uint *)(param_1 + 8) & param_2;
      if (uVar5 != 0) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar4);
        }
        InstructionSynchronizationBarrier(0xf);
        return uVar5;
      }
    }
    if ((param_5 | param_6) == 0) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
    }
    else {
      *(uint *)(iVar2 + 100) = param_2;
      *(int *)(iVar2 + 0x68) = param_3 << 1;
      iVar3 = FUN_0e06dec8(param_1 + 0xc,uVar4,param_1,param_5 | param_6,param_5,param_6);
      if (iVar3 == 0) {
        return param_2 & *(uint *)(iVar2 + 100);
      }
    }
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ede4. Types and names are inferred; NOT original source. */

void FUN_0e06ede4(int param_1)

{
  if (param_1 != 0) {
    FUN_0e06ca58(*(undefined4 *)(param_1 + -4),param_1 + -4);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06edf4. Types and names are inferred; NOT original source. */

undefined4 * FUN_0e06edf4(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  if (0xfffffffb < param_1) {
    return (undefined4 *)0x0;
  }
  puVar1 = (undefined4 *)FUN_0e06c9d0(&DAT_23001b64,4,param_1 + 4,param_4,0,0);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &DAT_23001b64;
    return puVar1 + 1;
  }
  return (undefined4 *)0x0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ee28. Types and names are inferred; NOT original source. */

void FUN_0e06ee28(int param_1)

{
  *(undefined **)(param_1 + 0x80) = &DAT_23001b64;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06ee34. Types and names are inferred; NOT original source. */

undefined4 * FUN_0e06ee34(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int extraout_r3;
  undefined *puVar3;
  
  iVar1 = FUN_0e06d830();
  if (iVar1 == 0) {
    puVar3 = *(undefined **)(DAT_23007170 + 0x80);
    iVar1 = DAT_23007170;
    if (puVar3 == (undefined *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  else {
    puVar3 = &DAT_23001b64;
    iVar1 = extraout_r3;
  }
  if ((param_2 < 0xfffffffc) &&
     (puVar2 = (undefined4 *)FUN_0e06c9d0(puVar3,param_1 | 4,param_2 + 4,iVar1,0,0),
     puVar2 != (undefined4 *)0x0)) {
    *puVar2 = puVar3;
    return puVar2 + 1;
  }
  return (undefined4 *)0x0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06eea8. Types and names are inferred; NOT original source. */

/* WARNING: Type propagation algorithm not settling */

char * FUN_0e06eea8(int param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  byte *pbVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  uint uVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  uint uVar18;
  bool bVar19;
  uint local_54;
  byte *local_4c;
  undefined4 local_44;
  char local_40 [28];
  
  pcVar5 = *(code **)(param_1 + 4);
  if ((int)((uint)*(byte *)(param_1 + 2) << 0x1e) < 0) {
    pcVar8 = (char *)0x0;
    do {
      while( true ) {
        uVar12 = (uint)*param_2;
        if (uVar12 == 0) {
          return pcVar8;
        }
        if (uVar12 != 0x25) break;
        uVar12 = (uint)param_2[1];
        local_4c = param_2 + 2;
        if (uVar12 == 0x25) goto LAB_0e06eed0;
        uVar15 = 0;
        uVar17 = 0;
        puVar9 = param_3;
        uVar7 = 0;
        do {
          param_3 = puVar9;
          uVar14 = uVar7;
          if (uVar17 < 0x20) {
            switch(uVar12) {
            default:
              if (9 < uVar12 - 0x30) goto LAB_0e06ef20;
LAB_0e06ef88:
              uVar17 = uVar17 | 0x20;
              uVar15 = uVar15 * 10 + (uVar12 - 0x30);
              break;
            case 0x23:
              uVar17 = uVar17 | 0x10;
              break;
            case 0x27:
              break;
            case 0x2b:
              uVar17 = uVar17 | 2;
            case 0x20:
              uVar17 = uVar17 | 4;
              break;
            case 0x2d:
              uVar17 = uVar17 | 8;
              break;
            case 0x30:
              uVar17 = uVar17 | 1;
            }
          }
          else {
            if (uVar17 < 0x80) {
              if (uVar12 - 0x30 < 10) {
                if ((uVar17 & 0x40) == 0) goto LAB_0e06ef88;
                uVar14 = uVar7 * 10 + (uVar12 - 0x30);
              }
              else {
LAB_0e06ef20:
                if (uVar12 == 0x2a) {
                  param_3 = puVar9 + 1;
                  uVar12 = *puVar9;
                  uVar14 = uVar12;
                  if ((uVar17 & 0x40) == 0) {
                    if ((int)uVar12 < 0) {
                      uVar15 = -uVar12;
                      uVar17 = uVar17 | 0x28;
                      uVar14 = uVar7;
                    }
                    else {
                      uVar17 = uVar17 | 0x20;
                      uVar14 = uVar7;
                      uVar15 = uVar12;
                    }
                  }
                }
                else {
                  if (uVar12 != 0x2e) goto LAB_0e06efa6;
                  if ((uVar17 & 0x40) != 0) {
                    return pcVar8;
                  }
                  uVar17 = uVar17 | 0x40;
                }
              }
              goto switchD_0e06ef02_caseD_27;
            }
LAB_0e06efa6:
            if (uVar12 == 0x6c) {
              if ((uVar17 & 0x80) != 0) {
                uVar17 = uVar17 | 0x200;
              }
              uVar17 = uVar17 | 0x80;
            }
            else if (uVar12 < 0x6d) {
              if (uVar12 == 0x68) {
                if ((uVar17 & 0x100) != 0) {
                  uVar17 = uVar17 | 0x200;
                }
                uVar17 = uVar17 | 0x100;
              }
              else {
                if ((uVar12 != 0x6a) && (uVar12 != 0x4c)) break;
                uVar17 = uVar17 | 0x280;
              }
            }
            else if ((uVar12 != 0x74) && (uVar12 != 0x7a)) break;
          }
switchD_0e06ef02_caseD_27:
          pbVar6 = local_4c + 1;
          uVar12 = (uint)*local_4c;
          puVar9 = param_3;
          uVar7 = uVar14;
          local_4c = pbVar6;
        } while (uVar12 != 0);
        uVar7 = uVar12 | 0x20;
        if ((int)uVar14 < 0) {
          uVar17 = uVar17 & 0xffffffbf;
          uVar14 = 0;
        }
        if ((uVar7 - 0x65 < 3) || (uVar7 == 0x61)) {
          uVar12 = 7;
          pcVar16 = "*float*";
          puVar9 = (uint *)(((int)param_3 + 7U & 0xfffffff8) + 8);
          goto LAB_0e06efe6;
        }
        uVar18 = uVar14;
        local_54 = uVar14;
        switch(uVar12) {
        case 99:
          puVar9 = param_3 + 1;
          uVar12 = 1;
          pcVar16 = local_40;
          local_40[0] = (char)*param_3;
          goto LAB_0e06efe6;
        case 100:
        case 0x69:
          if ((uVar17 & 0x80) == 0) {
            puVar9 = param_3 + 1;
            uVar2 = *param_3;
            if ((uVar17 & 0x100) == 0) goto LAB_0e06f150;
            if ((uVar17 & 0x200) == 0) {
              iVar1 = uVar2 << 0x10;
              uVar2 = (int)(short)uVar2;
            }
            else {
              iVar1 = uVar2 << 0x18;
              uVar2 = (int)(char)uVar2;
            }
            uVar4 = iVar1 >> 0x1f;
          }
          else if ((uVar17 & 0x200) == 0) {
            uVar2 = *param_3;
LAB_0e06f150:
            puVar9 = param_3 + 1;
            uVar4 = (int)uVar2 >> 0x1f;
          }
          else {
            puVar10 = (uint *)((int)param_3 + 7U & 0xfffffff8);
            uVar4 = puVar10[1];
            puVar9 = puVar10 + 2;
            uVar2 = *puVar10;
          }
          uVar11 = uVar17 & 0xffffffef;
          if ((int)uVar4 < 0) {
            bVar19 = uVar2 != 0;
            uVar2 = -uVar2;
            uVar11 = uVar11 | 0x400;
            uVar4 = -uVar4 - (uint)bVar19;
LAB_0e06f112:
            uVar7 = 10;
            goto LAB_0e06f118;
          }
          if (((uVar2 != 0 || uVar4 != 0) || ((uVar17 & 0x40) == 0)) || (uVar14 != 0))
          goto LAB_0e06f112;
          uVar17 = uVar17 & 0xffffffee;
          goto LAB_0e06f192;
        default:
          if (uVar7 == 0x78) {
            uVar7 = 0x78 - uVar12 | 0x10;
            break;
          }
          iVar1 = (*pcVar5)(0x25,param_1);
          if (-1 < iVar1) {
            pcVar8 = pcVar8 + 2;
            goto LAB_0e06eed2;
          }
          goto LAB_0e06f0cc;
        case 0x6f:
          uVar7 = 8;
          uVar12 = 0;
          break;
        case 0x70:
          uVar17 = uVar17 | 0x10;
          uVar7 = 0x10;
          uVar12 = 0x78;
          break;
        case 0x73:
          puVar9 = param_3 + 1;
          pcVar16 = (char *)*param_3;
          if (pcVar16 == (char *)0x0) {
            pcVar16 = "(null)";
          }
          if ((uVar17 & 0x40) == 0) {
            uVar14 = 0xffffffff;
          }
          uVar12 = FUN_0e06b44c(pcVar16,uVar14);
LAB_0e06efe6:
          uVar7 = uVar15;
          if ((uVar17 & 8) == 0) {
            for (; uVar12 < uVar7; uVar7 = uVar7 - 1) {
              iVar1 = (*pcVar5)(0x20,param_1);
              if (iVar1 < 0) goto LAB_0e06f0cc;
            }
            pcVar8 = pcVar8 + (uVar15 - uVar7);
          }
          pcVar13 = pcVar16;
          while (pcVar13 != pcVar16 + uVar12) {
            iVar1 = (*pcVar5)(*pcVar13,param_1);
            pcVar13 = pcVar13 + 1;
            if (iVar1 < 0) goto LAB_0e06f0cc;
          }
          iVar1 = uVar7 - uVar12;
          pcVar8 = pcVar13 + ((int)pcVar8 - (int)pcVar16);
          param_3 = puVar9;
          pcVar16 = pcVar8;
          goto LAB_0e06f352;
        case 0x75:
          uVar17 = uVar17 & 0xffffffef;
          uVar7 = 10;
        }
        if ((uVar17 & 0x80) == 0) {
          puVar9 = param_3 + 1;
          uVar2 = *param_3;
          uVar4 = 0;
          if ((uVar17 & 0x100) != 0) {
            if ((uVar17 & 0x200) == 0) {
              uVar2 = uVar2 & 0xffff;
            }
            else {
              uVar2 = uVar2 & 0xff;
            }
            uVar4 = 0;
          }
        }
        else if ((uVar17 & 0x200) == 0) {
          puVar9 = param_3 + 1;
          uVar2 = *param_3;
          uVar4 = 0;
        }
        else {
          puVar10 = (uint *)((int)param_3 + 7U & 0xfffffff8);
          uVar4 = puVar10[1];
          puVar9 = puVar10 + 2;
          uVar2 = *puVar10;
        }
        if (uVar2 == 0 && uVar4 == 0) {
          uVar11 = uVar17 & 0xffffffe9;
          if (((uVar17 & 0x40) == 0) || (uVar14 != 0)) goto LAB_0e06f118;
          uVar17 = uVar17 & 0xffffffe8;
LAB_0e06f1ee:
          uVar11 = uVar17 & 0x10;
          uVar18 = local_54;
          if (uVar11 == 0) {
LAB_0e06f192:
            if ((uVar17 & 0x406) != 0) {
              uVar18 = uVar18 + 1;
            }
            uVar11 = 0;
          }
          else {
            if (uVar12 != 0) goto LAB_0e06f280;
            uVar18 = local_54 + 1;
          }
        }
        else {
          uVar11 = uVar17 & 0xfffffff9;
LAB_0e06f118:
          iVar1 = FUN_0e06f3fe(uVar2,uVar4,local_40,uVar7);
          local_54 = iVar1 - (int)local_40;
          uVar17 = uVar11;
          if ((-1 < (int)(uVar11 << 0x19)) ||
             (uVar17 = uVar11 & 0xfffffffe, (int)uVar14 <= (int)local_54)) goto LAB_0e06f1ee;
          if (uVar12 == 0) {
            uVar17 = uVar11 & 0xffffffee;
            goto LAB_0e06f192;
          }
          uVar11 = uVar11 & 0x10;
          if (uVar11 == 0) goto LAB_0e06f192;
LAB_0e06f280:
          uVar18 = uVar18 + 2;
        }
        if (-1 < (int)(uVar17 << 0x1c)) {
          uVar7 = uVar18;
          if (((int)(uVar17 << 0x1f) < 0) && (uVar14 = local_54, (int)uVar18 < (int)uVar15)) {
            iVar1 = uVar15 - uVar18;
            uVar18 = uVar15;
            uVar7 = uVar15;
            uVar14 = iVar1 + local_54;
          }
          for (; (int)uVar18 < (int)uVar15; uVar18 = uVar18 + 1) {
            local_44 = uVar11;
            iVar1 = (*pcVar5)(0x20,param_1);
            if (iVar1 < 0) goto LAB_0e06f0cc;
            uVar11 = local_44;
          }
          pcVar8 = pcVar8 + (uVar18 - uVar7);
        }
        if (uVar11 == 0) {
          pcVar16 = pcVar8;
          if ((uVar17 & 0x406) != 0) {
            pcVar8 = pcVar8 + 1;
            if ((uVar17 & 2) == 0) {
              uVar12 = 0x20;
            }
            else {
              uVar12 = 0x2b;
            }
            if ((uVar17 & 0x400) != 0) {
              uVar12 = 0x2d;
            }
            goto LAB_0e06f2f4;
          }
        }
        else {
          iVar1 = (*pcVar5)(0x30,param_1);
          if (iVar1 < 0) goto LAB_0e06f0cc;
          if (uVar12 != 0) {
            pcVar8 = pcVar8 + 2;
LAB_0e06f2f4:
            iVar1 = (*pcVar5)(uVar12,param_1);
            pcVar16 = pcVar8;
            goto joined_r0x0e06f2fa;
          }
          pcVar8 = pcVar8 + 1;
          pcVar16 = pcVar8;
        }
        while (uVar12 = local_54, (int)local_54 < (int)(pcVar16 + (uVar14 - (int)pcVar8))) {
          pcVar8 = pcVar8 + 1;
          iVar1 = (*pcVar5)(0x30,param_1);
joined_r0x0e06f2fa:
          if (iVar1 < 0) goto LAB_0e06f0cc;
        }
        while (uVar12 != 0) {
          iVar1 = (*pcVar5)(local_40[uVar12 - 1],param_1);
          uVar12 = uVar12 - 1;
          if (iVar1 < 0) goto LAB_0e06f0cc;
        }
        iVar1 = uVar15 - uVar18;
        pcVar8 = pcVar8 + local_54;
        param_3 = puVar9;
        pcVar16 = pcVar8;
LAB_0e06f352:
        while (param_2 = local_4c, 0 < (int)(pcVar16 + (iVar1 - (int)pcVar8))) {
          pcVar8 = pcVar8 + 1;
          iVar3 = (*pcVar5)(0x20,param_1);
          if (iVar3 < 0) goto LAB_0e06f0cc;
        }
      }
      local_4c = param_2 + 1;
LAB_0e06eed0:
      pcVar8 = pcVar8 + 1;
LAB_0e06eed2:
      iVar1 = (*pcVar5)(uVar12,param_1);
      param_2 = local_4c;
    } while (-1 < iVar1);
LAB_0e06f0cc:
    *(byte *)(param_1 + 2) = *(byte *)(param_1 + 2) | 4;
  }
  return (char *)0xffffffff;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f35c. Types and names are inferred; NOT original source. */

void FUN_0e06f35c(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  
  puVar2 = param_2 + param_3;
  puVar3 = (undefined1 *)(param_1 + -1);
  if (param_2 != puVar2) {
    do {
      puVar1 = param_2 + 1;
      puVar3 = puVar3 + 1;
      *puVar3 = *param_2;
      param_2 = puVar1;
    } while (puVar1 != puVar2);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f376. Types and names are inferred; NOT original source. */

void FUN_0e06f376(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = param_2 + param_3;
  if ((param_2 < param_1) && (param_1 < puVar2)) {
    puVar1 = param_1 + param_3;
    while (puVar1 != param_1) {
      puVar2 = puVar2 + -1;
      puVar1 = puVar1 + -1;
      *puVar1 = *puVar2;
    }
  }
  else {
    param_1 = param_1 + -1;
    for (; param_2 != puVar2; param_2 = param_2 + 1) {
      param_1 = param_1 + 1;
      *param_1 = *param_2;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f3aa. Types and names are inferred; NOT original source. */

void FUN_0e06f3aa(undefined1 *param_1,undefined1 param_2,int param_3)

{
  undefined1 *puVar1;
  
  puVar1 = param_1 + param_3;
  for (; param_1 != puVar1; param_1 = param_1 + 1) {
    *param_1 = param_2;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f3ba. Types and names are inferred; NOT original source. */

int FUN_0e06f3ba(byte *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = (byte *)(param_2 + -1);
  pbVar2 = param_1 + param_3;
  while( true ) {
    if (param_1 == pbVar2) {
      return 0;
    }
    pbVar1 = pbVar1 + 1;
    if ((uint)*param_1 != (uint)*pbVar1) break;
    param_1 = param_1 + 1;
  }
  return (uint)*param_1 - (uint)*pbVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f3da. Types and names are inferred; NOT original source. */

int FUN_0e06f3da(byte *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    pbVar3 = (byte *)(param_2 + -1);
    pbVar1 = param_1;
    do {
      uVar4 = (uint)*pbVar1;
      pbVar3 = pbVar3 + 1;
      if ((uVar4 != *pbVar3) || (pbVar1 + 1 == param_1 + param_3)) break;
      pbVar1 = pbVar1 + 1;
    } while (uVar4 != 0);
    iVar2 = uVar4 - *pbVar3;
  }
  return iVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f3fe. Types and names are inferred; NOT original source. */

void FUN_0e06f3fe(uint param_1,uint param_2,char *param_3,byte param_4)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  
  do {
    uVar6 = param_1 & 0xff;
    if ((param_4 & 0x1f) == 8) {
      bVar2 = (byte)param_1 & 7;
      param_1 = param_1 >> 3 | param_2 << 0x1d;
      param_2 = param_2 >> 3;
    }
    else {
      if ((param_4 & 0x1f) == 0x10) {
        uVar6 = param_1 & 0xf;
        param_1 = param_1 >> 4 | param_2 << 0x1c;
        param_2 = param_2 >> 4;
      }
      else {
        uVar3 = param_1 >> 1 | param_2 << 0x1f;
        uVar1 = param_1 >> 2 | param_2 << 0x1e;
        uVar4 = uVar3 + uVar1;
        uVar3 = (param_2 >> 2) + (param_2 >> 1) + (uint)CARRY4(uVar3,uVar1);
        uVar1 = uVar4 >> 4 | uVar3 * 0x10000000;
        uVar5 = uVar4 + uVar1;
        uVar3 = uVar3 + (uVar3 >> 4) + (uint)CARRY4(uVar4,uVar1);
        uVar1 = uVar5 >> 8 | uVar3 * 0x1000000;
        uVar4 = uVar5 + uVar1;
        uVar3 = uVar3 + (uVar3 >> 8) + (uint)CARRY4(uVar5,uVar1);
        uVar1 = uVar4 >> 0x10 | uVar3 * 0x10000;
        uVar5 = uVar4 + uVar1;
        uVar3 = uVar3 + (uVar3 >> 0x10) + (uint)CARRY4(uVar4,uVar1);
        param_2 = uVar3 + CARRY4(uVar5,uVar3);
        param_1 = uVar5 + uVar3 >> 3 | param_2 * 0x20000000;
        param_2 = param_2 >> 3;
        uVar6 = uVar6 + param_1 * -10;
        uVar1 = uVar6 & 0xff;
        bVar2 = (byte)uVar6;
        if (uVar1 < 10) goto LAB_0e06f486;
        bVar7 = 0xfffffffe < param_1;
        param_1 = param_1 + 1;
        param_2 = param_2 + bVar7;
        uVar6 = uVar1 - 10 & 0xff;
      }
      bVar2 = (byte)uVar6;
      if (9 < uVar6) {
        bVar2 = bVar2 + ('7' - param_4);
      }
    }
LAB_0e06f486:
    *param_3 = bVar2 + 0x30;
    param_3 = param_3 + 1;
    if (param_1 == 0 && param_2 == 0) {
      return;
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f4ac. Types and names are inferred; NOT original source. */

undefined4 FUN_0e06f4ac(void)

{
  return DAT_23006930;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f4c0. Types and names are inferred; NOT original source. */

void ram_candidate_23021db0(void)

{
  ram_candidate_23021db0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f4c8. Types and names are inferred; NOT original source. */

void thunk_FUN_23026020(void)

{
  FUN_23026020();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 0e06f4d0. Types and names are inferred; NOT original source. */

void ram_candidate_23021d9c(void)

{
  ram_candidate_23021d9c();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020000. Types and names are inferred; NOT original source. */

uint ram_candidate_23020000(int param_1,int param_2,ushort *param_3)

{
  uint uVar1;
  byte *pbVar2;
  
  if (param_3 == (ushort *)0x0) {
    uVar1 = 0xffff;
  }
  else {
    uVar1 = (uint)*param_3;
  }
  if (param_2 != 0) {
    pbVar2 = (byte *)(param_1 + -1);
    do {
      pbVar2 = pbVar2 + 1;
      uVar1 = ((uVar1 & 0xff) << 8 | uVar1 >> 8) ^ (uint)*pbVar2;
      uVar1 = (uVar1 & 0xff) >> 4 ^ uVar1;
      uVar1 = uVar1 ^ uVar1 << 0xc;
      uVar1 = (uVar1 & 0xff) << 5 ^ uVar1 & 0xffff;
    } while (pbVar2 != (byte *)(param_2 + param_1 + -1));
  }
  return uVar1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302003c. Types and names are inferred; NOT original source. */

void FUN_2302003c(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  
  uVar3 = *param_1;
  puVar2 = param_1 + param_2 + 0x3fffffff;
  uVar6 = (0x34 / param_2 + 6) * -0x61c88647;
  do {
    uVar5 = uVar3;
    if (param_2 != 1) {
      uVar5 = *puVar2;
      uVar4 = param_2 - 1;
      puVar7 = puVar2;
      do {
        uVar1 = puVar7[-1];
        uVar3 = uVar5 - ((*(uint *)(param_3 + ((uVar6 >> 2 ^ uVar4) & 3) * 4) ^ uVar1) +
                         (uVar3 ^ uVar6) ^ (uVar1 << 4 ^ uVar3 >> 3) + (uVar3 << 2 ^ uVar1 >> 5));
        uVar4 = uVar4 - 1;
        *puVar7 = uVar3;
        uVar5 = uVar1;
        puVar7 = puVar7 + -1;
      } while (uVar4 != 0);
      uVar5 = *param_1;
    }
    uVar4 = *puVar2;
    uVar3 = uVar5 - ((uVar4 << 4 ^ uVar3 >> 3) + (uVar3 << 2 ^ uVar4 >> 5) ^
                    (*(uint *)(param_3 + (uVar6 >> 2 & 3) * 4) ^ uVar4) + (uVar3 ^ uVar6));
    uVar6 = uVar6 + 0x61c88647;
    *param_1 = uVar3;
  } while (uVar6 != 0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020108. Types and names are inferred; NOT original source. */

void FUN_23020108(uint param_1)

{
  int iVar1;
  
  iVar1 = (param_1 & 0xf) * 0x10;
  DAT_23003020 = *(undefined4 *)
                  (
                  "7J2CyEPxN1miKPZCPoWOZxArbjiLfHYysi3LvIVVDCEo5eT4hIDO88XVKfNMYEk3jnMVteRXR2cnu8qX12GJdIuJlnXz2vd757dkMNqMXSxorjDLU4IWJ9PUpdEja8B58ZyjCOcUiJgUYoR57JG0wiUWnZYfErkEny3PyM23SMkSsr8bMYDRUwdb256hj4b2xsIDSYeDa0xUAKV54Cvt3x0DtzsKHAAwNqdgjmVSa8VEgtVKEumomQz51OFDRORr"
                  + iVar1);
  DAT_23003024 = *(undefined4 *)
                  (
                  "7J2CyEPxN1miKPZCPoWOZxArbjiLfHYysi3LvIVVDCEo5eT4hIDO88XVKfNMYEk3jnMVteRXR2cnu8qX12GJdIuJlnXz2vd757dkMNqMXSxorjDLU4IWJ9PUpdEja8B58ZyjCOcUiJgUYoR57JG0wiUWnZYfErkEny3PyM23SMkSsr8bMYDRUwdb256hj4b2xsIDSYeDa0xUAKV54Cvt3x0DtzsKHAAwNqdgjmVSa8VEgtVKEumomQz51OFDRORr"
                  + iVar1 + 4);
  DAT_23003028 = *(undefined4 *)
                  (
                  "7J2CyEPxN1miKPZCPoWOZxArbjiLfHYysi3LvIVVDCEo5eT4hIDO88XVKfNMYEk3jnMVteRXR2cnu8qX12GJdIuJlnXz2vd757dkMNqMXSxorjDLU4IWJ9PUpdEja8B58ZyjCOcUiJgUYoR57JG0wiUWnZYfErkEny3PyM23SMkSsr8bMYDRUwdb256hj4b2xsIDSYeDa0xUAKV54Cvt3x0DtzsKHAAwNqdgjmVSa8VEgtVKEumomQz51OFDRORr"
                  + iVar1 + 8);
  DAT_2300302c = *(undefined4 *)
                  (
                  "7J2CyEPxN1miKPZCPoWOZxArbjiLfHYysi3LvIVVDCEo5eT4hIDO88XVKfNMYEk3jnMVteRXR2cnu8qX12GJdIuJlnXz2vd757dkMNqMXSxorjDLU4IWJ9PUpdEja8B58ZyjCOcUiJgUYoR57JG0wiUWnZYfErkEny3PyM23SMkSsr8bMYDRUwdb256hj4b2xsIDSYeDa0xUAKV54Cvt3x0DtzsKHAAwNqdgjmVSa8VEgtVKEumomQz51OFDRORr"
                  + iVar1 + 0xc);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020128. Types and names are inferred; NOT original source. */

undefined4 FUN_23020128(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  undefined1 auStack_30 [32];
  
  bVar1 = *param_2;
  thunk_FUN_0e06f35c(auStack_30,param_1,bVar1);
  if (bVar1 >> 2 != 0) {
    FUN_2302003c(auStack_30,bVar1 >> 2,&DAT_23003020);
    bVar1 = *param_2;
  }
  thunk_FUN_0e06f35c(param_1,auStack_30,bVar1);
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020160. Types and names are inferred; NOT original source. */

bool FUN_23020160(undefined4 param_1,int param_2,char *param_3,uint param_4)

{
  char *pcVar1;
  char *pcVar2;
  
  if (param_2 == 1) {
    if (param_4 != 0) {
      pcVar2 = param_3;
      do {
        pcVar1 = pcVar2 + 1;
        if (*pcVar2 != '\0') {
          return true;
        }
        pcVar2 = pcVar1;
      } while (param_3 + param_4 != pcVar1);
      return false;
    }
  }
  else if (param_2 == 2) {
    if (param_4 != 0) {
      pcVar2 = param_3;
      do {
        pcVar1 = pcVar2 + 1;
        if (*pcVar2 != '\0') {
          return true;
        }
        pcVar2 = pcVar1;
      } while (pcVar1 != param_3 + param_4);
      return false;
    }
  }
  else if ((param_2 == 4) && (*param_3 == '\x01')) {
    return 1 < param_4;
  }
  return false;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230201b4. Types and names are inferred; NOT original source. */

void FUN_230201b4(uint param_1,int param_2)

{
  ushort uVar1;
  undefined2 local_20;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 local_14;
  
  local_1c = 0;
  uStack_18 = 0;
  local_14 = 0;
  uVar1 = (ushort)(1 << (param_1 & 0xff));
  local_1d = (undefined1)param_1;
  if (param_2 == 1) {
    if (param_1 == 1) {
      local_20 = 0x905;
      local_1d = 1;
    }
    else {
      local_20 = 0x3509;
    }
    DAT_23002c80 = DAT_23002c80 | uVar1;
    local_1e = 3;
    FUN_230268b0(4,&local_20,0x10);
    FUN_2302060c(param_1 & 0xff);
    return;
  }
  if (param_1 == 1) {
    local_20 = 0x905;
    local_1d = 1;
  }
  else {
    local_20 = 0x3509;
  }
  DAT_23002c80 = DAT_23002c80 & ~uVar1;
  local_1e = 2;
  FUN_230268b0(4,&local_20,0x10);
  FUN_23025b40(0xff,0);
  thunk_FUN_230207a4(0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020250. Types and names are inferred; NOT original source. */

void FUN_23020250(uint param_1,byte *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_18;
  int iStack_14;
  
  if (DAT_23002c82 == 1) {
    switch(param_1) {
    case 1:
      if (DAT_23002c88 == '\x01') {
        *param_2 = (byte)DAT_23002c8a | *param_2;
        param_2[1] = param_2[1] + DAT_23002c8a._2_1_;
        param_2[2] = param_2[2] + DAT_23002c8a._3_1_;
        *(short *)(param_2 + 4) = *(short *)(param_2 + 4) + (short)DAT_23002c8e;
        *(short *)(param_2 + 6) = *(short *)(param_2 + 6) + DAT_23002c8e._2_2_;
        param_2[3] = param_2[3] + DAT_23002c8a._1_1_;
        DAT_23002c88 = '\0';
        uRam23002c89 = 0;
        DAT_23002c8a._0_1_ = 0;
        DAT_23002c8a._1_1_ = '\0';
        DAT_23002c8a._2_1_ = '\0';
        DAT_23002c8a._3_1_ = '\0';
        DAT_23002c8e._0_2_ = 0;
        DAT_23002c8e._2_2_ = 0;
      }
      iVar1 = FUN_230268b0(1,param_2,param_3 & 0xff);
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)param_2;
        DAT_23002c8a._0_1_ = (byte)uVar2;
        DAT_23002c8a._1_1_ = (char)((uint)uVar2 >> 8);
        DAT_23002c8a._2_1_ = (char)((uint)uVar2 >> 0x10);
        DAT_23002c8a._3_1_ = (char)((uint)uVar2 >> 0x18);
        DAT_23002c88 = '\x01';
        DAT_23002c8e._0_2_ = (short)*(undefined4 *)(param_2 + 4);
        DAT_23002c8e._2_2_ = (short)((uint)*(undefined4 *)(param_2 + 4) >> 0x10);
      }
      break;
    case 2:
      FUN_230268b0(2,param_2,param_3 & 0xff);
      return;
    case 3:
      if (*param_2 == 0xb1) {
        DAT_230071b5 = param_2[6];
        DAT_230071b6 = param_2[7];
        DAT_230071b4 = param_2[5];
        FUN_23025b40(0xe1);
        FUN_23025b40(0xe2,DAT_230071b5);
        FUN_23025b40(0xe3,DAT_230071b6);
        DAT_230071b8 = 1;
        DAT_2300341c = (ushort)DAT_230071b4;
        return;
      }
      break;
    case 4:
      FUN_230268b0(4,param_2,param_3 & 0xff);
      if (param_2[1] == 0x31) {
        DAT_230071b6 = param_2[2];
        FUN_23025b40(0xe3);
        return;
      }
      break;
    case 5:
      if (*param_2 == 0x5a) {
        thunk_FUN_0e06f35c(&DAT_23002d1c,param_2 + 2,param_3 - 2);
        DAT_23002d74 = param_2[1];
      }
    }
  }
  else {
    iVar1 = FUN_23020160(0,param_1 & 0xff,param_2);
    if ((iVar1 != 0) && (local_18 = FUN_23026ad8(), local_18 == 0)) {
      FUN_23026928(1);
      iStack_14 = local_18;
      FUN_230268b0(1,&local_18,8);
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230203cc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_230203cc(int param_1)

{
  if (param_1 == 0) {
    _DAT_23002c84 = (uint)DAT_23002c84;
    return;
  }
  if (param_1 != 1) {
    _DAT_23002c84 = 0;
    DAT_230071bd = 0;
    FUN_2302060c(1);
    return;
  }
  DAT_230071bd = 1;
  _DAT_23002c84 = param_1;
  FUN_2302060c();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230203fc. Types and names are inferred; NOT original source. */

void FUN_230203fc(int param_1,undefined1 *param_2,char param_3)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = 0;
  uStack_14 = 0;
  local_10 = 0;
  uStack_c = 0;
  if (param_1 == 2) {
    if ((DAT_23002c80 != 0) && (DAT_23002c82 == 1)) {
      DAT_230071b3 = *param_2;
      FUN_23025b40(0xe0);
      local_18 = CONCAT22(CONCAT11(local_18._3_1_,DAT_230071b3),0x5605);
      FUN_230268b0(4,&local_18,0x10);
    }
  }
  else {
    if (param_1 == 99) {
      FUN_230268b0(4,param_2,param_3);
      return;
    }
    if (param_1 == 1) {
      local_18 = 0x72fe05;
      thunk_FUN_0e06f35c((int)&local_18 + 3);
      FUN_230268b0(4,&local_18,param_3 + '\x03');
      return;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302048c. Types and names are inferred; NOT original source. */

void FUN_2302048c(void)

{
  DAT_23006595 = 1;
  thunk_FUN_0e05c504();
  FUN_0e06d43c(&DAT_23002c94);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230204ac. Types and names are inferred; NOT original source. */

undefined1 FUN_230204ac(void)

{
  return (undefined1)DAT_23002c80;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230204b8. Types and names are inferred; NOT original source. */

void FUN_230204b8(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230204bc. Types and names are inferred; NOT original source. */

void thunk_FUN_23024db4(uint param_1)

{
  ushort uVar1;
  undefined1 uStack_30;
  ushort uStack_2f;
  
  if ((DAT_2300659a & 0xffff) != param_1) {
    uVar1 = (ushort)((param_1 & 0xff) << 8) | (ushort)(param_1 >> 8) & 0xff;
    DAT_2300659a = param_1 & 0xffff | param_1 << 0x10;
    uStack_30 = 0xac;
    DAT_2300659e = 0;
    DAT_230065b0 = 0;
    uStack_2f = uVar1;
    FUN_230251e4(0,3,&uStack_30);
    if ((DAT_2300659a & 0xffff) == 0) {
      if (DAT_23006598 != '\0') {
        DAT_23006598 = (char)DAT_2300659a;
        thunk_FUN_0e06ec54(&DAT_23001ad8);
        return;
      }
    }
    else if (DAT_23006598 == '\0') {
      DAT_23006598 = '\x01';
      thunk_FUN_0e06ebe0(&DAT_23001ad8,1,100000,0,1000,0,uVar1);
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230204c0. Types and names are inferred; NOT original source. */

undefined4 FUN_230204c0(void)

{
  thunk_FUN_0e06d8f8(&DAT_23001ea0,&DAT_2300f200,0x800,0x23020545,0,0,0,0xe,0);
  thunk_FUN_0e06d3f0(&DAT_23002c94,0x230205f9);
  FUN_2302532c();
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020510. Types and names are inferred; NOT original source. */

void FUN_23020510(void)

{
  DAT_23006595 = 1;
  thunk_FUN_0e05c5ec();
  FUN_0e06d43c(&DAT_23002c94);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020530. Types and names are inferred; NOT original source. */

void FUN_23020530(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  thunk_FUN_0e05c6d4();
  FUN_0e06d43c(&DAT_23002c94,extraout_r1,extraout_r2,in_r3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020544. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23020544(void)

{
  ushort uVar1;
  
  thunk_FUN_0e05c200();
LAB_23020568:
  do {
    thunk_FUN_0e06e334(100000,0);
    FUN_23026ea4();
    FUN_23025994();
    if ((DAT_230071b8 == '\0') || (DAT_230071b7 == '\0')) goto LAB_23020560;
    FUN_23025a44();
    DAT_230071b7 = '\0';
    FUN_23025cb0();
  } while (DAT_23002c84 == 0);
  goto LAB_23020598;
LAB_23020560:
  FUN_23025cb0();
  if (DAT_23002c84 != 0) {
LAB_23020598:
    uVar1 = DAT_23002c86 + 1;
    _DAT_23002c84 = CONCAT22(uVar1,DAT_23002c84);
    if (4 < uVar1) {
      _DAT_23002c84 = 0;
      DAT_230071bd = 0;
      FUN_2302060c(1);
    }
  }
  goto LAB_23020568;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230205c8. Types and names are inferred; NOT original source. */

void FUN_230205c8(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == 1) {
    FUN_230251e4(0,5,param_2,param_3);
    return;
  }
  if (param_1 != 2) {
    return;
  }
  FUN_230251e4(1,5,param_2,param_3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230205ec. Types and names are inferred; NOT original source. */

void FUN_230205ec(void)

{
  FUN_0e06d43c(&DAT_23002c94);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230205f8. Types and names are inferred; NOT original source. */

void ram_candidate_230205f8(void)

{
  FUN_23026090();
  (*(code *)0xe05c775)();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020608. Types and names are inferred; NOT original source. */

void FUN_23020608(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302060c. Types and names are inferred; NOT original source. */

void FUN_2302060c(int param_1)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined4 local_12;
  undefined4 local_e;
  undefined2 local_a;
  
  local_a = 0;
  local_17 = DAT_230071bd;
  local_12 = 0;
  local_e = 0;
  local_16 = DAT_230071bc;
  local_18 = 0xb1;
  local_15 = 1;
  local_14 = DAT_230071e5;
  local_13 = (undefined1)DAT_23002c82;
  FUN_230251e4(param_1 != 1,3,&local_18,6);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020674. Types and names are inferred; NOT original source. */

void thunk_FUN_230252a4(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uStack_2c = 8;
  uStack_28 = param_1;
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001bb4,&uStack_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001bb4);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020678. Types and names are inferred; NOT original source. */

void thunk_FUN_23020fec(char *param_1)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  char cVar4;
  uint uVar5;
  byte *pbVar6;
  
  DAT_230031fa = *param_1 != '\0';
  DAT_230031fb = param_1[1];
  if (0x27 < DAT_230031fb - 1) {
    DAT_230031fa = 0;
    return;
  }
  pbVar3 = (byte *)(param_1 + 1);
  pcVar2 = (char *)&DAT_230031fb;
  pbVar6 = pbVar3 + DAT_230031fb;
  do {
    while( true ) {
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
      if (bVar1 - 2 < 0x7f) break;
      pcVar2 = pcVar2 + 1;
      *pcVar2 = '\0';
      if (pbVar3 == pbVar6) {
        return;
      }
    }
    uVar5 = (short)(ushort)(bVar1 >> 4) * 10 + (bVar1 & 0xf);
    if (uVar5 == 2) {
      cVar4 = '%';
    }
    else if (uVar5 < 0x1a) {
      cVar4 = (char)((uVar5 - 4) * 0x800000 >> 0x18);
    }
    else if (uVar5 == 0x1a) {
      cVar4 = '&';
    }
    else if (uVar5 < 0x50) {
      cVar4 = (char)((int)(uVar5 - 0x1c) >> 1) + '\v';
    }
    else {
      cVar4 = '\'';
    }
    pcVar2 = pcVar2 + 1;
    *pcVar2 = cVar4;
  } while (pbVar3 != pbVar6);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302067c. Types and names are inferred; NOT original source. */

void thunk_FUN_23025300(undefined4 param_1)

{
  int iVar1;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uStack_2c = 9;
  uStack_28 = param_1;
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001bb4,&uStack_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001bb4);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020680. Types and names are inferred; NOT original source. */

void FUN_23020680(void)

{
  undefined4 in_r3;
  
  FUN_23024fd8(DAT_23002dcf << 0x18 | (DAT_23002dcf >> 8 & 0xff) << 0x10 |
               (DAT_23002dcf >> 0x10 & 0xff) << 8 | DAT_23002dcf >> 0x18);
  thunk_FUN_0e06f3aa(&DAT_230065b8,0,0x28,in_r3,in_r3);
  DAT_230065b4 = 0x20002;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230206c4. Types and names are inferred; NOT original source. */

void FUN_230206c4(void)

{
  DAT_23002c82 = 0;
  FUN_2302539c(0x28);
  thunk_FUN_0e06ddc4(&DAT_23001ea0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230206e4. Types and names are inferred; NOT original source. */

void FUN_230206e4(void)

{
  DAT_23002c82 = 1;
  FUN_2302539c(0x2c);
  thunk_FUN_0e06ddc4(&DAT_23001ea0);
  DAT_230071b7 = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302070c. Types and names are inferred; NOT original source. */

void FUN_2302070c(void)

{
  DAT_23002c82 = 0;
  FUN_2302539c(0x2b);
  thunk_FUN_0e06dd90(&DAT_23001ea0);
  DAT_230071b9 = 0;
  FUN_23025954(0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302073c. Types and names are inferred; NOT original source. */

void FUN_2302073c(int param_1,int param_2)

{
  char cVar1;
  
  param_2 = param_2 + param_1 * 0xf84;
  disableIRQinterrupts();
  cVar1 = *(char *)((int)&DAT_230033e8 + param_2 + 0x15a) + '\x01';
  if (*(char *)((int)&DAT_230033e8 + param_2 + 0x160) == cVar1) {
    cVar1 = '\0';
  }
  *(char *)((int)&DAT_230033e8 + param_2 + 0x15a) = cVar1;
  enableIRQinterrupts();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020768. Types and names are inferred; NOT original source. */

short FUN_23020768(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  
  param_2 = param_2 + param_1 * 0xf84;
  uVar2 = (ushort)*(byte *)((int)&DAT_230033e8 + param_2 + 0x15a);
  uVar1 = (ushort)*(byte *)((int)&DAT_230033e8 + param_2 + 0x154);
  if (uVar2 != uVar1) {
    if (uVar2 < uVar1) {
      uVar2 = uVar2 + *(byte *)((int)&DAT_230033e8 + param_2 + 0x160);
    }
    return (uVar2 - 1) - uVar1;
  }
  return *(byte *)((int)&DAT_230033e8 + param_2 + 0x160) - 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230207a4. Types and names are inferred; NOT original source. */

void FUN_230207a4(int param_1)

{
  param_1 = param_1 * 0xf84;
  *(undefined4 *)(&DAT_23003542 + param_1) = 0;
  *(undefined2 *)(&DAT_23003546 + param_1) = 0;
  *(undefined4 *)(&DAT_2300353c + param_1) = 0;
  *(undefined2 *)(&DAT_23003540 + param_1) = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230207ec. Types and names are inferred; NOT original source. */

int FUN_230207ec(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = (param_2 & 0xff) + param_1 * 0xf84;
  if (*(char *)((int)&DAT_230033e8 + iVar1 + 0x15a) != *(char *)((int)&DAT_230033e8 + iVar1 + 0x154)
     ) {
    iVar1 = param_2 + param_1 * 0xf84;
    iVar1 = (uint)*(byte *)((int)&DAT_230033e8 + iVar1 + 0x15a) *
            (uint)*(byte *)((int)&DAT_230033e8 + iVar1 + 0x166) +
            *(int *)(&DAT_23003554 + (param_2 + param_1 * 0x3e1) * 4);
    *(undefined1 *)(iVar1 + 2) = 1;
    return iVar1 + 4;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302083c. Types and names are inferred; NOT original source. */

void FUN_2302083c(int param_1)

{
  param_1 = param_1 * 0xf84;
  *(undefined4 *)(&DAT_23003542 + param_1) = 0;
  *(undefined2 *)(&DAT_23003546 + param_1) = 0;
  *(undefined4 *)(&DAT_2300353c + param_1) = 0;
  *(undefined2 *)(&DAT_23003540 + param_1) = 0;
  *(undefined4 *)(&DAT_23003548 + param_1) = 0x20101020;
  *(undefined4 *)(&DAT_2300354c + param_1) = 0x10106020;
  *(undefined4 *)(&DAT_23003550 + param_1) = 0x10101010;
  *(int *)(&DAT_23003554 + param_1) = param_1 + 0x2300356c;
  *(int *)(&DAT_23003558 + param_1) = param_1 + 0x2300376c;
  *(int *)(&DAT_2300355c + param_1) = param_1 + 0x2300386c;
  *(int *)(&DAT_23003560 + param_1) = param_1 + 0x2300396c;
  *(int *)(&DAT_23003564 + param_1) = param_1 + 0x23003b6c;
  *(int *)(&DAT_23003568 + param_1) = param_1 + 0x23003d6c;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230208b8. Types and names are inferred; NOT original source. */

undefined4 FUN_230208b8(int param_1,uint param_2,undefined4 param_3,char param_4,undefined1 param_5)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  byte bVar5;
  
  iVar1 = (param_2 & 0xff) + param_1 * 0xf84;
  bVar5 = *(char *)((int)&DAT_230033e8 + iVar1 + 0x154) + 1;
  if (*(byte *)((int)&DAT_230033e8 + iVar1 + 0x160) <= bVar5) {
    bVar5 = 0;
  }
  if (*(byte *)((int)&DAT_230033e8 + iVar1 + 0x15a) == bVar5) {
    return 0;
  }
  iVar1 = param_2 + param_1 * 0xf84;
  iVar4 = (int)(short)(ushort)*(byte *)((int)&DAT_230033e8 + iVar1 + 0x154) *
          (int)(short)(ushort)*(byte *)((int)&DAT_230033e8 + iVar1 + 0x166);
  iVar2 = *(int *)(&DAT_23003554 + (param_1 * 0x3e1 + param_2) * 4);
  *(char *)(iVar4 + iVar2) = param_4;
  iVar2 = iVar2 + iVar4;
  *(undefined1 *)(iVar2 + 1) = param_5;
  *(undefined1 *)(iVar2 + 2) = 0;
  *(char *)(iVar2 + 4) = param_4 + '\x02';
  *(byte *)(iVar2 + 6) =
       *(byte *)((int)&DAT_230033e8 + iVar1 + 0xa7) | (byte)((param_2 & 0xff) << 3);
  thunk_FUN_0e06f35c(iVar2 + 7,param_3);
  disableIRQinterrupts();
  cVar3 = *(char *)((int)&DAT_230033e8 + iVar1 + 0x154) + '\x01';
  if (*(char *)((int)&DAT_230033e8 + iVar1 + 0x160) == cVar3) {
    cVar3 = '\0';
  }
  *(char *)((int)&DAT_230033e8 + iVar1 + 0x154) = cVar3;
  enableIRQinterrupts();
  cVar3 = *(char *)((int)&DAT_230033e8 + iVar1 + 0xa7) + '\x01';
  if (cVar3 == '\b') {
    cVar3 = '\x01';
  }
  *(char *)((int)&DAT_230033e8 + iVar1 + 0xa7) = cVar3;
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020978. Types and names are inferred; NOT original source. */

uint FUN_23020978(uint param_1,uint param_2)

{
  return (param_2 & 1) << 6 | (param_1 & 1) << 7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020988. Types and names are inferred; NOT original source. */

uint FUN_23020988(uint param_1)

{
  return param_1 >> 7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302098c. Types and names are inferred; NOT original source. */

byte FUN_2302098c(char param_1,char param_2,char param_3,char param_4,byte param_5)

{
  return param_5 | param_4 << 4 | param_3 << 5 | param_2 << 6 | param_1 << 7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209a8. Types and names are inferred; NOT original source. */

uint FUN_230209a8(uint param_1)

{
  return param_1 >> 7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209ac. Types and names are inferred; NOT original source. */

uint FUN_230209ac(uint param_1)

{
  return param_1 & 0xf;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209b4. Types and names are inferred; NOT original source. */

uint FUN_230209b4(uint param_1)

{
  return (param_1 & 0x7f) >> 4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209bc. Types and names are inferred; NOT original source. */

byte FUN_230209bc(char param_1,char param_2,byte param_3)

{
  return param_3 | param_2 << 6 | param_1 << 7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209c8. Types and names are inferred; NOT original source. */

uint FUN_230209c8(undefined4 param_1,uint param_2)

{
  return param_2 & 0xf;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209d0. Types and names are inferred; NOT original source. */

byte FUN_230209d0(char param_1,char param_2,byte param_3)

{
  return param_3 | param_2 << 6 | param_1 << 7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209dc. Types and names are inferred; NOT original source. */

byte FUN_230209dc(char param_1,byte param_2)

{
  return param_2 | param_1 << 3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209e4. Types and names are inferred; NOT original source. */

uint FUN_230209e4(uint param_1)

{
  return param_1 & 7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209ec. Types and names are inferred; NOT original source. */

uint FUN_230209ec(uint param_1)

{
  return param_1 >> 7;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209f0. Types and names are inferred; NOT original source. */

uint FUN_230209f0(uint param_1)

{
  return (param_1 & 0x7f) >> 6;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230209f8. Types and names are inferred; NOT original source. */

uint FUN_230209f8(uint param_1)

{
  return (param_1 & 0x3f) >> 3;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020a00. Types and names are inferred; NOT original source. */

void ram_candidate_23020a00(void)

{
  short sVar1;
  dword dVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  ushort uVar6;
  undefined2 uVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint local_28;
  
  uVar6 = DAT_230032d0;
  uVar5 = DAT_2300305c;
  uVar4 = DAT_23003058;
  uVar3 = DAT_23003054;
  uVar8 = DAT_23003050;
  if (DAT_23003230 == 5) {
    (*(code *)0xe05d099)();
    return;
  }
  uVar10 = (uint)DAT_23003234;
  if (uVar10 == 4) {
    dVar2 = RADIO_S_EVENTS_TXREADY;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_TXREADY = 0;
    }
    dVar2 = RADIO_S_EVENTS_RXREADY;
    if ((dVar2 == 1) && (RADIO_S_EVENTS_RXREADY = 0, 1 < DAT_23003230)) {
      FUN_23024190(0xe);
    }
    dVar2 = RADIO_S_EVENTS_ADDRESS;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_ADDRESS = 0;
    }
    dVar2 = RADIO_S_EVENTS_END;
    if ((dVar2 == 0) || (RADIO_S_EVENTS_END = 0, DAT_23003230 < 2)) {
      dVar2 = RADIO_S_EVENTS_DISABLED;
    }
    else {
      FUN_23024190(4);
      dVar2 = RADIO_S_EVENTS_DISABLED;
    }
    if (dVar2 == 1) {
      RADIO_S_EVENTS_DISABLED = 0;
      if (1 < DAT_23003230) {
        FUN_23024190(5);
        FUN_23020c30();
        return;
      }
      FUN_23020c30();
      return;
    }
    return;
  }
  if (uVar10 == 1) {
    dVar2 = RADIO_S_EVENTS_TXREADY;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_TXREADY = 0;
    }
    dVar2 = RADIO_S_EVENTS_RXREADY;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_RXREADY = 0;
    }
    dVar2 = RADIO_S_EVENTS_ADDRESS;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_ADDRESS = 0;
    }
    dVar2 = RADIO_S_EVENTS_END;
    local_28 = uVar10;
    if ((dVar2 == 1) && (RADIO_S_EVENTS_END = 0, 1 < DAT_23003230)) {
      uVar10 = DAT_23006274 & 0xffff;
      iVar12 = uVar10 * 0xf84;
      if ((&DAT_23003468)[uVar10 * 0x3e1] == 0xc) {
        dVar2 = RADIO_S_EVENTS_CRCOK;
        if ((dVar2 == 1) && ((char)DAT_23003050 != '\0')) {
          RADIO_S_EVENTS_CRCOK = 0;
          DAT_23003050 = (uint)DAT_23003050._1_3_ << 8;
          uVar13 = DAT_23006274 & 0xffff;
          *(uint *)(&DAT_230034fc + iVar12) = uVar8;
          *(undefined4 *)(&DAT_23003500 + iVar12) = uVar3;
          *(undefined4 *)(&DAT_23003504 + iVar12) = uVar4;
          *(undefined4 *)(&DAT_23003508 + iVar12) = uVar5;
          (&DAT_23003487)[iVar12] = 1;
          uVar6 = FUN_230209a8((&DAT_230034fd)[iVar12]);
          *(ushort *)(&DAT_23003484 + iVar12) = uVar6 & 0xff | uVar6 << 8;
          uVar8 = FUN_230209b4((&DAT_230034fd)[iVar12]);
          if ((byte)(&DAT_23003483)[iVar12] != uVar8) {
            uVar11 = (uint)DAT_230032ca;
            sVar1 = *(short *)(&DAT_2300347e + uVar10 * 0x3e1);
            (&DAT_23003470)[uVar10 * 0x7c2] = 0;
            *(undefined2 *)((int)&DAT_230033e8 + (uVar10 * 0x7c2 + uVar11 + 0x48) * 2) = 0;
            if (sVar1 != 0) {
              cVar9 = (&DAT_23003482)[iVar12] + '\x01';
              if (cVar9 == '\b') {
                cVar9 = '\x01';
              }
              (&DAT_23003482)[iVar12] = cVar9;
              FUN_2302073c(uVar13);
              *(undefined2 *)((int)&DAT_2300347e + iVar12 + 2) =
                   *(undefined2 *)(&DAT_2300347e + uVar10 * 0x3e1);
            }
          }
          (&DAT_23003483)[uVar10 * 0xf84] = (char)uVar8;
          *(undefined2 *)(&DAT_2300347e + uVar10 * 0x3e1) = 0;
          FUN_23021c24(uVar13);
          uVar7 = FUN_230209c8(0,(&DAT_230034fd)[uVar10 * 0xf84]);
          uVar8 = (uint)DAT_230032ca;
          *(undefined2 *)((int)&DAT_230033e8 + (uVar10 * 0x7c2 + uVar8 + 0x48) * 2) = uVar7;
          *(undefined2 *)((int)&DAT_230033e8 + (uVar8 + 0xfcc) * 2) = uVar7;
        }
        else {
          DAT_23003050 = (uint)DAT_23003050._1_3_ << 8;
          if (DAT_2300341c == 1) {
            (&DAT_2300348a)[uVar10 * 0xf84] = 1;
          }
          else if (DAT_230032d0 < 2) {
            (&DAT_2300348a)[uVar10 * 0xf84] = 1;
          }
          else {
            FUN_23023708(1);
          }
        }
        (&DAT_23003468)[uVar10 * 0x3e1] = 0xb;
      }
      else if ((&DAT_23003468)[uVar10 * 0x3e1] == 0xd) {
        FUN_23020f1c(&DAT_23003468 + uVar10 * 0x3e1,&RADIO_S_TASKS_DISABLE);
      }
    }
    dVar2 = RADIO_S_EVENTS_DISABLED;
    if (dVar2 == 1) {
      RADIO_S_EVENTS_DISABLED = 0;
      if ((1 < DAT_23003230) &&
         (uVar8 = DAT_23006274 & 0xffff, (&DAT_23003468)[uVar8 * 0x3e1] == 0xd)) {
        uVar10 = (uint)DAT_230032ca;
        if (2 < *(ushort *)((int)&DAT_230033e8 + (uVar8 * 0x7c2 + uVar10 + 0x48) * 2)) {
          if (DAT_23005384 == '\0') {
            cVar9 = (&DAT_23005349)[uVar10] + '\x01';
            if (DAT_23005353 == cVar9) {
              cVar9 = '\0';
            }
            (&DAT_23005349)[uVar10] = cVar9;
            uVar10 = (uint)DAT_230032ca;
          }
          *(undefined2 *)((int)&DAT_230033e8 + (uVar8 * 0x7c2 + uVar10 + 0x48) * 2) = 0;
        }
        (&DAT_23003468)[uVar8 * 0x3e1] = 0xd;
      }
      FUN_23020c30();
      return;
    }
    return;
  }
  if (uVar10 != 2) {
    return;
  }
  dVar2 = RADIO_S_EVENTS_TXREADY;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_TXREADY = 0;
  }
  dVar2 = RADIO_S_EVENTS_RXREADY;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_RXREADY = 0;
  }
  dVar2 = RADIO_S_EVENTS_END;
  if (dVar2 != 0) {
    RADIO_S_EVENTS_END = 0;
  }
  dVar2 = RADIO_S_EVENTS_DISABLED;
  if (dVar2 == 1) {
    RADIO_S_EVENTS_DISABLED = 0;
    if (1 < DAT_23003230) {
      uVar10 = (uint)DAT_230032d0;
      switch((&DAT_23003468)[uVar10 * 0x3e1]) {
      case 8:
        (&DAT_23003468)[uVar10 * 0x3e1] = 7;
        break;
      case 9:
        dVar2 = RADIO_S_EVENTS_CRCOK;
        if (dVar2 == 1) {
          uVar8 = FUN_230223f0(uVar10,&DAT_230034bc + uVar10 * 0xf84);
          if (uVar8 < 2) {
            (&DAT_23003468)[uVar10 * 0x3e1] = 7;
          }
          else if (uVar8 == 2) {
            FUN_23020f1c(&DAT_23003468 + uVar10 * 0x3e1,&RADIO_S_TASKS_DISABLE,10);
          }
        }
        else {
          (&DAT_23003468)[uVar10 * 0x3e1] = 7;
        }
        break;
      case 10:
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_RXEN = 0;
        RADIO_S_SUBSCRIBE_DISABLE = 0;
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_RXEN = 0;
        RADIO_S_SUBSCRIBE_DISABLE = 0;
        RADIO_S_SUBSCRIBE_TXEN = 0;
        FUN_23020f1c(&DAT_23003468 + uVar10 * 0x3e1,&RADIO_S_TASKS_DISABLE);
        FUN_23021dbc((char)uVar6);
        local_28 = CONCAT22(local_28._2_2_,uVar6);
        FUN_2302546c(&local_28);
        break;
      case 0xb:
        (&DAT_23003468)[uVar10 * 0x3e1] = 0xb;
        break;
      case 0xc:
        dVar2 = RADIO_S_EVENTS_CRCOK;
        if (dVar2 == 1) {
          iVar12 = uVar10 * 0xf84;
          DAT_23003050 = DAT_23003050 & 0xffffff00;
          *(uint *)(&DAT_230034fc + iVar12) = uVar8;
          *(undefined4 *)(&DAT_23003500 + iVar12) = uVar3;
          *(undefined4 *)(&DAT_23003504 + iVar12) = uVar4;
          *(undefined4 *)(&DAT_23003508 + iVar12) = uVar5;
          (&DAT_23003487)[iVar12] = 1;
          uVar6 = FUN_230209a8((&DAT_230034fd)[iVar12]);
          *(ushort *)(&DAT_23003484 + iVar12) = uVar6 & 0xff | uVar6 << 8;
          uVar8 = FUN_230209b4((&DAT_230034fd)[iVar12]);
          if ((byte)(&DAT_23003483)[iVar12] != uVar8) {
            uVar13 = (uint)DAT_230032ca;
            sVar1 = *(short *)(&DAT_2300347e + uVar10 * 0x3e1);
            (&DAT_23003470)[uVar10 * 0x7c2] = 0;
            *(undefined2 *)((int)&DAT_230033e8 + (uVar10 * 0x7c2 + uVar13 + 0x48) * 2) = 0;
            if (sVar1 != 0) {
              cVar9 = (&DAT_23003482)[iVar12] + '\x01';
              if (cVar9 == '\b') {
                cVar9 = '\x01';
              }
              (&DAT_23003482)[iVar12] = cVar9;
              FUN_2302073c(uVar10);
              *(undefined2 *)((int)&DAT_2300347e + iVar12 + 2) =
                   *(undefined2 *)(&DAT_2300347e + uVar10 * 0x3e1);
            }
          }
          (&DAT_23003483)[uVar10 * 0xf84] = (char)uVar8;
          *(undefined2 *)(&DAT_2300347e + uVar10 * 0x3e1) = 0;
          FUN_23021c24(uVar10);
        }
        (&DAT_23003468)[uVar10 * 0x3e1] = 0xb;
        break;
      case 0xd:
        (&DAT_23003468)[uVar10 * 0x3e1] = 0xd;
      }
    }
    FUN_23020c30();
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020a2c. Types and names are inferred; NOT original source. */

void FUN_23020a2c(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020a30. Types and names are inferred; NOT original source. */

void FUN_23020a30(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020a34. Types and names are inferred; NOT original source. */

void FUN_23020a34(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  dword dVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  
  thunk_FUN_0e06f3aa(param_1,0,0x20,param_4,param_4);
  *param_1 = DAT_23003244;
  uVar2 = DAT_23003230;
  param_1[1] = DAT_2300324c;
  dVar1 = RADIO_S_BASE1;
  param_1[2] = dVar1;
  uVar3 = DAT_230033e8;
  dVar1 = RADIO_S_PREFIX0;
  param_1[3] = dVar1;
  *(char *)((int)param_1 + 0x13) = (char)uVar2;
  *(char *)(param_1 + 6) = (char)uVar3;
  *(char *)((int)param_1 + 0x19) = (char)DAT_23003468;
  *(char *)((int)param_1 + 0x1a) = (char)DAT_230034b0;
  *(char *)((int)param_1 + 0x1b) = (char)DAT_230034b2;
  *(char *)(param_1 + 7) = (char)DAT_230034b4;
  *(char *)((int)param_1 + 0x1d) = (char)DAT_230034b6;
  *(char *)((int)param_1 + 0x1e) = (char)DAT_230034b8;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020a94. Types and names are inferred; NOT original source. */

undefined4 FUN_23020a94(void)

{
  DPPIC020_S_CHENCLR =
       1 << DAT_230071c6 | 1 << DAT_230071c5 | 1 << DAT_230071c4 | 1 << DAT_230071c3 |
       1 << DAT_230071c2 | 1 << DAT_230071c1 | 1 << DAT_230071c0 | 1 << DAT_230071bf;
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020b1c. Types and names are inferred; NOT original source. */

undefined4 FUN_23020b1c(void)

{
  dword dVar1;
  
  dVar1 = DPPIC020_S_CHEN;
  if (dVar1 == 0) {
    DAT_230071c6 = 0;
    DAT_230071c5 = 1;
    DAT_230071c4 = 2;
    DAT_230071c3 = 3;
    DAT_230071c2 = 4;
    DAT_230071c1 = 5;
    DAT_230071c0 = 6;
    DAT_230071bf = 7;
    TIMER020_S_PUBLISH_COMPARE_0 = 0x80000000;
    TIMER020_S_PUBLISH_COMPARE_1 = 0x80000001;
    TIMER020_S_PUBLISH_COMPARE_2 = 0x80000002;
    TIMER020_S_PUBLISH_COMPARE_3 = 0x80000003;
    TIMER020_S_PUBLISH_COMPARE_4 = 0x80000004;
    TIMER020_S_PUBLISH_COMPARE_5 = 0x80000005;
    RADIO_S_PUBLISH_ADDRESS = 0x80000006;
    DPPIC020_S_CHENSET = 0xff;
    return 0;
  }
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020bd4. Types and names are inferred; NOT original source. */

void FUN_23020bd4(undefined4 param_1)

{
  dword dVar1;
  
  switch(param_1) {
  case 0:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xfffffff5;
    return;
  case 1:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xfffffff3;
    return;
  case 2:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xfffffff9;
    return;
  default:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xfffffffe;
    return;
  case 7:
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 & 0xffffff7f;
    return;
  }
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020c30. Types and names are inferred; NOT original source. */

void FUN_23020c30(void)

{
  RADIO_S_EVENTS_CRCOK = 0;
  RADIO_S_EVENTS_CRCERROR = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020c44. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23020c44(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  dword dVar1;
  undefined4 extraout_r1;
  
  thunk_FUN_0e0612c8(0x2c);
  RADIO_S_TASKS_DISABLE = 1;
  RADIO_S_TIMING = 1;
  RADIO_S_TXADDRESS = 3;
  RADIO_S_RXADDRESSES = 6;
  RADIO_S_PREFIX0 = 0xc3c2c1e7;
  RADIO_S_PREFIX1 = 0xc7c6c5c4;
  RADIO_S_BASE0 = 0xeb8a542c;
  RADIO_S_BASE1 = *(dword *)(param_1 + 4);
  RADIO_S_MODE = (uint)*(byte *)(param_1 + 0x20);
  RADIO_S_TXPOWER = 0x1a;
  _DAT_2300303b = 0x101;
  DAT_2300303a = 3;
  _DAT_23003030 = 5;
  _DAT_23003038 = 0x1f;
  _DAT_23003034 = 0x100;
  DAT_23003045 = 1;
  DAT_2300304c = 1;
  RADIO_S_PCNF0 = 0x1000005;
  RADIO_S_PCNF1 = 0x303001f;
  _DAT_23003040 = 5;
  DAT_23003042 = 0;
  RADIO_S_CRCCNF = 0x102;
  RADIO_S_CRCPOLY = 0x11021;
  RADIO_S_CRCINIT = 0xffff;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x80001;
  _DAT_23003048 = 0x102001f;
  RADIO_S_INTENSET00 = 0x100;
  RADIO_S_EVENTS_ADDRESS = 0;
  RADIO_S_EVENTS_READY = 0;
  RADIO_S_EVENTS_END = 0;
  RADIO_S_EVENTS_DISABLED = 0;
  thunk_FUN_0e0612f0(0x2c,1,0);
  DAT_e000e42c = 0;
  _DAT_e000e284 = 0x1000;
  thunk_FUN_0e0612ac(0x2c,extraout_r1,0x1000,param_4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020d5c. Types and names are inferred; NOT original source. */

void FUN_23020d5c(void)

{
  RADIO_S_PREFIX0 = 0xc3c2c1e7;
  RADIO_S_PCNF0 =
       (uint)DAT_23003032 << 0x10 | (uint)DAT_23003031 << 8 | (uint)DAT_23003030 |
       (uint)DAT_23003033 << 0x14 | (uint)DAT_23003034 << 0x16 | (uint)DAT_23003035 << 0x18 |
       (uint)DAT_23003036 << 0x1a | (uint)DAT_23003037 << 0x1d;
  RADIO_S_PCNF1 =
       (uint)DAT_2300303a << 0x10 | (uint)DAT_23003039 << 8 | (uint)DAT_23003038 |
       (uint)DAT_2300303b << 0x18 | (uint)DAT_2300303c << 0x19;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020dd4. Types and names are inferred; NOT original source. */

void FUN_23020dd4(void)

{
  RADIO_S_PREFIX0 = DAT_2300324c;
  RADIO_S_PCNF0 =
       (uint)DAT_23003042 << 0x10 | (uint)DAT_23003041 << 8 | (uint)DAT_23003040 |
       (uint)DAT_23003043 << 0x14 | (uint)DAT_23003044 << 0x16 | (uint)DAT_23003045 << 0x18 |
       (uint)DAT_23003046 << 0x1a | (uint)DAT_23003047 << 0x1d;
  RADIO_S_PCNF1 =
       (uint)DAT_2300304a << 0x10 | (uint)DAT_23003049 << 8 | (uint)DAT_23003048 |
       (uint)DAT_2300304b << 0x18 | (uint)DAT_2300304c << 0x19;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020e50. Types and names are inferred; NOT original source. */

void FUN_23020e50(void)

{
  dword dVar1;
  
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_INTENSET00 = 0x100;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = 0;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x80001;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020e84. Types and names are inferred; NOT original source. */

void FUN_23020e84(int param_1)

{
  int iVar1;
  
  if (param_1 == 2) {
    RADIO_S_MODE = 4;
  }
  else if (param_1 == 4) {
    RADIO_S_MODE = 9;
  }
  iVar1 = DAT_5302c8a0;
  if ((iVar1 == -0x80000000) || (iVar1 = DAT_5302c8a0, iVar1 == 0x58120e)) {
    DAT_5302c8a0 = 0x58090e;
  }
  DAT_5302c8a4 = 0xf8aa5f;
  DAT_5302c8a8 = 0xc00030;
  DAT_5302c8ac = 0xa80030;
  DAT_5302c7ac = 0x8672827a;
  DAT_5302c7b0 = 0x7e768672;
  DAT_5302c7b4 = 0x406007e;
  DAT_5302c7e4 = 0x412c384;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020f1c. Types and names are inferred; NOT original source. */

void FUN_23020f1c(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  *param_1 = param_3;
  RADIO_S_EVENTS_READY = 0;
  RADIO_S_EVENTS_END = 0;
  RADIO_S_EVENTS_DISABLED = 0;
  *param_2 = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020f3c. Types and names are inferred; NOT original source. */

void FUN_23020f3c(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    RADIO_S_RXADDRESSES = 10;
    return;
  case 1:
    RADIO_S_RXADDRESSES = 0xc;
    return;
  case 2:
    RADIO_S_RXADDRESSES = 6;
    return;
  default:
    RADIO_S_RXADDRESSES = 1;
    return;
  case 7:
    RADIO_S_RXADDRESSES = 0x80;
    return;
  }
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020f84. Types and names are inferred; NOT original source. */

void FUN_23020f84(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    RADIO_S_TXADDRESS = 1;
    return;
  case 1:
    RADIO_S_TXADDRESS = 2;
    return;
  case 2:
    RADIO_S_TXADDRESS = 3;
    return;
  default:
    RADIO_S_TXADDRESS = 0;
    return;
  case 7:
    RADIO_S_TXADDRESS = 7;
    return;
  }
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020fcc. Types and names are inferred; NOT original source. */

void FUN_23020fcc(undefined4 param_1,uint param_2)

{
  RADIO_S_BASE1 = param_2;
  DAT_23003244 = param_2;
  DAT_2300324c = ~param_2;
  DAT_230030e6 = (ushort)param_2 ^ (ushort)(param_2 >> 0x10);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23020fec. Types and names are inferred; NOT original source. */

void FUN_23020fec(char *param_1)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  char cVar4;
  uint uVar5;
  byte *pbVar6;
  
  DAT_230031fa = *param_1 != '\0';
  DAT_230031fb = param_1[1];
  if (0x27 < DAT_230031fb - 1) {
    DAT_230031fa = 0;
    return;
  }
  pbVar3 = (byte *)(param_1 + 1);
  pcVar2 = (char *)&DAT_230031fb;
  pbVar6 = pbVar3 + DAT_230031fb;
  do {
    while( true ) {
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
      if (bVar1 - 2 < 0x7f) break;
      pcVar2 = pcVar2 + 1;
      *pcVar2 = '\0';
      if (pbVar3 == pbVar6) {
        return;
      }
    }
    uVar5 = (short)(ushort)(bVar1 >> 4) * 10 + (bVar1 & 0xf);
    if (uVar5 == 2) {
      cVar4 = '%';
    }
    else if (uVar5 < 0x1a) {
      cVar4 = (char)((uVar5 - 4) * 0x800000 >> 0x18);
    }
    else if (uVar5 == 0x1a) {
      cVar4 = '&';
    }
    else if (uVar5 < 0x50) {
      cVar4 = (char)((int)(uVar5 - 0x1c) >> 1) + '\v';
    }
    else {
      cVar4 = '\'';
    }
    pcVar2 = pcVar2 + 1;
    *pcVar2 = cVar4;
  } while (pbVar3 != pbVar6);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021094. Types and names are inferred; NOT original source. */

void FUN_23021094(undefined4 param_1,undefined4 param_2)

{
  DAT_23003240 = param_2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021114. Types and names are inferred; NOT original source. */

void FUN_23021114(byte *param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  uint uVar4;
  
  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  if (DAT_230031f6 != 0) {
    pbVar2 = (byte *)((int)&DAT_230031aa + 1);
    do {
      while( true ) {
        pbVar1 = pbVar2 + 1;
        uVar4 = (uint)*pbVar1;
        if (uVar4 < 8) break;
        if (0xf < uVar4) {
          if (uVar4 < 0x18) {
            param_1[2] = (byte)(1 << (uVar4 - 0x10 & 0xff)) | param_1[2];
          }
          else if (uVar4 < 0x20) {
            param_1[3] = (byte)(1 << (uVar4 - 0x18 & 0xff)) | param_1[3];
          }
          else if (uVar4 < 0x28) {
            param_1[4] = (byte)(1 << (uVar4 - 0x20 & 0xff)) | param_1[4];
          }
          goto LAB_2302113c;
        }
        param_1[1] = (byte)(1 << (uVar4 - 8 & 0xff)) | param_1[1];
        pbVar3 = pbVar2 + -0x230031aa;
        pbVar2 = pbVar1;
        if ((int)(uint)DAT_230031f6 <= (int)pbVar3) {
          return;
        }
      }
      *param_1 = *param_1 | (byte)(1 << uVar4);
LAB_2302113c:
      pbVar3 = pbVar2 + -0x230031aa;
      pbVar2 = pbVar1;
    } while ((int)pbVar3 < (int)(uint)DAT_230031f6);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230211c8. Types and names are inferred; NOT original source. */

void FUN_230211c8(int param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined1 uVar6;
  byte bVar7;
  byte bVar8;
  byte local_19 [5];
  
  if (DAT_230031f7 == '\0') {
    thunk_FUN_0e0621b8(local_19,1);
    uVar5 = local_19[0] & 0xf;
    uVar3 = (uint)(local_19[0] >> 4);
    DAT_230031d2 = (&DAT_230003bd)
                   [uVar3 - (((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xc) + uVar3 / 5)];
    DAT_230031d1 = (&DAT_230003b8)
                   [uVar5 - (((uint)((ulonglong)uVar5 * 0xcccccccd >> 0x20) & 0xc) + uVar5 / 5)];
    thunk_FUN_0e0621b8(local_19,1);
    uVar5 = local_19[0] & 0xf;
    uVar3 = (uint)(local_19[0] >> 4);
    DAT_230031d3 = (&DAT_230003c2)
                   [uVar5 - (((uint)((ulonglong)uVar5 * 0xcccccccd >> 0x20) & 0xc) + uVar5 / 5)];
    DAT_230031d4 = (&DAT_230003c7)
                   [uVar3 - (((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xc) + uVar3 / 5)];
    thunk_FUN_0e0621b8(local_19,1);
    uVar5 = local_19[0] & 0xf;
    uVar3 = (uint)(local_19[0] >> 4);
    DAT_230031d5 = (&DAT_230003cc)
                   [uVar5 - (((uint)((ulonglong)uVar5 * 0xcccccccd >> 0x20) & 0xc) + uVar5 / 5)];
    DAT_230031d6 = (&DAT_230003d1)
                   [uVar3 - (((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xc) + uVar3 / 5)];
    thunk_FUN_0e0621b8(local_19,1);
    uVar3 = local_19[0] & 0xf;
    uVar5 = (uint)(local_19[0] >> 4);
    DAT_230031d7 = (&DAT_230003d6)
                   [uVar3 - (((uint)((ulonglong)uVar3 * 0xcccccccd >> 0x20) & 0xc) + uVar3 / 5)];
    uVar3 = uVar5 - (((uint)((ulonglong)uVar5 * 0xaaaaaaab >> 0x20) & 0xe) + uVar5 / 3) & 0xff;
    if (uVar3 == 0) {
      param_1 = 1;
    }
    else if (uVar3 == 1) {
      param_1 = 6;
    }
    else {
      param_1 = 0xb;
    }
  }
  else {
    FUN_230213f0(&DAT_230031d1,0);
    FUN_230213f0(&DAT_230031d3,1);
    FUN_230213f0(&DAT_230031d5,2);
  }
  pbVar4 = (byte *)0x230003d5;
  uVar3 = 0xff;
  uVar5 = 0xff;
  bVar1 = 0;
  bVar7 = 0;
  do {
    while( true ) {
      bVar8 = bVar1;
      pbVar4 = pbVar4 + 1;
      uVar2 = (uint)*pbVar4;
      bVar1 = (&DAT_2300315c)[uVar2];
      if (bVar1 < bVar8) break;
      uVar3 = uVar5;
      uVar5 = uVar2;
      bVar7 = bVar8;
      if (pbVar4 == &DAT_230003da) goto LAB_23021334;
    }
    if (bVar7 <= bVar1) {
      uVar3 = uVar2;
      bVar7 = bVar1;
    }
    bVar1 = bVar8;
  } while (pbVar4 != &DAT_230003da);
LAB_23021334:
  uVar6 = (undefined1)uVar5;
  if (uVar5 == 0xff) {
    thunk_FUN_0e0621b8(local_19,1);
    uVar5 = local_19[0] & 0xf;
    uVar6 = (&DAT_230003d6)
            [uVar5 - (((uint)((ulonglong)uVar5 * 0xcccccccd >> 0x20) & 0xc) + uVar5 / 5)];
  }
  if (uVar3 == 0xff) {
    thunk_FUN_0e0621b8(local_19,1);
  }
  DAT_230031d7 = uVar6;
  if (param_1 != 1) {
    if (param_1 == 6) {
      DAT_230031ac = DAT_230031d1;
      DAT_230031ad = DAT_230031d5;
      DAT_230031f6 = 2;
    }
    else if (param_1 == 0xb) {
      DAT_230031ac = DAT_230031d1;
      DAT_230031ad = DAT_230031d3;
      DAT_230031f6 = 2;
      return;
    }
    return;
  }
  DAT_230031ac = DAT_230031d3;
  DAT_230031ad = DAT_230031d5;
  DAT_230031f6 = 2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230213f0. Types and names are inferred; NOT original source. */

void FUN_230213f0(undefined1 *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined1 uVar9;
  byte bVar10;
  byte bVar11;
  byte local_19 [5];
  byte *pbVar5;
  
  uVar8 = 0xff;
  pbVar3 = &DAT_230003e8 + (byte)(&DAT_230003e0)[param_2 * 2];
  if ((byte)(&DAT_230003e1)[param_2 * 2] != 0) {
    pbVar5 = pbVar3;
    uVar6 = 0xff;
    bVar1 = 0;
    bVar10 = 0;
    do {
      while( true ) {
        bVar11 = bVar1;
        pbVar4 = pbVar5 + 1;
        uVar2 = (uint)*pbVar5;
        bVar1 = (&DAT_2300315c)[uVar2];
        pbVar5 = pbVar4;
        if (bVar1 < bVar11) break;
        uVar8 = uVar6;
        uVar6 = uVar2;
        bVar10 = bVar11;
        if (pbVar3 + (byte)(&DAT_230003e1)[param_2 * 2] == pbVar4) goto LAB_2302143e;
      }
      if (bVar10 <= bVar1) {
        uVar8 = uVar2;
        bVar10 = bVar1;
      }
      bVar1 = bVar11;
    } while (pbVar3 + (byte)(&DAT_230003e1)[param_2 * 2] != pbVar4);
LAB_2302143e:
    uVar7 = (undefined1)uVar8;
    uVar9 = (undefined1)uVar6;
    if (uVar6 != 0xff) goto joined_r0x23021444;
  }
  uVar7 = (undefined1)uVar8;
  thunk_FUN_0e0621b8(local_19,1);
  uVar6 = local_19[0] & 0xf;
  uVar9 = (&DAT_230003b8)
          [uVar6 - (((uint)((ulonglong)uVar6 * 0xcccccccd >> 0x20) & 0xc) + uVar6 / 5)];
joined_r0x23021444:
  if (uVar8 == 0xff) {
    thunk_FUN_0e0621b8(local_19,1);
    uVar8 = (uint)(local_19[0] >> 4);
    uVar7 = (&DAT_230003bd)
            [uVar8 - (((uint)((ulonglong)uVar8 * 0xcccccccd >> 0x20) & 0xc) + uVar8 / 5)];
    *param_1 = uVar9;
    param_1[1] = uVar7;
    return;
  }
  *param_1 = uVar9;
  param_1[1] = uVar7;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230214bc. Types and names are inferred; NOT original source. */

void FUN_230214bc(void)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined2 local_16;
  undefined1 local_14;
  
  local_18 = 0x28;
  local_17 = (undefined1)DAT_230030de;
  local_16 = CONCAT11(DAT_230030de._2_1_,DAT_230030de._1_1_);
  local_14 = DAT_230030de._3_1_;
  FUN_230208b8(0,0,&local_18,5,0xff);
  local_17 = DAT_230030e2;
  local_16 = DAT_230033d6 << 8 | DAT_230033d6 >> 8;
  local_14 = 0;
  local_18 = 0x29;
  FUN_230208b8(0,0,&local_18,5,0xff);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021534. Types and names are inferred; NOT original source. */

void FUN_23021534(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_230030e6;
  DAT_230030e4 = (undefined2)param_1;
  iVar1 = FUN_23021b8c(param_1 ^ uVar2);
  iVar1 = FUN_23021b8c(uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff);
  iVar1 = FUN_23021b8c(uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff);
  uVar2 = uVar2 ^ uVar2 + (iVar1 * 0x11 & 0xffffU) & 0xffff;
  DAT_230030e3 = (&DAT_23003132)[uVar2 % 0x25];
  if (DAT_230030e3 == -1) {
    DAT_230030e3 = (&DAT_2300310d)[(byte)(&DAT_230030e8)[uVar2 * DAT_23003157 >> 0x10]];
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230215c4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_230215c4(void)

{
  DAT_2300534b = CONCAT13((&DAT_2300040c)[_DAT_0fffe010 & 3],
                          CONCAT12((&DAT_23000408)[(_DAT_0fffe010 & 0xf) >> 2],
                                   CONCAT11((&DAT_23000404)[(_DAT_0fffe010 & 0x3f) >> 4],
                                            (&DAT_23000400)[(_DAT_0fffe010 & 0xff) >> 6])));
  DAT_2300534f = CONCAT13((&DAT_2300041c)[_DAT_0fffe014 & 3],
                          CONCAT12((&DAT_23000418)[(_DAT_0fffe014 & 0xf) >> 2],
                                   CONCAT11((&DAT_23000414)[(_DAT_0fffe014 & 0x3f) >> 4],
                                            (&DAT_23000410)[(_DAT_0fffe014 & 0xff) >> 6])));
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021654. Types and names are inferred; NOT original source. */

uint FUN_23021654(undefined4 param_1,int param_2)

{
  if ((DAT_2300323e == 0) || (DAT_2300323e == 1)) {
    return (uint)*(byte *)((int)&DAT_2300534b + param_2 * 4 + (uint)(byte)(&DAT_23005349)[param_2]);
  }
  if ((DAT_2300323e != 2) && (DAT_2300323e != 3)) {
    return 0x962;
  }
  FUN_23021534();
  DAT_23003228 = (ushort)DAT_230030e3;
  return (uint)(byte)(&DAT_0e06fb84)[DAT_230030e3];
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230216b0. Types and names are inferred; NOT original source. */

undefined1 FUN_230216b0(int param_1)

{
  return (&DAT_0e06fb84)[param_1];
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021700. Types and names are inferred; NOT original source. */

void FUN_23021700(void)

{
  byte bVar1;
  dword dVar2;
  dword dVar3;
  int iVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  
  if ((1 < DAT_2300323e) && (DAT_2300323e - 2 < 2)) {
    iVar4 = 0;
    uVar7 = 0;
    pbVar9 = (byte *)0x230030d8;
    do {
      bVar6 = 1;
      pbVar9 = pbVar9 + 1;
      bVar1 = *pbVar9;
      puVar10 = (undefined1 *)(uVar7 + 0x23003131);
      uVar8 = uVar7 + 8;
      do {
        uVar5 = (undefined1)uVar7;
        if ((bVar1 & bVar6) == 0) {
          uVar5 = 0xff;
        }
        else {
          (&DAT_230030e8)[iVar4] = (char)iVar4;
          (&DAT_2300310d)[iVar4] = uVar5;
          iVar4 = iVar4 + 1;
        }
        uVar7 = uVar7 + 1;
        puVar10 = puVar10 + 1;
        *puVar10 = uVar5;
        bVar6 = bVar6 << 1;
      } while ((uVar7 < 0x25) && (uVar8 != uVar7));
    } while (pbVar9 != &DAT_230030dd);
    DAT_23003157 = (char)iVar4;
    dVar2 = RADIO_S_BASE1;
    dVar3 = RADIO_S_BASE1;
    DAT_230030e6 = (ushort)dVar3 ^ (ushort)(dVar2 >> 0x10);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021718. Types and names are inferred; NOT original source. */

void FUN_23021718(void)

{
  byte bVar1;
  dword dVar2;
  dword dVar3;
  int iVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  undefined1 *puVar10;
  
  DAT_230030d9 = DAT_230030de;
  DAT_230030dd = DAT_230030e2;
  if ((1 < DAT_2300323e) && (DAT_2300323e - 2 < 2)) {
    iVar4 = 0;
    uVar7 = 0;
    pbVar9 = (byte *)0x230030d8;
    do {
      bVar6 = 1;
      pbVar9 = pbVar9 + 1;
      bVar1 = *pbVar9;
      puVar10 = (undefined1 *)(uVar7 + 0x23003131);
      uVar8 = uVar7 + 8;
      do {
        uVar5 = (undefined1)uVar7;
        if ((bVar1 & bVar6) == 0) {
          uVar5 = 0xff;
        }
        else {
          (&DAT_230030e8)[iVar4] = (char)iVar4;
          (&DAT_2300310d)[iVar4] = uVar5;
          iVar4 = iVar4 + 1;
        }
        uVar7 = uVar7 + 1;
        puVar10 = puVar10 + 1;
        *puVar10 = uVar5;
        bVar6 = bVar6 << 1;
      } while ((uVar7 < 0x25) && (uVar8 != uVar7));
    } while (pbVar9 != &DAT_230030dd);
    DAT_23003157 = (char)iVar4;
    dVar2 = RADIO_S_BASE1;
    dVar3 = RADIO_S_BASE1;
    DAT_230030e6 = (ushort)dVar3 ^ (ushort)(dVar2 >> 0x10);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021af4. Types and names are inferred; NOT original source. */

undefined4 FUN_23021af4(int param_1)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  
  if (DAT_230031aa != 0) {
    DAT_230031aa = DAT_230031aa + -1;
    return 0;
  }
  uVar2 = (uint)DAT_230031a8;
  (&DAT_23003452)[param_1 * 0xf84] = (&DAT_230003e8)[uVar2];
  DAT_230031a7 = DAT_230031a7 + 1;
  bVar1 = DAT_230031a8;
  if (9 < DAT_230031a7) {
    uVar2 = uVar2 + 1;
    DAT_230031a7 = 0;
    if ((uVar2 & 0xff) < 0x17) {
      DAT_230031a8 = (char)uVar2;
      return 1;
    }
    DAT_230031a8 = 0;
    bVar3 = DAT_230031a6 != 0xff;
    DAT_230031a6 = 0;
    bVar1 = 0;
    if (bVar3) {
      if (DAT_230033e8 == 3) {
        DAT_230031aa = 200;
      }
      else {
        DAT_230031aa = 5000;
      }
      DAT_230031a6 = 0;
      DAT_230031a9 = 1;
      bVar1 = DAT_230031a8;
    }
  }
  DAT_230031a8 = bVar1;
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021b8c. Types and names are inferred; NOT original source. */

ushort FUN_23021b8c(uint param_1)

{
  return (ushort)(byte)"7J2CyEPxN1miKPZCPoWOZxArbjiLfHYysi3LvIVVDCEo5eT4hIDO88XVKfNMYEk3jnMVteRXR2cnu8qX12GJdIuJlnXz2vd757dkMNqMXSxorjDLU4IWJ9PUpdEja8B58ZyjCOcUiJgUYoR57JG0wiUWnZYfErkEny3PyM23SMkSsr8bMYDRUwdb256hj4b2xsIDSYeDa0xUAKV54Cvt3x0DtzsKHAAwNqdgjmVSa8VEgtVKEumomQz51OFDRORr"
                       [((param_1 & 0xff) >> 4) + 0x100] |
         (ushort)(byte)"7J2CyEPxN1miKPZCPoWOZxArbjiLfHYysi3LvIVVDCEo5eT4hIDO88XVKfNMYEk3jnMVteRXR2cnu8qX12GJdIuJlnXz2vd757dkMNqMXSxorjDLU4IWJ9PUpdEja8B58ZyjCOcUiJgUYoR57JG0wiUWnZYfErkEny3PyM23SMkSsr8bMYDRUwdb256hj4b2xsIDSYeDa0xUAKV54Cvt3x0DtzsKHAAwNqdgjmVSa8VEgtVKEumomQz51OFDRORr"
                       [(param_1 & 0xf) + 0x100] << 4 |
         (ushort)(byte)"7J2CyEPxN1miKPZCPoWOZxArbjiLfHYysi3LvIVVDCEo5eT4hIDO88XVKfNMYEk3jnMVteRXR2cnu8qX12GJdIuJlnXz2vd757dkMNqMXSxorjDLU4IWJ9PUpdEja8B58ZyjCOcUiJgUYoR57JG0wiUWnZYfErkEny3PyM23SMkSsr8bMYDRUwdb256hj4b2xsIDSYeDa0xUAKV54Cvt3x0DtzsKHAAwNqdgjmVSa8VEgtVKEumomQz51OFDRORr"
                       [((param_1 & 0xfff) >> 8) + 0x100] << 0xc |
         (ushort)(byte)"7J2CyEPxN1miKPZCPoWOZxArbjiLfHYysi3LvIVVDCEo5eT4hIDO88XVKfNMYEk3jnMVteRXR2cnu8qX12GJdIuJlnXz2vd757dkMNqMXSxorjDLU4IWJ9PUpdEja8B58ZyjCOcUiJgUYoR57JG0wiUWnZYfErkEny3PyM23SMkSsr8bMYDRUwdb256hj4b2xsIDSYeDa0xUAKV54Cvt3x0DtzsKHAAwNqdgjmVSa8VEgtVKEumomQz51OFDRORr"
                       [(param_1 >> 0xc) + 0x100] << 8;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021bbc. Types and names are inferred; NOT original source. */

/* WARNING: Removing unreachable block (ram,0x23023be8) */
/* WARNING: Removing unreachable block (ram,0x23023bec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23021bbc(void)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  dword dVar4;
  undefined4 uVar5;
  dword dVar6;
  undefined2 uVar7;
  uint uVar8;
  dword dVar9;
  undefined4 *puVar10;
  uint uVar11;
  
  if (DAT_23003230 < 2) {
    return;
  }
  if (DAT_23003234 != 4) {
    if (DAT_23003234 != 1) {
      if (DAT_23003234 != 2) {
        return;
      }
      dVar9 = TIMER020_S_EVENTS_COMPARE_0;
      if (dVar9 == 1) {
        TIMER020_S_EVENTS_COMPARE_0 = 0;
        TIMER020_S_CC_0 = 16000;
        RADIO_S_SUBSCRIBE_TXEN = 0;
        RADIO_S_SUBSCRIBE_RXEN = 0;
        TIMER020_S_CC_1 = 0x1040;
        TIMER020_S_CC_2 = 0x1220;
        FUN_23022888(0);
        DAT_230032d0 = 0;
        return;
      }
      dVar9 = TIMER020_S_EVENTS_COMPARE_1;
      if (dVar9 != 1) {
        dVar9 = TIMER020_S_EVENTS_COMPARE_2;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_2 = 0;
          if (DAT_230032d0 == 1) {
            RADIO_S_SUBSCRIBE_TXEN = 0;
            RADIO_S_SUBSCRIBE_RXEN = 0;
            TIMER020_S_CC_1 = 0x2260;
            TIMER020_S_CC_2 = 0x2580;
            FUN_23022888(1);
            return;
          }
          if (DAT_230032d0 == 2) {
            RADIO_S_SUBSCRIBE_TXEN = 0;
            TIMER020_S_CC_1 = 0x3980;
            TIMER020_S_CC_2 = 0;
            if (DAT_23005370 == 0xb) {
              FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE);
            }
            if (2 < DAT_230033e8) {
              DAT_23003470 = DAT_23003470 + 1;
              DAT_2300346e = DAT_2300346e + 1;
              DAT_23003474 = DAT_23003474 + 1;
            }
            if (2 < DAT_2300436c) {
              DAT_230043f2 = DAT_230043f2 + 1;
              DAT_230043f4 = DAT_230043f4 + 1;
              DAT_230043f8 = DAT_230043f8 + 1;
            }
            if (2 < DAT_230052f0) {
              DAT_23005376 = DAT_23005376 + 1;
              DAT_23005378 = DAT_23005378 + 1;
              DAT_2300537c = DAT_2300537c + 1;
            }
            DAT_23003222 = FUN_23021654(DAT_23005376,DAT_230032ca);
            DAT_230032ca = (ushort)(((uint)DAT_23005376 << 0x1e) >> 0x1f);
            FUN_23022e48(0);
            FUN_23022e48(1);
            return;
          }
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_3;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_3 = 0;
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_4;
        if (dVar9 != 1) {
          dVar9 = TIMER020_S_EVENTS_COMPARE_5;
          if (dVar9 == 1) {
            TIMER020_S_EVENTS_COMPARE_5 = 0;
            return;
          }
          dVar9 = TIMER020_S_EVENTS_COMPARE_6;
          if (dVar9 == 1) {
            TIMER020_S_EVENTS_COMPARE_6 = 0;
            return;
          }
          dVar9 = TIMER020_S_EVENTS_COMPARE_7;
          if (dVar9 == 1) {
            TIMER020_S_EVENTS_COMPARE_7 = 0;
            return;
          }
          return;
        }
        TIMER020_S_EVENTS_COMPARE_4 = 0;
        return;
      }
      TIMER020_S_EVENTS_COMPARE_1 = 0;
      RADIO_S_SUBSCRIBE_DISABLE = 0;
      RADIO_S_SUBSCRIBE_DISABLE = 0;
      uVar1 = DAT_230032d0;
      if (DAT_230032d0 == 0) {
        FUN_230226c8();
        if (DAT_23003468 == 9) {
          DAT_23003468 = 7;
          DAT_230034b0 = uVar1;
        }
        DAT_230032d0 = 1;
        return;
      }
      if (DAT_230032d0 != 1) {
        if (DAT_230032d0 == 2) {
          FUN_230226c8(0);
          DAT_230032d0 = 0;
          return;
        }
        return;
      }
      FUN_230226c8(2);
      if (DAT_230043ec == 9) {
        DAT_23004434 = 0;
        DAT_230043ec = 7;
      }
      DAT_230032d0 = 2;
      if (DAT_23005370 != 0xd) {
        DAT_230032d0 = 2;
        return;
      }
      if (DAT_23003484 == '\0') {
        if (DAT_23004408 == '\0') {
          RADIO_S_SUBSCRIBE_TXEN = 0;
          FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE);
          DAT_23003484 = 0;
          DAT_23004408 = 0;
          return;
        }
        DAT_2300347e._0_2_ = 0xff;
        DAT_23004402._0_2_ = 0xff;
      }
      else {
        DAT_2300347e._0_2_ = 0xff;
        DAT_23004402._0_2_ = 0xff;
        if (DAT_23003484 == '\x01') {
          uVar8 = 0;
          do {
            puVar10 = (undefined4 *)FUN_230207ec(0,uVar8 & 0xffff);
            uVar11 = uVar8 + 1;
            if (puVar10 != (undefined4 *)0x0) {
              uVar5 = 0;
              DAT_2300347e._0_2_ = (undefined2)uVar8;
              uVar2 = 1;
              goto LAB_23023124;
            }
            uVar8 = uVar11;
          } while (uVar11 != 6);
        }
      }
      if (DAT_23004408 == '\x01') {
        uVar8 = 0;
        do {
          puVar10 = (undefined4 *)FUN_230207ec(1,uVar8 & 0xffff);
          uVar11 = uVar8 + 1;
          if (puVar10 != (undefined4 *)0x0) {
            DAT_23004402._0_2_ = (undefined2)uVar8;
            uVar5 = 1;
            uVar2 = 0;
            goto LAB_23023124;
          }
          uVar8 = uVar11;
        } while (uVar11 != 6);
      }
      uVar2 = 0;
      DAT_230053e4 = 5;
      DAT_230053e6 = FUN_230209dc(0,DAT_23005397);
      uVar5 = 0;
      DAT_23005397 = DAT_23005397 + '\x01';
      if (DAT_23005397 == '\b') {
        DAT_23005397 = '\x01';
      }
      DAT_230053e7 = 0x1f;
      puVar10 = (undefined4 *)&DAT_230053e4;
      DAT_230053e8._0_2_ = CONCAT11(DAT_230053e8._1_1_,DAT_23005349 & 0xf | DAT_2300534a << 4);
LAB_23023124:
      uVar2 = FUN_2302098c(DAT_23004408,DAT_23003484,uVar5,uVar2,
                           *(undefined1 *)((int)&DAT_230033e8 + (DAT_230032ca + 0xfcc) * 2));
      *(undefined1 *)((int)puVar10 + 1) = uVar2;
      RADIO_S_PACKETPTR = 0x23003070;
      DAT_23004408 = 0;
      DAT_23003484 = 0;
      DAT_2300307c = puVar10[3];
      DAT_23003078 = puVar10[2];
      DAT_23003074 = puVar10[1];
      DAT_23003070 = *puVar10;
      return;
    }
    dVar9 = TIMER020_S_EVENTS_COMPARE_0;
    if (dVar9 == 1) {
      TIMER020_S_EVENTS_COMPARE_0 = 0;
      TIMER020_S_CC_0 = 16000;
      RADIO_S_SUBSCRIBE_RXEN = 0;
      if (DAT_2300341c == 1) {
        uVar5 = 0xf00;
        TIMER020_S_CC_1 = 0xb40;
        TIMER020_S_CC_2 = 0xf00;
        TIMER020_S_CC_3 = 0x2bc0;
      }
      else {
        uVar5 = 0x1220;
        TIMER020_S_CC_1 = 0xe60;
        TIMER020_S_CC_2 = 0x1220;
        TIMER020_S_CC_3 = 0xa00;
      }
      DAT_230032d0 = 0;
      FUN_230233b0(1,uVar5,0,1);
      return;
    }
    dVar9 = TIMER020_S_EVENTS_COMPARE_1;
    if (dVar9 != 1) {
      dVar9 = TIMER020_S_EVENTS_COMPARE_2;
      if (dVar9 != 1) {
        dVar9 = TIMER020_S_EVENTS_COMPARE_3;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_3 = 0;
          if (DAT_2300341c == 1) {
            TIMER020_S_CC_3 = 0;
            FUN_230233b0(5,1,0,1);
            return;
          }
          if ((DAT_230032d0 & 0xfffd) == 0) {
            FUN_230233b0(5,DAT_2300341c,0,1);
            return;
          }
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_4;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_4 = 0;
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_5;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_5 = 0;
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_6;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_6 = 0;
          return;
        }
        dVar9 = TIMER020_S_EVENTS_COMPARE_7;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_7 = 0;
          return;
        }
        return;
      }
      TIMER020_S_EVENTS_COMPARE_2 = 0;
      if (DAT_2300341c == 1) {
        if (DAT_230032d0 == 0) {
          dVar9 = 0xb40;
          dVar4 = 0xf00;
        }
        else {
          switch(DAT_230032d0) {
          case 1:
            dVar9 = 0x15e0;
            dVar4 = 0x19a0;
            break;
          case 2:
            dVar9 = 0x2080;
            dVar4 = 0x2440;
            break;
          case 3:
            dVar9 = 0x2e40;
            dVar4 = 0x3160;
            break;
          case 4:
            TIMER020_S_CC_1 = 0x3ac0;
            TIMER020_S_CC_2 = 0;
joined_r0x23023dd4:
            if (DAT_23005370 == 0xd) {
              FUN_23023268();
            }
            if (2 < DAT_230033e8) {
              DAT_2300346e = DAT_2300346e + 1;
              DAT_23003470 = DAT_23003470 + 1;
              if (DAT_23003474 < 200) {
                DAT_23003474 = DAT_23003474 + 1;
              }
            }
            FUN_23023b5c(2);
            if (2 < DAT_230033e8) {
              if (99 < DAT_23003470) {
                RADIO_S_SUBSCRIBE_RXEN = 0;
                RADIO_S_SUBSCRIBE_TXEN = 0;
                RADIO_S_SUBSCRIBE_RXEN = 0;
                RADIO_S_SUBSCRIBE_TXEN = 0;
                RADIO_S_SUBSCRIBE_TXEN = 0;
                RADIO_S_SUBSCRIBE_DISABLE = 0;
                FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_DISABLE,0);
                FUN_23021dfc(0);
                FUN_230221a4(0);
                FUN_230254f8(&stack0xffffffe8);
                return;
              }
              if (DAT_23003474 < 200) {
                DAT_230033e8 = 3;
              }
              else {
                DAT_230033e8 = 4;
              }
            }
            return;
          default:
            goto switchD_23023e40_default;
          }
        }
        TIMER020_S_CC_1 = dVar9;
        TIMER020_S_CC_2 = dVar4;
        FUN_230233b0(1,dVar9,dVar4,1);
        return;
      }
      if (DAT_230032d0 == 0) {
        dVar9 = 0xe60;
        dVar4 = 0x1220;
        dVar6 = 0;
LAB_23023ec8:
        TIMER020_S_CC_1 = dVar9;
        TIMER020_S_CC_2 = dVar4;
        TIMER020_S_CC_3 = dVar6;
        FUN_230233b0();
        return;
      }
      if (DAT_230032d0 == 1) {
        TIMER020_S_CC_1 = 0x1b80;
        TIMER020_S_CC_2 = 8000;
        TIMER020_S_CC_3 = 0;
        if (DAT_23005370 == 0xd) {
          FUN_23023268();
          return;
        }
      }
      else {
        if (DAT_230032d0 == 2) {
          dVar9 = 0x2da0;
          dVar4 = 0x3160;
          dVar6 = 0x2940;
          goto LAB_23023ec8;
        }
        if (DAT_230032d0 == 3) {
          TIMER020_S_CC_1 = 0x3ac0;
          TIMER020_S_CC_2 = 0;
          TIMER020_S_CC_3 = 0;
          goto joined_r0x23023dd4;
        }
      }
switchD_23023e40_default:
      return;
    }
    TIMER020_S_EVENTS_COMPARE_1 = 0;
    if (DAT_2300341c == 1) {
      uVar7 = 1;
      if (DAT_230032d0 == 0) {
LAB_23023e64:
        DAT_230032d0 = uVar7;
        FUN_230232d0();
        return;
      }
      switch(DAT_230032d0) {
      case 1:
        uVar7 = 2;
        goto LAB_23023e64;
      case 2:
        DAT_230032d0 = 3;
        FUN_230232d0();
        return;
      case 3:
        FUN_230233b0(2);
        DAT_230032d0 = 4;
        break;
      case 4:
        uVar1 = DAT_2300341e;
        DAT_230032d0 = 0;
        if ((DAT_2300341e != 0) && (DAT_23003420 == DAT_23005376)) {
          DAT_2300341e = 0;
          DAT_2300341c = uVar1;
        }
        goto LAB_23023cfc;
      default:
        goto switchD_23023e40_default;
      }
    }
    else {
      if (DAT_230032d0 == 0) {
        DAT_230032d0 = 1;
        FUN_230232d0();
        goto LAB_23023bcc;
      }
      if (DAT_230032d0 == 1) {
        DAT_230032d0 = 2;
LAB_23023cfc:
        FUN_230232d0();
        FUN_230233b0(4);
        return;
      }
      if (DAT_230032d0 != 2) {
        if (DAT_230032d0 != 3) {
          return;
        }
        DAT_230032d0 = 0;
        if ((DAT_2300341e != 0) && (DAT_23003420 == DAT_23005376)) {
          DAT_2300341c = DAT_2300341e;
          DAT_2300341e = 0;
        }
        goto LAB_23023cfc;
      }
      DAT_230032d0 = 3;
    }
    FUN_230232d0();
LAB_23023bcc:
    if (DAT_23005370 != 0xd) {
      return;
    }
    if (DAT_2300341c == 1) {
      if ((DAT_23003484 == '\0') || (iVar3 = FUN_230237e0(), iVar3 == 0)) {
        RADIO_S_SUBSCRIBE_TXEN = 0;
        FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE,0xd);
        FUN_23023708(0);
      }
    }
    else if ((DAT_23003484 == '\0') || (iVar3 = FUN_230237e0(), iVar3 == 0)) {
      RADIO_S_SUBSCRIBE_TXEN = 0;
      RADIO_S_SUBSCRIBE_TXEN = 0;
      FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE,0xd);
    }
    DAT_23003484 = 0;
    return;
  }
  dVar9 = TIMER020_S_EVENTS_COMPARE_0;
  if (dVar9 == 1) {
    TIMER020_S_EVENTS_COMPARE_0 = 0;
    DAT_230032d0 = 0;
    TIMER020_S_CC_0 = 16000;
    RADIO_S_SUBSCRIBE_RXEN = 0;
    TIMER020_S_CC_1 = 0xaa0;
    TIMER020_S_CC_4 = 0;
    TIMER020_S_CC_2 = 0xc80;
    if ((DAT_23003468 == 0xb) || (DAT_23003468 == 0xc)) {
      RADIO_S_SUBSCRIBE_RXEN = 0;
    }
    uVar8 = (uint)DAT_23005376;
    if ((DAT_2300325d != '\0') && (DAT_230033d6 == uVar8)) {
      DAT_2300325d = '\0';
      FUN_23021718();
      uVar8 = (uint)DAT_23005376;
    }
    uVar5 = DAT_230033dc;
    uVar8 = uVar8 & 0x7ff;
    if (uVar8 != 0) {
      return;
    }
    DAT_230033d8 = DAT_230033dc;
    DAT_230033dc = uVar8;
    DAT_230033d8._2_2_ = (ushort)((uint)uVar5 >> 0x10);
    DAT_230033e0 = 0;
    if (DAT_2300341c != 1) {
      if (DAT_2300341c < 0x21) {
        switch(DAT_2300341c) {
        case 2:
          if (DAT_230033d8._2_2_ < 0xf9a) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        case 4:
          if (DAT_230033d8._2_2_ < 0x7cd) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        case 8:
          if (DAT_230033d8._2_2_ < 999) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        case 0x10:
          if (DAT_230033d8._2_2_ < 500) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        case 0x20:
          if (DAT_230033d8._2_2_ < 0xfa) {
            DAT_230033d8 = uVar5;
            return;
          }
          DAT_230033d8 = uVar5;
          DAT_230033e0 = 1;
          return;
        }
      }
      else if (DAT_2300341c == 0x40) {
        if (DAT_230033d8._2_2_ < 0x7d) {
          DAT_230033d8 = uVar5;
          return;
        }
        DAT_230033d8 = uVar5;
        DAT_230033e0 = 1;
        return;
      }
    }
    if (DAT_230033d8._2_2_ < 0x1f9a) {
      DAT_230033d8 = uVar5;
      return;
    }
    DAT_230033e0 = 1;
    DAT_230033d8 = uVar5;
    return;
  }
  dVar9 = TIMER020_S_EVENTS_COMPARE_1;
  if (dVar9 != 1) {
    dVar9 = TIMER020_S_EVENTS_COMPARE_2;
    if (dVar9 == 1) {
      TIMER020_S_EVENTS_COMPARE_2 = 0;
      if (DAT_230032d0 == 1) {
        TIMER020_S_CC_1 = 0x1220;
        TIMER020_S_CC_4 = 0x1220;
        TIMER020_S_CC_2 = 0x14a0;
        if ((DAT_23003468 == 0xb) || (DAT_23003468 == 0xc)) {
          RADIO_S_SUBSCRIBE_RXEN = 0;
        }
      }
      else {
        switch(DAT_230032d0) {
        case 2:
          RADIO_S_SUBSCRIBE_TXEN = 0;
          TIMER020_S_CC_1 = 0x1b80;
          TIMER020_S_CC_4 = 0;
          TIMER020_S_CC_2 = 8000;
          break;
        case 3:
          RADIO_S_SUBSCRIBE_RXEN = 0;
          TIMER020_S_CC_1 = 0x29e0;
          TIMER020_S_CC_4 = 0;
          TIMER020_S_CC_2 = 0x2bc0;
          if ((DAT_23003468 == 0xb) || (DAT_23003468 == 0xc)) {
            RADIO_S_SUBSCRIBE_RXEN = 0;
          }
          break;
        case 4:
          TIMER020_S_CC_1 = 0x3160;
          TIMER020_S_CC_4 = 0x3160;
          TIMER020_S_CC_2 = 0x33e0;
          if ((DAT_23003468 == 0xb) || (DAT_23003468 == 0xc)) {
            RADIO_S_SUBSCRIBE_RXEN = 0;
          }
          break;
        case 5:
          RADIO_S_SUBSCRIBE_TXEN = 0;
          TIMER020_S_CC_1 = 0x3ac0;
          TIMER020_S_CC_4 = 0;
          TIMER020_S_CC_2 = 0;
          if (2 < DAT_230033e8) {
            DAT_2300346e = DAT_2300346e + 1;
            DAT_23003470 = DAT_23003470 + 1;
            DAT_23003474 = DAT_23003474 + 1;
          }
          if (2 < DAT_230052f0) {
            DAT_23005376 = DAT_23005376 + 1;
            DAT_23005378 = DAT_23005378 + 1;
            DAT_2300537c = DAT_2300537c + 1;
          }
          _DAT_23003226 = FUN_23021654(DAT_23005376,DAT_230032ca);
          DAT_230032ca = (ushort)(((uint)DAT_23005376 << 0x1e) >> 0x1f);
          if (2 < DAT_230033e8) {
            if (DAT_23003470 < 100) {
              if (DAT_23003474 < 200) {
                DAT_230033e8 = 3;
              }
              else {
                DAT_230033e8 = 4;
              }
            }
            else {
              RADIO_S_SUBSCRIBE_RXEN = 0;
              RADIO_S_SUBSCRIBE_RXEN = 0;
              RADIO_S_SUBSCRIBE_STOP = 0;
              RADIO_S_SUBSCRIBE_TXEN = 0;
              FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_DISABLE,0);
              FUN_23021dfc(0);
              FUN_230221a4(0);
              FUN_230254f8(&stack0xffffffe0);
            }
          }
        }
      }
    }
    else {
      dVar9 = TIMER020_S_EVENTS_COMPARE_3;
      if (dVar9 == 1) {
        TIMER020_S_EVENTS_COMPARE_3 = 0;
        return;
      }
      dVar9 = TIMER020_S_EVENTS_COMPARE_4;
      if (dVar9 == 1) {
        TIMER020_S_EVENTS_COMPARE_4 = 0;
      }
      else {
        dVar9 = TIMER020_S_EVENTS_COMPARE_5;
        if (dVar9 == 1) {
          TIMER020_S_EVENTS_COMPARE_5 = 0;
        }
        else {
          dVar9 = TIMER020_S_EVENTS_COMPARE_6;
          if (dVar9 == 1) {
            TIMER020_S_EVENTS_COMPARE_6 = 0;
          }
          else {
            dVar9 = TIMER020_S_EVENTS_COMPARE_7;
            if (dVar9 == 1) {
              TIMER020_S_EVENTS_COMPARE_7 = 0;
            }
          }
        }
      }
    }
switchD_23024a52_default:
    return;
  }
  TIMER020_S_EVENTS_COMPARE_1 = 0;
  if (DAT_230032d0 == 0) {
    DAT_230032d0 = 1;
    goto LAB_23024a6c;
  }
  switch(DAT_230032d0) {
  case 1:
    FUN_230240ac(2);
    DAT_230032d0 = 2;
    goto LAB_23024aa6;
  case 2:
    DAT_230032d0 = 3;
    break;
  case 3:
    DAT_230032d0 = 4;
    break;
  case 4:
    FUN_230240ac(2);
    DAT_230032d0 = 5;
LAB_23024aa6:
    FUN_23023fa4();
    if (DAT_23005370 != 0xd) {
      return;
    }
    if (DAT_23003484 == '\0') {
      FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE,0xe);
      DAT_23003484 = 0;
      return;
    }
    uVar8 = 0;
    do {
      puVar10 = (undefined4 *)FUN_230207ec(0,uVar8 & 0xffff);
      uVar11 = uVar8 + 1;
      if (puVar10 != (undefined4 *)0x0) {
        DAT_2300347e._0_2_ = (undefined2)uVar8;
        DAT_23003488 = 1;
        goto LAB_230248be;
      }
      uVar8 = uVar11;
    } while (uVar11 != 6);
    DAT_2300347e._0_2_ = 0xff;
    DAT_230053e4 = 5;
    DAT_230053e6 = FUN_230209dc(0,DAT_23005397);
    DAT_230053e8._0_2_ = DAT_23005376 << 8 | DAT_23005376 >> 8;
    DAT_23005397 = DAT_23005397 + '\x01';
    DAT_230053e7 = 0x1f;
    if (DAT_23005397 == '\b') {
      puVar10 = (undefined4 *)&DAT_230053e4;
      DAT_23005397 = '\x01';
    }
    else {
      puVar10 = (undefined4 *)&DAT_230053e4;
    }
LAB_230248be:
    uVar2 = FUN_230209d0(1,DAT_23003488,
                         *(undefined1 *)((int)&DAT_230033e8 + (DAT_230032ca + 0xfcc) * 2));
    *(undefined1 *)((int)puVar10 + 1) = uVar2;
    DAT_23003074 = puVar10[1];
    DAT_23003078 = puVar10[2];
    DAT_23003070 = *puVar10;
    DAT_2300307c = puVar10[3];
    RADIO_S_PACKETPTR = 0x23003070;
    TIMER020_S_TASKS_CAPTURE_7 = 1;
    if (DAT_230032d0 == 2) {
      dVar9 = TIMER020_S_CC_7;
      if (0x14a0 < dVar9) goto LAB_23024932;
    }
    else if ((DAT_230032d0 == 5) && (dVar9 = TIMER020_S_CC_7, 0x33e0 < dVar9)) {
LAB_23024932:
      FUN_23020f1c(&DAT_23005370,&RADIO_S_TASKS_DISABLE,0xd);
      DAT_23003484 = 0;
      return;
    }
    _DAT_5300e440 = 1;
    _DAT_5300e000 = 1;
    DAT_23003484 = 0;
    return;
  case 5:
    DAT_230032d0 = 0;
    break;
  default:
    goto switchD_23024a52_default;
  }
LAB_23024a6c:
  FUN_23023fa4();
  FUN_230240ac(4);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021be4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ram_candidate_23021be4(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined *puVar9;
  uint *puVar10;
  char cVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined local_28;
  undefined1 auStack_27 [3];
  
  if (DAT_23003234 == 4) {
    FUN_2302455c(DAT_230071a4);
    bVar2 = (&DAT_23003486)[(uint)DAT_230071a4 * 0xf84];
    if ((DAT_2300323e == 0) || (DAT_2300323e == 1)) {
      *(ushort *)((int)&DAT_230033e8 + ((byte)DAT_230032ca + 0x48) * 2) = (ushort)bVar2;
    }
    else if ((DAT_2300323e == 2) || (DAT_2300323e == 3)) {
      if ((ushort)(&DAT_23003232)[DAT_23003228 + 0x80] < (ushort)bVar2) {
        (&DAT_23003232)[DAT_23003228 + 0x80] = (ushort)bVar2;
      }
      return 1;
    }
    return 1;
  }
  if (DAT_23003234 != 1) {
    if (DAT_23003234 != 2) {
      return param_1;
    }
    uVar6 = (uint)DAT_230071a4;
    iVar12 = uVar6 * 0xf84;
    cVar11 = (&DAT_230034fc)[iVar12];
    uVar8 = uVar6;
    if ('\0' < (char)(&DAT_230034fc)[iVar12]) {
      uVar1 = (&DAT_230034fe)[iVar12];
      iVar7 = FUN_230209f8(uVar1);
      uVar8 = FUN_230209e4(uVar1);
      if (iVar7 == 0) {
        uVar8 = FUN_2302552c(uVar6,(&DAT_23003451)[iVar12]);
        return uVar8;
      }
      if (*(byte *)((int)&DAT_230033e8 + iVar7 + iVar12 + 0xb7) != uVar8) {
        *(char *)((int)&DAT_230033e8 + iVar7 + iVar12 + 0xb7) = (char)uVar8;
        puVar9 = &DAT_230034ff + iVar12;
        uVar8 = (uint)(char)(cVar11 + -2);
        if (iVar7 == 1) {
          local_28 = 0;
          thunk_FUN_0e06f35c(auStack_27,puVar9,uVar8);
          puVar9 = &local_28;
          uVar8 = (uint)(char)(cVar11 + -1);
        }
        local_30 = (uint)(byte)(&DAT_23003451)[uVar6 * 0xf84];
        uVar8 = FUN_230254a0(uVar6,iVar7,puVar9,uVar8 & 0xffff);
        (&DAT_23003474)[uVar6 * 0x3e1] = 0;
        return uVar8;
      }
    }
    return uVar8;
  }
  uVar8 = (uint)DAT_230071a4;
  iVar12 = uVar8 * 0xf84;
  cVar11 = (&DAT_230034fc)[iVar12];
  if ((char)(&DAT_230034fc)[iVar12] < '\x01') {
    return uVar8;
  }
  uVar1 = (&DAT_230034fe)[iVar12];
  iVar7 = FUN_230209f8(uVar1);
  uVar6 = FUN_230209e4(uVar1);
  if (iVar7 == 0) {
    if ((&DAT_230034ff)[iVar12] == '\x17') {
      (&DAT_23003474)[uVar8 * 0x3e1] =
           (*(ushort *)(&DAT_23003500 + iVar12) & 0xff) << 8 |
           (uint)(*(ushort *)(&DAT_23003500 + iVar12) >> 8);
    }
    else if ((&DAT_230034ff)[iVar12] == ',') {
      (&DAT_2300341e)[uVar8 * 0x7c2] = (ushort)(byte)(&DAT_23003500)[iVar12];
      (&DAT_23003420)[uVar8 * 0x7c2] =
           *(ushort *)(&DAT_23003501 + iVar12) << 8 | *(ushort *)(&DAT_23003501 + iVar12) >> 8;
    }
    uVar8 = FUN_2302552c(uVar8,(&DAT_23003451)[uVar8 * 0xf84]);
    return uVar8;
  }
  if (*(byte *)((int)&DAT_230033e8 + iVar7 + iVar12 + 0xb7) == uVar6) {
    if (iVar7 != 1) {
      return uVar6;
    }
    if ((&DAT_23003485)[iVar12] == '\x01') {
      _DAT_230030a2 = 0;
      DAT_230030a6 = 0;
    }
    (&DAT_23003474)[uVar8 * 0x3e1] = 0;
    return uVar6;
  }
  *(char *)((int)&DAT_230033e8 + iVar7 + iVar12 + 0xb7) = (char)uVar6;
  if (iVar7 == 1) {
    uVar3 = *(ushort *)(&DAT_23003501 + iVar12) << 8 | *(ushort *)(&DAT_23003501 + iVar12) >> 8;
    uVar4 = *(ushort *)(&DAT_23003503 + iVar12) << 8 | *(ushort *)(&DAT_23003503 + iVar12) >> 8;
    cVar5 = (char)DAT_230030a6;
    iVar14 = (int)_DAT_230030a2;
    iVar13 = (int)DAT_230030a4;
    if ((&DAT_23003485)[iVar12] == '\0') {
      _DAT_230030a2 = CONCAT22(uVar4,uVar3);
      DAT_230030a6 = CONCAT11((&DAT_230034ff)[iVar12],(&DAT_23003500)[iVar12]);
    }
    else {
      _DAT_230030a2 = 0;
      DAT_230030a6 = 0;
    }
    iVar14 = (uint)uVar3 - iVar14;
    iVar13 = (uint)uVar4 - iVar13;
    local_2c = (undefined1)iVar14;
    local_2b = (undefined1)((uint)iVar13 >> 8);
    local_2a = (undefined1)iVar13;
    cVar11 = '\a';
    puVar10 = &local_30;
    local_30 = (uint)CONCAT21(CONCAT11((char)((uint)iVar14 >> 8),(&DAT_23003500)[iVar12] - cVar5),
                              (&DAT_230034ff)[iVar12]) << 8;
  }
  else {
    cVar11 = cVar11 + -2;
    if (cVar11 < '\x01') goto LAB_230239ea;
    puVar10 = (uint *)(&DAT_230034ff + iVar12);
  }
  uVar6 = FUN_230254a0(0,iVar7,puVar10,cVar11,(&DAT_23003451)[uVar8 * 0xf84]);
LAB_230239ea:
  (&DAT_23003474)[uVar8 * 0x3e1] = 0;
  return uVar6;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021c24. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23021c24(undefined2 param_1)

{
  DAT_230071a4 = param_1;
  _DAT_e000e208 = 0x10000000;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021c3c. Types and names are inferred; NOT original source. */

void ram_candidate_23021c3c(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 extraout_r1_03;
  
  cVar1 = DAT_23003251;
  do {
    do {
      while( true ) {
        DAT_23003251 = cVar1;
        thunk_FUN_0e06d118(&DAT_23001c54,param_2,0xffffffff,0xffffffff);
        cVar1 = DAT_23003251;
        param_2 = extraout_r1;
        if ((char)DAT_23003252 == '\0') break;
        DAT_23003252 = (ushort)DAT_23003252._1_1_ << 8;
      }
    } while ((((DAT_23003250 != '\0') || (DAT_23003258 == '\0')) ||
             (cVar1 = DAT_23003250, DAT_23003251 != '\0')) ||
            ((uVar2 = (uint)DAT_23003257, cVar1 = DAT_23003251, uVar2 != 0 || (DAT_23003259 == '\0')
             )));
    if (DAT_23003252._1_1_ == 0) {
      if (DAT_23003254 == 0) {
        if (DAT_230033ec == 0) {
          if (DAT_23004370 != '\0') {
            DAT_23004370 = '\0';
            FUN_23021eb8();
            FUN_230221c0(1);
            cVar1 = DAT_23003251;
            param_2 = extraout_r1_00;
          }
        }
        else {
          DAT_230033ec = DAT_23003254;
          FUN_23021eb8();
          FUN_230221c0(0);
          cVar1 = DAT_23003251;
          param_2 = extraout_r1_02;
        }
      }
      else {
        DAT_23003254 = DAT_23003252._1_1_;
        DAT_230032d4 = 8;
        DAT_23003252 = 1;
        FUN_23021f04();
        cVar1 = DAT_23003251;
        param_2 = extraout_r1_03;
      }
    }
    else {
      DAT_23003252 = (ushort)DAT_23003257 << 8;
      DAT_230034b4 = (ushort)DAT_23003257;
      DAT_230033e8 = uVar2;
      DAT_23003468 = uVar2;
      DAT_2300347e = uVar2;
      DAT_2300436c = uVar2;
      DAT_230043ec = uVar2;
      DAT_23004402 = uVar2;
      DAT_23004438 = DAT_230034b4;
      DAT_230052f0 = uVar2;
      DAT_23005370 = uVar2;
      DAT_23005386 = uVar2;
      DAT_230053bc = DAT_230034b4;
      FUN_23021eb8();
      FUN_230221c0(0);
      FUN_230221c0(1);
      cVar1 = DAT_23003251;
      param_2 = extraout_r1_01;
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021d38. Types and names are inferred; NOT original source. */

void FUN_23021d38(void)

{
  uint uVar1;
  undefined4 in_r3;
  undefined4 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  thunk_FUN_0e06f3aa(&DAT_230033e8,0,0x2e8c,in_r3,in_r3);
  thunk_FUN_0e06f3aa(&DAT_23003230,0,0x1b8);
  thunk_FUN_0e06f3aa(&DAT_230030a8,0,0x188);
  puVar2 = &DAT_2300349f;
  do {
    uVar1 = uVar3 & 0xffff;
    *(undefined4 *)((int)puVar2 + -0xb7) = 0;
    *(undefined4 *)((int)puVar2 + -0x37) = 0;
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0xffffffff;
    uVar3 = uVar3 + 1;
    FUN_2302083c(uVar1);
    puVar2 = puVar2 + 0x3e1;
  } while (uVar3 != 3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021d9c. Types and names are inferred; NOT original source. */

void ram_candidate_23021d9c(void)

{
  FUN_23021f88(0);
  DAT_23003230 = 5;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021db0. Types and names are inferred; NOT original source. */

void ram_candidate_23021db0(void)

{
  DAT_23003230 = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021dbc. Types and names are inferred; NOT original source. */

void FUN_23021dbc(int param_1)

{
  dword dVar1;
  int iVar2;
  undefined2 uVar3;
  
  DAT_23003234 = DAT_23003236;
  if (DAT_23003236 == 4) {
    FUN_23020dd4();
    iVar2 = param_1 * 0xf84;
    (&DAT_230033e8)[param_1 * 0x3e1] = 3;
    DAT_23005370 = 0xd;
    (&DAT_23003474)[param_1 * 0x3e1] = 0;
    (&DAT_23003468)[param_1 * 0x3e1] = 0xb;
    *(undefined4 *)(&DAT_2300346e + param_1 * 0x7c2) = 0;
    *(undefined4 *)(&DAT_23003478 + iVar2) = 0;
    (&DAT_2300346d)[iVar2] = 1;
    (&DAT_23003483)[iVar2] = 0xff;
    RADIO_S_SHORTS = 0;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 1;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 0x10;
    RADIO_S_INTENCLR00 = 0xffffffff;
    RADIO_S_INTENSET00 = 0x144;
    FUN_23020e84(4);
    TIMER020_S_CC_1 = 0;
    TIMER020_S_CC_2 = 0x33e0;
    DAT_230032d0 = 5;
    TIMER020_S_EVENTS_COMPARE_1 = 0;
    TIMER020_S_EVENTS_COMPARE_2 = 0;
    TIMER020_S_EVENTS_COMPARE_3 = 0;
    return;
  }
  if (DAT_23003236 != 1) {
    if (DAT_23003236 != 2) {
      return;
    }
    iVar2 = param_1 * 0xf84;
    (&DAT_230033e8)[param_1 * 0x3e1] = 3;
    DAT_23005370 = 0xd;
    (&DAT_23003474)[param_1 * 0x3e1] = 0;
    (&DAT_23003468)[param_1 * 0x3e1] = 0xb;
    *(undefined4 *)(&DAT_2300346e + param_1 * 0x7c2) = 0;
    *(undefined4 *)(&DAT_23003478 + iVar2) = 0;
    (&DAT_2300346d)[iVar2] = 1;
    (&DAT_23003483)[iVar2] = 0xff;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 0x10;
    RADIO_S_INTENCLR00 = 0xffffffff;
    RADIO_S_INTENSET00 = 0x100;
    FUN_23020e84(2);
    return;
  }
  FUN_23020dd4();
  uVar3 = 3;
  iVar2 = param_1 * 0xf84;
  (&DAT_230033e8)[param_1 * 0x3e1] = 3;
  DAT_23005370 = 0xd;
  (&DAT_23003474)[param_1 * 0x3e1] = 0;
  (&DAT_23003468)[param_1 * 0x3e1] = 0xb;
  *(undefined4 *)(&DAT_2300346e + param_1 * 0x7c2) = 0;
  *(undefined4 *)(&DAT_23003478 + iVar2) = 0;
  (&DAT_2300346d)[iVar2] = 1;
  (&DAT_23003483)[iVar2] = 0xff;
  RADIO_S_SHORTS = 0;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 1;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x10;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_INTENSET00 = 0x148;
  FUN_23020e84(2);
  if ((&DAT_2300341c)[param_1 * 0x7c2] == 1) {
    uVar3 = 4;
  }
  TIMER020_S_CC_1 = 0;
  TIMER020_S_CC_2 = 0x3160;
  TIMER020_S_CC_3 = 0;
  DAT_230032d0 = uVar3;
  TIMER020_S_EVENTS_COMPARE_1 = 0;
  TIMER020_S_EVENTS_COMPARE_2 = 0;
  TIMER020_S_EVENTS_COMPARE_3 = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021dfc. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23021dfc(int param_1)

{
  dword dVar1;
  
  DAT_23003234 = 2;
  RADIO_S_SHORTS = 0;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 | 0x80001;
  RADIO_S_INTENCLR00 = 0xffffffff;
  RADIO_S_INTENSET00 = 0x100;
  FUN_23020e84(2);
  FUN_23020d5c();
  if ((DAT_23003468 < 0xb) && (DAT_230043ec < 0xb)) {
    _DAT_23005349 = 0;
    DAT_23005380 = 0;
    DAT_23005370 = 0xb;
  }
  (&DAT_2300353c)[param_1 * 0xf84] = 0;
  (&DAT_23003542)[param_1 * 0xf84] = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021e74. Types and names are inferred; NOT original source. */

void FUN_23021e74(void)

{
  thunk_FUN_0e06d8f8(&DAT_23001fc0,&DAT_2300fa00,0x200,0x23021c3d,0,0,0,0xe,0);
  FUN_0e05d634("falcon8_core_thread created\n");
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021eb8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23021eb8(void)

{
  FUN_23022d18();
  FUN_23020e50();
  FUN_23020b1c();
  if (DAT_2300323a == 1) {
    DAT_2300325a._0_1_ = 1;
    return;
  }
  thunk_FUN_0e0612c8(0x28);
  _DAT_e000e284 = 0x100;
  TIMER020_S_TASKS_CLEAR = 1;
  TIMER020_S_TASKS_START = 1;
  thunk_FUN_0e0612ac(0x28);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021f04. Types and names are inferred; NOT original source. */

void FUN_23021f04(void)

{
  FUN_23020a94();
  thunk_FUN_0e0612c8(0x28);
  DAT_230052f0 = 0;
  TIMER020_S_TASKS_STOP = 1;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_STOP = 0;
  DAT_23003230 = 0;
  RADIO_S_TASKS_DISABLE = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23021f88. Types and names are inferred; NOT original source. */

void FUN_23021f88(void)

{
  thunk_FUN_0e06dd90(&DAT_23001fc0);
  DAT_23003232 = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  DAT_23003252 = 0;
  FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_DISABLE,0);
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  RADIO_S_SUBSCRIBE_RXEN = 0;
  RADIO_S_SUBSCRIBE_DISABLE = 0;
  RADIO_S_SUBSCRIBE_TXEN = 0;
  FUN_23020f1c(&DAT_230043ec,&RADIO_S_TASKS_DISABLE,0);
  FUN_23021f04();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022008. Types and names are inferred; NOT original source. */

void FUN_23022008(void)

{
  undefined1 auStack_34 [4];
  undefined4 local_30;
  undefined4 local_14;
  
  local_30 = DAT_23003244;
  local_14 = 4;
  DAT_23003232 = 1;
  FUN_23020c44(auStack_34);
  DAT_23003259 = 1;
  DAT_23003250 = DAT_2300323a == 1;
  DAT_23003258 = !(bool)DAT_23003250;
  DAT_23003252._1_1_ = 1;
  DAT_230033ec = 0;
  DAT_23004370 = 0;
  thunk_FUN_0e06ddc4(&DAT_23001fc0);
  thunk_FUN_0e06d0d0(&DAT_23001c54);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302206c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302206c(uint *param_1)

{
  dword dVar1;
  undefined1 auStack_44 [4];
  uint local_40;
  
  _DAT_5300e040 = 1;
  _DAT_5301e040 = 1;
  _DAT_5302e040 = 1;
  FUN_23021d38();
  FUN_23020b1c();
  FUN_23020a30();
  DAT_23003244 = *param_1;
  DAT_23003238 = (undefined2)param_1[1];
  DAT_2300324c = ~*param_1;
  FUN_23020a2c();
  local_40 = DAT_23003244;
  FUN_23020c44(auStack_44);
  DAT_23003234 = 2;
  DAT_2300323e = 3;
  FUN_230211c8(0);
  FUN_23021114(&DAT_230030d9);
  FUN_23021700();
  FUN_230215c4();
  thunk_FUN_0e0612c8(0x28);
  TIMER020_S_TASKS_STOP = 1;
  TIMER020_S_TASKS_CLEAR = 1;
  TIMER020_S_PRESCALER = 0;
  dVar1 = TIMER020_S_MODE;
  TIMER020_S_MODE = dVar1 & 0xfffffffc;
  dVar1 = TIMER020_S_BITMODE;
  TIMER020_S_BITMODE = dVar1 & 0xfffffffc | 2;
  TIMER020_S_CC_0 = 0;
  TIMER020_S_CC_1 = 0;
  TIMER020_S_CC_2 = 0;
  TIMER020_S_CC_3 = 0;
  TIMER020_S_CC_4 = 0;
  TIMER020_S_CC_5 = 0;
  TIMER020_S_CC_6 = 0;
  TIMER020_S_CC_7 = 0;
  TIMER020_S_INTENCLR = 0xff0000;
  thunk_FUN_0e0612f0(0x28,1,0);
  DAT_e000e428 = 0x20;
  _DAT_e000e284 = 0x100;
  thunk_FUN_0e0612ac(0x28);
  thunk_FUN_0e0612f0(0x5c,1,0);
  DAT_e000e45c = 0x60;
  _DAT_e000e288 = 0x10000000;
  thunk_FUN_0e0612ac(0x5c);
  thunk_FUN_0e0612f0(0x5b,1,0);
  DAT_e000e45b = 0x60;
  _DAT_e000e288 = 0x8000000;
  thunk_FUN_0e0612ac(0x5b);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230221a4. Types and names are inferred; NOT original source. */

void FUN_230221a4(int param_1)

{
  (&DAT_230033ec)[param_1 * 0xf84] = 1;
  thunk_FUN_0e06d0d0(&DAT_23001c54);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230221c0. Types and names are inferred; NOT original source. */

void FUN_230221c0(int param_1)

{
  (&DAT_230033e8)[param_1 * 0x3e1] = 2;
  (&DAT_230034b0)[param_1 * 0x7c2] = 0;
  (&DAT_23003468)[param_1 * 0x3e1] = 7;
  DAT_23003234 = 2;
  (&DAT_230034b4)[param_1 * 0x7c2] = 0x14;
  FUN_23020e84(2);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230221f8. Types and names are inferred; NOT original source. */

void FUN_230221f8(undefined2 param_1)

{
  DAT_2300323a = param_1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022204. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23022204(void)

{
  dword dVar1;
  byte bVar2;
  uint uVar3;
  
  bVar2 = DAT_23003256;
  if (DAT_23003230 != 5) {
    if (DAT_23003250 != '\0') {
      DAT_23003250 = 0;
      DAT_23003256 = 1;
      thunk_FUN_0e06d0d0(&DAT_23001c54);
      return;
    }
    uVar3 = (uint)DAT_23003256;
    if (uVar3 == 0) {
      if (DAT_23003258 != '\0') {
        if ((char)DAT_2300325a != '\0') {
          thunk_FUN_0e0612c8(0x28);
          _DAT_e000e284 = 0x100;
          TIMER020_S_TASKS_CLEAR = 1;
          TIMER020_S_TASKS_START = 1;
          thunk_FUN_0e0612ac(0x28);
          _DAT_2300325a = CONCAT12(bVar2,0x100);
          DAT_23003264 = uVar3;
          return;
        }
        if (DAT_2300325a._1_1_ == '\0') {
          if (DAT_2300325c != '\0') {
            dVar1 = TIMER020_S_CC_7;
            if (dVar1 - 0x6e1 < 0x63f) {
              DAT_23003278 = DAT_23003278 + 1;
              DAT_23003270 = DAT_23003270 + dVar1;
            }
            if (0x1f < DAT_23003278) {
              uVar3 = DAT_23003270 >> 5;
              if (uVar3 < 0xa01) {
                if ((uVar3 != 0xa00) && (0x1f < 0xa00 - uVar3)) {
                  dVar1 = TIMER020_S_CC_0;
                  TIMER020_S_CC_0 = dVar1 - 0x20;
                }
              }
              else if (0x1f < uVar3 - 0xa00) {
                dVar1 = TIMER020_S_CC_0;
                TIMER020_S_CC_0 = dVar1 + 0x20;
              }
              DAT_23003270 = 0;
              DAT_23003278 = 0;
              return;
            }
          }
        }
        else {
          DAT_23003264 = DAT_23003264 + 1;
          if (0x20 < (int)DAT_23003264) {
            _DAT_2300325a = 0x10000;
            return;
          }
        }
      }
    }
    else {
      DAT_23003264 = DAT_23003264 + 1;
      if (0x40 < (int)DAT_23003264) {
        DAT_23003256 = DAT_23003250;
        DAT_23003258 = 1;
        thunk_FUN_0e06d0d0(&DAT_23001c54);
        return;
      }
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022300. Types and names are inferred; NOT original source. */

void ram_candidate_23022300(void)

{
  dword dVar1;
  uint in_r3;
  int unaff_r4;
  
  if (0x1f < in_r3) {
    dVar1 = TIMER020_S_CC_0;
    TIMER020_S_CC_0 = dVar1 - 0x20;
  }
  *(undefined4 *)(unaff_r4 + 0x40) = 0;
  *(undefined4 *)(unaff_r4 + 0x48) = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022328. Types and names are inferred; NOT original source. */

void ram_candidate_23022328(void)

{
  byte bVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  char cVar12;
  char *pcVar13;
  byte *pbVar11;
  
  uVar7 = (uint)DAT_230071a2;
  if (DAT_230071a0 == 0) {
    iVar6 = uVar7 * 0xf84;
    if ((&DAT_23003450)[iVar6] == '\0') {
      if ((&DAT_2300344e)[iVar6] == '\0') {
        (&DAT_2300344e)[iVar6] = (&DAT_23003451)[iVar6];
      }
      iVar6 = uVar7 * 0xf84;
      if ((&DAT_2300344f)[iVar6] == '\0') {
        (&DAT_2300344f)[iVar6] = (&DAT_23003451)[iVar6];
      }
      iVar6 = uVar7 * 0xf84;
      bVar1 = (&DAT_23003451)[iVar6];
      if (bVar1 != 0) {
        if (bVar1 < (byte)(&DAT_2300344e)[iVar6]) {
          (&DAT_2300344e)[iVar6] = bVar1;
        }
        else if ((byte)(&DAT_2300344f)[iVar6] < bVar1) {
          (&DAT_2300344f)[iVar6] = bVar1;
        }
      }
      iVar6 = uVar7 * 0xf84;
      sVar2 = *(short *)(&DAT_23003456 + iVar6);
      *(ushort *)(&DAT_23003456 + iVar6) = sVar2 + 1U;
      if (0x1f < (ushort)(sVar2 + 1U)) {
        *(undefined2 *)(&DAT_23003456 + iVar6) = 0;
        (&DAT_2300344d)[iVar6] = (&DAT_2300344e)[iVar6];
        *(undefined2 *)(&DAT_2300344e + iVar6) = 0xff;
      }
      return;
    }
    bVar1 = (&DAT_23003452)[iVar6];
    if (((&DAT_2300315c)[bVar1] == 0) ||
       ((byte)(&DAT_23003451)[iVar6] < (byte)(&DAT_2300315c)[bVar1])) {
      (&DAT_2300315c)[bVar1] = (&DAT_23003451)[iVar6];
    }
    (&DAT_23003181)[bVar1] = (&DAT_23003181)[bVar1] + '\x01';
    return;
  }
  if (DAT_230071a0 != 1) {
    return;
  }
  bVar3 = true;
  if (DAT_230031f6 == 0) {
    bVar4 = false;
  }
  else {
    bVar4 = false;
    pbVar9 = (byte *)((int)&DAT_230031aa + 1);
    do {
      pbVar9 = pbVar9 + 1;
      if (10 < *(ushort *)(&DAT_23003332 + (uint)*pbVar9 * 2)) {
        if (0xd < *(ushort *)(&DAT_23003332 + (uint)*pbVar9 * 2)) {
          bVar4 = true;
        }
        bVar3 = false;
      }
    } while (pbVar9 != (byte *)((int)&DAT_230031aa + DAT_230031f6 + 1));
  }
  cVar12 = '\0';
  uVar7 = 0xff;
  pbVar9 = &DAT_230003e0;
  pcVar13 = &DAT_230003dc;
  do {
    uVar8 = (uint)pbVar9[1];
    if (uVar8 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0;
      pbVar11 = &DAT_230003e8 + *pbVar9;
      do {
        pbVar10 = pbVar11 + 1;
        uVar5 = uVar5 + (byte)(&DAT_2300315c)[*pbVar11];
        pbVar11 = pbVar10;
      } while (&DAT_230003e8 + uVar8 + *pbVar9 != pbVar10);
    }
    pbVar9 = pbVar9 + 2;
    if (uVar5 / uVar8 < uVar7) {
      cVar12 = *pcVar13;
      uVar7 = uVar5 / uVar8;
    }
    pcVar13 = pcVar13 + 1;
  } while (pbVar9 != &DAT_230003e8);
  uVar8 = (uint)DAT_2300344d;
  if (cVar12 == 'B') {
    if (((uVar8 != 0) && (DAT_230031f7 != '\0')) && ((uint)DAT_230031f9 <= uVar7 + 0xc)) {
      cVar12 = '\x06';
      goto LAB_23021a2e;
    }
    bVar3 = false;
    cVar12 = '\x06';
LAB_23021974:
    if (DAT_230031fa != '\0') goto LAB_23021950;
    FUN_230211c8(cVar12);
  }
  else {
    if (((uVar8 == 0) || (DAT_230031f7 == '\0')) || (uVar7 + 0xc < (uint)DAT_230031f9)) {
LAB_2302193c:
      if (cVar12 != '\0') {
LAB_23021a6c:
        bVar3 = false;
        goto LAB_23021974;
      }
    }
    else {
LAB_23021a2e:
      if (!bVar3) {
        if (DAT_230033e0 == 1) {
          if ((7 < DAT_2300341c) && (bVar4)) goto LAB_2302193c;
          if (DAT_230033e2 < 5) {
            DAT_230033e2 = DAT_230033e2 + 1;
          }
        }
        else if (DAT_230033e2 == 0) {
          if (DAT_230031f7 == cVar12) {
            if (DAT_230031f8 < 2) {
              DAT_230031f8 = DAT_230031f8 + 1;
            }
            goto LAB_23021a6c;
          }
          if (uVar7 <= uVar8 + 0x23) {
            if (DAT_230031f8 != 0) {
              DAT_230031f8 = DAT_230031f8 - 1;
              bVar3 = true;
              cVar12 = DAT_230031f7;
              goto LAB_23021974;
            }
            goto LAB_2302193c;
          }
        }
        else {
          DAT_230033e2 = DAT_230033e2 - 1;
        }
      }
    }
    if (DAT_230031fa == '\0') goto LAB_230219ca;
    bVar3 = false;
    cVar12 = '\0';
LAB_23021950:
    DAT_230031f6 = DAT_230031fb;
    thunk_FUN_0e06f35c(&DAT_230031ac);
  }
  iVar6 = FUN_23021114(&DAT_230030de);
  iVar6 = thunk_FUN_0e06f3ba(iVar6 + -5,iVar6,5);
  if (iVar6 != 0) {
    if (DAT_230033e8 == 3) {
      DAT_230033d6 = DAT_23005376 + 100;
    }
    else {
      DAT_230033d6 = DAT_23005376 + 0xfa;
    }
    DAT_2300325d = 1;
    FUN_230214bc();
  }
  if (!bVar3) {
    DAT_230031f9 = (byte)uVar7;
    DAT_230031f8 = 1;
    DAT_230031f7 = cVar12;
  }
LAB_230219ca:
  thunk_FUN_0e06f3aa(&DAT_2300315c,0,0x25);
  thunk_FUN_0e06f3aa(&DAT_23003181,0,0x25);
  DAT_230033c6 = 0;
  thunk_FUN_0e06f3aa(&DAT_230032e8,0,0x4a);
  thunk_FUN_0e06f3aa(&DAT_23003332,0,0x4a);
  thunk_FUN_0e06f3aa(&DAT_2300337c,0,0x4a,&DAT_230071a2);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302233c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302233c(undefined2 param_1,undefined2 param_2)

{
  DAT_230071a2 = param_1;
  DAT_230071a0 = param_2;
  _DAT_e000e208 = 0x8000000;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022360. Types and names are inferred; NOT original source. */

void FUN_23022360(uint param_1)

{
  byte bVar1;
  uint uVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = param_1 * 0xf84;
  (&DAT_230034bc)[iVar5] = 0xb;
  uVar3 = FUN_23020978(0,param_1 & 0xff);
  (&DAT_230034bd)[iVar5] = uVar3;
  uVar3 = FUN_230209dc(0,(&DAT_2300348f)[iVar5]);
  (&DAT_230034be)[iVar5] = uVar3;
  uVar2 = DAT_23003244;
  (&DAT_230034bf)[iVar5] = 0x11;
  *(uint *)(&DAT_230034c0 + iVar5) =
       uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18;
  bVar1 = (byte)DAT_23003238;
  (&DAT_230034c5)[iVar5] = 0;
  (&DAT_230034c4)[iVar5] =
       bVar1 & 0xf | (&DAT_2300346d)[iVar5] << 7 |
       (byte)(*(short *)(&DAT_23003402 + iVar5) << 6) & 0x40;
  (&DAT_230034c6)[iVar5] = (char)((ushort)DAT_23005376 >> 8);
  (&DAT_230034c7)[iVar5] = (char)DAT_23005376;
  cVar4 = (&DAT_2300348f)[iVar5] + '\x01';
  if (cVar4 == '\b') {
    cVar4 = '\x01';
  }
  (&DAT_2300348f)[iVar5] = cVar4;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230223f0. Types and names are inferred; NOT original source. */

undefined4 FUN_230223f0(uint param_1,char *param_2)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  short sVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  int iVar8;
  undefined4 uVar9;
  char cVar10;
  uint uVar11;
  int iVar12;
  undefined2 uVar13;
  undefined2 local_34;
  undefined2 local_32;
  undefined4 local_30;
  undefined2 local_2c;
  undefined2 local_2a;
  
  iVar12 = param_1 * 0xf84;
  uVar13 = (&DAT_230034b0)[param_1 * 0x7c2];
  iVar8 = FUN_23020988(param_2[1]);
  uVar11 = DAT_230033e8;
  if (iVar8 == 0) {
    sVar5 = (&DAT_230034b0)[param_1 * 0x7c2];
    if (sVar5 == 2) {
      if ((param_2[3] == '\x14') && (*param_2 == '\v')) {
        (&DAT_2300341c)[param_1 * 0x7c2] = (ushort)(byte)param_2[4];
        (&DAT_230034bc)[iVar12] = 0xb;
        uVar7 = FUN_23020978(0,param_1 & 0xff,0);
        (&DAT_230034bd)[iVar12] = uVar7;
        uVar7 = FUN_230209dc(0,(&DAT_2300348f)[iVar12]);
        (&DAT_230034be)[iVar12] = uVar7;
        sVar5 = DAT_2300323e;
        (&DAT_230034bf)[iVar12] = 0x15;
        uVar6 = DAT_2300534f;
        uVar9 = DAT_23003158;
        uVar7 = DAT_230030dd;
        if ((sVar5 == 0) || (sVar5 == 1)) {
          *(undefined4 *)(&DAT_230034c0 + iVar12) = DAT_2300534b;
          *(undefined4 *)(&DAT_230034c4 + iVar12) = uVar6;
        }
        else if (sVar5 == 2) {
          *(undefined4 *)(&DAT_230034c0 + iVar12) = DAT_230030d9;
          (&DAT_230034c4)[iVar12] = uVar7;
          (&DAT_230034c5)[iVar12] = (char)uVar9;
        }
        else if (sVar5 == 3) {
          *(undefined4 *)(&DAT_230034c0 + iVar12) = DAT_230030d9;
          (&DAT_230034c4)[iVar12] = uVar7;
        }
        uVar9 = 1;
        cVar10 = (&DAT_2300348f)[param_1 * 0xf84] + '\x01';
        if (cVar10 == '\b') {
          cVar10 = '\x01';
        }
        (&DAT_2300348f)[param_1 * 0xf84] = cVar10;
        uVar13 = 3;
        *(undefined4 *)(&DAT_230034b4 + param_1 * 0x7c2) = 0x40000;
        goto LAB_23022416;
      }
    }
    else if (sVar5 == 3) {
      if ((param_2[3] == '\x16') && (*param_2 == '\v')) {
        if ((&DAT_230033fc)[param_1 * 0x3e1] != 0) {
          local_32 = 1;
          local_30 = DAT_23003244;
          local_2c = CONCAT11((&DAT_230033ee)[iVar12],(&DAT_230033ef)[iVar12]);
          local_34 = (undefined2)param_1;
          local_2a = CONCAT11((&DAT_230033f0)[iVar12],(&DAT_230033f1)[iVar12]);
          FUN_23025580(&local_34);
          (&DAT_230033fc)[param_1 * 0x3e1] = 0;
          iVar8 = DAT_230033fc;
          *(undefined2 *)(&DAT_23003402 + iVar12) = 0;
          if (iVar8 == 0 && DAT_23004380 == 0) {
            FUN_23020bd4(0xff);
          }
        }
        uVar9 = 2;
        uVar13 = 6;
        *(undefined4 *)(&DAT_230034b4 + param_1 * 0x7c2) = 0;
        goto LAB_23022416;
      }
    }
    else if ((((sVar5 == 0) && (param_2[3] == '\x12')) && (*param_2 == '\v')) &&
            ((((&DAT_230033fc)[param_1 * 0x3e1] == 0 || (*(short *)(&DAT_230033ee + iVar12) == -1))
             || ((param_2[6] == (&DAT_230033ee)[iVar12] && (param_2[7] == (&DAT_230033ef)[iVar12])))
             ))) {
      (&DAT_2300346c)[param_1 * 0xf84] = (byte)param_2[4] >> 7;
      bVar1 = (byte)DAT_23003234;
      if ((uVar11 < 3) && (DAT_2300436c < 3)) {
        bVar1 = (byte)DAT_23003238;
      }
      uVar11 = (uint)(param_2[4] & bVar1);
      if ((param_2[4] & bVar1 & 0xf) != 0) {
        iVar8 = param_1 * 0xf84;
        cVar10 = param_2[6];
        (&DAT_230033ee)[iVar8] = cVar10;
        cVar2 = param_2[7];
        (&DAT_230033ef)[iVar8] = cVar2;
        cVar3 = param_2[8];
        (&DAT_230033f0)[iVar8] = cVar3;
        cVar4 = param_2[9];
        *(ushort *)(&DAT_230033f2 + param_1 * 0x3e1) = CONCAT11(cVar10,cVar2);
        *(ushort *)((int)&DAT_230033f2 + iVar8 + 2) = CONCAT11(cVar3,cVar4);
        (&DAT_230033f1)[iVar8] = cVar4;
        if ((int)(uVar11 << 0x1c) < 0) {
          DAT_23003236 = 8;
          uVar11 = 8;
        }
        else if ((int)(uVar11 << 0x1d) < 0) {
          uVar11 = 4;
          DAT_23003236 = 4;
        }
        else {
          uVar11 = 2 - (uVar11 & 1) & 0xff;
          DAT_23003236 = (undefined2)uVar11;
        }
        iVar8 = param_1 * 0xf84;
        (&DAT_230034bc)[iVar8] = 0xb;
        uVar7 = FUN_23020978(0,param_1 & 0xff);
        (&DAT_230034bd)[iVar8] = uVar7;
        uVar7 = FUN_230209dc(0,(&DAT_2300348f)[iVar8]);
        sVar5 = DAT_2300323e;
        (&DAT_230034be)[iVar8] = uVar7;
        (&DAT_230034bf)[iVar8] = 0x13;
        (&DAT_230034c1)[iVar8] = 0;
        (&DAT_230034c0)[iVar8] = (byte)uVar11 | ((byte)sVar5 & 3) << 4;
        (&DAT_230034c2)[iVar8] = DAT_23005349 & 0xf | DAT_2300534a << 4;
        cVar10 = (&DAT_2300348f)[iVar8] + '\x01';
        if (cVar10 == '\b') {
          cVar10 = '\x01';
        }
        (&DAT_2300348f)[iVar8] = cVar10;
        uVar13 = 2;
        *(undefined4 *)(&DAT_230034b4 + param_1 * 0x7c2) = 0x40000;
        uVar9 = 1;
        goto LAB_23022416;
      }
    }
  }
  uVar9 = 0;
LAB_23022416:
  (&DAT_230034b0)[param_1 * 0x7c2] = uVar13;
  return uVar9;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230226c8. Types and names are inferred; NOT original source. */

void FUN_230226c8(int param_1)

{
  dword dVar1;
  undefined4 uVar2;
  byte *pbVar3;
  
  if ((uint)(&DAT_230033e8)[param_1 * 0x3e1] < 2) {
    if ((DAT_23005376 & 0x80) == 0) {
      uVar2 = 0x27;
    }
    else {
      uVar2 = 0x25;
    }
    dVar1 = FUN_230216b0(uVar2);
    RADIO_S_FREQUENCY = dVar1;
    RADIO_S_BASE1 = DAT_23003240;
    FUN_23020f3c(7);
    if (param_1 == 0) {
      pbVar3 = &DAT_230071c6;
    }
    else {
      pbVar3 = &DAT_230071c4;
    }
    RADIO_S_SUBSCRIBE_RXEN = *pbVar3 | 0x80000000;
    RADIO_S_SUBSCRIBE_DISABLE = DAT_230071c5 | 0x80000000;
    RADIO_S_PACKETPTR = (dword)(&DAT_230034bc + param_1 * 0xf84);
    (&DAT_230034b0)[param_1 * 0x7c2] = 0;
    return;
  }
  if ((&DAT_230033e8)[param_1 * 0x3e1] != 2) {
    RADIO_S_FREQUENCY = (uint)DAT_23003222;
    RADIO_S_BASE1 = DAT_23003244;
    FUN_23020f84(2);
    FUN_23020f3c(2);
    if (param_1 == 0) {
      pbVar3 = &DAT_230071c6;
    }
    else {
      if (param_1 != 1) {
        if (DAT_23005370 != 0xd) {
          return;
        }
        RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
        return;
      }
      pbVar3 = &DAT_230071c4;
    }
    RADIO_S_SUBSCRIBE_RXEN = *pbVar3 | 0x80000000;
    RADIO_S_SUBSCRIBE_DISABLE = DAT_230071c5 | 0x80000000;
    return;
  }
  RADIO_S_BASE1 = DAT_23003244;
  dVar1 = FUN_230216b0((&DAT_0e06fbac)[(ushort)(&DAT_230034b2)[param_1 * 0x7c2]]);
  RADIO_S_FREQUENCY = dVar1;
  RADIO_S_PACKETPTR = (dword)(&DAT_230034bc + param_1 * 0xf84);
  if (-1 < (int)((uint)DAT_23005376 << 0x1f)) {
    if (param_1 == 0) {
      RADIO_S_SUBSCRIBE_TXEN = DAT_230071c6 | 0x80000000;
    }
    else if (param_1 == 1) {
      RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
    }
    if (((&DAT_230033fc)[param_1 * 0x3e1] == 0) && (*(int *)(&DAT_23003410 + param_1 * 0xf84) == 0))
    {
      FUN_23020f84(param_1);
      return;
    }
    FUN_23020f84(0xff);
    return;
  }
  if (param_1 == 0) {
    pbVar3 = &DAT_230071c6;
  }
  else {
    if (param_1 != 1) goto LAB_23022768;
    pbVar3 = &DAT_230071c4;
  }
  RADIO_S_SUBSCRIBE_RXEN = *pbVar3 | 0x80000000;
  RADIO_S_SUBSCRIBE_DISABLE = DAT_230071c5 | 0x80000000;
LAB_23022768:
  FUN_23020f3c(param_1);
  if (((&DAT_230033fc)[param_1 * 0x3e1] != 0) || (*(int *)(&DAT_23003410 + param_1 * 0xf84) != 0)) {
    dVar1 = RADIO_S_RXADDRESSES;
    RADIO_S_RXADDRESSES = dVar1 | 1;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022888. Types and names are inferred; NOT original source. */

void FUN_23022888(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  char cVar5;
  ushort uVar6;
  ushort uVar7;
  
  switch((&DAT_23003468)[param_1 * 0x3e1]) {
  case 7:
    if (param_2 != 1) {
      return;
    }
    iVar4 = param_1 * 0xf84;
    RADIO_S_PACKETPTR = (dword)(&DAT_230034bc + iVar4);
    sVar1 = (&DAT_230034b6)[param_1 * 0x7c2];
    if ((sVar1 == 0) || ((&DAT_230034b6)[param_1 * 0x7c2] = sVar1 + -1, sVar1 != 1)) {
      if ((&DAT_230034b0)[param_1 * 0x7c2] == 0) goto LAB_2302291e;
    }
    else {
      (&DAT_230034b0)[param_1 * 0x7c2] = 0;
LAB_2302291e:
      iVar2 = param_1 * 0xf84;
      if ((DAT_23005376 & 1) == 0) {
        uVar6 = DAT_23005376 & 3;
        uVar7 = DAT_23005376 & 3;
        (&DAT_230034b4)[param_1 * 0x7c2] = (&DAT_230034b4)[param_1 * 0x7c2] + 1;
        if (uVar6 == 0) {
          if (*(int *)(&DAT_23003410 + iVar2) == 0) {
            if ((&DAT_230033fc)[param_1 * 0x3e1] == 0) goto LAB_230229c8;
            FUN_23022360(param_1);
          }
          else {
            (&DAT_230034bc)[iVar4] = 7;
            uVar3 = FUN_23020978(uVar7,param_1 & 0xff,1);
            (&DAT_230034bd)[iVar4] = uVar3;
            uVar3 = FUN_230209dc(uVar7,(&DAT_2300348f)[iVar2]);
            (&DAT_230034be)[iVar4] = uVar3;
            (&DAT_230034bf)[iVar4] = 0x24;
            cVar5 = (&DAT_2300348f)[iVar2] + '\x01';
            if (cVar5 == '\b') {
              cVar5 = '\x01';
            }
            (&DAT_2300348f)[iVar2] = cVar5;
          }
        }
        else {
LAB_230229c8:
          FUN_23022360(param_1);
        }
      }
      else if ((ushort)(&DAT_230034b4)[param_1 * 0x7c2] < 0x14) {
        thunk_FUN_0e06f3aa(&DAT_230034bc + iVar4,0,0x20);
      }
      else {
        uVar6 = (&DAT_230034b2)[param_1 * 0x7c2] + 1;
        if (3 < uVar6) {
          uVar6 = 0;
        }
        (&DAT_230034b2)[param_1 * 0x7c2] = uVar6;
        (&DAT_230034b4)[param_1 * 0x7c2] = 0;
        FUN_23020f1c(&DAT_23003468 + param_1 * 0x3e1,&RADIO_S_TASKS_DISABLE,7,uVar6,param_4);
        RADIO_S_SUBSCRIBE_DISABLE = 0;
        RADIO_S_SUBSCRIBE_DISABLE = 0;
      }
    }
    if ((DAT_23005376 & 1) == 0) {
      (&DAT_23003468)[param_1 * 0x3e1] = 8;
    }
    else {
      (&DAT_23003468)[param_1 * 0x3e1] = 9;
      (&DAT_230034bc)[param_1 * 0xf84] = 0;
    }
    break;
  case 8:
    if (param_2 == 1) {
      FUN_23020f1c(&DAT_23003468 + param_1 * 0x3e1,&RADIO_S_TASKS_DISABLE,7,0xf84,param_4);
      (&DAT_230034b0)[param_1 * 0x7c2] = 0;
    }
    break;
  case 9:
    if (param_2 == 2) {
      (&DAT_23003468)[param_1 * 0x3e1] = 7;
      (&DAT_230034b0)[param_1 * 0x7c2] = 0;
    }
    break;
  case 0xb:
    if (param_2 == 1) {
      RADIO_S_PACKETPTR = 0x23003050;
      DAT_23003050._0_1_ = 0;
      (&DAT_23003468)[param_1 * 0x3e1] = 0xc;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022d18. Types and names are inferred; NOT original source. */

void FUN_23022d18(void)

{
  TIMER020_S_CC_0 = 0x9240;
  DAT_23003234 = 2;
  DAT_230032d0 = 2;
  TIMER020_S_CC_1 = 0;
  TIMER020_S_CC_2 = 0x2580;
  TIMER020_S_CC_3 = 0;
  TIMER020_S_CC_4 = 0;
  TIMER020_S_CC_5 = 0;
  TIMER020_S_CC_6 = 0;
  TIMER020_S_CC_7 = 0;
  DAT_23003280 = 100;
  TIMER020_S_SHORTS = 1;
  TIMER020_S_INTENSET = 0x3f0000;
  DAT_23003230 = 3;
  DAT_230052f0 = 3;
  DAT_23005370 = 0xb;
  DAT_23003282 = 0xff;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23022e48. Types and names are inferred; NOT original source. */

void FUN_23022e48(uint param_1)

{
  undefined4 uVar1;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  if (2 < (uint)(&DAT_230033e8)[param_1 * 0x3e1]) {
    if (99 < (ushort)(&DAT_23003470)[param_1 * 0x7c2]) {
      FUN_23020f1c(&DAT_23003468 + param_1 * 0x3e1,&RADIO_S_TASKS_DISABLE,0);
      (&DAT_230033e8)[param_1 * 0x3e1] = 0;
      (&DAT_23003468)[param_1 * 0x3e1] = 0xb;
      FUN_23021dfc(param_1 & 0xff);
      FUN_230221a4(param_1 & 0xff);
      local_1c = *(undefined2 *)(&DAT_230033f2 + param_1 * 0x3e1);
      local_1a = *(undefined2 *)((int)&DAT_230033f2 + param_1 * 0xf84 + 2);
      local_20 = (undefined2)param_1;
      local_1e = 0;
      FUN_230254f8(&local_20);
      return;
    }
    if ((uint)(&DAT_23003474)[param_1 * 0x3e1] < 200) {
      uVar1 = 3;
    }
    else {
      uVar1 = 4;
    }
    (&DAT_230033e8)[param_1 * 0x3e1] = uVar1;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23023268. Types and names are inferred; NOT original source. */

void FUN_23023268(void)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_230032d0;
  if (DAT_2300341c == 1) {
    if (uVar1 == 0) {
      DAT_23006274 = uVar1;
      RADIO_S_SUBSCRIBE_RXEN = 0;
      return;
    }
    if ((uVar1 < 3) || (uVar1 == 3)) {
      return;
    }
    if (uVar1 != 4) {
      return;
    }
  }
  else if ((uVar1 == 0) || ((uVar1 != 1 && (uVar1 == 2)))) {
    DAT_23006274 = 0;
    RADIO_S_SUBSCRIBE_RXEN = 0;
    return;
  }
  RADIO_S_SUBSCRIBE_TXEN = 0;
  DAT_23006274 = 2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230232d0. Types and names are inferred; NOT original source. */

void FUN_230232d0(void)

{
  dword dVar1;
  
  if (DAT_2300341c != 1) {
    RADIO_S_FREQUENCY = (uint)DAT_23003222;
    RADIO_S_BASE1 = DAT_23003244;
    FUN_23020f84(2);
    FUN_23020f3c(2);
    if (DAT_230032d0 == 0) {
      RADIO_S_SUBSCRIBE_RXEN = DAT_230071c6 | 0x80000000;
      return;
    }
    if ((DAT_230032d0 != 1) && (DAT_230032d0 == 2)) {
      RADIO_S_SUBSCRIBE_RXEN = DAT_230071c4 | 0x80000000;
      return;
    }
    RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
    return;
  }
  if (DAT_230032d0 == 0) {
    RADIO_S_FREQUENCY = (uint)DAT_23003222;
    RADIO_S_BASE1 = DAT_23003244;
    FUN_23020f84(2);
    FUN_23020f3c(2);
    RADIO_S_SUBSCRIBE_RXEN = DAT_230071c6 | 0x80000000;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 0x20;
    return;
  }
  if (DAT_230032d0 != 4) {
    return;
  }
  RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
  dVar1 = RADIO_S_SHORTS;
  RADIO_S_SHORTS = dVar1 & 0xffffffdf;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230233b0. Types and names are inferred; NOT original source. */

void FUN_230233b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_23003468 == 0xb) {
    if (DAT_2300341c == 1) {
      if (param_1 != 4) {
        if (param_1 == 1) {
          DAT_23003468 = 0xc;
          FUN_23023268();
          return;
        }
        if (param_1 != 2) {
          return;
        }
        goto LAB_2302345a;
      }
LAB_2302343a:
      RADIO_S_PACKETPTR = 0x23003050;
      DAT_23003050._0_1_ = 0;
      DAT_23003468 = 0xc;
      return;
    }
    if (param_1 == 4) goto LAB_2302343a;
  }
  else {
    if (DAT_23003468 != 0xc) {
      return;
    }
    if (DAT_2300341c != 1) {
      if (param_1 != 1) {
        if (param_1 != 5) {
          return;
        }
        if ((byte)DAT_23003050 - 1 < 0xc) {
          return;
        }
        FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_STOP,0xb,(byte)DAT_23003050 - 1,param_4);
        if (DAT_230032d0 < 2) {
          DAT_2300348a = 1;
        }
        else {
          FUN_23023708(1);
        }
        return;
      }
      goto LAB_230233de;
    }
    if (param_1 == 2) {
LAB_2302345a:
      FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_STOP,0xb);
      return;
    }
    if (param_1 == 5) {
      if ((byte)DAT_23003050 - 1 < 0xc) {
        return;
      }
      FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_STOP,0xb);
      DAT_2300348a = 1;
      return;
    }
  }
  if (param_1 != 1) {
    return;
  }
LAB_230233de:
  FUN_23023268();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23023708. Types and names are inferred; NOT original source. */

void FUN_23023708(int param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  
  if ((param_1 != 0) && (DAT_2300348a == '\0')) {
    return;
  }
  if (DAT_230033e8 == 3) {
    uVar1 = (uint)DAT_2300341c;
    if (uVar1 < 9) {
      uVar1 = -0x117 >> (uVar1 & 0xff);
    }
    else {
      if (uVar1 != 0x10) {
        if (uVar1 == 0x20) {
          uVar4 = DAT_2300346e & 3;
        }
        else {
          if (uVar1 != 0x40) {
            DAT_2300348a = 0;
            return;
          }
          uVar4 = DAT_2300346e & 7;
        }
        goto joined_r0x230237c0;
      }
      uVar1 = (uint)DAT_2300346e;
    }
    if (-1 < (int)(uVar1 << 0x1f)) goto LAB_23023748;
  }
  else {
    if (DAT_230033e8 != 4) {
      DAT_2300348a = 0;
      return;
    }
    uVar4 = DAT_23005376 & 0x1d;
joined_r0x230237c0:
    if (uVar4 == 0) {
LAB_23023748:
      uVar1 = (uint)DAT_230032ca;
      iVar2 = uVar1 + 0x48;
      uVar4 = *(short *)((int)&DAT_230033e8 + iVar2 * 2) + 1;
      *(ushort *)((int)&DAT_230033e8 + iVar2 * 2) = uVar4;
      if (3 < uVar4) {
        if (DAT_23005384 == '\0') {
          cVar3 = (&DAT_23005349)[uVar1] + '\x01';
          if (DAT_23005353 == cVar3) {
            cVar3 = '\0';
          }
          (&DAT_23005349)[uVar1] = cVar3;
          iVar2 = DAT_230032ca + 0x48;
        }
        *(undefined2 *)((int)&DAT_230033e8 + iVar2 * 2) = 0;
        DAT_2300348a = 0;
        return;
      }
      DAT_2300348a = 0;
      return;
    }
  }
  DAT_2300348a = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230237e0. Types and names are inferred; NOT original source. */

undefined4 FUN_230237e0(void)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  do {
    puVar2 = (undefined4 *)FUN_230207ec(0,uVar3 & 0xffff);
    uVar4 = uVar3 + 1;
    if (puVar2 != (undefined4 *)0x0) {
      DAT_2300347e._0_2_ = (undefined2)uVar3;
      DAT_23003488 = 1;
      goto LAB_23023852;
    }
    uVar3 = uVar4;
  } while (uVar4 != 6);
  DAT_230053e4 = 5;
  DAT_230053e6 = FUN_230209dc(0,DAT_23005397);
  DAT_23005397 = DAT_23005397 + '\x01';
  DAT_230053e8._0_1_ = DAT_23005349 & 0xf | DAT_2300534a << 4;
  DAT_230053e7 = 0x1f;
  if (DAT_23005397 == '\b') {
    puVar2 = (undefined4 *)&DAT_230053e4;
    DAT_23005397 = '\x01';
  }
  else {
    puVar2 = (undefined4 *)&DAT_230053e4;
  }
LAB_23023852:
  uVar1 = FUN_230209bc(1,DAT_23003488,
                       *(undefined1 *)((int)&DAT_230033e8 + (DAT_230032ca + 0xfcc) * 2));
  *(undefined1 *)((int)puVar2 + 1) = uVar1;
  DAT_23003070 = *puVar2;
  DAT_23003074 = puVar2[1];
  DAT_23003078 = puVar2[2];
  DAT_2300307c = puVar2[3];
  RADIO_S_PACKETPTR = 0x23003070;
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23023b5c. Types and names are inferred; NOT original source. */

void FUN_23023b5c(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (2 < (uint)(&DAT_230033e8)[param_1 * 0x3e1]) {
    uVar1 = (&DAT_23003474)[param_1 * 0x3e1];
    uVar2 = uVar1;
    if (uVar1 < 200) {
      uVar2 = uVar1 + 1;
    }
    (&DAT_2300346e)[param_1 * 0x7c2] = (&DAT_2300346e)[param_1 * 0x7c2] + 1;
    (&DAT_23003470)[param_1 * 0x7c2] = (&DAT_23003470)[param_1 * 0x7c2] + 1;
    if (uVar1 < 200) {
      (&DAT_23003474)[param_1 * 0x3e1] = uVar2;
    }
  }
  if (param_1 != 2) {
    return;
  }
  DAT_230032ca = (ushort)(((uint)DAT_23005376 << 0x1e) >> 0x1f);
  DAT_23003222 = FUN_23021654();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23023fa4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23023fa4(void)

{
  dword dVar1;
  
  if (DAT_230032d0 == 0) {
    DAT_2300322c = DAT_23003224;
    _DAT_23003222 = _DAT_23003226;
    RADIO_S_FREQUENCY = _DAT_23003226 & 0xffff;
    RADIO_S_BASE1 = DAT_23003244;
    FUN_23020f84(2);
    FUN_23020f3c(2);
    RADIO_S_SUBSCRIBE_RXEN = DAT_230071c6 | 0x80000000;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 & 0xfff7ffff;
    dVar1 = RADIO_S_SHORTS;
    RADIO_S_SHORTS = dVar1 | 0x20;
  }
  else {
    switch(DAT_230032d0) {
    case 1:
    case 4:
      RADIO_S_SUBSCRIBE_STOP = DAT_230071c2 | 0x80000000;
      return;
    case 2:
    case 5:
      if (DAT_23003484 == '\x01') {
        RADIO_S_SUBSCRIBE_TXEN = DAT_230071c4 | 0x80000000;
        dVar1 = RADIO_S_SHORTS;
        RADIO_S_SHORTS = dVar1 | 0x80000;
        return;
      }
      DAT_2300325e = 1;
      return;
    case 3:
      RADIO_S_FREQUENCY = _DAT_23003222 & 0xffff;
      RADIO_S_BASE1 = DAT_23003244;
      RADIO_S_SUBSCRIBE_RXEN = DAT_230071c4 | 0x80000000;
      dVar1 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar1 & 0xfff7ffff;
      dVar1 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar1 | 0x20;
      return;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230240ac. Types and names are inferred; NOT original source. */

void FUN_230240ac(int param_1)

{
  dword dVar1;
  
  if (DAT_23003468 == 0xb) {
    if (param_1 == 4) {
      RADIO_S_PACKETPTR = 0x23003050;
      DAT_23003050._0_1_ = 0;
      TIMER020_S_TASKS_CAPTURE_7 = 1;
      if (DAT_230032d0 == 0) {
        dVar1 = TIMER020_S_CC_7;
        if (0xc7f < dVar1) {
          DAT_23003468 = 0xc;
          return;
        }
      }
      else {
        if (DAT_230032d0 != 3) {
          DAT_23003050._0_1_ = 0;
          DAT_23003468 = 0xc;
          return;
        }
        dVar1 = TIMER020_S_CC_7;
        if (dVar1 < 0x1f41) {
          DAT_23003050._0_1_ = 0;
          DAT_23003468 = 0xc;
          return;
        }
      }
      FUN_23020f1c(&DAT_23003468,&RADIO_S_TASKS_RXEN,0xc);
      return;
    }
    if (param_1 == 1) goto LAB_23024102;
    if (param_1 == 2) {
      RADIO_S_SUBSCRIBE_STOP = 0;
      dVar1 = RADIO_S_SHORTS;
      RADIO_S_SHORTS = dVar1 & 0xffffffdf;
      return;
    }
  }
  else {
    if (DAT_23003468 != 0xc) {
      return;
    }
    if (param_1 == 4) {
      RADIO_S_PACKETPTR = 0x23003050;
      DAT_23003050._0_1_ = 0;
      return;
    }
    if (param_1 == 1) {
LAB_23024102:
      RADIO_S_SUBSCRIBE_RXEN = 0;
      return;
    }
    if (param_1 == 2) {
      RADIO_S_SUBSCRIBE_STOP = 0;
      dVar1 = RADIO_S_SHORTS;
      DAT_23003468 = 0xb;
      RADIO_S_SHORTS = dVar1 & 0xffffffdf;
      return;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024190. Types and names are inferred; NOT original source. */

void FUN_23024190(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  dword dVar8;
  char *pcVar9;
  char cVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  
  uVar3 = DAT_2300305c;
  uVar2 = DAT_23003058;
  uVar1 = DAT_23003054;
  uVar12 = (uint)DAT_230032d0;
  if (uVar12 != 2) {
    uVar12 = (uint)(uVar12 == 5) << 1;
  }
  switch((&DAT_23003468)[uVar12 * 0x3e1]) {
  case 0xc:
    if (param_1 != 4) {
      return;
    }
    dVar8 = RADIO_S_EVENTS_CRCOK;
    if ((dVar8 == 1) && (uVar7 = DAT_23003050 & 0xff, uVar7 != 0)) {
      cVar10 = '\0';
      uVar13 = uVar7 - 1 & 0xff;
      RADIO_S_EVENTS_CRCOK = 0;
      DAT_23003050 = CONCAT31(DAT_23003050._1_3_,(char)(uVar7 - 1));
      uVar11 = DAT_23003050;
      if (uVar13 == 0) {
        pcVar14 = (char *)((int)&DAT_23003050 + 1);
        cVar10 = '\0';
      }
      else {
        pcVar14 = (char *)((int)&DAT_23003050 + 1);
        do {
          pcVar9 = pcVar14 + 1;
          cVar10 = cVar10 + *pcVar14;
          pcVar14 = pcVar9;
        } while (pcVar9 != (char *)((int)&DAT_23003050 + uVar7));
        cVar10 = -cVar10;
        pcVar14 = (char *)((int)&DAT_23003050 + uVar13 + 1);
      }
      if (*pcVar14 != cVar10) goto LAB_2302420a;
      iVar6 = uVar12 * 0xf84;
      DAT_23003050 = (uint)DAT_23003050._1_3_ << 8;
      *(uint *)(&DAT_230034fc + iVar6) = uVar11;
      *(undefined4 *)(&DAT_23003500 + iVar6) = uVar1;
      *(undefined4 *)(&DAT_23003504 + iVar6) = uVar2;
      *(undefined4 *)(&DAT_23003508 + iVar6) = uVar3;
      (&DAT_23003487)[iVar6] = 1;
      uVar5 = FUN_230209a8((&DAT_230034fd)[iVar6]);
      *(ushort *)(&DAT_23003484 + iVar6) = uVar5 & 0xff | uVar5 << 8;
      uVar4 = FUN_230209ac((&DAT_230034fd)[iVar6]);
      (&DAT_23003486)[iVar6] = uVar4;
      uVar7 = FUN_230209b4((&DAT_230034fd)[iVar6]);
      if ((byte)(&DAT_23003483)[iVar6] != uVar7) {
        uVar11 = (uint)DAT_230032ca;
        uVar5 = *(ushort *)(&DAT_2300347e + uVar12 * 0x3e1);
        (&DAT_23003470)[uVar12 * 0x7c2] = 0;
        *(undefined2 *)((int)&DAT_230033e8 + (uVar12 * 0x7c2 + uVar11 + 0x48) * 2) = 0;
        if (uVar5 < 6) {
          cVar10 = (&DAT_23003482)[iVar6] + '\x01';
          if (cVar10 == '\b') {
            cVar10 = '\x01';
          }
          (&DAT_23003482)[iVar6] = cVar10;
          FUN_2302073c(uVar12);
          *(undefined2 *)((int)&DAT_2300347e + iVar6 + 2) =
               *(undefined2 *)(&DAT_2300347e + uVar12 * 0x3e1);
        }
      }
      (&DAT_23003483)[uVar12 * 0xf84] = (char)uVar7;
      *(undefined2 *)(&DAT_2300347e + uVar12 * 0x3e1) = 0xff;
      FUN_23021c24(uVar12);
      dVar8 = RADIO_S_RSSISAMPLE;
      DAT_23003451 = (undefined1)dVar8;
      DAT_23003452 = (undefined1)DAT_23003224;
      DAT_23003450 = 0;
      FUN_2302233c(0);
    }
    else {
LAB_2302420a:
      DAT_23003050 = DAT_23003050 & 0xffffff00;
    }
    (&DAT_23003468)[uVar12 * 0x3e1] = 0xb;
    break;
  case 0xd:
    if (param_1 == 5) {
      (&DAT_23003468)[uVar12 * 0x3e1] = 0xd;
    }
    break;
  case 0xe:
    if (param_1 == 5) {
      iVar6 = FUN_23021af4(2);
      if (iVar6 != 0) {
        RADIO_S_SUBSCRIBE_DISABLE = DAT_230071c5 | 0x80000000;
        dVar8 = FUN_230216b0(DAT_2300535a);
        RADIO_S_FREQUENCY = dVar8;
        FUN_23020f1c(&DAT_23003468 + uVar12 * 0x3e1,&RADIO_S_TASKS_RXEN,0xf,param_4);
        return;
      }
      if (DAT_230031a9 == '\x01') {
        DAT_230031a9 = '\0';
        FUN_2302233c(2);
      }
      (&DAT_23003468)[uVar12 * 0x3e1] = 0xd;
    }
    break;
  case 0xf:
    if (param_1 == 0xe) {
      FUN_23020f1c(&DAT_23003468 + uVar12 * 0x3e1,&RADIO_S_TASKS_RSSISTART,0x10,param_4);
      return;
    }
    break;
  case 0x10:
    RADIO_S_SUBSCRIBE_DISABLE = 0;
    dVar8 = RADIO_S_RSSISAMPLE;
    DAT_23005359 = (undefined1)dVar8;
    DAT_23005358 = 1;
    FUN_2302233c(2);
    (&DAT_23003468)[uVar12 * 0x3e1] = 0xd;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302455c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_2302455c(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  int iVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined local_30;
  byte local_2f;
  char local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  
  iVar10 = param_1 * 0xf84;
  cVar9 = (&DAT_230034fc)[iVar10];
  if ((char)(&DAT_230034fc)[iVar10] < '\x01') {
    return;
  }
  uVar1 = (&DAT_230034fe)[iVar10];
  iVar2 = FUN_230209ec(uVar1);
  uVar3 = FUN_230209f0(uVar1);
  iVar4 = FUN_230209f8(uVar1);
  uVar5 = FUN_230209e4(uVar1);
  if (iVar4 == 0) {
    cVar9 = (&DAT_230034ff)[iVar10];
    if (cVar9 == '+') {
      DAT_230033d2 = *(ushort *)(&DAT_23003501 + iVar10) << 8 |
                     *(ushort *)(&DAT_23003501 + iVar10) >> 8;
      DAT_230033d4 = *(ushort *)(&DAT_23003503 + iVar10) << 8 |
                     *(ushort *)(&DAT_23003503 + iVar10) >> 8;
      DAT_230033ce = (byte)(&DAT_23003500)[iVar10] & 0x3f;
      DAT_230033d0 = (ushort)((byte)(&DAT_23003500)[iVar10] >> 6);
      FUN_2302233c(0,2);
    }
    else if (cVar9 == ',') {
      (&DAT_2300341e)[param_1 * 0x7c2] = (ushort)(byte)(&DAT_23003500)[iVar10];
      (&DAT_23003420)[param_1 * 0x7c2] =
           *(ushort *)(&DAT_23003501 + iVar10) << 8 | *(ushort *)(&DAT_23003501 + iVar10) >> 8;
    }
    else if (cVar9 == '\x17') {
      (&DAT_23003474)[param_1 * 0x3e1] =
           (*(ushort *)(&DAT_23003500 + iVar10) & 0xff) << 8 |
           (uint)(*(ushort *)(&DAT_23003500 + iVar10) >> 8);
    }
    FUN_2302552c(param_1,(&DAT_23003451)[param_1 * 0xf84]);
    goto LAB_23024606;
  }
  if (*(byte *)((int)&DAT_230033e8 + iVar4 + iVar10 + 0xb7) == uVar5) {
    if (iVar4 == 1) {
      if (((&DAT_23003485)[iVar10] == '\x01') && (iVar2 == 0)) {
        DAT_230030a6 = 0;
        _DAT_230030a2 = 0;
      }
      (&DAT_23003474)[param_1 * 0x3e1] = 0;
    }
    goto LAB_23024606;
  }
  *(char *)((int)&DAT_230033e8 + iVar4 + iVar10 + 0xb7) = (char)uVar5;
  if (iVar4 == 1) {
    if ((iVar2 == 1) && ((byte)(&DAT_2300348e)[iVar10] != uVar3)) {
      uVar6 = 0;
      (&DAT_2300348e)[iVar10] = (char)uVar3;
      uVar3 = uVar6;
      uVar5 = uVar6;
    }
    else {
      uVar6 = (uint)(byte)DAT_230030a6;
      uVar3 = _DAT_230030a2 & 0xffff;
      uVar5 = _DAT_230030a2 >> 0x10;
    }
    _DAT_230030a2 =
         (*(ushort *)(&DAT_23003501 + iVar10) & 0xff) << 8 |
         (uint)(*(ushort *)(&DAT_23003501 + iVar10) >> 8);
    iVar8 = _DAT_230030a2 - uVar3;
    uVar3 = (*(ushort *)(&DAT_23003503 + iVar10) & 0xff) << 8 |
            (uint)(*(ushort *)(&DAT_23003503 + iVar10) >> 8);
    iVar11 = uVar3 - uVar5;
    _DAT_230030a2 = _DAT_230030a2 | uVar3 << 0x10;
    cVar9 = (&DAT_23003500)[iVar10];
    local_2e = cVar9 - (char)uVar6;
    local_2b = (undefined1)((uint)iVar11 >> 8);
    local_2f = (&DAT_230034ff)[iVar10];
    uVar3 = (uint)local_2f;
    uVar5 = (uint)cVar9;
    local_2a = (undefined1)iVar11;
    local_2d = (undefined1)((uint)iVar8 >> 8);
    local_2c = (undefined1)iVar8;
    if ((&DAT_23003485)[param_1 * 0xf84] == '\0') {
      DAT_230030a6 = CONCAT11(local_2f,cVar9);
    }
    else {
      if (iVar2 != 1) {
        uVar5 = 0;
        uVar3 = uVar5;
        _DAT_230030a2 = uVar5;
      }
      DAT_230030a6 = CONCAT11((char)uVar3,(char)uVar5);
    }
    local_30 = 0;
    cVar9 = '\a';
    puVar7 = &local_30;
LAB_230245d6:
    FUN_230254a0(0,iVar4,puVar7,cVar9,(&DAT_23003451)[param_1 * 0xf84]);
  }
  else {
    cVar9 = cVar9 + -2;
    if ('\0' < cVar9) {
      puVar7 = &DAT_230034ff + iVar10;
      goto LAB_230245d6;
    }
  }
  (&DAT_23003474)[param_1 * 0x3e1] = 0;
  DAT_230033dc._2_2_ = DAT_230033dc._2_2_ + 1;
LAB_23024606:
  DAT_230033dc._0_2_ = (short)DAT_230033dc + 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024c84. Types and names are inferred; NOT original source. */

void thunk_FUN_230207a4(int param_1)

{
  param_1 = param_1 * 0xf84;
  *(undefined4 *)(&DAT_23003542 + param_1) = 0;
  *(undefined2 *)(&DAT_23003546 + param_1) = 0;
  *(undefined4 *)(&DAT_2300353c + param_1) = 0;
  *(undefined2 *)(&DAT_23003540 + param_1) = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024c88. Types and names are inferred; NOT original source. */

undefined4 FUN_23024c88(int param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = *param_2;
  if (cVar1 != -0x55) {
    if (cVar1 != -0x54) {
      if (cVar1 != -0x5c) {
        return 0;
      }
      DAT_230065e2 = 0x50000;
      DAT_23006590 = 0;
      FUN_230201b4(1,0);
      FUN_230203fc(0x14,0,0);
      return 1;
    }
    *(char *)((int)&DAT_230065b0 + param_1 + 2) = param_2[1];
  }
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024cd4. Types and names are inferred; NOT original source. */

void FUN_23024cd4(void)

{
  uint uVar1;
  undefined1 local_28 [32];
  
  uVar1 = (uint)DAT_23006590;
  if ((int)(uVar1 << 0x1f) < 0) {
    local_28[0] = 0xa3;
    FUN_230251e4(0,3,local_28,1);
    uVar1 = (uint)DAT_23006590;
  }
  if ((int)(uVar1 << 0x1e) < 0) {
    local_28[0] = 0xa3;
    FUN_230251e4(1,3,local_28);
  }
  thunk_FUN_0e06ebe0(&DAT_23001aa0,0,2000000,0,0,0);
  thunk_FUN_0e06ec54(&DAT_23001a68);
  thunk_FUN_0e06ec54(&DAT_23001ad8);
  thunk_FUN_0e06ec54(&DAT_23001b10);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024d54. Types and names are inferred; NOT original source. */

void FUN_23024d54(void)

{
  thunk_FUN_0e06ec54(&DAT_23001aa0);
  thunk_FUN_0e06ec54(&DAT_23001a68);
  if (DAT_23006598 != '\0') {
    thunk_FUN_0e06ebe0(&DAT_23001ad8,0,100000,0,1000,0);
  }
  thunk_FUN_0e06ebe0(&DAT_23001b10,0,100000,0,1000000,0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024db4. Types and names are inferred; NOT original source. */

void FUN_23024db4(uint param_1)

{
  ushort uVar1;
  undefined1 local_30;
  ushort local_2f;
  
  if ((DAT_2300659a & 0xffff) != param_1) {
    uVar1 = (ushort)((param_1 & 0xff) << 8) | (ushort)(param_1 >> 8) & 0xff;
    DAT_2300659a = param_1 & 0xffff | param_1 << 0x10;
    local_30 = 0xac;
    DAT_2300659e = 0;
    DAT_230065b0 = 0;
    local_2f = uVar1;
    FUN_230251e4(0,3,&local_30);
    if ((DAT_2300659a & 0xffff) == 0) {
      if (DAT_23006598 != '\0') {
        DAT_23006598 = (char)DAT_2300659a;
        thunk_FUN_0e06ec54(&DAT_23001ad8);
        return;
      }
    }
    else if (DAT_23006598 == '\0') {
      DAT_23006598 = '\x01';
      thunk_FUN_0e06ebe0(&DAT_23001ad8,1,100000,0,1000,0,uVar1);
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024e38. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23024e38(void)

{
  undefined4 extraout_r1;
  uint auStack_48 [3];
  undefined4 uStack_3c;
  uint uStack_38;
  
  do {
    thunk_FUN_0e06cc94(&DAT_23001bb4,&uStack_3c,0xffffffff,0xffffffff);
    switch(uStack_3c) {
    case 1:
      auStack_48[0] = uStack_38;
      auStack_48[1] = 4;
      FUN_2302206c(auStack_48);
      FUN_23020108(auStack_48[0] & 0xffff);
      ram_candidate_23024e46();
      return;
    case 4:
      FUN_23021f88(0);
      FUN_23022008();
      DAT_230065e2._2_2_ = 5;
      ram_candidate_23024e46();
      return;
    case 8:
      FUN_23020fcc(0,uStack_38);
      FUN_23020108(uStack_38 & 0xffff);
      ram_candidate_23024e46();
      return;
    case 9:
      FUN_23021094(0,uStack_38);
      ram_candidate_23024e46();
      return;
    case 10:
    case 0x28:
      _DAT_23006592 = 0;
      FUN_23024d54();
      ram_candidate_23024e46();
      return;
    case 0x29:
      _DAT_23006592 = 0x101;
      FUN_230221f8(1);
      FUN_23022008();
      thunk_FUN_0e06ebe0(&DAT_23001b10,extraout_r1,100000,0,1000000,0);
      DAT_230065e2._2_2_ = 5;
      ram_candidate_23024e46();
      return;
    case 0x2b:
      _DAT_23006592 = (ushort)DAT_23006593 << 8;
      FUN_23024cd4();
      FUN_230221f8(0);
      ram_candidate_23024e46();
      return;
    case 0x2c:
      _DAT_23006592 = CONCAT11(DAT_23006593,1);
      FUN_23024d54();
      FUN_230221f8(1);
      if (DAT_23006593 != '\0') {
        FUN_23022008();
        DAT_230065e2._2_2_ = 5;
        ram_candidate_23024e46();
        return;
      }
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024e46. Types and names are inferred; NOT original source. */

void ram_candidate_23024e46(void)

{
  undefined4 extraout_r1;
  int unaff_r5;
  uint in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000014;
  uint in_stack_00000018;
  
  do {
    thunk_FUN_0e06cc94();
    switch(in_stack_00000014) {
    case 1:
      in_stack_00000008 = in_stack_00000018;
      in_stack_0000000c = 4;
      FUN_2302206c(&stack0x00000008);
      FUN_23020108(in_stack_00000008 & 0xffff);
      ram_candidate_23024e46();
      return;
    case 4:
      FUN_23021f88(0);
      FUN_23022008();
      *(undefined2 *)(unaff_r5 + 0x54) = 5;
      ram_candidate_23024e46();
      return;
    case 8:
      FUN_23020fcc(0,in_stack_00000018);
      FUN_23020108(in_stack_00000018 & 0xffff);
      ram_candidate_23024e46();
      return;
    case 9:
      FUN_23021094(0,in_stack_00000018);
      ram_candidate_23024e46();
      return;
    case 10:
    case 0x28:
      *(undefined2 *)(unaff_r5 + 2) = 0;
      FUN_23024d54();
      ram_candidate_23024e46();
      return;
    case 0x29:
      *(undefined2 *)(unaff_r5 + 2) = 0x101;
      FUN_230221f8(1);
      FUN_23022008();
      thunk_FUN_0e06ebe0(&DAT_23001b10,extraout_r1,100000,0);
      *(undefined2 *)(unaff_r5 + 0x54) = 5;
      ram_candidate_23024e46();
      return;
    case 0x2b:
      *(undefined1 *)(unaff_r5 + 2) = 0;
      FUN_23024cd4();
      FUN_230221f8(0);
      ram_candidate_23024e46();
      return;
    case 0x2c:
      *(undefined1 *)(unaff_r5 + 2) = 1;
      FUN_23024d54();
      FUN_230221f8(1);
      if (*(char *)(unaff_r5 + 3) != '\0') {
        FUN_23022008();
        *(undefined2 *)(unaff_r5 + 0x54) = 5;
        ram_candidate_23024e46();
        return;
      }
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f14. Types and names are inferred; NOT original source. */

void ram_candidate_23024f14(void)

{
  int unaff_r5;
  
  *(undefined2 *)(unaff_r5 + 2) = 0;
  FUN_23024d54();
  ram_candidate_23024e46();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f1e. Types and names are inferred; NOT original source. */

void ram_candidate_23024f1e(void)

{
  undefined4 in_stack_00000018;
  
  FUN_23021094(0,in_stack_00000018);
  ram_candidate_23024e46();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f28. Types and names are inferred; NOT original source. */

void ram_candidate_23024f28(void)

{
  uint in_stack_00000018;
  
  FUN_23020fcc(0,in_stack_00000018);
  FUN_23020108(in_stack_00000018 & 0xffff);
  ram_candidate_23024e46();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f3a. Types and names are inferred; NOT original source. */

void ram_candidate_23024f3a(void)

{
  int unaff_r5;
  
  FUN_23021f88(0);
  FUN_23022008();
  *(undefined2 *)(unaff_r5 + 0x54) = 5;
  ram_candidate_23024e46();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f4c. Types and names are inferred; NOT original source. */

void ram_candidate_23024f4c(void)

{
  uint uStack00000008;
  undefined4 uStack0000000c;
  uint in_stack_00000018;
  
  uStack00000008 = in_stack_00000018;
  uStack0000000c = 4;
  FUN_2302206c(&stack0x00000008);
  FUN_23020108(uStack00000008 & 0xffff);
  ram_candidate_23024e46();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f64. Types and names are inferred; NOT original source. */

void ram_candidate_23024f64(void)

{
  undefined4 extraout_r1;
  int unaff_r5;
  uint in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000014;
  uint in_stack_00000018;
  
code_r0x23024f64:
  *(undefined1 *)(unaff_r5 + 2) = 1;
  FUN_23024d54();
  FUN_230221f8(1);
  if (*(char *)(unaff_r5 + 3) != '\0') {
    FUN_23022008();
    *(undefined2 *)(unaff_r5 + 0x54) = 5;
    ram_candidate_23024e46();
    return;
  }
code_r0x23024e46:
  thunk_FUN_0e06cc94();
  switch(in_stack_00000014) {
  case 1:
    in_stack_00000008 = in_stack_00000018;
    in_stack_0000000c = 4;
    FUN_2302206c(&stack0x00000008);
    FUN_23020108(in_stack_00000008 & 0xffff);
    ram_candidate_23024e46();
    return;
  default:
    goto code_r0x23024e46;
  case 4:
    FUN_23021f88(0);
    FUN_23022008();
    *(undefined2 *)(unaff_r5 + 0x54) = 5;
    ram_candidate_23024e46();
    return;
  case 8:
    FUN_23020fcc(0,in_stack_00000018);
    FUN_23020108(in_stack_00000018 & 0xffff);
    ram_candidate_23024e46();
    return;
  case 9:
    FUN_23021094(0,in_stack_00000018);
    ram_candidate_23024e46();
    return;
  case 10:
  case 0x28:
    *(undefined2 *)(unaff_r5 + 2) = 0;
    FUN_23024d54();
    ram_candidate_23024e46();
    return;
  case 0x29:
    *(undefined2 *)(unaff_r5 + 2) = 0x101;
    FUN_230221f8(1);
    FUN_23022008();
    thunk_FUN_0e06ebe0(&DAT_23001b10,extraout_r1,100000,0);
    *(undefined2 *)(unaff_r5 + 0x54) = 5;
    ram_candidate_23024e46();
    return;
  case 0x2b:
    *(undefined1 *)(unaff_r5 + 2) = 0;
    FUN_23024cd4();
    FUN_230221f8(0);
    ram_candidate_23024e46();
    return;
  case 0x2c:
    goto code_r0x23024f64;
  }
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f8a. Types and names are inferred; NOT original source. */

void ram_candidate_23024f8a(void)

{
  int unaff_r5;
  
  *(undefined1 *)(unaff_r5 + 2) = 0;
  FUN_23024cd4();
  FUN_230221f8(0);
  ram_candidate_23024e46();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024f9e. Types and names are inferred; NOT original source. */

void ram_candidate_23024f9e(void)

{
  undefined4 extraout_r1;
  int unaff_r5;
  
  *(undefined2 *)(unaff_r5 + 2) = 0x101;
  FUN_230221f8(1);
  FUN_23022008();
  thunk_FUN_0e06ebe0(&DAT_23001b10,extraout_r1,100000,0);
  *(undefined2 *)(unaff_r5 + 0x54) = 5;
  ram_candidate_23024e46();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23024fd8. Types and names are inferred; NOT original source. */

void FUN_23024fd8(undefined4 param_1)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  local_2c = 1;
  uStack_28 = param_1;
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001bb4,&local_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001bb4);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025004. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23025004(undefined4 param_1,int param_2,byte *param_3,char param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *pcVar4;
  byte *pbVar5;
  int iVar6;
  char cVar7;
  byte *pbVar8;
  char local_49;
  byte local_48 [4];
  short local_44;
  undefined2 local_42;
  byte abStack_39 [21];
  
  bVar1 = *param_3;
  pbVar8 = (byte *)(param_2 * 0x80 + 0x23006278);
  local_49 = param_4;
  if ((bVar1 & 0x1f) == 0) {
    (&DAT_23006578)[param_2] = bVar1 & 0x1f;
    (&DAT_23006580)[param_2] = param_4 + -1;
    cVar7 = '\x01';
    thunk_FUN_0e06f35c(pbVar8,param_3 + 1);
  }
  else {
    if ((&DAT_23006578)[param_2] != (bVar1 & 0x1f)) {
      (&DAT_23006578)[param_2] = 0;
      (&DAT_23006580)[param_2] = 0;
      return;
    }
    bVar2 = (&DAT_23006580)[param_2];
    cVar7 = (&DAT_23006578)[param_2] + 1;
    thunk_FUN_0e06f35c(pbVar8 + bVar2,param_3 + 1);
    (&DAT_23006580)[param_2] = bVar2 + param_4 + -1;
  }
  (&DAT_23006578)[param_2] = cVar7;
  if ((int)((uint)bVar1 << 0x18) < 0) {
    return;
  }
  iVar6 = 0;
  (&DAT_23006578)[param_2] = 0;
  cVar7 = (&DAT_23006580)[param_2];
  (&DAT_23006580)[param_2] = 0;
  if (param_2 == 1) {
    local_48[0] = (DAT_230062f8 | DAT_23006588) & 0x7f;
    local_44 = (uRam230062fa << 8 | uRam230062fa >> 8) + _DAT_2300658c;
    local_42 = (uRam230062fc << 8 | uRam230062fc >> 8) + DAT_2300658e;
    cVar7 = (char)DAT_23006589;
    DAT_23006588 = 0;
    _DAT_2300658c = 0;
    DAT_23006589 = 0;
    local_48[3] = cRam230062f9 + cVar7;
    local_48[1] = 0;
    local_48[2] = 0;
  }
  else {
    local_49 = cVar7;
    if (param_2 == 3) {
      iVar6 = FUN_23024c88(param_1,0x230063f8,cVar7);
      if (iVar6 != 0) {
        return;
      }
      goto LAB_230250be;
    }
    if (param_2 != 2) {
      if (param_2 == 4) {
        pbVar8 = local_48;
        thunk_FUN_0e06f3aa(pbVar8,0,0x20);
        thunk_FUN_0e06f35c(pbVar8,0x23006478,cVar7);
        iVar3 = FUN_23020128(pbVar8,&local_49);
        if (iVar3 == 0) {
          return;
        }
        local_49 = '\x10';
        if (local_48[0] == 1) {
          pbVar5 = local_48 + 1;
          DAT_23006594 = 0;
          do {
            pbVar5 = pbVar5 + 1;
            if (*pbVar5 != 0) {
              iVar6 = iVar3;
            }
          } while (abStack_39 != pbVar5);
          if (iVar6 != 0) {
            DAT_23006594 = 1;
          }
        }
      }
      goto LAB_230250be;
    }
    thunk_FUN_0e06f3aa(local_48,0,0x20);
    thunk_FUN_0e06f35c(local_48,0x23006378,cVar7);
    iVar6 = FUN_23020128(local_48,&local_49);
    if (iVar6 == 0) {
      return;
    }
    iVar3 = 0;
    pcVar4 = &local_49;
    do {
      pcVar4 = pcVar4 + 1;
      if (*pcVar4 != '\0') {
        iVar3 = iVar6;
      }
    } while ((char *)((int)&local_42 + 1) != pcVar4);
    DAT_23006594 = iVar3 != 0;
  }
  local_49 = '\b';
  pbVar8 = local_48;
LAB_230250be:
  FUN_23020250(param_2,pbVar8,local_49);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230251e4. Types and names are inferred; NOT original source. */

void FUN_230251e4(undefined4 param_1,undefined4 param_2,char *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  byte local_68;
  undefined1 auStack_67 [67];
  char *pcVar4;
  
  if (param_4 == 0) {
    cVar9 = '\0';
  }
  else {
    cVar9 = '\0';
    pcVar4 = param_3;
    do {
      pcVar3 = pcVar4 + 1;
      cVar9 = cVar9 + *pcVar4;
      pcVar4 = pcVar3;
    } while (pcVar3 != param_3 + param_4);
    cVar9 = -cVar9;
  }
  param_3[param_4] = cVar9;
  uVar5 = param_4 + 1U & 0xffff;
  uVar1 = FUN_23020768(param_1,param_2);
  uVar8 = ((int)(uVar5 + 3) >> 2) - 1U & 0xffff;
  if (uVar8 < uVar1) {
    uVar6 = 0;
    uVar1 = 0;
    do {
      if (uVar1 == uVar8) {
        local_68 = 0;
        uVar1 = uVar5 + 1 & 0xffff;
        uVar7 = uVar5;
      }
      else {
        uVar1 = 5;
        local_68 = 0x80;
        uVar7 = 4;
      }
      local_68 = local_68 | (byte)uVar6;
      thunk_FUN_0e06f35c(auStack_67,param_3);
      iVar2 = FUN_230208b8(param_1,param_2,&local_68,uVar1,0xff);
      uVar6 = uVar6 + 1;
      uVar1 = uVar6 & 0xffff;
      uVar5 = uVar5 - uVar7 & 0xffff;
    } while ((iVar2 != 0) && (param_3 = param_3 + uVar7, uVar1 <= uVar8));
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230252a4. Types and names are inferred; NOT original source. */

void FUN_230252a4(undefined4 param_1)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  local_2c = 8;
  uStack_28 = param_1;
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001bb4,&local_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001bb4);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230252d0. Types and names are inferred; NOT original source. */

void thunk_FUN_23020fec(char *param_1)

{
  byte bVar1;
  char *pcVar2;
  byte *pbVar3;
  char cVar4;
  uint uVar5;
  byte *pbVar6;
  
  DAT_230031fa = *param_1 != '\0';
  DAT_230031fb = param_1[1];
  if (0x27 < DAT_230031fb - 1) {
    DAT_230031fa = 0;
    return;
  }
  pbVar3 = (byte *)(param_1 + 1);
  pcVar2 = (char *)&DAT_230031fb;
  pbVar6 = pbVar3 + DAT_230031fb;
  do {
    while( true ) {
      pbVar3 = pbVar3 + 1;
      bVar1 = *pbVar3;
      if (bVar1 - 2 < 0x7f) break;
      pcVar2 = pcVar2 + 1;
      *pcVar2 = '\0';
      if (pbVar3 == pbVar6) {
        return;
      }
    }
    uVar5 = (short)(ushort)(bVar1 >> 4) * 10 + (bVar1 & 0xf);
    if (uVar5 == 2) {
      cVar4 = '%';
    }
    else if (uVar5 < 0x1a) {
      cVar4 = (char)((uVar5 - 4) * 0x800000 >> 0x18);
    }
    else if (uVar5 == 0x1a) {
      cVar4 = '&';
    }
    else if (uVar5 < 0x50) {
      cVar4 = (char)((int)(uVar5 - 0x1c) >> 1) + '\v';
    }
    else {
      cVar4 = '\'';
    }
    pcVar2 = pcVar2 + 1;
    *pcVar2 = cVar4;
  } while (pbVar3 != pbVar6);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025300. Types and names are inferred; NOT original source. */

void FUN_23025300(undefined4 param_1)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 uStack_28;
  
  local_2c = 9;
  uStack_28 = param_1;
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001bb4,&local_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001bb4);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302532c. Types and names are inferred; NOT original source. */

void FUN_2302532c(void)

{
  FUN_23021e74();
  thunk_FUN_0e06d8f8(&DAT_230020e0,&DAT_23010000,0x400,0x23024e39,0,0,0,0xe,0);
  thunk_FUN_0e06d8f8(&DAT_23002050,&DAT_2300fc00,0x400,0x230253c5,0,0,0,0xe,0);
  FUN_0e05d634("falcon app system init\n");
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302539c. Types and names are inferred; NOT original source. */

void FUN_2302539c(undefined4 param_1)

{
  int iVar1;
  undefined4 local_2c [9];
  
  local_2c[0] = param_1;
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001bb4,local_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001bb4);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230253c4. Types and names are inferred; NOT original source. */

void FUN_230253c4(void)

{
  undefined2 local_48 [2];
  int local_44;
  ushort local_40;
  
  do {
    while( true ) {
      thunk_FUN_0e06cc94(&DAT_23001b8c,&local_44,0xffffffff,0xffffffff);
      if (local_44 == 1) break;
      if ((local_44 == 2) && (local_40 == 0 && (short)DAT_230065e2 == 0)) {
        thunk_FUN_0e06ebe0(&DAT_23001a30,2,2000000,0,0,0);
        DAT_230065e2 = CONCAT22(DAT_230065e2._2_2_,4);
        DAT_230065de = 0;
      }
    }
    DAT_23006590 = (ushort)(1 << (local_40 & 0xff)) | DAT_23006590;
    DAT_230065e6 = 5;
    if (local_40 == 0) {
      FUN_230201b4(1);
      local_48[0] = 4;
      FUN_230203fc(2,local_48);
      thunk_FUN_0e06ec54(&DAT_23001a30);
      DAT_230065e2 = 0;
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302546c. Types and names are inferred; NOT original source. */

void FUN_2302546c(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  local_28 = *param_1;
  local_2c = 1;
  uStack_24 = param_1[1];
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001b8c,&local_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001b8c);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230254a0. Types and names are inferred; NOT original source. */

void FUN_230254a0(uint param_1,undefined1 param_2,undefined4 param_3,uint param_4,ushort param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_5;
  FUN_23025004(param_1 & 0xff,param_2,param_3,param_4 & 0xff,param_4);
  if ((uVar4 != 0) && (uVar4 != 0xff)) {
    *(uint *)(&DAT_23006590 + (param_1 + 4) * 2) =
         *(int *)(&DAT_23006590 + (param_1 + 4) * 2) + uVar4;
    *(int *)(&DAT_23006590 + (param_1 + 6) * 2) = *(int *)(&DAT_23006590 + (param_1 + 6) * 2) + 1;
    iVar1 = (param_1 + 8) * 4;
    iVar2 = (param_1 + 10) * 4;
    iVar3 = *(int *)(&DAT_23006598 + iVar2);
    *(uint *)(&DAT_23006598 + iVar1) = uVar4 + *(int *)(&DAT_23006598 + iVar1);
    *(int *)(&DAT_23006598 + iVar2) = iVar3 + 1;
  }
  DAT_230065e6 = 5;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230254f8. Types and names are inferred; NOT original source. */

void FUN_230254f8(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  
  local_28 = *param_1;
  local_2c = 2;
  uStack_24 = param_1[1];
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001b8c,&local_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001b8c);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302552c. Types and names are inferred; NOT original source. */

void FUN_2302552c(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 != 0) && (param_2 != 0xff)) {
    *(int *)(&DAT_23006590 + (param_1 + 4) * 2) =
         *(int *)(&DAT_23006590 + (param_1 + 4) * 2) + param_2;
    *(int *)(&DAT_23006590 + (param_1 + 6) * 2) = *(int *)(&DAT_23006590 + (param_1 + 6) * 2) + 1;
    iVar1 = (param_1 + 8) * 4;
    *(int *)(&DAT_23006598 + iVar1) = *(int *)(&DAT_23006598 + iVar1) + param_2;
    iVar1 = (param_1 + 10) * 4;
    DAT_230065e6 = 5;
    *(int *)(&DAT_23006598 + iVar1) = *(int *)(&DAT_23006598 + iVar1) + 1;
    return;
  }
  DAT_230065e6 = 5;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025580. Types and names are inferred; NOT original source. */

void FUN_23025580(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  local_28 = *param_1;
  local_2c = 5;
  uStack_24 = param_1[1];
  uStack_20 = param_1[2];
  while (iVar1 = thunk_FUN_0e06cbdc(&DAT_23001b8c,&local_2c,0,0), iVar1 != 0) {
    thunk_FUN_0e06cd54(&DAT_23001b8c);
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230255b8. Types and names are inferred; NOT original source. */

void ram_candidate_230255b8(void)

{
  DAT_23006590 = 0;
  DAT_230065e2 = 0x50000;
  FUN_230201b4(1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230255d0. Types and names are inferred; NOT original source. */

void ram_candidate_230255d0(undefined4 param_1,undefined4 param_2)

{
  thunk_FUN_0e06ebe0(&DAT_23001aa0,param_2,100000,0,0,0);
  FUN_23022008();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230255f8. Types and names are inferred; NOT original source. */

void ram_candidate_230255f8(undefined4 param_1,undefined4 param_2)

{
  thunk_FUN_0e06ebe0(&DAT_23001a68,param_2,400000,0,0,0);
  FUN_23021f88(0);
  if (DAT_23006590 == 0) {
    return;
  }
  DAT_23006590 = 0;
  DAT_230065e2._0_2_ = 0;
  FUN_230201b4(1);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025640. Types and names are inferred; NOT original source. */

void FUN_23025640(void)

{
  bool bVar1;
  ushort uVar2;
  undefined4 local_30;
  
  if ((DAT_2300659a._2_2_ != 0) &&
     (bVar1 = DAT_2300659a._2_2_ == 1, DAT_2300659a._2_2_ = DAT_2300659a._2_2_ - 1, bVar1)) {
    DAT_2300659e = (ushort)DAT_2300659a >> 1;
    DAT_2300659a._2_2_ = (ushort)DAT_2300659a;
    if (DAT_230065a8 == 0) {
      DAT_230065b0._0_1_ = 0;
    }
    else {
      DAT_230065b0._0_1_ = (undefined1)(DAT_230065a0 / DAT_230065a8);
    }
    DAT_230065a0 = 0;
    DAT_230065a8 = 0;
    DAT_230065b0._1_1_ = 0;
    if (DAT_230065ac != 0) {
      DAT_230065b0._1_1_ = (undefined1)(DAT_230065a4 / DAT_230065ac);
    }
    DAT_230065a4 = 0;
    DAT_230065ac = 0;
    local_30 = CONCAT31(CONCAT12(local_30._3_1_,
                                 (ushort)DAT_2300659a << 8 | (ushort)DAT_2300659a >> 8),0xac);
    FUN_230251e4(0,3,&local_30);
  }
  if ((DAT_2300659e != 0) &&
     (uVar2 = DAT_2300659e - 1, bVar1 = DAT_2300659e == 1, DAT_2300659e = uVar2, bVar1)) {
    local_30 = CONCAT13(DAT_230065b0._3_1_,
                        CONCAT12(DAT_230065b0._1_1_,
                                 CONCAT11(DAT_230065b0._2_1_,(undefined1)DAT_230065b0)));
    FUN_230203fc(1,&local_30,4);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230256e8. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_230256e8(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 extraout_r1;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *extraout_r2;
  uint *puVar7;
  short sVar8;
  uint extraout_r3;
  uint *unaff_r5;
  uint unaff_r6;
  bool bVar9;
  undefined4 local_3c [10];
  
  if (DAT_230065b4._2_2_ == 0) goto LAB_2302576c;
  DAT_230065b4._2_2_ = DAT_230065b4._2_2_ + -1;
  if (DAT_230065b4._2_2_ != 0) goto LAB_2302576c;
  unaff_r6 = (uint)DAT_230065e0;
  DAT_230065b4._2_2_ = (short)DAT_230065b4;
  puVar1 = &DAT_230065dc;
  puVar6 = &DAT_230065b4;
  unaff_r5 = &DAT_230065bc;
  DAT_230065c8 = 0;
LAB_23025712:
  do {
    puVar7 = puVar6 + 1;
    uVar3 = 0;
    if (*puVar7 == 0) goto LAB_230257d2;
    uVar4 = *puVar7 / puVar6[3];
    uVar5 = uVar4 & 0xff;
    puVar1[-4] = (char)uVar4;
    puVar6 = puVar7;
    if (unaff_r6 == 0) {
      if (uVar5 == 0) goto LAB_230257da;
      if (DAT_23002da8._2_1_ < uVar5) {
        if (DAT_23002da8._3_1_ < uVar5) {
          if ((byte)DAT_23002dac < uVar5) {
            *puVar1 = 1;
          }
          else {
            *puVar1 = 2;
          }
        }
        else {
          *puVar1 = 3;
        }
      }
      else {
        *puVar1 = 4;
      }
    }
    while( true ) {
      *puVar6 = DAT_230065c8;
      puVar6[2] = DAT_230065c8;
      puVar1 = puVar1 + 1;
      if (puVar6 != unaff_r5) break;
      while( true ) {
        DAT_230065cc = DAT_230065c8;
        DAT_230065d0 = DAT_230065c8;
        DAT_230065d4 = DAT_230065c8;
        if (_DAT_230065dc != DAT_230065de) {
          if (DAT_23006590 != 0) {
            FUN_230203fc(2,&DAT_230065dc);
          }
          DAT_230065de = _DAT_230065dc;
        }
LAB_2302576c:
        if ((ushort)DAT_230065e2 != 0) {
          DAT_230065e2._0_2_ = (ushort)DAT_230065e2 - 1;
          unaff_r5 = (uint *)(uint)(ushort)DAT_230065e2;
          if (unaff_r5 == (uint *)0x0) {
            DAT_230065e2._2_2_ = 5;
            DAT_23006590 = (ushort)DAT_230065e2;
            thunk_FUN_0e06ec54(&DAT_23001a30);
            FUN_230201b4(1,0);
          }
        }
        if (((DAT_23006595 == '\0') && (DAT_230065e2._2_2_ != 0)) &&
           (sVar8 = DAT_230065e2._2_2_ + -1, bVar9 = DAT_230065e2._2_2_ == 1,
           DAT_230065e2._2_2_ = sVar8, bVar9)) {
          unaff_r5 = (uint *)&DAT_23001bb4;
          local_3c[0] = 4;
          while (iVar2 = thunk_FUN_0e06cbdc(&DAT_23001bb4,local_3c,0,0), iVar2 != 0) {
            thunk_FUN_0e06cd54(&DAT_23001bb4);
          }
        }
        if ((DAT_23006590 == 0) ||
           ((DAT_230065e6 != 0 &&
            (sVar8 = DAT_230065e6 + -1, bVar9 = DAT_230065e6 != 1, DAT_230065e6 = sVar8, bVar9)))) {
          return;
        }
        puVar1 = (undefined1 *)thunk_FUN_0e05d698(0);
        puVar7 = extraout_r2;
        DAT_230065c8 = extraout_r3;
        uVar3 = extraout_r1;
LAB_230257d2:
        puVar1[-4] = uVar3;
        puVar6 = puVar7;
        if (unaff_r6 != 0) break;
LAB_230257da:
        *puVar1 = 0;
        *puVar6 = DAT_230065c8;
        puVar6[2] = DAT_230065c8;
        puVar1 = puVar1 + 1;
        if (puVar6 != unaff_r5) goto LAB_23025712;
      }
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025848. Types and names are inferred; NOT original source. */

undefined4 FUN_23025848(void)

{
  int iVar1;
  undefined1 auStack_1c [4];
  uint local_18;
  
  DAT_230071b0 = 0;
  DAT_23002ca4 = &DAT_0e06f6cc;
  iVar1 = thunk_FUN_0e06c6c0();
  if (iVar1 != 0) {
    DAT_230071b0 = 1;
  }
  DAT_23001f68 = &DAT_0e06f6cc;
  iVar1 = thunk_FUN_0e06c6c0(&DAT_0e06f6cc);
  if (iVar1 != 0) {
    DAT_23001f30 = 0x1db000;
    iVar1 = thunk_FUN_0e067468(DAT_23001f68,0x1db000,auStack_1c);
    if (iVar1 == 0) {
      DAT_23001f4c = 0x2000 / local_18;
      DAT_23001f48 = local_18;
      iVar1 = thunk_FUN_0e05e6d4(&DAT_23001f30);
      if (iVar1 == 0) {
        DAT_23001fb0 = &DAT_0e06f6cc;
        iVar1 = thunk_FUN_0e06c6c0(&DAT_0e06f6cc);
        if (iVar1 != 0) {
          DAT_23001f78 = 0x1df000;
          iVar1 = thunk_FUN_0e067468(DAT_23001fb0,0x1df000,auStack_1c);
          if (iVar1 == 0) {
            DAT_23001f94 = 0x3000 / local_18;
            DAT_23001f90 = local_18;
            iVar1 = thunk_FUN_0e05e6d4(&DAT_23001f78);
            if (iVar1 == 0) {
              return 0;
            }
          }
        }
      }
    }
  }
  return 0xffffffea;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230258fc. Types and names are inferred; NOT original source. */

bool FUN_230258fc(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (1 < param_1) {
    return false;
  }
  iVar1 = thunk_FUN_0e05ed64(&DAT_23001f30 + param_1 * 0x12);
  return iVar1 == param_4;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025924. Types and names are inferred; NOT original source. */

bool FUN_23025924(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (1 < param_1) {
    return false;
  }
  iVar1 = thunk_FUN_0e05eb1c(&DAT_23001f30 + param_1 * 0x12);
  if (iVar1 != param_4) {
    return iVar1 == 0;
  }
  return true;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025954. Types and names are inferred; NOT original source. */

void FUN_23025954(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  uVar1 = param_1 - 1U & 0xff;
  if (uVar1 < 4) {
    uVar4 = (&DAT_0e06f78c)[uVar1];
    uVar3 = (&DAT_0e06f784)[uVar1];
    uVar5 = (&DAT_0e06f788)[uVar1];
  }
  else {
    uVar4 = 0;
    uVar3 = uVar4;
    uVar5 = uVar4;
  }
  uVar1 = 0;
  do {
    uVar2 = uVar1 & 0xff;
    uVar1 = uVar1 + 1;
    FUN_23025ce0(uVar2,uVar4,uVar5,uVar3,param_4);
  } while (uVar1 != 3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025994. Types and names are inferred; NOT original source. */

void FUN_23025994(void)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  
  if (DAT_230071b9 != '\0') {
    DAT_2300719c = DAT_2300719c + 1;
    if (DAT_23000b52 <= DAT_2300719c) {
      bVar1 = DAT_230071b1 & 1;
      if ((DAT_230071b1 & 1) == 0) {
        pcVar3 = &DAT_23002cb4;
        do {
          if (*pcVar3 == '\x01') {
            FUN_23025ce0(bVar1,0xff,0);
          }
          bVar1 = bVar1 + 1;
          pcVar3 = pcVar3 + 1;
        } while (bVar1 != 3);
      }
      else {
        cVar2 = '\0';
        pcVar3 = &DAT_23002cb4;
        do {
          if (*pcVar3 == '\x01') {
            FUN_23025ce0(cVar2,0,0);
          }
          cVar2 = cVar2 + '\x01';
          pcVar3 = pcVar3 + 1;
        } while (cVar2 != '\x03');
      }
      DAT_230071b1 = DAT_230071b1 + 1;
      if (DAT_230071b1 < 4) {
        DAT_23000b52 = 1;
      }
      else {
        DAT_230071b1 = 0;
        DAT_23000b52 = 10;
      }
      DAT_2300719c = 0;
    }
    return;
  }
  DAT_2300719c = 0;
  DAT_230071b1 = DAT_230071b9;
  DAT_23000b52 = 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025a44. Types and names are inferred; NOT original source. */

void FUN_23025a44(void)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  undefined1 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined2 uVar8;
  uint uVar9;
  char *pcVar4;
  
  puVar7 = &DAT_23002ca8;
  iVar1 = (((uint)DAT_230071b6 * 100) / 0xff) * 4;
  pcVar4 = &DAT_23002cb4;
  do {
    pcVar3 = pcVar4 + 1;
    cVar2 = *pcVar4;
    if (cVar2 == '\x01') {
      uVar8 = *(undefined2 *)(&DAT_0e06f7d4 + iVar1);
      *(undefined1 *)((int)puVar7 + 3) = 1;
      uVar5 = (&DAT_0e06f7d6)[iVar1];
      *(undefined2 *)puVar7 = uVar8;
      *(undefined1 *)((int)puVar7 + 2) = uVar5;
    }
    else if (cVar2 == '\x02') {
      uVar9 = (uint)DAT_230071b3;
      *(undefined1 *)((int)puVar7 + 3) = 1;
      *(undefined2 *)puVar7 = *(undefined2 *)(&DAT_0e06f7c0 + uVar9 * 4);
      *(undefined *)((int)puVar7 + 2) = (&DAT_0e06f7c2)[uVar9 * 4];
    }
    else if (cVar2 == '\x03') {
      if ((int)((uint)DAT_230071b4 << 0x1f) < 0) {
        uVar8 = 0xff;
        uVar5 = 0;
LAB_23025b02:
        *(undefined1 *)((int)puVar7 + 2) = uVar5;
        *(undefined2 *)puVar7 = uVar8;
        *(undefined1 *)((int)puVar7 + 3) = 1;
      }
      else {
        uVar9 = 1;
        do {
          uVar6 = uVar9 + 1;
          if (((int)(uint)DAT_230071b4 >> (uVar9 & 0xff)) << 0x1f < 0) {
            uVar8 = (&DAT_0e06f7a4)[uVar9 * 2];
            uVar5 = (&DAT_0e06f7a6)[uVar9 * 4];
            goto LAB_23025b02;
          }
          uVar9 = uVar6;
        } while (uVar6 != 7);
      }
    }
    else if (cVar2 == '\x04') {
      uVar9 = (uint)DAT_230071b5;
      *(undefined1 *)((int)puVar7 + 3) = 1;
      *(undefined2 *)puVar7 = *(undefined2 *)(&DAT_0e06f790 + uVar9 * 4);
      *(undefined *)((int)puVar7 + 2) = (&DAT_0e06f792)[uVar9 * 4];
    }
    else {
      *(undefined2 *)puVar7 = 0;
      *(undefined1 *)((int)puVar7 + 3) = 1;
      *(undefined1 *)((int)puVar7 + 2) = 0;
    }
    puVar7 = puVar7 + 1;
    pcVar4 = pcVar3;
    if (pcVar3 == (char *)0x23002cb7) {
      return;
    }
  } while( true );
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025b40. Types and names are inferred; NOT original source. */

void FUN_23025b40(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar8;
  char *pcVar7;
  
  switch(param_1) {
  case 0xe0:
    if (param_2 < 5) {
      puVar4 = &DAT_23002ca8;
      pcVar7 = &DAT_23002cb4;
      do {
        pcVar6 = pcVar7 + 1;
        if (*pcVar7 == '\x02') {
          uVar3 = *(undefined2 *)(&DAT_0e06f7c0 + param_2 * 4);
          *(undefined1 *)((int)puVar4 + 3) = 1;
          *(undefined2 *)puVar4 = uVar3;
          *(undefined *)((int)puVar4 + 2) = (&DAT_0e06f7c2)[param_2 * 4];
        }
        puVar4 = puVar4 + 1;
        pcVar7 = pcVar6;
      } while (pcVar6 != (char *)0x23002cb7);
    }
    break;
  case 0xe1:
    if ((int)(param_2 << 0x1f) < 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (param_2 & 3) >> 1;
      if (-1 < (int)(param_2 << 0x1e)) {
        uVar5 = 2;
        while (uVar8 = uVar5 + 1, -1 < ((int)param_2 >> (uVar5 & 0xff)) << 0x1f) {
          uVar5 = uVar8;
          if (uVar8 == 7) {
            return;
          }
        }
      }
    }
    puVar4 = &DAT_23002ca8;
    pcVar7 = &DAT_23002cb4;
    do {
      pcVar6 = pcVar7 + 1;
      if (*pcVar7 == '\x03') {
        uVar3 = (&DAT_0e06f7a4)[uVar5 * 2];
        *(undefined1 *)((int)puVar4 + 3) = 1;
        *(undefined2 *)puVar4 = uVar3;
        *(undefined1 *)((int)puVar4 + 2) = (&DAT_0e06f7a6)[uVar5 * 4];
      }
      puVar4 = puVar4 + 1;
      pcVar7 = pcVar6;
    } while (pcVar6 != (char *)0x23002cb7);
    break;
  case 0xe2:
    if (param_2 < 5) {
      puVar4 = &DAT_23002ca8;
      pcVar7 = &DAT_23002cb4;
      do {
        pcVar6 = pcVar7 + 1;
        if (*pcVar7 == '\x04') {
          uVar3 = *(undefined2 *)(&DAT_0e06f790 + param_2 * 4);
          *(undefined1 *)((int)puVar4 + 3) = 1;
          *(undefined2 *)puVar4 = uVar3;
          *(undefined *)((int)puVar4 + 2) = (&DAT_0e06f792)[param_2 * 4];
        }
        puVar4 = puVar4 + 1;
        pcVar7 = pcVar6;
      } while (pcVar6 != (char *)0x23002cb7);
    }
    break;
  case 0xe3:
    DAT_230071b9 = param_2 < 0x10;
    if (!(bool)DAT_230071b9) {
      puVar4 = &DAT_23002ca8;
      iVar1 = ((param_2 * 100) / 0xff) * 4;
      pcVar7 = &DAT_23002cb4;
      do {
        pcVar6 = pcVar7 + 1;
        if (*pcVar7 == '\x01') {
          uVar3 = *(undefined2 *)(&DAT_0e06f7d4 + iVar1);
          *(undefined1 *)((int)puVar4 + 3) = 1;
          uVar2 = (&DAT_0e06f7d6)[iVar1];
          *(undefined2 *)puVar4 = uVar3;
          *(undefined1 *)((int)puVar4 + 2) = uVar2;
        }
        puVar4 = puVar4 + 1;
        pcVar7 = pcVar6;
      } while (pcVar6 != (char *)0x23002cb7);
    }
    break;
  case 0xff:
    DAT_23002cac = 0x1000000;
    DAT_23002cb0 = 0x1000000;
    DAT_23002ca8 = 0x1000000;
    DAT_230071b9 = 0;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025cb0. Types and names are inferred; NOT original source. */

void FUN_23025cb0(void)

{
  undefined4 in_r3;
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  puVar1 = &DAT_23002ca8;
  do {
    if (*(char *)((int)puVar1 + 3) != '\0') {
      FUN_23025ce0(uVar2 & 0xff,*(undefined1 *)puVar1,*(undefined1 *)((int)puVar1 + 1),
                   *(undefined1 *)((int)puVar1 + 2),in_r3);
      *(undefined1 *)((int)puVar1 + 3) = 0;
    }
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 != 3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025ce0. Types and names are inferred; NOT original source. */

void FUN_23025ce0(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  uint local_30;
  int iStack_2c;
  
  uVar10 = (&DAT_0e06f96c)[param_1 * 0xc];
  uVar9 = (&DAT_0e06f970)[param_1 * 0xc];
  uVar1 = (&DAT_0e06f974)[param_1 * 0x18];
  iVar7 = (&DAT_0e06f968)[param_1 * 0xc];
  iVar3 = (**(code **)(*(int *)(iVar7 + 8) + 4))(iVar7,uVar10,&local_30);
  iVar6 = iStack_2c;
  uVar5 = local_30;
  if (-1 < iVar3) {
    uVar8 = uVar9 * iStack_2c + (int)((ulonglong)uVar9 * (ulonglong)local_30 >> 0x20);
    uVar4 = thunk_FUN_0e05ba10((int)((ulonglong)uVar9 * (ulonglong)local_30),uVar8,1000000000,0);
    if ((uVar8 < 1000000000) &&
       (uVar9 = (uVar9 * param_2) / 0xff, lVar2 = (ulonglong)uVar9 * (ulonglong)uVar5,
       uVar9 = uVar9 * iVar6 + (int)((ulonglong)lVar2 >> 0x20),
       uVar5 = thunk_FUN_0e05ba10((int)lVar2,uVar9,1000000000,0), uVar9 < 1000000000)) {
      if (uVar5 <= uVar4) {
        (*(code *)**(undefined4 **)(iVar7 + 8))(iVar7,uVar10,uVar4,uVar5,uVar1);
      }
    }
  }
  iVar6 = param_1 * 0x30;
  uVar9 = *(uint *)(&DAT_0e06f980 + iVar6);
  iVar7 = (&DAT_0e06f978)[param_1 * 0xc];
  uVar10 = *(undefined4 *)(&DAT_0e06f97c + iVar6);
  uVar1 = *(undefined2 *)(&DAT_0e06f984 + iVar6);
  iVar3 = (**(code **)(*(int *)(iVar7 + 8) + 4))(iVar7,uVar10,&local_30);
  iVar6 = iStack_2c;
  uVar5 = local_30;
  if (-1 < iVar3) {
    uVar8 = uVar9 * iStack_2c + (int)((ulonglong)uVar9 * (ulonglong)local_30 >> 0x20);
    uVar4 = thunk_FUN_0e05ba10((int)((ulonglong)uVar9 * (ulonglong)local_30),uVar8,1000000000,0);
    if ((uVar8 < 1000000000) &&
       (uVar9 = (uVar9 * param_3) / 0xff, lVar2 = (ulonglong)uVar9 * (ulonglong)uVar5,
       uVar9 = uVar9 * iVar6 + (int)((ulonglong)lVar2 >> 0x20),
       uVar5 = thunk_FUN_0e05ba10((int)lVar2,uVar9,1000000000,0), uVar9 < 1000000000)) {
      if (uVar5 <= uVar4) {
        (*(code *)**(undefined4 **)(iVar7 + 8))(iVar7,uVar10,uVar4,uVar5,uVar1);
      }
    }
  }
  param_1 = param_1 * 0x30;
  uVar5 = *(uint *)(&DAT_0e06f990 + param_1);
  iVar3 = *(int *)(&DAT_0e06f988 + param_1);
  uVar10 = *(undefined4 *)(&DAT_0e06f98c + param_1);
  uVar1 = *(undefined2 *)(&DAT_0e06f994 + param_1);
  iVar6 = (**(code **)(*(int *)(iVar3 + 8) + 4))(iVar3,uVar10,&local_30);
  if (-1 < iVar6) {
    uVar4 = uVar5 * iStack_2c + (int)((ulonglong)uVar5 * (ulonglong)local_30 >> 0x20);
    uVar9 = thunk_FUN_0e05ba10((int)((ulonglong)uVar5 * (ulonglong)local_30),uVar4,1000000000,0);
    if ((uVar4 < 1000000000) &&
       (uVar5 = (uVar5 * param_4) / 0xff, lVar2 = (ulonglong)uVar5 * (ulonglong)local_30,
       uVar4 = uVar5 * iStack_2c + (int)((ulonglong)lVar2 >> 0x20),
       uVar5 = thunk_FUN_0e05ba10((int)lVar2,uVar4,1000000000,0), uVar4 < 1000000000)) {
      if (uVar5 <= uVar9) {
        (*(code *)**(undefined4 **)(iVar3 + 8))(iVar3,uVar10,uVar9,uVar5,uVar1);
      }
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025ee0. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_23025ee0(void)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint local_30;
  int iStack_2c;
  
  _DAT_23002cb4 = DAT_23002d90._1_2_;
  DAT_23002cb6 = DAT_23002d90._3_1_;
  DAT_23006c7c = DAT_23006c7c & 0xffffffef;
  FUN_0e067700(&PTR_s_gpio_938000_0e06f5dc,4,0x60000);
  piVar7 = &DAT_0e06f968;
  do {
    iVar11 = 0;
    piVar6 = piVar7;
    do {
      iVar2 = thunk_FUN_0e06c6c0(*piVar6);
      if (iVar2 == 0) {
        return 0xfffffffa;
      }
      iVar9 = *piVar6;
      iVar10 = piVar6[1];
      uVar8 = piVar6[2];
      iVar2 = piVar6[3];
      iVar3 = (**(code **)(*(int *)(iVar9 + 8) + 4))(iVar9,iVar10,&local_30);
      if ((-1 < iVar3) &&
         (lVar1 = (ulonglong)local_30 * (ulonglong)uVar8,
         uVar8 = uVar8 * iStack_2c + (int)((ulonglong)lVar1 >> 0x20),
         uVar4 = thunk_FUN_0e05ba10((int)lVar1,uVar8,1000000000,0), uVar8 < 1000000000)) {
        (*(code *)**(undefined4 **)(iVar9 + 8))(iVar9,iVar10,uVar4,0,(short)iVar2);
      }
      iVar11 = iVar11 + 4;
      piVar6 = piVar6 + 4;
    } while (iVar11 != 0xc);
    piVar7 = piVar7 + 0xc;
  } while (piVar7 != &DAT_0e06f9f8);
  if ((int)(DAT_23006c7c << 0x1b) < 0) {
    pcVar5 = (code *)0xe0679b1;
  }
  else {
    pcVar5 = (code *)0xe06796d;
  }
  (*pcVar5)(&PTR_s_gpio_938000_0e06f5dc,0x10);
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23025fe0. Types and names are inferred; NOT original source. */

void FUN_23025fe0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = 0;
  uVar5 = (uint)(param_1 * 100) / 0xff;
  iVar1 = uVar5 * 4;
  uVar4 = (&DAT_0e06f7d4)[uVar5 * 4];
  uVar2 = (&DAT_0e06f7d5)[iVar1];
  uVar3 = (&DAT_0e06f7d6)[iVar1];
  do {
    uVar5 = uVar6 & 0xff;
    uVar6 = uVar6 + 1;
    FUN_23025ce0(uVar5,uVar4,uVar2,uVar3,param_4);
  } while (uVar6 != 3);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026020. Types and names are inferred; NOT original source. */

undefined4 FUN_23026020(void)

{
  thunk_FUN_0e05be20();
  thunk_FUN_0e05be4c();
  FUN_23025848();
  FUN_23026f6c();
  FUN_23025ee0();
  FUN_23026c58();
  FUN_23026e70();
  FUN_230204c0();
  FUN_23020680();
  return 0;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302604c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_2302604c(uint param_1)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  uint3 uVar4;
  byte bVar5;
  byte bVar6;
  undefined4 uVar7;
  char cVar8;
  int iVar9;
  uint uVar10;
  
  cVar8 = DAT_230071bd;
  cVar1 = DAT_23002d24;
  bVar3 = DAT_23002d25;
  uVar2 = _DAT_23002d24;
  bVar5 = DAT_23002d26;
  bVar6 = DAT_23002d27;
  if (DAT_23002d22 < 0x11) {
    uVar4 = _DAT_23002d25;
    switch(DAT_23002d22) {
    case 0:
      goto LAB_2302617c;
    default:
      return param_1;
    case 7:
      if (DAT_23002d23 == 0x95) {
        DAT_23002d1c = 2;
        _DAT_23002d24 = CONCAT12(DAT_23002cb6,_DAT_23002cb4);
        _DAT_23002d24 = CONCAT13(bVar6,_DAT_23002d24);
        return param_1;
      }
      if (DAT_23002d23 < 0x96) {
        if (DAT_23002d23 == 0x15) {
          uVar10 = _DAT_23002d24 & 0xff;
          if (((uVar10 < 5) && (bVar3 < 5)) && (bVar5 < 5)) {
            _DAT_23002cb4 = uVar2;
            DAT_23002cb6 = bVar5;
            if (((DAT_23002d90._1_1_ != uVar10) || (DAT_23002d90._2_1_ != bVar3)) ||
               (DAT_23002d90._3_1_ != bVar5)) {
              DAT_23002d90._1_2_ = uVar2;
              DAT_23002d90._3_1_ = bVar5;
              FUN_23026f30(2);
            }
            uVar10 = FUN_23025a44();
            DAT_23002d1c = 2;
            return uVar10;
          }
          DAT_23002d1c = 3;
          return uVar10;
        }
        if (DAT_23002d23 == 0x17) {
          if (((DAT_23002da8._2_1_ != cVar1) || (DAT_23002da8._2_2_ >> 8 != uVar2 >> 8)) ||
             (uVar10 = (uint)(byte)DAT_23002dac, uVar10 != bVar5)) {
            DAT_23002da8._2_2_ = uVar2;
            DAT_23002dac._0_1_ = bVar5;
            uVar10 = FUN_23026f30(2);
          }
          DAT_23002d1c = 2;
          return uVar10;
        }
      }
      else {
        if (DAT_23002d23 == 0x96) {
          DAT_23002d1c = 2;
          _DAT_23002d24 = CONCAT31(uVar4,DAT_230071b3);
          return param_1;
        }
        if (DAT_23002d23 == 0x97) {
          DAT_23002d1c = 2;
          _DAT_23002d24 = CONCAT12((byte)DAT_23002dac,DAT_23002da8._2_2_);
          _DAT_23002d24 = CONCAT13(bVar6,_DAT_23002d24);
        }
      }
      return param_1;
    case 0xf:
      DAT_23002d1c = 2;
      return param_1;
    case 0x10:
      uVar10 = (*(code *)0xe05be8d)();
      return uVar10;
    }
  }
  if (DAT_23002d22 != 0xfe) {
    return param_1;
  }
  if ((char)DAT_23002d23 < '\0') {
    if (0xf0 < DAT_23002d23) {
      switch(DAT_23002d23) {
      case 0xf1:
        FUN_23020530(&DAT_23002d24);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_230266b0();
        return uVar10;
      case 0xf3:
        if (DAT_23002d1d >> 5 == 7) {
          _DAT_23002d24 = DAT_23002d94;
          DAT_23002d30 = DAT_23002da0;
          _DAT_23002d28 = DAT_23002d98;
          DAT_23002d2c = DAT_23002d9c;
          DAT_23002d34 = DAT_23002da4;
          DAT_23002d38 = (undefined2)DAT_23002da8;
          goto LAB_2302680e;
        }
        break;
      case 0xfa:
        DAT_23002d1c = 2;
        _DAT_23002d24 = _DAT_0fffe014;
        _DAT_23002d28 = _DAT_0fffe010;
        uVar10 = ram_candidate_230266b0();
        return uVar10;
      case 0xfb:
        FUN_23020a34(&DAT_23002d24);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_230266b0();
        return uVar10;
      case 0xff:
        FUN_230204b8(&DAT_23002d24);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_230266b0();
        return uVar10;
      }
    }
    return 1;
  }
  if (0x6f < DAT_23002d23) {
    switch(DAT_23002d23) {
    case 0x70:
      FUN_2302048c(&DAT_23002d24);
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_230266b0();
      return uVar10;
    case 0x71:
      FUN_23020510(&DAT_23002d24);
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_230266b0();
      return uVar10;
    case 0x72:
      thunk_FUN_23024db4((_DAT_23002d24 & 0xff) << 8 | (uint)(_DAT_23002d24 >> 8));
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_230266b0();
      return uVar10;
    case 0x73:
      goto ram_candidate_230267e2;
    default:
      return 1;
    case 0x7f:
      thunk_FUN_23020fec(&DAT_23002d24);
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_230266b0();
      return uVar10;
    }
  }
  if (DAT_23002d23 != 0x33) {
    return 1;
  }
  if (DAT_23002d1d >> 5 != 7) {
    return 1;
  }
  if (DAT_230071bd != '\x02') {
    DAT_23002d1c = 3;
    uVar10 = ram_candidate_230266b0();
    return uVar10;
  }
  DAT_230071b2 = '\x01';
  if ((_DAT_23002d24 & 0xff) != 0) {
    FUN_23025fe0();
    DAT_23002d1c = cVar8;
    uVar10 = ram_candidate_230266b0();
    return uVar10;
  }
  if (bVar3 == 0xff) {
    if (DAT_23002d26 == 0) {
      if (DAT_23002d27 == 0) {
        FUN_23025954(2);
        goto LAB_2302680e;
      }
    }
    else if ((DAT_23002d26 & DAT_23002d27) == 0xff) {
      FUN_23025954(1);
      goto LAB_2302680e;
    }
  }
  else if (bVar3 == 0) {
    if (DAT_23002d26 == 0xff) {
      if (DAT_23002d27 == 0) {
        FUN_23025954(3);
        goto LAB_2302680e;
      }
    }
    else if ((DAT_23002d26 == 0) && (DAT_23002d27 == 0xff)) {
      FUN_23025954(4);
      goto LAB_2302680e;
    }
  }
  FUN_23025954(0);
LAB_2302680e:
  DAT_23002d1c = 2;
  uVar10 = ram_candidate_230266b0();
  return uVar10;
ram_candidate_230267e2:
  if (DAT_23002d1d >> 5 != 7) {
    return 1;
  }
  DAT_23002d94 = _DAT_23002d24;
  DAT_23002da0 = DAT_23002d30;
  DAT_23002d98 = _DAT_23002d28;
  DAT_23002d9c = DAT_23002d2c;
  DAT_23002da4 = DAT_23002d34;
  DAT_23002da8._0_2_ = DAT_23002d38;
  FUN_23026f30(2);
  goto LAB_2302680e;
LAB_2302617c:
  if (0xc6 < DAT_23002d23) {
    return 1;
  }
  if (DAT_23002d23 < 0x8d) {
    if (DAT_23002d23 < 0x16) {
      if (DAT_23002d23 < 4) {
        return 1;
      }
      switch(DAT_23002d23) {
      case 4:
        if (DAT_23002d1d >> 5 != 7) {
          return 1;
        }
        DAT_230071bd = cVar1;
        if ((((_DAT_23002d24 & 0xff) == 0) || ((_DAT_23002d24 & 0xff) == 3)) &&
           (DAT_230071b2 != '\0')) {
          iVar9 = FUN_230204ac();
          if (iVar9 == 0) {
            FUN_23025954();
          }
          else {
            FUN_23025a44();
          }
          DAT_230071b2 = '\0';
        }
        break;
      default:
        goto code_r0x23026216;
      case 0xb:
        uVar10 = _DAT_23002d24 & 0xff;
        if (uVar10 == 1) {
          FUN_23026f68();
          thunk_FUN_23025300(ram0x23002d8b << 0x18 | (ram0x23002d8b >> 8 & 0xff) << 0x10 |
                             (ram0x23002d8b >> 0x10 & 0xff) << 8 | ram0x23002d8b >> 0x18);
          uVar10 = ram_candidate_23026216();
          return uVar10;
        }
        if (uVar10 != 3) {
          if (uVar10 != 5) {
            return 1;
          }
          FUN_23020608(0x2ee);
          DAT_23002d1c = 2;
          uVar10 = ram_candidate_23026216();
          return uVar10;
        }
        DAT_23002d80._2_2_ = 0xffff;
        FUN_23026f30(2);
        FUN_23020608(0x2ee);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_23026216();
        return uVar10;
      case 0xd:
        DAT_23002db5 = _DAT_23002d24;
        FUN_23026f30(4);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_23026216();
        return uVar10;
      case 0x12:
        DAT_23002db9 = _DAT_23002d24;
        DAT_23002dbd = _DAT_23002d28;
        DAT_23002dc1 = DAT_23002d2c;
        DAT_23002dc5 = DAT_23002d30;
        DAT_23002dc9 = DAT_23002d34;
        FUN_23026f30(4);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_23026216();
        return uVar10;
      case 0x15:
        if (((((DAT_23002dcf & 0xff) != (_DAT_23002d24 & 0xff)) ||
             ((DAT_23002dcf >> 8 & 0xff) != (_DAT_23002d24 & 0xffff) >> 8)) ||
            ((DAT_23002dcf >> 0x10 & 0xff) != (_DAT_23002d24 & 0xffffff) >> 0x10)) ||
           (DAT_23002dcf >> 0x18 != _DAT_23002d24 >> 0x18)) {
          DAT_23002dcf = _DAT_23002d24;
          ram0x23002d8b = _DAT_23002d24;
          if (0xfffffffc < _DAT_23002d24 - 1 && _DAT_23002d24 != 0xfffffffe) {
            register0x0000002c =
                 _DAT_0fffe010 >> 0x18 | ((_DAT_0fffe010 & 0xffffff) >> 0x10) << 8 |
                 ((_DAT_0fffe010 & 0xffff) >> 8) << 0x10 | _DAT_0fffe010 << 0x18;
            DAT_23002dcf = CONCAT13((char)_DAT_0fffe010,
                                    CONCAT12((char)(_DAT_0fffe010 >> 8),
                                             CONCAT11((char)(_DAT_0fffe010 >> 0x10),
                                                      (char)(_DAT_0fffe010 >> 0x18))));
          }
          FUN_23026f30(4);
          FUN_23026f30(2);
          thunk_FUN_230252a4(DAT_23002dcf << 0x18 | (DAT_23002dcf >> 8 & 0xff) << 0x10 |
                             (DAT_23002dcf >> 0x10 & 0xff) << 8 | DAT_23002dcf >> 0x18);
        }
      }
    }
    else {
      if (DAT_23002d23 == 0x45) {
        if ((_DAT_23002d24 & 0xff) == 1) {
          DAT_23002dd3 = cVar1;
          DAT_23002d80._2_2_ = _DAT_23002d25;
          DAT_23002d1c = 2;
          FUN_23026f30(4);
          FUN_23026f30(2);
          uVar10 = ram_candidate_23026216();
          return uVar10;
        }
        if ((_DAT_23002d24 & 0xff) != 2) {
          return 1;
        }
        DAT_23002dd3 = cVar1;
        DAT_23002d84._0_2_ = _DAT_23002d25;
        DAT_23002d1c = cVar1;
        FUN_23026f30(4);
        FUN_23026f30(2);
        uVar10 = ram_candidate_23026216();
        return uVar10;
      }
      if (DAT_23002d23 != 0x46) {
        if (DAT_23002d23 != 0x3c) {
          return 1;
        }
        DAT_23002db3 = uVar2;
        FUN_23026f30(4);
        DAT_23002d1c = 2;
        uVar10 = ram_candidate_23026216();
        return uVar10;
      }
    }
    goto switchD_23026190_caseD_c6;
  }
  switch(DAT_23002d23) {
  case 0x8d:
    DAT_23002d1c = 2;
    _DAT_23002d24 = DAT_23002db5;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  default:
    goto code_r0x23026216;
  case 0x91:
    DAT_23002d1c = 2;
    _DAT_23002d24 = CONCAT22(_DAT_23002d26,0x1401);
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0x92:
    _DAT_23002d24 = DAT_23002db9;
    DAT_23002d2c = DAT_23002dc1;
    _DAT_23002d28 = DAT_23002dbd;
    DAT_23002d30 = DAT_23002dc5;
    DAT_23002d34 = DAT_23002dc9;
    break;
  case 0x93:
    DAT_23002d1c = 2;
    _DAT_23002d24 = 0x1401;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0x95:
    _DAT_23002d24 = DAT_23002dcf;
    _DAT_23002d28 = ram0x23002d8b;
    DAT_23002d1c = 2;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0x9f:
    _DAT_23002d24 = CONCAT12(DAT_0000f008,CONCAT11(DAT_0000f004,DAT_0000f000));
    _DAT_23002d24 = CONCAT13(DAT_0000f00c,_DAT_23002d24);
    DAT_23002d1c = 2;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xb8:
    _DAT_23002d24 = (uint)uVar4 << 8;
    iVar9 = FUN_230204ac();
    if (iVar9 << 0x1e < 0) {
      _DAT_23002d24 = _DAT_23002d24 | 1;
    }
    iVar9 = FUN_230204ac();
    if (iVar9 << 0x1d < 0) {
      _DAT_23002d24 = _DAT_23002d24 | 2;
    }
    break;
  case 0xba:
    _DAT_23002d24 = CONCAT31(uVar4,2);
    iVar9 = FUN_230204ac();
    _DAT_23002d24 = CONCAT11((byte)((uint)(iVar9 << 0x1e) >> 0x1f),DAT_23002d24);
    iVar9 = FUN_230204ac();
    DAT_23002d1c = 2;
    _DAT_23002d24 = CONCAT12((byte)((uint)(iVar9 << 0x1d) >> 0x1f),_DAT_23002d24);
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xbc:
    DAT_23002d1c = 2;
    _DAT_23002d24 = CONCAT22(_DAT_23002d26,DAT_23002db3);
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xbf:
    _DAT_23002d24 = CONCAT31(uVar4,2);
    iVar9 = FUN_230204ac();
    _DAT_23002d24 = CONCAT11((byte)((uint)(iVar9 << 0x1e) >> 0x1f),DAT_23002d24);
    _DAT_23002d24 = CONCAT12(DAT_23002d80._2_1_,_DAT_23002d24);
    _DAT_23002d24 = CONCAT13(DAT_23002d80._3_1_,_DAT_23002d24);
    iVar9 = FUN_230204ac();
    uVar7 = _DAT_23002d28;
    DAT_23002d28_1._2_1_ = SUB41(uVar7,3);
    _DAT_23002d28 = CONCAT12(DAT_23002d84._1_1_,(short)DAT_23002d84 << 8);
    DAT_23002d1c = 2;
    _DAT_23002d28 = CONCAT31(_DAT_23002d29,(byte)((uint)(iVar9 << 0x1d) >> 0x1f));
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xc3:
    _DAT_23002d24 = 0;
    DAT_23002d1c = 2;
    uVar10 = ram_candidate_23026216();
    return uVar10;
  case 0xc5:
    if (DAT_23002dd3 == '\x01') {
      _DAT_23002d24 = CONCAT11(DAT_23002d80._2_1_,1);
      _DAT_23002d24 = CONCAT12(DAT_23002d80._3_1_,_DAT_23002d24);
      _DAT_23002d24 = CONCAT13(bVar6,_DAT_23002d24);
      DAT_23002d1c = 2;
      uVar10 = ram_candidate_23026216();
      return uVar10;
    }
    if (DAT_23002dd3 == '\x02') {
      _DAT_23002d24 = CONCAT11((undefined1)DAT_23002d84,2);
      _DAT_23002d24 = CONCAT12(DAT_23002d84._1_1_,_DAT_23002d24);
      _DAT_23002d24 = CONCAT13(bVar6,_DAT_23002d24);
      DAT_23002d1c = DAT_23002dd3;
      uVar10 = ram_candidate_23026216();
      return uVar10;
    }
    goto code_r0x23026216;
  case 0xc6:
    break;
  }
switchD_23026190_caseD_c6:
  DAT_23002d1c = 2;
code_r0x23026216:
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026090. Types and names are inferred; NOT original source. */

void FUN_23026090(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  
  if (DAT_230071bb != '\0') {
    pbVar5 = &DAT_23002d1d;
    pbVar3 = &DAT_23002d1d;
    bVar1 = 0;
    do {
      bVar4 = bVar1;
      pbVar3 = pbVar3 + 1;
      bVar1 = bVar4 ^ *pbVar3;
    } while (pbVar3 != &DAT_23002d74);
    if (*pbVar3 == bVar4) {
      bVar1 = DAT_23002d1d >> 5;
      if (bVar1 == 0) {
        iVar6 = 1;
      }
      else if (bVar1 == 4) {
        iVar6 = 2;
      }
      else if (bVar1 == 7) {
        iVar6 = 0;
      }
      else {
        iVar6 = 0xff;
      }
      FUN_2302604c();
      if (DAT_23002d1c == '\x01') {
        iVar2 = FUN_230204ac();
        if ((iVar2 >> iVar6 & 1U) == 0) {
          DAT_23002d1c = '\x04';
          DAT_23002d74 = 0;
          do {
            pbVar5 = pbVar5 + 1;
            DAT_23002d74 = DAT_23002d74 ^ *pbVar5;
          } while (pbVar5 != (byte *)0x23002d73);
        }
        else if (iVar6 - 1U < 2) {
          uVar7 = (uint)DAT_23002d21;
          DAT_23002cb9 = DAT_23002d74;
          DAT_23002cb8 = 0x5a;
          thunk_FUN_0e06f35c(&DAT_23002cba,&DAT_23002d1c,uVar7 + 8);
          FUN_230205c8(iVar6,&DAT_23002cb8,uVar7 + 10);
        }
        else {
          DAT_23002d74 = 0;
          DAT_23002d1c = '\x03';
          do {
            pbVar5 = pbVar5 + 1;
            DAT_23002d74 = DAT_23002d74 ^ *pbVar5;
          } while (pbVar5 != (byte *)0x23002d73);
        }
      }
      else {
        DAT_23002d74 = 0;
        do {
          pbVar5 = pbVar5 + 1;
          DAT_23002d74 = DAT_23002d74 ^ *pbVar5;
        } while (pbVar5 != (byte *)0x23002d73);
      }
    }
    else {
      DAT_23002d1c = '\x03';
    }
    DAT_230071bb = '\0';
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026216. Types and names are inferred; NOT original source. */

undefined4 ram_candidate_23026216(void)

{
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026290. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_23026290(void)

{
  uint uVar1;
  undefined1 *unaff_r4;
  
  uVar1 = *(uint *)(unaff_r4 + 8);
  if (((((DAT_23002dcf & 0xff) != (uVar1 & 0xff)) ||
       ((DAT_23002dcf >> 8 & 0xff) != (uVar1 & 0xffff) >> 8)) ||
      ((DAT_23002dcf >> 0x10 & 0xff) != (uVar1 & 0xffffff) >> 0x10)) ||
     (DAT_23002dcf >> 0x18 != uVar1 >> 0x18)) {
    unique0x10000095 = uVar1;
    DAT_23002dcf = uVar1;
    if (0xfffffffc < uVar1 - 1 && uVar1 != 0xfffffffe) {
      register0x0000002c =
           _DAT_0fffe010 >> 0x18 | ((_DAT_0fffe010 & 0xffffff) >> 0x10) << 8 |
           ((_DAT_0fffe010 & 0xffff) >> 8) << 0x10 | _DAT_0fffe010 << 0x18;
      DAT_23002dcf = CONCAT13((char)_DAT_0fffe010,
                              CONCAT12((char)(_DAT_0fffe010 >> 8),
                                       CONCAT11((char)(_DAT_0fffe010 >> 0x10),
                                                (char)(_DAT_0fffe010 >> 0x18))));
    }
    FUN_23026f30(4);
    FUN_23026f30(2);
    thunk_FUN_230252a4(DAT_23002dcf << 0x18 | (DAT_23002dcf >> 8 & 0xff) << 0x10 |
                       (DAT_23002dcf >> 0x10 & 0xff) << 8 | DAT_23002dcf >> 0x18);
  }
  *unaff_r4 = 2;
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026300. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23026300(void)

{
  DAT_23002db9 = _DAT_23002d24;
  DAT_23002dbd = _DAT_23002d28;
  DAT_23002dc1 = DAT_23002d2c;
  DAT_23002dc5 = DAT_23002d30;
  DAT_23002dc9 = DAT_23002d34;
  FUN_23026f30(4);
  DAT_23002d1c = 2;
  ram_candidate_23026216();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026326. Types and names are inferred; NOT original source. */

void ram_candidate_23026326(void)

{
  undefined1 *unaff_r4;
  
  DAT_23002db5 = *(undefined4 *)(unaff_r4 + 8);
  FUN_23026f30(4);
  *unaff_r4 = 2;
  ram_candidate_23026216();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302633a. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_2302633a(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 *unaff_r4;
  
  cVar1 = unaff_r4[8];
  if (cVar1 == '\x01') {
    FUN_23026f68();
    thunk_FUN_23025300(ram0x23002d8b << 0x18 | (ram0x23002d8b >> 8 & 0xff) << 0x10 |
                       (ram0x23002d8b >> 0x10 & 0xff) << 8 | ram0x23002d8b >> 0x18);
    uVar2 = ram_candidate_23026216();
    return uVar2;
  }
  if (cVar1 != '\x03') {
    if (cVar1 == '\x05') {
      FUN_23020608(0x2ee);
      *unaff_r4 = 2;
      uVar2 = ram_candidate_23026216();
      return uVar2;
    }
    return 1;
  }
  DAT_23002d80._2_2_ = 0xffff;
  FUN_23026f30(2);
  FUN_23020608(0x2ee);
  *unaff_r4 = 2;
  uVar2 = ram_candidate_23026216();
  return uVar2;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302635c. Types and names are inferred; NOT original source. */

undefined4 ram_candidate_2302635c(void)

{
  int iVar1;
  undefined1 *unaff_r4;
  
  if ((byte)unaff_r4[1] >> 5 == 7) {
    DAT_230071bd = unaff_r4[8];
    if (((DAT_230071bd == '\0') || (DAT_230071bd == '\x03')) && (DAT_230071b2 != '\0')) {
      iVar1 = FUN_230204ac();
      if (iVar1 == 0) {
        FUN_23025954();
      }
      else {
        FUN_23025a44();
      }
      DAT_230071b2 = '\0';
    }
    *unaff_r4 = 2;
  }
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230266b0. Types and names are inferred; NOT original source. */

undefined4 ram_candidate_230266b0(void)

{
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302674c. Types and names are inferred; NOT original source. */

void ram_candidate_2302674c(void)

{
  FUN_230204b8(&DAT_23002d24);
  DAT_23002d1c = 2;
  ram_candidate_230266b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302675c. Types and names are inferred; NOT original source. */

void ram_candidate_2302675c(void)

{
  FUN_23020530(&DAT_23002d24);
  DAT_23002d1c = 2;
  ram_candidate_230266b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 2302676c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_2302676c(void)

{
  undefined4 uVar1;
  undefined1 *unaff_r4;
  
  uVar1 = DAT_23002da0;
  if ((byte)unaff_r4[1] >> 5 == 7) {
    *(undefined4 *)(unaff_r4 + 8) = DAT_23002d94;
    DAT_23002d30 = uVar1;
    _DAT_23002d28 = DAT_23002d98;
    DAT_23002d2c = DAT_23002d9c;
    DAT_23002d34 = DAT_23002da4;
    DAT_23002d38 = (undefined2)DAT_23002da8;
    *unaff_r4 = 2;
    uVar1 = ram_candidate_230266b0();
    return uVar1;
  }
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026792. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23026792(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *unaff_r4;
  
  uVar2 = _DAT_0fffe014;
  uVar1 = _DAT_0fffe010;
  *unaff_r4 = 2;
  *(undefined4 *)(unaff_r4 + 8) = uVar2;
  *(undefined4 *)(unaff_r4 + 0xc) = uVar1;
  ram_candidate_230266b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230267a2. Types and names are inferred; NOT original source. */

void ram_candidate_230267a2(void)

{
  FUN_23020a34(&DAT_23002d24);
  DAT_23002d1c = 2;
  ram_candidate_230266b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230267b2. Types and names are inferred; NOT original source. */

void ram_candidate_230267b2(void)

{
  FUN_2302048c(&DAT_23002d24);
  DAT_23002d1c = 2;
  ram_candidate_230266b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230267c2. Types and names are inferred; NOT original source. */

void ram_candidate_230267c2(void)

{
  FUN_23020510(&DAT_23002d24);
  DAT_23002d1c = 2;
  ram_candidate_230266b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230267d2. Types and names are inferred; NOT original source. */

void ram_candidate_230267d2(void)

{
  undefined1 *unaff_r4;
  
  thunk_FUN_23024db4(*(ushort *)(unaff_r4 + 8) << 8 | *(ushort *)(unaff_r4 + 8) >> 8);
  *unaff_r4 = 2;
  ram_candidate_230266b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230267e2. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 ram_candidate_230267e2(void)

{
  undefined4 uVar1;
  undefined1 *unaff_r4;
  
  if ((byte)unaff_r4[1] >> 5 == 7) {
    DAT_23002d94 = *(undefined4 *)(unaff_r4 + 8);
    DAT_23002da0 = DAT_23002d30;
    DAT_23002d98 = _DAT_23002d28;
    DAT_23002d9c = DAT_23002d2c;
    DAT_23002da4 = DAT_23002d34;
    DAT_23002da8._0_2_ = DAT_23002d38;
    FUN_23026f30(2);
    *unaff_r4 = 2;
    uVar1 = ram_candidate_230266b0();
    return uVar1;
  }
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026814. Types and names are inferred; NOT original source. */

void ram_candidate_23026814(void)

{
  thunk_FUN_23020fec(&DAT_23002d24);
  DAT_23002d1c = 2;
  ram_candidate_230266b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230268b0. Types and names are inferred; NOT original source. */

char FUN_230268b0(int param_1)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  cVar1 = DAT_230071e4;
  if (DAT_230071e4 != '\0') {
    uVar4 = (uint)(byte)(&DAT_2300048c)[param_1];
    uVar2 = (uint)*(byte *)((int)&DAT_23006838 + uVar4);
    uVar3 = uVar2 + 1 & 0xff;
    if (uVar3 == 4) {
      if (*(byte *)((int)&DAT_23006834 + uVar4) != 0) {
        thunk_FUN_0e06f35c(&DAT_2300683c +
                           ((short)(ushort)(byte)(&DAT_2300048c)[param_1] * 4 + 3) * 0x10);
        *(undefined1 *)((int)&DAT_23006838 + uVar4) = 0;
        return cVar1;
      }
    }
    else if (uVar3 != *(byte *)((int)&DAT_23006834 + uVar4)) {
      if (uVar2 < 4) {
        thunk_FUN_0e06f35c(&DAT_2300683c + (uVar2 + uVar4 * 4) * 0x10);
        *(char *)((int)&DAT_23006838 + uVar4) = (char)(uVar2 + 1);
        return cVar1;
      }
      DAT_23006838 = 0;
      DAT_2300683a = 0;
      DAT_23006834 = 0;
      DAT_23006836 = 0;
    }
  }
  return '\0';
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026928. Types and names are inferred; NOT original source. */

void FUN_23026928(int param_1)

{
  *(undefined1 *)((int)&DAT_23006904 + param_1) = 0;
  *(undefined1 *)((int)&DAT_23006838 + param_1) = 0;
  *(undefined1 *)((int)&DAT_23006834 + param_1) = 0;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026ad8. Types and names are inferred; NOT original source. */

undefined4 FUN_23026ad8(void)

{
  undefined4 uVar1;
  
  if ((DAT_230071e3 == '\0') && (DAT_230071e6 == '\x03')) {
    uVar1 = thunk_FUN_0e0622bc(DAT_2300690c);
    DAT_230071e3 = 1;
    return uVar1;
  }
  return 0xffffffff;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026b08. Types and names are inferred; NOT original source. */

void ram_candidate_23026b08(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  
  switch(*param_2) {
  case 0:
    iVar1 = thunk_FUN_0e06245c();
    if (iVar1 != 0) {
      thunk_FUN_0e0623ac(param_1);
    }
    DAT_23006904._0_1_ = 0;
    DAT_230071e6 = 0;
    DAT_23006838 = 0;
    DAT_2300683a = 0;
    DAT_23006834 = 0;
    DAT_23006836 = 0;
    DAT_230071e3 = 0;
    return;
  case 1:
    iVar1 = thunk_FUN_0e06245c();
    if (iVar1 != 0) {
      thunk_FUN_0e062414(param_1);
    }
    DAT_230071e6 = 1;
    return;
  case 2:
    DAT_23006908 = 0;
    DAT_2300690a = 0;
    DAT_23006900 = 0;
    DAT_230071e3 = 0;
    DAT_23006902 = 0;
    FUN_230206e4();
    DAT_230071e6 = 2;
    return;
  case 3:
    DAT_23006900 = 0;
    DAT_230071e3 = 0;
    DAT_23006908 = 0;
    DAT_23006902 = 0;
    DAT_2300690a = 0;
    FUN_2302070c();
    DAT_230071e6 = 3;
    break;
  case 4:
    DAT_230071e4 = 0;
    DAT_230071e3 = 0;
    DAT_23006900 = 0;
    DAT_23006908 = 0;
    DAT_23006902 = 0;
    DAT_2300690a = 0;
    FUN_230206c4();
    DAT_230071e6 = 4;
    break;
  case 5:
    DAT_230071e3 = 0;
    DAT_230071e4 = 1;
    DAT_23002c82 = 1;
    FUN_2302539c(0x29);
    thunk_FUN_0e06ddc4(&DAT_23001ea0);
    FUN_23025b40(0xff,0);
    return;
  default:
    goto switchD_23026b12_default;
  }
  DAT_23006838 = 0;
  DAT_23006904._0_1_ = 0;
  DAT_2300683a = 0;
  DAT_23006834 = 0;
  DAT_23006836 = 0;
switchD_23026b12_default:
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026bfc. Types and names are inferred; NOT original source. */

undefined4 ram_candidate_23026bfc(void)

{
  return DAT_230068fc;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026c08. Types and names are inferred; NOT original source. */

undefined4
ram_candidate_23026c08
          (undefined **param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  if (param_2 != 3) {
    return 0xffffff7a;
  }
  if ((param_1 == &PTR_s_hid_dev_0_0e06f6a4) && (param_4 == 0x5a)) {
    thunk_FUN_0e06f35c(param_5,&DAT_23002d1c,0x62);
    return 0x5a;
  }
  return 0xffffff7a;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026c3c. Types and names are inferred; NOT original source. */

void ram_candidate_23026c3c(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    return;
  }
  DAT_230071e5 = thunk_FUN_0e062244(DAT_2300690c);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026c58. Types and names are inferred; NOT original source. */

undefined4 FUN_23026c58(void)

{
  int iVar1;
  undefined4 in_r3;
  int iVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  
  iVar2 = 0;
  DAT_23006900 = 0;
  DAT_23006902 = 0;
  DAT_230071e4 = 0;
  ppuVar4 = &PTR_ram_candidate_23026c3c_1_23000420;
  puVar3 = &DAT_0e06fd34;
  DAT_23006904 = 0;
  DAT_23006908 = 0;
  DAT_23006906 = 0;
  DAT_2300690a = 0;
  DAT_230071e6 = 1;
  while( true ) {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    if ((&DAT_0e06fd1c)[iVar1] == 0) {
      return 1;
    }
    iVar1 = thunk_FUN_0e06450c((&DAT_0e06fd1c)[iVar1],*puVar3,*(undefined2 *)(puVar3 + 1),ppuVar4,
                               in_r3);
    puVar3 = puVar3 + 2;
    ppuVar4 = ppuVar4 + 9;
    if (iVar1 != 0) break;
    if (iVar2 == 3) {
      DAT_2300690c = thunk_FUN_0e05bd18(0x23026b09);
      return 1;
    }
  }
  return 1;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026cd0. Types and names are inferred; NOT original source. */

void ram_candidate_23026cd0(undefined **param_1)

{
  if (param_1 == &PTR_s_hid_dev_0_0e06f6a4) {
    if ((char)DAT_23006904 != '\0') {
      DAT_23006904._0_1_ = (char)DAT_23006904 + -1;
      return;
    }
  }
  else {
    if (param_1 == &PTR_s_hid_dev_1_0e06f690) {
      DAT_23006900._1_1_ = 0;
      DAT_23006908._1_1_ = 0;
      return;
    }
    if (param_1 == &PTR_s_hid_dev_2_0e06f67c) {
      DAT_23006902 = 0;
      DAT_2300690a = 0;
      return;
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026d28. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ram_candidate_23026d28(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  
  bVar1 = (byte)DAT_23006904;
  iVar6 = 0x15;
  do {
    _DAT_5f9a2048 = 1;
    if ((0x44 < _DAT_5f9a2548 - 1U) || ((byte)DAT_23006838 != (byte)DAT_23006834)) break;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  puVar5 = (undefined4 *)0x23001e80;
  if ((DAT_23006830 & 1) == 0) {
    puVar5 = &DAT_23001e60;
  }
  bVar2 = DAT_23006902;
  bVar3 = DAT_2300690a;
  if (DAT_230071e4 != '\0') {
    if (((byte)DAT_23006904 < 2) && (uVar8 = (uint)(byte)DAT_23006834, (byte)DAT_23006838 != uVar8))
    {
      if (uVar8 < 4) {
        uVar4 = *(undefined4 *)(&DAT_23006840 + uVar8 * 0x10);
        *puVar5 = *(undefined4 *)(&DAT_2300683c + uVar8 * 0x10);
        puVar5[1] = uVar4;
        if (bVar1 < 2) {
          DAT_23006904._0_1_ = (byte)DAT_23006904 + 1;
        }
        iVar6 = thunk_FUN_0e064504(&PTR_s_hid_dev_0_0e06f6a4,8);
        if (iVar6 == 0) {
          cVar7 = (byte)DAT_23006834 + '\x01';
          if (cVar7 == '\x04') {
            cVar7 = '\0';
          }
          DAT_23006830 = 1 - DAT_23006830;
          DAT_23006834 = CONCAT11(DAT_23006834._1_1_,cVar7);
        }
        else if ((byte)DAT_23006904 != 0) {
          DAT_23006904._0_1_ = (byte)DAT_23006904 - 1;
        }
      }
      else {
        DAT_23006838 = 0;
        DAT_2300683a = 0;
        DAT_23006834 = 0;
        DAT_23006836 = 0;
      }
    }
    bVar1 = DAT_23006900._1_1_;
    bVar2 = DAT_23006908._1_1_;
    if (DAT_23006900._1_1_ == 0) {
      uVar8 = (uint)DAT_23006834._1_1_;
      if (DAT_23006838._1_1_ != uVar8) {
        if (uVar8 < 4) {
          DAT_23006900._1_1_ = 1;
          iVar6 = (uVar8 + 4) * 0x10;
          DAT_23006908._1_1_ = 3;
          DAT_23001e40 = *(undefined4 *)(&DAT_2300683c + iVar6);
          DAT_23001e44 = *(undefined4 *)(&DAT_23006840 + iVar6);
          DAT_23001e48 = *(undefined4 *)(&DAT_23006844 + iVar6);
          DAT_23001e4c = *(undefined4 *)(&DAT_23006848 + iVar6);
          iVar6 = thunk_FUN_0e064504(&PTR_s_hid_dev_1_0e06f690,0x10,&DAT_23001e40);
          bVar2 = bVar1;
          if (iVar6 == 0) {
            bVar1 = DAT_23006900._1_1_;
            bVar2 = DAT_23006908._1_1_;
            if ((byte)(DAT_23006834._1_1_ + '\x01') == '\x04') {
              DAT_23006834 = DAT_23006834 & 0xff;
            }
            else {
              DAT_23006834 = CONCAT11(DAT_23006834._1_1_ + '\x01',(byte)DAT_23006834);
            }
          }
        }
        else {
          DAT_23006834 = 0;
          DAT_23006836 = bVar1;
          DAT_23006838 = DAT_23006834;
          DAT_2300683a = bVar1;
        }
      }
    }
    DAT_23006908._1_1_ = bVar2;
    DAT_23006900._1_1_ = bVar1;
    bVar2 = DAT_23006902;
    bVar1 = DAT_23006902;
    bVar3 = DAT_2300690a;
    if ((DAT_23006902 == 0) && (uVar8 = (uint)DAT_23006836, DAT_2300683a != uVar8)) {
      if (uVar8 < 4) {
        DAT_23006902 = 1;
        iVar6 = (uVar8 + 8) * 0x10;
        DAT_2300690a = 3;
        DAT_23001e20 = *(undefined4 *)(&DAT_2300683c + iVar6);
        DAT_23001e24 = *(undefined4 *)(&DAT_23006840 + iVar6);
        iVar6 = thunk_FUN_0e064504(&PTR_s_hid_dev_2_0e06f67c,8);
        bVar3 = bVar1;
        if ((iVar6 == 0) &&
           (DAT_23006836 = DAT_23006836 + 1, bVar2 = DAT_23006902, bVar3 = DAT_2300690a,
           DAT_23006836 == 4)) {
          DAT_23006836 = 0;
        }
      }
      else {
        DAT_23006834 = 0;
        DAT_23006836 = bVar1;
        DAT_23006838 = DAT_23006834;
        DAT_2300683a = bVar1;
      }
    }
  }
  DAT_2300690a = bVar3;
  DAT_23006902 = bVar2;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026d68. Types and names are inferred; NOT original source. */

void ram_candidate_23026d68(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_230068fc = param_3;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026d74. Types and names are inferred; NOT original source. */

void ram_candidate_23026d74(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026d78. Types and names are inferred; NOT original source. */

undefined4
ram_candidate_23026d78(undefined **param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  if (param_2 == 3) {
    if ((param_1 == &PTR_s_hid_dev_0_0e06f6a4) && (param_4 == 0x5a)) {
      thunk_FUN_0e06f35c(&DAT_23002d1d,param_5 + 1,0x59);
      DAT_23002d1c = 1;
      DAT_230071bb = 1;
      FUN_230205ec();
      return 0;
    }
  }
  else if ((param_2 == 2) &&
          (((param_1 == &PTR_s_hid_dev_2_0e06f67c && (param_4 == 1)) ||
           ((param_1 == &PTR_s_hid_dev_1_0e06f690 && (param_4 == 2)))))) {
    return 0;
  }
  return 0xffffff7a;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026de0. Types and names are inferred; NOT original source. */

void ram_candidate_23026de0(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 *puVar7;
  char cVar8;
  uint uVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 unaff_r4;
  char *pcVar12;
  
  if (DAT_230071e4 == '\0') {
    return;
  }
  TIMER020_S_TASKS_CAPTURE_7 = 1;
  FUN_23022204();
  pcVar6 = (char *)&DAT_23006908;
  DAT_230071e2 = 1;
  pcVar12 = (char *)&DAT_23006900;
  do {
    pcVar11 = pcVar12 + 1;
    if ((*pcVar12 != '\0') && (cVar8 = *pcVar6, *pcVar6 = cVar8 + -1, (char)(cVar8 + -1) == '\0')) {
      *pcVar12 = '\0';
    }
    bVar1 = (byte)DAT_23006904;
    pcVar6 = pcVar6 + 1;
    pcVar12 = pcVar11;
  } while (pcVar11 != &DAT_23006903);
  if (DAT_230071e6 != '\x03') {
    if ((byte)DAT_23006838 != (byte)DAT_23006834) {
      puVar7 = (undefined4 *)0x23001e80;
      if ((DAT_23006830 & 1) == 0) {
        puVar7 = &DAT_23001e60;
      }
      bVar2 = DAT_23006902;
      bVar3 = DAT_2300690a;
      if (DAT_230071e4 != '\0') {
        if (((byte)DAT_23006904 < 2) &&
           (uVar9 = (uint)(byte)DAT_23006834, (byte)DAT_23006838 != uVar9)) {
          if (uVar9 < 4) {
            puVar10 = (undefined4 *)(&DAT_2300683c + uVar9 * 0x10);
            uVar5 = *(undefined4 *)(&DAT_23006840 + uVar9 * 0x10);
            *puVar7 = *puVar10;
            puVar7[1] = uVar5;
            if (bVar1 < 2) {
              DAT_23006904._0_1_ = (byte)DAT_23006904 + 1;
              puVar10 = (undefined4 *)(uint)(byte)DAT_23006904;
            }
            iVar4 = thunk_FUN_0e064504(&PTR_s_hid_dev_0_0e06f6a4,8,puVar7,puVar10,unaff_r4);
            if (iVar4 == 0) {
              cVar8 = (byte)DAT_23006834 + '\x01';
              if (cVar8 == '\x04') {
                cVar8 = '\0';
              }
              DAT_23006830 = 1 - DAT_23006830;
              DAT_23006834 = CONCAT11(DAT_23006834._1_1_,cVar8);
            }
            else if ((byte)DAT_23006904 != 0) {
              DAT_23006904._0_1_ = (byte)DAT_23006904 - 1;
            }
          }
          else {
            DAT_23006838 = 0;
            DAT_2300683a = 0;
            DAT_23006834 = 0;
            DAT_23006836 = 0;
          }
        }
        bVar1 = DAT_23006900._1_1_;
        bVar2 = DAT_23006908._1_1_;
        if (DAT_23006900._1_1_ == 0) {
          uVar9 = (uint)DAT_23006834._1_1_;
          if (DAT_23006838._1_1_ != uVar9) {
            if (uVar9 < 4) {
              DAT_23006900._1_1_ = 1;
              iVar4 = (uVar9 + 4) * 0x10;
              DAT_23006908._1_1_ = 3;
              DAT_23001e40 = *(undefined4 *)(&DAT_2300683c + iVar4);
              DAT_23001e44 = *(undefined4 *)(&DAT_23006840 + iVar4);
              DAT_23001e48 = *(undefined4 *)(&DAT_23006844 + iVar4);
              DAT_23001e4c = *(undefined4 *)(&DAT_23006848 + iVar4);
              iVar4 = thunk_FUN_0e064504(&PTR_s_hid_dev_1_0e06f690,0x10,&DAT_23001e40,DAT_23001e4c,
                                         unaff_r4);
              bVar2 = bVar1;
              if (iVar4 == 0) {
                bVar1 = DAT_23006900._1_1_;
                bVar2 = DAT_23006908._1_1_;
                if ((byte)(DAT_23006834._1_1_ + '\x01') == '\x04') {
                  DAT_23006834 = DAT_23006834 & 0xff;
                }
                else {
                  DAT_23006834 = CONCAT11(DAT_23006834._1_1_ + '\x01',(byte)DAT_23006834);
                }
              }
            }
            else {
              DAT_23006834 = 0;
              DAT_23006836 = bVar1;
              DAT_23006838 = DAT_23006834;
              DAT_2300683a = bVar1;
            }
          }
        }
        DAT_23006908._1_1_ = bVar2;
        DAT_23006900._1_1_ = bVar1;
        bVar2 = DAT_23006902;
        bVar1 = DAT_23006902;
        bVar3 = DAT_2300690a;
        if ((DAT_23006902 == 0) && (uVar9 = (uint)DAT_23006836, DAT_2300683a != uVar9)) {
          if (uVar9 < 4) {
            DAT_23006902 = 1;
            iVar4 = (uVar9 + 8) * 0x10;
            DAT_2300690a = 3;
            DAT_23001e20 = *(undefined4 *)(&DAT_2300683c + iVar4);
            DAT_23001e24 = *(undefined4 *)(&DAT_23006840 + iVar4);
            iVar4 = thunk_FUN_0e064504(&PTR_s_hid_dev_2_0e06f67c,8,&DAT_23001e20,
                                       &DAT_2300683c + iVar4,unaff_r4);
            bVar3 = bVar1;
            if ((iVar4 == 0) &&
               (DAT_23006836 = DAT_23006836 + 1, bVar2 = DAT_23006902, bVar3 = DAT_2300690a,
               DAT_23006836 == 4)) {
              DAT_23006836 = 0;
            }
          }
          else {
            DAT_23006834 = 0;
            DAT_23006836 = bVar1;
            DAT_23006838 = DAT_23006834;
            DAT_2300683a = bVar1;
          }
        }
      }
      DAT_2300690a = bVar3;
      DAT_23006902 = bVar2;
      return;
    }
    FUN_0e06d5c8(&DAT_23002170,&DAT_23002220,0x32,0);
    return;
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026e70. Types and names are inferred; NOT original source. */

void FUN_23026e70(void)

{
  thunk_FUN_0e06d5b0(&DAT_23002220,0x23026d29);
  thunk_FUN_0e06d530(&DAT_23002170,&DAT_23010400,0x400,0xfffffff0,0);
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026ea4. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23026ea4(void)

{
  int iVar1;
  undefined4 in_r3;
  uint uVar2;
  
  uVar2 = (uint)DAT_230071ba;
  if ((uVar2 != 0) && (DAT_2300719e == 0)) {
    if ((int)(uVar2 << 0x1e) < 0) {
      DAT_23002db0 = 0x46;
      DAT_23002df4 = ram_candidate_23020000(&DAT_23002db0,0x44,0,uVar2,in_r3);
      iVar1 = FUN_23025924(0,0xa001,&DAT_23002db0,0x46);
      uVar2 = (uint)DAT_230071ba;
      if (iVar1 != 0) {
        uVar2 = uVar2 & 0xfd;
        DAT_230071ba = (byte)uVar2;
      }
    }
    if ((int)(uVar2 << 0x1f) < 0) {
      DAT_23002d80._0_2_ = 0x2f;
      register0x00000020 = ram_candidate_23020000(&DAT_23002d80,0x2d,0,uVar2 << 0x1f,in_r3);
      iVar1 = FUN_23025924(1,0xa002,&DAT_23002d80,0x2f);
      if (iVar1 != 0) {
        DAT_230071ba = DAT_230071ba & 0xfe;
        return;
      }
    }
  }
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026f30. Types and names are inferred; NOT original source. */

void FUN_23026f30(int param_1)

{
  if (param_1 == 4) {
    DAT_2300719e = 0;
    DAT_230071ba = DAT_230071ba | 2;
    return;
  }
  if (param_1 != 2) {
    return;
  }
  DAT_2300719e = 0;
  DAT_230071ba = DAT_230071ba | 1;
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026f68. Types and names are inferred; NOT original source. */

void FUN_23026f68(void)

{
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23026f6c. Types and names are inferred; NOT original source. */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_23026f6c(void)

{
  uint uVar1;
  uint uVar2;
  
  FUN_230258fc(0,0xa001,&DAT_23002db0,0x46);
  if ((DAT_23002db0 != 0x46) ||
     (uVar2 = (uint)DAT_23002df4, uVar1 = ram_candidate_23020000(&DAT_23002db0,0x44,0),
     uVar2 != uVar1)) {
    thunk_FUN_0e06f35c(&DAT_23002db0,&DAT_0e06fa28,0x46);
  }
  FUN_230258fc(1,0xa002,&DAT_23002d80,0x2f);
  if ((DAT_23002d80 & 0xffff) == 0x2f) {
    uVar2 = (uint)ram0x23002dad;
    uVar1 = ram_candidate_23020000(&DAT_23002d80,0x2d,0);
    if (uVar2 == uVar1) goto LAB_23027002;
  }
  DAT_23002d80 = 0xffff002f;
  DAT_23002d84 = 0x102ffff;
  DAT_23002d88 = 0xff000101;
  DAT_23002d8c = 0xffffff;
  DAT_23002d90 = 0x3010200;
  _DAT_23002dac = 0x46;
  DAT_23002da8 = CONCAT22(0x3c32,(short)DAT_23002da8);
LAB_23027002:
  if (0xfffffffd < DAT_23002dcf - 1U) {
    DAT_23002dcf = CONCAT13((char)_DAT_0fffe010,
                            CONCAT12((char)((uint)_DAT_0fffe010 >> 8),
                                     CONCAT11((char)((uint)_DAT_0fffe010 >> 0x10),
                                              (char)((uint)_DAT_0fffe010 >> 0x18))));
    DAT_230071ba = DAT_230071ba | 2;
    DAT_2300719e = 0;
  }
  if (0xfffffffd < CONCAT31((undefined3)DAT_23002d8c,DAT_23002d88._3_1_) - 1U) {
    DAT_23002d88._3_1_ = (undefined1)DAT_23002dcf;
    DAT_23002d8c._0_3_ = (undefined3)((uint)DAT_23002dcf >> 8);
    DAT_2300719e = 0;
    DAT_230071ba = DAT_230071ba | 1;
  }
  if (((_DAT_0fffe014 == 0xc000) && (_DAT_0fffe010 == -0x80000000)) && (DAT_23002dcf == 0x80)) {
    thunk_FUN_0e0621b8(&DAT_23002dcf,4);
    DAT_2300719e = 0;
    DAT_230071ba = DAT_230071ba | 2;
  }
  FUN_23026ea4();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230270f0. Types and names are inferred; NOT original source. */

void thunk_FUN_0e062244(void)

{
  FUN_0e062244();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230270f8. Types and names are inferred; NOT original source. */

void thunk_FUN_0e067468(void)

{
  FUN_0e067468();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027100. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06d8f8(void)

{
  FUN_0e06d8f8();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027108. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06cbdc(void)

{
  FUN_0e06cbdc();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027110. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06ebe0(void)

{
  FUN_0e06ebe0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027118. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0612ac(void)

{
  FUN_0e0612ac();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027120. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05eb1c(void)

{
  FUN_0e05eb1c();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027128. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05c6d4(void)

{
  FUN_0e05c6d4();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027130. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06d5b0(void)

{
  FUN_0e06d5b0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027140. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06dd90(void)

{
  FUN_0e06dd90();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027148. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0621b8(void)

{
  FUN_0e0621b8();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027150. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05c504(void)

{
  FUN_0e05c504();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027158. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06f3ba(void)

{
  FUN_0e06f3ba();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027160. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06f3aa(void)

{
  FUN_0e06f3aa();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027170. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06ddc4(void)

{
  FUN_0e06ddc4();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027178. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06245c(void)

{
  FUN_0e06245c();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027180. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06ec54(void)

{
  FUN_0e06ec54();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027188. Types and names are inferred; NOT original source. */

void thunk_FUN_0e064504(void)

{
  FUN_0e064504();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027190. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05c200(void)

{
  FUN_0e05c200();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027198. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06d3f0(void)

{
  FUN_0e06d3f0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271a0. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06cd54(void)

{
  FUN_0e06cd54();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271b0. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06e334(void)

{
  FUN_0e06e334();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271b8. Types and names are inferred; NOT original source. */

void thunk_FUN_0e062414(void)

{
  FUN_0e062414();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271c8. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06d118(void)

{
  FUN_0e06d118();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271d8. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05be20(void)

{
  FUN_0e05be20();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271e0. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0623ac(void)

{
  FUN_0e0623ac();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271e8. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06cc94(void)

{
  FUN_0e06cc94();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271f0. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05c5ec(void)

{
  FUN_0e05c5ec();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 230271f8. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0622bc(void)

{
  FUN_0e0622bc();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027200. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06d0d0(void)

{
  FUN_0e06d0d0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027208. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05ba10(void)

{
  FUN_0e05ba10();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027210. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05be4c(void)

{
  FUN_0e05be4c();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027218. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06d530(void)

{
  FUN_0e06d530();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027228. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0612c8(void)

{
  FUN_0e0612c8();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027230. Types and names are inferred; NOT original source. */

void thunk_FUN_0e0612f0(void)

{
  FUN_0e0612f0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027238. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06c6c0(void)

{
  FUN_0e06c6c0();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027240. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06f35c(void)

{
  FUN_0e06f35c();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027248. Types and names are inferred; NOT original source. */

void thunk_FUN_0e06450c(void)

{
  FUN_0e06450c();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027250. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05d698(void)

{
  FUN_0e05d698();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027258. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05ed64(void)

{
  FUN_0e05ed64();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027260. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05bd18(void)

{
  FUN_0e05bd18();
  return;
}



/* Automatically decompiled from Suit1FWData__radio_radio.bin at 23027268. Types and names are inferred; NOT original source. */

void thunk_FUN_0e05e6d4(void)

{
  FUN_0e05e6d4();
  return;
}


