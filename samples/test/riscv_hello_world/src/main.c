/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

extern int get_mstatus();
extern void set_mstatus(int x);
extern void clear_mstatus(int x);
extern void privilege(int x);
extern int get_misa();
extern void set_misa(int x);
extern void clear_misa(int x);
extern void to_umode();
extern void ecall();
extern int get_reg();
extern void set_reg(int x);
extern void clear_reg(int x);
int test();

void print_reg(){
  int s;
  printk("Register status:\n");
  s = get_mstatus();
  printk("mstatus = 0x%x\n", s);
  // s = get_misa();
  // printk("misa = 0x%x\n", s);
  // s = get_reg();
  // printk("mtvec = 0x%x\n", s);
}



void main(void)
{
  int x = test();
  to_umode();
  ecall();

	      printk("Hello World! %d\n", x);
}

int test(){
  //This is a test function to check registers
  int x = 0;
  x = x + 4;
  return x;
}
