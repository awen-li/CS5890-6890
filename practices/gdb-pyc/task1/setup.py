from setuptools import setup, Extension

module = Extension ("taskc",
                    sources=["taskc/taskc.c"])

setup(
    name="taskc",
    version="1.0",
    description="task for gdb practice",
    ext_modules=[module],
)
