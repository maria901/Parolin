	.file	"gcc_asm.c"
	.text
.globl _getcpuinfo
	.def	_getcpuinfo;	.scl	2;	.type	32;	.endef
_getcpuinfo:
                     	push   %ebp
                  	mov    %esp,%ebp
              	sub    $0x14,%esp
                      	push   %ebx
                  	push   %esi
                     	push   %edi
   	movl   $0x0,-0xc(%ebp)
  	movl   $0x0,-0x10(%ebp)
   	movl   $0x0,-0x14(%ebp)
  	movl   $0x0,-0x4(%ebp)
  	movl   $0x0,-0x8(%ebp)
              	mov    0x8(%ebp),%eax
                 	cpuid  
              	mov    %eax,-0x8(%ebp)
              	mov    %ebx,-0x10(%ebp)
               	mov    %edx,-0x4(%ebp)
               	mov    %ecx,-0x14(%ebp)
               	mov    0x14(%ebp),%eax
               	mov    -0x14(%ebp),%ecx
                  	mov    %ecx,(%eax)
               	mov    0x18(%ebp),%edx
               	mov    -0x4(%ebp),%eax
                  	mov    %eax,(%edx)
              	mov    0x10(%ebp),%ecx
              	mov    -0x10(%ebp),%edx
                  	mov    %edx,(%ecx)
               	mov    0xc(%ebp),%eax
              	mov    -0x8(%ebp),%ecx
                 	mov    %ecx,(%eax)
                	xor    %eax,%eax
                    	pop    %edi
                    	pop    %esi
       	pop    %ebx
               	mov    %ebp,%esp
                 	pop    %ebp
                   	ret 
