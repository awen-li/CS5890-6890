import os
from distutils.core import setup, Extension


mymoudle = Extension('analyzer',
                    define_macros = [('MAJOR_VERSION', '1'), ('MINOR_VERSION', '0')],
                    extra_link_args=[],
                    extra_compile_args=['-std=c++11'],
                    include_dirs = ['./include'],
                    libraries = ['shmQueue'],
                    library_dirs = [],
                    sources = ['./source/analyzer.cpp', './source/ext.cpp'])


setup(
    name='myAnalyzer',
    version='1.0',
    description='A Python package with a C extension for reading from shared memory',
    ext_modules=[mymoudle]
)

