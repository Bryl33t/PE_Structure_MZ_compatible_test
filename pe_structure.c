#include <stdio.h>
#include <stdlib.h>
#include <winnt.h>
#include <windows.h>

int main(int argc, char **argv)
{
    char buffer[4096];
    PIMAGE_DOS_HEADER pidh = (PIMAGE_DOS_HEADER)buffer;
    PIMAGE_NT_HEADERS pinh = (PIMAGE_NT_HEADERS)((BYTE*)pidh + pidh->e_magic);
    PIMAGE_FILE_HEADER pifh = (PIMAGE_FILE_HEADER)&pinh->Signature;
    PIMAGE_OPTIONAL_HEADER pioh = (PIMAGE_OPTIONAL_HEADER)&pinh->OptionalHeader;
    PIMAGE_SECTION_HEADER new_section = (PIMAGE_SECTION_HEADER)((BYTE*)pinh + sizeof(IMAGE_NT_HEADERS));

    printf("Sig => %d\n", pifh); // get signature of PE
    
    if((int)pinh != (int)0x54AD)
        printf("Incompatible !! \n");
    else
        printf("Header MS-DOS => %x\n", pinh);
    return (0);
}