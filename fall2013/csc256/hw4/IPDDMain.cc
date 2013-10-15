#include <iostream>
using namespace std;

int byteToDec(int arg0, char *arg1);
void IPtoDD(int arg0, char *arg1);

int main() {
  int num = 0x8234000a;
  char str[16];

  IPtoDD(num, str);
  cout << str << endl;

  num = 0xab0932ba;
  IPtoDD(num, str);
  cout << str << endl;
}

int byteToDec(int arg0, char *arg1)
{
  int temp, flag = 0, count = 0;

  if (arg0==0) {
    *arg1 = '0';
    return 1;
  }
  else {
    temp = arg0/100;

    if (temp != 0) {
      *arg1++ = (char) temp + 0x30;
      count++;
      flag = 1;
    }

    temp = (arg0 % 100) / 10;

    if ((flag!=0) || (temp != 0)) {
      *arg1++ = (char) temp + 0x30;
      count++;
    }

    temp = arg0 % 10;
    *arg1 = (char) temp + 0x30;
    count++;

    return count;
  }
}

void IPtoDD(int arg0, char *arg1)
{
  int temp, numChar, shift = 24;

  for (int i=0; i<4; i++) {
    temp = arg0 >> shift;
    temp = temp & 0x000000ff;
    numChar = byteToDec(temp,arg1);
    arg1 += numChar;
    *arg1++ = '.';
    shift -= 8;
  }

  arg1--;
  *arg1 = 0;

  return;
}

