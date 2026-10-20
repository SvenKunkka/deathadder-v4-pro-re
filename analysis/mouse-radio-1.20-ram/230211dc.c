/* Automatically decompiled from Suit2FWData__radio_radio.bin at 230211dc. Types and names are inferred; NOT original source. */

void ram_candidate_230211dc(void)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  
  if ((DAT_23007797 != '\0') && (DAT_23007715 == '\0')) {
    DAT_23003e99 = DAT_23003f54;
    DAT_23003e98 = 0x5a;
    pcVar3 = &DAT_23003f53;
    cVar2 = 'X';
    do {
      cVar1 = cVar2 + -1;
      if (*pcVar3 != '\0') {
        cVar2 = cVar2 + '\x02';
        goto LAB_23021214;
      }
      pcVar3 = pcVar3 + -1;
      cVar2 = cVar1;
    } while (cVar1 != '\b');
    cVar2 = '\n';
LAB_23021214:
    thunk_FUN_0e09739c(&DAT_23003e9a,&DAT_23003efc);
    FUN_23025ab0(0,5,&DAT_23003e98,cVar2,0xff);
    DAT_23007797 = '\0';
  }
  return;
}


