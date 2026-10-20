/* Automatically decompiled from Suit2FWData__radio_radio.bin at 0e08464c. Types and names are inferred; NOT original source. */

void FUN_0e08464c(void)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  char *pcVar4;
  
  pcVar4 = DAT_0e0847b8;
  if (*DAT_0e0847ac == '\0') {
    return;
  }
  if (*DAT_0e0847b0 == '\x04') {
    uVar3 = *DAT_0e0847b4;
    cVar2 = *DAT_0e0847b8;
  }
  else {
    if (*DAT_0e0847b0 != '\x01') {
      return;
    }
    bVar1 = *(byte *)(DAT_0e0847bc + 3);
    uVar3 = *DAT_0e0847b4;
    cVar2 = *DAT_0e0847b8;
    if (1 < bVar1) {
      if (bVar1 == 2) {
        if ((uVar3 < 0x2711) && (DAT_0e0847b4[1] < 0x2711)) {
          if ((uVar3 < 0xfa1) && (DAT_0e0847b4[1] < 0xfa1)) {
            if (cVar2 != '\b') {
              FUN_0e0822fc();
              *pcVar4 = '\b';
            }
          }
          else if (cVar2 != '\t') {
            FUN_0e082768();
            *pcVar4 = '\t';
          }
        }
        else if (cVar2 != '\n') {
          FUN_0e082bd4();
          *pcVar4 = '\n';
        }
      }
      else if (bVar1 < 5) {
        if ((uVar3 < 0x2711) && (DAT_0e0847b4[1] < 0x2711)) {
          if ((uVar3 < 0xfa1) && (DAT_0e0847b4[1] < 0xfa1)) {
            if (cVar2 != '\x05') {
              FUN_0e0815b8();
              *pcVar4 = '\x05';
            }
          }
          else if (cVar2 != '\x06') {
            FUN_0e081a24();
            *pcVar4 = '\x06';
          }
        }
        else if (cVar2 != '\a') {
          FUN_0e081e90();
          *pcVar4 = '\a';
        }
      }
      else if ((uVar3 < 0x2711) && (DAT_0e0847b4[1] < 0x2711)) {
        if ((uVar3 < 0xfa1) && (DAT_0e0847b4[1] < 0xfa1)) {
          if (cVar2 != '\x02') {
            FUN_0e080874();
            *pcVar4 = '\x02';
          }
        }
        else if (cVar2 != '\x03') {
          FUN_0e080ce0();
          *pcVar4 = '\x03';
        }
      }
      else if (cVar2 != '\x04') {
        FUN_0e08114c();
        *pcVar4 = '\x04';
      }
      goto LAB_0e084690;
    }
  }
  if ((uVar3 < 0x2711) && (DAT_0e0847b4[1] < 0x2711)) {
    if ((uVar3 < 0xfa1) && (DAT_0e0847b4[1] < 0xfa1)) {
      if (cVar2 != '\v') {
        FUN_0e083920();
        *pcVar4 = '\v';
      }
    }
    else if (cVar2 != '\f') {
      FUN_0e083d84();
      *pcVar4 = '\f';
    }
  }
  else if (cVar2 != '\r') {
    FUN_0e0841e8();
    *pcVar4 = '\r';
    FUN_0e080470(1);
    return;
  }
LAB_0e084690:
  FUN_0e080470(1);
  return;
}


