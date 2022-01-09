#!/usr/bin/env python3

import re
from gradelib import *

r = Runner(save("xv6.out"))

"""
@test(0, "running cowtest")
def test_cowtest():
    r.run_qemu(shell_script([
        'cowtest'
    ]))

@test(30, "simple", parent=test_cowtest)
def test_simple():
    matches = re.findall("^simple: ok$", r.qemu.output, re.M)
    assert_equal(len(matches), 2, "Number of appearances of 'simple: ok'")

@test(30, "three", parent=test_cowtest)
def test_three():
    matches = re.findall("^three: ok$", r.qemu.output, re.M)
    assert_equal(len(matches), 3, "Number of appearances of 'three: ok'")

@test(20, "file", parent=test_cowtest)
def test_file():
    r.match('^file: ok$')
"""
"""
@test(0, "usertests")
def test_usertests():
    r.run_qemu(shell_script([
        'usertests'
    ]), timeout=300)
    r.match('^ALL TESTS PASSED$')

def usertest_check(testcase, nextcase, output):
    if not re.search(r'\ntest {}: [\s\S]*OK\ntest {}'.format(testcase, nextcase), output):
        raise AssertionError('Failed ' + testcase)

@test(5, "usertests: copyin", parent=test_usertests)
def test_sbrkbugs():
    usertest_check("copyin", "copyout", r.qemu.output)

@test(5, "usertests: copyout", parent=test_usertests)
def test_sbrkbugs():
    usertest_check("copyout", "copyinstr1", r.qemu.output)
"""

@test(0, "running sbrk1")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1'
    ]))

@test(0, "running sbrk10")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk10'
    ]))

@test(0, "running sbrk100")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk100'
    ]))

@test(0, "running sbrk1000")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1000'
    ]))

@test(0, "running sbrk1e4")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1e4'
    ]))

@test(0, "running sbrk1e5")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1e5'
    ]))

@test(0, "running sbrk1e6")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1e6'
    ]))

@test(0, "running sbrk1e7")
def test_cowtest():
    r.run_qemu(shell_script([
        'sbrk1e7'
    ]))

run_tests()