/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e0775b4. Types and names are inferred; NOT original source. */

void FUN_0e0775b4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  
  uVar8 = DAT_0e077680;
  pcVar7 = DAT_0e07767c;
  puVar6 = DAT_0e077678;
  pcVar5 = DAT_0e077674;
  pbVar4 = DAT_0e077670;
  pcVar3 = DAT_0e07766c;
  pcVar2 = DAT_0e077668;
  do {
    do {
      thunk_FUN_0e0950f0(uVar8,param_2,0xffffffff,0xffffffff,param_4);
      thunk_FUN_0e07e228();
      FUN_0e073024();
      thunk_FUN_0e07d90c();
      FUN_0e073808();
      FUN_0e078c10();
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
    FUN_0e07782c();
    FUN_0e078bac();
    if (*pcVar7 != '\0') {
      FUN_0e077710();
    }
    FUN_0e073340();
    FUN_0e078f0c();
    FUN_0e074390();
    FUN_0e06d0f0();
    thunk_FUN_0e07d864(1);
    FUN_0e072c7c();
    FUN_0e074654();
    FUN_0e072e04();
    thunk_FUN_0e07ec68();
    param_2 = extraout_r1_00;
  } while( true );
}


