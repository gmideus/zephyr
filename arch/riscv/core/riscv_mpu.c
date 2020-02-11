#include <device.h>
#include <init.h>
#include <kernel.h>
#include <soc.h>
#include <kernel_structs.h>

#include "riscv_mpu.h"
#include <linker/linker-defs.h>


#ifdef CONFIG_USERSPACE

/* !!STUB TODO!! */
void arch_mem_domain_thread_add(struct k_thread *thread)
{
	return;
}

/* !!STUB TODO!! */
int arch_mem_domain_max_partitions_get(void)
{
	return 3;
}


#endif /* CONFIG_USERSPACE */
