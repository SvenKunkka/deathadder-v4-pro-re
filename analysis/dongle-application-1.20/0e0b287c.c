/* Automatically decompiled from Suit1FWData__application_application.bin at 0e0b287c. Types and names are inferred; NOT original source. */

int FUN_0e0b287c(char *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = param_1;
  do {
    pcVar2 = pcVar1;
    if (pcVar2 == param_1 + param_2) break;
    pcVar1 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  return (int)pcVar2 - (int)param_1;
}


