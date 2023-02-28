/*
    x86-64 gcc7.3-8.3 -O0 -mindirect-branch=thunk
    gcc should Disable switch jump tables when retpolines are enabled 
*/
int global;

int foo3 (int x)
{
  switch (x) {
    case 0:
      return 11;
    case 1:
      return 123;
    case 2:
      global += 1;
      return 3;
    case 3:
      return 44;
    case 4:
      return 444;
    default:
      return 0;
  }
}