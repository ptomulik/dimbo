---
layout: post
title: "Initial support for code coverage"
description: ""
category: 
tags: []
sidenav: "home"
---
{% include JB/setup %}

I'm in the process of integrating
[gcov](http://gcc.gnu.org/onlinedocs/gcc/Gcov.html) to DIMBO. It initially
works and it's possible to generate instrumented code for code coverage
analysis. Now I fight a battle for reliable statistics generated by
[lcov](http://ltp.sourceforge.net/coverage/lcov.php), as there are plenty of
source files that exist in DIMBO source tree but their statistics do not show
in lcov report. What is still left in front is to automatize the generation of
coverage reports when running tests.

To generate instrumented code, one has to set an OS environment variable
`DIMBO_ENABLE_GCOV`, for example

```console
DIMBO_ENABLE_GCOV=YES scons check
```

More details about testing and code coverage may be found in
[HOWTO/test.rst](https://github.com/ptomulik/dimbo/blob/master/HOWTO/test.rst)
file.

### Generating code coverage reports

Currently this may be done manually. First compile DIMBO with code
instrumentation enabled and run tests

```console
DIMBO_ENABLE_GCOV=YES scons check
```

then collect coverage data

```console
lcov --capture --directory build/lib/dimbo --base-directory . --no-external \
     --output-file /tmp/coverage.info
```

and you may generate HTML output

```console
genhtml /tmp/coverage.info --output-directory /tmp/coverage.html/
```

you may then check the HTML output:

```console
firefox /tmp/coverage.html/index.html
```

For the moment, the report generation doesn't work with code generated by clang
compiler due to a bug or version incompatibility (investigating).

<!-- vim: set syntax=markdown: -->