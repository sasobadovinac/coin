#!/bin/sh

# Regenerate all files which are constructed by the autoconf, automake
# and libtool tool-chain. Note: only developers should need to use
# this script.

# Author: Morten Eriksen, <mortene@sim.no>.

DIE=false

PROJECT=Coin
MACRODIR=conf-macros
AUTOMAKE_ADD=

if test "$1" = "--clean"; then
  rm -f aclocal.m4 \
        config.guess \
        config.h.in \
        config.sub \
        configure \
        depcomp \
        install-sh \
        ltconfig \
        ltmain.sh \
        missing \
        mkinstalldirs \
        stamp-h*
  find . -name Makefile.in -print | xargs rm
  exit
elif test "$1" = "--add"; then
  AUTOMAKE_ADD="--add-missing --gnu --copy"
fi

echo "Checking the installed configuration tools..."

AUTOCONF_VER=2.14.1-SIM  # Autoconf from CVS @ 2000-01-13.
if test -z "`autoconf --version | grep \" $AUTOCONF_VER\" 2> /dev/null`"; then
    echo
    echo "You must have autoconf version $AUTOCONF_VER installed to"
    echo "generate configure information and Makefiles for $PROJECT."
    echo ""
    echo "The Autoconf version we are using is a development version"
    echo "\"frozen\" from the CVS repository at 2000-01-13, with a few"
    echo "patches applied to fix bugs. You can get it here:"
    echo ""
    echo "   ftp://ftp.sim.no/pub/coin/autoconf-2.14.1-coin.tar.gz"
    echo ""
    DIE=true
fi

AUTOMAKE_VER=1.4a-SIM-20000531  # Automake from CVS
if test -z "`automake --version | grep \" $AUTOMAKE_VER\" 2> /dev/null`"; then
    echo
    echo "You must have automake version $AUTOMAKE_VER installed to"
    echo "generate configure information and Makefiles for $PROJECT."
    echo ""
    echo "The Automake version we are using is a development version"
    echo "\"frozen\" from the CVS repository. You can get it here:"
    echo ""
    echo "   ftp://ftp.sim.no/pub/coin/automake-1.4a-coin.tar.gz"
    echo ""
    DIE=true
fi

LIBTOOL_VER=1.3.5
if test -z "`libtool --version | egrep \"$LIBTOOL_VER\" 2> /dev/null`"; then
    echo
    echo "You must have libtool version $LIBTOOL_VER installed to"
    echo "generate configure information and Makefiles for $PROJECT."
    echo ""
    echo "Get ftp://ftp.gnu.org/pub/libtool/libtool-1.3.5.tar.gz"
    echo ""
    DIE=true
fi

# The separate $MACRODIR module was added late in the project, and
# since we need to do a cvs checkout to obtain it (cvs update won't do
# with modules), we run this check.
if ! test -d $MACRODIR
then
    cvs -z3 checkout -P $MACRODIR
    if ! test -d $MACRODIR
    then
	echo "Couldn't fetch $MACRODIR module!"
        echo
        echo "Directory ``$MACRODIR'' (a separate CVS module) seems to be missing."
        echo "You probably checked out $PROJECT before ``$MACRODIR'' was added."
        echo "Run 'cvs -d :pserver:cvs@cvs.sim.no:/export/cvsroot co $MACRODIR'"
        echo "to try again."
	DIE=true
	exit 1
    fi
fi

$DIE && exit 1

echo "Running aclocal (generating aclocal.m4)..."
aclocal -I $MACRODIR

echo "Running autoheader (generating config.h.in)..."
autoheader

echo "Running automake (generating the Makefile.in files)..."
automake $AUTOMAKE_ADD

echo "Running autoconf (generating the configure script)..."
autoconf

echo
echo "Done. Now run './configure' and 'make install' to build $PROJECT."
echo
