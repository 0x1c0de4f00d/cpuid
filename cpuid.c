#include <stdio.h>
#include <string.h>



int main() {
    unsigned int rax, rbx, rcx, rdx;
    rax = 0x00;
    unsigned char cpu_name[17];
    cpu_name[16] = 0x00;
    asm volatile(
        "cpuid"
    : "=b"(rbx), "=c"(rcx), "=d"(rdx)
    : "a"(rax)
    : "memory", "cc"
    );
    printf("%x\n%x\n%x\n%x\n", rax, rbx, rcx, rdx);
    memcpy(cpu_name, &rbx, 4);
    memcpy(cpu_name+4, &rdx, 4);
    memcpy(cpu_name+8, &rcx, 4);
    
    printf("%s\n", cpu_name);
}
