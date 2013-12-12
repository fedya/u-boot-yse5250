#
# (C) Copyright 2000-2010
# Wolfgang Denk, DENX Software Engineering, wd@denx.de.
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

CROSS_COMPILE ?= ppc_8xx-

STANDALONE_LOAD_ADDR = 0x40000

PLATFORM_RELFLAGS += -mrelocatable -ffunction-sections -fdata-sections
PLATFORM_CPPFLAGS += -DCONFIG_PPC -D__powerpc__
PLATFORM_LDFLAGS  += -n --gc-sections

ifdef CONFIG_SYS_LDSCRIPT
# need to strip off double quotes
LDSCRIPT := $(subst ",,$(CONFIG_SYS_LDSCRIPT))
else ifdef CONFIG_NAND_SPL
LDSCRIPT := $(SRCTREE)/$(CONFIG_BOARDDIR)/u-boot-nand.lds
else
ifneq ($(wildcard $(SRCTREE)/arch/powerpc/cpu/$(CPU)/u-boot.lds),)
LDSCRIPT := $(SRCTREE)/arch/powerpc/cpu/$(CPU)/u-boot.lds
endif
endif

#
# When cross-compiling on NetBSD, we have to define __PPC__ or else we
# will pick up a va_list declaration that is incompatible with the
# actual argument lists emitted by the compiler.
#
# [Tested on NetBSD/i386 1.5 + cross-powerpc-netbsd-1.3]

ifeq ($(CROSS_COMPILE),powerpc-netbsd-)
PLATFORM_CPPFLAGS+= -D__PPC__
endif
ifeq ($(CROSS_COMPILE),powerpc-openbsd-)
PLATFORM_CPPFLAGS+= -D__PPC__
endif
