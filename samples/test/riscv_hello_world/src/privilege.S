    .text
    .globl privilege
    .type privilege, @function
privilege:
    addi s3, x0, 2
    ecall
    ret

  .globl to_umode
  .type to_umode, @function
to_umode:
  la t1, 0x1800
  csrc mstatus, t1
  la t0, umode_return
  csrw mepc, t0
	mret
umode_return:
  ret

  .globl ecall
  .type ecall, @function
ecall:
	ecall
  /* Some dummy instructions */
  addi t0, t0, 2
  addi t0, t0, 4
	ret
