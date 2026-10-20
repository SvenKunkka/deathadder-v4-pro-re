/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e07f5a4. Types and names are inferred; NOT original source. */

void FUN_0e07f5a4(void)

{
  char cVar1;
  ushort *puVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  
  puVar4 = DAT_0e07f66c;
  pcVar3 = DAT_0e07f658;
  if ((((*DAT_0e07f648 != '\0') || (*DAT_0e07f64c != '\0')) || (*DAT_0e07f650 != '\0')) ||
     (*DAT_0e07f654 != '\0')) {
    return;
  }
  cVar1 = *DAT_0e07f658;
  if (DAT_0e07f658[4] == '\x01') {
    if ((cVar1 != '\x01') && (DAT_0e07f658[2] != '\x01')) {
      *DAT_0e07f65c = '\0';
      return;
    }
    if (*DAT_0e07f65c == '\0') {
      if (*DAT_0e07f660 != '\0') {
        return;
      }
      if (*DAT_0e07f668 == '\0') {
        if (cVar1 != '\x01') {
          return;
        }
      }
      else {
        if (cVar1 != '\x01') {
          if ((cVar1 == '\0') && (DAT_0e07f658[2] == '\x01')) {
            *DAT_0e07f65c = '\x01';
            *puVar4 = 2;
          }
          *DAT_0e07f670 = 0;
          return;
        }
        *DAT_0e07f65c = '\x01';
        puVar5 = DAT_0e07f670;
        *DAT_0e07f66c = 4;
        *puVar5 = 0;
      }
      goto LAB_0e07f5de;
    }
    FUN_0e07f404();
  }
  else {
    *DAT_0e07f65c = '\0';
  }
  if (*pcVar3 != '\x01') {
    return;
  }
  if (*DAT_0e07f660 != '\0') {
    return;
  }
LAB_0e07f5de:
  pcVar3 = DAT_0e07f594;
  puVar2 = DAT_0e07f590;
  if (*DAT_0e07f664 == '\0') {
    return;
  }
  if (*DAT_0e07f58c <= *DAT_0e07f590) {
    return;
  }
  *DAT_0e07f58c = 0;
  puVar4 = DAT_0e07f598;
  if (*pcVar3 == '\0') {
    *pcVar3 = '\x01';
    puVar4 = DAT_0e07f598;
    *puVar2 = 200;
    *puVar4 = 0xff;
    *DAT_0e07f59c = 0x14;
    *DAT_0e07f5a0 = 0x14;
    return;
  }
  if (*pcVar3 != '\x01') {
    *pcVar3 = '\0';
    *puVar2 = 200;
    return;
  }
  *pcVar3 = '\0';
  *puVar4 = 0;
  puVar4 = DAT_0e07f5a0;
  *DAT_0e07f59c = 0;
  *puVar4 = 0;
  *puVar2 = 1000;
  return;
}


