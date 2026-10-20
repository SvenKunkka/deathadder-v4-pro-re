
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


