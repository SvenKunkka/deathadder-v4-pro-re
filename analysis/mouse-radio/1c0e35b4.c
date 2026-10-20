/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0e35b4. Types and names are inferred; NOT original source. */

void FUN_1c0e35b4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  byte *pbVar4;
  char *pcVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  
  uVar8 = DAT_1c0e3680;
  pcVar7 = DAT_1c0e367c;
  puVar6 = DAT_1c0e3678;
  pcVar5 = DAT_1c0e3674;
  pbVar4 = DAT_1c0e3670;
  pcVar3 = DAT_1c0e366c;
  pcVar2 = DAT_1c0e3668;
  do {
    do {
      thunk_EXT_FUN_0e0950f0(uVar8,param_2,0xffffffff,0xffffffff,param_4);
      thunk_EXT_FUN_0e07e228();
      FUN_1c0df024();
      thunk_EXT_FUN_0e07d90c();
      FUN_1c0df808();
      FUN_1c0e4c10();
      param_2 = extraout_r1;
    } while (*pcVar2 == '\0');
    if (*pcVar3 != '\0') {
      if ((byte)(*pbVar4 + 1) < 0x32) {
        *pbVar4 = *pbVar4 + 1;
      }
      else {
        cVar1 = *pcVar5;
        *pbVar4 = 0;
        *pcVar3 = '\0';
        if (cVar1 == '\x01') {
          *puVar6 = 1;
        }
        else if (cVar1 == '\x04') {
          *pcVar7 = '\x01';
        }
      }
    }
    FUN_1c0e382c();
    FUN_1c0e4bac();
    if (*pcVar7 != '\0') {
      FUN_1c0e3710();
    }
    FUN_1c0df340();
    thunk_EXT_FUN_0e07d2fc();
    FUN_1c0e0390();
    FUN_1c0d90f0();
    thunk_EXT_FUN_0e07d864(1);
    FUN_1c0dec7c();
    FUN_1c0e0654();
    FUN_1c0dee04();
    thunk_EXT_FUN_0e07ec68();
    param_2 = extraout_r1_00;
  } while( true );
}


