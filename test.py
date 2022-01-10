#!/usr/bin/env python3

import re
from gradelib import *

r = Runner(save("xv6.out"))


@test(5, "running sbrk1")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1'
    ]))

@test(5, "running sbrk10")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk10'
    ]))

@test(5, "running sbrk100")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk100'
    ]))

@test(5, "running sbrk1000")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1000'
    ]))

@test(5, "running sbrk1e4")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1e4'
    ]))

@test(5, "running sbrk1e5")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1e5'
    ]))

@test(5, "running sbrk1e6")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1e6'
    ]))

@test(5, "running sbrk1e7")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1e7'
    ]))

@test(5, "running sbrk1e8")
def test_sbrk1e8test():
    r.run_qemu(shell_script([
        'sbrk1e8'
    ]))

@test(5, "running cowtest")
def test_cowtest():
    r.run_qemu(shell_script([
        'cowtest'
    ]))


@test(5, "running usyscalltest")
def test_usyscalltest():
    r.run_qemu(shell_script([
        'usyscalltest'
    ]))


@test(5, "running forktest")
def test_forktest():
    r.run_qemu(shell_script([
        'forktest'
    ]))
run_tests()