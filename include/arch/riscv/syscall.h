/**
*	It must be included by the syscall interface architecture-abstraction header
* (include/arch/syscall.h)
*/



#ifndef ZEPHYR_INCLUDE_ARCH_RISCV_SYSCALL_H_
#define ZEPHYR_INCLUDE_ARCH_RISCV_SYSCALL_H_


#ifdef CONFIG_USERSPACE
#ifndef _ASMLANGUAGE

#include <zephyr/types.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif


/*
* Syscall invocation macros for RISC-V architecture.
*/
static inline uintptr_t arch_syscall_invoke6(uintptr_t arg1, uintptr_t arg2,
					     uintptr_t arg3, uintptr_t arg4,
					     uintptr_t arg5, uintptr_t arg6,
					     uintptr_t call_id)
{
	register u32_t ret __asm__("a0") = arg1;
	register u32_t a1 __asm__("a1") = arg2;
	register u32_t a2 __asm__("a2") = arg3;
	register u32_t a3 __asm__("a3") = arg4;
	register u32_t a4 __asm__("a4") = arg5;
	register u32_t a5 __asm__("a5") = arg6;
	register u32_t a7 __asm__("a7") = call_id;

	__asm__ volatile("ecall\n"
			 : "=r"(ret)
			 : "r" (ret), "r" (a1), "r" (a2), "r" (a3),
			   "r" (a4), "r" (a5), "r" (a7)
			 : "memory", "ret", "a7", "a1", "a2", "a3", "a4", "a5");

	return ret;
}

static inline uintptr_t arch_syscall_invoke5(uintptr_t arg1, uintptr_t arg2,
					     uintptr_t arg3, uintptr_t arg4,
					     uintptr_t arg5,
					     uintptr_t call_id)
{
	register u32_t ret __asm__("a0") = arg1;
	register u32_t a1 __asm__("a1") = arg2;
	register u32_t a2 __asm__("a2") = arg3;
	register u32_t a3 __asm__("a3") = arg4;
	register u32_t a4 __asm__("a4") = arg5;
	register u32_t a7 __asm__("a7") = call_id;

	__asm__ volatile("ecall\n"
			 : "=r"(ret)
			 : "r" (ret), "r" (a1), "r" (a2), "r" (a3),
			   "r" (a4), "r" (a7)
			 : "memory", "ret", "a7", "a1", "a2", "a3", "a4");

	return ret;
}

static inline uintptr_t arch_syscall_invoke4(uintptr_t arg1, uintptr_t arg2,
					     uintptr_t arg3, uintptr_t arg4,
					     uintptr_t call_id)
{
	register u32_t ret __asm__("a0") = arg1;
	register u32_t a1 __asm__("a1") = arg2;
	register u32_t a2 __asm__("a2") = arg3;
	register u32_t a3 __asm__("a3") = arg4;
	register u32_t a7 __asm__("a7") = call_id;

	__asm__ volatile("ecall\n"
			 : "=r"(ret)
			 : "r" (ret), "r" (a1), "r" (a2), "r" (a3),
			   "r" (a7)
			 : "memory", "ret", "a7", "a1", "a2", "a3");

	return ret;
}

static inline uintptr_t arch_syscall_invoke3(uintptr_t arg1, uintptr_t arg2,
					     uintptr_t arg3,
					     uintptr_t call_id)
{
	register u32_t ret __asm__("a0") = arg1;
	register u32_t a1 __asm__("a1") = arg2;
	register u32_t a2 __asm__("a2") = arg3;
	register u32_t a7 __asm__("a7") = call_id;

	__asm__ volatile("ecall\n"
			 : "=r"(ret)
			 : "r" (ret), "r" (a1), "r" (a2), "r" (a7)
			 : "memory", "ret", "a7", "a1", "a2");

	return ret;
}

static inline uintptr_t arch_syscall_invoke2(uintptr_t arg1, uintptr_t arg2,
					     uintptr_t call_id)
{
	register u32_t ret __asm__("a0") = arg1;
	register u32_t a1 __asm__("a1") = arg2;
	register u32_t a7 __asm__("a7") = call_id;

	__asm__ volatile("ecall\n"
			 : "=r"(ret)
			 : "r" (ret), "r" (a1), "r" (a7)
			 : "memory", "ret", "a7", "a1");

	return ret;
}

static inline uintptr_t arch_syscall_invoke1(uintptr_t arg1,
					     uintptr_t call_id)
{
	register u32_t ret __asm__("a0") = arg1;
	register u32_t a7 __asm__("a7") = call_id;

	__asm__ volatile("ecall\n"
			 : "=r"(ret)
			 : "r" (ret), "r" (a7)
			 : "memory", "ret", "a7");
	return ret;
}

static inline uintptr_t arch_syscall_invoke0(uintptr_t call_id)
{
	register u32_t ret __asm__("a0");
	register u32_t a7 __asm__("a7") = call_id;

	__asm__ volatile("ecall\n"
			 : "=r"(ret)
			 : "r" (ret), "r" (a7)
			 : "memory", "ret", "a7");

	return ret;
}


#ifdef __cplusplus
}
#endif

#endif /* _ASMLANGUAGE */
#endif /* CONFIG_USERSPACE */
#endif /* ZEPHYR_INCLUDE_ARCH_RISCV_SYSCALL_H_ */
