from setuptools import setup, Extension

module = Extension ("taskc",
                    extra_compile_args=['-O0'],
                    sources=["taskc/taskc.c"])

setup(
    name="taskc",
    version="1.0",
    description="task for gdb practice",
    ext_modules=[module],
)
