/* Automatically decompiled from Suit2FWData__radio_radio.bin at 1c0df340. Types and names are inferred; NOT original source. */

void FUN_1c0df340(void)

{
  byte *pbVar1;
  short *psVar2;
  byte *pbVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  
  puVar5 = DAT_1c0df448;
  pcVar4 = DAT_1c0df444;
  pbVar3 = DAT_1c0df440;
  psVar2 = DAT_1c0df43c;
  pbVar1 = DAT_1c0df438;
  uVar7 = (uint)*DAT_1c0df438;
  uVar8 = (uint)*DAT_1c0df434 | (uint)*DAT_1c0df430 << 1;
  if (uVar7 == uVar8) {
    if ((*DAT_1c0df440 != uVar7) && (*DAT_1c0df43c == 0)) {
      cVar6 = *DAT_1c0df444;
      if (uVar7 == 3) {
        if (cVar6 != '\x04') {
          *DAT_1c0df444 = '\x04';
          *puVar5 = 0;
          FUN_1c0e40e8();
          FUN_1c0e41e8();
          FUN_1c0e3e1c();
          FUN_1c0e4008();
          thunk_EXT_FUN_0e08464c();
          *DAT_1c0df450 = 0;
          FUN_1c0d9ad8();
          FUN_1c0e4114();
          FUN_1c0df510();
          FUN_1c0e3d6c();
          FUN_1c0e3f1c();
          *DAT_1c0df454 = 0;
          *DAT_1c0df458 = 0;
          *DAT_1c0df45c = 0;
          *DAT_1c0df460 = 0;
          *DAT_1c0df464 = 0;
          *DAT_1c0df468 = 0;
          thunk_EXT_FUN_0e07ee28();
          FUN_1c0e3eb0();
          FUN_1c0e433c();
          cVar6 = *pcVar4;
          *puVar5 = 1;
        }
      }
      else if (cVar6 != '\x01') {
        *DAT_1c0df444 = '\x01';
        *puVar5 = 0;
        FUN_1c0e40e8();
        FUN_1c0e41e8();
        FUN_1c0e3e1c();
        FUN_1c0e4008();
        thunk_EXT_FUN_0e08464c();
        FUN_1c0e0e38(1);
        if (*DAT_1c0df44c == '\0') {
          thunk_EXT_FUN_0e07f074();
        }
        cVar6 = *pcVar4;
      }
      thunk_EXT_FUN_0e084f70(cVar6);
      *pbVar3 = *pbVar1;
      return;
    }
  }
  else {
    *DAT_1c0df438 = (byte)uVar8;
    *psVar2 = 200;
  }
  return;
}


