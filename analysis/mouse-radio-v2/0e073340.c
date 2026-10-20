/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e073340. Types and names are inferred; NOT original source. */

void FUN_0e073340(void)

{
  byte *pbVar1;
  short *psVar2;
  byte *pbVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char cVar6;
  uint uVar7;
  uint uVar8;
  
  puVar5 = DAT_0e073448;
  pcVar4 = DAT_0e073444;
  pbVar3 = DAT_0e073440;
  psVar2 = DAT_0e07343c;
  pbVar1 = DAT_0e073438;
  uVar7 = (uint)*DAT_0e073438;
  uVar8 = (uint)*DAT_0e073434 | (uint)*DAT_0e073430 << 1;
  if (uVar7 == uVar8) {
    if ((*DAT_0e073440 != uVar7) && (*DAT_0e07343c == 0)) {
      cVar6 = *DAT_0e073444;
      if (uVar7 == 3) {
        if (cVar6 != '\x04') {
          *DAT_0e073444 = '\x04';
          *puVar5 = 0;
          FUN_0e0780e8();
          FUN_0e0781e8();
          FUN_0e077e1c();
          FUN_0e078008();
          thunk_FUN_0e08464c();
          *DAT_0e073450 = 0;
          FUN_0e06dad8();
          FUN_0e078114();
          FUN_0e073510();
          FUN_0e077d6c();
          FUN_0e077f1c();
          *DAT_0e073454 = 0;
          *DAT_0e073458 = 0;
          *DAT_0e07345c = 0;
          *DAT_0e073460 = 0;
          *DAT_0e073464 = 0;
          *DAT_0e073468 = 0;
          thunk_FUN_0e07ee28();
          FUN_0e077eb0();
          FUN_0e07833c();
          cVar6 = *pcVar4;
          *puVar5 = 1;
        }
      }
      else if (cVar6 != '\x01') {
        *DAT_0e073444 = '\x01';
        *puVar5 = 0;
        FUN_0e0780e8();
        FUN_0e0781e8();
        FUN_0e077e1c();
        FUN_0e078008();
        thunk_FUN_0e08464c();
        FUN_0e074e38(1);
        if (*DAT_0e07344c == '\0') {
          thunk_FUN_0e07f074();
        }
        cVar6 = *pcVar4;
      }
      thunk_FUN_0e084f70(cVar6);
      *pbVar3 = *pbVar1;
      return;
    }
  }
  else {
    *DAT_0e073438 = (byte)uVar8;
    *psVar2 = 200;
  }
  return;
}


